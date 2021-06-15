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

void plot( Environment * _environment, char * _x, char * _y, char *_c ) {

    if ( _c ) {
        pen( _environment, _c );
    }

    if ( !_x ) {
        _x = variable_retrieve( _environment, "XGR" )->name;
    }

    if ( !_y ) {
        _y = variable_retrieve( _environment, "YGR" )->name;
    }

    point_at_vars( _environment, _x, _y );

}

Variable * point( Environment * _environment, char * _x, char * _y ) {

    Variable * result = variable_temporary( _environment, VT_COLOR, "(point's result)");

    if ( !_x ) {
        _x = variable_retrieve( _environment, "XGR" )->name;
    }

    if ( !_y ) {
        _y = variable_retrieve( _environment, "YGR" )->name;
    }

    Variable * y = variable_retrieve( _environment, _y );
    Variable * x = variable_retrieve( _environment, _x );

    outline0( "LD HL, (COLORMAPADDRESS)");
    outline1( "LD A, (%s)", y->realName );
    outline0( "LD D, A" );
    outline0( "LD A, 0" );
    outline0( "LD E, A" );
    outline0( "ADD HL,DE");
    outline1( "LD A, (%s)", x->realName );
    outline0( "LD E, A");
    outline1( "LD A, (%s+1)", x->realName );
    outline0( "LD D, A" );
    outline0( "ADD HL, DE" );
    outline0( "LD A, (HL)");
    outline1( "LD (%s), A", result->realName );

    return result;

}
