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
 * @brief Return the maximum value between two expressions
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @return Variable* The maximum value of both
 */
Variable * maximum( Environment * _environment, char * _source, char * _destination ) {
    Variable * source = variable_retrieve( _environment, _source );

    Variable * target = variable_cast( _environment, _destination, source->type );
    if ( ! target ) {
        CRITICAL_VARIABLE(_destination);
    }

    if ( target->type != source->type ) {
        CRITICAL_DATATYPE_MISMATCH( _source, _destination );
    }

    Variable * result = variable_temporary( _environment, source->type, "(result of MAX)");

    MAKE_LABEL

    char greaterThanLabel[32]; sprintf( greaterThanLabel, "%sl1", label );
    char endLabel[32]; sprintf( endLabel, "%sl2", label );

    Variable * compare = variable_greater_than( _environment, source->name, target->name, 0 );

    cpu_bveq( _environment, compare->realName, greaterThanLabel );

    variable_move_naked( _environment, source->name, result->name );
    
    cpu_jump( _environment, endLabel );

    cpu_label( _environment, greaterThanLabel );

    variable_move_naked( _environment, target->name, result->name );
    
    cpu_label( _environment, endLabel );

    return result;
}

