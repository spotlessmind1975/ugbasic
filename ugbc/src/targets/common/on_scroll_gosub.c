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

/**
 * @brief Emit ASM code for <b>ON ... GOSUB ...</b>
 * 
 * This function outputs the code to implement the unconditional jump
 * with returning, calculated by expression.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword ON SCROLL..GOSUB

@english
This command is used to force a unconditional jump with returning to a pre-defined position 
when the screen is scrolled down by an entire row or column. 

@italian
Questo comando viene utilizzato per forzare un salto incondizionato a una
posizione predefinita (con ritorno), laddove lo schermo sia fatto scorrere
da una intera riga o colonna.

@syntax ON SCROLL {UP ROW|DOWN ROW|LEFT COLUMN|RIGHT COLUMN} GOSUB [label]

@example ON SCROLL UP ROW GOSUB scrolledAway

@target all
</usermanual> */
void on_scroll_gosub( Environment * _environment, int _x, int _y, char * _label ) {

    switch( _y ) {
        case -1:
            cpu_set_callback( _environment, "ONSCROLLUP", _label );
            break;
        case 1:
            cpu_set_callback( _environment, "ONSCROLLDOWN", _label );
            break;
        default:
            break;
    }

    switch( _x ) {
        case -1:
            cpu_set_callback( _environment, "ONSCROLLLEFT", _label );
            break;
        case 1:
            cpu_set_callback( _environment, "ONSCROLLRIGHT", _label );
            break;
        default:
            break;
    }

}

