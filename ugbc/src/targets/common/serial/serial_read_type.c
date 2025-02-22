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
 * @brief Emit code for <strong>SERIAL READ datatype</strong>
 * 
 * @param _environment Current calling environment
 */

/* <usermanual>
@keyword SERIAL READ

@english

This command allows you to read one or more bytes, up to a whole string, 
from the serial port. The simplest syntax is the one that allows you to 
retrieve a string from the serial port, indicating the number of characters 
(''chars'') to read. It is possible to omit the size (in bytes) to read 
and instead directly indicate the ''type''. In this case, a piece of data 
will be read from the serial port as long as the indicated type. In this last 
use case, the programmer must pay particular attention to the order of the 
bytes, where the data exceeds the size of one byte. In other words, the data 
is read with the endianess prevailing on the target computer. To change this 
behavior and ensure that the endianess is the same, regardless of the computer 
used, it is necessary to use the ''BIG ENDIAN'' or ''LITTLE ENDIAN'' option, 
to indicate the preferred endianess.

@italian

Questo comando permette di leggere uno o più bytes, fino a una stringa intera, 
dalla porta seriale. La sintassi più semplice è quella che permette di recuperare una
stringa dalla porta seriale, indicando il numero di caratteri (''chars'') da leggere. 
E' possibile omettere la dimensione (in bytes) da leggere e indicare, invece, 
direttamente, il tipo (''type''). In questo caso, sarà letto un dato dalla porta 
seriale lungo tnato quanto il tipo indicato. In quest'ultimo caso d'uso, 
particolare attenzione deve essere posta dal programmatore sull'ordine dei byte, 
laddove il dato superi la dimensione di un byte. In altri termini, il dato viene 
letto con la endianess prevalente sul computer target. Per cambiare questo 
comportamento e garantire che l'endianess sia la stessa, a prescindere dal 
computer utilizzato, è necessario usare l'opzione ''BIG ENDIAN'' o ''LITTLE ENDIAN'', 
per indicare l'endianess di preferenzaa.

@syntax = SERIAL READ [()] AS datatype [BIG ENDIAN|LITTLE ENDIAN]
@syntax = SERIAL READ (chars)

@example result = SERIAL READ AS BYTE

</usermanual> */

#if ! defined( __coco__ ) && ! defined( __atari__ ) && ! defined( __atarixl__ )

Variable * serial_read_type( Environment * _environment, VariableType _datatype, int _big_endian ) {

    Variable * result = variable_temporary( _environment, _datatype, "(data)" );

    variable_store( _environment, result->name, 0 );

    return result;

}

#endif