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
 * @brief Emit code for <strong>DECLARE PROC ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword DECLARE PROCEDURE

@english

@italian

@syntax DECLARE [SYSTEM] PROCEDURE [name] ( [ [parameter] {, [parameter { [, ...]]]}} ) [ ON [targets] ]] 

@example DECLARE PROCEDURE test ON CPUZ80
@example DECLARE SYSTEM PROCEDURE test ON CPC, ZX

@usedInExample extern_example_11.bas

@target all
</usermanual> */
void declare_procedure( Environment * _environment, char * _name, int _address, int _system ) {

    if ( _environment->emptyProcedure ) {
        return;
    }
    
    if ( _environment->procedureName ) {
        CRITICAL_DECLARE_PROC_NESTED_UNSUPPORTED(_name);
    }

    Procedure * procedure = malloc( sizeof( Procedure ) );
    memset( procedure, 0, sizeof( Procedure ) );
    procedure->name = strdup( _name );
    procedure->declared = 1;
    procedure->address = _address;
    procedure->system = _system;
    
    int i = 0;
    procedure->parameters = _environment->parameters;
    for( i=0; i<_environment->parameters; ++i ) {
        procedure->parametersEach[i] = _environment->parametersEach[i];
        procedure->parametersAsmioEach[i] = _environment->parametersAsmioEach[i];
        procedure->parametersTypeEach[i] = _environment->parametersTypeEach[i];
    }

    procedure->returns = _environment->returns;
    for( i=0; i<_environment->returns; ++i ) {
        procedure->returnsEach[i] = _environment->returnsEach[i];
        procedure->returnsAsmioEach[i] = _environment->returnsAsmioEach[i];
        procedure->returnsTypeEach[i] = _environment->returnsTypeEach[i];
    }

    procedure->next = _environment->procedures;
    
    _environment->procedures = procedure;

}
