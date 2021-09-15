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

void cmove_direct( Environment * _environment, int _dx, int _dy ) {

    if ( _dx ) {
        Variable * windowCX = variable_retrieve( _environment, "windowCX" );
        Variable * windowX = variable_retrieve( _environment, "windowX" );
        Variable * windowX2 = variable_retrieve( _environment, "windowX2" );
        Variable * dx = variable_temporary( _environment, VT_SBYTE, "(cmove hz)" );
        variable_store( _environment, dx->name, _dx );
        add_complex( _environment, windowCX->name, dx->name, windowX->name, windowX2->name );
    }

    if ( _dy ) {
        Variable * windowCY = variable_retrieve( _environment, "windowCY" );
        Variable * windowY = variable_retrieve( _environment, "windowY" );
        Variable * windowY2 = variable_retrieve( _environment, "windowY2" );
        Variable * dy = variable_temporary( _environment, VT_SBYTE, "(cmove vt)" );
        variable_store( _environment, dy->name, _dy );
        add_complex( _environment, windowCY->name, dy->name, windowY->name, windowY2->name );
    }

}

/**
 * @brief Emit code for <strong>CMOVE</strong>
 * 
 * @param _environment 
 */
/* <usermanual>
@keyword CMOVE

@english
''CMOVE'' allows to move the text cursor a pre-set distance away from its current position. 
The command is followed by a pair of variables that represent the width and height of the 
required offset, and these values are added to the current cursor coordinates. Like 
''LOCATE'', either of the coordinates can be omitted, as long as the comma is positioned
correctly. An additional technique is to use negative values as well as positive offsets.

@italian
Il comando ''CMOVE'' consente di spostare il cursore del testo di una distanza preimpostata 
dalla sua posizione corrente. Il comando è seguito da una coppia di variabili che rappresentano
la larghezza e l'altezza dell'offset richiesto e questi valori vengono aggiunti alle coordinate
correnti del cursore. Come "LOCATE", una delle coordinate può essere omessa, purché la virgola
sia posizionata correttamente. Una tecnica aggiuntiva consiste nell'utilizzare valori negativi 
e offset positivi.

@syntax CMOVE {[dx]},{[dy]}

@example CMOVE -1, -1

@usedInExample texts_position_03.bas
@usedInExample texts_position_04.bas
@usedInExample texts_position_07.bas

@target all
</usermanual> */
void cmove( Environment * _environment, char * _dx, char * _dy ) {

    if ( _dx ) {
        Variable * windowCX = variable_retrieve( _environment, "windowCX" );
        Variable * windowX = variable_retrieve( _environment, "windowX" );
        Variable * windowX2 = variable_retrieve( _environment, "windowX2" );
        Variable * dx = variable_retrieve_or_define( _environment, _dx, VT_SBYTE, 0 );
        add_complex( _environment, windowCX->name, dx->name, windowX->name, windowX2->name );
    }

    if ( _dy ) {
        Variable * windowCY = variable_retrieve( _environment, "windowCY" );
        Variable * windowY = variable_retrieve( _environment, "windowY" );
        Variable * windowY2 = variable_retrieve( _environment, "windowY2" );
        Variable * dy = variable_retrieve_or_define( _environment, _dy, VT_SBYTE, 0 );
        add_complex( _environment, windowCY->name, dy->name, windowY->name, windowY2->name );
    }

}
