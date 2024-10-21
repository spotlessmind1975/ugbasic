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
@keyword INPUT (function)

@english

The ''INPUT'' command allows you to ask the user to enter data, such as 
numbers or text, while your program is running. When your program 
encounters an ''INPUT'' statement, it stops executing and displays 
a prompt (usually the name of the variable) that invites the user 
to enter a value. The user types the value and presses Enter. 
The entered value is then stored in the specified variable.

Make sure the variable type matches the type of data you want 
to capture (e.g. a numeric variable for a number, a string 
variable for text). The message is optional but highly 
recommended to make it clear to the user what to enter.
After entering the value, the user must always press Enter to confirm.

@italian

Il comando ''INPUT'' consente di chiedere all'utente di immettere dati, 
come numeri o testo, mentre il programma è in esecuzione. Quando il 
programma incontra un'istruzione ''INPUT'', interrompe l'esecuzione e
visualizza un prompt (solitamente il nome della variabile) che invita 
l'utente a immettere un valore. L'utente digita il valore e preme Invio.
Il valore immesso viene quindi memorizzato nella variabile specificata.

Assicurati che il tipo di variabile corrisponda al tipo di dati che 
desideri acquisire (ad esempio una variabile numerica per un numero, 
una variabile stringa per il testo). Il messaggio è facoltativo ma 
altamente consigliato per chiarire all'utente cosa immettere.
Dopo aver immesso il valore, l'utente deve sempre premere 
invio per confermare.

