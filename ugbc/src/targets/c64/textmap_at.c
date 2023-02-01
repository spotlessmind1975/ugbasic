/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
@keyword TEXTADDRESS

@english
This is a variable (16 bit) that contains the actual address of the textmap. 
It can be modified directly by using assignment, and can be read as any 
other variable. Note that no check is done when using this variable, so an
invalid value lead to undefined behaviours. If you want to use a valid value
please use the [[TEXTMAP AT]] command.

@italian
Questa variabile contiene l'indirizzo effettivo (a 16 bit) della mappa 
di memoria con i contenuti testuali. Può essere modificata direttamente 
utilizzando l'assegnazione, e può essere letta come qualsiasi altra 
variabile. Si noti che non viene eseguito alcun controllo quando si utilizza
questa variabile, quindi un valore non valido porta a comportamenti 
indefiniti. Se vuoi assegnare un valore valido usa il comando [[TEXTMAP AT]].

@syntax [variable] = TEXTADDRESS
@syntax TEXTADDRESS = [expression]

@example actual = TEXTADDRESS
@example TEXTADDRESS = $8400

@target c64

@seeAlso TEXTMAP AT
</usermanual> */

/**
 * @brief Emit ASM code for <b>TEXTMAP AT [int]xx</b>
 * 
 * This function allows you to set the starting address, in memory, for the 
 * text and it is the version that is used when the memory is given as a
 * direct number (i.e.: $8400). The input parameter is decoded and declined 
 * according to the hardware limits. So it is not said that exactly the 
 * given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `TEXTADDRESS` (VT_ADDRESS) - the starting address of text memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
/* <usermanual>
@keyword TEXTMAP AT

@english
Set the starting address, in memory, for the textmap. The input parameter 
is decoded and declined according to the hardware limits. So it is not
said that exactly the given address is set.

@italian
Imposta l'indirizzo di partenza, in memoria, per la textmap. Il parametro 
di input viene decodificato e declinato in base ai limiti hardware. Quindi 
non è detto che sia impostato esattamente con l'indirizzo specificato.

@syntax TEXTMAP AT # [integer]

@example TEXTMAP AT #$8400

@target c64

@seealso TEXTADDRESS
</usermanual> */
void textmap_at( Environment * _environment, int _address ) {

    

    // Let's define the special variable bitmapAddress, and update
    // it with the requested value.
    Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );
    variable_store( _environment, TEXTADDRESS->realName, ( ( _address >> 10 ) & 0x0f ) * 0x8400 );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "#$%2.2x", ( _address >> 8 ) & 0xff );

    vic2_textmap_at( _environment, addressString );

}

/**
 * @brief Emit ASM code for <b>TEXTMAP AT [expression]</b>
 * 
 * This function allows you to set the starting address, in memory, for the 
 * text and it is the version that is used when the memory is given as an
 * expression. The input parameter is decoded and declined according to the 
 * hardware limits. So it is not said that exactly the given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `TEXTADDRESS` (VT_ADDRESS) - the starting address of text memory
 * 
 * @param _environment Current calling environment
 * @param _address Expression with address to use
 */
/* <usermanual>
@keyword TEXTMAP AT

@syntax TEXTMAP AT [expression]

@example TEXTMAP AT newTextmapAddress

@target c64
</usermanual> */
void textmap_at_var( Environment * _environment, char * _address ) {

    

    Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );
    Variable * address = variable_retrieve( _environment, _address );

    variable_move( _environment, address->name, TEXTADDRESS->name );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "%s+1", address->realName );

    vic2_textmap_at( _environment, addressString );

}
