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

void text_text( Environment * _environment, char * _text ) {

    Variable * text = variable_retrieve( _environment, _text );
    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * pen = variable_retrieve( _environment, "PEN" );
    Variable * paper = variable_retrieve( _environment, "PAPER" );
    Variable * ww = variable_retrieve( _environment, "windowWW" );

    text_encoded_at( _environment, x->name, y->name, text->name, pen->name, paper->name, ww->name );
    
}

void text_newline( Environment * _environment ) {

    MAKE_LABEL

    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * screenHeight = variable_retrieve( _environment, "CURRENTTILESHEIGHT" );

    cpu_store_8bit( _environment, x->realName, 0 );    

    cpu_inc( _environment, y->realName );

    Variable * result = variable_compare( _environment, y->name, screenHeight->name );    

    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label);
    char scrollLabel[MAX_TEMPORARY_STORAGE]; sprintf(scrollLabel, "%sscroll", label);

    cpu_bvneq( _environment, result->realName, scrollLabel );

    cpu_jump( _environment, endLabel );

    cpu_label( _environment, scrollLabel );

    text_vscroll_screen( _environment, -1 );

    cpu_dec( _environment, y->realName );

    cpu_label( _environment, endLabel );

}

void text_tab( Environment * _environment ) {

    Variable * tab = variable_retrieve( _environment, "TAB" );

    text_text( _environment, tab->name );
    
}

void text_at( Environment * _environment, char * _x, char * _y, char * _text ) {

    setup_text_variables( _environment );

    locate( _environment, _x, _y );

    text_text( _environment, _text );
    
}

void text_inverse( Environment * _environment, int _value ) {

    setup_text_variables( _environment );

    Variable * inverse = variable_retrieve( _environment, "windowS" );

    variable_store( _environment, inverse->name, _value );
    
}

void text_shade( Environment * _environment, int _value ) {

    setup_text_variables( _environment );

    Variable * shade = variable_retrieve( _environment, "windowS" );

    variable_store( _environment, shade->name, _value );
    
}

void text_under( Environment * _environment, int _value ) {

    setup_text_variables( _environment );

    Variable * under = variable_retrieve( _environment, "windowS" );

    variable_store( _environment, under->name, _value );
    
}

Variable * text_get_xcurs( Environment * _environment ) {
    
    return variable_retrieve( _environment, "windowCX");

}

Variable * text_get_ycurs( Environment * _environment ) {
    
    return variable_retrieve( _environment, "windowCY");

}

void text_question_mark( Environment * _environment ) {

    Variable * questionMark = variable_temporary( _environment, VT_STRING, "(question mark)" );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "?" );

    variable_store_string(_environment, questionMark->name, resultString );

    text_text( _environment, questionMark->name );

}

/* <usermanual>
@keyword CDOWN

@english
By using the ''CDOWN'' command you can force the text cursor down a single line.

@italian
Utilizzando il comando ''CDOWN'' è possibile forzare il cursore del testo
verso il basso di una singola riga.

@syntax CDOWN

@example CDOWN

@usedInExample texts_position_04.bas

@seeAlso CMOVE
@seeAlso CUP
@seeAlso CDOWN$
@seeAlso CLEFT
@seeAlso CRIGHT
@target all
</usermanual> */

/* <usermanual>
@keyword CDOWN$

@english
The effect of summoning up the special control character ''CDOWN$'' is exactly the 
same as printing after a ''CDOWN'' command. The advantage of this alternative is 
that several text cursor movements can be combined in a single string, using ''CDOWN$''.

@italian
L'effetto dell'uso del carattere di controllo speciale ''CDOWN$'' è esattamente lo
stesso della stampa dopo un comando ''CDOWN''. Il vantaggio di questa alternativa
è che diversi movimenti del cursore di testo possono essere combinati
in una singola stringa, utilizzando ''CDOWN$''.

@syntax CDOWN$

@example PRINT CDOWN$

@usedInExample texts_position_10.bas

@seeAlso CMOVE$
@seeAlso CUP$
@seeAlso CDOWN
@seeAlso CLEFT$
@seeAlso CRIGHT$
@target all
</usermanual> */


