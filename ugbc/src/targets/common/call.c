/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>CALL/PROC ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword CALL

@english
This keyword will invoke a procedure. 

@italian
Questa parola chiave invoca una funzione.

@syntax CALL [name][{[parameter],{[parameter],....}}]

@example CALL factorial(42)

@usedInExample procedures_param_01.bas
@usedInExample procedures_param_02.bas

@target all
</usermanual> */
/* <usermanual>
@keyword PROC

@english
This keyword will invoke a procedure. 

@italian
Questa parola chiave invoca una funzione.

@syntax PROC [name][{[parameter],{[parameter],....}}]

@example PROC factorial(42)

@usedInExample procedures_param_01.bas
@usedInExample procedures_param_02.bas

@target all
</usermanual> */
void call_procedure( Environment * _environment, char * _name ) {

    if ( _environment->emptyProcedure ) {
        return;
    }

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

    if ( procedure->protothread ) {
        CRITICAL_PARALLEL_PROCEDURE_CANNOT_BE_CALLED(_name);
    }

    if ( procedure->declared ) {

        int realParametersCount = 0;
        if ( procedure->parameters ) {
            for( int i=0; i<procedure->parameters; ++i ) {
                if ( procedure->parametersTypeEach[i] != -1 ) {
                    ++realParametersCount;
                    if ( _environment->parametersEach[i] ) {
                        Variable * var = variable_retrieve( _environment, _environment->parametersEach[i] );
                        cpu_set_asmio_indirect( _environment, procedure->parametersAsmioEach[i], var->realName );
                    } else {
                        cpu_set_asmio( _environment, procedure->parametersAsmioEach[i], _environment->parametersValueEach[i] );
                    }
                } else {
                    cpu_set_asmio( _environment, procedure->parametersAsmioEach[i], procedure->parametersValueEach[i] );
                }
            }
        }

        if ( _environment->parameters != realParametersCount ) {
            CRITICAL_PROCEDURE_PARAMETERS_MISMATCH(_name, realParametersCount, _environment->parameters );
        }

        if ( procedure->system ) {
            sys_call( _environment, procedure->address );
        } else {
            char address[MAX_TEMPORARY_STORAGE]; sprintf( address, "$%4.4x", procedure->address );
            cpu_call( _environment, address );
        }

        if ( procedure->returns ) {
            for( int i=0; i<procedure->returns; ++i ) {
                Variable * var;
                if ( procedure->returnsEach[i] ) {
                    var = variable_retrieve_or_define( _environment, _environment->parametersEach[i], procedure->returnsTypeEach[i], 0 );
                } else {
                    char paramName[MAX_TEMPORARY_STORAGE]; sprintf(paramName,"%s__PARAM", procedure->name );
                    var = variable_define( _environment, paramName, procedure->returnsTypeEach[i], 0 );
                }
                cpu_get_asmio_indirect( _environment, procedure->returnsAsmioEach[i], var->realName );
                break;
            }
        } 

    } else {

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

        cpu_call( _environment, procedureLabel );

    }

    
}

