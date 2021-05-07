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

void add_complex( Environment * _environment, char * _variable, char * _expression, char * _limit_lower, char * _limit_upper ) { 

    MAKE_LABEL

    char lessThanLabel[32]; sprintf( lessThanLabel, "%sl", label );
    char greaterThanLabel[32]; sprintf( greaterThanLabel, "%sg", label );
    char endLabel[32]; sprintf( endLabel, "%se", label );
    
    variable_move_naked( _environment, variable_add( _environment, _variable, _expression )->name, _variable );

    Variable * less = variable_less_than( _environment, _variable, _limit_lower, 0 );

    cpu_bveq( _environment, less->realName, greaterThanLabel );

    variable_move( _environment, _limit_upper, _variable );

    cpu_jump( _environment, endLabel );

    cpu_label( _environment, greaterThanLabel );

    Variable * greater = variable_greater_than( _environment, _variable, _limit_upper, 0 );

    cpu_bveq( _environment, greater->realName, endLabel );

    variable_move( _environment, _limit_lower, _variable );

    cpu_label( _environment, endLabel );

}
