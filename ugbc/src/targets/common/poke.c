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

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit ASM code for <b>POKE</b>
 * 
 * @param _environment Current calling environment
 * @param _address Expression with the location to write to.
 * @param _value Expression to write.
 */
/* <usermanual>
@keyword POKE

@english

The ''POKE'' is the write equivalent of the ''PEEK'' command, meaning it allows you 
to modify the contents of a specific memory cell. Essentially, ''POKE'' allows you 
to "write" a numeric value to a particular location in your computer's memory.

In many 8-bit systems, ''POKE'' was used to directly configure hardware, such as 
changing the color of the screen or the sound. By combining ''POKE'' with ''PEEK'', 
you could create custom graphics and sound effects, going beyond the standard 
ugBASIC capabilities. 

''POKE'' gives you very fine-grained control over your computer's memory, and
it allows you to create special effects and customizations that would otherwise 
be impossible. It is a great tool for understanding how a computer works internally.

Improper use of ''POKE'' can cause your computer to freeze or corrupt data. 
Randomly modifying memory can have unpredictable consequences. Valid memory 
addresses and their meanings vary from system to system.

@italian

''POKE'' è l'equivalente in scrittura del comando ''PEEK'', il che significa 
che consente di modificare il contenuto di una specifica cella di memoria,
ovvero di un singolo byte. 
In sostanza, ''POKE'' consente di "scrivere" un valore numerico in una posizione
specifica nella memoria del computer.

In molti sistemi a 8 bit, ''POKE'' veniva utilizzato per configurare direttamente 
l'hardware, ad esempio per cambiare il colore dello schermo o il suono. Combinando 
''POKE'' con ''PEEK'', era possibile creare effetti grafici ed effetti sonori 
personalizzati, andando oltre le capacità standard di ugBASIC.

''POKE'' offre un controllo molto preciso sulla memoria del computer e consente 
di creare effetti speciali e personalizzazioni che altrimenti sarebbero 
impossibili. È un ottimo strumento per comprendere il funzionamento interno 
di un computer.

L'uso improprio di ''POKE'' può causare il blocco o la corruzione dei dati 
del computer. La modifica casuale della memoria può avere conseguenze imprevedibili. 
Gli indirizzi di memoria validi e il loro significato variano da sistema a sistema.

@syntax POKE address, value

@example POKE 32768, 2

@seeAlso POKEW
@seeAlso POKED
@seeAlso D!POKE

</usermanual> */

void poke_var( Environment * _environment, char * _address, char * _value ) {

    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );

    Variable * realValue = variable_temporary( _environment, VT_BYTE, "(byte)" );

    Variable * value = NULL;

    if ( variable_exists( _environment, _value ) ) {
        value = variable_retrieve( _environment, _value );
    } else {
        value = variable_temporary( _environment, VT_BYTE, "(byte)" );
    }

    variable_move( _environment, value->name, realValue->name );

    cpu_poke( _environment, address->realName, realValue->realName );

}

/* <usermanual>
@keyword POKEW

@english

The ''POKEW'' is the write equivalent of the ''PEEKW'' command, meaning it allows you 
to modify the contents of two memory cells. Essentially, ''POKEW'' allows you 
to "write" a numeric value to a particular location in your computer's memory.

In many 8-bit systems, ''POKEW'' was used to directly configure hardware, such as 
changing the color of the screen or the sound. By combining ''POKEW'' with ''PEEKW'', 
you could create custom graphics and sound effects, going beyond the standard 
ugBASIC capabilities. 

''POKEW'' gives you very fine-grained control over your computer's memory, and
it allows you to create special effects and customizations that would otherwise 
be impossible. It is a great tool for understanding how a computer works internally.

Improper use of ''POKEW'' can cause your computer to freeze or corrupt data. 
Randomly modifying memory can have unpredictable consequences. Valid memory 
addresses and their meanings vary from system to system.

@italian

''POKEW'' è l'equivalente in scrittura del comando ''PEEKW'', il che significa 
che consente di modificare il contenuto di una specifica cella di memoria,
ovvero di un singolo byte. In sostanza, ''POKEW'' consente di "scrivere" un 
valore numerico in una posizione specifica nella memoria del computer.

In molti sistemi a 8 bit, ''POKEW'' veniva utilizzato per configurare direttamente 
l'hardware, ad esempio per cambiare il colore dello schermo o il suono. Combinando 
''POKEW'' con ''PEEKW'', era possibile creare effetti grafici ed effetti sonori 
personalizzati, andando oltre le capacità standard di ugBASIC.

''POKEW'' offre un controllo molto preciso sulla memoria del computer e consente 
di creare effetti speciali e personalizzazioni che altrimenti sarebbero 
impossibili. È un ottimo strumento per comprendere il funzionamento interno 
di un computer.

L'uso improprio di ''POKEW'' può causare il blocco o la corruzione dei dati 
del computer. La modifica casuale della memoria può avere conseguenze imprevedibili. 
Gli indirizzi di memoria validi e il loro significato variano da sistema a sistema.

@syntax POKEW address, value

@example POKEW 32768, 2

@seeAlso POKE
@seeAlso POKED
@alias D!POKE

</usermanual> */

