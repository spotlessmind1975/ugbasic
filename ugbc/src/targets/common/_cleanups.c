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

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit source and configuration lines for game loops
 * 
 * This function can be called to generate all the definitions (on the source
 * file, on the configuration file and on any support file) necessary to 
 * implement the memory banks.
 * 
 * @param _environment Current calling environment
 */
void gameloop_cleanup( Environment * _environment ) {

    if ( _environment->hasGameLoop ) {
        end_gameloop( _environment );
    }
    
}

void end_compilation( Environment * _environment ) {

    gameloop_cleanup( _environment );
    
    if ( !_environment->runParallel && _environment->anyProtothread ) {
        begin_loop( _environment );
        run_parallel( _environment );
        end_loop( _environment );
    }

    halt( _environment );

    if ( _environment->conditionals ) {

        switch( _environment->conditionals->type ) {
            case CT_IF:
                CRITICAL_IF_WITHOUT_ENDIF( );
            case CT_SELECT_CASE:
                CRITICAL_SELECT_CASE_WITHOUT_ENDSELECT( );
        }

    }

    if ( _environment->loops ) {

        switch( _environment->loops->type ) {
            case LT_DO:
                CRITICAL_DO_WITHOUT_LOOP( );
            case LT_WHILE:
                CRITICAL_WHILE_WITHOUT_WEND( );
            case LT_REPEAT:
                CRITICAL_REPEAT_WITHOUT_UNTIL( );
            case LT_FOR:
            case LT_FOR_MT:
                CRITICAL_FOR_WITHOUT_NEXT( );
            case LT_GAMELOOP:
                CRITICAL_BEGIN_GAMELOOP_WITHOUT_END_GAMELOOP( );
        }

    }

    int j=0;
    for( j=0; j<MAX_TEMPORARY_STORAGE; ++j ) {
        if ( _environment->deferredEmbedded[j] ) {
            int size = _environment->deferredEmbeddedSize[j];
            char * parsed = malloc( (8*size) + 1 );
            memset( parsed, 0, (8*size) + 1 );
            char * line = strtok( _environment->deferredEmbedded[j], "\x0a" );
            while( line ) {
                _environment->embedResult.line = line;
                _environment->embedResult.conditional = 0;
                 _environment->embedResult.lineCount = 0;
                embed_scan_string( line );
                embedparse(_environment);
                if ( ! _environment->embedResult.conditional ) {
                    int i;
                    for( i=0; i<_environment->embedResult.current; ++i ) {
                        if ( _environment->embedResult.excluded[i] )
                            break;
                    }
                    if ( i>= _environment->embedResult.current ) {
                        if ( _environment->embedResult.lineCount ) {
                            int j=0;
                            for( j=0; j<_environment->embedResult.lineCount; ++j ) {
                                strcat( parsed, _environment->embedResult.lines[j] );
                                strcat( parsed, "\x0a" );
                                ((Environment *)_environment)->producedAssemblyLines += assemblyLineIsAComment( _environment->embedResult.lines[j] ) ? 0 : 1;
                            }
                        } else {
                            strcat( parsed, line );
                            strcat( parsed, "\x0a" );
                            ((Environment *)_environment)->producedAssemblyLines += assemblyLineIsAComment( line ) ? 0 : 1;
                        }                        
                    }
                }
                line = strtok( NULL, "\x0a" );
            }
            free( _environment->deferredEmbedded[j] );
            fwrite( parsed, strlen( parsed )-1, 1, ((Environment *)_environment)->asmFile );
            free( parsed );
            fputs( "\n", ((Environment *)_environment)->asmFile );
        }
    }

    bank_cleanup( _environment );
    every_cleanup( _environment );
    variable_cleanup( _environment );
    dstring_cleanup( _environment );
    
    target_finalization( _environment );

    if ( _environment->configurationFileName ) {
        linker_setup( _environment );
        linker_cleanup( _environment );
        fclose(_environment->configurationFile);
    }

    if ( _environment->debuggerLabelsFile ) {
        fclose(_environment->debuggerLabelsFile);
    }
    
    fclose(_environment->asmFile);

}