/* <usermanual>
@keyword CUP

@english
By using the ''CUP'' command you can force the text cursor up a single line.

@italian
Utilizzando il comando ''CUP'' è possibile forzare il cursore del testo
verso l'alto di una singola riga.

@syntax CUP

@example CUP

@usedInExample texts_position_04.bas

@seeAlso CMOVE
@seeAlso CUP$
@seeAlso CDOWN
@seeAlso CLEFT
@seeAlso CRIGHT
@target all
</usermanual> */

/* <usermanual>
@keyword CUP$

@english
The effect of summoning up the special control character ''CUP$'' is exactly the 
same as printing after a ''CUP'' command. The advantage of this alternative is 
that several text cursor movements can be combined in a single string, using ''CUP$''.

@italian
L'effetto dell'uso del carattere di controllo speciale ''CUP$'' è esattamente lo
stesso della stampa dopo un comando ''CUP''. Il vantaggio di questa alternativa
è che diversi movimenti del cursore di testo possono essere combinati
in una singola stringa, utilizzando ''CUP$''.

@syntax CUP$

@example PRINT CUP$

@usedInExample texts_position_10.bas

@seeAlso CMOVE$
@seeAlso CUP
@seeAlso CDOWN$
@seeAlso CLEFT$
@seeAlso CRIGHT$
@target all
</usermanual> */


/* <usermanual>
@keyword CRIGHT

@english
By using the ''CRIGHT'' command you can force the text cursor right by a single character.

@italian
Utilizzando il comando ''CRIGHT'' è possibile forzare il cursore del testo
verso destra di un singolo carattere.

@syntax CRIGHT

@example CRIGHT

@usedInExample texts_position_04.bas

@seeAlso CMOVE
@seeAlso CUP
@seeAlso CDOWN
@seeAlso CLEFT
@seeAlso CRIGHT$
@target all
</usermanual> */

/* <usermanual>
@keyword CRIGHT$

@english
The effect of summoning up the special control character ''CRIGHT$'' is exactly the 
same as printing after a ''CRIGHT'' command. The advantage of this alternative is 
that several text cursor movements can be combined in a single string, using ''CRIGHT$''.

@italian
L'effetto dell'uso del carattere di controllo speciale ''CRIGHT$'' è esattamente lo
stesso della stampa dopo un comando ''CRIGHT''. Il vantaggio di questa alternativa
è che diversi movimenti del cursore di testo possono essere combinati
in una singola stringa, utilizzando ''CRIGHT$''.

@syntax CRIGHT$

@example PRINT CRIGHT$

@usedInExample texts_position_10.bas

@seeAlso CMOVE$
@seeAlso CUP$
@seeAlso CDOWN$
@seeAlso CLEFT
@seeAlso CRIGHT$
@target all
</usermanual> */

/* <usermanual>
@keyword CLEFT

@english
By using the ''CLEFT'' command you can force the text cursor left by a single character.

@italian
Utilizzando il comando ''CLEFT'' è possibile forzare il cursore del testo
verso sinistra di un singolo carattere.

@syntax CLEFT

@example CLEFT

@usedInExample texts_position_04.bas

@seeAlso CMOVE
@seeAlso CUP
@seeAlso CDOWN
@seeAlso CLEFT$
@seeAlso CRIGHT
@target all
</usermanual> */

/* <usermanual>
@keyword CLEFT$

@english
The effect of summoning up the special control character ''CLEFT$'' is exactly the 
same as printing after a ''CLEFT'' command. The advantage of this alternative is 
that several text cursor movements can be combined in a single string, using ''CLEFT$''.

@italian
L'effetto dell'uso del carattere di controllo speciale ''CLEFT$'' è esattamente lo
stesso della stampa dopo un comando ''CLEFT''. Il vantaggio di questa alternativa
è che diversi movimenti del cursore di testo possono essere combinati
in una singola stringa, utilizzando ''CLEFT$''.

@syntax CLEFT$

@example PRINT CCLEFTUP$

@usedInExample texts_position_10.bas

@seeAlso CMOVE$
@seeAlso CUP$
@seeAlso CDOWN$
@seeAlso CLEFT
@seeAlso CRIGHT$
@target all
</usermanual> */