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

/**
 * @brief Emit code for <strong>FRAMES(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _image image to check
 * @return The number of frames
 */
/* <usermanual>
@keyword FRAMES

@english
This function allows you to obtain the number of frames that make up a set of images (''IMAGES'').
If applied to a single image resource (''IMAGE''), however, it always returns 1. 
The value is obtained by retrieving it from the resource itself, and therefore is 
constant for the entire duration of the execution.

There is also a compile-level function for this keyword, which is called when the value 
is used to initialize a constant. In this case, the value is that taken from inspecting 
the instructions at the time of compilation.

@italian
Questa funzione permette di ottenere il numero di fotogrammi di cui è composta una risorsa che
contiene un'insieme di immagini (''IMAGES''). Se applicato a una risorsa di tipo singola 
immagine (''IMAGE''), invece, ritorna sempre 1. Il valore è ottenuto recuperandolo dalla risorsa stessa, 
e quindi è costante per l'intera durata dell'esecuzione. 

Di questa parola chiave esiste anche una funzione a livello di compilazione, 
che viene richiamata quando il valore viene utilizzato per inizializzare una 
costante. In tal caso, il valore è quello desunto dall'ispezione delle 
istruzioni al momento della compilazione.

@syntax = FRAMES([images])

@example FOR i = 0 TO FRAMES(animazione)

@usedInExample images_load_06.bas
@usedInExample multitasking_example_06.bas

@target all
</usermanual> */

/* <usermanual>
@keyword IMAGES COUNT

@english
Alias for ''FRAMES''.

@italian
Alias per ''FRAMES''.

@seeAlso FRAMES

@target all
</usermanual> */

/* <usermanual>
@keyword FRAMES COUNT

@english
Alias for ''FRAMES''.

@italian
Alias per ''FRAMES''.

@seeAlso FRAMES

@target all
</usermanual> */
int frames( Environment * _environment, char * _image ) {

    Variable * v = variable_retrieve( _environment, _image );
    switch( v->type ) {
        case VT_SEQUENCE:
            if ( !v->valueBuffer ) {
                CRITICAL_NOT_ASSIGNED_SEQUENCE( v->name );
            }
            return v->frameCount;
            break;
        case VT_IMAGES:
            if ( !v->valueBuffer ) {
                CRITICAL_NOT_ASSIGNED_IMAGES( v->name );
            }
            return v->frameCount;
            break;
        case VT_IMAGE:
            if ( !v->valueBuffer ) {
                CRITICAL_NOT_ASSIGNED_IMAGE( v->name );
            }
            return 1;
            break;
        default:
            CRITICAL_NOT_IMAGES( v->name );
    }

}
