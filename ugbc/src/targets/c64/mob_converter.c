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

Variable * mob_converter( Environment * _environment, char * _data, int _width, int _height, int _mode ) {

    Variable * mob = variable_temporary( _environment, VT_MOB, "(mob)" );

    switch( _mode ) {
        case BITMAP_MODE_STANDARD:
        case BITMAP_MODE_MULTICOLOR:
        case BITMAP_MODE_AH:
        case BITMAP_MODE_AIFLI:
        case BITMAP_MODE_ASSLACE:
        case BITMAP_MODE_ECI:
        case BITMAP_MODE_IAFLI:
        case BITMAP_MODE_IH:
        case BITMAP_MODE_MRFLI:
        case BITMAP_MODE_MUCSUFLI:
        case BITMAP_MODE_MUCSUH:
        case BITMAP_MODE_MUFLI:
        case BITMAP_MODE_MUIFLI:
        case BITMAP_MODE_NUFLI:
        case BITMAP_MODE_NUIFLI:
        case BITMAP_MODE_SH:
        case BITMAP_MODE_SHFLI:
        case BITMAP_MODE_SHI:
        case BITMAP_MODE_SHIFLI:
        case BITMAP_MODE_SHIFXL:
        case BITMAP_MODE_UFLI:
        case BITMAP_MODE_UIFLI:
        case BITMAP_MODE_TRIFLI:
        case BITMAP_MODE_XFLI:
        case BITMAP_MODE_XIFLI:
        case BITMAP_MODE_FLI:
        case BITMAP_MODE_HCB:
        case BITMAP_MODE_IFLI:
        case BITMAP_MODE_MUCSU:
        case BITMAP_MODE_MCI:
        case BITMAP_MODE_MEGATEXT:
        case BITMAP_MODE_PRS:
            CRITICAL_MOB_CONVERTER_UNSUPPORTED_MODE( _mode );

        case TILEMAP_MODE_STANDARD:
        case TILEMAP_MODE_MULTICOLOR:
        case TILEMAP_MODE_EXTENDED:
            CRITICAL_MOB_CONVERTER_UNSUPPORTED_MODE( _mode );
    }

    return mob;

}