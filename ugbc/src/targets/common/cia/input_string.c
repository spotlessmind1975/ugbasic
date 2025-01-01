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
@keyword INPUT (function)

@english

The INPUT$ function reads a string of characters specified on the 
keyboard and stores them in a variable. Unlike ''INPUT'', which pauses 
and waits until the user presses wnter, ''INPUT$'' reads a fixed 
''number'' of characters without prompting for an enter.

It is used to read barcodes, serial numbers, or other fixed 
character sequences, and to create simpler and more direct 
user interfaces, avoiding the need to press enter after each 
character. 

''INPUT$'' always reads the specified ''number'' of characters, 
even if the user types fewer than that. It does not perform any 
checks on the validity of the characters entered.

@italian

La funzione ''INPUT$'' legge una stringa di caratteri specificati 
sulla tastiera e li memorizza in una variabile. ''INPUT'', che si
ferma e attende che l'utente prema wnter, ''INPUT$'' legge un 
''number'' fisso di caratteri senza richiedere un invio.

Viene utilizzata per leggere codici a barre, numeri di serie 
o altre sequenze di caratteri fisse e per creare interfacce 
utente più semplici e dirette, evitando la necessità di premere
invio dopo ogni carattere.

''INPUT$'' legge sempre il ''number'' di caratteri specificato, 
anche se l'utente ne digita meno. Non esegue alcun controllo 
sulla validità dei caratteri immessi.

@syntax = INPUT$(number)

@example IF INPUT$(3) = "123" THEN
@example    PRINT "123 has been pressed!"
@example ENDIF

@seeAlso INPUT (instruction)

</usermanual> */

Variable * input_string( Environment * _environment, char * _size ) {

    MAKE_LABEL
    
    char repeatLabel[MAX_TEMPORARY_STORAGE]; sprintf(repeatLabel, "%srepeat", label );

    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of INPUT$)");
    Variable * offset = variable_temporary( _environment, VT_BYTE, "(offset inside INPUT$)");
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of result of INPUT$)");
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_BYTE, 0 );
    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");
    Variable * key = variable_temporary( _environment, VT_CHAR, "(key pressed)");

    cpu_dsfree( _environment, result->realName );
    cpu_dsalloc( _environment, size->realName, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, pressed->realName );

    cpu_store_8bit( _environment, offset->realName, 0 );

    cpu_label( _environment, repeatLabel );

    cia_inkey( _environment, key->realName );

    cpu_bveq( _environment, key->realName, repeatLabel );

    cpu_move_8bit_indirect_with_offset2( _environment, key->realName, address->realName, offset->realName );

    cpu_inc( _environment, offset->realName );

    cpu_compare_8bit( _environment, offset->realName, size->realName, pressed->realName, 1 );

    cpu_bveq( _environment, pressed->realName, repeatLabel );

    return result;

}

#endif
