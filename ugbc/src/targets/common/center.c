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
 * @brief Emit code for <strong>CENTRE ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _string String to center
 */
/* <usermanual>
@keyword CENTRE

@english

@italian

@syntax CENTRE text [;]

@example CENTRE "HELLO!"
@example CENTRE "HELLO!";

@usedInExample texts_position_07.bas
@usedInExample contrib_joystick.bas
@usedInExample contrib_What_a_wonderful_world.bas
@usedInExample screens_resolution_02.bas

@target all

@alias CENTER

@verified
</usermanual> */
/* <usermanual>
@keyword CENTER

@english

The ''CENTER'' command aligns a text string in the center of a line. In other words, 
it allows you to position a word or phrase so that it occupies the available space 
in a symmetrical manner. The ''CENTER'' command calculates the white space needed 
on the sides of the string to center it within the specified width and 
adds the necessary spaces. If the statement is followed by a semicolon, the cursor 
will remain on the same line. Otherwise, it will move to the next line.

This command can be used to create aesthetically pleasing section or chapter titles,
to center menu options in the center of the console and to format data neatly 
in a report. Centered text is easier to read and makes programs look neater.

By using CENTER, you can ensure that text is aligned uniformly in different 
parts of the program, and on different targets. Moreover, reduce the need 
to manually calculate character positions. 

@italian

Il comando ''CENTER'' allinea una stringa di testo al centro di una riga. 
In altre parole, consente di posizionare una parola o una frase in modo 
che occupi lo spazio disponibile in modo simmetrico. Il comando ''CENTER'' 
calcola lo spazio bianco necessario ai lati della stringa per centrarla entro
la larghezza specificata e aggiunge gli spazi necessari. Se l'istruzione è 
seguita da un punto e virgola, il cursore rimarrà sulla stessa riga. Altrimenti,
si sposterà alla riga successiva.

Questo comando può essere utilizzato per creare titoli di sezioni o capitoli 
esteticamente gradevoli, per centrare le opzioni di menu al centro della console 
e per formattare i dati in modo ordinato in un report. Il testo centrato è più 
facile da leggere e rende i programmi più ordinati.

Utilizzando CENTER, è possibile garantire che il testo sia allineato uniformemente
in diverse parti del programma e su diversi target. Inoltre, si riduce la necessità
di calcolare manualmente le posizioni dei caratteri.

@syntax CENTER text [;]

@example CENTER "HELLO!"
@example CENTER "HELLO!";

@usedInExample texts_position_07.bas
@usedInExample contrib_joystick.bas
@usedInExample contrib_What_a_wonderful_world.bas
@usedInExample screens_resolution_02.bas

@target all

@alias CENTRE
</usermanual> */

void center( Environment * _environment, char * _string, int _newline, char * _width ) {

    MAKE_LABEL
    
    Variable * string = variable_retrieve( _environment, _string );
    Variable * currentWidth;
    
    if ( _width ) {
         currentWidth = variable_retrieve( _environment, _width);
    } else {
         currentWidth = variable_retrieve( _environment, "CONSOLEW");
    }
    
    Variable * len = variable_string_len( _environment, _string);
    Variable * result = variable_temporary( _environment, VT_BYTE, "(compare)");
    Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)");

    cpu_store_8bit( _environment, zero->realName, 0 );

    cpu_greater_than_8bit( _environment, len->realName, currentWidth->realName, result->realName, 1, 0 );

    char nothingLabel[MAX_TEMPORARY_STORAGE]; sprintf( nothingLabel, "%snothing", label );
    char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneLabel, "%sdone", label );

    cpu_bvneq( _environment, result->realName, nothingLabel );

    Variable * w = variable_sub( _environment, currentWidth->name, len->name );
    w = variable_sr_const( _environment, w->name, 1 );

    locate( _environment, w->name, NULL );

    cpu_jump( _environment, doneLabel );

    cpu_label( _environment, nothingLabel );

    locate( _environment, zero->name, NULL );

    cpu_label( _environment, doneLabel );

    print( _environment, string->name, 0, 0 );

    if ( _newline && ( _environment->centerWithoutNewLine == 0 ) ) {
        text_newline( _environment );
    }

}
