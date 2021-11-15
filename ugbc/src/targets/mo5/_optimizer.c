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

/* a version of strcmp that ends at EOL and deal with NULL */
int _strcmp(char *s, char *t) {
	if(s==NULL || t==NULL) return 1;
	while(*s && *t && *s!='\r' && *t!='\r' && *s!='\n' && *t!='\n' && *s==*t) {
		++s;
		++t;
	}
	return *s - *t;
}

static inline char _toUpper(char a) {
	return (a>='a' && a<='z') ? a-'a'+'A' : a;
}

/* match a string: 
	space maches any '\t' or ' ' 
	* matches any non space
   returns NULL if no match or else the last matched '*' 
                            or s if no '*' is present
*/
char *match(char *s, char *p) {
	char *r = s, *_s = s, *_p = p;
	while(*s && *s!='\r' && *s!='\n' && *p) {
		if(*p==' ' || *p=='\t') {
			while(*p==' ' || *p=='\t') ++p;
			if(*s!=' ' && *s!='\t') {r = NULL; break;}
			do ++s; while(*s==' ' || *s=='\t');
		} else if(*p=='*') {
			while(*p=='*') ++p;
			if(*s==' ' || *s=='\t') {r = NULL; break;}
			r = s; do ++s; while(*s && *s!=' ' && *s!='\t');
		} else if(_toUpper(*s++) != _toUpper(*p++)) {r = NULL; break;}
	}
	// printf("match '%s' '%s'==%d\n", _p, _s, *p=='\0' && r!=NULL);
	return *p=='\0' ? r : NULL;
}

/* can this opcode make A non zero */
int can_nzA(char *opcode) {
	if(opcode==NULL) return 1;
	if(match(opcode, "ADDA ")) return 1;
	if(match(opcode, "ADDD ")) return 1;
	if(match(opcode, "BSR ")) return 1;
	if(match(opcode, "COMA")) return 1;
	if(match(opcode, "DECA")) return 1;
	if(match(opcode, "EORA ")) return 1;
	if(match(opcode, "EXG ")) return 1;
	if(match(opcode, "JSR ")) return 1;
	if(match(opcode, "LDA ")) return 1;
	if(match(opcode, "LDD ")) return 1;
	if(match(opcode, "ORA ")) return 1;
	if(match(opcode, "PULS ")) return 1;
	if(match(opcode, "PULU ")) return 1;
	if(match(opcode, "ROLA")) return 1;
	if(match(opcode, "RORA")) return 1;
	if(match(opcode, "RTI")) return 1;
	if(match(opcode, "RTS")) return 1;
	if(match(opcode, "SBCA ")) return 1;
	if(match(opcode, "SEX")) return 1;
	if(match(opcode, "SUBA ")) return 1;
	if(match(opcode, "SUBD ")) return 1;
	if(match(opcode, "TFR")) return 1;
	return 0;
}

/* can this opcode make B non zero */
int can_nzB(char *opcode) {
	if(opcode==NULL) return 1;
	if(match(opcode, "ADDB ")) return 1;
	if(match(opcode, "ADDD ")) return 1;
	if(match(opcode, "BSR ")) return 1;
	if(match(opcode, "COMB")) return 1;
	if(match(opcode, "DECB")) return 1;
	if(match(opcode, "EORB ")) return 1;
	if(match(opcode, "EXG ")) return 1;
	if(match(opcode, "JSR ")) return 1;
	if(match(opcode, "LDB ")) return 1;
	if(match(opcode, "LDD ")) return 1;
	if(match(opcode, "ORB ")) return 1;
	if(match(opcode, "PULS ")) return 1;
	if(match(opcode, "PULU ")) return 1;
	if(match(opcode, "ROLB")) return 1;
	if(match(opcode, "RORB")) return 1;
	if(match(opcode, "RTI")) return 1;
	if(match(opcode, "RTS")) return 1;
	if(match(opcode, "SBCB ")) return 1;
	if(match(opcode, "SUBB ")) return 1;
	if(match(opcode, "SUBD ")) return 1;
	if(match(opcode, "TFR")) return 1;
	return 0;
}

static int change;
static void optim(char *buffer, char *rule, char *repl) {
	char tmp[MAX_TEMPORARY_STORAGE];
	
	strcpy(tmp, "; peephole: ");
	strcat(tmp, rule);
	strcat(tmp, "\n;");
	strcat(tmp, buffer);
	if(repl) strcat(tmp, repl);
	strcpy(buffer, tmp);
	
	++change;
}

static char *chkLDD(char *buffer, char *xxyy) {
	char *s = match( buffer, " LDD #$*");
	return s && 
		strlen(s)>=4 && 
		(xxyy[0]=='-' || xxyy[0]==s[0]) &&
		(xxyy[1]=='-' || xxyy[1]==s[1]) &&
		(xxyy[2]=='-' || xxyy[2]==s[2]) &&
		(xxyy[3]=='-' || xxyy[3]==s[3]) ? s : NULL;
}

