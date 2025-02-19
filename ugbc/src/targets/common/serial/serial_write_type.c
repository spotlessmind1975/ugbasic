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

#include "../../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>SERIAL WRITE(...)</strong>
 * 
 * @param _environment Current calling environment
 */

/* <usermanual>
@keyword SERIAL WRITE

@english

This command allows you to write one or more bytes, up to a whole string, 
to the serial port. The simplest syntax is to write a variable to the 
serial port: in this case, the command will send the exact number of bytes 
needed to the serial port. To ensure that the actual size is respected, it is 
possible to indicate the type of data to be considered. Finally, in the case of 
data types larger than a byte, it is possible to indicate the endianess with which 
the data will be sent to the serial port.

@italian

Questo comando permette di scrivere uno o più bytes, fino a una stringa intera, 
sulla porta seriale. La sintassi più semplice è quella che permette di scrivere 
una variabile verso la porta seriale: in tal caso, il comando invierà l'esatto 
numero di byte necessari verso la porta seriale. Per garantire il rispetto dela 
dimensione effettiva, è possibile indicare il tipo di dati da considerare. 
Infine, nel caso di tipi di dato di dimensioni superiori al byte, è possibile 
indicare l'endianess con cui i dati saranno inviati sulla porta seriale.

@syntax = SERIAL WRITE( variable [AS type] )
@syntax SERIAL WRITE variable [AS type]

@example result = SERIAL WRITE( 42 AS BYTE )

</usermanual> */

#if ! defined( __coco__ ) && ! defined( __atari__ )

Variable * serial_write_type( Environment * _environment, char * _data, VariableType _type ) {

    Variable * result = variable_temporary( _environment, _type, "(status)" );

    variable_store( _environment, result->name, 0 );

    return result;

}

#endif
