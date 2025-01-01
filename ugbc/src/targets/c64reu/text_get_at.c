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
 * @brief Emit code for <strong>= AT$(...,...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _x Column to locate to
 * @param _y Row to locate to
 */
 /* <usermanual>
@keyword AT (function)

@english

The ''AT'' function is used to create a string to position the cursor to an exact position on the screen,
when it will be printed on the screen. It's like telling a painter where to start painting on a canvas,
not moving immediately but storing the command in a string. 

The ''AT'' function is followed by two expressions, 
separated by a comma: ''x'' indicates the column in which move the cursor, while ''y'' will be the line 
in which to start writing. 

The string that is returned takes the standard format. So whenever this string
is printed, the text cursor will be moved to the text coordinates held by ''x'' and y.

@italian
La funzione ''AT'' viene utilizzata per creare una stringa per posizionare il cursore in una 
posizione esatta sullo schermo, quando verrà stampato sullo schermo. È come dire a un pittore 
dove iniziare a dipingere su una tela, non muovendosi immediatamente ma memorizzando il 
comando in una stringa.

La funzione ''AT'' è seguita da due espressioni, separate da una virgola: ''x'' indica la 
colonna in cui spostare il cursore, mentre ''y'' sarà la riga in cui iniziare a scrivere.

La stringa restituita assume il formato standard. Quindi ogni volta che questa stringa 
viene stampata, il cursore del testo verrà spostato alle coordinate del testo mantenute 
da ''x'' e y.

@syntax = AT$( x , y )
@syntax = AT( x , y )

@example PRINT AT$(10,10); "at 10, 10"

@usedInExample texts_position_05.bas
@usedInExample texts_position_06.bas

@seeAlso LOCATE (function)

</usermanual> */

 /* <usermanual>
@keyword LOCATE (function)

@english

@italian

@syntax = LOCATE$( x , y )
@syntax = LOCATE( x , y )

@example PRINT LOCATE$(10,10); "at 10, 10"

@usedInExample texts_position_05.bas
@usedInExample texts_position_06.bas

@seeAlso AT (function)

</usermanual> */

Variable * get_at( Environment * _environment, char * _x, char * _y ) {
    
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_DSTRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x4  " );

    variable_store_string(_environment, result->name, resultString );

    cpu_dswrite( _environment, result->realName );
    
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_move_8bit_indirect_with_offset(_environment, x->realName, address->realName, 1 );
    cpu_move_8bit_indirect_with_offset(_environment, y->realName, address->realName, 2 );
        
    return result;

}
