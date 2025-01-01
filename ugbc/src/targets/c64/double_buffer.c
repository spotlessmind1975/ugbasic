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
 * @brief Emit code for <strong>DOUBLE BUFFER ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _enabled if double buffer is enabled
 */
/* <usermanual>
@keyword DOUBLE BUFFER

@english

The ''DOUBLE BUFFER'' is a command that enable / disable the graphics programming 
technique used to avoid screen flickering, which is especially noticeable in 
animations and interactive graphics applications. It is especially useful in 
8-bit computers, where graphics resources are limited.

Imagine having a screen and two areas of memory, called buffers, dedicated to 
graphics. In the first the entire frame (the complete image) that we want 
to display on the screen is drawn. While drawing in the first buffer, 
the contents of the second buffer are displayed on the screen. Once the 
drawing in the first buffer is complete, the two buffers are swapped: 
the contents of the first buffer are copied to the second and displayed 
on the screen, while the first buffer is emptied and prepared for the 
next frame. This process is repeated continuously.

The command will enable this method, and screens will be swapped
if the ''SCREEN SWAP'' is used.

This instruction activates the technique only where available.

@italian

Il ''DOUBLE BUFFER'' è un comando che abilita/disabilita la tecnica
di programmazione grafica utilizzata per evitare lo sfarfallio dello 
schermo, che è particolarmente evidente nelle animazioni e nelle 
applicazioni grafiche interattive. È particolarmente utile nei 
computer a 8 bit, dove le risorse grafiche sono limitate.

Immagina di avere uno schermo e due aree di memoria, chiamate buffer, 
dedicate alla grafica. Nella prima viene disegnato l'intero frame 
(l'immagine completa) che vogliamo visualizzare sullo schermo. 
Mentre disegni nel primo buffer, il contenuto del secondo buffer 
viene visualizzato sullo schermo. Una volta completato il disegno 
nel primo buffer, i due buffer vengono scambiati: il contenuto del 
primo buffer viene copiato nel secondo e visualizzato sullo schermo, 
mentre il primo buffer viene svuotato e preparato per il frame 
successivo. Questo processo viene ripetuto continuamente.

Il comando abiliterà questo metodo e gli schermi verranno scambiati 
se viene utilizzato ''SCREEN SWAP''.

Questa istruzione attiva la tecnica solo dove disponibile.

@syntax DOUBLE BUFFER [ON|OFF]

@example DOUBLE BUFFER ON

@seeAlso SCREEN SWAP

@target c64
</usermanual> */
void double_buffer( Environment * _environment, int _enabled ) {

    if ( _environment->doubleBufferEnabled != _enabled ) {

        _environment->doubleBufferEnabled = _enabled;

        if ( _enabled ) {
            if ( _environment->deployed.scroll ) {
                cpu_set_callback( _environment, "SCREENSCROLLEMBED", "SCREENSCROLLVOID" );
                cpu_set_callback( _environment, "ONSWITCHTILEMAP", "SCREENSCROLL" );
            }
            outline0("JSR DOUBLEBUFFERINIT")
        } else {
            if ( _environment->deployed.scroll ) {
                cpu_set_callback( _environment, "SCREENSCROLLEMBED", "SCREENSCROLL" );
                cpu_set_callback( _environment, "ONSWITCHTILEMAP", "SCREENSCROLLVOID" );
            }
            outline0("JSR DOUBLEBUFFERCLEANUP")
        }

    };

}
