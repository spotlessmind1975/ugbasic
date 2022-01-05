/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
* @brief Emit ASM implementation for <b>BITMAP CLEAR WITH [int]</b> instruction
 * 
 * This instruction allows you to fill the bitmap with a certain pattern 
 * (usually zero is used to indicate the blank screen). The filled part is 
 * exclusively that linked to the bitmap, so the color information is kept 
 * unchanged. This is the version that is recalled where the source presents 
 * the instruction with reference to a direct pattern (e.g. 42).
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @param _pattern Pattern to use
 * @throw EXIT_FAILURE "BITMAP CLEAR WITH xxx needs BITMAP ENABLED"
 */
/* <usermanual>
@keyword BITMAP CLEAR

@target pc128op
</usermanual> */
void bitmap_clear_with( Environment * _environment, int _pattern ) {

}

/**
 * @brief Emit ASM implementation for <b>BITMAP CLEAR WITH [expression]</b> instruction
 * 
 * This instruction allows you to fill the bitmap with a certain pattern 
 * (usually zero is used to indicate the blank screen). The filled part is 
 * exclusively that linked to the bitmap, so the color information is kept 
 * unchanged. This is the version that is recalled where the source presents 
 * the instruction with reference to a computer expression.
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @param _pattern Pattern to use
 */
/* <usermanual>
@keyword BITMAP CLEAR
</usermanual> */
void bitmap_clear_with_vars( Environment * _environment, char * _pattern ) {

}

/**
 * @brief Emit ASM implementation for <b>BITMAP CLEAR</b> instruction
 * 
 * This instruction allows you to fill the bitmap with an empty pattern 
 * (usually zero). The filled part is exclusively that linked to the bitmap, 
 * so the color information is kept unchanged. This is the version that is 
 * recalled where the source presents the instruction with reference to a 
 * computer expression.
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @throw EXIT_FAILURE CRITICAL: BITMAP CLEAR WITH xxx needs BITMAP ENABLED
 */
/* <usermanual>
@keyword BITMAP CLEAR
</usermanual> */
void bitmap_clear( Environment * _environment ) {

}
