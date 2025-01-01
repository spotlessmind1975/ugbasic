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
@keyword KEY PRESSED

@english

The ''KEY PRESSED'' command allows you to know the pressing state of a
single specific key, during the "duty cycle" of the keyboard driver.
The reading is deferred: therefore, it is 
possible to detect the pressing of just one key at a time but there is 
no possibility that the pressing of the key is not detected.

The parameter of this function is the so-called "keycode". Each 
key on the target computer's keyboard is encoded by a value, which 
is specific to the hardware being considered. It should not be 
confused with the ASCII code, which is a representation shared between 
the various targets.

All the keys on the keyboard have been encoded by a specific 
constant, which is part of the dictionary of this language.

@italian

Il comando ''KEY PRESSED'' consente di conoscere lo stato di 
pressione di un singolo tasto specifico, durante il "duty cycle"
del driver della tastiera. La lettura è differita: quindi, è
possibile rilevare la pressione di un solo tasto alla volta 
ma non c'è possibilità che la pressione del tasto non venga rilevata.

Il parametro di questa funzione è il cosiddetto "keycode". Ogni
tasto sulla tastiera del computer di destinazione è codificato 
da un valore, che è specifico dell'hardware in questione. Non deve 
essere confuso con il codice ASCII, che è una rappresentazione 
condivisa tra i vari target.

Tutti i tasti della tastiera sono stati codificati da una costante 
specifica, che fa parte del dizionario di questo linguaggio.

@syntax = KEY PRESSED(keycode)

@example IF KEY PRESSED(KEY A) THEN
@example     PRINT "A has been pressed!"
@example ENDIF

</usermanual> */

Variable * key_pressed( Environment * _environment, int _scancode ) {

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of KEY PRESSED)");

    char value[MAX_TEMPORARY_STORAGE]; sprintf( value, "#$%2.2x", _scancode );

    cia_key_pressed( _environment, value, result->realName );

    return result;
    
}

Variable * key_pressed_var( Environment * _environment, char * _scancode ) {

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of KEY PRESSED)");
    Variable * scancode = variable_retrieve_or_define( _environment, _scancode, VT_BYTE, 0xff);

    cia_key_pressed( _environment, scancode->realName, result->realName );

    return result;
    
}

#endif
