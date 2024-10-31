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
 * @brief Emit ASM code for <b>PEEK(...)</b>
 * 
 * This function outputs valid code to retrieve a byte from memory, 
 * and returns it as a temporary variable. This version is valid 
 * for use where the location to be read is an expression
 * 
 * @param _environment Current calling environment
 * @param _location Expression with the location to read from.
 * @return Variable* Temporary variable with the content of the location (1 byte).
 */
/* <usermanual>
@keyword PEEK

@english

''PEEK'' is a command that allows you to "peek" into 
your computer's memory. In practice, it allows you to read the value stored 
in a specific memory cell.

When using ''PEEK'', you give the command the memory ''address'' you want to know 
the contents of. The command will then return the numeric value (a byte) 
stored at that address.

''PEEK'' allows you to read data directly from memory, without going 
through the normal program variables. On some systems, it is possible to 
read the state of input/output ports using ''PEEK''. With caution, 
''PEEK'' can be used to access memory reserved for the operating system,
or the ugBASIC program. Although it is generally discouraged, as it can 
cause system instability or crashes, it can also speed up some operations.

The use of ''PEEK'' is highly dependent on the computer architecture and 
operating system. Valid memory addresses and the meaning of the values
read may vary from one system to another. Improper use of ''PEEK'' can cause 
damage to your system or corrupt data. It is important to have a thorough 
understanding of how your computer works before using this command.

@italian

''PEEK'' è un comando che consente di "sbirciare" 
nella memoria del computer. In pratica, consente di leggere il valore 
memorizzato in una specifica cella di memoria.

Quando si utilizza ''PEEK'', si fornisce al comando l'''indirizzo'' di memoria 
di cui si desidera conoscere il contenuto. Il comando restituirà quindi il 
valore numerico (un byte) memorizzato in quell'indirizzo.

''PEEK'' consente di leggere i dati direttamente dalla memoria, senza passare 
attraverso le normali variabili del programma. Su alcuni sistemi, è possibile 
leggere lo stato delle porte di input/output utilizzando ''PEEK''. Con cautela, 
''PEEK'' può essere utilizzato per accedere alla memoria riservata al sistema 
operativo o al programma ugBASIC. Sebbene sia generalmente sconsigliato, 
in quanto può causare instabilità o crash del sistema, può anche velocizzare 
alcune operazioni.

L'utilizzo di ''PEEK'' dipende fortemente dall'architettura del computer e 
dal sistema operativo. Gli indirizzi di memoria validi e il significato dei 
valori letti possono variare da un sistema all'altro. L'uso improprio di 
''PEEK'' può causare danni al sistema o dati corrotti. È importante avere 
una conoscenza approfondita del funzionamento del computer prima di utilizzare 
questo comando.

@syntax = PEEK( address )

@example x = PEEK(1024)

@seeAlso PEEKW
@seeAlso PEEKD
@seeAlso D!PEEKW

</usermanual> */
Variable * peek_var( Environment * _environment, char * _location ) {

    Variable * location = variable_retrieve_or_define( _environment, _location, VT_ADDRESS, 0 );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)" );

    cpu_peek( _environment, location->realName, result->realName );

    return result;

}

