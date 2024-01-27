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
 * @brief Emit code for <strong>DECLARE PROC ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword DECLARE PROCEDURE

@english

The ''DECLARE PROCEDURE'' is a way to define and call external procedures written in machine language 
and to insert assembly into the sources. The procedures defined in this way can be called as if they 
were an integral part of the language. Once the procedure has been declared, it will be sufficient 
to invoke it with one of the following syntaxes:

  CALL test

  PROC test

  test[]

as if it were any ugBASIC procedure. If desired, parameters can be added. For each it is obviously 
necessary to indicate how the value will be passed to the function written in machine language. 

The ugBASIC compiler allows you to declare functions and procedures that are “system”. What does 
“system” mean? It means that the machine code resides in a ROM, preloaded at run time and therefore 
already made available to any program that knows how to call it.

However, since ugBASIC makes available all memory space allowed by the hardware, it is possible that
the ROMs have been disabled or otherwise made unreachable. Indicating that you want to call a procedure
or a system function, ugBASIC will take care of re-enabling the ROM before executing the request, 
deactivating it on exit. 

To declare a procedure or function to be system, simply use the ''SYSTEM'' keyword. 

@italian

Il ''DECLARE PROCEDURE'' è un modo per definire e chiamare procedure esterne scritte in linguaggio macchina 
e per inserire assembly nei sorgenti. Le procedure così definite possono essere richiamate come se 
fossero parte integrante del linguaggio. Una volta dichiarata la procedura sarà sufficiente invocarla 
con una delle seguenti sintassi:

  CALL test

  PROC test

  test[]

come se fosse una procedura ugBASIC. Se lo si desidera, è possibile aggiungere parametri. Per ognuno 
è ovviamente necessario indicare come verrà passato il valore alla funzione scritta in linguaggio macchina.

Il compilatore ugBASIC consente di dichiarare funzioni e procedure che sono “di sistema”. Cosa significa 
“di sistema”? Vuol dire che il codice macchina risiede in una ROM, precaricata in fase di esecuzione e 
quindi già resa disponibile a qualsiasi programma che sappia chiamarla.

Tuttavia, poiché ugBASIC mette a disposizione tutto lo spazio di memoria consentito dall'hardware, è 
possibile che le ROM siano state disabilitate o comunque rese irraggiungibili. Indicando che si vuole 
chiamare una procedura o una funzione di sistema, ugBASIC si occuperà di riabilitare la ROM prima di 
eseguire la richiesta, disattivandola all'uscita.

Per dichiarare una procedura o una funzione come sistema, utilizzare semplicemente la parola chiave ''SYSTEM''.

@syntax DECLARE [SYSTEM] PROCEDURE name AT address [ ( par1 [, par2 [, ... ] ] ) ] [ ON targets ]
@syntax par : name AS type ON register
@syntax par : name AS type ON STACK(width)
@syntax width: BYTE | WORD | DWORD
@syntax targets : name of targets, separated by comma (,)

@example DECLARE SYSTEM PROCEDURE test ON CPC, ZX

@usedInExample extern_example_11.bas

