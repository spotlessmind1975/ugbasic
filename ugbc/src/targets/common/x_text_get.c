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
 * @brief Return the graphic abscissa for the given text abscissa
 * 
 * @param _environment Current calling environment
 * @param _value Text abscissa
 * @return Variable* Screen abscissa
 */
/* <usermanual>
@keyword X TEXT

@english
This function performs the conversion of graphic abscissa to text abscissa, and can be
used to position an area of graphics on the screen, over the text.

@italian
Questa funzione esegue la conversione delle ascisse del formato grafico in ascisse del 
formato testo e può essere utilizzato per posizionare un'area della grafica 
sul testo.

@syntax = X TEXT([x graphics])

@example x = X TEXT(100)

@usedInExample graphics_text_03.bas

@target all
</usermanual> */
/* <usermanual>
@keyword XTEXT

@english
Alias for ''X TEXT''.

@italian
Alias per ''X TEXT''.

@seeAlso X TEXT

@target all
</usermanual> */
Variable * x_text_get( Environment * _environment, char * _x ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * result = variable_temporary( _environment, VT_POSITION, "(x)" );

    variable_move( _environment, variable_div( _environment, x->name, "FONTWIDTH", NULL )->name, result->name );

    return result;

}

