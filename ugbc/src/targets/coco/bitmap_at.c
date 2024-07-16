/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM implementation for <b>BITMAP AT [int]</b> instruction
 * 
 * This function allows you to set the starting address, in memory, for the 
 * bitmap and it is the version that is used when the memory is given as a
 * direct number (i.e.: $A000). The input parameter is decoded and declined 
 * according to the hardware limits. So it is not said that exactly the 
 * given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `BITMAPADDRESS` (VT_ADDRESS) - the starting address of bitmap memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
/* <usermanual>
@keyword BITMAP AT

@target coco
</usermanual> */
void bitmap_at( Environment * _environment, int _address ) {

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "#$%4.4x", _address );

    c6847_bitmap_at( _environment, addressString );

}

/**
 * @brief Emit ASM implementation for <b>BITMAP AT [expression]</b> instruction
 * 
 * This function allows you to set the starting address, in memory, for the 
 * bitmap and it is the version that is used when the memory is given as a
 * expression that involves variables. The input parameter is decoded and declined 
 * according to the hardware limits. So it is not said that exactly the 
 * given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `BITMAPADDRESS` (VT_ADDRESS) - the starting address of bitmap memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
/* <usermanual>
@keyword BITMAP AT
</usermanual> */
void bitmap_at_var( Environment * _environment, char * _address ) {

    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0x0c00 );

    c6847_bitmap_at( _environment, address->realName );

}