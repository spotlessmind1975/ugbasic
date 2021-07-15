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
 * @brief Emit code for <strong>PROCEDURE ... END PROC</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword PROCEDURE...END PROC

@english
This couple of keywords create a procedure by giving it a name. The name is
then followed by a list of parameters and the procedure must be ended 
with an ''END PROC'' command. ''PROCEDURE'' and ''END PROC'' commands 
should be placed on their own individual lines, but it is not mandatory.

It is possible to place the procedure definition anywhere in the program. 
When ugBASIC encounters a procedure statement, the procedure is recognised 
and a jump is made to the final ''END PROC''. In this way, there is no 
risk of executing your procedure by accident.

Following the procedure's name can be given a list of parameters. This creates a
group of local variables that can be loaded directly from the main program. 
Note that the values to be loaded into parameters must be entered between 
square brackets as part of the procedure call. This system works equally well
with constants as well as variables, but although you are allowed to 
transfer integer, real or string variables, you may transfer also arrays 
using this method. If you need to enter more than one parameter, the 
variables must be separated by commas.

@italian
Questa coppia di parole chiave crea una procedura assegnandole un nome. 
Il nome è quindi seguito da un elenco di parametri e la procedura deve 
terminare con i comandi ''END PROC''. I comandi dovrebbero essere 
posti su singole righe, ma non è obbligatorio.

È possibile posizionare la definizione della procedura ovunque nel programma. 
Quando ugBASIC incontra una definizione di procedura, la procedura viene 
riconosciuta come tale e viene eseguito un salto all' ''END PROC''. In 
questo modo non vi è alcun rischio di eseguire accidentalmente la procedura.

Di seguito al nome della procedura può essere posto un elenco di parametri. 
Questo crea un gruppo di variabili locali che possono essere caricate 
direttamente dal programma principale. Da notare che i valori da caricare 
nei parametri devono essere inseriti tra parentesi quadre come parte della 
chiamata di procedura. Questo sistema funziona altrettanto bene con
costanti e variabili, ma anche array. Se è necessario immettere più di 
un parametro, i parametri devono essere separate da virgole.

@syntax PROCEDURE [name] [ [parameter] {, [parameter { [, ...]]]}}]
@syntax  ...
@syntax END PROC{ [expression] }

@example PROCEDURE test
@example    DEBUG "HELLO WORLD!"
@example END PROC
@example &nbsp;
@example PROCEDURE sumOf( x, y )
@example END PROC[x+y]

@usedInExample procedures_hello_01.bas
@usedInExample procedures_hello_02.bas
@usedInExample procedures_hello_03.bas
@usedInExample procedures_parameters_01.bas
@usedInExample procedures_parameters_02.bas

@target all
</usermanual> */
void begin_procedure( Environment * _environment, char * _name ) {

    if ( _environment->procedureName ) {
        CRITICAL_PROCEDURE_NESTED_UNSUPPORTED(_name);
    }

    Procedure * procedure = malloc( sizeof( Procedure ) );
    procedure->name = strdup( _name );
    
    int i = 0;
    for( i=0; i<_environment->parameters; ++i ) {
        char parameterName[MAX_TEMPORARY_STORAGE]; sprintf( parameterName, "%s__%s", procedure->name, _environment->parametersEach[i] );
        Variable * parameter = variable_retrieve_or_define( _environment, parameterName, _environment->parametersTypeEach[i], 0 );
    }

    procedure->parameters = _environment->parameters;
    memcpy( &procedure->parametersEach, &_environment->parametersEach, sizeof( char * ) * _environment->parameters );
    memcpy( &procedure->parametersTypeEach, &_environment->parametersTypeEach, sizeof( VariableType ) * _environment->parameters );
    _environment->parameters = 0;

    procedure->next = _environment->procedures;
    _environment->procedures = procedure;

    _environment->procedureName = strdup( _name );
    _environment->procedureVariables = NULL;

    char procedureAfterLabel[MAX_TEMPORARY_STORAGE]; sprintf(procedureAfterLabel, "%safter", _environment->procedureName );
    char procedureLabel[MAX_TEMPORARY_STORAGE]; sprintf(procedureLabel, "%s", _environment->procedureName );

    cpu_jump( _environment, procedureAfterLabel  );

    cpu_label( _environment, procedureLabel );

}
