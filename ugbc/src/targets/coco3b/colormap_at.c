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
</usermanual> */
void colormap_at( Environment * _environment, int _address ) {

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
</usermanual> */
void colormap_at_var( Environment * _environment, char * _address ) {

}
