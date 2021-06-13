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

/* <usermanual>
@keyword TEXTADDRESS

@english
This is a variable (16 bit) that contains the actual address of the textmap. 
It can be modified directly by using assignment, and can be read as any 
other variable. Note that no check is done when using this variable, so an
invalid value lead to undefined behaviours. If you want to use a valid value
please use the [[TEXTMAP AT]] command.

@italian
Questa variabile contiene l'indirizzo effettivo (a 16 bit) della mappa 
di memoria con i contenuti testuali. Può essere modificata direttamente 
utilizzando l'assegnazione, e può essere letta come qualsiasi altra 
variabile. Si noti che non viene eseguito alcun controllo quando si utilizza
questa variabile, quindi un valore non valido porta a comportamenti 
indefiniti. Se vuoi assegnare un valore valido usa il comando [[TEXTMAP AT]].

@syntax [variable] = TEXTADDRESS
@syntax TEXTADDRESS = [expression]

@example actual = TEXTADDRESS
@example TEXTADDRESS = $8400

@target c64

@seeAlso TEXTMAP AT
</usermanual> */

/**
 * @brief Emit ASM code for <b>TEXTMAP AT [int]xx</b>
 * 
 * This function allows you to set the starting address, in memory, for the 
 * text and it is the version that is used when the memory is given as a
 * direct number (i.e.: $8400). The input parameter is decoded and declined 
 * according to the hardware limits. So it is not said that exactly the 
 * given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `TEXTADDRESS` (VT_ADDRESS) - the starting address of text memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
/* <usermanual>
@keyword TEXTMAP AT

@english
Set the starting address, in memory, for the textmap. The input parameter 
is decoded and declined according to the hardware limits. So it is not
said that exactly the given address is set.

@italian
Imposta l'indirizzo di partenza, in memoria, per la textmap. Il parametro 
di input viene decodificato e declinato in base ai limiti hardware. Quindi 
non è detto che sia impostato esattamente con l'indirizzo specificato.

@syntax TEXTMAP AT # [integer]

@example TEXTMAP AT #$8400

@target c64

@seealso TEXTADDRESS
</usermanual> */
void textmap_at( Environment * _environment, int _address ) {

    outline1("; TEXTMAP AT $%4.4x", _address);

    // Let's define the special variable bitmapAddress, and update
    // it with the requested value.
    // TODO: the TEXTADDRESS should be populated by a get_TEXTADDRESS() function!
    Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );
    variable_store( _environment, TEXTADDRESS->realName, ( ( _address >> 10 ) & 0x0f ) * 0x8400 );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "#$%2.2x", ( _address >> 8 ) & 0xff );

    vic2_textmap_at( _environment, addressString );

}

/**
 * @brief Emit ASM code for <b>TEXTMAP AT [expression]</b>
 * 
 * This function allows you to set the starting address, in memory, for the 
 * text and it is the version that is used when the memory is given as an
 * expression. The input parameter is decoded and declined according to the 
 * hardware limits. So it is not said that exactly the given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `TEXTADDRESS` (VT_ADDRESS) - the starting address of text memory
 * 
 * @param _environment Current calling environment
 * @param _address Expression with address to use
 */
/* <usermanual>
@keyword TEXTMAP AT

@syntax TEXTMAP AT [expression]

@example TEXTMAP AT newTextmapAddress

@target c64
</usermanual> */
void textmap_at_var( Environment * _environment, char * _address ) {

    outline1("; TEXTMAP AT %s", _address);

    Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );
    Variable * address = variable_retrieve( _environment, _address );

    variable_move( _environment, address->name, TEXTADDRESS->name );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "%s+1", address->realName );

    vic2_textmap_at( _environment, addressString );

}

void text_encoded_at( Environment * _environment, char * _x, char * _y, char * _text, char * _pen, char * _paper, char *_ww ) {

    Variable * text = variable_retrieve( _environment, _text );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * pen = variable_retrieve( _environment, _pen );
    Variable * ww = variable_retrieve( _environment, _ww );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(text address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(text size)" );

    switch( text->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, text->realName, size->realName );
            cpu_addressof_16bit( _environment, text->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, text->realName, address->realName, size->realName );
            break;
    }

    MAKE_LABEL

    vic2_text_at( _environment, x->realName, y->realName, address->realName, size->realName, pen->realName, ww->realName );

}

