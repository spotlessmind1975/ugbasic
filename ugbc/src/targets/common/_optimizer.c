/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *----------------------------------------------------------------------------
 * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
 * (la "Licenza"); è proibito usare questo file se non in conformità alla
 * Licenza. Una copia della Licenza è disponibile all'indirizzo:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Se non richiesto dalla legislazione vigente o concordato per iscritto,
 * il software distribuito nei termini della Licenza è distribuito
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

 /* Common optimizations routines for 
    - MOS 6502/6510
    - Motorola 6809 
    - Zilog Z80
  */

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"
#include <stdarg.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/* deallocate a buffer */
POBuffer po_buf_del(POBuffer buf) {
    if(buf != NULL) {
        free(buf->str);
        buf->str = NULL;
        buf->cap = 0;
        buf->len = 0;
        free(buf);
    }

    return NULL;
}

/* allocate a buffer */
POBuffer po_buf_new(int size) {
    POBuffer buf = malloc(sizeof(*buf));
    if(buf != NULL) {
        buf->len = 0;
        buf->cap = size+1;
        buf->str = malloc(buf->cap);
        buf->str[0] = '\0';
    }
    return buf;
}

/* ensure the buffer can hold len data */
static POBuffer _buf_cap(POBuffer buf, int len) {
    if(len+1 >= buf->cap) {
        buf->cap = len + 1 + MAX_TEMPORARY_STORAGE;
        buf->str = realloc(buf->str, buf->cap);
    }
    return buf;
}

/* append a string to a buffer */
POBuffer po_buf_cat(POBuffer buf, char *string) {
    if(buf != NULL) {
        int len = strlen(string);
        _buf_cap(buf, buf->len + len);
        strcpy(&buf->str[buf->len], string);
        buf->len += len;
    }
    return buf;
}

/* copy a string into a buffer */
POBuffer po_buf_cpy(POBuffer buf, char *string) {
    if(buf != NULL) buf->len = 0;
    return po_buf_cat(buf, string);
}

/* append a char at the end of the buffer */
POBuffer po_buf_add(POBuffer buf, char c) {
    if(buf) {
        _buf_cap(buf, buf->len + 1);
        buf->str[buf->len] = c;
        ++buf->len;
        buf->str[buf->len] = '\0';
    }
    return buf;
}

/* vprintf like function */
POBuffer po_buf_vprintf(POBuffer buf, const char *fmt, va_list ap) {
    if(buf != NULL) {
        int len = 0, avl;
        do {
            _buf_cap(buf, buf->len + len);
            avl = buf->cap - buf->len;
            len = vsnprintf(&buf->str[buf->len], avl, fmt, ap);
        } while(len >= avl);
        buf->len += len;
    }
    return buf;
}

/* sprintf like function */
#ifdef __GNUC__
POBuffer po_buf_printf(POBuffer buf, const char *fmt, ...)
    __attribute__ ((format (printf, 2, 3)));
#endif
POBuffer po_buf_printf(POBuffer buf, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    po_buf_vprintf(buf, fmt, ap);
    va_end(ap);
    return buf;
}

/* fgets-like */
POBuffer po_buf_fgets(POBuffer buf, FILE *f) {
    int c;

    po_buf_cpy(buf, "");

    while( (c = fgetc(f)) != EOF) {
        po_buf_add(buf, (char)c);
        if(c=='\n') break;
    }

    return buf;
}

/* strcmp */
int po_buf_cmp(POBuffer a, POBuffer b) {
    if(a) return b ? strcmp(a->str, b->str) : 1;
    else return -1;
}

int po_buf_trim(POBuffer buf) {
    char * p = buf->str;
    char * q = buf->str + buf->len - 1;
    while((p-buf->str) < buf->len) {
        if ( ! ( (*p == ' ') || (*p == '\n') || (*p == '\r') || (*p == 13) || (*p == 10) || (*p == '\t') ) ) {
            break;
        };
        ++p;
    }
    while(q > p) {
        if ( ! ( (*q == ' ') || (*q == '\n') || (*q == '\r') || (*q == 13) || (*q == 10) || (*q == '\t') ) ) {
            break;
        };
        --q;
    }
    memmove( buf->str, p, ( q - p ) + 1 );
    buf->len = q - p + 1;
    *(buf->str + buf->len) = 0;
    return p - buf->str;
}

