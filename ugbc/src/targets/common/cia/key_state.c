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
@keyword KEY STATE

@english

The ''KEY STATE'' command allows you to know the pressing state of a
single specific key. The reading is immediate: therefore, it is 
possible to detect the pressing of even more than one key at a time 
and, if the user is too fast or the program is too slow, there is 
the possibility that the pressing of the key is not detected.

The parameter of this function is the so-called "keycode". Each 
key on the target computer's keyboard is encoded by a value, which 
is specific to the hardware being considered. It should not be 
confused with the ASCII code, which is a representation shared between 
the various targets.

All the keys on the keyboard have been encoded by a specific 
constant, which is part of the dictionary of this language.

@italian

Il comando ''KEY STATE'' consente di conoscere lo stato di pressione di 
un singolo tasto specifico. La lettura è immediata: è quindi possibile 
rilevare la pressione anche di più tasti contemporaneamente e, se l'utente
è troppo veloce o il programma è troppo lento, c'è la possibilità che la 
pressione del tasto non venga rilevata.

Il parametro di questa funzione è il cosiddetto "keycode". Ogni tasto 
sulla tastiera del computer di destinazione è codificato da un valore, 
che è specifico per l'hardware in questione. Non deve essere confuso 
con il codice ASCII, che è una rappresentazione condivisa tra i vari target.

Tutti i tasti della tastiera sono stati codificati da una costante 
specifica, che fa parte del dizionario di questo linguaggio.

@syntax = KEY STATE(keycode)

@example IF KEY STATE(KEY A) THEN
@example     PRINT "A has been pressed!"
@example ENDIF

@alias KEYSTATE

</usermanual> */

/* <usermanual>
@keyword KEYSTATE

@english

@italian

@syntax = KEY STATE(keycode)

@alias KEY STATE

</usermanual> */

Variable * key_state( Environment * _environment, int _scancode ) {

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of KEY PRESSED)");

    char value[MAX_TEMPORARY_STORAGE]; sprintf( value, "#$%2.2x", _scancode );

    cia_key_state( _environment, value, result->realName );

    return result;
    
}

Variable * key_state_var( Environment * _environment, char * _scancode ) {

    Variable * scancode = variable_retrieve_or_define( _environment, _scancode, VT_BYTE, 0);
    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of KEY STATE)");

    cia_key_state( _environment, scancode->realName, result->realName );

    return result;
    
}

#endif
