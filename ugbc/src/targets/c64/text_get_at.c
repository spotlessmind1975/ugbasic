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
 * @brief Emit code for <strong>= AT$(...,...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _x Column to locate to
 * @param _y Row to locate to
 */
/* <usermanual>
@keyword AT$

@english
The ''AT$'' can be used to change the position of the text cursor directly from 
inside a character string. This is ideal for positioning text once and for all
on screen, no matter what happens in the program, because the text cursor can
be set during the program's initialisation phase. 

The string that is returned takes the standard format. So whenever this string
is printed, the text cursor will be moved to the text coordinates held by x and y.

@italian
''AT$'' può essere utilizzato per modificare la posizione del cursore del 
testo direttamente dall'interno di una stringa di caratteri. Questo è l'ideale 
per posizionare il testo una volta per tutte sullo schermo, indipendentemente 
da ciò che accade nel programma, perché il cursore del testo può essere
impostato durante la fase di inizializzazione del programma.

La stringa restituita assume il formato standard. Quindi ogni volta che
questa stringa viene stampata, il cursore del testo verrà spostato sulle 
coordinate testo x e y.

@syntax = AT$([x],[y])

@example PRINT AT$(10,10)

@usedInExample texts_position_05.bas
@usedInExample texts_position_06.bas

@seeAlso LOCATE
@target all
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
