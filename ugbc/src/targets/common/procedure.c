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

void begin_procedure( Environment * _environment, char * _name ) {

    if ( _environment->procedureName ) {
        CRITICAL_PROCEDURE_NESTED_UNSUPPORTED(_name);
    }

    Procedure * procedure = malloc( sizeof( Procedure ) );
    procedure->name = strdup( _name );
    
    int i = 0;
    for( i=0; i<_environment->parameters; ++i ) {
        char parameterName[256]; sprintf( parameterName, "%s_%s", procedure->name, _environment->parametersEach[i] );
        Variable * parameter = variable_retrieve_or_define( _environment, parameterName, _environment->parametersTypeEach[i], 0 );
    }

    procedure->parameters = _environment->parameters;
    memcpy( &procedure->parametersEach, &_environment->parametersEach, sizeof( char * ) * _environment->parameters );
    memcpy( &procedure->parametersTypeEach, &_environment->parametersTypeEach, sizeof( VariableType ) * _environment->parameters );

    procedure->next = _environment->procedures;
    _environment->procedures = procedure;

    _environment->procedureName = strdup( _name );
    _environment->procedureVariables = NULL;

    char procedureAfterLabel[32]; sprintf(procedureAfterLabel, "%safter", _environment->procedureName );
    char procedureLabel[32]; sprintf(procedureLabel, "%s", _environment->procedureName );

    cpu_jump( _environment, procedureAfterLabel  );

    cpu_label( _environment, procedureLabel );

}

void end_procedure( Environment * _environment ) {

    if ( ! _environment->procedureName ) {
        CRITICAL_PROCEDURE_NOT_OPENED();
    }

    char procedureAfterLabel[32]; sprintf(procedureAfterLabel, "%safter", _environment->procedureName );

    cpu_return( _environment );

    cpu_label( _environment, procedureAfterLabel );

    _environment->procedureName = NULL;

    Variable * current = _environment->procedureVariables;

    Variable * varLast = _environment->variables;
    if ( varLast ) {
        while( varLast->next ) {
            varLast = varLast->next;
        }
        varLast->next = current;
    } else {
        _environment->variables = current;
    }

    _environment->procedureVariables = NULL;

};

void call_procedure( Environment * _environment, char * _name ) {

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

    if ( _environment->parameters != procedure->parameters ) {
        CRITICAL_PROCEDURE_PARAMETERS_MISMATCH(_name);
    }

    int i=0;
    for( i=0; i<procedure->parameters; ++i ) {
        char parameterName[256]; sprintf( parameterName, "%s_%s", procedure->name, procedure->parametersEach[i] );
        Variable * parameter = variable_retrieve_or_define( _environment, parameterName, procedure->parametersTypeEach[i], 0 );
        Variable * value = variable_retrieve( _environment, _environment->parametersEach[i] );
        variable_move( _environment, value->name, parameter->name );
    }

    char procedureLabel[32]; sprintf(procedureLabel, "%s", _name );

    cpu_call( _environment, procedureLabel );
    
}

void exit_procedure( Environment * _environment ) {

    cpu_return( _environment );
    
}