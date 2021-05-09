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
 * @brief Emit ASM code for <b>TEXTMAP AT [int]xx</b>
 * 
 * This function allows you to set the starting address, in memory, for the 
 * text and it is the version that is used when the memory is given as a
 * direct number (i.e.: $0400). The input parameter is decoded and declined 
 * according to the hardware limits. So it is not said that exactly the 
 * given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `textmap_address` (VT_ADDRESS) - the starting address of text memory
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

@example TEXTMAP AT #$0400

@target c64
</usermanual> */
void textmap_at( Environment * _environment, int _address ) {

    outline1("; TEXTMAP AT $%4.4x", _address);

    // Let's define the special variable bitmap_address, and update
    // it with the requested value.
    // TODO: the textmap_address should be populated by a get_textmap_address() function!
    Variable * text_address = variable_define( _environment, "textmap_address", VT_ADDRESS, _address );
    variable_store( _environment, "textmap_address", ( ( _address >> 10 ) & 0x0f ) * 0x0400 );

    char addressString[16]; sprintf(addressString, "#$%2.2x", ( _address >> 8 ) & 0xff );

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
 *  * `textmap_address` (VT_ADDRESS) - the starting address of text memory
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

    Variable * text_address = variable_define( _environment, "text_address", VT_ADDRESS, 0x0400 );

    Variable * address = variable_retrieve( _environment, _address );

    char addressString[16]; sprintf(addressString, "%s+1", address->realName );

    vic2_textmap_at( _environment, addressString );

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
@keyword TEXT ENABLE

@english
Enable the text mode.

@italian
Abilita la modalità testuale.

@syntax TEXT ENABLE

@example TEXT ENABLE

@target c64
</usermanual> */
void text_enable( Environment * _environment ) {
    
    bitmap_disable( _environment );

}

/**
 * @brief Emit ASM implementation for <b>TEXT DISABLE</b> instruction
 * 
 * This function can be called to emit the code to disable text mode
 * on the target machine.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword TEXT DISABLE

@english
Disable the text mode.

@italian
Disabilita la modalità testuale.

@syntax TEXT ENABLE

@example TEXT ENABLE

@target c64
</usermanual> */
void text_disable( Environment * _environment ) {
    
    bitmap_enable( _environment );
    
}

void text_at( Environment * _environment, char * _x, char * _y, char * _text ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * text = variable_retrieve( _environment, _text );

    char textString[16]; sprintf(textString, "%s+1", text->realName );

    vic2_text_at( _environment, x->realName, y->realName, textString, text->realName );
    
}