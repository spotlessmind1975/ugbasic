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

/**
 * @brief Emit code for <strong>TAB$</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword TICKS PER SECOND

@english
The ''TICKS PER SECOND'' returns the number of ticks per second that can 
be detected using the ''TIMER'' keyword. Note that this value is calculated 
dynamically at the start of the program, and is therefore no longer modified. 
However, because there may be versions of the same hardware running at 
different frequencies, the value cannot be used as a compile-time constant.

@italian
La funzione ''TICKS PER SECOND'' ritorna il numero di tick per secondo che 
si possono rilevare utilizzando la parola chiave ''TIMER''. Da notare che questo 
valore è calcolato dinamicamente alla partenza del programma, e non viene quindi
più modificato. Tuttavia, poiché possono esistere versioni dello stesso hardware
che funzionano a frequenze diverse, il valore non può essere usato come costante
al momento della compilazione.

@syntax = TICKS PER SECOND

@example PRINT TICKS PER SECOND

@usedInExample contrib_calibration.bas

@target all
</usermanual> */
Variable * get_ticks_per_second( Environment * _environment ) {
    
    Variable * ticks_per_second = variable_temporary( _environment, VT_BYTE, "(ticks per second)" );

    cpu_move_8bit( _environment, "TICKSPERSECOND", ticks_per_second->realName );
    
    return ticks_per_second;

}