@target all
</usermanual> */
/* <usermanual>
@keyword DECLARE PROC

@english

The ''DECLARE PROC'' is a way to define and call external procedures written in machine language 
and to insert assembly into the sources. The procedures defined in this way can be called as if they 
were an integral part of the language. Once the procedure has been declared, it will be sufficient 
to invoke it with one of the following syntaxes:

  CALL test

  PROC test

  test[]

as if it were any ugBASIC procedure. If desired, parameters can be added. For each it is obviously 
necessary to indicate how the value will be passed to the function written in machine language. 

The ugBASIC compiler allows you to declare functions and procedures that are “system”. What does 
“system” mean? It means that the machine code resides in a ROM, preloaded at run time and therefore 
already made available to any program that knows how to call it.

However, since ugBASIC makes available all memory space allowed by the hardware, it is possible that
the ROMs have been disabled or otherwise made unreachable. Indicating that you want to call a procedure
or a system function, ugBASIC will take care of re-enabling the ROM before executing the request, 
deactivating it on exit. 

To declare a procedure or function to be system, simply use the ''SYSTEM'' keyword. 

@italian

Il ''DECLARE PROC'' è un modo per definire e chiamare procedure esterne scritte in linguaggio macchina 
e per inserire assembly nei sorgenti. Le procedure così definite possono essere richiamate come se 
fossero parte integrante del linguaggio. Una volta dichiarata la procedura sarà sufficiente invocarla 
con una delle seguenti sintassi:

  CALL test

  PROC test

  test[]

come se fosse una procedura ugBASIC. Se lo si desidera, è possibile aggiungere parametri. Per ognuno 
è ovviamente necessario indicare come verrà passato il valore alla funzione scritta in linguaggio macchina.

Il compilatore ugBASIC consente di dichiarare funzioni e procedure che sono “di sistema”. Cosa significa 
“di sistema”? Vuol dire che il codice macchina risiede in una ROM, precaricata in fase di esecuzione e 
quindi già resa disponibile a qualsiasi programma che sappia chiamarla.

Tuttavia, poiché ugBASIC mette a disposizione tutto lo spazio di memoria consentito dall'hardware, è 
possibile che le ROM siano state disabilitate o comunque rese irraggiungibili. Indicando che si vuole 
chiamare una procedura o una funzione di sistema, ugBASIC si occuperà di riabilitare la ROM prima di 
eseguire la richiesta, disattivandola all'uscita.

Per dichiarare una procedura o una funzione come sistema, utilizzare semplicemente la parola chiave ''SYSTEM''.

@syntax DECLARE [SYSTEM] PROC name AT address [ ( par1 [, par2 [, ... ] ] ) ] [ ON targets ]
@syntax par : name AS type ON register
@syntax par : name AS type ON STACK(width)
@syntax width: BYTE | WORD | DWORD
@syntax targets : name of targets, separated by comma (,)

@example DECLARE SYSTEM PROCEDURE test ON CPC, ZX

@usedInExample extern_example_11.bas

@target all
</usermanual> */

/* <usermanual>
@keyword DECLARE FUNCTION

@english

The ''DECLARE FUNCTION'' is a way to define and call external functions written in machine language 
and to insert assembly into the sources. The functions defined in this way can be called as if they 
were an integral part of the language. Once the function has been declared, it will be sufficient 
to invoke it with one of the following syntaxes:

  x = test[ ]

as if it were any ugBASIC function. If desired, parameters can be added. For each it is obviously 
necessary to indicate how the value will be passed to the function written in machine language. 

The ugBASIC compiler allows you to declare functions and procedures that are “system”. What does 
“system” mean? It means that the machine code resides in a ROM, preloaded at run time and therefore 
already made available to any program that knows how to call it.

However, since ugBASIC makes available all memory space allowed by the hardware, it is possible that
the ROMs have been disabled or otherwise made unreachable. Indicating that you want to call a procedure
or a system function, ugBASIC will take care of re-enabling the ROM before executing the request, 
deactivating it on exit. 

To declare a procedure or function to be system, simply use the ''SYSTEM'' keyword. 

@italian

Il ''DECLARE FUNCTION'' è un modo per definire e chiamare funzioni esterne scritte in linguaggio macchina 
e per inserire assembly nei sorgenti. Le funzioni così definite possono essere richiamate come se 
fossero parte integrante del linguaggio. Una volta dichiarata la funzione sarà sufficiente invocarla 
con una delle seguenti sintassi:

  x = test[ ]

come se fosse una procedura ugBASIC. Se lo si desidera, è possibile aggiungere parametri. Per ognuno 
è ovviamente necessario indicare come verrà passato il valore alla funzione scritta in linguaggio macchina.

Il compilatore ugBASIC consente di dichiarare funzioni e procedure che sono “di sistema”. Cosa significa 
“di sistema”? Vuol dire che il codice macchina risiede in una ROM, precaricata in fase di esecuzione e 
quindi già resa disponibile a qualsiasi programma che sappia chiamarla.

Tuttavia, poiché ugBASIC mette a disposizione tutto lo spazio di memoria consentito dall'hardware, è 
possibile che le ROM siano state disabilitate o comunque rese irraggiungibili. Indicando che si vuole 
chiamare una procedura o una funzione di sistema, ugBASIC si occuperà di riabilitare la ROM prima di 
eseguire la richiesta, disattivandola all'uscita.

Per dichiarare una procedura o una funzione come sistema, utilizzare semplicemente la parola chiave ''SYSTEM''.

@syntax DECLARE [SYSTEM] FUNCTION name AT address [ ( par1 [, par2 [, ... ] ] ) ] RETURN ret [ ON targets ]
@syntax par : name AS type ON register
@syntax par : name AS type ON STACK(width)
@syntax ret : register AS type | STACK(width) AS type
@syntax width: BYTE | WORD | DWORD
@syntax targets : name of targets, separated by comma (,)

@example DECLARE SYSTEM FUNCTION test ON CPC, ZX

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
