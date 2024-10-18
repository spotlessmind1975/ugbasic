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
@keyword ASCII CODE

@english

The ''ASCII CODE'' command capture a keystroke "on the Fly",
and return the equivalent ASCII code instead of internal ''SCANCODE''.
This command is a fundamental tool for making programs more interactive. 
It allows you to read a character typed by the user without having to press 
the enter key.

Unlike other input commands, ''ASCII CODE'' does not require the user to press
Enter to send the character, while the typed character is not displayed on 
the screen. It return directly the ASCII code of the typed character, or
a special value (0) if no key was pressed. It is equivalent to write
''ASC( INKEY$() )'', but faster, since no string is created. Note that
the reading speed could vary significantly depending on the target.

This command allows you to create simple games in which the user must 
press specific keys to control a character or object. It can be used 
to create more responsive user interfaces, in which the user can interact
with the program in real time or that respond to certain key combinations, 
automating certain operations.

Due to the limitations of 7-bit ASCII encoding, ''ASCII CODE'' could only 
read characters in the standard ASCII set. Use ''SCANCODE'' if you need
to be able to detect any key.

@italian

Il comando ''ASCII CODE'' cattura una pressione di tasto "al volo" e
restituisce il codice ASCII equivalente invece dello ''SCANCODE'' interno.
Questo comando è uno strumento fondamentale per rendere i programmi più interattivi.
Consente di leggere un carattere digitato dall'utente senza dover premere il 
tasto Invio.

A differenza di altri comandi di input, ''ASCII CODE'' non richiede all'utente 
di premere Invio per inviare il carattere, mentre il carattere digitato non 
viene visualizzato sullo schermo. Restituisce direttamente il codice ASCII 
del carattere digitato o un valore speciale (0) se non è stato premuto alcun 
tasto. È equivalente alla scrittura di ''ASC(INKEY$())'', ma più veloce, 
poiché non viene creata alcuna stringa. Nota che la velocità di lettura 
potrebbe variare in modo significativo a seconda del target.

Questo comando consente di creare semplici giochi in cui l'utente 
deve premere tasti specifici per controllare un personaggio o 
un oggetto. Può essere utilizzato per creare interfacce utente 
più reattive, in cui l'utente può interagire con il programma in 
tempo reale o che rispondono a determinate combinazioni di tasti,
automatizzando determinate operazioni.

A causa delle limitazioni della codifica ASCII a 7 bit, ''ASCII CODE'' 
poteva leggere solo caratteri nel set ASCII standard. Utilizzare 
''SCANCODE'' se è necessario essere in grado di rilevare qualsiasi 
tasto.

@syntax = ASCII CODE

@example IF ASCII CODE = 42 THEN
@example    PRINT "ASTERISK has been pressed!"
@example ENDIF

@seeAlso SCANCODE
@alias ASCIICODE

</usermanual> */

/* <usermanual>
@keyword ASCIICODE

@english

@italian

@syntax = ASCIICODE

@example IF ASCIICODE = 42 THEN
@example    PRINT "ASTERISK has been pressed!"
@example ENDIF

@seeAlso SCANCODE
@alias ASCII CODE

</usermanual> */

Variable * asciicode( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of ASCIICODE)");

    cia_asciicode( _environment, result->realName );

    return result;

}

#endif