/* <usermanual>
@keyword D!POKE
@alias POKEW
</usermanual> */

void pokew_var( Environment * _environment, char * _address, char * _value ) {

    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );

    Variable * realValue = variable_temporary( _environment, VT_WORD, "(word)" );

    Variable * value = NULL;

    if ( variable_exists( _environment, _value ) ) {
        value = variable_retrieve( _environment, _value );
    } else {
        value = variable_temporary( _environment, VT_WORD, "(word)" );
    }

    variable_move( _environment, value->name, realValue->name );

    cpu_pokew( _environment, address->realName, realValue->realName );

}

/* <usermanual>
@keyword POKED

@english

The ''POKED'' is the write equivalent of the ''PEEKD'' command, meaning it allows you 
to modify the contents of four memory cells. Essentially, ''POKED'' allows you 
to "write" a numeric value to a particular location in your computer's memory.

In many 8-bit systems, ''POKED'' was used to directly configure hardware, such as 
changing the color of the screen or the sound. By combining ''POKED'' with ''PEEKD'', 
you could create custom graphics and sound effects, going beyond the standard 
ugBASIC capabilities. 

''POKED'' gives you very fine-grained control over your computer's memory, and
it allows you to create special effects and customizations that would otherwise 
be impossible. It is a great tool for understanding how a computer works internally.

Improper use of ''POKED'' can cause your computer to freeze or corrupt data. 
Randomly modifying memory can have unpredictable consequences. Valid memory 
addresses and their meanings vary from system to system.

@italian

''POKED'' è l'equivalente in scrittura del comando ''PEEKD'', il che significa 
che consente di modificare il contenuto di una specifica cella di memoria,
ovvero di un singolo byte. In sostanza, ''POKED'' consente di "scrivere" un 
valore numerico in una posizione specifica nella memoria del computer.

In molti sistemi a 8 bit, ''POKED'' veniva utilizzato per configurare direttamente 
l'hardware, ad esempio per cambiare il colore dello schermo o il suono. Combinando 
''POKED'' con ''PEEKD'', era possibile creare effetti grafici ed effetti sonori 
personalizzati, andando oltre le capacità standard di ugBASIC.

''POKED'' offre un controllo molto preciso sulla memoria del computer e consente 
di creare effetti speciali e personalizzazioni che altrimenti sarebbero 
impossibili. È un ottimo strumento per comprendere il funzionamento interno 
di un computer.

L'uso improprio di ''POKED'' può causare il blocco o la corruzione dei dati 
del computer. La modifica casuale della memoria può avere conseguenze imprevedibili. 
Gli indirizzi di memoria validi e il loro significato variano da sistema a sistema.

@syntax POKED address, value

@example POKED 32768, 2

@seeAlso POKE
@seeAlso POKEW

</usermanual> */

void poked_var( Environment * _environment, char * _address, char * _value ) {

    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );

    Variable * realValue = variable_temporary( _environment, VT_DWORD, "(dword)" );

    Variable * value = NULL;

    if ( variable_exists( _environment, _value ) ) {
        value = variable_retrieve( _environment, _value );
    } else {
        value = variable_temporary( _environment, VT_DWORD, "(dword)" );
    }

    variable_move( _environment, value->name, realValue->name );

    cpu_poked( _environment, address->realName, realValue->realName );

}
