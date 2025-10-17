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
 * @brief 
 * 
 * @param _environment 
 * @param _mode 
 * @param _start_page 
 */
 /* <usermanual>
@keyword PMODE

@english

The instruction ''PMODE'' allow to select the mode and startpage, using the
Dragon BASIC syntax. The ''mode'' is a number from 0 to 4, and startpage 
is the page in video RAM you wish to start writing to. Note that ''mode''
and ''startpage'' must be constants.

@italian

L'istruzione ''PMODE'' permette di selezionare la modalità e la pagina 
iniziale, utilizzando la sintassi Dragon BASIC. La "modalità" è un numero 
da 0 a 4 e la pagina iniziale è la pagina nella RAM video su cui desideri 
iniziare a scrivere. Da notare che i parametri ''mode'' e ''startpage''
devono essere delle costanti.

@syntax PMODE mode, startpage

@example PMODE 1, 1

@target cocob
@verified
</usermanual> */
void pmode( Environment * _environment, int _mode, int _start_page ) {

    int m = 0;

    switch( _mode ) {
        // 0	128x96		BITMAP_MODE_RESOLUTION2
        case 0:
            m = BITMAP_MODE_RESOLUTION2;
            break;
        // 1	128x96		BITMAP_MODE_COLOR3
        case 1:
            m = BITMAP_MODE_COLOR3;
            break;
        // 2	192x128		BITMAP_MODE_RESOLUTION3
        case 2:
            m = BITMAP_MODE_RESOLUTION3;
            break;
        // 3	192x128		BITMAP_MODE_COLOR6
        case 3:
            m = BITMAP_MODE_COLOR6;
            break;
        // 4	256x192		BITMAP_MODE_RESOLUTION6        
        case 4:
            m = BITMAP_MODE_RESOLUTION6;
            break;
        default:
            WARNING_SCREEN_MODE( _mode );
            break;
    }

    if ( m ) {

        ScreenMode * mode = find_screen_mode_by_id( _environment, m );

        if ( mode ) {
            
            c6847b_screen_mode_enable( _environment, mode );    

            _environment->currentMode = mode->id;
            _environment->currentTileMode = mode->bitmap ? 0 : 1;

            cpu_store_8bit( _environment, "CURRENTMODE", _environment->currentMode );
            cpu_store_8bit( _environment, "CURRENTTILEMODE", _environment->currentTileMode );

        } else {
            WARNING_SCREEN_MODE( _mode );
        }

    }

}