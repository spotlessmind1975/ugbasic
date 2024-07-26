/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>CENTRE ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _string String to center
 */
/* <usermanual>
@keyword CHAR AT

@english

The ''CHAR'' command allows you to display character-by-character text character in 
high-resolution and multi-color modes. The parameters ''x'' and ''y'' specify the 
position of the character on the screen. The next one parameter represents the poke code of that character (see list of the poke codes in the User Guide of your COMMODORE 64). The plot type was described in paragraph 6.4. The last parameter of this command specifies the height of the character, in the range from 1 to 8. The value 1 indicates a normal-sized character, i.e. 8 pixels tall. Increasing the parameter increases the character height proportionally. For example, for a value of 3, the character is 24 pixels tall. The character width CANNOT be changed.

@italian

@syntax 

@example
@example

@target all
@verified
</usermanual> */

void char_at( Environment * _environment, char *_x, char *_y, char *_code, char *_type, char *_size ) {

    Variable * c = variable_string_chr( _environment, _code );
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    pen( _environment, sbpen_get( _environment, _type )->name );
    locate( _environment, 
                variable_div2_const( _environment, x->name, 3 )->name, 
                variable_div2_const( _environment, y->name, 3 )->name 
    );
    print( _environment, c->name, 0 );

}


