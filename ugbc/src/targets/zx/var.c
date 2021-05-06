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
                // TODO: zx: management of banks' variables
                // outhead1("section %s", actual->name);
                // outline1("org $%4.4x", actual->address);
                Variable * variable = _environment->variables;
                while( variable ) {
                    switch( variable->type ) {
                        case VT_BYTE:
                        case VT_COLOR:
                            outline1("%s: defs 1", variable->realName);
                            break;
                        case VT_WORD:
                        case VT_POSITION:
                        case VT_ADDRESS:
                            outline1("%s: defs 2", variable->realName);
                            break;
                        case VT_DWORD:
                            outline1("%s: defs 4", variable->realName);
                            break;
                        case VT_STRING:
                            outline1("%s: defs 3", variable->realName);
                            break;
                        case VT_BUFFER:
                            outline2("%s: defs %d", variable->realName, variable->size);
                            break;
                    }
                    variable = variable->next;
                }
            } else if ( actual->type == BT_TEMPORARY ) {
                // TODO: zx: management of banks' variables
                // outhead1("section %s", actual->name);
                // outline1("org $%4.4x", actual->address);
                if ( _environment->bitmaskNeeded ) {
                    outhead0("BITMASK: defm $01,$02,$04,$08,$10,$20,$40,$80");
                    outhead0("BITMASKN: defm $fe,$fd,$fb,$f7,$ef,$df,$bf,$7f");
                }
                Variable * variable = _environment->tempVariables;
                while( variable ) {
                    switch( variable->type ) {
                        case VT_BYTE:
                        case VT_COLOR:
                            outline1("%s: defs 1", variable->realName);
                            break;
                        case VT_WORD:
                        case VT_POSITION:
                        case VT_ADDRESS:
                            outline1("%s: defs 2", variable->realName);
                            break;
                        case VT_DWORD:
                            outline1("%s: defs 4", variable->realName);
                            break;
                        case VT_STRING:
                            outline1("%s: defs 3", variable->realName);
                            break;
                        case VT_BUFFER:
                            outline2("%s: defs %d", variable->realName, variable->size);
                            break;
                    }
                    variable = variable->next;
                }
            } else {

            }
           actual = actual->next;
        }
    }    

}
