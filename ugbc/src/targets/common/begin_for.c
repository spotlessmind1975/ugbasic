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
 * @brief Emit ASM code for <b>FOR ...</b>
 * 
 * This function outputs the code to implement the starting
 * point of a FOR...NEXT loop
 * 
 * @param _environment Current calling environment
 * @param _index Variable to use as index
 * @param _from Starting value
 * @param _to Ending value
 */
/* <usermanual>
@keyword FOR...NEXT

@english
This instruction implements a loop with explicit number of times to repeat.
Each ''FOR'' statement must be matched by a single ''NEXT'', and pairs of ''FOR...NEXT'' 
loops can be nested inside one another. Each loop repeats a list of 
instructions for a specific number of times, governed by an index which 
counts the number of times the loop is repeated. Once inside the loop, 
this index can be read by the program as if it is a normal variable.

@italian
Questa istruzione implementa un ciclo con un numero di ripetizioni indicato
esplicitamente. Ogni istruzione ''FOR'' deve essere abbinata a una singola
istruzione ''NEXT'' e le coppie di cicli ''FOR...NEXT'' possono essere 
annidate l'una nell'altra. Ogni ciclo ripete un elenco di istruzioni per 
un numero specifico di volte, governato da un indice che conta il numero 
di volte che il ciclo viene ripetuto. Una volta all'interno del ciclo,
questo indice può essere letto dal programma come se fosse una normale variabile.

@syntax FOR [identifier] = [expression] TO [expression] : ... : NEXT

@example i = 0 : FOR i = 1 to 100: PRINT i : NEXT
@usedInExample control_controlled_01.bas
@usedInExample control_controlled_02.bas

@target all
</usermanual> */
void begin_for( Environment * _environment, char * _index, char * _from, char * _to ) {

    Variable * index = NULL;

    Variable * from = variable_retrieve( _environment, _from );
    Variable * to = variable_retrieve( _environment, _to );

    int maxType = VT_MAX_BITWIDTH_TYPE( from->type, to->type );

    Variable * step = variable_resident( _environment, maxType, "(step 1)" );

    if ( variable_exists( _environment, _index ) ) {
        index = variable_retrieve( _environment, _index );
    } else {
        index = variable_retrieve_or_define( _environment, _index, maxType, 0 );
    }

    Variable * toResident = variable_resident( _environment, index->type, "(resident to)" );
    variable_move( _environment, to->name, toResident->name );
    
    variable_store( _environment, step->name, 1 );
    
    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    memset( loop, 0, sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_FOR;
    loop->next = _environment->loops;
    loop->index = index;
    loop->index->locked = 1;
    loop->step = step;
    loop->step->locked = 1;
    loop->to = toResident;
    loop->to->locked = 1;
    _environment->loops = loop;

    variable_move( _environment, from->name, index->name );

    unsigned char beginFor[MAX_TEMPORARY_STORAGE]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char endFor[MAX_TEMPORARY_STORAGE]; sprintf(endFor, "%sbis", loop->label );

    cpu_label( _environment, beginFor );

    Variable * isLastStep = variable_greater_than( _environment, index->name, loop->to->name, 0 );

    cpu_bvneq( _environment, isLastStep->realName, endFor );

}