void text_vscroll_screen( Environment * _environment, int _direction ) {

    vic2_scroll_text( _environment, _direction );

}

/**
 * @brief Emit code for <strong>CLS</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword CLS

@english
The ''CLS'' command clears the current window.

@italian
Il comando ''CLS'' cancella lo schermo corrente.

@syntax CLS

@example CLS

@usedInExample texts_position_01.bas
@usedInExample texts_position_02.bas

@target all
</usermanual> */
void cls( Environment * _environment, char * _paper ) {

    if ( _paper ) {
        paper( _environment, _paper );
    }

    vic2_cls( _environment );

    outline0("JSR CLS");
    
}

/**
 * @brief Emit code for <strong>CLINE ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _characters Characters to remove
 */
/* <usermanual>
@keyword CLINE

@english
The ''CLINE'' command is used to clear the line currently occupied by the text 
cursor. If ''CLINE'' is followed by a number, then that number of characters
get cleared, starting from the current cursor position and leaving the cursor 
exactly where it is. 

@italian
Il comando ''CLINE'' viene utilizzato per cancellare la riga attualmente 
occupata dal cursore. Se ''CLINE'' è seguito da un numero, quel numero 
di caratteri sarà cancellato, a partire dalla posizione corrente del 
cursore e lasciando il cursore esattamente dove si trova.

@syntax CLINE {[expression]}

@example CLINE

@usedInExample texts_position_01.bas
@usedInExample texts_position_02.bas

@target all
</usermanual> */
void text_cline( Environment * _environment, char * _characters ) {

    Variable * characters = NULL;
    if ( _characters ) {
        characters = variable_retrieve( _environment, _characters );
        outline1("LDA %s", characters->realName);
    } else {
        outline0("LDA #0");
    }
    outline0("STA $25");

    if ( !_environment->textClineDeployed ) {

        Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );
        Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );
        Variable * x = variable_retrieve( _environment, "windowCX" );
        Variable * y = variable_retrieve( _environment, "windowCY" );

        outline0("JMP lib_text_cline_after");

        outline0("lib_text_cline:");
        outline1("LDA %s", x->realName );
        outline0("STA $30" );
        outline1("LDA %s", y->realName );
        outline0("STA $31");

        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", TEXTADDRESS->realName);
        outline0("STA $22");
        outline1("LDA %s+1", TEXTADDRESS->realName);
        outline0("STA $23");
        outline1("LDA %s", colormapAddress->realName );
        outline0("STA $29");
        outline1("LDA %s+1", colormapAddress->realName );
        outline0("STA $2a");
 
        outline0("LDX $31" ); // y
        outline0("BEQ lib_text_cline_skip" );
        outhead0("lib_text_cline_loop1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $23");
        outline0("STA $23");
        outline0("DEX" );
        outline0("BNE lib_text_cline_loop1" );

        outline0("LDX $31" ); // y
        outhead0("lib_text_cline_loopc1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $29");
        outline0("STA $29");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $2a");
        outline0("STA $2a");
        outline0("DEX" );
        outline0("BNE lib_text_cline_loopc1" );

        outhead0("lib_text_cline_skip:" );

        outline0("LDA $25");
        outline0("BEQ lib_text_cline_entire_line");

        outline0("CLC"); // x
        outline0("LDA $30"); // x
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0");
        outline0("ADC $23");
        outline0("STA $23");

        outline0("CLC"); // x
        outline0("LDA $30"); // x
        outline0("ADC $29");
        outline0("STA $29");
        outline0("LDA #0");
        outline0("ADC $2a");
        outline0("STA $2a");

        outline0("LDX $25");
        outline0("LDY #0");


        outhead0("lib_text_cline_increment_x:");
        outline0("LDA #32");
        outline0("STA ($22),y");
        
        outline0("INC $30"); // x
        outline0("LDA $30"); // x
        outline0("CMP #40"); // x
        outline0("BNE lib_text_cline_next"); // x
        outline0("LDA #0"); // x
        outline0("STA $30"); // x
        outline0("INC $31"); // y
        outline0("LDA $31"); // y
        outline0("CMP #24"); // h
        outline0("BNE lib_text_cline_next"); // x

        text_vscroll_screen( _environment, -1 );

        outline0("DEC $31"); // y
        outline0("SEC");
        outline0("LDA $22");
        outline0("SBC #40");
        outline0("STA $22");
        outline0("LDA $23");
        outline0("SBC #0");
        outline0("STA $23");

        outline0("SEC");
        outline0("LDA $29");
        outline0("SBC #40");
        outline0("STA $29");
        outline0("LDA $2a");
        outline0("SBC #0");
        outline0("STA $2a");
 
        outline0("lib_text_cline_next:");
        outline0("INY");
        outline0("DEX");
        outline0("BNE lib_text_cline_increment_x");
        outline0("RTS");

        outhead0("lib_text_cline_entire_line:");

        outline0("LDY #0");

        outhead0("lib_text_cline_increment2_x:");

        outline0("LDA #32");
        outline0("STA ($22),y");
        
        outline0("INY"); // x
        outline0("INC $30"); // x
        outline0("LDA $30"); // x
        outline0("CMP #40"); // x
        outline0("BNE lib_text_cline_increment2_x"); // x
        outline0("RTS");

        outhead0("lib_text_cline_after:");

        _environment->textClineDeployed = 1;

    }

    outline0("JSR lib_text_cline");
    
}

