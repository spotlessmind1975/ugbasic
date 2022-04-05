/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

@target c128
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
