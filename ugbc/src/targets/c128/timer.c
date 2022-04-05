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

/**
 * @brief Emit code for <strong>= TI</strong>
 * 
 * Emit code to measure the current value of 60th/50th seconds passed.
 * 
 * @param _environment Current calling environment
 * @return Temporary variable with the number of ticks passed
 */
/* <usermanual>
@keyword TIMER

@english
This variable represents a "timer", which is the number of sixtieths / fiftieths 
of a second that have passed since the machine was turned on. This variable, 
when used as a value, measures the elapsed time. However, it can be set to an 
arbitrary value, such as 0, to measure a defined period of time. 

The refresh rate of this timer depends on the type of video standard used, 
that is, PAL (50Hz) or NTSC (60Hz).

This variable can be abbreviated as ''TI''.

@italian
Questa variable rappresenta un "timer", ovvero il numero di sessantesimi / 
cinquantesimi di secondo che sono passati dall'accensione della macchina. 
Questa variabile, se usata come valore, misura il tempo passato. Può essere 
comunque impostata ad un valore arbitrario, come ad esempio 0, per misurare un 
periodo di tempo definito. 

La frequenza di aggiornamento di questo timer dipende dal tipo di standard 
video utilizzato, ovvero se PAL (50Hz) oppure NTSC (60Hz).

Questa variabile può essere abbreviata come ''TI''.

@syntax = TIMER
@syntax TIMER = [50th/60th seconds]

@example PRINT TIMER

@usedInExample contrib_sierpinski.bas
@usedInExample contrib_sierpinski2.bas
@usedInExample contrib_sierpinski3.bas

@seeAlso TI
@target c128
</usermanual> */
/* <usermanual>
@keyword TI

@english
Alias for ''TIMER''.

@italian
Alias per ''TIMER''.

@seeAlso TIMER
@target all
</usermanual> */
Variable * get_timer( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(result of get timer)");

    char resultAddress[MAX_TEMPORARY_STORAGE]; 
    cpu_move_8bit( _environment, "$A2", result->realName );
    sprintf(resultAddress, "%s+1", result->realName );
    cpu_move_8bit( _environment, "$A1", resultAddress );
    // sprintf(resultAddress, "%s+2", result->realName );
    // cpu_move_8bit( _environment, "$A2", resultAddress );
    
    return result;
    
}

/**
 * @brief Emit code for <strong>TI =</strong>
 * 
 * Emit code to assign the current value of the internal timer.
 * 
 * @param _environment Current calling environment
 * @param _value Time to assign
 */
/* <usermanual>
@keyword TIMER
</usermanual> */

void set_timer( Environment * _environment, char * _value ) {

    Variable * value = variable_retrieve_or_define( _environment, _value, VT_WORD, 0 );

    char valueAddress[MAX_TEMPORARY_STORAGE]; 
    cpu_move_8bit( _environment, value->realName, "$A2" );
    sprintf(valueAddress, "%s+1", value->realName );
    cpu_move_8bit( _environment, valueAddress, "$A1" );
    cpu_move_8bit( _environment, "#0", "$A0" );
        
}
