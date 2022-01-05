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

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Return the graphic ordinate for the given text ordinate
 * 
 * @param _environment Current calling environment
 * @param _value Text ordinate
 * @return Variable* Screen ordinate
 */
/* <usermanual>
@keyword Y GRAPHIC

@english
This function performs the conversion of text ordinate to graphic ordinate, and can be
used to position text over an area of graphics on the screen.

@italian
Questa funzione esegue la conversione delle ordinate del formato testo in ordinate del formato grafico e può essere
utilizzato per posizionare il testo su un'area della grafica sullo schermo.

@syntax = Y GRAPHIC([x text])

@example x = Y GRAPHIC(10)

@usedInExample graphics_text_01.bas

@target all
</usermanual> */
/* <usermanual>
@keyword YGRAPHIC

@english
Alias for ''Y GRAPHIC''.

@italian
Alias per ''Y GRAPHIC''.

@seeAlso Y GRAPHIC

@target all
</usermanual> */
Variable * y_graphic_get( Environment * _environment, char * _y ) {

    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_temporary( _environment, VT_POSITION, "(y)" );

    variable_move( _environment, variable_mul( _environment, y->name, "FONTHEIGHT" )->name, result->name );

    return result;

}

