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
 * @brief Emit ASM code for instruction <b>= COLOR( [int] )</b>
 * 
 * This function outputs the ASM code to get the color index, among 
 * those available.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the common color to set
 * @return Shade of the common color to set
 */
/* <usermanual>
@keyword COLOR (function)

@english

This function allows you to retrieve the color associated with the indicated position. 
Depending on the video chipset considered, the parameter of this function can be the 
number of possible colors or a specific register. Furthermore, the information returned 
is of type ''COLOR'', so it can be used where it is necessary to indicate a color. 

Note that this function does not necessarily return information on the "shade", but the 
result can be compared with the predefined constants.

@italian

Questa funzione permette di recuperare il colore associato alla posizione indicata. 
A seconda del chipset video considerato, il parametro di questa funzione può essere 
il numero dei colori possibili oppure un registro specifico. Inoltre, l'informazione 
restituita è di tipo ''COLOR'', quindi utilizzabile laddove sia necessario indicare 
un colore.

Da notare che questa funzione non restituisce necessariamente informazioni sulla 
"sfumatura", ma il risultato può essere confrontato con le costanti predefinite.

@syntax = COLOR(index)

@example c = COLOR(0)

@target c128
</usermanual> */
Variable * color_get_vars( Environment * _environment, char * _index ) {

    Variable * index = variable_retrieve_or_define( _environment, _index, VT_COLOR, COLOR_BLACK );
    Variable * result = variable_temporary( _environment, VT_COLOR, "(shade)" );

    vic2_background_color_get_vars( _environment, index->realName, result->realName );

    return result;
    
}
