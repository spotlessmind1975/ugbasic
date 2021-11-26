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

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Return the text ordinate for the given graphic ordinate
 * 
 * @param _environment Current calling environment
 * @param _value Screen ordinate
 * @return Variable* Text ordinate
 */
/* <usermanual>
@keyword Y TEXT

@english
This function performs the conversion of graphic ordinate to text ordinate, and it can be
used to position an area of graphics on the screen, over the text.

@italian
Questa funzione esegue la conversione delle ordinate del formato grafico in ordinate del 
formato testo e può essere utilizzato per posizionare un'area della grafica 
sul testo.

@syntax = Y TEXT([x graphics])

@example x = Y TEXT(100)

@usedInExample graphics_text_03.bas

@target all
</usermanual> */
/* <usermanual>
@keyword YTEXT

@english
Alias for ''Y TEXT''.

@italian
Alias per ''Y TEXT''.

@seeAlso Y TEXT

@target all
</usermanual> */
Variable * y_text_get( Environment * _environment, char * _y ) {

    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_temporary( _environment, VT_POSITION, "(y)" );

    variable_move( _environment, variable_div( _environment, y->name, "FONTHEIGHT", NULL )->name, result->name );

    return result;

}

