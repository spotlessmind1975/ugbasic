/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

extern char BANK_TYPE_AS_STRING[][16];
extern char DATATYPE_AS_STRING[][16];

static void variable_cleanup_entry( Environment * _environment, Variable * _first ) {

    Variable * variable = _first;

    while( variable ) {

        if ( ( !variable->assigned || ( variable->assigned && !variable->temporary ) ) && !variable->imported && !variable->memoryArea ) {

            if ( variable->memoryArea && _environment->debuggerLabelsFile ) {
                fprintf( _environment->debuggerLabelsFile, "%4.4x %s\r\n", variable->absoluteAddress, variable->realName );
            }

            switch( variable->type ) {
                case VT_CHAR:
                case VT_BYTE:
                case VT_SBYTE:
                case VT_COLOR:
                case VT_THREAD:
                    if ( variable->memoryArea ) {
                        // outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outline1("%s: .res 1", variable->realName);
                    }        
                    break;
                case VT_WORD:
                case VT_SWORD:
                case VT_POSITION:
                case VT_ADDRESS:
                    if ( variable->memoryArea ) {
                        // outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outline1("%s: .res 2", variable->realName);
                    }
                    break;
                case VT_DWORD:
                case VT_SDWORD:
                    if ( variable->memoryArea ) {
                        // outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outline1("%s: .res 4", variable->realName);
                    }
                    break;
                case VT_STRING:
                    if ( variable->memoryArea ) {
                        // outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        if ( variable->printable ) {
                            int c = strlen( variable->valueString );
                            out2("%s: .byte %d,", variable->realName, c);
                            int i=0;
                            for (i=0; i<(c-1); ++i ) {
                                out1("$%2.2x,", (unsigned char)variable->valueString[i]);
                            }
                            outline1("$%2.2x", (unsigned char)variable->valueString[(c-1)]);                        
                        } else {
                            outline3("%s: .byte %d,%s", variable->realName, (int)strlen(variable->valueString), escape_newlines( variable->valueString ) );
                        }
                    }
                    break;
                case VT_DSTRING:
                    if ( variable->memoryArea ) {
                        // outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outline1("%s: .res 1", variable->realName);
                    }
                    break;
                case VT_TILE:
                case VT_TILESET:
                case VT_SPRITE:
                case VT_MOB:
                    if ( variable->memoryArea ) {
                        // outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outline1("%s: .res 1", variable->realName);
                    }
                    break;
                case VT_TILES:
                    if ( variable->memoryArea ) {
                        // outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outline1("%s: .res 4", variable->realName);
                    }
                    break;                case VT_IMAGE:
                case VT_IMAGES:
                case VT_BUFFER:
                    if ( ! variable->absoluteAddress ) {
                        if ( variable->valueBuffer ) {
                            if ( variable->printable ) {
                                char * string = malloc( variable->size + 1 );
                                memset( string, 0, variable->size );
                                memcpy( string, variable->valueBuffer, variable->size );
                                outline2("%s: .byte %s", variable->realName, escape_newlines( string ) );
                            } else {
                                out1("%s: .byte ", variable->realName);
                                int i=0;
                                for (i=0; i<(variable->size-1); ++i ) {
                                    out1("%d,", variable->valueBuffer[i]);
                                }
                                outline1("%d", variable->valueBuffer[(variable->size-1)]);
                            }
                        } else {
                            outline2("%s: .res %d", variable->realName, variable->size);
                        }
                    } else {
                        if ( ! variable->memoryArea && variable->valueBuffer ) {
                            outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                            if ( variable->printable ) {
                                char * string = malloc( variable->size + 1 );
                                memset( string, 0, variable->size );
                                memcpy( string, variable->valueBuffer, variable->size );
                                outline2("%scopy: .byte %s", variable->realName, escape_newlines( string ) );
                            } else {
                                out1("%scopy: .byte ", variable->realName);
                                int i=0;
                                for (i=0; i<(variable->size-1); ++i ) {
                                    out1("%d,", variable->valueBuffer[i]);
                                }
                                outline1("%d", variable->valueBuffer[(variable->size-1)]);
                            }
                        }
                    }
                    break;
                case VT_ARRAY: {
                    if ( ! variable->memoryArea && variable->valueBuffer ) {
                        out1("%s: .byte ", variable->realName);
                        int i=0;
                        for (i=0; i<(variable->size-1); ++i ) {
                            out1("%d,", variable->valueBuffer[i]);
                        }
                        outline1("%d", variable->valueBuffer[(variable->size-1)]);
                    } else if ( variable->memoryArea && ! variable->value ) {
                        // outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        if ( variable->value ) {
                            outline3("%s: .res %d, $%2.2x", variable->realName, variable->size, (unsigned char)(variable->value&0xff));
                        } else {
                            outline2("%s: .res %d", variable->realName, variable->size);
                        }
                    }
                    break;
                }
            }
        }
        variable = variable->next;
    }

}

