/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for instruction <b>COLOR [int], [int]</b>
 * 
 * This function outputs the ASM code to change the color index, among 
 * those available. It should be used where the command is invoked with integers.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the common color to set
 * @param _shade Shade of the common color to set
 */
/* <usermanual>
@keyword COLOR
</usermanual> */
void color( Environment * _environment, int _index, int _shade ) {

    char indexAsString[MAX_TEMPORARY_STORAGE];
    char shadeAsString[MAX_TEMPORARY_STORAGE];

    sprintf( indexAsString, "#$%2.2x", _index );
    sprintf( shadeAsString, "#$%2.2x", _shade );

    if ( _index == 0 ) {
        c6847_border_color( _environment, shadeAsString );
    }

    c6847_background_color( _environment, indexAsString, shadeAsString );

}

/**
 * @brief Emit ASM code for instruction <b>COLOR [expression], [expression]</b>
 * 
 * This function outputs the ASM code to change the common color, among 
 * those available. It should be used where the command is invoked with expressions.
 * 
 * @param _environment Current calling environment
 * @param _index Expression with the index of common color to set
 * @param _common_color Expression with the index of the color to use
 */
/* <usermanual>
@keyword COLOR
</usermanual> */
void color_semivars( Environment * _environment, int _index, char *_shade ) {

    char indexAsString[MAX_TEMPORARY_STORAGE];

    Variable * shade = variable_retrieve_or_define( _environment, _shade, VT_COLOR, 0 );

    sprintf( indexAsString, "#$%2.2x", _index );

    if ( _index == 0 ) {
        c6847_border_color( _environment, shade->realName );
    }

    c6847_background_color( _environment, indexAsString, shade->realName );

}

/**
 * @brief Emit ASM code for instruction <b>COLOR [expression], [expression]</b>
 * 
 * This function outputs the ASM code to change the common color, among 
 * those available. It should be used where the command is invoked with expressions.
 * 
 * @param _environment Current calling environment
 * @param _index Expression with the index of common color to set
 * @param _common_color Expression with the index of the color to use
 */
/* <usermanual>
@keyword COLOR
</usermanual> */
void color_vars( Environment * _environment, char *_index, char *_shade ) {

    MAKE_LABEL

    Variable * index = variable_retrieve_or_define( _environment, _index, VT_BYTE, 0 );
    Variable * shade = variable_retrieve_or_define( _environment, _shade, VT_COLOR, 0 );

    cpu6809_compare_and_branch_8bit_const( _environment, index->realName, 0, label, 0 );

    c6847_border_color( _environment, shade->realName );

    cpu_label( _environment, label );

    c6847_background_color( _environment, index->realName, shade->realName );

}