void text_hscroll_line( Environment * _environment, int _direction ) {

    Variable * y = variable_retrieve( _environment, "windowCY" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA $26" );
    outline1("LDA %s", y->realName );
    outline0("STA $31");

    if ( !_environment->textHScrollLineDeployed ) {

        Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );
        Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );

        outline0("JMP lib_text_hscroll_line_after");

        outhead0("lib_text_hscroll_line:" );

        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", TEXTADDRESS->realName);
        outline0("STA $22");
        outline1("LDA %s+1", TEXTADDRESS->realName);
        outline0("STA $23");
        outline1("LDA %s", colormapAddress->realName );
        outline0("STA $29");
        outline1("LDA %s+1", colormapAddress->realName );
        outline0("STA $2a");
 
        outline0("LDX $31" ); // y
        outline0("BEQ lib_text_hscroll_line_skip" );
        outhead0("lib_text_hscroll_line_loop1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $23");
        outline0("STA $23");
        outline0("DEX" );
        outline0("BNE lib_text_hscroll_line_loop1" );

        outline0("LDX $31" ); // y
        outhead0("lib_text_hscroll_line_loopc1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $29");
        outline0("STA $29");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $2a");
        outline0("STA $2a");
        outline0("DEX" );
        outline0("BNE lib_text_hscroll_line_loopc1" );

        outhead0("lib_text_hscroll_line_skip:");
        outline0("LDA $22");
        outline0("STA $24");
        outline0("LDA $23");
        outline0("STA $25");

        outline0("CLC");
        outline0("LDA #1");
        outline0("ADC $24");
        outline0("STA $24");
        outline0("LDA #0");
        outline0("ADC $25");
        outline0("STA $25");

        outline0("LDA $26");
        outline0("CMP #$80");
        outline0("BCC lib_text_hscroll_line_right");

        outhead0("lib_text_hscroll_line_left:");
        outline0("LDY #0");
        outhead0("lib_text_hscroll_line_left_loop:");
        outline0("LDA ($24),Y");
        outline0("STA ($22),Y");
        outline0("INY");
        outline0("CPY #39");
        outline0("BNE lib_text_hscroll_line_left_loop");
        outline0("LDA #32");
        outline0("STA ($22),Y");
        outline0("RTS");

        outhead0("lib_text_hscroll_line_right:");
        outline0("CLC");
        outline0("LDA #1");
        outline0("ADC $24");
        outline0("STA $24");
        outline0("LDA #0");
        outline0("ADC $25");
        outline0("STA $25");
        outline0("LDY #40");
        outhead0("lib_text_hscroll_line_right_loop:");
        outline0("LDA ($22),Y");
        outline0("STA ($24),Y");
        outline0("DEY");
        outline0("CPY #0");
        outline0("BNE lib_text_hscroll_line_right_loop");
        outline0("LDA #32");
        outline0("STA ($24),Y");
        outline0("RTS");

        outhead0("lib_text_hscroll_line_after:");

        _environment->textHScrollLineDeployed = 1;

    }

    outline0("JSR lib_text_hscroll_line");
    
}

