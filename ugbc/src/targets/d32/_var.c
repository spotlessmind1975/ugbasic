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

extern char BANK_TYPE_AS_STRING[][16];
extern char DATATYPE_AS_STRING[][16];

static void variable_cleanup_entry( Environment * _environment, Variable * _first ) {

    Variable * variable = _first;

    while( variable ) {

        if ( !variable->assigned && !variable->imported ) {

            if ( variable->memoryArea && _environment->debuggerLabelsFile ) {
                fprintf( _environment->debuggerLabelsFile, "%4.4x %s\r\n", variable->absoluteAddress, variable->realName );
            }

            switch( variable->type ) {
                case VT_BYTE:
                case VT_SBYTE:
                case VT_COLOR:
                case VT_THREAD:
                    if ( variable->memoryArea ) {
                        outhead2("%s equ $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s rzb 1", variable->realName);
                    }   
                    break;
                case VT_WORD:
                case VT_SWORD:
                case VT_POSITION:
                case VT_ADDRESS:
                    if ( variable->memoryArea ) {
                        outhead2("%s equ $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s rzb 2", variable->realName);
                    }   
                    break;
                case VT_DWORD:
                case VT_SDWORD:
                    if ( variable->memoryArea ) {
                        outhead2("%s equ $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s rzb 4", variable->realName);
                    }   
                    break;
                case VT_STRING:
                    if ( ! variable->valueString ) {
                        printf("%s", variable->realName);
                        exit(EXIT_FAILURE);
                    }
                    if ( variable->memoryArea ) {
                        outhead2("%s equ $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead2("%s fcb %d", variable->realName, (int)strlen(variable->valueString) );
                        if ( strlen( variable->valueString ) > 0 ) {
                            outhead1("   fcc \"%s\"", variable->valueString );
                        } 
                    }   
                    break;
                case VT_DSTRING:
                    if ( variable->memoryArea ) {
                        outhead2("%s equ $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s rzb 1", variable->realName);
                    }   
                    break;
                case VT_MOB:
                    if ( variable->memoryArea ) {
                        outhead2("%s equ $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s rzb 1", variable->realName);
                    }   
                    break;
                case VT_IMAGE:
                case VT_IMAGES:
                case VT_BUFFER:
                    if ( ! variable->absoluteAddress ) {
                        if ( variable->valueBuffer ) {
                            out1("%s fcb ", variable->realName);
                            int i=0;
                            for (i=0; i<(variable->size-1); ++i ) {
                                out1("%d,", variable->valueBuffer[i]);
                            }
                            outhead1("%d", variable->valueBuffer[(variable->size-1)]);
                        } else {
                            outhead2("%s rzb %d", variable->realName, variable->size);
                        }
                    } else {
                        outhead2("%s equ $%4.4x", variable->realName, variable->absoluteAddress);
                        if ( variable->valueBuffer ) {
                            out1("%scopy fcb ", variable->realName);
                            int i=0;
                            for (i=0; i<(variable->size-1); ++i ) {
                                out1("%d,", variable->valueBuffer[i]);
                            }
                            outhead1("%d", variable->valueBuffer[(variable->size-1)]);
                        }
                    }
                    break;
                case VT_ARRAY: {
                    int i=0,size=1;
                    for( i=0; i<variable->arrayDimensions; ++i ) {
                        size *= variable->arrayDimensionsEach[i];
                    }
                    if ( VT_BITWIDTH( variable->arrayType ) > 0 ) {
                        size *= ( VT_BITWIDTH( variable->arrayType ) >> 3 );
                    } else if ( variable->arrayType == VT_DSTRING ) {
                        size *= 1;
                    } else if ( variable->arrayType == VT_MOB ) {
                        size *= 1;
                    } else {
                        CRITICAL_DATATYPE_UNSUPPORTED("array(1)", DATATYPE_AS_STRING[variable->arrayType]);
                    }
                    if ( variable->value ) {
                        outhead3("%s rzb %d, $%2.2x", variable->realName, size, (unsigned char)(variable->value&0xff));
                    } else {
                        outhead2("%s rzb %d", variable->realName, size);
                    }
                    break;
                }
            }
        }
        
        variable = variable->next;

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
            outhead1("OFFSETS%4.4x", actual->size );
            out0("        fdb " );
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
                    outhead0("BITMASK fcb $01,$02,$04,$08,$10,$20,$40,$80");
                    outhead0("BITMASKN fcb $fe,$fd,$fb,$f7,$ef,$df,$bf,$7f");
                }
                if ( _environment->deployed.dstring ) {
                    outhead1("max_free_string equ $%4.4x", _environment->dstring.space == 0 ? DSTRING_DEFAULT_SPACE : _environment->dstring.space );
                }

                for( int j=0; j< (_environment->currentProcedure+1); ++j ) {
                    Variable * variable = _environment->tempVariables[j];
                    variable_cleanup_entry( _environment, variable );
                } 
                
                Variable * variable = _environment->tempResidentVariables;

                variable_cleanup_entry( _environment, variable );

            } else if ( actual->type == BT_STRINGS ) {
                // cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                // cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
            } else {

            }
           actual = actual->next;
        }
    }    
}
