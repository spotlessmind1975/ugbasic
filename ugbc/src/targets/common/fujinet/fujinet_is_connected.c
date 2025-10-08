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
@keyword FUJINET CONNECTED

@english

The function ''FUJINET CONNECTED'' returns if the channel is connected for the 
selected device. The value refers to the last execution of the ''FUJINET STATUS'' 
command, so you need to execute this command before reading the information.

@italian

La funzione ''FUJINET CONNECTED'' restituisce se il canale relativo 
alla periferica selezionata è ancora connesso. Il valore è riferito all'ultima esecuzione 
del comando ''FUJINET STATUS'', quindi è necessario eseguire questo comando prima di 
leggere l'informazione.

@syntax = FUJINET CONNECTED

@example IF FUJINET CONNECTED THEN: "I AM CONNECTED!": ENDIF

@seeAlso FUJINET STATUS

@target atari coco
</usermanual> */

#if !defined(__atari__) && !defined(__atarixl__) && !defined(__coco__) && !defined(__cocob__) 

Variable * fujinet_is_connected( Environment * _environment ) {

    Variable * isConnected = variable_temporary( _environment, VT_SBYTE, "(bytes)");

    return isConnected;

}

#endif
