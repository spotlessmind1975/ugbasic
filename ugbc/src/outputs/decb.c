/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include "decb.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/****************************************************************************
 * DATA TYPES AND CONSTANTS
 ****************************************************************************/

 typedef struct _DECBEntry {

    int                   mark;
    int                   size;
    int                   address;
    char                * data;
    struct _DECBEntry   * next;
    
} DECBEntry;

/****************************************************************************
 * STATIC FUNCTIONS
 ****************************************************************************/

static DECBEntry * decb_find_last_entry( DECBHandle * _handle ) {

    if ( !_handle ) 
        return NULL;

    if ( !_handle->first )
        return NULL;

    DECBEntry * actual = _handle->first;
    while( actual->next ) {
        actual = actual->next;
    }

    return actual;

}

/****************************************************************************
 * FUNCTIONS
 ****************************************************************************/

DECBHandle * decb_create( ) {

    DECBHandle * result;

    result = malloc( sizeof( DECBHandle ) );
    memset( result, 0, sizeof (DECBHandle) );

    return result;

}

void decb_add_raw( DECBHandle * _handle, int _mark, int _size, int _address, char * _data ) {

    DECBEntry * entry;

    if ( _size ) {

        int size = _size;
        int address = _address;
        char * data = _data;
        while( size > 0 ) {

            entry = malloc( sizeof( DECBEntry ) );
            memset( entry, 0, sizeof( DECBEntry ) );

            entry->mark = _mark;
            if ( size > DECB_BLOCK_SIZE ) {
                entry->size = DECB_BLOCK_SIZE;
                size -= DECB_BLOCK_SIZE;
            } else {
                entry->size = size;
                size = 0;
            }
            entry->address = address;
            address += entry->size;

            entry->data = malloc( entry->size );
            memcpy( entry->data, data, entry->size );
            data += entry->size;
            
            DECBEntry * last = decb_find_last_entry( _handle );
            if ( last ) {
                last->next = entry;
            } else {
                _handle->first = entry;
            }

        }

    } else {

            entry = malloc( sizeof( DECBEntry ) );
            memset( entry, 0, sizeof( DECBEntry ) );

            entry->mark = _mark;
            entry->address = _address;
            
            DECBEntry * last = decb_find_last_entry( _handle );
            if ( last ) {
                last->next = entry;
            } else {
                _handle->first = entry;
            }
        
    }

}

void decb_add( DECBHandle * _handle, int _size, int _address, char * _data ) {
    decb_add_raw( _handle, DECB_MARK_DATA, _size, _address, _data );
}

void decb_eof( DECBHandle * _handle, int _address ) {
    decb_add_raw( _handle, DECB_MARK_EOF, 0, _address, NULL );
}

void decb_output( DECBHandle * _handle, unsigned char * _filename ) {

    FILE * fh = fopen( _filename, "wb" );
    if ( fh ) {
        DECBEntry * actual = _handle->first;
        while( actual ) {
            unsigned char mark = actual->mark;
            fwrite( &mark, 1, 1, fh );
            unsigned short size = actual->size;
            unsigned char sizeLow = (unsigned char)(actual->size&0xff);
            unsigned char sizeHigh = (unsigned char)((actual->size>>8)&0xff);
            fwrite( &sizeHigh, 1, 1, fh );
            fwrite( &sizeLow, 1, 1, fh );
            unsigned short address = actual->address;
            unsigned char addressLow = (unsigned char)(actual->address&0xff);
            unsigned char addressHigh = (unsigned char)((actual->address>>8)&0xff);
            fwrite( &addressHigh, 1, 1, fh );
            fwrite( &addressLow, 1, 1, fh );
            if ( size ) {
                fwrite( actual->data, size, 1, fh );
            }
            actual = actual->next;
        }
        fclose( fh );
    }

}

void decb_free( DECBHandle * _handle ) {

    if ( _handle )
        free( _handle );

}