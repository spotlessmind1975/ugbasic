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
 * @brief Emit code for <strong>DESERIALIZE</strong>
 * 
 * @param _environment Current calling environment
 * @param _string Data to deserialize
 */
/* <usermanual>
@keyword SERIALIZE

@english

@italian

@syntax = DESERIALIZE( data[, key] TO variable)

@example DIM p(4) AS INTEGER
@example IF DESERIALIZE()"003-a00-22", "SECRET" TO p) THEN: PRINT "OK!": ENDIF

@target all
</usermanual> */

Variable * deserialize( Environment * _environment, char * _data, char * _key, char * _var ) {

    Variable * data = variable_retrieve( _environment, _data );
    Variable * var = variable_retrieve( _environment, _var );
    Variable * key = NULL;

    Variable * result = variable_hex2bin( _environment, data->name, var->name );

    if ( _key ) {
        key = variable_retrieve( _environment, _key );
        cpu_move_8bit( _environment, decrypt( _environment, var->name, _key, var->name )->realName, result->realName );
    } 

    return result;

}