/* <usermanual>
@keyword PEEKW

@english

''PEEKW'' is a command that allows you to "peek" into 
your computer's memory. In practice, it allows you to read the value stored 
in a specific memory cell.

When using ''PEEKW'', you give the command the memory ''address'' you want to know 
the contents of. The command will then return the numeric value (a word) 
stored at that address.

''PEEKW'' allows you to read data directly from memory, without going 
through the normal program variables. On some systems, it is possible to 
read the state of input/output ports using ''PEEKW''. With caution, 
''PEEKW'' can be used to access memory reserved for the operating system,
or the ugBASIC program. Although it is generally discouraged, as it can 
cause system instability or crashes, it can also speed up some operations.

The use of ''PEEKW'' is highly dependent on the computer architecture and 
operating system. Valid memory addresses and the meaning of the values
read may vary from one system to another. Improper use of ''PEEKW'' can cause 
damage to your system or corrupt data. It is important to have a thorough 
understanding of how your computer works before using this command.

@italian

''PEEKW'' è un comando che consente di "sbirciare" 
nella memoria del computer. In pratica, consente di leggere il valore 
memorizzato in una specifica cella di memoria.

Quando si utilizza ''PEEKW'', si fornisce al comando l'''address'' di memoria 
di cui si desidera conoscere il contenuto. Il comando restituirà quindi il 
valore numerico (un byte) memorizzato in quell'indirizzo.

''PEEKW'' consente di leggere i dati direttamente dalla memoria, senza passare 
attraverso le normali variabili del programma. Su alcuni sistemi, è possibile 
leggere lo stato delle porte di input/output utilizzando ''PEEKW''. Con cautela, 
''PEEKW'' può essere utilizzato per accedere alla memoria riservata al sistema 
operativo o al programma ugBASIC. Sebbene sia generalmente sconsigliato, 
in quanto può causare instabilità o crash del sistema, può anche velocizzare 
alcune operazioni.

L'utilizzo di ''PEEKW'' dipende fortemente dall'architettura del computer e 
dal sistema operativo. Gli indirizzi di memoria validi e il significato dei 
valori letti possono variare da un sistema all'altro. L'uso improprio di 
''PEEKW'' può causare danni al sistema o dati corrotti. È importante avere 
una conoscenza approfondita del funzionamento del computer prima di utilizzare 
questo comando.

@syntax = PEEKW( address )

@example x = PEEKW(1024)

@seeAlso PEEK
@seeAlso PEEKD
@alias D!PEEK

</usermanual> */

Variable * peekw_var( Environment * _environment, char * _location ) {

    Variable * location = variable_retrieve_or_define( _environment, _location, VT_ADDRESS, 0 );

    Variable * result = variable_temporary( _environment, VT_WORD, "(result)" );

    cpu_peekw( _environment, location->realName, result->realName );

    return result;

}

/* <usermanual>
@keyword PEEKD

@english

''PEEKD'' is a command that allows you to "peek" into 
your computer's memory. In practice, it allows you to read the value stored 
in a specific memory cell.

When using ''PEEKD'', you give the command the memory ''address'' you want to know 
the contents of. The command will then return the numeric value (a double word) 
stored at that address.

''PEEKD'' allows you to read data directly from memory, without going 
through the normal program variables. On some systems, it is possible to 
read the state of input/output ports using ''PEEKD''. With caution, 
''PEEKD'' can be used to access memory reserved for the operating system,
or the ugBASIC program. Although it is generally discouraged, as it can 
cause system instability or crashes, it can also speed up some operations.

The use of ''PEEKD'' is highly dependent on the computer architecture and 
operating system. Valid memory addresses and the meaning of the values
read may vary from one system to another. Improper use of ''PEEKD'' can cause 
damage to your system or corrupt data. It is important to have a thorough 
understanding of how your computer works before using this command.

@italian

''PEEKD'' è un comando che consente di "sbirciare" 
nella memoria del computer. In pratica, consente di leggere il valore 
memorizzato in una specifica cella di memoria.

Quando si utilizza ''PEEKD'', si fornisce al comando l'''address'' di memoria 
di cui si desidera conoscere il contenuto. Il comando restituirà quindi il 
valore numerico (un byte) memorizzato in quell'indirizzo.

''PEEKD'' consente di leggere i dati direttamente dalla memoria, senza passare 
attraverso le normali variabili del programma. Su alcuni sistemi, è possibile 
leggere lo stato delle porte di input/output utilizzando ''PEEKD''. Con cautela, 
''PEEKD'' può essere utilizzato per accedere alla memoria riservata al sistema 
operativo o al programma ugBASIC. Sebbene sia generalmente sconsigliato, 
in quanto può causare instabilità o crash del sistema, può anche velocizzare 
alcune operazioni.

L'utilizzo di ''PEEKD'' dipende fortemente dall'architettura del computer e 
dal sistema operativo. Gli indirizzi di memoria validi e il significato dei 
valori letti possono variare da un sistema all'altro. L'uso improprio di 
''PEEKD'' può causare danni al sistema o dati corrotti. È importante avere 
una conoscenza approfondita del funzionamento del computer prima di utilizzare 
questo comando.

@syntax = PEEKD( address )

@example x = PEEKD(1024)

@seeAlso PEEK
@seeAlso PEEKW

</usermanual> */
Variable * peekd_var( Environment * _environment, char * _location ) {

    Variable * location = variable_retrieve_or_define( _environment, _location, VT_ADDRESS, 0 );

    Variable * result = variable_temporary( _environment, VT_DWORD, "(result)" );

    cpu_peekd( _environment, location->realName, result->realName );

    return result;

}
