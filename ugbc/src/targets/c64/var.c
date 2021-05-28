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
    for(i=0; i<BANK_TYPE_COUNT; ++i) {
        Bank * actual = _environment->banks[i];
        while( actual ) {
            if ( actual->type == BT_VARIABLES ) {
                cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
                outhead1(".segment \"%s\"", actual->name);
                Variable * variable = _environment->variables;
                
                while( variable ) {

                    if ( !variable->imported ) {

                        switch( variable->type ) {
                            case VT_BYTE:
                            case VT_SBYTE:
                            case VT_COLOR:
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
                                outline3("%s: .byte %d,\"%s\"", variable->realName, (int)strlen(variable->valueString), variable->valueString );
                                break;
                            case VT_DSTRING:
                                outline1("%s: .res 1", variable->realName);
                                break;
                            case VT_BUFFER:
                                outline2("%s: .res %d", variable->realName, variable->size);
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
                                } else {
                                    CRITICAL_DATATYPE_UNSUPPORTED("array(1)", DATATYPE_AS_STRING[variable->arrayType]);
                                }
                                outline2("%s: .res %d", variable->realName, size);
                                break;
                            }
                        }
                    }
                    variable = variable->next;
                }
            } else if ( actual->type == BT_TEMPORARY ) {
                cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
                outhead1(".segment \"%s\"", actual->name);
                if ( _environment->bitmaskNeeded ) {
                    outhead0("BITMASK: .byte $01,$02,$04,$08,$10,$20,$40,$80");
                    outhead0("BITMASKN: .byte $fe,$fd,$fb,$f7,$ef,$df,$bf,$7f");
                }
                Variable * variable = _environment->tempVariables;

                while( variable ) {
                    if ( !variable->imported ) {

                        switch( variable->type ) {
                            case VT_BYTE:
                            case VT_SBYTE:
                            case VT_COLOR:
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
                                outline3("%s: .byte %d,\"%s\"", variable->realName, (int)strlen(variable->valueString), variable->valueString );
                                break;
                            case VT_DSTRING:
                                outline1("%s: .res 1", variable->realName);
                                break;
                            case VT_BUFFER:
                                outline2("%s: .res %d", variable->realName, variable->size);
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
                                } else {
                                    CRITICAL_DATATYPE_UNSUPPORTED("array(2)", DATATYPE_AS_STRING[variable->arrayType]);
                                }
                                outline2("%s: .res %d", variable->realName, size);
                                break;
                            }
                        }
                    }
                    variable = variable->next;
                }
            } else if ( actual->type == BT_STRINGS ) {
                cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
            } else {

            }
           actual = actual->next;
        }
    }    
}
