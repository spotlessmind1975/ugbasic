/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for function <strong>= VARPTR( ... )</strong>
 * 
 * @param _environment Current calling environment
 * @param _identifier Identifier to explore
 * @return Variable* Address of identifier
 */
/* <usermanual>
@keyword VARPTR

@english
This function allows you to retrieve the memory address
where a variable is found.

@italian
Questa funzione permette di recuperare l'indirizzo di memoria 
dove si trova una variabile.

@syntax = VARPTR([var])

@example address = VARPTR(x)

@target all
</usermanual> */
Variable * varptr( Environment * _environment, char * _name ) {

    Variable * name = variable_retrieve( _environment, _name );
    Variable * result = variable_temporary( _environment, VT_ADDRESS, "(address)" );

    cpu_addressof_16bit( _environment, name->realName, result->realName );
    
    return result;

}

