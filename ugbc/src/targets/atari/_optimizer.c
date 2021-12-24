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

void target_peephole_optimizer( Environment * _environment ) {

    char fileNameOptimized[MAX_TEMPORARY_STORAGE];

    sprintf( fileNameOptimized, "%s.asm", get_temporary_filename( _environment ) );

    FILE * fileAsm = fopen( _environment->asmFileName, "rt" );
    FILE * fileOptimized = fopen( fileNameOptimized, "wt" );

    char buffer[3][MAX_TEMPORARY_STORAGE];

    int line = 0;
    
    while( !feof( fileAsm ) ) {
        if ( line > 2 ) {
            fputs( buffer[0], fileOptimized );
        }
        strcpy( buffer[0], buffer[1] );
        strcpy( buffer[1], buffer[2] );
        do {
            (void)!fgets( buffer[2], MAX_TEMPORARY_STORAGE, fileAsm );
        } while( isAComment( buffer[2] ) && !feof( fileAsm ) );

        // LDA x, STA y, LDA x => LDA x, STA y

        if ( strstr( buffer[0], "\tLDA " ) != NULL && strstr( buffer[1], "\tSTA " ) != NULL && strstr( buffer[2], "\tLDA " ) != NULL && strcmp( buffer[2], buffer[0] ) == 0 ) {
            strcpy( buffer[2], "; peephole: rule #1 (LDA,STA,LDA->LDA,STA)\n");
        }

        // LDA x, STA y, LDA y => LDA x, STA y

        if ( strstr( buffer[0], "\tLDA " ) != NULL && strstr( buffer[1], "\tSTA " ) != NULL && strstr( buffer[2], "\tLDA " ) != NULL ) {
            char * variable1 = strchr( buffer[1], '_' );
            char * variable2 = strchr( buffer[2], '_' );
            if (variable1 && variable2) {
                if ( strcmp( variable1, variable2 ) == 0 ) {
                    strcpy( buffer[2], "; peephole: rule #2 (LDA,STA,LDA->LDA,STA)\n");
                }            
            }            
        }

        ++line;
    }

    fputs( buffer[0], fileOptimized );
    fputs( buffer[1], fileOptimized );
    // fputs( buffer[2], fileOptimized );

    fclose( fileAsm );
    fclose( fileOptimized );

    remove( _environment->asmFileName );
    
    rename( fileNameOptimized, _environment->asmFileName );

}