/* returns an UPPER-cased char */
static inline char _toUpper(char a) {
    return (a>='a' && a<='z') ? a-'a'+'A' : a;
}

/* returns true if char is end of line ? */
static inline int _eol(char c) {
    return c=='\0' || c=='\n';
}

/* returns true if both char matches */
static inline int _eq(char pat, char txt) {
    return (pat<=' ') ? (txt<=' ') : (_toUpper(pat)==_toUpper(txt));
}

#define TMP_BUF_POOL 32
static struct tmp_buf_pool {
    POBuffer buf;
    void *key1;
    int key2;
} tmp_buf_pool[TMP_BUF_POOL];

/* an integer hash
   https://gist.github.com/badboy/6267743
*/
static unsigned int tmp_buf_hash(unsigned int key) {
    key ^= (key<<17) | (key>>16);
    return key;
}

/* a static one-time buffer */
POBuffer tmp_buf(void *key1, unsigned int key2) {
    int hash = tmp_buf_hash(((intptr_t)key1)*31 + key2) % TMP_BUF_POOL;
    struct tmp_buf_pool *tmp = &tmp_buf_pool[hash];
    int count = 0;

    while(tmp->buf!=NULL && (tmp->key1!=key1 || tmp->key2!=key2)) {
        ++count;
        if(++tmp == &tmp_buf_pool[TMP_BUF_POOL]) {
            tmp = tmp_buf_pool;
        }
    }

    if(tmp->buf == NULL) {
        if(count == TMP_BUF_POOL) {
            fprintf(stderr, "TMP_BUF_POOL to short\n");
            exit(-1);
        }
        tmp->buf  = po_buf_new(0);
        tmp->key1 = key1;
        tmp->key2 = key2;
    }

    return tmp->buf;
}

void tmp_buf_clr(void *key1) {
    struct tmp_buf_pool *tmp = &tmp_buf_pool[0];
    for(;tmp!=&tmp_buf_pool[TMP_BUF_POOL];++tmp) {
        if(tmp->key1 == key1) tmp->buf = po_buf_del(tmp->buf);
    }
}

/* a version of strcmp that ends at EOL and deal our special equality. */
int po_buf_strcmp(POBuffer _s, POBuffer _t) {
    char *s = _s->str, *t = _t->str;

    while(!_eol(*s) && !_eol(*t) && _eq(*s,*t)) {
        ++s;
        ++t;
    }
    return _eol(*s) && _eol(*t) ? 0 : _eol(*s) ? 1 : -1;
}

/* Matches a string:
    - ' ' maches anthing <= ' ' (eg 'r', \n', '\t' or ' ' )
    - '*' matches up to the next one in the pattern.
   Matched content is copied into buffers passed as varargs. If
   a passed variable is NULL the matched content corresponding
   to it is not copied.

   Returns the last matched '*' or the buffer if pattern is fully
   matched, or NULL otherwise meaning "no match".
*/
POBuffer po_buf_match(POBuffer _buf, const char *_pattern, ...) {
    POBuffer ret = _buf;
    const char *s = _buf->str, *p = _pattern;
    va_list ap;

    va_start(ap, _pattern);

    while(!_eol(*s) && *p) {
        if(*p==' ') {while(*p==' ') ++p;
            if(!_eq(' ', *s)) {
                ret = NULL;
                break;
            }
            while(!_eol(*s) && _eq(' ', *s)) ++s;
        } else if(*p=='^') {
            ++p;
            while(!_eol(*s) && !_eq(*p, *s)) ++s;
            if(!_eq(*p,*s)) {
                ret = NULL;
                break;
            }
        } else if(*p=='*') {
            POBuffer m = va_arg(ap, POBuffer); ++p;
            if(m != NULL) {
                ret = po_buf_cpy(m, "");
            }
            while(!_eol(*s) && !_eq(*p, *s)) po_buf_add(m, *s++);
            if(!_eq(*p,*s)) {
                ret = NULL;
                break;
            }
        } else if(_toUpper(*s++) != _toUpper(*p++)) {
            ret = NULL;
            break;
        }
    }

    va_end(ap);

    return *p=='\0' ? ret : NULL;
}
