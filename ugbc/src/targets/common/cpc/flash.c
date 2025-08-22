/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

#if defined(__cpc__)

void flash( Environment * _environment, char * _index, char * _register ) {

        Variable * idx = variable_retrieve_or_define( _environment, _index, VT_BYTE, 0 );
    Variable * reg = NULL;
    if ( _register ) {
        reg = variable_retrieve_or_define( _environment, _register, VT_ADDRESS, 0xd021 );
    }

    cpc_flash_begin( _environment, idx->realName, reg!=NULL?reg->realName:NULL );

    int i = 0;

    while( i < _environment->flashVarsIndex ) {
        Variable * timer = variable_retrieve_or_define( _environment, _environment->flashVars[i], VT_BYTE, 0 );
        ++i;
        if ( !timer ) {
            break;
        }
        Variable * color = variable_retrieve_or_define( _environment, _environment->flashVars[i], VT_COLOR, COLOR_BLACK );
        if ( !color ) {
            break;
        }
        ++i;
        cpc_flash_register( _environment, idx->realName, timer->realName, color->realName );
    }

    cpc_flash_end( _environment );

}

#endif