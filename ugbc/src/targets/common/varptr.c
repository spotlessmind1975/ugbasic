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
 * @brief Emit code for function <strong>= VARPTR( ... )</strong>
 * 
 * @param _environment Current calling environment
 * @param _identifier Identifier to explore
 * @return Variable* Address of identifier
 */
/* <usermanual>
@keyword VARPTR

@english

The ''VARPTR'' command (short for "variable pointer") is a pretty advanced statement 
that lets you get the memory address of a variable. Essentially, it tells you "where" 
in memory the value of a specific variable is stored.

In some advanced cases, you may want to directly manipulate the contents of memory. 
This is useful for things like creating custom data structures or optimizing the 
speed of execution of certain operations.

Directly manipulating memory can lead to program errors that are difficult to 
detect and correct. If you are not completely sure what you are doing, it is
 best to avoid using ''VARPTR''.

@italian

Il comando ''VARPTR'' (abbreviazione di "puntatore di variabile") è un'istruzione piuttosto
 avanzata che consente di ottenere l'indirizzo di memoria di una variabile. In 
 sostanza, indica "dove" nella memoria è archiviato il valore di una variabile specifica.

In alcuni casi avanzati, potresti voler manipolare direttamente il contenuto della memoria.
Ciò è utile per cose come la creazione di strutture dati personalizzate o l'ottimizzazione 
della velocità di esecuzione di determinate operazioni.

La manipolazione diretta della memoria può portare a errori di programma difficili da 
rilevare e correggere. Se non sei completamente sicuro di cosa stai facendo, è meglio 
evitare di usare ''VARPTR''.

@syntax = VARPTR(var)

@example address = VARPTR(x)

</usermanual> */
Variable * varptr( Environment * _environment, char * _name ) {

    Variable * name = variable_retrieve( _environment, _name );
    Variable * result = variable_temporary( _environment, VT_ADDRESS, "(address)" );

    cpu_addressof_16bit( _environment, name->realName, result->realName );
    
    return result;

}

