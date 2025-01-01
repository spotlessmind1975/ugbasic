/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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

/* <usermanual>
@keyword CGOTO

@english

Calculate the number of the line to which the program execution must pass. 
Allows you to jump to a variable program line number, determined by the result 
of a calculation. ''CGOTO'' is a command that replaces long jump tables behind 
the BASIC command ''ON''. 

Instead of specifying the jump targets as with ''ON''
and then calling them by specifying the location number of the desired target, 
the desired target line can be targeted immediately by calculation after 
''CGOTO'' without much typing. 

The use of ''CGOTO'' requires that the lines 
are arranged in such a way when programming that these lines remain accessible 
for the algorithm ''expression'' behind ''CGOTO''.

@italian

Calcola il numero della riga a cui deve passare l'esecuzione del programma. 
Consente di saltare a un numero di riga di programma variabile, determinato 
dal risultato di un calcolo. 

''CGOTO'' è un comando che sostituisce le tabelle 
di salto in lungo dietro il comando BASIC ''ON''. Invece di specificare i target 
di salto come con ''ON'' e quindi chiamarli specificando il numero di posizione 
del target desiderato, la riga del target desiderato può essere mirata immediatamente 
tramite calcolo dopo ''CGOTO'' senza molta digitazione. 

L'uso di ''CGOTO''
richiede che le righe siano disposte in modo tale durante la programmazione che queste
righe rimangano accessibili per l'algoritmo ''espressione'' dietro ''CGOTO''.

@syntax CGOTO expression

@example CGOTO 10*i+100

@usedInExample tsb_cgoto_01.bas

@target all
@verified
</usermanual> */
void cgoto( Environment * _environment, char * _expression ) {

    MAKE_LABEL

    Variable * expression = variable_retrieve_or_define( _environment, _expression, VT_WORD, 0 );
    Variable * address = variable_temporary( _environment, VT_WORD, 0 );

    _environment->hasCGoto = 1;

    cpu_address_table_call( _environment, "CGOTOADDRESS", expression->realName, address->realName );

    cpu_compare_and_branch_16bit_const( _environment, address->realName, 0, label, 1 );

    cpu_jump_indirect( _environment, address->realName );

    cpu_label( _environment, label );

}