@syntax INPUT [prompt];v1[;v2[;...]
@syntax INPUT [prompt];v1[,v2[,...]
@syntax INPUT [prompt],v1[;v2[;...]
@syntax INPUT [prompt],v1[,v2[,...]

@example INPUT "Type a string ", a$
@example PRINT "The string was "; a$

@seeAlso INPUT (function)

</usermanual> */

/* <usermanual>
@keyword LINE INPUT

@english

The ''LINE INPUT'' command takes a complete line of text entered 
by the user and assign it to a string variable. Unlike the ''INPUT'' 
command, which stops at the first comma or space, ''LINE INPUT''
reads all the characters until the user presses enter.

Typically, you precede the ''LINE INPUT'' command with a message 
that tells the user what to enter. When the user presses enter, 
the entire line of text typed is assigned to the variable specified 
after the ''LINE INPUT'' command.

The variable containing the captured string can be used later in
the program for various operations, such as printing the value, 
comparing it to other strings, or manipulating it further.

The ''LINE INPUT'' is especially useful when you want to capture 
sentences or longer texts, which may contain spaces, commas, and 
other special characters. It does not impose restrictions on the 
format of the input, allowing the user to enter any type of 
character. It is a command that is easy to use and understand.

@italian

Il comando ''LINE INPUT'' prende una riga completa di testo 
immessa dall'utente e la assegna a una variabile stringa. A 
differenza del comando ''INPUT'', che si ferma alla prima virgola
o spazio, ''LINE INPUT'' legge tutti i caratteri finché l'utente
 non preme Invio.

In genere, si fa precedere il comando ''LINE INPUT'' da un messaggio
che indica all'utente cosa immettere. Quando l'utente preme Invio, 
l'intera riga di testo digitata viene assegnata alla variabile 
specificata dopo il comando ''LINE INPUT''.

La variabile contenente la stringa catturata può essere utilizzata 
in seguito nel programma per varie operazioni, come la stampa del 
valore, il confronto con altre stringhe o l'ulteriore manipolazione.

''LINE INPUT'' è particolarmente utile quando si desidera catturare 
frasi o testi più lunghi, che possono contenere spazi, virgole e 
altri caratteri speciali. Non impone restrizioni al formato 
dell'input, consentendo all'utente di immettere qualsiasi tipo 
di carattere. È un comando facile da usare e da capire.

@syntax LINE INPUT [prompt];v1
@syntax LINE INPUT [prompt],v1

@example LINE INPUT "Type a line ", a$
@example PRINT a$

@seeAlso INPUT (instruction)

</usermanual> */

void input( Environment * _environment, char * _variable, VariableType _default_type ) {

    MAKE_LABEL
    
    Variable * result = variable_retrieve_or_define( _environment, _variable, _default_type, 0 );

    char repeatLabel[MAX_TEMPORARY_STORAGE]; sprintf(repeatLabel, "%srepeat", label );
    char finishedLabel[MAX_TEMPORARY_STORAGE]; sprintf(finishedLabel, "%sfinished", label );
    char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf(doneLabel, "%sdone", label );
    char backspaceLabel[MAX_TEMPORARY_STORAGE]; sprintf(backspaceLabel, "%sbackspace", label );

    Variable * temporary = variable_temporary( _environment, VT_DSTRING, "(temporary storage for input)");
    Variable * offset = variable_temporary( _environment, VT_BYTE, "(offset inside temporary storage)");

    Variable * enter = variable_temporary( _environment, VT_CHAR, "(enter)" );
    Variable * comma = variable_temporary( _environment, VT_CHAR, "(comma)" );
    Variable * space = variable_temporary( _environment, VT_CHAR, "(space)" );
    Variable * underscore = variable_temporary( _environment, VT_CHAR, "(underscore)" );
    Variable * backspace = variable_temporary( _environment, VT_CHAR, "(backspace)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size max)" );
    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");
    Variable * key = variable_temporary( _environment, VT_CHAR, "(key pressed)");
    Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );

    cpu_store_8bit( _environment, enter->realName, 13 );
    cpu_store_8bit( _environment, offset->realName, 0 );
    cpu_store_8bit( _environment, backspace->realName, 8 );
    cpu_store_8bit( _environment, space->realName, 32 );
    cpu_store_8bit( _environment, zero->realName, 0 );

    if ( _environment->lineInput ) {
        cpu_store_8bit( _environment, comma->realName, 13 );
    } else {
        cpu_store_8bit( _environment, comma->realName, _environment->keyboardConfig.separator == 0 ? INPUT_DEFAULT_SEPARATOR : _environment->keyboardConfig.separator );
    }

    cpu_store_8bit( _environment, size->realName, _environment->keyboardConfig.size == 0 ? INPUT_DEFAULT_SIZE : _environment->keyboardConfig.size );
    cpu_store_8bit( _environment, underscore->realName, _environment->keyboardConfig.cursor == 0 ? INPUT_DEFAULT_CURSOR : _environment->keyboardConfig.cursor );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
    cpu_dsfree( _environment, temporary->realName );
    cpu_dsalloc( _environment, size->realName, temporary->realName );
    cpu_dsdescriptor( _environment, temporary->realName, address->realName, pressed->realName );

    cpu_label( _environment, repeatLabel );

    print( _environment, underscore->name, 0 );
    cmove_direct( _environment, -1, 0 );

    cia_inkey( _environment, key->realName );

    cpu_bveq( _environment, key->realName, repeatLabel );

    cpu_compare_8bit( _environment, key->realName, backspace->realName, pressed->realName, 1 );

    cpu_bvneq( _environment, pressed->realName, backspaceLabel );

    cpu_compare_8bit( _environment, key->realName, comma->realName, pressed->realName, 1 );

    cpu_bvneq( _environment, pressed->realName, finishedLabel );

    cpu_compare_8bit( _environment, key->realName, enter->realName, pressed->realName, 1 );

    cpu_bvneq( _environment, pressed->realName, finishedLabel );

    print( _environment, key->name, 0 );

    cpu_move_8bit_indirect_with_offset2( _environment, key->realName, address->realName, offset->realName );

    cpu_inc( _environment, offset->realName );

    cpu_compare_8bit( _environment, offset->realName, size->realName, pressed->realName, 1 );

    cpu_bveq( _environment, pressed->realName, repeatLabel );

    cpu_jump( _environment, finishedLabel );

    cpu_label( _environment, backspaceLabel );

    cpu_compare_8bit( _environment, offset->realName, zero->realName, pressed->realName, 1 );
    
    cpu_bvneq( _environment, pressed->realName, repeatLabel );

    cpu_dec( _environment, offset->realName );

    print( _environment, space->name, 0 );

    cmove_direct( _environment, -2, 0 );

    print( _environment, space->name, 0 );

    cmove_direct( _environment, -1, 0 );
    
    cpu_jump( _environment, repeatLabel );

    cpu_label( _environment, finishedLabel );

    print( _environment, space->name, 0 );
    cmove_direct( _environment, -1, 0 );

    cpu_compare_8bit( _environment, comma->realName, enter->realName, pressed->realName, 1 );
    cpu_bveq( _environment, pressed->realName, doneLabel );

    print_newline( _environment );

    cpu_label( _environment, doneLabel );

    cpu_dsresize( _environment, temporary->realName, offset->realName );

    switch( VT_BITWIDTH( result->type ) ) {
        case 8:
        case 16:
        case 32:
            variable_move( _environment, variable_string_val( _environment, temporary->name )->name, result->name );
            break;
        case 0:
            switch( result->type ) {
                case VT_DSTRING:
                    variable_move_naked( _environment, temporary->name, result->name );
                    break;
                default:
                    CRITICAL_INPUT_UNSUPPORTED( _variable, DATATYPE_AS_STRING[result->type] );        
            }
    }

}

#endif
