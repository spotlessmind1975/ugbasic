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
 
extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Emit code for <strong>READ</strong> instruction
 * 
 * @param _environment Current calling environment
 * @param _variable Variable to store to
 */
/* <usermanual>
@keyword RANGE
 
@english

The ''RANGE'' function allows you to know if the ''value'' of a variable is within the range 
given by the ''min'' and ''max'' extremes. Note that the extremes are included.
 
@italian
 
La funzione ''RANGE'' consente di sapere se il valore (''value'') di una variabile è all'interno 
dell'intervallo dato dagli estremi ''min'' e ''max''. Da notare che gli estremi sono compresi.

@syntax = RANGE(value,min,max)
 
@example IF RANGE(v,0,100) THEN: PRINT "Value is between 0 and 100.": ENDIF
 
@target all
@verified
</usermanual> */
 
Variable * range( Environment * _environment, char * _expression, char * _min, char * _max ) {

    Variable * expression = variable_retrieve( _environment, _expression );
    Variable * min = variable_retrieve_or_define( _environment, _min, expression->type, 0 );
    Variable * max = variable_retrieve_or_define( _environment, _max, expression->type, 0 );

    return variable_and(
            _environment,
            variable_greater_than( _environment, expression->name, min->name, 1 )->name,
            variable_less_than( _environment, expression->name, max->name, 1 )->name );

}
 
