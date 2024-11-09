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
@keyword PUT KEY

@english

The ''PUT KEY'' command allows you to simulate pressing a key on your computer 
keyboard. Basically, you enter a string of characters and ugBASIC will use
it as if they were typed one after the other. This can be very useful for 
automating certain actions, such as automatically entering your password 
or emulating keystrokes.

This can be used to automatically enters a password into a game or application,
or to simulate an user interaction with the program itself, such as pressing a 
button or selecting a menu. It can help to create sequences of commands that 
are executed automatically, such as a macro.

The maximum length of the string you can enter depends on the keyboard buffer,
but normally is up to 10 characters.

Please note that this feature is available with the "asynchronous" keyboard 
reading mechanism or in some specific, selected targets.

@italian

Il comando ''PUT KEY'' consente di simulare la pressione di un tasto sulla 
tastiera del computer. In pratica, si immette una stringa di caratteri e 
ugBASIC la utilizzerà come se fossero stati digitati uno dopo l'altro.
 Questo può essere molto utile per automatizzare determinate azioni, come 
 l'immissione automatica della password o l'emulazione di sequenze di tasti.

Questo può essere utilizzato per immettere automaticamente una password in un 
gioco o in un'applicazione, o per simulare un'interazione dell'utente con il 
programma stesso, come la pressione di un pulsante o la selezione di un menu. 
Può aiutare a creare sequenze di comandi che vengono eseguiti automaticamente, 
come una macro.

La lunghezza massima della stringa che è possibile immettere dipende dal 
buffer della tastiera, ma normalmente è fino a 10 caratteri.

Da notare che questa funzionalità è disponibile con il  meccanismo di lettura 
della tastiera di tipo "asincrono" oppure in alcuni, specifici, target selezionati.

@syntax PUT KEY string

@example PUT KEY "yes"

</usermanual> */

void put_key( Environment * _environment, char * _string ) {

    Variable * string = variable_retrieve( _environment, _string );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );

    switch( string->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, string->realName, size->realName );
            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            break;
        case VT_CHAR:
            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_store_8bit( _environment, size->realName, 1 );
            break;
    }

    cia_put_key( _environment, address->realName, size->realName );

}

#endif
