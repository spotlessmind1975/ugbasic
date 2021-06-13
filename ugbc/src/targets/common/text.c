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
 * @brief Emit ASM implementation for <b>TEXT DISABLE</b> instruction
 * 
 * This function can be called to emit the code to disable text mode
 * on the target machine.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword TILEMAP DISABLE

@english
Disable the tilemap mode.

@italian
Disabilita la modalità a tiles.

@syntax TILEMAP DISABLE

@example TILEMAP DISABLE

@target c64
</usermanual> */
void tilemap_disable( Environment * _environment ) {
    
    bitmap_enable( _environment, 0, 0, 0 );
    
}

/*

text screen
	- TEXT ENABLE
	- SCREEN WIDTH
	- SCREEN HEIGHT

text window
	- 0 <= index <= WINDOW COUNT
	- 0 <= x <= SCREEN WIDTH = XWIND(index)
	- 0 <= y <= SCREEN HEIGHT = YWIND(index)
	- 1 <= width <= (SCREEN WIDTH - x) = WWIND(index)
	- 1 <= height <= (SCREEN HEIGHT - x) = HWIND(index)

by default:
text window 0 <-> text screen

windowX_x:	.res 1
windowX_y:	.res 1
windowX_w:	.res 1
windowX_h:	.res 1
windowX_cx:	.res 1
windowX_cy:	.res 1

*/
void setup_text_variables( Environment * _environment ) {

    variable_define( _environment, "windowX", VT_BYTE, 0 );
    variable_define( _environment, "windowY", VT_BYTE, 0 );                
    variable_define( _environment, "windowX2", VT_BYTE, (TEXT_COLUMNS_COUNT-1) );
    variable_define( _environment, "windowY2", VT_BYTE, (TEXT_ROWS_COUNT-1) );                
    variable_define( _environment, "windowCX", VT_BYTE, 0 );
    variable_define( _environment, "windowCY", VT_BYTE, 0 );
    variable_define( _environment, "PEN", VT_COLOR, COLOR_BLACK );
    variable_define( _environment, "PAPER", VT_COLOR, COLOR_WHITE );
    variable_define( _environment, "windowE", VT_BYTE, 0 );
    variable_define( _environment, "windowS", VT_BYTE, 0 );
    variable_define( _environment, "windowW", VT_BYTE, 0 );
    variable_define( _environment, "windowT", VT_BYTE, 4 );
    variable_define( _environment, "windowWW", VT_BYTE, WW_PEN | WW_PAPER );
    variable_define( _environment, "TAB", VT_STRING, 0 );
    variable_store_string( _environment, "TAB", "\t");
    variable_define( _environment, "windowMX", VT_BYTE, 0 );
    variable_define( _environment, "windowMY", VT_BYTE, 0 );                

}

/**
 * @brief Emit code for <strong>LOCATE ...,...</strong>
 * 
 * @param _environment Current calling environment
 * @param _x Column to locate to
 * @param _y Row to locate to
 */
/* <usermanual>
@keyword LOCATE

@english
The ''LOCATE'' command moves the text cursor to specific coordinates, 
and this new location sets the start position for all subsequent 
text printing until commanded otherwise. 

All screen positions are measured in “text coordinates”, which are 
measured in units of one printed character on screen, with the 
x-coordinate controlling the horizontal position and the 
y-coordinate referring to the vertical. 

The top left-hand corner of the screen has coordinates of 0,0 
whereas text coordinates of 15,10 refer to a position 15 characters 
from the left-hand edge of the screen and 10 characters from the top.

The range of these coordinates will depend on the size of your character 
set and the dimensions of the display area allocated, known as a “window”. 

All coordinate measurements are taken using text coordinates relative to 
the current window. If you try and print something outside of these 
limits, an error will be generated or the screen will be automatically
scrolled down.

The current screen is automatically treated as a window, so there is no 
need to "open" one.

@italian
Il comando ''LOCATE'' sposta il cursore del testo su coordinate specifiche,
e questa nuova posizione definisce la posizione iniziale per tutti i successivi
comandi di stampa testo fino a quando non viene comandato diversamente.

Tutte le posizioni dello schermo sono misurate in "coordinate di testo", che sono
misurate in unità di un carattere stampato sullo schermo, con la coordinata x 
che controlla la posizione orizzontale e la coordinata y riferita alla
posizione verticale.

L'angolo in alto a sinistra dello schermo ha coordinate 0,0
mentre le coordinate di testo di 15,10 si riferiscono a una posizione di 15 caratteri
dal bordo sinistro dello schermo e 10 caratteri dall'alto.

L'intervallo di queste coordinate dipenderà dalle dimensioni del carattere
e le dimensioni dell'area di visualizzazione assegnata, denominata "finestra".

Tutte le misurazionidi  coordinate vengono effettuate utilizzando le coordinate 
di  testo relative a la finestra corrente. Provare a stampare qualcosa al di fuori di questi
limiti verrà generato un errore o la schermata verrà automaticamente
fatta scorrere verso il basso.

La schermata corrente viene automaticamente trattata come una finestra, quindi non c'è
bisogno di "aprirne" una.

@syntax LOCATE {[x]},{[y]}

@example LOCATE 15,0
@example LOCATE ,20

@usedInExample texts_position_01.bas
@usedInExample texts_position_02.bas

@seeAlso AT$
@seeAlso CMOVE
@target all
</usermanual> */
void text_locate( Environment * _environment, char * _x, char * _y ) {

    if ( _x ) {
        Variable * windowCX = variable_retrieve( _environment, "windowCX" );
        Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
        variable_move( _environment, x->name, windowCX->name );
    }

    if ( _y ) {
        Variable * windowCY = variable_retrieve( _environment, "windowCY" );
        Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );
        variable_move( _environment, y->name, windowCY->name );
    }

}

