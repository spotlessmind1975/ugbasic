/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code to implement <strong>CLIP</strong> command
 * 
 * @param _environment Current calling environment
 * @param _x1 Left abscissa for clipping area
 * @param _y1 Top ordinate for clipping area
 * @param _x2 Right abscissa for clipping area
 * @param _y2 Bottom ordinate for clipping area
 */
/* <usermanual>
@keyword CLIP

@english
The ''CLIP'' instruction allows you to delimit the area in which the graphics 
are actually drawn. In general, the area corresponds to the entire surface 
of the screen ''(0,0)-(SCREEN WIDTH,SCREEN HEIGHT)''. However, it is possible 
to limit the drawing to a sub area, to ensure that the area outside this crop
area is not altered or modified. 

The area is bounded by the coordinate ''(x1, y1)'' to the coordinate ''(x2, y2)''. 
If any of the components are omitted, the current value will be used.

@italian
L'istruzione ''CLIP'' permette di delimitare l'area nella quale la grafica 
viene effettivamente disegnata. In generale, l'area corrisponde all'intera 
superficie dello schermo. E' tuttavia possibile limitare il disegno a una sotto 
area, di modo da garantire che l'are al di fuori di tale area di ritaglio non 
venga alterata o modificata. L'area viene delimitata dalla coordinata ''(x1,y1)'' 
alla coordinata ''(x2,y2)''. Se una delle componenti viene omessa, sarà 
utilizzato il valore attuale. 

@syntax CLIP { [x1] },{ [y1] } TO { [x2] },{ [x2] } 

@example CLIP 42,42 TO 84,84
@usedInExample graphics_clip_01.bas

@target all
</usermanual> */
void clip( Environment * _environment, char * _x1, char * _y1, char * _x2, char * _y2 ) {

    Variable * c;
    
    c = variable_retrieve( _environment, "CLIPX1" );
    if ( _x1 ) {
        Variable * x = variable_retrieve_or_define( _environment, _x1, VT_POSITION, 0 );
        variable_move( _environment, x->name, c->name );
    } else {
        variable_store( _environment, c->name, 0 );
    }

    c = variable_retrieve( _environment, "CLIPY1" );
    if ( _y1 ) {
        Variable * x = variable_retrieve_or_define( _environment, _y1, VT_POSITION, 0 );
        variable_move( _environment, x->name, c->name );
    } else {
        variable_store( _environment, c->name, 0 );
    }

    c = variable_retrieve( _environment, "CLIPX2" );
    if ( _x2 ) {
        Variable * x = variable_retrieve_or_define( _environment, _x2, VT_POSITION, 0 );
        variable_move( _environment, x->name, c->name );
    } else {
        variable_move( _environment, screen_get_width( _environment )->name, c->name );
    }

    c = variable_retrieve( _environment, "CLIPY2" );
    if ( _y2 ) {
        Variable * x = variable_retrieve_or_define( _environment, _y2, VT_POSITION, 0 );
        variable_move( _environment, x->name, c->name );
    } else {
        variable_move( _environment, screen_get_height( _environment )->name, c->name );
    }

}
