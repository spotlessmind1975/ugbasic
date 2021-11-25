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
This command allow to redefine every single color, and therefore to each index 
can actually be assigned a hue among the hues available. The indices are 
a small selection from a wide range of possible colors. 

If we wish, we can set this number directly to a value between 0 and ''SCREEN SHADES''. 
Typically, however, we use the ''RGB'' function that allows us to mix the gradient 
by obtaining it from the sum of three simple components.

@italian
Questo comando permette di ridefinire ogni singolo colore, e quindi ad ogni indice 
può essere effettivamente assegnata una tonalità tra quelle disponibili. 
Gli indici rappresentano ora una piccola selezione da un'ampia gamma di 
colori possibili. Il valore della tonalità definisce la tonalità precisa del colore 
da assegnare all'indice. 

E' possibile impostare il numero direttamente su un valore compreso tra 0 e 
''SCREEN SHADES''. Tipicamente, però, utilizziamo la funzione ''RGB'' che ci permette 
di mescolare il gradiente ricavandolo dalla somma di tre semplici componenti.

@syntax COLOR [index], [shade]

@example COLOR 0, $fff

@target atari
</usermanual> */
void color( Environment * _environment, int _index, int _shade ) {

    gtia_background_color( _environment, _index, _shade );

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

    gtia_background_color_vars( _environment, _index, _shade );

}