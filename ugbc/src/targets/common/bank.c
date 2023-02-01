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

extern char DATATYPE_AS_STRING[][16];
extern char BANK_TYPE_AS_STRING[][16];

/**
 * @brief Implementation for <b>BANK xxx AT [WITH yyy]</b>
 * 
 * This method deals with populating the data structures for the definition of
 * a "bank" of memory. The memory banks are defined and separate areas, 
 * identified by a name (optionally given) and a starting address and 
 * populated (optionally) with data coming from an external file. This 
 * definition occurs when the program presents a <b>BANK</b> instruction. 
 * Banks are characterized by a "type", which represents the nature of the 
 * data contained therein. The types surveyed are the following:
 * 
 * - `BT_CODE` (<b>CODE</b>) - executable code
 * - `BT_VARIABLES` (<b>VARIABLES</b>) - program's variables
 * - `BT_TEMPORARY` (<b>TEMPORARY</b>) - temporary variables
 * - `BT_DATA` (<b>DATA</b>) - untyped data (graphics, sound, ...)
 * 
 * There can be only one definition of a bank with a specific name. 
 * Any duplicate definitions will be ignored.
 * 
 * @param _environment Current calling environment
 * @param _name Name of the bank (NULL if automatic)
 * @param _type 
 * @param _address 
 * @param _filename 
 * @return Bank* 
 */
/* <usermanual>
@keyword BANK

@english
Define a bank of memory named [identifier], starting from [address] 
of type [bankType]. Optionally, fill the bank of memory with static 
data coming from [filename].

Available [bankType]:

    * ''CODE'' executable code (binary)
    * ''VARIABLES'' program's variables
    * ''TEMPORARY'' temporary variables
    * ''DATA'' unspecified data

If [identifier] is missing, the bank will have an unique name.
If [bankType] is missing, the default type is DATA.
If [filename] is missing, the default is a simply memory reservation.

@italian
Definisce un banco di memoria di nome [identifier], che inizia
all'indirizzo [address] e del tipo [bankType]. In opzione, è possibile
riempire tale banco con dei dati statici che provengano dal file
[filename].

I tipi di banco sono:

    * ''CODE'' codice eseguibile (binario)
    * ''VARIABLES'' variabili del programma
    * ''TEMPORARY'' variabili temporanee
    * ''DATA'' dati non meglio specificati

Se [identifier] manca, al banco sarà assegnato un nome univoco.
Se non viene indicato il [bankType], quello di default è DATA.
Se manca il [filename] allora il banco non sarà preriempito.

@syntax BANK { [identifier] } AT # [address] { AS [bankType]} { WITH [filename] }
@syntax BANK { [bankType] } { [identifier] } AT # [address] { WITH [filename] }

@example BANK VARIABLES AT $c000

@seeAlso VAR

@target all

 </usermanual> */
Bank * bank_define( Environment * _environment, char * _name, BankType _type, int _address, char * _filename ) {

    Bank * bank = NULL;
    if ( _name != NULL ) {
        bank = bank_find( _environment->banks[_type], _name );
    } else {
        char temporaryName[MAX_TEMPORARY_STORAGE];
        sprintf(temporaryName, "bank%4.4d", UNIQUE_ID );
        _name = strdup( temporaryName );
    }
    if ( bank ) {
        // if ( _filename ) {
        //     outline4("; BANK %s %s AT $%4.4x WITH \"%s\" (duplicate)", BANK_TYPE_AS_STRING[_type], _name, _address, _filename);
        // } else {
        //     outline3("; BANK %s %s AT $%4.4x (duplicate)", BANK_TYPE_AS_STRING[_type], _name, _address);
        // }
    } else {
        if ( _filename ) {
            
        } else {
            
        }
        bank = malloc( sizeof( Bank ) );
        memset( bank, 0, sizeof( Bank ) );
        bank->name = strdup( _name );
        bank->type = _type;
        bank->filename = _filename;
        bank->address = _address;
        // if ( bank->type == BT_STRINGS ) {
        //     variable_store( _environment, "stringsAddress", bank->address );
        // }
        bank->next = _environment->banks[_type]; 
        _environment->banks[_type] = bank;
    }
    return bank;
}