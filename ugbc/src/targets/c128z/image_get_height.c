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
 * @brief Emit code for <strong>IMAGE HEIGHT(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param Image to measure.
 */
/* <usermanual>
@keyword IMAGE HEIGHT

@english
The ''IMAGE HEIGHT'' function will allow you to obtain the height of an
image (in pixels).

@italian
La funzione ''IMAGE HEIGHT'' permette di ottenere l'altezza di una immagine (in pixel).

@syntax = IMAGE HEIGHT([image])

@example starshipHeight = IMAGE HEIGHT( LOAD IMAGE("starship.png") )

@usedInExample mobs_example_01.bas

@target all
</usermanual> */
Variable * image_get_height( Environment * _environment, char * _image ) {

    Variable * image = variable_retrieve( _environment, _image );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(image height)" );

    outline1("LD HL, %s", image->realName );
    outline0("ADD HL, 2" );
    outline0("LD A, (HL)" );
    outline1("LD (%s), A", result->realName );

    return result;

}
