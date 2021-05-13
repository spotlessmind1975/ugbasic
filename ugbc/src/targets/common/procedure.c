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

/**
 * @brief Emit code for <strong>RETURN ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _value Value to the return
 */
/* <usermanual>
@keyword RETURN ...

@english
If you want to return a parameter from inside a procedure, that is to say, 
if you need to send back a value from a local variable and/or expression,
you need a way of telling your main program where to find this local variable. T

The ''RETURN'' instruction takes the result of an expression and put it into 
the ''PARAM'' variable and it returns the expression like the result of the calling
procedure.

@italian
Per restituire un parametro dall'interno di una procedura, vale a dire,
per restituire un valore da una variabile locale e/o da un'espressione,
è necessario avere un modo per comunicare al programma principale 
dove trovare questo valore.

L'istruzione ''RETURN'' prende il risultato di un'espressione e lo inserisce
nella variabile ''PARAM'' e, contemporaneamente, lo restituisce come 
espressione come il risultato della chiamata.

@syntax RETURN [expression]

@example RETURN 42

@usedInExample procedures_param_01.bas
@usedInExample procedures_param_02.bas
@usedInExample procedures_param_03.bas

@target all
</usermanual> */
void return_procedure( Environment * _environment, char * _value ) {
    char paramName[MAX_TEMPORARY_STORAGE]; sprintf(paramName,"%s__PARAM", _environment->procedureName );
    Variable * value = variable_retrieve_or_define( _environment, _value, VT_WORD, 0 );
    Variable * param = variable_retrieve_or_define( _environment, paramName, value->type, 0 );
    variable_move( _environment, value->name, param->name );
    cpu_return( _environment );
}

/**
 * @brief Emit code for <strong>PARAM(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 * @return Variable* Variable with the result of the function
 */
/* <usermanual>
@keyword PARAM

@english
The PARAM function takes the result of an expression in an ''END PROC'' statement
(or from a ''RETURN'' statement), and returns it. If the variable you are interested 
in is a string variable, the ''$'' character can be used (but it is not mandatory). 

@italian
La funzione ''PARAM'' recupera il risultato di un'espressione in un'istruzione ''END PROC''
(o da un'istruzione ''RETURN'') e la restituisce. Se la variabile di interesse
è una stringa, è possibile utilizzare il carattere ''$'' (ma non è obbligatorio).

@syntax PARAM([name])

@example CALL factorial
@example x = PARAM(factorial)

@usedInExample procedures_param_01.bas
@usedInExample procedures_param_02.bas

@target all
</usermanual> */
Variable * param_procedure( Environment * _environment, char * _name ) {

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

    char paramName[MAX_TEMPORARY_STORAGE]; sprintf(paramName,"%s__PARAM", _name );
    Variable * param = variable_retrieve( _environment, paramName );
    
    return param;

}

/**
 * @brief Emit code for <strong>END PROC</strong>
 * 
 * @param _environment Current calling environment
 * @param _value Value to the return
 */
/* <usermanual>
@keyword PROCEDURE...END PROC

@english
As an option, you can specify a value for the function to return. 
The value must be indicated in square brackets (''[...]''). 
The value will then be copied into the ''PARAM'' variable and 
returned by the call, if the call was made in the context of an expression.

@italian
Come opzione è possibile indicare un valore da restituire da parte 
della procedura. Il valore va indicato tra parentesi quadre. 
Il valore sarà, quindi, copiato nella variable ''PARAM'' e restituito 
dalla chiamata, se la chiamata è stata fatta nel contesto di una espressione.

@example &nbsp;
@example PROCEDURE hundred
@example END PROC[100]

</usermanual> */
void end_procedure( Environment * _environment, char * _value ) {

    if ( ! _environment->procedureName ) {
        CRITICAL_PROCEDURE_NOT_OPENED();
    }

    if ( _value ) {
        char paramName[MAX_TEMPORARY_STORAGE]; sprintf(paramName,"%s__PARAM", _environment->procedureName );
        Variable * value = variable_retrieve_or_define( _environment, _value, VT_WORD, 0 );
        Variable * param = variable_retrieve_or_define( _environment, paramName, value->type, 0 );
        variable_move( _environment, value->name, param->name );
    }

    char procedureAfterLabel[MAX_TEMPORARY_STORAGE]; sprintf(procedureAfterLabel, "%safter", _environment->procedureName );

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
        char parameterName[MAX_TEMPORARY_STORAGE]; sprintf( parameterName, "%s__%s", procedure->name, procedure->parametersEach[i] );
        Variable * parameter = variable_retrieve_or_define( _environment, parameterName, procedure->parametersTypeEach[i], 0 );
        Variable * value = variable_retrieve( _environment, _environment->parametersEach[i] );
        variable_move( _environment, value->name, parameter->name );
    }
    _environment->parameters = 0;

    char procedureLabel[MAX_TEMPORARY_STORAGE]; sprintf(procedureLabel, "%s", _name );

    cpu_call( _environment, procedureLabel );
    
}

