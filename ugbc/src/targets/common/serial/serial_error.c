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
 * @brief Emit code for <strong>SERIAL ERROR</strong>
 * 
 * @param _environment Current calling environment
 */

/* <usermanual>
@keyword SERIAL ERROR

@english

This instruction allows you to know the reason why the last operation failed. 
The numeric code must refer to the possible values for the target considered. 
Note that the value of zero means, in any target, "no error" and is the value 
returned if everything went well.

@italian

Questa istruzione permette di conoscere il motivo per cui l'ultima operazione 
è fallita. Il codice numerico deve essere riferito ai valori possibili per il 
target considerato. Da notare che il valore di zero significa, in qualsiasi 
target, "no error" ed è il valore restituito se tutto è andato per il meglio.

@syntax = SERIAL ERROR

@example IF SERIAL ERROR > 0 THEN: PRINT "Some error occurred: ";SERIAL ERROR : ENDIF

@target atari
@target coco

</usermanual> */

#if ! defined( __coco__ ) && ! defined( __atari__ ) && ! defined( __atarixl__ )

Variable * serial_status( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(data)" );

    variable_store( _environment, result->name, 0 );

    return result;

}

#endif