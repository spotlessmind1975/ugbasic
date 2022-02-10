/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

@english
This low-level command can be used to move memory blocks at high speed 
between addresses. There are several cases that are covered by this 
command. The simplest is to copy data from one or more CPU memory 
locations (RAM) to another CPU memory location (RAM). This can be 
achieved with the standard version of the command.

If you add the ''VIDEO'' keyword, you can indicate that the memory to copy 
from or to copy to is not in the CPU RAM but in the RAM possibly 
dedicated to the GPU. In this case it is called VRAM.

You cannot move overlapped area or VRAMS together.

@italian
Questo comando a basso livello può essere utilizzato per muovere blocchi 
di memoria ad alta velocità, tra un indirizzo e l'altro. Vi sono diverse 
casistiche che sono coperte da questo comando. La più semplice è quella 
di copiare dati da una o più locazioni di memoria della CPU (RAM) a 
un'altra locazione di memoria della CPU (RAM). Questo lo si può ottenere 
con la versione standard del comando.

Se si aggiunge la parola chiave ''VIDEO'', si può indicare che la memoria da 
cui copiare o in cui copiare si trova non nella RAM della CPU ma nella 
RAM eventualmente dedicata alla GPU. In questo caso prende il nome di VRAM.

Non è possibile copiare aree sovrapposte o due aree video.

@syntax MMOVE {VIDEO} [address] TO {VIDEO} [address] SIZE [size]

@example MMOVE $0000 TO $C000 SIZE 1024
@example MMOVE VIDEO $1800 TO $C000 SIZE 960
@example MMOVE $C000 TO VIDEO $0000 SIZE 2048
@example MMOVE VIDEO $1800 TO VIDEO $0000 SIZE 2048

@target coleco
</usermanual> */
void mmove_memory_memory( Environment * _environment, char * _from, char * _to, char * _size ) {

    Variable * from = variable_retrieve_or_define( _environment, _from, VT_ADDRESS, 0 );
    Variable * to = variable_retrieve_or_define( _environment, _to, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _to, VT_ADDRESS, 0 );

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
    Variable * size = variable_retrieve_or_define( _environment, _to, VT_ADDRESS, 0 );

    if ( VT_BITWIDTH( size->type ) != 16 ) {
        CRITICAL_CANNOT_MMOVE_INVALID_SIZE( _size );
    }

    tms9918_move_memory_video( _environment, from->realName, to->realName, size->realName );

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
    Variable * size = variable_retrieve_or_define( _environment, _to, VT_ADDRESS, 0 );

    if ( VT_BITWIDTH( size->type ) != 16 ) {
        CRITICAL_CANNOT_MMOVE_INVALID_SIZE( _size );
    }

    tms9918_move_video_memory( _environment, from->realName, to->realName, size->realName );

}

