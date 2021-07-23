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
 * @brief Emit ASM code for <b>SCREEN ROWS [integer]</b>
 * 
 * This function changes the number of lines that can be displayed. 
 * Depending on the hardware, the effect can be different as different 
 * are the acceptable values. This version is the one called when an 
 * integer number of lines is given in the program.
 * 
 * @param _environment Current calling environment
 * @param _rows Number of rows
 */
/* <usermanual>
@keyword SCREEN ROWS
</usermanual> */
void screen_rows( Environment * _environment, int _rows ) {

    outline1("; SCREEN ROWS %d", _rows);

    char rowsString[MAX_TEMPORARY_STORAGE]; sprintf( rowsString, "#$%2.2x", _rows );

    gtia_screen_rows( _environment, rowsString );

}

/**
 * @brief Emit ASM code for <b>SCREEN ROWS [int]x</b>
 * 
 * This function changes the number of lines that can be displayed. 
 * Depending on the hardware, the effect can be different as different 
 * are the acceptable values. This version is the one called when an 
 * expression is given in the program.
 * 
 * @param _environment Current calling environment
 * @param _rows Number of rows
 */
/* <usermanual>
@keyword SCREEN ROWS
</usermanual> */
void screen_rows_var( Environment * _environment, char * _rows ) {

    outline1("; SCREEN ROWS %s", _rows);

    Variable * rows = variable_retrieve( _environment, _rows );
    gtia_screen_rows( _environment, rows->realName );

}