void text_hscroll_screen( Environment * _environment, int _direction ) {

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA $26" );

    if ( !_environment->textHScrollScreenDeployed ) {

        Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );
        Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );

        outline0("JMP lib_text_hscroll_screen_after");

        outline0("lib_text_hscroll_screen:");

        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", TEXTADDRESS->realName);
        outline0("STA $22");
        outline1("LDA %s+1", TEXTADDRESS->realName);
        outline0("STA $23");
        outline1("LDA %s", colormapAddress->realName );
        outline0("STA $29");
        outline1("LDA %s+1", colormapAddress->realName );
        outline0("STA $2a");
 
        outline0("LDX #24" ); // y

        outline0("LDA $22");
        outline0("STA $24");
        outline0("LDA $23");
        outline0("STA $25");

        outline0("CLC");
        outline0("LDA #1");
        outline0("ADC $24");
        outline0("STA $24");
        outline0("LDA #0");
        outline0("ADC $25");
        outline0("STA $25");

        outhead0("lib_text_hscroll_screen_loop:")
        outline0("LDA $26");
        outline0("CMP #$80");
        outline0("BCC lib_text_hscroll_screen_right");

        outhead0("lib_text_hscroll_screen_left:");
        outline0("LDY #0");
        outhead0("lib_text_hscroll_screen_left_loop:");
        outline0("LDA ($24),Y");
        outline0("STA ($22),Y");
        outline0("INY");
        outline0("CPY #39");
        outline0("BNE lib_text_hscroll_screen_left_loop");
        outline0("LDA #32");
        outline0("STA ($22),Y");
        outline0("JMP lib_text_hscroll_screen_next_line");

        outhead0("lib_text_hscroll_screen_right:");
        outline0("CLC");
        outline0("LDA #1");
        outline0("ADC $24");
        outline0("STA $24");
        outline0("LDA #0");
        outline0("ADC $25");
        outline0("STA $25");
        outline0("LDY #40");
        outhead0("lib_text_hscroll_screen_right_loop:");
        outline0("LDA ($22),Y");
        outline0("STA ($24),Y");
        outline0("DEY");
        outline0("CPY #0");
        outline0("BNE lib_text_hscroll_screen_right_loop");
        outline0("LDA #32");
        outline0("STA ($24),Y");

        outhead0("lib_text_hscroll_screen_next_line:")

        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $23");
        outline0("STA $23");

        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $24");
        outline0("STA $24");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $25");
        outline0("STA $25");

        outline0("DEX");
        outline0("BNE lib_text_hscroll_screen_loop");
        outline0("RTS");

        outhead0("lib_text_hscroll_screen_after:");

        _environment->textHScrollScreenDeployed = 1;

    }

    outline0("JSR lib_text_hscroll_screen");
    
}

/**
 * @brief Emit code for the <strong>PEN$(...)</strong>
 * 
 * @param _environment 
 * @param _color 
 * @return Variable* 
 */
/* <usermanual>
@keyword PEN$

@english
The ''PEN$'' function returns a special control sequence that changes
the pen colour inside a string. This means that, whenever the string is 
printed on the screen, the pre-set pen colour is automatically assigned 
to it. The format of the string returned by ''PEN$'' is not specific 
for the target. 

@italian
La funzione ''PEN$'' restituisce una speciale sequenza di controllo 
che cambia il colore della penna all'interno di una stringa. 
Ciò significa che, ogni volta che la stringa viene stampata 
sullo schermo, le viene automaticamente assegnato il colore 
della penna preimpostato. Il formato della stringa restituita da
''PEN$'' non è specifico per l'hardware

@syntax = PEN$([expression])

@example PRINT PEN$(BLACK)

@UsedInExample texts_options_02.bas

@target all
</usermanual> */
Variable * text_get_pen( Environment * _environment, char * _color ) {
    
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_WHITE );

    Variable * result = variable_temporary( _environment, VT_DSTRING, 0 );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, 0 );
    Variable * size = variable_temporary( _environment, VT_BYTE, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x1 " );

    variable_store_string(_environment, result->name, resultString );

    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_move_8bit_with_offset(_environment, color->realName, address->realName, 1 );
        
    return result;

}

