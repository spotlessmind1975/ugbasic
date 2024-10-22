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

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit ASM code for <b>OUT</b>
 * 
 * @param _environment Current calling environment
 * @param _port Expression with the port to send output to
 * @param _value Expression to send.
 */
/* <usermanual>
@keyword OUT

@english

The ''OUT'' command is a statement that allows your program to interact directly 
with your computer's hardware, specifically its input/output (I/O) ports. This
command is especially useful in contexts where you want to control external 
devices connected to your computer, such as printers, sound cards, or 
data acquisition devices.

When you use the ''OUT'' command, you specify a port address and a value to 
send to that port. The port address identifies a particular hardware 
device connected to your computer, while the value sent determines the action
the device will perform.

The use of the ''OUT'' command is highly dependent on the specific hardware 
of your computer. The port addresses and values to send vary depending on 
the type of device connected and the system configuration. 

Improper use of the ''OUT'' command can damage the hardware or cause the 
system to malfunction. It is essential to have a thorough understanding 
of the hardware you are interacting with and to use this command with caution.

@italian

Il comando ''OUT'' è un'istruzione che consente al programma di interagire 
direttamente con l'hardware del computer, in particolare con le porte di 
input/output (I/O). Questo comando è particolarmente utile nei contesti 
in cui si desidera controllare dispositivi esterni collegati al computer, 
come stampanti, schede audio o dispositivi di acquisizione dati.

Quando si utilizza il comando ''OUT'', si specifica un indirizzo di porta 
e un valore da inviare a tale porta. L'indirizzo di porta identifica un 
particolare dispositivo hardware collegato al computer, mentre il valore 
inviato determina l'azione che il dispositivo eseguirà.

L'utilizzo del comando ''OUT'' dipende in larga misura dall'hardware 
specifico del computer. Gli indirizzi di porta e i valori da inviare 
variano a seconda del tipo di dispositivo collegato e della configurazione 
del sistema.

L'utilizzo improprio del comando ''OUT'' può danneggiare l'hardware o 
causare malfunzionamenti del sistema. È essenziale avere una conoscenza 
approfondita dell'hardware con cui si sta interagendo e utilizzare questo 
comando con cautela.

@syntax OUT port, value

@example OUT &HBC00, 0

@target c128z
@target coleco
@target cpc
@target msx1
@target sc3000
@target sg1000
@target vg5000
@target zx
</usermanual> */
void out_var( Environment * _environment, char * _port, char * _value ) {

    Variable * port = variable_retrieve_or_define( _environment, _port, VT_WORD, 0 );

    Variable * value = variable_retrieve_or_define( _environment, _value, VT_BYTE, 0 );

    cpu_out( _environment, port->realName, value->realName );

}
