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

#if defined(__c64__) || defined(__c64reu__) || defined(__c128__)

/**
 * @brief Emit code for <strong>FADE</strong>
 */
 
/* <usermanual>
@keyword FADE

@english

This instruction allow you to perform a "fade". The fade, in graphic terms, consists of gradually passing 
from one image or color to another. Fade to black implies a gradual transition to the color black (RGB: 0, 0, 0). 
To implement this transition, ugBASIC will progressively vary the color values ​​of the pixels on the screen. The 
function takes the desired fade time in ticks or milliseconds (it will be rouded to the next tick). The accuracy 
and smoothness of the fade depends on the number of colors available in the palette and the number of steps. 

@italian

Questa istruzione consente di eseguire una "dissolvenza". La dissolvenza, in termini grafici, consiste 
nel passaggio graduale da un'immagine o colore a un altro. La dissolvenza al nero implica una transizione 
graduale al colore nero (RGB: 0, 0, 0). Per implementare questa transizione, ugBASIC varierà progressivamente 
i valori di colore dei pixel sullo schermo. La funzione impiega il tempo di dissolvenza desiderato in 
ticks o millisecondi (che saranno arrotondati al tick più vicino). La precisione e la fluidità della dissolvenza 
dipendono dal numero di colori disponibili nella tavolozza e dal numero di passaggi.

@syntax FADE time [TICKS|MILLISECONDS|MS]

@example FADE 1000 MS

@target alll
</usermanual> */

void fade_ticks_var( Environment * _environment, char * _ticks ) {

    Variable * ticks =  variable_div_const( _environment, variable_retrieve_or_define( _environment, _ticks, VT_WORD, 0 )->name, 8, NULL );

    vic2_fade( _environment, _ticks );

}

void fade_milliseconds_var( Environment * _environment, char * _millliseconds ) {

    Variable * realTiming = variable_div_const( _environment, variable_retrieve_or_define( _environment, _millliseconds, VT_WORD, 0 )->name, 20 * 8, NULL );

    vic2_fade( _environment, realTiming->realName );

}

#endif