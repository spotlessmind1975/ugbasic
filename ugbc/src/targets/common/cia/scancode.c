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

#include "../../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#if defined(__c128__) || defined(__c64__) || defined(__c64reu__)

extern char DATATYPE_AS_STRING[][16];

/* <usermanual>
@keyword SCANCODE

@english

The ''SCANCODE' (or ''SCAN CODE'') capture a single character typed by the user 
without having to press enter. In other words, the program is "listening" 
to the keyboard and, as soon as a key is pressed, "captures" it and 
stores it in a variable.

Like the  ''INKEY'' command, it  reads the character as soon as it is 
pressed. If no key has been pressed, it returns NONE. The captured 
character is stored in a ''BYTE'' variable, and it is in a target
dependent encoding. You must use the various constants to compare
the value returned with the key wanted.

It is used to create interactive games where the user can control the 
character or objects by pressing specific keys, to create text menus 
where the user can select an option by pressing a letter or number
or to create programs that respond to external events, such as 
pressing a key to start or stop an action.

@italian

''SCANCODE'' (o ''SCAN CODE'') cattura un singolo carattere 
digitato dall'utente senza dover premere Invio. In altre parole, 
il programma "ascolta" la tastiera e, non appena viene premuto un tasto, 
lo "cattura" e lo memorizza in una variabile.

Come il comando ''INKEY'', legge il carattere non appena viene premuto. 
Se non è stato premuto alcun tasto, restituisce NONE. Il carattere
catturato viene memorizzato in una variabile ''BYTE'' ed è in una codifica 
dipendente dal target. È necessario utilizzare le varie costanti per
confrontare il valore restituito con il tasto desiderato.

Viene utilizzato per creare giochi interattivi in ​​cui l'utente può 
controllare il personaggio o gli oggetti premendo tasti specifici, 
per creare menu di testo in cui l'utente può selezionare un'opzione 
premendo una lettera o un numero, o per creare programmi che rispondono 
a eventi esterni, come la pressione di un tasto per avviare o interrompere 
un'azione.

@syntax = SCANCODE

@example IF SCANCODE = KEY A THEN
@example    PRINT "A has been pressed!"
@example ENDIF

@seeAlso SCANCODE

</usermanual> */

Variable * scancode( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of SCANCODE)");

    cia_scancode( _environment, result->realName );

    return result;

}

#endif
