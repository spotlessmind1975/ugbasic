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

        if ( ( !variable->assigned || ( variable->assigned && !variable->temporary ) ) && !variable->imported ) {

        switch( variable->type ) {
            case VT_CHAR:
            case VT_BYTE:
            case VT_SBYTE:
            case VT_COLOR:
            case VT_THREAD:
                outline1("%s: .res 1", variable->realName);
                break;
            case VT_WORD:
            case VT_SWORD:
            case VT_POSITION:
            case VT_ADDRESS:
                outline1("%s: .res 2", variable->realName);
                break;
            case VT_DWORD:
            case VT_SDWORD:
                outline1("%s: .res 4", variable->realName);
                break;
            case VT_STRING:
                if ( ! variable->valueString ) {
                    printf("%s", variable->realName);
                    exit(EXIT_FAILURE);
                }
                if ( variable->printable ) {
                    c = strlen( variable->valueString );
                    out1("%s: .byte %d,", variable->realName, c);
                    int i=0;
                    for (i=0; i<(c-1); ++i ) {
                        out1("$%2.2x,", (unsigned char)variable->valueString[i]);
                    }
                    outline1("$%2.2x", variable->valueString[(c-1)]);                        
                } else {
                    outline3("%s: .byte %d,\"%s\"", variable->realName, (int)strlen(variable->valueString), escape_newlines( variable->valueString ) );
                }
                break;
            case VT_DSTRING:
                outline1("%s: .res 1", variable->realName);
                break;
            case VT_MOB:
                outline1("%s: .res 1", variable->realName);
                break;
            case VT_IMAGE:
            case VT_IMAGES:
            case VT_BUFFER:
                if ( ! variable->absoluteAddress ) {
                    if ( variable->valueBuffer ) {
                        if ( variable->printable ) {
                            char * string = malloc( variable->size + 1 );
                            memset( string, 0, variable->size );
                            memcpy( string, variable->valueBuffer, variable->size );
                            outline2("%s: .byte \"%s\"", variable->realName, escape_newlines( string ) );
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
                    outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    if ( variable->valueBuffer ) {
                        if ( variable->printable ) {
                            char * string = malloc( variable->size + 1 );
                            memset( string, 0, variable->size );
                            memcpy( string, variable->valueBuffer, variable->size );
                            outline2("%scopy: .byte \"%s\"", variable->realName, escape_newlines( string ) );
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
                if ( variable->valueBuffer ) {
                    out1("%s: .byte ", variable->realName);
                    int i=0;
                    for (i=0; i<(variable->size-1); ++i ) {
                        out1("%d,", variable->valueBuffer[i]);
                    }
                    outline1("%d", variable->valueBuffer[(variable->size-1)]);
                } else if ( variable->value ) {
                    outline3("%s: .res %d, $%2.2x", variable->realName, variable->size, (unsigned char)(variable->value&0xff));
                } else {
                    outline2("%s: .res %d", variable->realName, variable->size);
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

            } else if ( actual->type == BT_STRINGS ) {
                // cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                // cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
            } else {

            }
           actual = actual->next;
        }
    }    
}
