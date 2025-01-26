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
 * @brief Emit code for <strong>SERIAL WRITE(...)</strong>
 * 
 * @param _environment Current calling environment
 */

/* <usermanual>
@keyword SERIAL WRITE

@english

This instruction allows you to write one or more bytes to the standard serial 
connection. The instruction will return ''FALSE'' if any error occurs.

@italian

Questa istruzione consente di scrivere uno o più byte sulla connessione 
seriale standard. L'istruzione restituirà ''FALSE'' se si verifica un errore.

@syntax = SERIAL WRITE( data )

@example result = SERIAL WRITE( "test" )

</usermanual> */

#if ! defined( __coco__ )

Variable * serial_write( Environment * _environment, char * _data ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(status)" );

    return result;

}

#endif
