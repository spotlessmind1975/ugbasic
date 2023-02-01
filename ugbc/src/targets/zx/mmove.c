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

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Emit ASM code for <b>MMOVE [expr] TO [expr] SIZE [expr]</b>
 * 
 * This function outputs a code that move a tile on a tilemap. 
 * 
 * @param _environment Current calling environment
 * @param _from Source address to move from
 * @param _to Destination address to move to
 * @param _size Size of the memory to move
 */
/* <usermanual>
@keyword MMOVE

@target zx
</usermanual> */
void mmove_memory_memory( Environment * _environment, char * _from, char * _to, char * _size ) {

    Variable * from = variable_retrieve_or_define( _environment, _from, VT_ADDRESS, 0 );
    Variable * to = variable_retrieve_or_define( _environment, _to, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_WORD, 0 );

    if ( VT_BITWIDTH( size->type ) != 16 ) {
        CRITICAL_CANNOT_MMOVE_INVALID_SIZE( _size );
    }

    cpu_mem_move_16bit( _environment, from->realName, to->realName, size->realName );

}

/**
 * @brief Emit ASM code for <b>MMOVE {VIDEO} [expr] TO {VIDEO} [expr] SIZE [expr]</b>
 * 
 * This function outputs a code that move a tile on a tilemap. 
 * 
 * @param _environment Current calling environment
 * @param _from Source address to move from
 * @param _to Destination address to move to
 * @param _size Size of the memory to move
 */
/* <usermanual>
@keyword MMOVE
</usermanual> */
void mmove_memory_video( Environment * _environment, char * _from, char * _to, char * _size ) {

    Variable * from = variable_retrieve_or_define( _environment, _from, VT_ADDRESS, 0 );
    Variable * to = variable_retrieve_or_define( _environment, _to, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_WORD, 0 );

    if ( VT_BITWIDTH( size->type ) != 16 ) {
        CRITICAL_CANNOT_MMOVE_INVALID_SIZE( _size );
    }

    cpu_mem_move_16bit( _environment, from->realName, to->realName, size->realName );

}

/**
 * @brief Emit ASM code for <b>MMOVE {VIDEO} [expr] TO {VIDEO} [expr] SIZE [expr]</b>
 * 
 * This function outputs a code that move a tile on a tilemap. 
 * 
 * @param _environment Current calling environment
 * @param _from Source address to move from
 * @param _to Destination address to move to
 * @param _size Size of the memory to move
 */
/* <usermanual>
@keyword MMOVE
</usermanual> */
void mmove_video_memory( Environment * _environment, char * _from, char * _to, char * _size ) {

    Variable * from = variable_retrieve_or_define( _environment, _from, VT_ADDRESS, 0 );
    Variable * to = variable_retrieve_or_define( _environment, _to, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_WORD, 0 );

    if ( VT_BITWIDTH( size->type ) != 16 ) {
        CRITICAL_CANNOT_MMOVE_INVALID_SIZE( _size );
    }

    cpu_mem_move_16bit( _environment, from->realName, to->realName, size->realName );

}

