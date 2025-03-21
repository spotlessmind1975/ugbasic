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

/**
 * @brief Emit code for <strong>STORAGE ... ENDSTORAGE</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the storage
 */
/* <usermanual>
@keyword BEGIN TYPE...END TYPE

@english

The ''BEGIN TYPE..END TYPE'' command lets you define custom data types, 
also known as "records" or "structures." These data types let you group 
variables of different types under a single name, making it easier to 
manage complex data.

The ''TYPE'' command lets you create data models that can contain 
variables of different types. It lets you organize data in a logical 
and structured way, improving the readability and maintainability of 
your code. Once you've defined a data type with ''TYPE'', you can access 
the individual members (variables) of the structure using the variable 
name and the member name separated by a period.

The ''TYPE'' command is especially useful when you work with large 
amounts of data or when you want to create complex data structures. 
It allows you to group related information and manage it efficiently.

@italian
Il comando ''BEGIN TYPE..END TYPE'' consente di definire tipi di dati personalizzati,
noti anche come "record" o "strutture". Questi tipi di dati consentono di raggruppare
variabili di tipi diversi sotto un unico nome, semplificando
la gestione di dati complessi.

Il comando ''TYPE'' consente di creare modelli di dati che possono contenere
variabili di tipi diversi. Consente di organizzare i dati in modo logico
e strutturato, migliorando la leggibilità e la manutenibilità del
codice. Dopo aver definito un tipo di dati con ''TYPE'', è possibile accedere
ai singoli membri (variabili) della struttura utilizzando il nome della variabile e il nome del membro separati da un punto.

Il comando ''TYPE'' è particolarmente utile quando si lavora con grandi
quantità di dati o quando si desidera creare strutture di dati complesse.
Consente di raggruppare informazioni correlate e gestirle in modo efficiente.

@syntax BEGIN TYPE name 
@syntax    variable AS datatype
@syntax END TYPE

@example BEGIN TYPE person
@example   age AS INT
@example   height AS BYTE
@example END TYPE

@alias TYPE...ENDTYPE
@alias BEGIN TYPE...ENDTYPE

</usermanual> */
/* <usermanual>
@keyword TYPE...END TYPE

@english

@italian

@syntax TYPE name 
@syntax    variable AS datatype
@syntax END TYPE

@example TYPE person
@example   age AS INT
@example   height AS BYTE
@example END TYPE

@alias BEGIN TYPE...END TYPE

</usermanual> */

void begin_type( Environment * _environment, char * _name ) {

    if ( _environment->currentType ) {
        CRITICAL_TYPE_NESTED_UNSUPPORTED(_name);
    }

    if ( type_find( _environment->types, _name ) ) {
        CRITICAL_TYPE_ALREADY_DEFINED(_name);
    }

    Type * type = malloc( sizeof( Type ) );
    memset( type, 0, sizeof ( Type ) );
    type->name = strdup( _name );

    _environment->currentType = type;

}
