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

@english

The ''COLOR BORDER'' command allows you to redefine the color used by the graphics chipset
for the border, where this is possible. "Redefinition" means assigning one of the possible 
colors to specific registers called "palette registers".

On some systems this is not possible at all, due to limitations of the chipset or 
the absence of registers or even of the border: for this reason, in such cases the 
command is ignored. On other systems this corresponds to the modification of specific 
registers, to which one of the available colors is assigned. On others it is possible 
to assign certain shades, which therefore go beyond the number of available colors.

Where it is possible to assign a shade, the value can range from ''0'' to the constant 
''SHADES''. However, it may be more practical to use the ''RGB'' function, which 
allows you to calculate the shade starting from the color components (red, green and blue).


@italian

Il comando ''COLOR BORDER'' consente di ridefinire il colore utilizzato dal chipset grafico 
per il bordo, laddove ciò sia possibile. "Ridefinire" significa assegnare uno dei colori 
possibili a registri specifici chiamati "registri palette".

Su alcuni sistemi questo non è affatto possibile, a causa di limitazioni del chipset o 
dell'assenza di registri o addirittura del bordo: per questo motivo, in tali casi il 
comando viene ignorato. Su altri sistemi ciò corrisponde alla modifica di registri 
specifici, a cui viene assegnato uno dei colori disponibili. Su altri è possibile assegnare
determinate tonalità, che quindi vanno oltre il numero di colori disponibili.

Dove è possibile assegnare una tonalità, il valore può variare da ''0'' alla costante 
''SHADES''. Tuttavia, può essere più pratico utilizzare la funzione ''RGB'', che consente 
di calcolare la tonalità a partire dalle componenti del colore (rosso, verde e blu).

@syntax COLOR BORDER value

@example COLOR BORDER #$1

@usedInExample control_uncond_jumps_01.bas
@usedInExample control_uncond_jumps_02.bas

@seeAlso COLOR
@seeAlso SHADES (constant)
@seeAlso RGB
@target c128
</usermanual> */
void color_border( Environment * _environment, int _color ) {
    
    

    char color[MAX_TEMPORARY_STORAGE]; sprintf(color, "#$%2.2x", _color);

    vic2_border_color( _environment, color );

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

    vic2_border_color( _environment, color->realName );

}
