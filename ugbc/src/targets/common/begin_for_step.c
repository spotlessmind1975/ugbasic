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

/**
 * @brief Emit ASM code for <b>FOR ... STEP ... NEXT</b>
 * 
 * This function outputs the code to implement the starting
 * point of a FOR ... STEP ... NEXT loop
 * 
 * @param _environment Current calling environment
 * @param _index Variable to use as index
 * @param _from Starting value
 * @param _to Ending value
 * @param _step Step value
 */
/* <usermanual>
@keyword FOR...NEXT

@english
Normally, the index counter is increased by 1 unit at every turn of a 
''FOR...NEXT'' loop. When the current value exceeds that of the last 
number specified, the loop is terminated. ''STEP'' is used to 
change the size of increase in the index value.

@italian
Normalmente, il contatore dell'indice viene incrementato di uno ad ogni 
ciclo. Quando il valore attuale supera quello dell'ultimo numero specificato, 
il ciclo si intende terminato. L'istruzione ''STEP'' può essere sfruttata
per modificare la dimensione dell'incremento del valore dell'indice.

@syntax FOR [identifier] = [expression] TO [expression] { STEP [expression] } : ... : NEXT

@example i = 0 : FOR i = 1 to 100 STEP 2: PRINT i : NEXT
@usedInExample control_controlled_01.bas
@usedInExample control_controlled_02.bas

@target all
</usermanual> */
void begin_for_step( Environment * _environment, char * _index, char * _from, char * _to, char * _step ) {

    Variable * index = NULL;

    if ( variable_exists( _environment, _index ) ) {
        index = variable_retrieve( _environment, _index );
    } else {
        index = variable_retrieve_or_define( _environment, _index, VT_SWORD, 0 );
    }

    outline1("; index = %s", index->realName );

    Variable * from = variable_retrieve( _environment, _from );
    Variable * to = variable_retrieve( _environment, _to );
    Variable * step = variable_retrieve( _environment, _step );

    Variable * toResident = variable_resident( _environment, to->type, "(resident to)" );
    variable_move_naked( _environment, to->name, toResident->name );

    Variable * stepResident = variable_resident( _environment, step->type, "(resident step)" );
    variable_move_naked( _environment, step->name, stepResident->name );

    Variable * zero = variable_resident( _environment, VT_WORD, "(zero)" );
    variable_store( _environment, zero->name, 0 );

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    memset( loop, 0, sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_FOR;
    loop->next = _environment->loops;
    loop->index = index;
    loop->index->locked = 1;
    loop->step = stepResident;
    loop->step->locked = 1;
    loop->to = toResident;
    loop->to->locked = 1;
    loop->zero = zero;
    loop->zero->locked = 1;
    _environment->loops = loop;

    variable_move( _environment, from->name, index->name );

    unsigned char beginFor[MAX_TEMPORARY_STORAGE]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char endFor[MAX_TEMPORARY_STORAGE]; sprintf(endFor, "%sbis", loop->label );
    unsigned char forwardFor[MAX_TEMPORARY_STORAGE]; sprintf(forwardFor, "%sfor", loop->label );
    unsigned char backwardFor[MAX_TEMPORARY_STORAGE]; sprintf(backwardFor, "%sback", loop->label );
    unsigned char continueFor[MAX_TEMPORARY_STORAGE]; sprintf(continueFor, "%scont", loop->label );

    cpu_label( _environment, beginFor );

    cpu_bvneq( _environment, variable_greater_than( _environment, loop->step->name, zero->name, 0)->realName, forwardFor );

    cpu_jump( _environment, backwardFor );

    cpu_label( _environment, forwardFor );

    cpu_bvneq( _environment, variable_greater_than( _environment, index->name, loop->to->name, 0 )->realName, endFor );

    cpu_jump( _environment, continueFor );

    cpu_label( _environment, backwardFor );

    cpu_bvneq( _environment, variable_less_than( _environment, index->name, loop->to->name, 1 )->realName, endFor );

    cpu_label( _environment, continueFor );

}
