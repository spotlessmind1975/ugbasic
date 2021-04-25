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
void textmap_at( Environment * _environment, int _address ) {

    outline1("; TEXTMAP AT $%4.4x (ignored)", _address);

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
void textmap_at_var( Environment * _environment, char * _address ) {

    outline1("; TEXTMAP AT %s (ignored)", _address);

}

/**
 * @brief Emit ASM implementation for <b>TEXT ENABLE</b> instruction
 * 
 * This function can be called to emit the code to enable text mode
 * on the target machine.
 * 
 * @param _environment Current calling environment
 */
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
void text_disable( Environment * _environment ) {
    
    bitmap_enable( _environment );
    
}