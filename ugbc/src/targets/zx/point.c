/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

/* <usermanual>
@keyword POINT

@target zx
 </usermanual> */
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

    outline1("LD HL,(%s)", x->realName );
    outline0("SRA H" );
    outline0("RR L" );
    outline0("SRA H" );
    outline0("RR L" );
    outline0("SRA H" );
    outline0("RR L" );
    outline0("LD DE,HL");

    outline1("LD HL,(%s)", y->realName );
    outline0("SLA L" );
    outline0("RL H" );
    outline0("SLA L" );
    outline0("RL H" );
    outline0("ADD HL,DE" );
    outline0("LD DE,(COLORMAPADDRESS)");
    outline0("ADD HL,DE" );
    outline0("LD A, (HL)");
    outline1("LD (%s), A", result->realName );

    return result;

}
