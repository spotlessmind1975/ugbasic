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
 * @brief Emit ASM code for <b>SCREEN [mode]</b>
 * 
 * This function outputs assembly code to change the current mode.
 * 
 * @param _environment Current calling environment
 * @param _mode Mode to change to
 */
void screen_mode( Environment * _environment, int _mode ) {

    ScreenMode * mode = find_screen_mode_by_id( _environment, _mode );

    if ( mode ) {
        ted_screen_mode_enable( _environment, mode );    

        _environment->currentMode = mode->id;
        _environment->currentTileMode = mode->bitmap ? 0 : 1;

        cpu_store_8bit( _environment, "CURRENTMODE", _environment->currentMode );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", _environment->currentTileMode );

    } else {
        WARNING_SCREEN_MODE( _mode );
    }
}

void screen_type_color_set( Environment * _environment, int _type, int _color_set ) {

    if ( _type == 0 ) {
        tilemap_enable( _environment, 0, 0, 0, 0, 0 );
    } else {
        bitmap_enable( _environment, 0, 0, 0 );
    }

}
