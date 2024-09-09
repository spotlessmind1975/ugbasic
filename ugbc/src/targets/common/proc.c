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

/**
 * @brief Emit ASM code for <b>PROC</b>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword PROC

@english
This keyword has multiple meaning. If the identifier that follows this
command is not already defined, this can be used to give a label (name)
to a pat of the program. This makes subprograms independent of their 
position in the program and makes it easier for the programmer to keep 
track of things (names are easier to assign to a purpose than line numbers).
The ''PROC'' command is used to define the name of such a subprogram 
(or jump target). The name may consist of several words separated by spaces. 
A leading space is not significant. Other BASIC commands may be in the same
line as ''PROC''.

If, instead, the identifier has been already used for a procedure, then this
command will call the procedure, as the instruction ''CALL''.

@italian
Questa parola chiave ha molteplici significati. Se l'identificatore che segue
questo comando non è già definito, questo può essere utilizzato per dare 
un'etichetta (nome) ad una parte del programma. Ciò rende i sottoprogrammi 
indipendenti dalla loro posizione nel programma e rende più semplice per il
programmatore tenere traccia delle cose (i nomi sono più facili da assegnare
a uno scopo rispetto ai numeri di riga). Il comando ''PROC'' viene utilizzato
per definire il nome di tale sottoprogramma (o destinazione del salto). Il
nome può essere composto da più parole separate da spazi. Uno spazio
principale non è significativo. Altri comandi BASIC possono trovarsi nella 
stessa riga di ''PROC''. Se invece l'identificatore è già stato utilizzato 
per una procedura, allora questo comando chiamerà la procedura, come 
l'istruzione ''CALL''.

@syntax PROC name

@example PROC factorial

@usedInExample tsb_option_call_01.bas

@target all
</usermanual> */
void proc( Environment * _environment, char * _label ) {

    Procedure * procedure = _environment->procedures;
    while ( procedure ) {
        if ( strcmp( procedure->name, _label ) == 0 ) {
            break;
        }
        procedure = procedure->next;
    }

    if ( procedure ) {
        call_procedure( _environment, procedure->name );
    } else {
        begin_procedure( _environment, _label );
    }

}