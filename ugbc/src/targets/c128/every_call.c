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

/* <usermanual>
@keyword EVERY...CALL

@target c128
</usermanual> */
void every_ticks_call( Environment * _environment, char * _timing, char * _label ) {

    Variable * timing = variable_retrieve( _environment, _timing );

    Variable * zero = variable_temporary( _environment, timing->type, "(zero)" );
    variable_store( _environment, zero->name, 0 );

    _environment->everyStatus = variable_retrieve( _environment, "EVERYSTATUS");
    _environment->everyStatus->locked = 1;
    _environment->everyCounter = variable_temporary( _environment, timing->type, "(every counter)");
    _environment->everyCounter->locked = 1;
    _environment->everyTiming = timing;
    _environment->everyTiming->locked = 1;

    variable_move_naked( _environment, _environment->everyTiming->name, _environment->everyCounter->name );

    char skipEveryRoutineLabel[MAX_TEMPORARY_STORAGE]; sprintf(skipEveryRoutineLabel, "setg%d", UNIQUE_ID );
    char everyRoutineLabel[MAX_TEMPORARY_STORAGE]; sprintf(everyRoutineLabel, "etg%d", UNIQUE_ID );
    char endOfEveryRoutineLabel[MAX_TEMPORARY_STORAGE]; sprintf(endOfEveryRoutineLabel, "eetg%d", UNIQUE_ID );
    
    cpu_jump( _environment, skipEveryRoutineLabel );
    
    cpu_label( _environment, everyRoutineLabel );
    
    cpu_di( _environment );
    
    outline0("PHA");
    outline0("TXA");
    outline0("PHA");
    outline0("TYA");
    outline0("PHA");

    cpu_bveq( _environment, _environment->everyStatus->realName, endOfEveryRoutineLabel );

    variable_decrement( _environment, _environment->everyCounter->name );

    cpu_bvneq( _environment, variable_compare_not( _environment, _environment->everyCounter->name, zero->name )->realName, endOfEveryRoutineLabel );

    call_procedure( _environment, _label );

    variable_move_naked( _environment, _environment->everyTiming->name, _environment->everyCounter->name );

    cpu_label( _environment, endOfEveryRoutineLabel );

    outline0("PLA");
    outline0("TAY");
    outline0("PLA");
    outline0("TAX");
    outline0("PLA");

    cpu_ei( _environment );

    vic2_next_raster( _environment );

    cpu_label( _environment, skipEveryRoutineLabel );

    vic2_raster_at( _environment, everyRoutineLabel, "#0", "#42" );

}
