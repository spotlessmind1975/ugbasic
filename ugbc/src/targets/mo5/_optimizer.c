/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"
#include <stdarg.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

int isAComment( char * _buffer ) {
    if ( ! *_buffer ) {
        return 1;
    }
    if ( *_buffer == 0x0d || *_buffer == 0x0a ) {
        return 1;
    }
    while( * _buffer ) {
        if ( *_buffer == ' ' || *_buffer == '\t' ) { 
            ++_buffer;
        } else if ( *_buffer == ';' ) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

static inline char _toUpper(char a) {
	return (a>='a' && a<='z') ? a-'a'+'A' : a;
}

static inline int _eol(char c) {
	return c=='\0' || c=='\n';
}

static inline int _eq(char pat, char txt) {
	return (pat<=' ') ? (txt<=' ') : (_toUpper(pat)==_toUpper(txt));
}

/* a version of strcmp that ends at EOL and deal with NULL */
int _strcmp(char *s, char *t) {
	if(s==NULL || t==NULL) return 1;
	while(!_eol(*s) && !_eol(*t) && _eq(*s,*t)) {
		++s;
		++t;
	}
	return _eol(*s) && _eol(*t) ? 0 : 1;
}

/* match a string: 
	space maches anthing <= ' ' (eg 'r', \n', '\t' or ' ' )
	* matches up to the next matching char, result in passed buffer
   returns NULL if mismatch 
                or else the last matched '*' 
                or s if no '*' is present
*/
static char *match(char *_s, char *_p, ...) {
	char *s = _s, *p = _p;
	char *ret = s;
	va_list ap;
	
	va_start(ap, _p);
	while(!_eol(*s) && *p) {
        // if(*p==' ' || *p=='\t') {
        // while(*p==' ' || *p=='\t') ++p;
        // if(*s!=' ' && *s!='\t') {r = NULL; break;}
        // do ++s; while(*s==' ' || *s=='\t');
		if(*p==' ') {while(*p==' ') ++p;
			if(!_eq(' ', *s)) {
				ret = NULL; 
				break;
			}
			while(!_eol(*s) && _eq(' ', *s)) ++s;
		} else if(*p=='*') {
			char *m = va_arg(ap, char*); ++p;
			if(*p && _eq(*p, *s)) { /* matches at lease one char */
				ret = NULL; 
				break;
			}
			ret = m == NULL ? s : m;
			do {
				if(m) *m++ = *s; 
				++s;
			} while(!_eol(*s) && !_eq(*p, *s));
			if(m) *m='\0';
		} else if(_toUpper(*s++) != _toUpper(*p++)) {
			ret = NULL; 
			break;
		}
	}
	va_end(ap);
	
	return *p=='\0' ? ret : NULL;
}

int sets_flag(char *buf, char REG) {
	char tmp[MAX_TEMPORARY_STORAGE];
	
	if(match(buf, " ADD* ", tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " ASL*",  tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " ASR*",  tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " COM*",  tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " DEC*",  tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " EOR* ", tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " INC* ", tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " LD* ",  tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " LSL*",  tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " LSR*",  tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " OR* ",  tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " ROL*",  tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " ROR*",  tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " SBC* ", tmp) && _toUpper(*tmp)==REG) return 1;
	if(match(buf, " SUB* ", tmp) && _toUpper(*tmp)==REG) return 1;
	
	return 0;
}

/* can this opcode make A non zero */
int can_nzA(char *buf) {
	char *s;
	for(s = buf; !_eol(*s) && *s!=','; ++s);
	if(!match(buf, " ")) return 1;
	if(match(buf, " ADDA ")) return 1;
	if(match(buf, " ADDD ")) return 1;
	if(match(buf, " BSR ")) return 1;
	if(match(buf, " COMA")) return 1;
	if(match(buf, " DECA")) return 1;
	if(match(buf, " EORA ")) return 1;
	if(match(buf, " EXG ")) return 1;
	if(match(buf, " INCA")) return 1;
	if(match(buf, " JSR ")) return 1;
	if(match(buf, " LDA ")) return 1;
	if(match(buf, " LDD ")) return 1;
	if(match(buf, " ORA ")) return 1;
	if(match(buf, " PULS ")) return 1;
	if(match(buf, " PULU ")) return 1;
	if(match(buf, " ROLA ")) return 1;
	if(match(buf, " RORA ")) return 1;
	if(match(buf, " RTI")) return 1;
	if(match(buf, " RTS")) return 1;
	if(match(buf, " SBCA ")) return 1;
	if(match(buf, " SEX")) return 1;
	if(match(buf, " SUBA ")) return 1;
	if(match(buf, " SUBD ")) return 1;
	if(match(buf, " TFR ") && s[0]==',' && s[1]=='A') return 1;
				
	return 0;
}

/* can this opcode make B non zero */
int can_nzB(char *buf) {
	char *s;
	for(s = buf; !_eol(*s) && *s!=','; ++s);
	if(!match(buf, " ")) return 1;
	if(match(buf, " ADDB ")) return 1;
	if(match(buf, " ADDD ")) return 1;
	if(match(buf, " BSR ")) return 1;
	if(match(buf, " COMB")) return 1;
	if(match(buf, " DECB")) return 1;
	if(match(buf, " EORB ")) return 1;
	if(match(buf, " EXG ")) return 1;
	if(match(buf, " INCB")) return 1;
	if(match(buf, " JSR ")) return 1;
	if(match(buf, " LDB ")) return 1;
	if(match(buf, " LDD ")) return 1;
	if(match(buf, " ORB ")) return 1;
	if(match(buf, " PULS ")) return 1;
	if(match(buf, " PULU ")) return 1;
	if(match(buf, " ROLB")) return 1;
	if(match(buf, " RORB")) return 1;
	if(match(buf, " RTI")) return 1;
	if(match(buf, " RTS")) return 1;
	if(match(buf, " SBCB ")) return 1;
	if(match(buf, " SUBB ")) return 1;
	if(match(buf, " SUBD ")) return 1;
	if(match(buf, " TFR ") && s[0]==',' && s[1]=='B') return 1;
	return 0;
}

int is_Bcc(char * buf) {
	if(match(buf, " BGT ")) return 1;
	if(match(buf, " BLE ")) return 1;
	if(match(buf, " BGE ")) return 1;
	if(match(buf, " BLT ")) return 1;
	if(match(buf, " BEQ ")) return 1;
	if(match(buf, " BNE ")) return 1;
	if(match(buf, " BHI ")) return 1;
	if(match(buf, " BLS ")) return 1;
	if(match(buf, " BHS ")) return 1;
	if(match(buf, " BLO ")) return 1;
	if(match(buf, " BMI ")) return 1;
	if(match(buf, " BPL ")) return 1;
		
	if(match(buf, " LBGT ")) return 1;
	if(match(buf, " LBLE ")) return 1;
	if(match(buf, " LBGE ")) return 1;
	if(match(buf, " LBLT ")) return 1;
	if(match(buf, " LBEQ ")) return 1;
	if(match(buf, " LBNE ")) return 1;
	if(match(buf, " LBHI ")) return 1;
	if(match(buf, " LBLS ")) return 1;
	if(match(buf, " LBHS ")) return 1;
	if(match(buf, " LBLO ")) return 1;
	if(match(buf, " LBMI ")) return 1;
	if(match(buf, " LBPL ")) return 1;

	return 0;
}

static int change; /* number of lines changed */

static void optim(char *buffer, char *rule, char *repl, ...) {
	char tmp[MAX_TEMPORARY_STORAGE];
	
	*tmp = '\0';
	if(rule) {
		strcat(tmp, "; peephole: ");
		strcat(tmp, rule);
		strcat(tmp, "\n");
	}
	
	strcat(tmp, ";"); strcat(tmp, buffer);
	
	if(repl) {
		va_list ap;
		va_start(ap, repl);
		vsprintf(tmp + strlen(tmp), repl, ap);
		va_end(ap);
		strcat(tmp, "\n");
	}
	
	strcpy(buffer, tmp);
	
	++change;
}

static char *chkLDD(char *buffer, char *xxyy, char *buf) {
	return match( buffer, " LDD #$*", buf) &&
		strlen(buf)>=4 && 
		(xxyy[0]=='-' || xxyy[0]==buf[0]) &&
		(xxyy[1]=='-' || xxyy[1]==buf[1]) &&
		(xxyy[2]=='-' || xxyy[2]==buf[2]) &&
		(xxyy[3]=='-' || xxyy[3]==buf[3]) ? buf : NULL;
}

static int isZero(char *buf) {
	if(buf==NULL) return 0;
	
	if(*buf == '$') ++buf;
	while(*buf=='0') ++buf;
	
	return _eq(' ', *buf);
}

void target_peephole_optimizer( Environment * _environment ) {
	int keep_comments = 1;
	int unsafe = 1;
    char fileNameOptimized[MAX_TEMPORARY_STORAGE];

    sprintf( fileNameOptimized, "%s.asm", tmpnam(NULL) );

    char buffer[4][MAX_TEMPORARY_STORAGE];
	int pass = 0;
	
	for(change=1; change;) {
		FILE * fileAsm = fopen( _environment->asmFileName, "rt" );
		FILE * fileOptimized = fopen( fileNameOptimized, "wt" );

		int line = 0;	
		int zA = 0, zB = 0;
		
		*buffer[0] = *buffer[1] = *buffer[2] = *buffer[3] = change = 0;
		++pass;
    
		while( !feof( fileAsm ) ) {
			char variable1[MAX_TEMPORARY_STORAGE];
			char variable2[MAX_TEMPORARY_STORAGE];
			char variable3[MAX_TEMPORARY_STORAGE];
			char variable4[MAX_TEMPORARY_STORAGE];
			
			if ( line > 3 ) {
				fputs( buffer[0], fileOptimized );
			}
			strcpy( buffer[0], buffer[1] );
			strcpy( buffer[1], buffer[2] );
			strcpy( buffer[2], buffer[3] );
			do {
				fgets( buffer[3], MAX_TEMPORARY_STORAGE, fileAsm );
				/* merge comment with previous line */
				if(isAComment(buffer[3]) && strlen(buffer[2]) + strlen(buffer[3]) + 1 <= MAX_TEMPORARY_STORAGE) {
					if(keep_comments)	strcat(buffer[2], buffer[3]);
					buffer[3][0] = '\0';
				} else break;
			} while(!feof( fileAsm ) );

			if ( match( buffer[0], " ST* *", variable1, variable2 )
            &&   match( buffer[1], " LD* *", variable3, variable4 )
			&&   strcmp(variable1, variable3)==0
			&&   strcmp(variable2, variable4)==0) {
				if(unsafe && match(variable2, "_Ttmp") && !match(buffer[2], "*SR ") && !(*variable1=='D' && match(buffer[2], " IF "))) {
					char *fmt = NULL;
					/* in case flags are necessary (IF,LBcc), insert TST or LEAX */
					if(match(buffer[2], " IF ") && match(buffer[3], " LB")) 
						fmt = *variable1=='X' ? "\tLEAX ,X" : "\tTST%c";
					optim( buffer[0], "(unsafe, presumed dead)", fmt, _toUpper(*variable1));
				}
				optim( buffer[1], "rule #1 (STORE*,LOAD*)", NULL);
			}

			if ( match( buffer[0], " CLR *", variable1 )
            &&   match( buffer[2], " ST* *", variable2, variable3 )
			&&   strchr("AB", _toUpper(*variable2))
			&&   strcmp(variable1, variable3)==0) {
				optim( buffer[0], "rule #2 (CLEAR*,LOAD*)", NULL);
			}
			
			if ( isZero(match(buffer[0], " LD* #*", variable1, variable2) )
		    && 	 strchr("AB", _toUpper(*variable1)) ) {
				optim(buffer[0],"rule #3 (LOAD#0)", "\tCLR%c", _toUpper(*variable1));
			}
			
			if ( match(buffer[0], " EOR* #$ff", variable1)
			&& 	 strchr("AB", _toUpper(*variable1)) ) {
				optim(buffer[0], "rule #4 (EOR #$FF)", "\tCOM%c", _toUpper(*variable1));
			}
			
			if ( (match(buffer[0], " LD* ", variable1) || match(buffer[0], " CLR*", variable1))
			&&   match(buffer[1], " LD* ", variable2)
			&&   *variable1 == *variable2) {
				optim(buffer[0], "rule #5 (LOAD/CLR,LOAD)", NULL);
			}
			
			if ( match( buffer[0], " LD")
			&&   match( buffer[1], " ST")
			&& _strcmp( buffer[2], buffer[0] )==0
			&& unsafe) {
				optim( buffer[2], "rule #6 (LOAD*,STORE,LOAD*)", NULL);
			}
			
			if ( match(buffer[0], " ST* *", NULL, variable1)
			&&   match(buffer[1], " LD* *", NULL, variable2)
			&& _strcmp(variable1, variable2)!=0
		    && _strcmp(buffer[0],buffer[2])==0 ) {
				optim(buffer[0], "rule #7 (STORE*->LOAD->STORE*)", NULL);
			}
			
			if ( match(buffer[0], " ST")
			&& _strcmp(buffer[0], buffer[1])==0) {
				optim(buffer[0], "rule #8 (STORE*,STORE*)", NULL);
			}
			if ((match(buffer[0], " ST* *+", NULL, variable1) || match(buffer[0], " ST* *", NULL, variable1)) 
			&&   match(buffer[1], " * *", NULL, variable2) &&  strcmp(variable1, variable2) !=0
			&& _strcmp(buffer[2], buffer[0])==0) {
				optim(buffer[0], "rule #8 (STORE*,?,STORE*)", NULL);
			}
			if ((match(buffer[0], " ST* *+", NULL, variable1) || match(buffer[0], " ST* *", NULL, variable1)) 
			&&   match(buffer[1], " * *", NULL, variable2) &&  strcmp(variable1, variable2) !=0
			&&   match(buffer[2], " * *", NULL, variable2) &&  strcmp(variable1, variable2) !=0
			&& _strcmp(buffer[3], buffer[0])==0) {
				optim(buffer[0], "rule #8 (STORE*,?,?,STORE*)", NULL);
			}
			
			if( (match(buffer[0], " LD* ", variable1) || match(buffer[0], " ST* ",variable1))
			&&  isZero(match(buffer[1], " CMP* #*", variable2, variable3))
			&&	*variable1==*variable2) {
				optim(buffer[1], "rule #9 (LOAD/STORE,CMP #0)", NULL);
			}
			
			if ( match(buffer[0], " LDD *", variable1)
			&&   match(buffer[1], " STD _Ttmp*", variable2)
			&&   match(buffer[2], " LDX *", variable3)
			&&   match(buffer[3], " CMPX _Ttmp*", variable4)
			&&  _strcmp(variable2, variable4)==0) {
				if(unsafe) {
					optim(buffer[0], "rule #10 (LDD,STD*,LDX,CMPX*)",  
						variable1[0]=='#' && variable1[1]=='$' && variable1[2]=='0' && variable1[3]=='0'
						? "\tCLRA" : NULL);
					optim(buffer[1], "(unsafe, presumed dead)", NULL);
					optim(buffer[3], NULL, "\tCMPX %s", variable1);
				} else {
					optim(buffer[3], "rule #10 (LDD,STD*,LDX,CMPX*)", "\tCMPX %s", variable1);
				}
			}

			if ( match(buffer[0], " LDD *", variable1)
			&&   match(buffer[1], " STD _Ttmp*", variable2)
			&&   match(buffer[2], " LDD *", variable3)
			&&   match(buffer[3], " ADD _Ttmp*", variable4)
			&&  _strcmp(variable2, variable4)==0) {
				if(unsafe) {
					optim(buffer[0], "rule #11 (LDD,STD*,LDD,ADDD*)", NULL);
					optim(buffer[1], "(unsafe, presumed dead)", NULL);
					optim(buffer[3], NULL, "\tADDD %s", variable1);
				} else {
					optim(buffer[3], "rule #11 (LDD,STD*,LDD,ADDD*)", "\tADDD %s", variable1);
				}
			}

			if ( match(buffer[0], " STD *", variable1)
			&&   match(buffer[1], " LDX *", variable2)
			&&   _strcmp(variable1,variable2)==0) {
				if(unsafe) optim(buffer[0], "(unsafe, presumed dead)", NULL);
				optim(buffer[1], "rule #12 (STD*,LDX*)", "\tTFR D,X");
			}
			
			if ( match(buffer[0], " STD *", variable1)
			&&   match(buffer[1], " LDA *+1", variable2)
			&&   strcmp(variable1, variable2)==0) {
				if(unsafe) optim(buffer[0], "(unsafe, presumed dead)", NULL);
				optim(buffer[1], "rule #13 (STD,LDA+1)", "\tTFR B,A");
			}

			if ( match(buffer[0], " LDD #*", variable1)
			&&   match(buffer[1], " ADDD #*", variable2)) {
				optim(buffer[0], "rule #14 (LDD#,ADD#)", "\tLDD #%s+%s", variable1, variable2);
				optim(buffer[1], NULL, NULL);
			}
			
			if ( match(buffer[0], " STX *", variable1)
			&&   match(buffer[1], " CLRA")
			&&   match(buffer[2], " LDX *", variable2)
			&&   _strcmp(variable1,variable2)==0) {
				optim(buffer[0], "rule #15 (STX*,CLRA,LDX*)", NULL);
				optim(buffer[2], NULL, "\tSTX %s", variable1);
			}

			if ( match(buffer[0], " STD *", variable1)
			&&   match(buffer[1], " LDD *", variable2)
			&&   match(buffer[2], " ADDD *", variable3)
			&&   strcmp(variable1,variable3)==0) {
				if(unsafe) optim(buffer[0], "(unsafe, presumed dead)", NULL);
				optim(buffer[1], "rule #16 (STD*,LDD,ADD*)", NULL);
				optim(buffer[2], NULL, "\tADDD %s", variable2);
			}

			if ( match(buffer[0], " STA *", variable1) 
			&&   match(buffer[1], " LDA *", variable2)
			&&   match(buffer[2], " *A *", variable3, variable4) 
			&&   strcmp(variable1,variable4)==0
			&&   (match(variable3, "OR") || match(variable3,"AND") || match(variable3,"EOR") || match(variable3,"ADD"))
			) {
				if(unsafe) optim(buffer[0], "(unsafe, presumed dead)", NULL);
				optim(buffer[1], "rule #17 (STA*,LDA,ORA/ANDA/EORA/ADDA*)", NULL);
				optim(buffer[2], NULL, "\t%sA %s", variable3, variable2);
			}


			if ( match(buffer[0], " STD _Ttmp*", variable1)
			&&   match(buffer[1], " LD* [_Ttmp*]", variable2, variable3)
			&&   strcmp(variable1,variable3)==0) {
				if(unsafe) optim(buffer[0], "(unsafe, presumed dead)", NULL);
				optim(buffer[1], "rule #18 (STD,LDD[])", "\tTFR D,X\n\tLD%c ,X", _toUpper(*variable2));
			}

			if ( match(buffer[0], " STD _Ttmp*", variable1)
			&&   match(buffer[1], " LD* ", variable2)
			&&   match(buffer[2], " ST* [_Ttmp*]", variable3, variable4)
			&&   *variable2==*variable3
			&&   strcmp(variable1,variable4)==0
			&&   unsafe) {
				optim(buffer[0], "(unsafe, presumed dead)", "\tTFR D,X");
				optim(buffer[2], "rule #19 (STD,LOAD,STORE[])", "\tST%c ,X", *variable2);
			}
			
			if ( match(buffer[1], " TST*", variable1)
			&&  sets_flag(buffer[0], *variable1)) {
				optim(buffer[1], "rule #20 (FLAG-SET,TST)", NULL);
			}
			
			if ( match(buffer[0], " LDB #$01")
			&&   match(buffer[1], " LDX *", variable1)
			&&	 match(buffer[2], " JSR CPUMATHMUL16BITTO32*", NULL)) {
				optim(buffer[0], "rule #21 (MUL#1)", "\tLDD %s", variable1);
				optim(buffer[1], NULL, "\tLDX #0");
				optim(buffer[2], NULL, NULL);
			}
			
			// if ( match(buffer[0], " LDX ") && match(buffer[1], " CLRA")) {
				// strcpy(buffer[1], buffer[0]);
				// strcpy(buffer[0], "\tCLRA\n");
			// }
						
			// more complex
			if(zA) {
				if (match( buffer[0], " CLRA")) {
					optim( buffer[0], "rule #1000 (A=0)", NULL);
				} else if (match( buffer[0], " LDA #$ff")) {
					optim( buffer[0], "rule #1001 (A=0)", "\tDECA");
					zA = 0;
				} else if (match( buffer[0], " LDA #$01")) {
					optim( buffer[0], "rule #1002 (A=0)", "\tINCA");
					zA = 0;
				} else if ( chkLDD( buffer[0], "00--", variable1)) {
					optim(buffer[0], "rule #1003 (A=0)", "\tLDB #$%c%c", variable1[2], variable1[3]);
					zB = 0;
				} else if(can_nzA(buffer[0])) {
					zA = 0;
				}
			} else if ( chkLDD(buffer[0], "00--", variable1) || match( buffer[0], " LDD #0") || match( buffer[0], " CLRA") ) {
				zA = 1;
			}
			
			if(zB) {
				if (match( buffer[0], " CLRB")) {
					optim( buffer[0], "rule #1004 (B=0)", NULL);
				} else if (match( buffer[0], " LDB #$ff")) {
					optim( buffer[0], "rule #1005 (B=0)", "\tDECB");
					zB = 0;
				} else if (match( buffer[0], " LDB #$01")) {
					optim( buffer[0], "rule #1006 (B=0)", "\tINCB");
					zB = 0;
				} else if ( chkLDD(buffer[0], "--00", variable1) ) {
					optim(buffer[0], "rule #1007 (B=0)", "\tLDA #$%c%c", variable1[0], variable1[1]);
					zA = 0;
				} else if (match( buffer[0], " TFR B,A")) {
					optim( buffer[0], "rule #1008 (B=0)", "\tCLRA");
					zA = 1;
				} else if(can_nzB(buffer[0])) {
					zB = 0;
				}
			} else if ( chkLDD(buffer[0], "--00", variable1) || match( buffer[0], " LDD #0") || match( buffer[0], " CLRB") ) {
				zB = 1;
			}
			++line;
		}

		fputs( buffer[0], fileOptimized );
		fputs( buffer[1], fileOptimized );
		fputs( buffer[2], fileOptimized );
		fprintf(fileOptimized, "; peephole: pass %d, %d change%s.\n", pass, change, change>1 ?"s":"");

		fclose( fileAsm );
		fclose( fileOptimized );

		rename( fileNameOptimized, _environment->asmFileName );
	}
}

