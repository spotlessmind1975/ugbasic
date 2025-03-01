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
 * @brief Emit code for <strong>INKB ...</strong> command
 * 
 * @param _environment Current calling environment
 * @param _color Color to use for the pen
 */
/* <usermanual>
@keyword INKB

@english

The ''INKB'' command is used to select one of two colors as the ink color, 
alternatively. If ''value'' is ''TRUE'', ''color1'' will be chosen as the 
color to use. On the contrary, if the ''value'' is ''FALSE'', ''color2'' 
will be chosen as the color. If any color is omitted, the color will be not
changed.

@italian

Il comando ''INKB'' ha lo scopo di selezionare come colore dell'inchiostro 
uno tra due colori, in alternativa. Se il valore di ''value'' è ''TRUE'', 
sarà scelto color1 come colore da utilizzare. Al contrario, se il valore 
è ''FALSE'', sarà scelto ''color2'' come colore. Se uno dei colori viene
omesso, il colore non sarà comunque modificato.

@syntax INKB value,color1,color2

@example INKB bool,YELLOW,RED

@target all
</usermanual> */

void inkb( Environment * _environment, char * _value, char * _color1, char * _color2 ) {

    Variable * value = variable_retrieve_or_define( _environment, _value, VT_SBYTE, 0 );

    Variable * color1 = NULL;
    if ( _color1 ) {
        color1 = variable_retrieve_or_define( _environment, _color1, VT_COLOR, 0 );
    };

    Variable * color2 = NULL;
    if ( _color2 ) {
        color2 = variable_retrieve_or_define( _environment, _color2, VT_COLOR, 0 );
    };
    
    MAKE_LABEL

    char trueColorLabel[MAX_TEMPORARY_STORAGE]; sprintf( trueColorLabel, "%struec", label );
    char doneColorLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneColorLabel, "%sdone", label );

    cpu_compare_and_branch_8bit_const( _environment, value->realName, 0xff, trueColorLabel, 1 );
    if ( color2 ) {
        ink( _environment, color2->name );
    }
    cpu_jump( _environment, doneColorLabel );

    cpu_label( _environment, trueColorLabel );
    if ( color1 ) {
        ink( _environment, color1->name );
    }

    cpu_label( _environment, doneColorLabel );
    
}
