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
@keyword FUJINET SET CHANNEL MODE

@english

The ''FUJINET SET CHANNEL MODE'' command allows you to specify the channel 
mode of the connection. Allowed modes are: 0 for body section, 1 for collect headers,
2 for get headers, 3 for set headers and 4 for setting data. The value &Hfc 
can be used for JSON mode. It returns 0 if ok, or an error otherwhise.

@italian

Il comando ''FUJINET SET CHANNEL MODE'' consente di specificare la modalità 
canale della connessione. Le modalità consentite sono: 0 per la sezione body, 
1 per raccogliere gli headers, 2 per ottenere intestazioni, 3 per impostare
le intestazioni e 4 per impostare dati binari. Il valore &Hfc può essere 
utilizzato per la modalità JSON. Restuisce 0 se ok, oppure un errore in caso
contrario.

@target atari coco
</usermanual> */

#if !defined(__atari__) && !defined(__atarixl__) && !defined(__coco__) 

Variable * fujinet_set_channel_mode( Environment * _environment, int _mode ) {

    Variable * err = variable_temporary( _environment, VT_BYTE, "(err)");

    variable_store( _environment, err->name, 0 );

    return err;

}

Variable * fujinet_set_channel_mode_var( Environment * _environment, char * _mode ) {

    Variable * err = variable_temporary( _environment, VT_BYTE, "(err)");
    
    variable_store( _environment, err->name, 0 );

    return err;

}

#endif
