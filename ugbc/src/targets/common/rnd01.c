/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Return a random value 
 * 
 * @param _environment Current calling environment
 * @param _value Maximum value for the random value
 * @return Variable* The random value
 */
/* <usermanual>
@keyword RND(0)

@english
The function ''RND(0)'' generates pseudo random floating point numbers in the range of 0.0 (inclusive) 
to 1.0 (exclusive). By using ''RND(0)'', it gives a different random number each time from a 
predetermined sequence (the sequence number is stored internally).

@italian
La funzione ''RND(0)'' genera numeri in virgola mobile pseudocasuali nell'intervallo da 0,0 (incluso)
a 1,0 (escluso). Utilizzando ''RND(0)'', viene fornito ogni volta un numero casuale diverso da una 
sequenza predeterminata (il numero di sequenza è memorizzato internamente).

@syntax RND(0)

@example value = 42.0 * RND(0)

@usedInExample tsb_block_rec_01.bas

@target all
</usermanual> */
Variable * rnd0( Environment * _environment ) {

    MAKE_LABEL

    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label );
    char lastRandomLabel[MAX_TEMPORARY_STORAGE]; sprintf(lastRandomLabel, "%slr", label );

    Variable * maxValue = variable_temporary( _environment, VT_WORD, "(maxValue)");
    variable_store( _environment, maxValue->name, 0x7fff );
    Variable * maxValueFloat = variable_cast( _environment, maxValue->name, VT_FLOAT );
    Variable * randomNumberInteger = variable_and_const( _environment, random_value( _environment, VT_WORD )->name, 0x7fff );
    Variable * randomNumberFloat = variable_cast( _environment, randomNumberInteger->name, VT_FLOAT );
    Variable * result = variable_div( _environment, randomNumberFloat->name, maxValueFloat->name, NULL );
    
    return result;

}

/* <usermanual>
@keyword RND(1)

@english
The function ''RND(1)'' generates pseudo random floating point numbers in the range of 0.0 (inclusive) 
to 1.0 (exclusive). By using ''RND(1)'', it gives a different random number each time from a 
predetermined sequence (the sequence number is stored internally).

@italian
La funzione ''RND(1)'' genera numeri in virgola mobile pseudocasuali nell'intervallo da 0,0 (incluso)
a 1,0 (escluso). Utilizzando ''RND(1)'', viene fornito ogni volta un numero casuale diverso da una 
sequenza predeterminata (il numero di sequenza è memorizzato internamente).

@syntax RND(1)

@example value = 42.0 * RND(1)

@usedInExample tsb_block_rec_01.bas

@target all
</usermanual> */
Variable * rnd1( Environment * _environment ) {

    MAKE_LABEL

    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label );
    char lastRandomLabel[MAX_TEMPORARY_STORAGE]; sprintf(lastRandomLabel, "%slr", label );

    Variable * maxValue = variable_temporary( _environment, VT_WORD, "(maxValue)");
    variable_store( _environment, maxValue->name, 0x7fff );
    Variable * maxValueFloat = variable_cast( _environment, maxValue->name, VT_FLOAT );
    Variable * randomNumberInteger = variable_and_const( _environment, random_value( _environment, VT_WORD )->name, 0x7fff );
    Variable * randomNumberFloat = variable_cast( _environment, randomNumberInteger->name, VT_FLOAT );
    Variable * result = variable_div( _environment, randomNumberFloat->name, maxValueFloat->name, NULL );
    
    return result;
    
}