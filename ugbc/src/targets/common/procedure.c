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

    Variable * current = _environment->procedureVariables ;

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

    char procedureLabel[32]; sprintf(procedureLabel, "%s", _name );

    cpu_call( _environment, procedureLabel );
    
}

void exit_procedure( Environment * _environment ) {

    cpu_return( _environment );
    
}