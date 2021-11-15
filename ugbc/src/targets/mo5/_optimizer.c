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
		} else if(*s++ != *p++) {r = NULL; break;}
	}
	// printf("match '%s' '%s'==%d\n", _p, _s, *p=='\0' && r!=NULL);
	return *p=='\0' ? r : NULL;
}

int canChgLD00xx(char *opcode) {
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

void target_peephole_optimizer( Environment * _environment ) {

    char fileNameOptimized[MAX_TEMPORARY_STORAGE];

    sprintf( fileNameOptimized, "%s.asm", tmpnam(NULL) );

    char buffer[4][MAX_TEMPORARY_STORAGE];
	int pass = 0;
	
	for(change=1; change;) {
		FILE * fileAsm = fopen( _environment->asmFileName, "rt" );
		FILE * fileOptimized = fopen( fileNameOptimized, "wt" );

		int line = 0;	
		int LDD00xx = 0;
		
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
				optim(buffer[0],"rule #5 (LDA #0->CLRA)", "\tCLRA\n");
			}
			if(LDD00xx) {
				if (match( buffer[0], " CLRA")) {
					optim( buffer[0], "rule #6 (A already 0)", NULL);
				} else
				if ((variable1=match( buffer[0], " LDD #$00*"))!=NULL && strlen(variable1)>=2) {
					char buf[MAX_TEMPORARY_STORAGE];
					sprintf(buf, "\tLDB #$%c%c\n", variable1[0], variable1[1]);
					optim(buffer[0], "rule #7 (A already 0)", buf);
				} else {
					if(!isAComment(buffer[0]) && canChgLD00xx(match(buffer[0], " *"))) {
						// printf("A!=0 %s\n", buffer[0]);
						LDD00xx = 0; 
					}
				}
			} else if ( match( buffer[0], " LDD #$00")
				   ||   match( buffer[0], " LDD #0")
			       ||   match( buffer[0], " CLRA") ) {
				// printf("A==0 %s\n", buffer[0]);
				LDD00xx = 1;
			}
			
			if ( (variable1 = match( buffer[0], " LD* *" ))!=NULL 
			&&                match( buffer[1], " ST*")
            &&   (variable2 = match( buffer[2], " LD* *" ))!=NULL
			&&   _strcmp(variable1, variable2)==0) {
				optim( buffer[2], "rule #8 (LD* Z->ST*->LD* Z)", NULL);
				++change;
			}
			if ( (variable1 = match(buffer[0], " ST* *"))!=NULL
			&&   (variable2 = match(buffer[1], " LD* *"))!=NULL
			&& _strcmp(variable1, variable2)!=0
		    && _strcmp(buffer[0],buffer[2])==0 ) {
				optim(buffer[0], "rule #10 (STr Z->LD*->STr Z)", NULL);
			}
			if ( (variable1 = match(buffer[0], " LD* "))!=NULL
			&&   (variable2 = match(buffer[1], " LD* "))!=NULL
			&&    *variable1 == *variable2) {
				optim(buffer[0], "rule #11 (LDr->LDr)", NULL);
			}
			if ( match(buffer[0], " ST* *")
			&& _strcmp(buffer[0], buffer[1])==0) {
				optim(buffer[1], "rule #12 (STr *->STr *)", NULL);
			}
			if ( (variable1=match(buffer[0], " EOR* #$ff"))!=NULL ) {
				char buf[8]; sprintf(buf, "\tCOM%c\n", *variable1);
				optim(buffer[0], "rule #13 (EORr #$FF-->COMr)", buf);
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
				// optim(buffer[0], "test", NULL);
				// optim(buffer[1], "test", NULL);
				optim(buffer[3], "rule #14 (LDD *->STD Z->LDX *->CMPX Z)", buf);
			}
			if( match(buffer[0], " LDX ")
			&&  match(buffer[1], " CMPX #$0000")) {
				optim(buffer[1], "rule #15 (LDr->CMPr #0)", NULL);
			}
			if( match(buffer[0], " LDY ")
			&&  match(buffer[1], " CMPY #$0000")) {
				optim(buffer[1], "rule #15 (LDr->CMPr #0)", NULL);
			}
			if( match(buffer[0], " LDU ")
			&&  match(buffer[1], " CMPU #$0000")) {
				optim(buffer[31], "rule #15 (LDr->CMPr #0)", NULL);
			}
			if( match(buffer[0], " LDA ")
			&&  match(buffer[1], " CMPA #$00")) {
				optim(buffer[1], "rule #15 (LDr->CMPr #0)", NULL);
			}
			if( match(buffer[0], " LDB ")
			&&  match(buffer[1], " CMPB #$00")) {
				optim(buffer[1], "rule #15 (LDr->CMPr #0)", NULL);
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

