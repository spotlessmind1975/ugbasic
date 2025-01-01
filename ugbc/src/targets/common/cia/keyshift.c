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

#if defined(__c128__) || defined(__c64__) || defined(__c64reu__)

extern char DATATYPE_AS_STRING[][16];

/* <usermanual>
@keyword KEY SHIFT

@english

The ''KEY SHIFT'' function returns the current status of the various 
control keys. These keys such as ''SHIFT'' or ''ALT'' cannot be 
detected using the standard ''INKEY$'' or ''SCANCODE'' functions. 
But you can easily test for any combination of control keys with 
just a single call to the ''KEY SHIFT'' function. The result is a 
bit map with the following meaning:

'''0 -LEFT SHIFT'''
'''1 - RIGHT SHIFT'''
'''2 - CAPS LOCK'''
'''3 - CTRL'''
'''4 - LEFT ALT'''
'''5 - RIGHT ALT''

If a bit is set to a one, then the associated button has been held 
down by the user.

Note that not all computers support control keys, nor is it possible 
to have individual pressure detection. Depending on the target, 
some of the bits may not be available, or only under certain 
conditions.

@italian

La funzione ''KEY SHIFT'' restituisce lo stato corrente dei vari 
tasti di controllo. Questi tasti come ''SHIFT'' o ''ALT'' non 
possono essere rilevati utilizzando le funzioni standard 
''INKEY$'' o ''SCANCODE''. Ma puoi facilmente testare qualsiasi 
combinazione di tasti di controllo con una singola chiamata alla 
funzione ''KEY SHIFT''. Il risultato è una bitmap con il seguente 
significato:

'''0 - LEFT SHIFT'''
'''1 - RIGHT SHIFT'''
'''2 - CAPS LOCK'''
'''3 - CTRL'''
'''4 - LEFT ALT'''
'''5 - RIGHT ALT''

Se un bit è impostato su uno, il pulsante associato è stato tenuto 
premuto dall'utente. Nota che non tutti i computer supportano i tasti 
di controllo, né è possibile avere il rilevamento della pressione di 
un singolo tasto. A seconda del target, alcuni bit potrebbero non 
essere disponibili o esserlo solo in determinate condizioni.

@syntax = KEY SHIFT

@example CENTER "Press some control keys"
@example DO
@example    LOCATE 14, 4
@example    PRINT BIN$(KEY SHIFT, 8)
@example LOOP

@alias KEYSHIFT

</usermanual> */

/* <usermanual>
@keyword KEYSHIFT

@english

@italian

@syntax = KEYSHIFT

@example CENTER "Press some control keys"
@example DO
@example    LOCATE 14, 4
@example    PRINT BIN$(KEYSHIFT, 8)
@example LOOP

@alias KEY SHIFT

</usermanual> */

Variable * keyshift( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of KEYSHIFT)");

    cia_keyshift( _environment, result->realName );

    return result;

}

#endif
