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
@keyword FUJINET STATUS

@english

The ''FUJINET STATUS'' instruction queries the connection status on FujiNet, 
updating a series of information that can then be queried separately, including
the number of bytes waiting to be read, the last error or whether the channel 
is actually connected.

@italian

L'istruzione ''FUJINET STATUS'' interroga lo stato della connessione su FujiNet, 
aggiornando una serie di informazioni che poi potranno essere interrogate 
separatamente, tra cui il numero di bytes in attesa di essere letti, l'ultimo errore 
o se il canale è effettivamente connesso.

@syntax FUJINET STATUS

@example FUJINET STATUS

@target coco
</usermanual> */

#if !defined(__atari__) && !defined(__atarixl__) && !defined(__coco__) 

void fujinet_get_status( Environment * _environment ) {

}

#endif