/**
 * @brief Emit code for <strong>POP PROC / EXIT PROC</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword POP PROC

@english
This keyword will exit from a procedure. 

@italian
Questa parola chiave fa uscire da una procedura.

@syntax POP PROC

@example POP PROC

@usedInExample procedures_jumping_02.bas

@target all
</usermanual> */
/* <usermanual>
@keyword EXIT PROC

@english
This keyword will exit from a procedure. 

@italian
Questa parola chiave fa uscire da una procedura.

@syntax EXIT PROC

@example EXIT PROC

@usedInExample procedures_jumping_02.bas

@target all
</usermanual> */
void exit_procedure( Environment * _environment ) {

    cpu_return( _environment );
    
}

/**
 * @brief Manage variable as "global"
 * 
 * @param _environment 
 */
/* <usermanual>
@keyword SHARED

@english
This keyword sets up a list of variables of a procedure that can be accessed from absolutely 
anywhere in your program.

There is a facility of using strings in procedure definitions. 
As with disc names, the "wild card" characters ''*'' and ''?'' can also 
be included. In this case, the ''*'' character is used to mean "match this 
with any list of characters in the variable name, until the next control 
character is reached", and the ''?'' character means "match this with any 
single character in the variable name". 

''GLOBAL'' or ''SHARED'' should be employed before the first use of the 
variable. Only strings may be used for this technique.

@italian
Questa parola chiave imposta un elenco di variabili della procedura a cui è possibile 
accedere da qualsiasi punto del programma. Prima del primo 
utilizzo della variabile è necessario utilizzare ''GLOBAL'' o ''SHARED''.

C'è la possibilità di usare le stringhe nelle definizioni delle procedure.
Come per i nomi dei file, possono essere inclusi anche i caratteri "jolly" 
''*'' e ''?''. In questo caso, il carattere ''*'' viene utilizzato per 
indicare "corrisponde a un qualsiasi elenco di caratteri nel nome della 
variabile, fino a quando non viene raggiunto il carattere di controllo 
successivo", e il carattere ''?''" significa "abbinalo a qualsiasi 
carattere singolo nel nome della variabile". Solo le stringhe possono 
essere utilizzate con questa tecnica.

@syntax SHARED [expression]{, [expression]{,[expression], ...}}

@example SHARED test
@example SHARED "a*", b, "*c"

@usedInExample procedures_global_01.bas
@usedInExample procedures_global_02.bas

@target all
</usermanual> */
void shared( Environment * _environment ) {

    if ( !_environment->procedureName ) {
        CRITICAL_SHARED_ONLY_IN_PROCEDURES();
    }

    int i = 0;
    for( i=0; i<_environment->parameters; ++i ) {
        variable_global( _environment, _environment->parametersEach[i] );
    }
    _environment->parameters = 0;
}

/**
 * @brief Manage variable as "global"
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword GLOBAL

@english
This keyword sets up a list of variables that can be accessed from absolutely 
anywhere in your program. This is a simplified single command, designed to 
be used without the need for an explicit ''SHARED'' statement in
procedure definitions.

There is a facility of using strings in procedure definitions. 
As with disc names, the "wild card" characters ''*'' and ''?'' can also 
be included. In this case, the ''*'' character is used to mean "match this 
with any list of characters in the variable name, until the next control 
character is reached", and the ''?'' character means "match this with any 
single character in the variable name". 

''GLOBAL'' or ''SHARED'' should be employed before the first use of the 
variable. Only strings may be used for this technique.

@italian
Questa parola chiave imposta un elenco di variabili a cui è possibile 
accedere da qualsiasi punto del programma. Si tratta di un singolo comando 
semplificato, progettato per essere utilizzato senza la necessità di un'esplicita 
istruzione ''SHARED'' in sede di definizione de procedura. Prima del primo 
utilizzo della variabile è necessario utilizzare ''GLOBAL'' o ''SHARED''.

C'è la possibilità di usare le stringhe nelle definizioni delle procedure.
Come per i nomi dei file, possono essere inclusi anche i caratteri "jolly" 
''*'' e ''?''. In questo caso, il carattere ''*'' viene utilizzato per 
indicare "corrisponde a un qualsiasi elenco di caratteri nel nome della 
variabile, fino a quando non viene raggiunto il carattere di controllo 
successivo", e il carattere ''?''" significa "abbinalo a qualsiasi 
carattere singolo nel nome della variabile". Solo le stringhe possono 
essere utilizzate con questa tecnica.

@syntax GLOBAL [expression]{, [expression]{,[expression], ...}}

@example GLOBAL test
@example GLOBAL "a*", b, "*c"

@usedInExample procedures_global_01.bas
@usedInExample procedures_global_02.bas

@target all
</usermanual> */
void global( Environment * _environment ) {

    if ( _environment->procedureName ) {
        CRITICAL_GLOBAL_ONLY_OUTSIDE_PROCEDURES();
    }

    int i = 0;
    for( i=0; i<_environment->parameters; ++i ) {
        variable_global( _environment, _environment->parametersEach[i] );
    }
    _environment->parameters = 0;
}