void text_cmove_direct( Environment * _environment, int _dx, int _dy ) {

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
 * @brief Emit code for <strong>CLS</strong>
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
void text_cmove( Environment * _environment, char * _dx, char * _dy ) {

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
        Variable * dy = variable_retrieve_or_define( _environment, _dy, VT_BYTE, 0 );
        add_complex( _environment, windowCY->name, dy->name, windowY->name, windowY2->name );
    }

}

/**
 * @brief Emit code for <strong>LOCATE ...,...</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword LOCATE

@english
The ''HOME'' command moves the text cursor back to the top left-hand corner
of the screen in a hurry.

@italian
Il comando "HOME" riporta il cursore del testo nell'angolo in alto a sinistra
dello schermo in fretta.

@syntax HOME

@example HOME

@usedInExample texts_position_02.bas

@seeAlso LOCATE
@seeAlso AT$
@seeAlso CMOVE
@target all
</usermanual> */
void text_home( Environment * _environment ) {

    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );

    variable_store( _environment, x->name, 0 );
    variable_store( _environment, y->name, 0 );

}

void text_text( Environment * _environment, char * _text ) {

    Variable * text = variable_retrieve( _environment, _text );
    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * pen = variable_retrieve( _environment, "PEN" );
    Variable * paper = variable_retrieve( _environment, "PAPER" );
    Variable * ww = variable_retrieve( _environment, "windowWW" );

    text_encoded_at( _environment, x->name, y->name, text->name, pen->name, paper->name, ww->name );
    
}

/**
 * @brief Emit code for <strong>= CMOVE(...,...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _x Column to locate to
 * @param _y Row to locate to
 */
/* <usermanual>
@keyword CMOVE$

@english
The ''CMOVE$'' function can be used to print something relative to the current 
cursor position.

@italian
La funzione ''CMOVE''" può essere utilizzata per stampare qualcosa relativo 
alla posizione corrente del cursore.

@syntax = CMOVE$([x],[y])

@example PRINT CMOVE$(10,10)

@usedInExample texts_position_04.bas

@seeAlso CMOVE
@target all
</usermanual> */
Variable * text_get_cmove( Environment * _environment, char * _x, char * _y ) {
    
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_DSTRING, "(text_get_cmove)" );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(text_get_cmove)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(text_get_cmove)" );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x3  " );

    variable_store_string(_environment, result->name, resultString );
    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );
    
    cpu_move_8bit_with_offset(_environment, x->realName, address->realName, 1 );
    cpu_move_8bit_with_offset(_environment, y->realName, address->realName, 2 );
        
    return result;

}

Variable * text_get_cmove_direct( Environment * _environment, int _x, int _y ) {
    
    Variable * result = variable_temporary( _environment, VT_DSTRING, 0 );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(text_get_cmove)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(text_get_cmove)" );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x3  " );

    variable_store_string(_environment, result->name, resultString );
    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_store_8bit_with_offset(_environment, address->realName, (_x & 0xff), 1 );
    cpu_store_8bit_with_offset(_environment, address->realName, (_y & 0xff), 2 );
        
    return result;

}

