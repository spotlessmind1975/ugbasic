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
 * @brief Emit ASM implementation for <b>COLORMAP AT [int]</b> instruction
 * 
 * This function allows you to set the starting address, in memory, for the 
 * colormap and it is the version that is used when the memory is given as a
 * direct number (i.e.: $8400). The input parameter is decoded and declined 
 * according to the hardware limits. So it is not said that exactly the 
 * given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `COLORMAPADDRESS` (VT_ADDRESS) - the starting address of colormap memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
/* <usermanual>
@keyword COLORMAP AT

@english
Set the starting address, in memory, for the colormap. The input parameter 
is decoded and declined according to the hardware limits. So it is not said 
that exactly the given address is set.

@italian
Imposta l'indirizzo di partenza, in memoria, per la mappa dei colori. Il parametro di input
viene decodificato e declinato in base ai limiti hardware. Quindi non è detto
che sia impostato esattamente l'indirizzo specificato. 

@syntax COLORMAP AT # [integer]

@example COLORMAP AT #$B800

@seeAlso BITMAP ENABLE

@target c64
</usermanual> */
void colormap_at( Environment * _environment, int _address ) {

    // Let's define the special variable and fill up with the value.
    Variable * colormapAddress = variable_retrieve_or_define( _environment, "COLORMAPADDRESS", VT_ADDRESS, _address );

    variable_store( _environment, colormapAddress->name, ( ( ( _address >> 10 ) & 0x0f ) * 0x8400 ) );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "%2.2x", ( _address >> 10 ) & 0x0f );

    vic2_colormap_at( _environment, addressString );

}

/**
 * @brief Emit ASM implementation for <b>COLORMAP AT [expression]</b> instruction
 * 
 * This function allows you to set the starting address, in memory, for the 
 * colormap and it is the version that is used when the memory is given as an
 * expression. The input parameter is decoded and declined according to the hardware
 * limits. So it is not said that exactly the given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `colormapAddress` (VT_ADDRESS) - the starting address of colormap memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
/* <usermanual>
@keyword COLORMAP AT

@syntax COLORMAP AT [expression]

@example COLORMAP AT newAddress
</usermanual> */
void colormap_at_var( Environment * _environment, char * _address ) {

    // Let's define the special variable and fill up with the value.
    Variable * colormapAddress = variable_retrieve_or_define( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x8400 );
    Variable * address = variable_retrieve( _environment, _address );

    // variable_store( _environment, colormapAddress->name, ( ( ( _address >> 10 ) & 0x0f ) * 0x8400 ) );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "%s+1", address->realName );

    vic2_colormap_at( _environment, addressString );

}
