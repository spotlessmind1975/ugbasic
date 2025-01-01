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
@keyword REMEMBER

@english
The ''REMEMBER'' command restores the cursor position previously stored by 
the ''MEMORIZE'' command. The ''REMEMBER'' command can be executed multiple
times, and this will restore the cursor position to the last stored position. 
Note that the stored position refers to the current console. If there are no 
consoles defined, one equal to full screen will be defined.

@italian
Il comando ''REMEMBER'' ripristina la posizione del cursore precedentemente 
memorizzata dal comando ''MEMORIZE''. Il comando ''REMEMBER'' può essere 
eseguito più volte, e questo ripristinerà la posizione del cursore alla 
posizione memorizzata per ultima. Da notare che la posizione memorizzata 
è riferita alla console attuale. Se non vi sono console definite, ne 
sarà definita una pari allo schermo intero.

@syntax REMEMBER

@example REMEMBER

@usedInExample texts_tracking_02.bas

@seeAlso MEMORIZE
@target all
</usermanual> */
void remember( Environment * _environment ) {
    
    MAKE_LABEL

    char doNothingLabel2[MAX_TEMPORARY_STORAGE];
    sprintf( doNothingLabel2, "%sdonothing", label );
    
    cpu_compare_and_branch_8bit_const( _environment, "CONSOLEID", 0xff, doNothingLabel2, 0 );
    console( _environment, 0, 0, _environment->screenTilesWidth - 1, _environment->screenTilesHeight - 1 );
    console_save( _environment, 0 );
    cpu_label( _environment, doNothingLabel2 );

    Variable * xcursys = variable_retrieve( _environment, "XCURSYS" );
    Variable * ycursys = variable_retrieve( _environment, "YCURSYS" );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(consoles)" );
    cpu_addressof_16bit( _environment, "CONSOLES2", address->realName  );

    Variable * actualNumber = variable_temporary( _environment, VT_BYTE, 0 );
    cpu_move_8bit( _environment, "CONSOLEID", actualNumber->realName );
    cpu_math_mul2_const_8bit( _environment, actualNumber->realName, 1, 0 );
    cpu_math_add_16bit_with_8bit( _environment, address->realName, actualNumber->realName, address->realName );

    cpu_move_8bit_indirect2( _environment, address->realName, xcursys->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect2( _environment, address->realName, ycursys->realName );

}
