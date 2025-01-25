/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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

static void linker_setup_variables_memory( Environment * _environment, Variable * _variable ) {

    Variable * variable = _variable;

    while( variable ) {

        if ( (variable->memoryArea && variable->bankAssigned != -1 && !variable->assigned) || ( !variable->assigned || ( variable->assigned && !variable->temporary ) ) && !variable->imported && !variable->memoryArea ) {
            switch( variable->type ) {
                case VT_MUSIC:
                    if ( variable->sidFile ) {
                        if ( variable->sidFile->loadAddress ) {
                            //cfgline3("MEM%s:     file = \"\", start = $%4.4x,     size = $%4.4x;", variable->name, variable->sidFile->loadAddress, variable->sidFile->size );
                        }
                    }
            }
        }

        variable = variable->next;

    }

}

static void linker_setup_variables_segment( Environment * _environment, Variable * _variable ) {

    Variable * variable = _variable;

    while( variable ) {

        if ( (variable->memoryArea && variable->bankAssigned != -1 && !variable->assigned) || ( !variable->assigned || ( variable->assigned && !variable->temporary ) ) && !variable->imported && !variable->memoryArea ) {
            switch( variable->type ) {
                case VT_MUSIC:
                    if ( variable->sidFile ) {
                        if ( variable->sidFile->loadAddress ) {
                            cfgline2("%s:  load = MAIN, type = overwrite,  optional = yes, start = $%4.4x;", variable->name, variable->sidFile->loadAddress );
                        }
                    }
            }
        }

        variable = variable->next;

    }

}

/**
 * @brief Emit tail of linker's configuration file lines
 * 
 * This function emit the header of linker's configuration file.
 * 
 * @param _environment Current calling environment
 */
void linker_setup( Environment * _environment ) {

    if ( _environment->program.startingAddress < 0x080e ) {
        CRITICAL_INVALID_PROGRAM_START( _environment->program.startingAddress );
    }

    cfghead0("FEATURES {");
    cfgline0("STARTADDRESS: default = $0801;");
    cfghead0("}");
    cfghead0("MEMORY {");
    cfgline0("ZP:       file = \"\", start = $0002,  size = $00FE,      define = yes;");
    // cfgline0("LOADADDR: file = %O, start = %S - 2, size = $0002;");

    MemoryArea * actual = _environment->memoryAreas;
    int maxAddress = 0xA802;
    while( actual ) {
        int realMaxAddress = 0x800 + actual->start + ( actual->end - actual->start );
        if ( actual->type != MAT_RAM && realMaxAddress > maxAddress ) {
            maxAddress = realMaxAddress;
        }
        actual = actual->next;
    }

    cfgline1("MAIN:     file = %%O, start = %%S-2,     size = $%4.4x - %%S;", (unsigned short)maxAddress);

    actual = _environment->memoryAreas;
    while( actual ) {
        if ( actual->type == MAT_RAM  ) {
            cfgline3("RAM%3.3x:     file = \"\", start = $%4.4x,     size = $%4.4x;", actual->id, (unsigned short)actual->start, (unsigned short)(actual->end - actual->start) );
        }
        actual = actual->next;
    }

    linker_setup_variables_memory( _environment, _environment->variables );
    for( int j=0; j< (_environment->currentProcedure+1); ++j ) {
        linker_setup_variables_memory( _environment, _environment->tempVariables[j] );
    }

    cfghead0("}");
    cfghead0("SEGMENTS {");
    cfgline0("ZEROPAGE: load = ZP,       type = zp,  optional = yes;");
    // cfgline0("LOADADDR: load = LOADADDR, type = ro;");
    // cfgline0("EXEHDR:   load = MAIN,     type = ro,  optional = yes;");

    cfgline0("BASIC:    load = MAIN,     type = ro,  optional = no;");
    cfgline1("CODE:     load = MAIN,     type = rw,  start = $%4.4x;", _environment->program.startingAddress);
    cfgline0("RODATA:   load = MAIN,     type = ro,  optional = yes;");
    cfgline0("DATA:     load = MAIN,     type = rw,  optional = yes;");
    cfgline0("BSS:      load = MAIN,     type = bss, optional = yes, define = yes;");
    cfgline0("UDCCHAR:  load = MAIN, type = overwrite,  optional = yes, start = $A000;");

    actual = _environment->memoryAreas;
    while( actual ) {
        if ( actual->type == MAT_RAM ) {
            cfgline3("MA%3.3x:  load = RAM%3.3x, type = overwrite,  optional = yes, start = $%4.4x;", actual->id, actual->id, actual->start);
        } else {
            cfgline2("MA%3.3x:  load = MAIN, type = overwrite,  optional = yes, start = $%4.4x;", actual->id, actual->start);
        }        
        actual = actual->next;
    }

    linker_setup_variables_segment( _environment, _environment->variables );
    for( int j=0; j< (_environment->currentProcedure+1); ++j ) {
        linker_setup_variables_segment( _environment, _environment->tempVariables[j] );
    }

}

/**
 * @brief Emit tail of linker's configuration file lines
 * 
 * This function emit the tail of linker's configuration file.
 * 
 * @param _environment Current calling environment
 */
void linker_cleanup( Environment * _environment ) {
 
    cfghead0("}");
    
}