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

#if defined(__c64__) || defined(__c64reu__) || defined(__c128__)

/**
 * @brief Emit code for <strong>SPRITE(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _image image to use as SPRITE
 */
Variable * msprite_duplicate( Environment * _environment, char * _original ) {

    if ( _environment->deployed.sprite ) {
        CRITICAL_CANNOT_MIX_SPRITES_MSPRITES();
    }

    Variable * index;
    Variable * startIndex;
    Variable * spriteCount;
    Variable * original = variable_retrieve( _environment, _original );   
    Variable * result = variable_temporary( _environment, VT_MSPRITE, "(sprite index)" );   

    index = variable_temporary( _environment, VT_MSPRITE, "(sprite index)" );   
    spriteCount = variable_retrieve( _environment, "SPRITECOUNT" );
    startIndex = variable_temporary( _environment, VT_MSPRITE, "(sprite index)" );

    cpu_move_8bit( _environment, spriteCount->realName, result->realName );
    cpu_move_8bit( _environment, address_displacement( _environment, original->realName, "1" ), address_displacement( _environment, result->realName, "1" ) );

    vic2_sprite_duplicate( _environment, result->name, original->name );

    return result;

}

#endif