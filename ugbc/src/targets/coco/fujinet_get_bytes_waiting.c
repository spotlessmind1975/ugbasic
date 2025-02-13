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
 
/* <usermanual>
@keyword FUJINET BYTES

@english

The function ''FUJINET BYTES'' returns the number of bytes that are waiting to 
be read from the channel for the selected device. In other words, if a read 
operation were performed, the system would read without blocking up to this 
number of bytes. The value refers to the last execution of the FUJINET STATUS 
command, so you need to execute this command before reading the information.

@italian

La funzione ''FUJINET BYTES'' restituisce il numero di byte che sono in attesa 
di essere letti dal canale relativo alla periferica selezionata. In altri termini, 
se venisse effettuata una operazione di lettura, il sistema leggerebbe senza 
bloccarsi fino a questo numero di bytes. Il valore è riferito all'ultima esecuzione 
del comando FUJINET STATUS, quindi è necessario eseguire questo comando prima di 
leggere l'informazione.

@syntax = FUJINET BYTES

@example PRINT FUJINET BYTES;" bytes to read"

@seeAlso FUJINET STATUS
@seeAlso FUJINET READ

@target coco
</usermanual> */
Variable * fujinet_get_bytes_waiting( Environment * _environment ) {

    Variable * bytes = variable_temporary( _environment, VT_BYTE, "(bytes)");

    coco_fujinet_get_bytes_waiting( _environment, bytes->realName );

    return bytes;

}