static void variable_cleanup_memory_mapped( Environment * _environment, Variable * _variable ) {

    outhead2("; %s (%4.4x)", _variable->realName, _variable->absoluteAddress );
    outhead1("%s:", _variable->realName );

    switch( _variable->type ) {
        case VT_CHAR:
        case VT_BYTE:
        case VT_SBYTE:
        case VT_COLOR:
        case VT_THREAD:
            outline1(" .byte $%1.1x", ( _variable->value & 0xff ) );
            break;
        case VT_WORD:
        case VT_SWORD:
        case VT_POSITION:
        case VT_ADDRESS:
            outline1(" .word $%2.2x", ( _variable->value & 0xffff ) );
            break;
        case VT_DWORD:
        case VT_SDWORD:
            outline1(" .dword $%4.4x", ( _variable->value & 0xffff ) );
            break;
        case VT_STRING:
            if ( _variable->printable ) {
                int c = strlen( _variable->valueString );
                out1("   .byte %d,", c);
                int i=0;
                for (i=0; i<(c-1); ++i ) {
                    out1("$%2.2x,", (unsigned char)_variable->valueString[i]);
                }
                outline1("$%2.2x", (unsigned char)_variable->valueString[(c-1)]);                        
            } else {
                outline2("   .byte %d,%s", (int)strlen(_variable->valueString), escape_newlines( _variable->valueString ) );
            }
            break;
        case VT_DSTRING:
        case VT_SPRITE:
        case VT_TILE:
        case VT_TILESET:
        case VT_MOB:
            outline0("   .byte 0" );
            break;
        case VT_TILES:
            outline0("   .byte 0, 0, 0, 0" );
            break;
        case VT_IMAGE:
        case VT_IMAGES:
        case VT_BUFFER:
            if ( _variable->valueBuffer ) {
                if ( _variable->printable ) {
                    char * string = malloc( _variable->size + 1 );
                    memset( string, 0, _variable->size );
                    memcpy( string, _variable->valueBuffer, _variable->size );
                    outline1("    .byte %s", escape_newlines( string ) );
                } else {
                    out0("    .byte ");
                    int i=0;
                    for (i=0; i<(_variable->size-1); ++i ) {
                        out1("%d,", _variable->valueBuffer[i]);
                    }
                    outline1("%d", _variable->valueBuffer[(_variable->size-1)]);
                }
            } else {
                outline1(" .res %d", _variable->size);
            }
            break;
        case VT_ARRAY: {
            if ( _variable->valueBuffer ) {
                out0("    .byte ");
                int i=0;
                for (i=0; i<(_variable->size-1); ++i ) {
                    out1("%d,", _variable->valueBuffer[i]);
                }
                outline1("%d", _variable->valueBuffer[(_variable->size-1)]);
            } else {
                if ( _variable->value ) {
                    outline2("    .res %d, $%2.2x", _variable->size, (unsigned char)(_variable->value&0xff));
                } else {
                    outline1("    .res %d", _variable->size);
                }
            }
            break;
        }
    }

}

/**
 * @brief Emit source and configuration lines for variables
 * 
 * This function can be called to generate all the definitions (on the source
 * file, on the configuration file and on any support file) necessary to 
 * implement the variables.
 * 
 * @param _environment Current calling environment
 */
