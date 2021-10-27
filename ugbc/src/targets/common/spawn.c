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

/**
 * @brief Emit code for <strong>SPAWN ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword SPAWN

@english
This keyword will invoke a (parallel) procedure. 

@italian
Questa parola chiave invoca una funzione affinché sia eseguita
in parallelo.

@syntax SPAWN [name][{[parameter],{[parameter],....}}]

@example SPAWN factorial(42)

@target all
</usermanual> */
Variable * spawn_procedure( Environment * _environment, char * _name ) {

    Variable * threadId = variable_temporary( _environment, VT_THREAD, "(thread)");

    Procedure * procedure = _environment->procedures;

    while( procedure ) {
        if ( strcmp( procedure->name, _name ) == 0 ) {
            break;
        }
        procedure = procedure->next;
    }

    if ( !procedure ) {
        CRITICAL_PROCEDURE_MISSING(_name);
    }

    if ( !procedure->protothread ) {
        CRITICAL_PROCEDURE_CANNOT_BE_INVOKED(_name);
    }

    if ( _environment->parameters != procedure->parameters ) {
        CRITICAL_PROCEDURE_PARAMETERS_MISMATCH(_name, procedure->parameters, _environment->parameters );
    }

    int i=0;
    for( i=0; i<procedure->parameters; ++i ) {
        char parameterName[MAX_TEMPORARY_STORAGE]; sprintf( parameterName, "%s__%s", procedure->name, procedure->parametersEach[i] );
        Variable * parameter = variable_retrieve_or_define( _environment, parameterName, procedure->parametersTypeEach[i], 0 );
        Variable * value = variable_retrieve( _environment, _environment->parametersEach[i] );
        variable_move( _environment, value->name, parameter->name );
    }
    _environment->parameters = 0;

    char procedureLabel[MAX_TEMPORARY_STORAGE]; sprintf(procedureLabel, "%s", _name );

    cpu_protothread_register( _environment, procedureLabel, threadId->realName );
    cpu_protothread_set_state( _environment, threadId->realName, PROTOTHREAD_STATUS_WAITING );

    return threadId;

}

