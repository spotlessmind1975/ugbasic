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
 * @brief Emit ASM implementation for <b>BITMAP ENABLE</b> instruction
 * 
 * This function can be called to emit the code to enable bitmap graphics
 * on the target machine. Bitmap resolution and colors depends on hardware.
 * Enabling the bitmap also sets the starting address in memory, for those 
 * computers that have graphics mapped in memory.
 * 
 * On some machine calling this instruction will define two special variables:
 * 
 *  * `BITMAPADDRESS` (VT_ADDRESS) - the starting address of bitmap memory
 *  * `COLORMAPADDRESS` (VT_ADDRESS) - the starting address of color map memory
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword BITMAP ENABLE

@target d32

</usermanual> */
void bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}