/**
 * @brief Emit code for <strong>TAB$</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword TAB$

@english
The ''TAB$'' function returns a special control character called ''TAB'', 
which carries the ASCII code of ''9''. When this character is printed, 
the text cursor is automatically moved to the next tabulated column 
setting (tab) to the right. The default setting for this is four
characters, which can be changed using ''[[SET TAB]]''. 


@italian
La funzione ''TAB$'' restituisce un carattere di controllo speciale 
chiamato "TAB", che contiene il codice ASCII 9. Quando questo carattere
viene stampato, il cursore del testo viene automaticamente spostato 
alla successiva impostazione della colonna tabulata (tabulazione) 
a destra. L'impostazione predefinita per questo è di quattro caratteri,
che può essere modificata utilizzando il comando ''[[SET TAB]]''.

@syntax = TAB$

@example PRINT TAB$

@usedInExample texts_position_08.bas

@target all
</usermanual> */
Variable * text_get_tab( Environment * _environment ) {
    
    Variable * tab = variable_retrieve( _environment, "TAB" );

    return tab;

}

void text_newline( Environment * _environment ) {

    MAKE_LABEL

    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * y2 = variable_retrieve( _environment, "windowY2" );

    cpu_store_8bit( _environment, x->realName, 0 );    

    Variable * result = variable_compare( _environment, y->name, y2->name );    

    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label);
    char scrollLabel[MAX_TEMPORARY_STORAGE]; sprintf(scrollLabel, "%sscroll", label);

    cpu_bvneq( _environment, result->realName, scrollLabel );

    cpu_inc( _environment, y->realName );

    cpu_jump( _environment, endLabel );

    cpu_label( _environment, scrollLabel );

    text_vscroll_screen( _environment, -1 );

    cpu_label( _environment, endLabel );

}

void text_tab( Environment * _environment ) {

    Variable * tab = variable_retrieve( _environment, "TAB" );

    text_text( _environment, tab->name );
    
}

/**
 * @brief Emit code for <strong>SET TAB ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _new_tab New tab count value
 */
/* <usermanual>
@keyword SET TAB

@english
The ''SET TAB'' command specifies the number of characters 
that the text cursor will move to the right when the next 
TAB$ is printed.

@italian
Il comando ''SET TAB'' specifica il numero di caratteri che
il cursore di testo sposterà a destra quando verrà stampato 
il successivo TAB $.

@syntax SET TAB [expression]

@example SET TAB 10

@usedInExample texts_position_08.bas

@target all
</usermanual> */
void text_set_tab( Environment * _environment, char * _new_tab ) {

    Variable * tab = variable_retrieve( _environment, "windowT" );
    Variable * new_tab = variable_retrieve_or_define( _environment, _new_tab, VT_BYTE, 4 );

    variable_move( _environment, new_tab->name, tab->name );
    
}

void text_at( Environment * _environment, char * _x, char * _y, char * _text ) {

    text_locate( _environment, _x, _y );

    text_text( _environment, _text );
    
}

void use_ansi( Environment * _environment ) {

    setup_text_variables( _environment );

    Variable * encoding = variable_retrieve( _environment, "windowE" );

    variable_store( _environment, encoding->name, 1 );
    
}

