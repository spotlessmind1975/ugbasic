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
 * @brief Emit ASM code for <b>IN</b>
 * 
 * @param _environment Current calling environment
 * @param _port Expression with the port to receive input from
 * @return _value Valure read
 */
/* <usermanual>
@keyword IN

@english

The ''IN'' command is used to read a value from a specific input/output (I/O) port.
The ''port'' parameter indicates the exact address of the I/O port from which you want to 
acquire the data. The port address varies depending on the architecture of the 
computer and the connected peripheral. 

When the program encounters the ''IN'' instruction, it stops executing and reads 
the binary value present on the specified port. The value read from the port is 
converted into a numeric format understandable by the program and is assigned 
to the value variable.

The ''IN'' command is often used to read data from sensors connected to I/O ports, 
such as temperature, humidity, light sensors, etc. It can be used to control the 
status of external devices, such as motors, relays, displays, etc. In combination 
with other instructions, the ''IN'' command can be used to implement serial 
communication with other devices.

@italian

Il comando ''IN'' viene utilizzato per leggere un valore da una porta di 
input/output (I/O) specifica. Il parametro ''port'' indica l'indirizzo esatto della 
porta I/O da cui si desidera acquisire i dati. L'indirizzo della porta varia a 
seconda dell'architettura del computer e della periferica collegata.

Quando il programma incontra l'istruzione ''IN'', interrompe l'esecuzione e 
legge il valore binario presente sulla porta specificata. Il valore letto dalla 
porta viene convertito in un formato numerico comprensibile dal programma e 
assegnato alla variabile valore.

Il comando ''IN'' viene spesso utilizzato per leggere dati da sensori collegati 
a porte I/O, come temperatura, umidità, sensori di luce, ecc. Può essere 
utilizzato per controllare lo stato di dispositivi esterni, come motori, relè, 
display, ecc. In combinazione con altre istruzioni, il comando ''IN'' può essere 
utilizzato per implementare la comunicazione seriale con altri dispositivi.

@syntax = IN(port)

@example x = IN( &HBC00 )

@target c128z
@target coleco
@target cpc
@target msx1
@target sc3000
@target sg1000
@target vg5000
@target zx
</usermanual> */

Variable * in_var( Environment * _environment, char * _port ) {

    Variable * port = variable_retrieve_or_define( _environment, _port, VT_WORD, 0 );

    Variable * value = variable_temporary( _environment, VT_BYTE, "(value)" );

    cpu_in( _environment, port->realName, value->realName );

    return value;
    
}
