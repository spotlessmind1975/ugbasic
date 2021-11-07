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

@syntax = PARAM([name])
@syntax = PARAM$([name])

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
