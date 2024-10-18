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

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit ASM code for <b>RASTER AT [int] WITH [label]</b>
 * 
 * This function outputs assembly code needed to initialize a raster routine. 
 * In other words, asynchronously and in parallel with the execution of the 
 * main program, the routine starting from the label provided will be executed
 * when the vertical brush on the screen reaches the value of _position. 
 * This function is particularly useful when the position is communicated 
 * is given as an integer.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _position The vertical position to wait for
 */
/* <usermanual>
@keyword RASTER AT

@english
The ''RASTER AT'' instruction will set the next execution raster line for a
raster routine. A raster routine is a small program or sequence of instructions 
that uses a particular moment in the screen display to be activated. This is 
when the electron beam (the raster beam) scans the screen, line by line, to 
draw the image.

The mechanism is simple. The computer generated an interrupt (a signal that 
stopped the main program being executed) every time the raster beam reached 
the given line on this instruction. When the interrupt occurred, the 
processor passed execution to the raster routine. The routine directly does
something, like modify the video memory o registers. Once the change was 
complete (by using the instruction ''NEXT RASTER''), the processor would 
resume execution of the main program from where it had stopped.

Using this mechanism, programmers could create very simple, but often 
surprisingly engaging, graphics, animations, and games, considering the
hardware limitations of the time. They were essential 
for creating effects such as scrolling, moving sprites around the screen, 
creating explosion or deformation effects. 

Raster routines offers very precise control over image generation, 
allowing for customized and optimized effects, and stimulated 
the creativity of programmers, who could invent new ways to exploit 
the mechanism to create innovative visual effects.

@italian
L'istruzione ''RASTER AT'' imposterà la successiva riga raster 
di esecuzione per una routine raster. Una routine raster è un 
piccolo programma o sequenza di istruzioni che utilizza un momento
particolare nella visualizzazione dello schermo per essere attivata. 
Questo è quando il fascio di elettroni (il fascio raster) esegue 
la scansione dello schermo, riga per riga, per disegnare l'immagine.

Il meccanismo è semplice. Il computer generava un'interruzione 
(un segnale che interrompeva l'esecuzione del programma principale) 
ogni volta che il fascio raster raggiungeva la riga specificata 
in questa istruzione. Quando si verificava l'interruzione, il 
processore passava l'esecuzione alla routine raster. La routine 
fa qualcosa direttamente, come modificare la memoria video o i 
registri. Una volta completata la modifica (utilizzando 
l'istruzione ''NEXT RASTER''), il processore riprendeva l'esecuzione del
programma principale da dove si era interrotta.

Utilizzando questo meccanismo, i programmatori potevano creare grafiche, 
animazioni e giochi molto semplici, ma spesso sorprendentemente 
coinvolgenti, considerando le limitazioni hardware dell'epoca. 
Erano essenziali per creare effetti come lo scorrimento, lo 
spostamento di sprite sullo schermo, la creazione di effetti 
di esplosione o deformazione.

Le routine raster offrono un controllo molto preciso sulla 
generazione delle immagini, consentendo effetti personalizzati e ottimizzati 
e stimolando la creatività dei programmatori, che hanno potuto inventare 
nuovi modi per sfruttare il meccanismo per creare effetti visivi innovativi.

@syntax RASTER AT line WITH label
@syntax RASTER label AT line

@example RASTER AT #&H42 WITH rasterRoutine

@target c128

@seeAlso NEXT RASTER
@seeAlso NEXT RASTER AT

</usermanual> */
void raster_at( Environment * _environment, char * _label, int _position ) {
    
    

    char positionlo[MAX_TEMPORARY_STORAGE]; sprintf( positionlo, "#$%2.2x", (unsigned char) ( _position & 0xff )  );
    char positionhi[MAX_TEMPORARY_STORAGE]; sprintf( positionhi, "#$%2.2x", (unsigned char) ( ( ( _position >> 8 ) & 0x01 ) << 8 ) );

    vic2_raster_at( _environment, _label, positionlo, positionhi );

}

/**
 * @brief Emit ASM code for <b>RASTER AT [expression] WITH label</b>
 * 
 * This function outputs assembly code needed to initialize a raster routine. 
 * In other words, asynchronously and in parallel with the execution of the 
 * main program, the routine starting from the label provided will be executed
 * when the vertical brush on the screen reaches the value of _position. 
 * This function is particularly useful when the position is communicated 
 * is given as an expression
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _position The vertical position to wait for
 */
/* <usermanual>
@keyword RASTER AT

@syntax RASTER AT line WITH label
@syntax RASTER label AT line

@example RASTER AT (rasterLine+1) WITH rasterRoutine
</usermanual> */
void raster_at_var( Environment * _environment, char * _label, char * _position ) {
   
    

    MAKE_LABEL

    Variable * var = variable_retrieve( _environment, _position );

    char positionlo[MAX_TEMPORARY_STORAGE]; sprintf( positionlo, "%s", var->realName );
    char positionhi[MAX_TEMPORARY_STORAGE]; sprintf( positionhi, "%s", address_displacement(_environment, var->realName, "1") );

    vic2_raster_at( _environment, _label, positionlo, positionhi );

}

