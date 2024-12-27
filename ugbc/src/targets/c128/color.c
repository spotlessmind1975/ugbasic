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

@english

The ''COLOR'' command allows you to redefine the colors used by the graphics chipset, 
where this is possible. "Redefinition" means assigning one of the possible colors to
specific registers called "palette registers".

On some systems this is not possible at all, due to limitations of the chipset or 
the absence of registers: for this reason, in such cases the command is ignored. 
On other systems this corresponds to the modification of specific registers, to which
one of the available colors is assigned. On others it is possible to assign certain 
shades, which therefore go beyond the number of available colors.

Where it is possible to assign a shade, the value can range from ''0'' to the constant 
''SHADES''. However, it may be more practical to use the ''RGB'' function, which 
allows you to calculate the shade starting from the color components (red, green and blue).

If compatibility with Tuned Simons' BASIC is active, the semantics of the command 
changes, to directly indicate some specific components through a series of syntax 
variants. With the three-parameter variant, you can directly set the colors of the 
border, background and text. With the two-parameter variant, it will be possible to 
indicate the border and the background. With a single parameter, it will be possible 
to indicate the color of the border only. There is also the format where the first 
parameter is omitted, in which case the second indicates the color of the text.

Note that the syntax with one or three parameters is automatically considered as pertaining to TSB.

@italian

Il comando ''COLOR'' permette di ridefinire i colori utilizzati dal chipset grafico, 
laddove questo sia possibile. Per "ridefinizione" si intende l'assegnazione, a 
specifici registri chiamati "palette", di uno dei colori possibili. 

Su alcuni sistemi questo non è proprio possibile, a causa delle limitazioni del chipset 
o dell'assenza di registri: ragion per cui, in tali casi il comando viene ignorato. 
Su altri sistemi questo corrisponde alla modifica di specifici registri, a cui 
viene assegnato uno dei colori disponibili. Su altri ancora è possibile assegnare 
determinate sfumature, che vanno quindi oltre il numero di colori disponibili.

Laddove sia possibile assegnare una sfumatura, il valore può andare da ''0'' alla costante 
''SHADES''. Tuttavia, può essere più pratico utilizzare la funzione ''RGB'', che 
permette di calcolare la sfumatura a partire dalle componenti di colore (rosso, verde e blu).

Nel caso sia attiva la compatibilità con il Tuned Simons' BASIC, la semantica del comando 
varia, per indicare direttamente alcune componenti specifiche tramite una serie di varianti 
di sintassi. Con la variante a tre parametri, si possono impostare direttamente i colori 
del bordo, dello sfondo e del testo. Con quella a due parametri, sarà possibile indicare 
il bordo e lo sfondo. Con un singolo parametro, sarà possibile indicare il colore del 
solo bordo. Esiste anche il formato dove il primo parametro è omesso, nel qual caso 
il secondo indicherà il colore del testo.

Da notare che la sintassi con uno o tre parametri è automaticamente considerata 
come afferente a TSB.

@syntax COLOR index, shade
@syntax COLOR border, background, foreground
@syntax COLOR [border,][background] (if TSB is enabled)
@syntax COLOR border
@syntax COLOR ,foreground

@example COLOR 0, $fff

@alias COLOUR
@seeAlso COLOR BORDER
@seeAlso SHADES (constant)
@seeAlso RGB
@target c128
</usermanual> */
/* <usermanual>
@keyword COLOUR

@english

@italian

@syntax COLOUR index, shade

@example COLOUR 0, $fff

@alias COLOR
@seeAlso SHADES (constant)
@seeAlso RGB
@target c128
</usermanual> */

void color( Environment * _environment, int _index, int _shade ) {

    vic2_background_color( _environment, _index, _shade );

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
void color_semivars( Environment * _environment, int _index, char *_shade ) {

    Variable * shade = variable_retrieve_or_define( _environment, _shade, VT_COLOR, 0 );
    
    vic2_background_color_semivars( _environment, _index, shade->realName );

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
void color_vars( Environment * _environment, char *_index, char *_shade ) {

    Variable * index = variable_retrieve_or_define( _environment, _index, VT_BYTE, 0 );
    Variable * shade = variable_retrieve_or_define( _environment, _shade, VT_COLOR, 0 );
    
    vic2_background_color_vars( _environment, index->realName, shade->realName );

}