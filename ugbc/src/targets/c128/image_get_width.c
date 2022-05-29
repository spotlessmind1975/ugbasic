/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>IMAGE WIDTH(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _image Image to measure.
 * @return The width of the image, in pixels
 */
/* <usermanual>
@keyword IMAGE WIDTH

@english
This function allows you to obtain the width of a given ''IMAGE'' or a given
set of ''IMAGES''. The width is expressed in pixels.

There is also a compile-level function for this keyword, which is called when the value 
is used to initialize a constant. In this case, the value is that taken from inspecting 
the instructions at the time of compilation.

@italian
Questa funzione permette di ottenere la larghezza dell'immagine (''IMAGE'') 
o delle immagini (''IMAGES'') date, espressa in pixel. La larghezza dipende 
dall'attuale modalità grafica selezionata, e può cambiare in sede di esecuzione.

Di questa parola chiave esiste anche una funzione a livello di compilazione, 
che viene richiamata quando il valore viene utilizzato per inizializzare una 
costante. In tal caso, il valore è quello desunto dall'ispezione delle 
istruzioni al momento della compilazione.

@syntax = IMAGE WIDTH([image])

@example starshipWidth = IMAGE WIDTH( LOAD IMAGE("starship.png") )

@usedInExample mobs_example_01.bas

@target all
</usermanual> */
Variable * image_get_width( Environment * _environment, char * _image ) {

    Variable * image = variable_retrieve( _environment, _image );
    Variable * result = variable_temporary( _environment, VT_WORD, "(image width)" );

    outline1("LDA #<%s", image->realName );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", image->realName );
    outline0("STA TMPPTR+1" );
    outline0("LDY #0" );
    outline0("LDA (TMPPTR),Y" );
    outline1("STA %s", result->realName );
    outline0("LDY #1" );
    outline0("LDA (TMPPTR),Y" );
    outline1("STA %s+1", result->realName );

    return result;

}
