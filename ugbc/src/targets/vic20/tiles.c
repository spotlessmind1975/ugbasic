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
 * @brief Emit ASM code for <b>TILES AT [int]xx</b>
 * 
 * This function allows you to set the starting address, in memory, for the 
 * tiles (for textual mode) and it is the version that is used when the memory 
 * is given as a direct number (i.e.: $8400). The input parameter is decoded 
 * and declined according to the hardware limits. So it is not said that 
 * exactly the given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `tilees_address` (VT_ADDRESS) - the starting address of text memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
/* <usermanual>
@keyword TILES AT

@english
Set the starting address, in memory, for the tiles (for textual mode).
The input parameter is decoded and declined according to the hardware 
limits. So it is not said that exactly the given address is set.

@italian
Imposta l'indirizzo di partenza, in memoria, per le tile (per 
la modalità testuale). Il parametro di input viene decodificato e 
declinato in base all'hardware. Quindi non è detto che sia impostato
esattamente all'indirizzo specificato.

@syntax TILES AT # [integer]

@example TILES AT #$8400

@target vic20
</usermanual> */
void tiles_at( Environment * _environment, int _address ) {

    

    // Let's define the special variable bitmapAddress, and update
    // it with the requested value.
    // TODO: tile_address should be retrieved via function!
    Variable * tiles_address = variable_retrieve_or_define( _environment, "tiles_address", VT_ADDRESS, _address );
    variable_store( _environment, tiles_address->name, ( ( _address >> 11 ) & 0x07 ) * 0x8400 );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "#$%2.2x", ( _address >> 8 ) & 0xff );

    vic1_tiles_at( _environment, addressString );

}

/**
 * @brief Emit ASM code for <b>TILES AT [expression]</b>
 * 
 * This function allows you to set the starting address, in memory, for the 
 * tiles (for textual mode) and it is the version that is used when the memory 
 * is given as an expression. The input parameter is decoded 
 * and declined according to the hardware limits. So it is not said that 
 * exactly the given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `tiles_address` (VT_ADDRESS) - the starting address of text memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
/* <usermanual>
@keyword TILES AT

@syntax TILES AT [expression]

@example TILES AT tilesAddress

@target vic20
</usermanual> */
void tiles_at_var( Environment * _environment, char * _address ) {

    

    Variable * address = variable_retrieve( _environment, _address );

    Variable * temp = variable_temporary( _environment, VT_ADDRESS, "(temporary storage)" );

    // Let's define the special variable bitmapAddress, and update
    // it with the requested value.
    Variable * tiles_address = variable_define( _environment, "tiles_address", VT_ADDRESS, 0x0800 );
    
    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "%s+1", address->realName );

    vic1_tiles_at( _environment, addressString );

}

