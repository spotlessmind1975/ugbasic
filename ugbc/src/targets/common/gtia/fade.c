/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

#include "../../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#if defined(__atari__) || defined(__atarixl__)

/**
 * @brief Emit code for <strong>FADE</strong>
 */
 
/* <usermanual>
@keyword FADE

@target atari
@target atarixl

</usermanual> */

void fade_ticks_var( Environment * _environment, char * _ticks ) {

    Variable * ticks =  variable_div_const( _environment, variable_retrieve_or_define( _environment, _ticks, VT_WORD, 0 )->name, 16, NULL );

    gtia_fade( _environment, _ticks );

}

void fade_milliseconds_var( Environment * _environment, char * _millliseconds ) {

    Variable * realTiming = variable_div_const( _environment, variable_retrieve_or_define( _environment, _millliseconds, VT_WORD, 0 )->name, 20 * 16, NULL );

    gtia_fade( _environment, realTiming->realName );

}

#endif