static int isZero(char *buf) {
	if(buf==NULL) return 0;
	if(*buf == '$') ++buf;
	while(*buf=='0') ++buf;
	return *buf=='\0' || *buf=='\t' || *buf==' ' || *buf=='\r' || *buf=='\n';
}

void target_peephole_optimizer( Environment * _environment ) {
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
			char *variable1, *variable2, *variable3;
			
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
					strcat(buffer[2], buffer[3]);
					buffer[3][0] = '\0';
				} else break;
			} while(!feof( fileAsm ) );

			if ( (variable1 = match( buffer[0], " STA *" ))!=NULL 
            &&   (variable2 = match( buffer[1], " LDA *" ))!=NULL
			&&   _strcmp(variable1, variable2)==0) {
				optim( buffer[1], "rule #1 (STA->LDA)", NULL);
			}
			if ( (variable1 = match( buffer[0], " STD *" ))!=NULL 
            &&   (variable2 = match( buffer[1], " LDD *" ))!=NULL
			&&   _strcmp(variable1, variable2)==0) {
				optim( buffer[1], "rule #2 (STD->LDD)", NULL);
			}
			if ( (variable1 = match( buffer[0], " STX *" ))!=NULL 
            &&   (variable2 = match( buffer[1], " LDX *" ))!=NULL
			&&   _strcmp(variable1, variable2)==0) {
				optim( buffer[1], "rule #3 (STX->LDX)", NULL);
			}
			if ( (variable1 = match( buffer[0], " CLR *" ))!=NULL 
            &&   (variable2 = match( buffer[2], " ST* *" ))!=NULL
			&&   _strcmp(variable1, variable2)==0) {
				optim( buffer[0], "rule #4 (CLR->ST*)", NULL);
			}
			if ( match(buffer[0], " LDA #0") 
		    ||   match(buffer[0], " LDA #$00")) {
				optim(buffer[0],"rule #5 (LDr #0->CLRr)", "\tCLRA\n");
			}
			if ( match(buffer[0], " LDB #0") 
		    ||   match(buffer[0], " LDB #$00")) {
				optim(buffer[0],"rule #5 (LDr #0->CLRr)", "\tCLRB\n");
			}
			if ( (variable1 = match( buffer[0], " LD* *" ))!=NULL 
			&&                match( buffer[1], " ST*")
            &&   (variable2 = match( buffer[2], " LD* *" ))!=NULL
			&&   _strcmp(variable1, variable2)==0) {
				optim( buffer[2], "rule #6 (LD* Z->ST*->LD* Z)", NULL);
				++change;
			}
			if ( (variable1 = match(buffer[0], " ST* *"))!=NULL
			&&   (variable2 = match(buffer[1], " LD* *"))!=NULL
			&& _strcmp(variable1, variable2)!=0
		    && _strcmp(buffer[0],buffer[2])==0 ) {
				optim(buffer[0], "rule #7 (STr Z->LD*->STr Z)", NULL);
			}
			if ( (variable1 = match(buffer[0], " LD* "))!=NULL
			&&   (variable2 = match(buffer[1], " LD* "))!=NULL
			&&    *variable1 == *variable2) {
				optim(buffer[0], "rule #8 (LDr->LDr)", NULL);
			}
			if ( match(buffer[0], " ST* *")
			&& _strcmp(buffer[0], buffer[1])==0) {
				optim(buffer[1], "rule #9 (STr *->STr *)", NULL);
			}
			if ( (variable1=match(buffer[0], " EOR* #$ff"))!=NULL ) {
				char buf[8]; sprintf(buf, "\tCOM%c\n", *variable1);
				optim(buffer[0], "rule #10 (EORr #$FF-->COMr)", buf);
			}

			if(        match(buffer[0], " LDD ")
			&&  isZero(match(buffer[1], " CMPD #*"))) {
				optim(buffer[1], "rule #11 (LDr->CMPr #0)", NULL);
			}
			if(        match(buffer[0], " LDX ")
			&&  isZero(match(buffer[1], " CMPX #*"))) {
				optim(buffer[1], "rule #11 (LDr->CMPr #0)", NULL);
			}
			if(        match(buffer[0], " LDY ")
			&&  isZero(match(buffer[1], " CMPY #*"))) {
				optim(buffer[1], "rule #11 (LDr->CMPr #0)", NULL);
			}
			if(        match(buffer[0], " LDU ")
			&&  isZero(match(buffer[1], " CMPU #*"))) {
				optim(buffer[31], "rule #11 (LDr->CMPr #0)", NULL);
			}
			if(        match(buffer[0], " LDA ")
			&&  isZero(match(buffer[1], " CMPA #*"))) {
				optim(buffer[1], "rule #11 (LDr->CMPr #0)", NULL);
			}
			if(        match(buffer[0], " LDB ")
			&&  isZero(match(buffer[1], " CMPB #*"))) {
				optim(buffer[1], "rule #11 (LDr->CMPr #0)", NULL);
			}

			if ( (variable1=match(buffer[0], " LDD *"))!=NULL
			&&   (variable2=match(buffer[1], " STD _Ttmp*"))!=NULL
			&&              match(buffer[2], " LDX ")
			&&   (variable3=match(buffer[3], " CMPX _Ttmp*"))!=NULL
			&& _strcmp(variable2, variable3)==0) {
				char buf[MAX_TEMPORARY_STORAGE], *s;
				sprintf(buf, "\tCMPX %s", variable1); 
				for(s=buf+6; *s  && *s!=' ' && *s!='\t'; ++s); 
				*s = '\0';
				if(unsafe) optim(buffer[1], "unsafe", NULL);
				optim(buffer[3], "rule #12 (LDD *->STD <tmp>->LDX *->CMPX <tmp>)", buf);
			}
			if ( (variable1=match(buffer[0], " LDD *"))!=NULL
			&&   (variable2=match(buffer[1], " STD _Ttmp*"))!=NULL
			&&              match(buffer[2], " LDD ")
			&&   (variable3=match(buffer[3], " ADDD _Ttmp*"))!=NULL
			&& _strcmp(variable2, variable3)==0) {
				char buf[MAX_TEMPORARY_STORAGE], *s;
				sprintf(buf, "\tADDD %s", variable1); 
				for(s=buf+6; *s  && *s!=' ' && *s!='\t'; ++s); 
				*s = '\0';
				if(unsafe) optim(buffer[1], "rule #13 (unsafe)", NULL);
				optim(buffer[3], "rule #13 (LDD *->STD <tmp>->LDD *->ADDD <tmp>)", buf);
			}
			if ( (variable1=match(buffer[0], " STD *"))!=NULL
			&&   (variable2=match(buffer[1], " LDX *"))!=NULL
			&&   _strcmp(variable1,variable2)==0) {
				if(unsafe && match(variable1, "_Ttmp")) 
				optim(buffer[0], "rule #14 (unsafe)", NULL);
				optim(buffer[1], "rule #14 (STD <tmp>->LDX <tmp>)", "\tTFR D,X\n");
			}
			// if ( match(buffer[0], " LDD ,X")
			// &&   match(buffer[1], " TFR D,X")) {
				// optim(buffer[0], "rule #15 (unsafe)", NULL);
				// optim(buffer[1], "rule #15 (LDD ,X->TFR D,X", "\tLDX ,X\n");
			// }
			
			if(zA) {
				if (match( buffer[0], " CLRA")) {
					optim( buffer[0], "rule #16 (A already 0)", NULL);
				} else if (match( buffer[0], " LDA #$ff")) {
					optim( buffer[0], "rule #17 (A was 0)", "\tDECA\n");
				} else if (match( buffer[0], " LDA #$01")) {
					optim( buffer[0], "rule #18 (A was 0)", "\tINCA\n");
				} else if ( (variable1=chkLDD( buffer[0], "00--"))!=NULL ) {
					char buf[MAX_TEMPORARY_STORAGE];
					sprintf(buf, "\tLDB #$%c%c\n", variable1[2], variable1[3]);
					optim(buffer[0], "rule #19 (A already 0)", buf);
					zB = 0;
				} else if(!isAComment(buffer[0]) && can_nzA(match(buffer[0], " *"))) {
					zA = 0;
				}
			} else if ( chkLDD(buffer[0], "00--") || match( buffer[0], " LDD #0") || match( buffer[0], " CLRA") ) {
				zA = 1;
			}

			if(zB) {
				if (match( buffer[0], " CLRB")) {
					optim( buffer[0], "rule #320 (B already 0)", NULL);
				} else if (match( buffer[0], " LDB #$ff")) {
					optim( buffer[0], "rule #21 (B was 0)", "\tDECB\n");
				} else if (match( buffer[0], " LDB #$01")) {
					optim( buffer[0], "rule #22 (B was 0)", "\tINCB\n");
				} else if ( (variable1=chkLDD(buffer[0], "--00"))!=NULL ) {
					char buf[MAX_TEMPORARY_STORAGE];
					sprintf(buf, "\tLDA #$%c%c\n", variable1[0], variable1[1]);
					optim(buffer[0], "rule #23 (B already 0)", buf);
					zA = 0;
				} else if(!isAComment(buffer[0]) && can_nzB(match(buffer[0], " *"))) {
					zB = 0;
				}
			} else if ( chkLDD(buffer[0], "--00") || match( buffer[0], " LDD #0") || match( buffer[0], " CLRB") ) {
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

