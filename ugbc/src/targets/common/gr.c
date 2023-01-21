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
 * @brief Emit code for <strong>GR LOCATE</strong> command.
 * 
 * @param _environment Current calling environment
 * @param _x Abscissa of current graphic location
 * @param _y Ordinate of current graphic location
 */
/* <usermanual>
@keyword GR LOCATE

@english
This command allows you to set the coordinates ''(x, y)'' for the next graphic operation. 
If the component is omitted, the current one will remain.

@italian
Questo comando permette di impostare le coordinate ''(x,y)'' per le prossime operazioni 
grafiche. Se la componente viene omessa, rimarrà quella attuale. 

@syntax GR LOCATE { [x] },{ [y] }

@example GR LOCATE 100,10
@usedInExample graphics_clip_01.bas
@usedInExample graphics_position_01.bas
@usedInExample graphics_shapes_02.bas

@target all
</usermanual> */

void gr_locate( Environment * _environment, char * _x, char * _y ) {

    if ( _x ) {
        Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
        Variable * xgr = variable_retrieve( _environment, "XGR" );
        if ( ((struct _Environment *)_environment)->resolutionUsed ) {
            variable_move( _environment, 
                variable_div( _environment, variable_mul( _environment, x->name, "RESOLUTIONX" )->name, "CURRENTWIDTH", NULL )->name, 
                x->name 
            );
        }
        if ( _environment->originUsed ) {
            variable_move( _environment, variable_sub( _environment, x->name, "ORIGINX")->name, xgr->name );
        } else {
            variable_move( _environment, x->name, xgr->name );
        }
    }

    if ( _y ) {
        Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
        Variable * ygr = variable_retrieve( _environment, "YGR" );
        if ( ((struct _Environment *)_environment)->resolutionUsed ) {
            variable_move( _environment, 
                variable_div( _environment, variable_mul( _environment, y->name, "RESOLUTIONY" )->name, "CURRENTHEIGHT", NULL )->name, 
                y->name 
            );
        }
        if ( _environment->originUsed ) {
            variable_move( _environment, variable_sub( _environment, y->name, "ORIGINY")->name, ygr->name );
            if ( _environment->originYDirection > 0 ) {
            } else {
                Variable * temp = variable_temporary( _environment, VT_POSITION, "(zero)");
                variable_store( _environment, temp->name, 0 );
                variable_move( _environment, variable_sub( _environment, temp->name, ygr->name )->name, ygr->name );
            }
        } else {
            variable_move( _environment, y->name, ygr->name );
        }
    }

}
