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
 * @brief Emit code for <strong>NEW IMAGE(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _width Width of the image, in pixel
 * @param _height Heigth of the image, in pixel
 * @param _mode Mode to use
 */
/* <usermanual>
@keyword NEW IMAGE

@english

The ''NEW IMAGE'' command allows you to define a memory area where you can 
store an image coming from the screen (with the ''GET IMAGE'' command), or 
from another graphic resource. 

The area must be defined by (constant) width and (constant) height, expressed in pixels. The actual size, 
in terms of bytes of RAM, will depend on the graphics mode selected at the time. If it is not 
possible to define an image in that screen mode, a specific error will be issued.

Generally speaking, it is not advisable to do a ''PUT IMAGE'' of a ''NEW IMAGE'' that has not 
been initialized, at least once, by a ''GET IMAGE''. Infact, the ''PUT IMAGE'' tries to draw 
the contents of an uninitialized frame (i.e.: all zeros), including the palette. So it 
could draw everything empty in terms of bitmap, and then overwrites the entire palette 
with zeros, giving rise to unexpected result. So you have to use a preliminary ''GET IMAGE'' 
on any ''NEW IMAGE''. 

If you want to use the ''PUT IMAGE'' without 
side effects on palette, you can opt for the ''PUT BITMAP''. In this case, ugBASIC 
will draw only the component related to the pixels, leaving the palette component 
unchanged.

@italian

Il comando ''NEW IMAGE'' consente di definire un'area di memoria in cui è possibile 
memorizzare un'immagine dallo schermo (con il comando ''GET IMAGE'') o da un'altra 
risorsa grafica.

L'area deve essere definita da una larghezza (costante) e un'altezza (costante), 
espresse in pixel. La dimensione effettiva, in termini di byte RAM, dipenderà 
dalla modalità grafica attualmente selezionata. Se non è possibile definire 
un'immagine in quella modalità schermo, verrà emesso un errore specifico.

In generale, non è consigliabile eseguire un ''PUT IMAGE'' di una ''NEW IMAGE'' 
che non sia stata inizializzata, almeno una volta, da un ''GET IMAGE''. Infatti, 
il ''PUT IMAGE'' tenta di disegnare il contenuto di un frame non inizializzato 
(ad esempio: tutti zeri), inclusa la palette. Quindi potrebbe disegnare tutto vuoto
in termini di bitmap e quindi sovrascrivere l'intera palette con zeri, con un 
risultato inaspettato. Quindi devi usare un ''GET IMAGE'' preliminare su qualsiasi 
''NEW IMAGE''.

Se vuoi usare ''PUT IMAGE'' senza effetti collaterali sulla palette, puoi optare 
per ''PUT BITMAP''. In questo caso, ugBASIC disegnerà solo il componente pixel, 
lasciando intatto il componente palette.

@syntax = NEW IMAGE( width, height )

@example background = NEW IMAGE(32,32)

@usedInExample contrib_cube.bas
@usedInExample contrib_cube2.bas
@usedInExample images_get_01.bas
@usedInExample images_get_02.bas
@usedInExample images_get_03.bas

</usermanual> */

Variable * new_image( Environment * _environment, int _width, int _height, int _mode ) {

    if ( _environment->emptyProcedure ) {
        Variable * emptyImage = variable_temporary( _environment, VT_IMAGE, "(empty)");
        return emptyImage;
    }
    
    Variable * result = vic2_new_image( _environment, _width, _height, _mode );

    result->usedImage = 1;

    return result;

}
