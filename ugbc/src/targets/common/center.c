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
 * @brief Emit code for <strong>CENTRE ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _string String to center
 */
/* <usermanual>
@keyword CENTRE

@english
The ''CENTRE'' (or ''CENTER'') command can be used to position text in the 
centre of the screen, and to save you the effort of calculating the text 
coordinates in order to achieve this. The CENTRE command takes a string 
of characters and prints it in the middle of the line currently occupied 
by the cursor. If the statement is followed by a semicolon, the cursor 
will remain on the same line. Otherwise, it will move to the next line.

@italian
Il comando ''CENTRE'' (o ''CENTER'') può essere utilizzato per posizionare
il testo al centro dello schermo e per risparmiare lo sforzo di 
calcolare le coordinate del testo per ottenere ciò. Il comando ''CENTER''
prende una stringa di caratteri e la stampa al centro della riga 
attualmente occupata dal cursore. Se l'istruzione è seguita dal punto e virgola, 
il cursore rimarrà sulla medesima riga. Altrimenti, si sposterà nella 
riga successiva.

@syntax CENTRE [expression] {;}

@example CENTRE "HELLO!"
@example CENTRE "HELLO!";

@usedInExample texts_position_07.bas

@target all
</usermanual> */
/* <usermanual>
@keyword CENTER

@english
Alias for ''CENTER''.

@italian
Alias per ''CENTRE''.

@seeAlso CENTRE

@target all
</usermanual> */

void center( Environment * _environment, char * _string, int _newline ) {

    MAKE_LABEL
    
    setup_text_variables( _environment );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    Variable * string = variable_retrieve( _environment, _string );
    Variable * currentWidth = variable_retrieve( _environment, "CURRENTTILESWIDTH");
    Variable * len = variable_string_len( _environment, _string);
    Variable * result = variable_temporary( _environment, VT_BYTE, "(compare)");
    Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)");

    cpu_store_8bit( _environment, zero->realName, 0 );

    cpu_greater_than_8bit( _environment, len->realName, currentWidth->realName, result->realName, 1, 0 );

    char nothingLabel[MAX_TEMPORARY_STORAGE]; sprintf( nothingLabel, "%snothing", label );
    char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneLabel, "%sdone", label );

    cpu_bvneq( _environment, result->realName, nothingLabel );

    Variable * w = variable_sub( _environment, currentWidth->name, len->name );
    w = variable_div2_const( _environment, w->name, 1 );

    locate( _environment, w->name, y->name );

    cpu_jump( _environment, doneLabel );

    cpu_label( _environment, nothingLabel );

    locate( _environment, zero->name, y->name );

    cpu_label( _environment, doneLabel );

    text_text( _environment, string->name );

    if ( _newline ) {
        text_newline( _environment );
    }

}
