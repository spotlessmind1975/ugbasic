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

/* <usermanual>
@keyword MEMORIZE

@english
The ''MEMORIZE'' command allows you to store the current position of the cursor, 
in terms of coordinates, relative to the current console. The cursor coordinates
can be restored with the ''REMEMBER'' command. Note that the two commands operate on 
the current console. If there are no consoles defined, using this method implicitly 
defines ''CONSOLE 0'' as the entire screen.

@italian
Il comando ''MEMORIZE'' permette di memorizzare l'attuale posizione del cursore, 
in termini di coordinate, relativo alla console attuale. Le coordinate del cursorse
possono essere ripristinate con il comando ''REMEMBER''. Da notare che i due comandi
operano sulla console attuale. Se non vi sono console definite, usare questo metodo
definisce in modo implicito la ''CONSOLE 0''.

@syntax MEMORIZE

@example MEMORIZE

@usedInExample texts_tracking_02.bas

@seeAlso REMEMBER
</usermanual> */

void memorize( Environment * _environment ) {

    MAKE_LABEL

    char doNothingLabel2[MAX_TEMPORARY_STORAGE];
    sprintf( doNothingLabel2, "%sdonothing", label );
    
    cpu_compare_and_branch_8bit_const( _environment, "CONSOLEID", 0xff, doNothingLabel2, 0 );
    // console( _environment, 0, 0, _environment->screenTilesWidth - 1, _environment->screenTilesHeight - 1 );
    // console_save( _environment, 0 );
    cpu_store_8bit( _environment, "CONSOLEID", 0 );
    cpu_label( _environment, doNothingLabel2 );

    Variable * xcursys = variable_retrieve( _environment, "XCURSYS" );
    Variable * ycursys = variable_retrieve( _environment, "YCURSYS" );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(consoles)" );
    cpu_addressof_16bit( _environment, "CONSOLES2", address->realName  );

    Variable * displacement = variable_temporary( _environment, VT_BYTE, "(displacement)" );

    cpu_move_8bit( _environment, "CONSOLEID", displacement->realName );
    cpu_math_mul2_const_8bit( _environment, displacement->realName, 1, 0 );
    cpu_math_add_16bit_with_8bit( _environment, address->realName, displacement->realName, address->realName );

    cpu_move_8bit_indirect( _environment, xcursys->realName, address->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect( _environment, ycursys->realName, address->realName );

}
