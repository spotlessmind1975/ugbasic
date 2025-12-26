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
 * @brief Emit code for <strong>ENCRYPT</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword ENCRYPT

@english

The ''ENCRYPT'' command applies a symmetric encryption algorithm to a 
structured variable or memory area, appending a security checksum to 
prevent data corruption or accidental tampering.

When the command is executed, the destination buffer is filled with the 
original data transformed by the encryption operation. A computed value 
a checksum is appended to the end of the buffer, to serve as a trust seal.

Note that the size of the key must be the same as the size of the data.

@italian

Il comando ''ENCRYPT'' applica un algoritmo di crittografia simmetrica a una
variabile strutturata o a un'area di memoria, aggiungendo un checksum di sicurezza per
impedire il danneggiamento dei dati o la manomissione accidentale.

Quando il comando viene eseguito, il buffer di destinazione viene riempito con i
dati originali trasformati dall'operazione di crittografia. Un valore calcolato, 
un checksum, viene aggiunto alla fine del buffer, come sigillo di attendibilità.

Si noti che la dimensione della chiave deve essere uguale alla dimensione dei dati.

@syntax = ENCRYPT( data, key )

@example DIM params(2) AS INTEGER
@example data = ENCRYPT( params, "OKOK")

</usermanual> */
Variable * encrypt( Environment * _environment, char * _data, char * _key ) {

    Variable * data = variable_retrieve( _environment, _data );
    Variable * key = variable_retrieve( _environment, _key );
    Variable * output = variable_temporary( _environment, VT_DSTRING, "(result)" );

    Variable * dataAddress = variable_temporary( _environment, VT_ADDRESS, "(address of data)");
    Variable * dataSize = variable_temporary( _environment, VT_BYTE, "(size of data)");

    Variable * keyAddress = variable_temporary( _environment, VT_ADDRESS, "(address of data)");
    Variable * keySize = variable_temporary( _environment, VT_BYTE, "(size of data)");

    Variable * outputAddress = variable_temporary( _environment, VT_ADDRESS, "(address of output)");

    switch( data->type ) {
        case VT_STRING: {
            cpu_move_8bit( _environment, data->realName, dataSize->realName );
            cpu_addressof_16bit( _environment, data->realName, dataAddress->realName );
            cpu_inc_16bit( _environment, dataAddress->realName );
            break;
        };
        case VT_DSTRING: {
            cpu_dsdescriptor( _environment, data->realName, dataAddress->realName, dataSize->realName );
            break;
        };
        case VT_TYPE:
        case VT_TARRAY:
        case VT_BUFFER: {
            cpu_store_8bit( _environment, dataSize->realName, data->size );
            cpu_addressof_16bit( _environment, data->realName, dataAddress->realName );
            break;
        };
    }

    switch( key->type ) {
        case VT_STRING: {
            cpu_move_8bit( _environment, key->realName, keySize->realName );
            cpu_addressof_16bit( _environment, key->realName, keyAddress->realName );
            cpu_inc_16bit( _environment, keyAddress->realName );
            break;
        };
        case VT_TARRAY:
        case VT_TYPE:
        case VT_BUFFER: {
            cpu_store_8bit( _environment, keySize->realName, key->size );
            cpu_addressof_16bit( _environment, key->realName, keyAddress->realName );
            break;
        };
        case VT_DSTRING: {
            cpu_dsdescriptor( _environment, key->realName, keyAddress->realName, keySize->realName );
            break;
        };
    }

    cpu_inc( _environment, dataSize->realName );
    cpu_dsfree( _environment, output->realName );
    cpu_dsalloc( _environment, dataSize->realName, output->realName );
    cpu_dsdescriptor( _environment, output->realName, outputAddress->realName, NULL );

    cpu_encrypt( _environment, dataAddress->realName, dataSize->realName, keyAddress->realName, keySize->realName, outputAddress->realName );

    return output;

}

