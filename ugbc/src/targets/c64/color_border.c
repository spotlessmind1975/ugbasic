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

/**
 * @brief Emit ASM code for instruction <b>COLOR BORDER [int]x</b>
 * 
 * This function outputs the ASM code to change the border color, where 
 * the command is invoked with a direct integer value.
 * 
 * @param _environment Current calling environment
 * @param _color Index color to use.
 */
/* <usermanual>
@keyword COLOR BORDER
@target c64
</usermanual> */
void color_border( Environment * _environment, int _color ) {
    
    vic2_border_color( _environment, _color );

}

/**
 * @brief Emit ASM code for instruction <b>COLOR BORDER [expression]</b>
 * 
 * This function outputs the ASM code to change the border color, where 
 * the command is invoked with an expression.
 * 
 * @param _environment Current calling environment
 * @param _color Variable with the expression.
 */
void color_border_var( Environment * _environment, char * _color ) {

    // Safety check -- expression must exists (it should be always true)
    Variable * color = variable_retrieve( _environment, _color );

    vic2_border_color_vars( _environment, color->realName );

}
