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

/* <usermanual>
@keyword PING

@english

The ''PING'' function lets you know if there is a DOJO server available or 
running at the time you call it.

@italian

La funzione PING consente di sapere se vi è un server DOJO disponibile o 
in funzione, al momento in cui viene richiamato.

@syntax = PING()

@example IF PING( ) THEN
@example    PRINT "DOJO is available"
@example ENDIF

@alias DOJO LOGIN

@target c64
</usermanual> */

/* <usermanual>
@keyword DOJO PING

@english

@italian

@syntax = DOJO PING()

@example IF DOJO PING( ) THEN
@example    PRINT "DOJO is available"
@example ENDIF

@alias PING

@target c64
</usermanual> */

Variable * dojo_ping( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result)" );

    c64_dojo_ping( _environment, result->realName );

    return result;

}
