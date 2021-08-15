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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

void every_cleanup( Environment * _environment ) {

    if ( _environment->everys || _environment->vbls ) {

        int i=0;

        cpu_label( _environment, "EVERYSVC" );

        char everyGlobalCheckLabel[MAX_TEMPORARY_STORAGE]; sprintf(everyGlobalCheckLabel, "everystatus%d", UNIQUE_ID );

        // cpu_di( _environment );

        cpu_store_8bit( _environment, "INSIDERASTER", 1 );

        for( i=0; i<_environment->vbls; ++i ) {

            cpu_call( _environment, _environment->vblLabel[i] );

        }

        if ( _environment->everyStatus ) {

            cpu_bveq( _environment, _environment->everyStatus->realName, everyGlobalCheckLabel );

            for( i=0; i<_environment->everys; ++i ) {

                char everyCheckLabel[MAX_TEMPORARY_STORAGE]; sprintf(everyCheckLabel, "everynone%d", UNIQUE_ID );

                cpu_dec( _environment, _environment->everyCounter[i]->realName );

                cpu_bvneq( _environment, _environment->everyCounter[i]->realName, everyCheckLabel );

                cpu_call( _environment, _environment->everyLabel[i] );

                variable_move_naked( _environment, _environment->everyTiming[i]->name, _environment->everyCounter[i]->name );

                cpu_label( _environment, everyCheckLabel );

            }

            cpu_label( _environment, everyGlobalCheckLabel );

        }

        cpu_store_8bit( _environment, "INSIDERASTER", 0 );

        // cpu_ei( _environment );

        vic2_next_raster( _environment );

    }

}
