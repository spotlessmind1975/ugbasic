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
to a part of the program. This makes subprograms independent of their 
position in the program and makes it easier for the programmer to keep 
track of things (names are easier to assign to a purpose than line numbers).

The ''PROC'' command is used to define the name of such a subprogram 
(or jump target). Following the convention in other BASICs of the time, 
such as Simon's BASIC or Tuned Simon's BASIC, the procedure name can also 
contain spaces. In this case, the trailing space will not be considered as
part of the name.

If, instead, the identifier has been already used for a procedure, then this
command will call the procedure, as the instruction ''CALL''.

@italian

Questa parola chiave ha molteplici significati. Se l'identificatore che 
segue questo comando non è già definito, può essere utilizzato per assegnare 
un'etichetta (nome) a una parte del programma. Ciò rende i sottoprogrammi 
indipendenti dalla loro posizione nel programma e semplifica per il programmatore 
il monitoraggio delle cose (è più facile assegnare uno scopo ai nomi rispetto 
ai numeri di riga).

Il comando ''PROC'' viene utilizzato per definire il nome di tale sottoprogramma 
(o destinazione di salto). Seguendo la convenzione di altri BASIC dell'epoca, 
come Simon BASIC o Tuned Simon BASIC, il nome della procedura può anche contenere 
spazi. In questo caso, lo spazio finale non verrà considerato parte del nome.

Se, tuttavia, l'identificatore è già stato utilizzato per una procedura, questo 
comando chiamerà la procedura, come l'istruzione ''CALL''.

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