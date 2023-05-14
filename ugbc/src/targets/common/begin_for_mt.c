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

void begin_for_mt( Environment * _environment, char * _index, char * _from, char * _to ) {

    Variable * index = variable_retrieve( _environment, _index );

    if ( index->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( index->name );
    }

    Variable * from = variable_retrieve( _environment, _from );
    Variable * to = variable_retrieve( _environment, _to );
    Variable * step = variable_resident( _environment, index->arrayType, "(step 1)" );

    Variable * toResident = variable_resident( _environment, index->arrayType, "(resident to)" );
    variable_move( _environment, to->name, toResident->name );
    
    variable_store( _environment, step->name, 1 );
    
    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    memset( loop, 0, sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_FOR_MT;
    loop->next = _environment->loops;
    loop->index = index;
    loop->index->locked = 1;
    loop->step = step;
    loop->step->locked = 1;
    loop->to = toResident;
    loop->to->locked = 1;
    _environment->loops = loop;

    ++((struct _Environment *)_environment)->arrayNestedIndex;
    memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
    ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
    ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    Variable * array = variable_retrieve( _environment, index->name );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( index->name );
    }
    variable_move_array( _environment, index->name, from->name );
    --((struct _Environment *)_environment)->arrayNestedIndex;
        
    unsigned char beginFor[MAX_TEMPORARY_STORAGE]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char endFor[MAX_TEMPORARY_STORAGE]; sprintf(endFor, "%sbis", loop->label );

    cpu_label( _environment, beginFor );

    ++((struct _Environment *)_environment)->arrayNestedIndex;
    memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
    ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
    ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    array = variable_retrieve_or_define( _environment, index->name, VT_ARRAY, 0 );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( index->name );
    }
    Variable * value = variable_move_from_array( _environment, index->name );
    --((struct _Environment *)_environment)->arrayNestedIndex;

    Variable * isLastStep = variable_greater_than( _environment, value->name, loop->to->name, 0 );

    cpu_bvneq( _environment, isLastStep->realName, endFor );

}