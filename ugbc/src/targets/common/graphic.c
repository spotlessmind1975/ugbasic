/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
#include "../../hw/6502.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

/**
 * @brief Emit ASM implementation for <b>GRAPHIC</b> instruction
 * 
 * This function is useful for quickly initializing the high resolution 
 * graphics mode. It is equivalent to running the following commands:
 * 
 * - <b>BITMAP ENABLE</b>
 * - <b>BITMAP CLEAR</b>
 * - <b>COLORMAP CLEAR</b>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
    @keyword GRAPHIC
    
    @english
    Do a quickly initialization with the high resolution graphics mode. 
    It is equivalent to running the following commands:

      - ''BITMAP ENABLE''
      - ''BITMAP CLEAR''
      - ''COLORMAP CLEAR''
      - ''COLOR BORDER BLACK''
    
    @italian
    Eseguire una rapida inizializzazione con la modalità grafica ad 
    alta risoluzione. Equivale a eseguire i seguenti comandi:

      - ''BITMAP ENABLE''
      - ''BITMAP CLEAR''
      - ''COLORMAP CLEAR''
      - ''COLOR BORDER BLACK''

    @syntax GRAPHIC

    @example GRAPHIC

    @target all

 </usermanual> */
void graphic( Environment * _environment ) {

    outline0("; GRAPHIC" );

    bitmap_enable( _environment );
    bitmap_clear( _environment );
    colormap_clear( _environment );
    color_border( _environment, COLOR_BLACK );

}