void use_specific( Environment * _environment ) {

    setup_text_variables( _environment );

    Variable * encoding = variable_retrieve( _environment, "windowE" );

    variable_store( _environment, encoding->name, 0 );
    
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

/**
 * @brief Emit code for <strong>WRITING</strong>
 * 
 * @param _environment Current calling environment
 * @param _mode Expression with the writing mode
 * @param _parts Expression with the writings parts
 */
/* <usermanual>
@keyword WRITING

@english
The WRITING command is used to control how the text is presented on the screen. 
The first value selects one of five writing modes:

 * ''REPLACE'' (0) – new text replaces any existing screen data;
 * ''OR'' (1) – merge new text with screen data, using logical OR;
 * ''XOR'' (2) – combine new text with screen data, using XOR;
 * ''AND'' (3) – Combine new text and screen data, using logical AND;
 * ''IGNORE'' (4) – ignore all subsequent printing instructions.

A number set as the optional second value selects which parts of the
text are to be printed on the screen, as follows:

 * ''NORMAL'' (3) – Print text and background together;
 * ''PAPER'' or ''PAPER ONLY'' (1) – paper only the background to be drawn on screen;
 * ''PEN'' or ''PEN ONLY'' (2) – ignore paper colour and print text on actual background.

The default value for both of the ''WRITING'' parameters is three (''3''), 
giving normal printed output.

@italian
Il comando ''WRITING'' viene utilizzato per controllare come 
il testo viene presentato sullo schermo. Il primo valore seleziona
una delle cinque modalità di scrittura:

  * ''REPLACE'' (0) - il nuovo testo sostituisce i dati dello schermo esistenti;
  * ''OR'' (1) - unisce il nuovo testo con i dati dello schermo, usando l'OR logico;
  * ''XOR'' (2) - combina il nuovo testo con i dati dello schermo, usando XOR;
  * ''AND'' (3) - Combina nuovo testo e dati sullo schermo, usando AND logico;
  * ''IGNORE'' (4) - ignora tutte le istruzioni di stampa successive.

Un numero impostato come secondo valore opzionale seleziona quali parti di
il testo deve essere stampato sullo schermo, come segue:

  * ''NORMAL'' (3) - Stampa testo e sfondo insieme;
  * ''PAPER'' o ''PAPER ONLY'' (1) - colora solo lo sfondo;
  * ''PEN'' o ''PEN ONLY'' (2) - colora solo il testo.

Il valore predefinito per entrambi i parametri di ''WRITING'' è tre ('' 3 ''),
che danno un output stampato normale.

@syntax WRITE {[mode]},{[parts]}

@example WRITING REPLACE,PEN
@example WRITING 3,

@UsedInExample texts_options_06.bas

@seeAlso PEN
@seeAlso PAPER
@target all
</usermanual> */
void text_writing( Environment * _environment, char * _mode, char * _parts ) {

    setup_text_variables( _environment );

    Variable * ww = variable_retrieve( _environment, "windowWW" );
    Variable * mode = variable_retrieve_or_define( _environment, _mode, VT_BYTE, WRITING_REPLACE );
    Variable * parts = variable_retrieve_or_define( _environment, _parts, VT_BYTE, WRITING_NORMAL );

    variable_move( _environment, mode->name, ww->name );
    cpu_math_mul2_const_8bit( _environment, ww->realName, 4  );
    cpu_math_add_8bit( _environment, ww->realName, parts->realName, ww->realName );
    
}

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
by the cursor.

@italian
Il comando ''CENTRE'' (o ''CENTER'') può essere utilizzato per posizionare
il testo al centro dello schermo e per risparmiare lo sforzo di 
calcolare le coordinate del testo per ottenere ciò. Il comando ''CENTER''
prende una stringa di caratteri e la stampa al centro della riga 
attualmente occupata dal cursore.

@syntax CENTRE [expression]

@example CENTRE "HELLO!"

@usedInExample texts_position_07.bas

@target all
</usermanual> */
void text_center( Environment * _environment, char * _string ) {

    setup_text_variables( _environment );

    Variable * x = variable_retrieve( _environment, "windowX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * x2 = variable_retrieve( _environment, "windowX2" );
    Variable * y2 = variable_retrieve( _environment, "windowY2" );
    Variable * string = variable_retrieve( _environment, _string );

    Variable * w = variable_sub( _environment, variable_sub( _environment, x2->name, x->name )->name, variable_string_len( _environment, _string)->name );
    variable_div2_const( _environment, w->name, 1 );

    text_at( _environment, w->name, y->name, string->name );

}

Variable * text_get_xcurs( Environment * _environment ) {
    
    return variable_retrieve( _environment, "windowCX");

}

Variable * text_get_ycurs( Environment * _environment ) {
    
    return variable_retrieve( _environment, "windowCY");

}

void text_memorize( Environment * _environment ) {

    setup_text_variables( _environment );

    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * mx = variable_retrieve( _environment, "windowMX" );
    Variable * my = variable_retrieve( _environment, "windowMY" );

    variable_move_naked( _environment, x->name, mx->name );
    variable_move_naked( _environment, y->name, my->name );

}

void text_remember( Environment * _environment ) {

    outline0("; text_remember");
    
    setup_text_variables( _environment );

    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * mx = variable_retrieve( _environment, "windowMX" );
    Variable * my = variable_retrieve( _environment, "windowMY" );

    variable_move_naked( _environment, mx->name, x->name );
    variable_move_naked( _environment, my->name, y->name );
    variable_store( _environment, mx->name, 0 );
    variable_store( _environment, my->name, 0 );

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