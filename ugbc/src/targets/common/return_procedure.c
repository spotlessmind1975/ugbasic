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
