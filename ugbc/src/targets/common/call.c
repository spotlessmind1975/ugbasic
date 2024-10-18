/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

The ''CALL'' command is used to call a previously defined procedure 
(or subroutine) within the same program. A procedure is a separate 
block of code designed to perform a specific task. By using ''CALL'', 
you can execute the code within the procedure multiple times, without 
having to rewrite the same statements each time.

Before you can call a procedure, you must define it. In ugBASIC, a 
procedure is typically defined with the ''PROCEDURE'' keyword followed 
by the name of the procedure. Inside the procedure, you write 
the statements that should be executed when the procedure is called.

To execute the code within the procedure, you use the ''CALL'' command 
followed by the name of the procedure.

When the program reaches this line, control is transferred to the 
first statement in the procedure. Once all the statements in the procedure 
are executed, control returns to the line after ''CALL''.

Dividing a program into procedures makes the code more organized and easier to read,
and a procedure can be called multiple times from different parts of the program, 
avoiding code duplication. Procedures can be used to break a complex problem into
simpler subproblems, that helps to create a hierarchical structure in the program.

You can also pass arguments to a procedure, enclosed in square parameters: 
arguments are values that are passed to the procedure when it is called and 
that can be used within the procedure itself. If the procedure returns a value, 
the calling statement just ignore  it.

By breaking code into procedures, it becomes easier to understand and maintain,
and by reusing the same procedures in multiple parts of the program, you reduce 
the chances of introducing errors. Finally, if you need to change one part of 
the code, you can simply change the corresponding procedure, without having 
to make changes in all the parts of the program that use that part of the code.

Important: if the ''OPTION CALL AS GOTO'' pragma is in effect, the instruction
will be considered as a ''GOTO'' rather than a ''GOSUB''. So, no return value and
no return, at all. This not applies to system calls.

@italian

Il comando ''CALL'' viene utilizzato per chiamare una procedura (o subroutine) 
definita in precedenza all'interno dello stesso programma. Una procedura è un 
blocco di codice separato progettato per eseguire un'attività specifica. 
Utilizzando ''CALL'', è possibile eseguire il codice all'interno della procedura più 
volte, senza dover riscrivere le stesse istruzioni ogni volta.

Prima di poter chiamare una procedura, è necessario definirla. In ugBASIC, una 
procedura è in genere definita con la parola chiave ''PROCEDURE'' seguita dal nome 
della procedura. All'interno della procedura, si scrivono le istruzioni che devono essere 
eseguite quando la procedura viene chiamata.

Per eseguire il codice all'interno della procedura, si utilizza il comando ''CALL''
seguito dal nome della procedura. Quando il programma raggiunge questa riga, il controllo 
viene trasferito alla prima istruzione nella procedura. Una volta eseguite tutte le istruzioni 
nella procedura, il controllo torna alla riga dopo ''CALL''.

Dividere un programma in procedure rende il codice più organizzato e facile da leggere, 
e una procedura può essere chiamata più volte da diverse parti del programma, evitando 
la duplicazione del codice. Le procedure possono essere utilizzate per suddividere un 
problema complesso in sottoproblemi più semplici, il che aiuta a creare una struttura 
gerarchica nel programma.

Puoi anche passare argomenti a una procedura, racchiusi in parametri quadrati: gli 
argomenti sono valori che vengono passati alla procedura quando viene chiamata e che 
possono essere utilizzati all'interno della procedura stessa. Se la procedura restituisce 
un valore, l'istruzione chiamante lo ignora.

Suddividendo il codice in procedure, diventa più facile da comprendere e gestire, e riutilizzando
le stesse procedure in più parti del programma, riduci le possibilità di introdurre errori. 
Infine, se hai bisogno di modificare una parte del codice, puoi semplicemente modificare la 
procedura corrispondente, senza dover apportare modifiche in tutte le parti del programma che 
utilizzano quella parte del codice.

Importante: se è in vigore il pragma ''OPTION CALL AS GOTO'', l'istruzione verrà considerata 
come un ''GOTO'' anziché un ''GOSUB''. Quindi, nessun valore di ritorno e nessun ritorno, 
per niente. Questo non si applica alle chiamate di sistema.

@syntax CALL name
@syntax CALL name parameters "[" [par1 [, par2[, ...]]] "]"

@example CALL factorial[42]

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
            if ( _environment->parametersEach[i] ) {
                char parameterName[MAX_TEMPORARY_STORAGE]; sprintf( parameterName, "%s__%s", procedure->name, procedure->parametersEach[i] );
                Variable * parameter = variable_retrieve_or_define( _environment, parameterName, procedure->parametersTypeEach[i], 0 );
                Variable * value = variable_retrieve( _environment, _environment->parametersEach[i] );
                variable_move( _environment, value->name, parameter->name );
            } else {
                char parameterName[MAX_TEMPORARY_STORAGE]; sprintf( parameterName, "%s__%s", procedure->name, procedure->parametersEach[i] );
                Variable * parameter = variable_retrieve_or_define( _environment, parameterName, procedure->parametersTypeEach[i], 0 );
                variable_store( _environment, parameter->name, _environment->parametersValueEach[i] );
            }
        }
        _environment->parameters = 0;

        if ( _environment->optionCallAsGoto ) {
            cpu_jump( _environment, procedure->realName );
        } else {
            cpu_call( _environment, procedure->realName );
        }

    }

    
}

