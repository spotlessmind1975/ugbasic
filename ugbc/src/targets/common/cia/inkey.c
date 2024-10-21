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
@keyword INKEY

@english

The ''INKEY' (or ''INKEY$'') capture a single character typed by the user 
without having to press enter. In other words, the program is "listening" 
to the keyboard and, as soon as a key is pressed, "captures" it and 
stores it in a variable.

Unlike the ''INPUT'' command, which requires the user to press enter after
typing, ''INKEY'' reads the character as soon as it is pressed. If no key 
has been pressed, ''INKEY$'' returns an empty string (""). The captured 
character is stored in a string variable.

It is used to create interactive games where the user can control the 
character or objects by pressing specific keys, to create text menus 
where the user can select an option by pressing a letter or number
or to create programs that respond to external events, such as 
pressing a key to start or stop an action.

The ''INKEY$'' only reads one character at a time. To read a complete 
string, you must use other commands or techniques. The command
does not usually display the pressed character on the screen.

@italian

''INKEY' (o ''INKEY$'') cattura un singolo carattere digitato 
dall'utente senza dover premere Invio. In altre parole, il 
programma "ascolta" la tastiera e, non appena viene premuto un 
tasto, lo "cattura" e lo memorizza in una variabile.

A differenza del comando ''INPUT'', che richiede all'utente di 
premere Invio dopo aver digitato, ''INKEY'' legge il carattere 
non appena viene premuto. Se non è stato premuto alcun tasto, 
''INKEY$'' restituisce una stringa vuota (""). Il carattere 
catturato viene memorizzato in una variabile stringa.

Viene utilizzato per creare giochi interattivi in ​​cui l'utente 
può controllare il personaggio o gli oggetti premendo tasti 
specifici, per creare menu di testo in cui l'utente può 
selezionare un'opzione premendo una lettera o un numero o 
per creare programmi che rispondono a eventi esterni, come 
la pressione di un tasto per avviare o interrompere un'azione.

''INKEY$'' legge solo un carattere alla volta. Per leggere
una stringa completa, è necessario utilizzare altri comandi 
o tecniche. Solitamente il comando non visualizza sullo 
schermo il carattere premuto.

@syntax = INKEY$

@example IF INKEY$ = "A" THEN
@example    PRINT "A has been pressed!"
@example ENDIF

@seeAlso SCANCODE

</usermanual> */

Variable * inkey( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of INKEY$)");
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of temporary string)");
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)");
    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");
    Variable * key = variable_temporary( _environment, VT_CHAR, "(key pressed)");

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, " " );

    variable_store_string(_environment, result->name, resultString );
    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    MAKE_LABEL

    char noKeyPressedLabel[MAX_TEMPORARY_STORAGE]; sprintf(noKeyPressedLabel, "%snokeyPressed", label );
    char finishedLabel[MAX_TEMPORARY_STORAGE]; sprintf(finishedLabel, "%sfinished", label );

    cia_inkey( _environment, key->realName );

    cpu_bveq( _environment, key->realName, noKeyPressedLabel );

    cpu_move_8bit_indirect(_environment, key->realName, address->realName );
    cpu_dsresize_size(_environment, result->realName, 1 );

    cpu_jump( _environment, finishedLabel );

    cpu_label( _environment, noKeyPressedLabel );

    cpu_dsresize_size(_environment, result->realName, 0 );

    cpu_label( _environment, finishedLabel );
    
    return result;

}

#endif