/**
 * @brief Emit code for the <strong>PAPER$(...)</strong>
 * 
 * @param _environment 
 * @param _color 
 * @return Variable* 
 */
/* <usermanual>
@keyword PAPER$

@english
The ''PEN$'' function returns a special control sequence that changes
the paper colour inside a string. This means that, whenever the string is 
printed on the screen, the pre-set paper colour is automatically assigned 
to it. The format of the string returned by ''PAPER$'' is not specific 
for the target. 

@italian
La funzione ''PAPER$'' restituisce una speciale sequenza di controllo 
che cambia il colore dello sfondo all'interno di una stringa. 
Ciò significa che, ogni volta che la stringa viene stampata 
sullo schermo, le viene automaticamente assegnato il colore 
dello sfondo preimpostato. Il formato della stringa restituita da
''PAPER$'' non è specifico per l'hardware

@syntax = PAPER$([expression])

@example PRINT PAPER$(WHITE)

@UsedInExample texts_options_02.bas

@target all
</usermanual> */
Variable * text_get_paper( Environment * _environment, char * _color ) {
    
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    Variable * result = variable_temporary( _environment, VT_DSTRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x2 " );

    variable_store_string(_environment, result->name, resultString );

    cpu_dswrite( _environment, result->realName );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_move_8bit_with_offset(_environment, color->realName, address->realName, 1 );
        
    return result;

}

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

Variable * text_get_at( Environment * _environment, char * _x, char * _y ) {
    
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_DSTRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x4  " );

    variable_store_string(_environment, result->name, resultString );

    cpu_dswrite( _environment, result->realName );
    
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_move_8bit_with_offset(_environment, x->realName, address->realName, 1 );
    cpu_move_8bit_with_offset(_environment, y->realName, address->realName, 2 );
        
    return result;

}

/**
 * @brief Emit ASM implementation for <b>TEXT ENABLE</b> instruction
 * 
 * This function can be called to emit the code to enable text mode
 * on the target machine.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword TILEMAP ENABLE

@english
Enable the tilemap mode.

@italian
Abilita la modalità a tiles.

@syntax TILEMAP ENABLE

@example TILEMAP ENABLE

@target c64
</usermanual> */
void tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {
    
    vic2_tilemap_enable( _environment, _width, _height, _colors );

}

/**
 * @brief Emit code for <strong>PEN ...</strong> command
 * 
 * @param _environment Current calling environment
 * @param _color Color to use for the pen
 */
/* <usermanual>
@keyword PEN

@english
The ''PEN'' command sets the colour of the text displayed in the current
window, when followed by the colour index number of your choice. 
The default setting of the pen colour is index number ''DEFAULT PEN'', 
and alternative colours may be selected from one of up to ''PEN COLORS'' 
choices, depending on the current graphics mode.

@italian
Il comando "PEN" imposta il colore del testo visualizzato nella finestra 
corrente, quando seguito dal numero di indice del colore scelto. 
L'impostazione predefinita del colore della penna è il numero di indice
''DEFAULT PEN'', e colori alternativi possono essere selezionati 
da una delle scelte fino a "PEN COLORS", a seconda della modalità 
grafica corrente.

@syntax PEN [expression]

@example PEN 4
@example PEN (esempio)

@UsedInExample texts_options_01.bas
@UsedInExample texts_options_02.bas

@target all
</usermanual> */

void pen( Environment * _environment, char * _color ) {

    Variable * pen = variable_retrieve( _environment, "PEN" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    MAKE_LABEL

    variable_move( _environment, color->name, pen->name );
    outline0("LDA $D011");
    outline0("AND #%00100000");
    outline1("BEQ %stxt", label );
    outline0("CLC" );
    outline0("ASL A" );
    outline0("CLC" );
    outline0("ASL A" );
    outline0("CLC" );
    outline0("ASL A" );
    outline0("CLC" );
    outline0("ASL A" );
    outhead1("%stxt:", label );
    
}