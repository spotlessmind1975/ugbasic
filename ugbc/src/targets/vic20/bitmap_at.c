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

@english
Set the starting address, in memory, for the bitmap. The input parameter 
is decoded and declined according to the hardware limits. So it is not 
said that exactly the  given address is set.

@italian
Imposta l'indirizzo di partenza, in memoria, per la bitmap. Il parametro 
di input viene decodificato e declinato in base ai limiti hardware. 
Quindi non èdetto che sia impostato esattamente l'indirizzo specificato.

@syntax BITMAP AT # [integer]

@example BITMAP AT #$0000

@seeAlso BITMAP ENABLE

@target vic20
</usermanual> */
void bitmap_at( Environment * _environment, int _address ) {

    // Let's define the special variable bitmapAddress, and update
    // it with the requested value.
    Variable * bitmapAddress = variable_retrieve( _environment, "BITMAPADDRESS" );
    variable_store( _environment, "BITMAPADDRESS", ( ( _address >> 14 ) & 0x1 ) * 0x2000 );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "#$%2.2x", ( _address >> 8 ) );

    vic1_bitmap_at( _environment, addressString );

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

@syntax BITMAP AT [expression]

@example BITMAP AT newAddress
</usermanual> */
void bitmap_at_var( Environment * _environment, char * _address ) {

    // Let's define the special variable bitmapAddress, and update
    // it with the requested value.    
    Variable * bitmapAddress = variable_retrieve( _environment, "BITMAPADDRESS" );
    Variable * address = variable_retrieve( _environment, _address );

    variable_move_naked( _environment, address->name, bitmapAddress->name );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "%s+1", address->realName );

    vic1_bitmap_at( _environment, addressString );

}