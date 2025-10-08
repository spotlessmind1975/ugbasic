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

void configure_set_value( Environment * _environment, int _name, int _parameter, int _value ) {

    switch( _name ) {
        case HN_GMC:
            switch( _parameter ) {
                case HPN_SLOT:
                    _environment->configureParameters.gmc.slot.value = _value;
                    _environment->configureParameters.gmc.slot.statically = 1;
                    break;
                default:
                    break;
            }
            break;
    }

}

void configure_set_value_var( Environment * _environment, int _name, int _parameter, char * _value ) {

    switch( _name ) {
        case HN_GMC:
            switch( _parameter ) {
                case HPN_SLOT: {
                    Variable * value = variable_retrieve_or_define( _environment, _value, VT_BYTE, 0 );
                    cpu_move_8bit( _environment, value->realName, "GMC_SLOT" );
                    outline0( "LDA #$30");
                    outline0( "ORA GMC_SLOT");
                    outline0( "STA $FF7F");
                    if ( !_environment->configureParameters.gmc.slot.statically ) {
                        _environment->configureParameters.gmc.slot.value = 0;
                    }
                    _environment->configureParameters.gmc.slot.dynamically = 1;
                    break;
                }
                default:
                    break;
            }
            break;
    }

}
