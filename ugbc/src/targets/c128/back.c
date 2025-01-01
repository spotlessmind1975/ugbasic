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

/**
 * @brief Emit ASM code to fill background color
 * 
 * This function can be called to fill the screen background with the given
 * color. Depending on the mode selected (TILEMAP vs BITMAP) it can fill
 * the screen in a different way.
 * 
 * @param _environment Current calling environment
 * @param _color Index of color to use to fill the screen
 */
/* <usermanual>
@keyword COLOR BACK

@english

The ''COLOR BACK'' command used on target that support both color graphics,
backgorund colors and specialized clearing screen routines. Its primary function 
is to set the background color of the screen or a specific area of the screen,
and then clearing the screen using that color.

This command can be used to customize the appearance of programs by creating
colored backgrounds, and could be essential for creating simple games or 
graphical applications, where the background color contributes to aesthetics 
and readability. This can be used to highlight certain areas of the screen 
or to create visual contrasts.

The availability of colors and the accuracy of their representation depend 
on the computer's video chipsed.

@italian

Il comando ''COLOR BACK'' utilizzato su target che supporta sia la grafica a 
colori, i colori di sfondo e le routine specializzate di cancellazione 
dello schermo. La sua funzione principale è quella di impostare il colore 
di sfondo dello schermo o di un'area specifica dello schermo, quindi cancellare 
lo schermo utilizzando quel colore.

Questo comando può essere utilizzato per personalizzare l'aspetto dei programmi 
creando sfondi colorati e può essere essenziale per creare semplici giochi o 
applicazioni grafiche, in cui il colore di sfondo contribuisce all'estetica e 
alla leggibilità. Può essere utilizzato per evidenziare determinate aree dello 
schermo o per creare contrasti visivi.

La disponibilità dei colori e l'accuratezza della loro rappresentazione 
dipendono dal chip video del computer.

@syntax COLOR BACK color

@example COLOR BACK RED
@example COLOR BACK WHITE

@usedInExample graphics_color_01.bas

@seeAlso PAPER
@seeAlso CLS

@target c128
</usermanual> */
void back( Environment * _environment, char * _color ) {

    paper( _environment, _color );

    vic2_back( _environment );

}
