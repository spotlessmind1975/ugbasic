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
 * @brief Emit code for <strong>SERIALIZE</strong>
 * 
 * @param _environment Current calling environment
 * @param _string Data to serialize
 */
/* <usermanual>
@keyword SERIALIZE

@english

The ''SERIALIZE'' statement converts the binary contents of a variable (numeric, string, 
or array) into a formatted text sequence. The result is an easily readable and 
transcriptable string, where each byte is separated by a hyphen, making it ideal for 
"save codes" or dynamically generated activation keys. If a ''key'' is provided, the output
data will be encrypted before processing.

@italian

L'istruzione ''SERIALIZE'' converte il contenuto binario di una variabile (numerica, stringa
o array) in una sequenza di testo formattata. Il risultato è una stringa facilmente leggibile e
trascrivibile, in cui ogni byte è separato da un trattino, rendendola ideale per
"codici di salvataggio" o chiavi di attivazione generate dinamicamente. Se viene fornita una ''key'', 
i dati di output verranno crittografati prima dell'elaborazione.

@syntax = SERIALIZE( data[, key] )

@example DIM p(4) AS INTEGER
@example PRINT SERIALIZE( p, "SECRET" )

@target all
</usermanual> */

Variable * serialize( Environment * _environment, char * _data, char * _key ) {

    Variable * encryptedData = NULL;
    Variable * key = NULL;

    if ( _key ) {
        key = variable_retrieve( _environment, _key );
        encryptedData = encrypt( _environment, _data, _key );
    } else {
        encryptedData = variable_retrieve( _environment, _data );
    }

    Variable * result = variable_hex( _environment, encryptedData->name, 1 );
    
    return result;

}
