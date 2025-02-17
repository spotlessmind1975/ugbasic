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

/* <usermanual>
@keyword FUJINET CLOSE

@english

The ''FUJINET CLOSE'' instruction can be used to close a previously opened 
connection on the currently selected FujiNet device. The information on the 
channel actually open, and on the general situation, is contained within the 
device. It follows that it is necessary to check whether the connection is still 
active, before sending this command, by querying the connection status with the 
commands ''FUJINET STATUS'' and ''FUJINET CONNECTED''.

@italian

L'istruzione ''FUJINET CLOSE'' può essere utilizzata per chiudere una connessione 
aperta in precedenza sul dispositivo FujiNet correntemente selezionato. 
L'informazione sul canale effettivamente aperto, e sulla situazione in generale, 
è contenuta all'interno dell'apparecchio. Ne consegue che è necessario verificare 
se la connessione è ancora attiva, prima di inviare questo comando, interrogando 
lo stato di connessione con i comandi ''FUJINET STATUS'' and ''FUJINET CONNECTED''.

@syntax FUJINET CLOSE

@example FUJINET STATUS
@example IF FUJINET CONNECTED THEN
@example    FUJINET CLOSE
@example ENDIF

@seeAlso FUJINET OPEN
@seeAlso FUJINET STATUS
@seeAlso FUJINET CONNECTED

@target atari coco
</usermanual> */

#if !defined(__atari__) && !defined(__atarixl__) && !defined(__coco__) 

void fujinet_close( Environment * _environment ) {

}

#endif
