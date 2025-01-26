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
 * @brief Emit code for <strong>RIGHTB ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _line Line of window to scroll
 * @param _column Column of window to scroll
 * @param _width Width of window to scroll
 * @param _height Height of window to scroll
 */
/* <usermanual>
@keyword RIGHTB

@english

''RIGHTB'' allows the programmer to scroll right a section of the text screen from ''x,y''
with the ''width'' and the ''height'', including the colors, column by column. 
The new columns inserted are filled in the left column with a "blank" character. 

Note that this command uses console #3 to store the current console values, in order to 
restore them after scrolling. So it cannot be used by the program.

@italian

''RIGHTB'' consente al programmatore di scorrere verso destra una sezione dello schermo 
di testo da ''x,y'' con la ''width'' e l''height'', inclusi i colori, colonna per colonna. 
Le nuove colonne inserite vengono riempite nella colonna a sinistra con un carattere "vuoto".

Da notare che questo comando utilizza la console nr. 3 per stoccare i valori della 
console attuale, al fine di ripristinarli al termine dello scorrimento. Quindi non 
può essere utilizzata dal programma.

@syntax RIGHTB y, x, width, height

@example RIGHTB 1, 1, 10, 10

@seeAlso RIGHTW

@target all
</usermanual> */
void rightb( Environment * _environment, char * _line, char * _column, char * _width, char * _height ) {

    Variable * column = variable_retrieve_or_define( _environment, _column, VT_BYTE, 0 );
    Variable * line = variable_retrieve_or_define( _environment, _line, VT_BYTE, 0 );
    Variable * width = variable_retrieve_or_define( _environment, _width, VT_BYTE, _environment->screenTilesWidth );
    Variable * height = variable_retrieve_or_define( _environment, _height, VT_BYTE, _environment->screenTilesHeight  );

    Variable * x2 = variable_add( _environment, column->name, width->name );
    Variable * y2 = variable_add( _environment, line->name, height->name );

    variable_decrement( _environment, x2->name );
    variable_decrement( _environment, y2->name );
    
    int previous = _environment->activeConsole.id;
    console_save( _environment, 3 );
    console_vars( _environment, _column, _line, x2->name, y2->name );
    text_hscroll_screen( _environment, 1, 0 );
    console_restore( _environment, previous );

}

