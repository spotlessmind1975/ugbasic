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

/**
 * @brief Emit ASM code for <b>INSTRUMENT ...</b>
 * 
 * This function emits a code capable of change the instrument 
 * for one or more voices.
 * 
 * @param _environment Current calling environment
 * @param _instrument instrument to use
 * @param _channels channels to play on
 */
void instrument( Environment * _environment, int _instrument, int _channels ) {

    ay8910_start( _environment, ( _channels & 0x07 ) );
    ay8910_set_program( _environment, _channels, _instrument );

}

/**
 * @brief Emit ASM code for <b>INSTRUMENT ...</b>
 * 
 * This function emits a code capable of change the instrument 
 * for one or more voices.
 * 
 * @param _environment Current calling environment
 * @param _instrument instrument to use
 * @param _channels channels to play on
 */
void instrument_semi_var( Environment * _environment, int _instrument, char * _channels ) {

    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        ay8910_start_var( _environment, channels->realName );
        ay8910_set_program_semi_var( _environment, channels->realName, _instrument );
    } else {
        ay8910_start_var( _environment, NULL );
        ay8910_set_program_semi_var( _environment, NULL, _instrument );
    }

}