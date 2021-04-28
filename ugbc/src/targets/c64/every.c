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

/**
 * @brief Emit ASM code for <b>EVERY ... TICKS GOSUB ...</b>
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _position The vertical position to wait for
 */
/* <usermanual>
@keyword EVERY ... TICKS GOSUB ...

@english

@italian

@syntax EVERY [expression] TICKS GOSUB [label]

@example EVERY period TICKS GOSUB updateGameStatus

@target c64
</usermanual> */
void every_ticks_gosub( Environment * _environment, char * _timing, char * _label ) {

    outline2("; EVERY %s TICKS GOSUB %s", _timing, _label );

    _environment->everyStatus = variable_temporary( _environment, VT_BYTE, "(every status)");
    _environment->everyStatus->locked = 1;

    char skipEveryRoutineLabel[16]; sprintf(skipEveryRoutineLabel, "setg%d", UNIQUE_ID );
    char everyRoutineLabel[16]; sprintf(everyRoutineLabel, "etg%d", UNIQUE_ID );
    char endOfEveryRoutineLabel[16]; sprintf(endOfEveryRoutineLabel, "eetg%d", UNIQUE_ID );
    
    cpu_jump( _environment, skipEveryRoutineLabel );
    
    cpu_label( _environment, everyRoutineLabel );
    
    cpu_bveq( _environment, _environment->everyStatus->realName, endOfEveryRoutineLabel );

    cpu_call( _environment, _label );

    cpu_label( _environment, endOfEveryRoutineLabel );

    vic2_next_raster( _environment );

    vic2_raster_at( _environment, everyRoutineLabel, "0", "0" );

    cpu_label( _environment, skipEveryRoutineLabel );

}

/**
 * @brief Emit ASM code for <b>EVERY ON</b>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword EVERY ON

@english

@italian

@syntax EVERY ON

@example EVERY ON
</usermanual> */
void every_on( Environment * _environment ) {
   
    outline0("; EVERY ON");

    if ( ! _environment->everyStatus ) {
        CRITICAL("EVERY ON without EVERY definition");
    }

    variable_store( _environment, _environment->everyStatus->name, 0xff );

}

/**
 * @brief Emit ASM code for <b>EVERY OFF</b>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword EVERY OFF

@english

@italian

@syntax EVERY OFF

@example EVERY OFF
</usermanual> */
void every_off( Environment * _environment ) {
   
    outline0("; EVERY OFF");

    if ( ! _environment->everyStatus ) {
        CRITICAL("EVERY OFF without EVERY definition");
    }

    variable_store( _environment, _environment->everyStatus->name, 0x0 );

}