void variable_cleanup( Environment * _environment ) {
    int i=0;

    if ( _environment->offsetting ) {
        Offsetting * actual = _environment->offsetting;
        while( actual ) {
            out1("OFFSETS%4.4x: .word ", actual->size );
            for( i=0; i<actual->count; ++i ) {
                out1("$%4.4x", i * actual->size );
                if ( i < ( actual->count - 1 ) ) {
                    out0(",");
                } else {
                    outline0("");
                }
            }
            actual = actual->next;
        }
    }

    for(i=0; i<BANK_TYPE_COUNT; ++i) {
        Bank * actual = _environment->banks[i];
        while( actual ) {
            if ( actual->type == BT_VARIABLES ) {
                // cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                // cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
                // outhead1(".segment \"%s\"", actual->name);
                Variable * variable = _environment->variables;
                
                variable_cleanup_entry( _environment, variable );

            } else if ( actual->type == BT_TEMPORARY ) {
                // cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                // cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
                // outhead1(".segment \"%s\"", actual->name);
                if ( _environment->bitmaskNeeded ) {
                    outhead0("BITMASK: .byte $01,$02,$04,$08,$10,$20,$40,$80");
                    outhead0("BITMASKN: .byte $fe,$fd,$fb,$f7,$ef,$df,$bf,$7f");
                }
                if ( _environment->deployed.dstring ) {
                    outhead1("max_free_string = $%4.4x", _environment->dstring.space == 0 ? DSTRING_DEFAULT_SPACE : _environment->dstring.space );
                }

                for( int j=0; j< (_environment->currentProcedure+1); ++j ) {
                    Variable * variable = _environment->tempVariables[j];
                    variable_cleanup_entry( _environment, variable );
                }
                
                Variable * variable = _environment->tempResidentVariables;

                variable_cleanup_entry( _environment, variable );

            // } else if ( actual->type == BT_STRINGS ) {
            //     cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
            //     cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
            } else {

            }
           actual = actual->next;
        }
    }    

    if ( _environment->descriptors ) {
        outhead0(".segment \"UDCCHAR\"" );
        int i=0,j=0;
        for(i=0;i<256;++i) {
            outline1("; $%2.2x ", i);
            out0(".byte " );
            for(j=0;j<7;++j) {
                out1("$%2.2x,", ((unsigned char)_environment->descriptors->data[i].data[j]) );
            }
            outline1("$%2.2x", ((unsigned char)_environment->descriptors->data[i].data[j]) );
        }
    }    

    if ( _environment->memoryAreas ) {
        MemoryArea * memoryArea = _environment->memoryAreas;
        while( memoryArea ) {
            if ( memoryArea->type == MAT_RAM ) {
                cfgline3("MA%3.3x:  load = RAM%3.3x, type = overwrite,  optional = yes, start = $%4.4x;", memoryArea->id, memoryArea->id, memoryArea->start);
            } else {
                cfgline2("MA%3.3x:  load = MAIN, type = overwrite,  optional = yes, start = $%4.4x;", memoryArea->id, memoryArea->start);
            }
            outhead1(".segment \"MA%3.3x\"", memoryArea->id );
            for( i=memoryArea->start; i<memoryArea->end; ++i ) {
                Variable * variable = _environment->variables;
                while( variable ) {
                    if ( !variable->assigned && variable->memoryArea == memoryArea && variable->absoluteAddress == i ) {
                        variable_cleanup_memory_mapped( _environment, variable );
                        variable->staticalInit = ( memoryArea->type == MAT_RAM ? 0 : 1 );
                        break;
                    }
                    variable = variable->next;
                }
                for( int j=0; j< (_environment->currentProcedure+1); ++j ) {
                    Variable * variable = _environment->tempVariables[j];
                    while( variable ) {
                        if ( !variable->assigned && variable->memoryArea == memoryArea && variable->absoluteAddress == i ) {
                            variable_cleanup_memory_mapped( _environment, variable );
                            variable->staticalInit = ( memoryArea->type == MAT_RAM ? 0 : 1 );
                            break;
                        }
                        variable = variable->next;
                    }
                }
                variable = _environment->tempResidentVariables;
                while( variable ) {
                    if ( !variable->assigned && variable->memoryArea == memoryArea && variable->absoluteAddress == i ) {
                        variable_cleanup_memory_mapped( _environment, variable );
                        variable->staticalInit = ( memoryArea->type == MAT_RAM ? 0 : 1 );
                        break;
                    }
                    variable = variable->next;
                }
            }
            memoryArea = memoryArea->next;
        }

    }    

    outhead0(".segment \"CODE\"" );

    variable_on_memory_init( _environment, 0 );


}
