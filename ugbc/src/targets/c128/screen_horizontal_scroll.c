/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>SCREEN HORIZONTAL SCROLL [int]x</b>
 * 
 * This function outputs an assembly code capable of performing a 
 * hardware scroll of the screen. The scroll is always in the direction 
 * from right to left, so with a _displacement of 0 the screen is exactly as 
 * it would be without scrolling while with the value 7 you would have a scroll
 * of 7 pixels to left. This version is used when a direct integer is used.
 * 
 * @param _environment Current calling environment
 * @param _displacement Horizontal offset in pixels (0-7)
 */
/* <usermanual>
@keyword SCREEN HORIZONTAL SCROLL

@english

The ''SCREEN HORIZONTAL SCROLL'' command is designed to scroll the screen 
horizontally, but its interpretation and the meaning of the parameter supplied 
vary significantly depending on the hardware platform on which the program is 
running. This peculiarity makes it essential to understand the specifics of each 
system to correctly use this command and achieve the desired effect.

On Commodore computers, the numeric parameter supplied to the 
''SCREEN HORIZONTAL SCROLL'' command takes integer values between 0 and 7. 
In this range, the value 4 represents the center position of the scroll. 
Values less than 4 move the screen content to the left, while values greater 
than 4 move it to the right. The amount of scrolling is proportional to the 
distance from the center value of 4. For example, a value of 0 or 7 will 
produce maximum scrolling to the left or right, respectively, while a value 
of 3 will cause a slight shift to the left of the center.

The ''SCREEN HORIZONTAL SCROLL'' command behaves differently on the TRS-80 
Color Computer 3. On this platform, the numeric parameter indicates the starting 
position of the screen. A value of 0 specifies that the display begins at the 
leftmost available column. As the parameter value increases, the screen is 
progressively moved to the left, revealing portions of the screen that were 
previously located to the right of the visible area. In other words, a larger parameter
value causes the displayed content to scroll to the left, revealing what was 
beyond the right edge of the screen. This approach is more intuitive for those 
who expect an increasing value to correspond to a movement in a specific direction.

This divergence in the semantics of the ''SCREEN HORIZONTAL SCROLL'' command across 
platforms highlights one of the inherent challenges in developing cross-platform 
software such as ugBASIC. The developer must be aware of the target machine in 
order to properly use this command and achieve the desired horizontal scrolling 
effect. Often, in ugBASIC programs that aim for cross-platform compatibility, 
conditional procedures (''PROCEDURE ... ON target'') are used to apply different 
parameter values to the ''SCREEN HORIZONTAL SCROLL'' command, adapting the behavior 
to the specifics of each system and thus ensuring a consistent user experience 
or desired visual effect on each machine.

@italian

Il comando ''SCREEN HORIZONTAL SCROLL'' è progettato per scorrere lo schermo in orizzontale, ma la sua interpretazione e il significato del parametro fornito variano significativamente a seconda della piattaforma hardware su cui il programma viene eseguito. Questa peculiarità rende essenziale comprendere le specifiche di ciascun sistema per utilizzare correttamente questo comando e ottenere l'effetto desiderato.

Sui computer Commodore, il parametro numerico fornito al comando ''SCREEN HORIZONTAL SCROLL'' accetta valori interi compresi tra 0 e 7.
In questo intervallo, il valore 4 rappresenta la posizione centrale dello scorrimento.
Valori inferiori a 4 spostano il contenuto dello schermo a sinistra, mentre valori superiori a 4 lo spostano a destra. La quantità di scorrimento è proporzionale alla distanza dal centro, pari a 4. Ad esempio, un valore pari a 0 o 7 produrrà il massimo scorrimento rispettivamente a sinistra o a destra, mentre un valore pari a 3 causerà un leggero spostamento a sinistra rispetto al centro. Il comando ''SCREEN HORIZONTAL SCROLL'' si comporta diversamente sul computer a colori TRS-80 3. Su questa piattaforma, il parametro numerico indica la posizione iniziale dello schermo. Un valore pari a 0 specifica che la visualizzazione inizia dalla colonna disponibile più a sinistra. All'aumentare del valore del parametro, lo schermo viene progressivamente spostato a sinistra, rivelando parti dello schermo che in precedenza si trovavano a destra dell'area visibile. In altre parole, un valore del parametro maggiore fa scorrere il contenuto visualizzato verso sinistra, rivelando ciò che si trovava oltre il bordo destro dello schermo. Questo approccio è più intuitivo per coloro che si aspettano che un valore crescente corrisponda a un movimento in una direzione specifica. Questa divergenza nella semantica del comando ''SCREEN HORIZONTAL SCROLL'' tra le diverse piattaforme evidenzia una delle sfide intrinseche nello sviluppo di software multipiattaforma come ugBASIC. Lo sviluppatore deve conoscere il computer di destinazione per utilizzare correttamente questo comando e ottenere l'effetto di scorrimento orizzontale desiderato. Spesso, nei programmi ugBASIC che mirano alla compatibilità multipiattaforma, vengono utilizzate procedure condizionali (''PROCEDURE ... ON target'') per applicare diversi valori di parametro al comando ''SCREEN HORIZONTAL SCROLL'', adattandone il comportamento alle specifiche di ciascun sistema e garantendo così un'esperienza utente coerente o l'effetto visivo desiderato su ogni macchina.

@syntax SCREEN HORIZONTAL SCROLL offset

@example SCREEN HORIZONTAL SCROLL 3

@target c128
@target c128
@target c128reu
@target coco3

</usermanual> */
void screen_horizontal_scroll( Environment * _environment, int _displacement ) {

    char displacementString[MAX_TEMPORARY_STORAGE]; sprintf( displacementString, "#$%2.2x", _displacement );

    vic2_horizontal_scroll( _environment, displacementString );

}

/**
 * @brief Emit ASM code for <b>SCREEN HORIZONTAL SCROLL [expression[</b>
 * 
 * This function outputs an assembly code capable of performing a 
 * hardware scroll of the screen. The scroll is always in the direction 
 * from right to left, so with a _displacement of 0 the screen is exactly as 
 * it would be without scrolling while with the value 7 you would have a scroll
 * of 7 pixels to left. This version is used when an expression is used.
 * 
 * @param _environment Current calling environment
 * @param _displacement Horizontal offset in pixels (0-7)
 */
void screen_horizontal_scroll_var( Environment * _environment, char * _displacement ) {

    

    Variable * displacement = variable_retrieve( _environment, _displacement );

    vic2_horizontal_scroll( _environment, displacement->realName );

}
