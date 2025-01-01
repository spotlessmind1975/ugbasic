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

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Return the absolute value of a variable
 * 
 * @param _environment Current calling environment
 * @param _value Value to calculate the absolute value
 * @return Variable* The absolute value
 */
/* <usermanual>
@keyword ABS

@english

The ''ABS'' command is a mathematical function that returns the absolute value 
of a number. In essence, it removes the negative sign from a number, always 
returning a positive or zero value. The parameter ''expression'' is the value whose 
absolute value you want to calculate. This can be a constant numeric value, 
a variable, or a mathematical expression.

The ''ABS'' command is very useful in several situations.  When calculating 
the distance between two points, the absolute value ensures that the distance
is always positive, regardless of the order in which you consider the points.
You can use ''ABS'' inside conditions to test whether a value is greater 
than or less than a certain threshold, ignoring the sign. In many applications, 
you need to work with absolute values to avoid errors or unexpected results.

The ''ABS'' command can be applied only to integers.

@italian
Il comando ''ABS'' è una funzione matematica che restituisce il valore assoluto 
di un numero. In sostanza, rimuove il segno negativo da un numero, restituendo 
sempre un valore positivo o zero. Il parametro ''expression'' è il valore di cui 
si desidera calcolare il valore assoluto. Può essere un valore numerico costante,
una variabile o un'espressione matematica.

Il comando ''ABS'' è molto utile in diverse situazioni. Quando si calcola la 
distanza tra due punti, il valore assoluto assicura che la distanza sia 
sempre positiva, indipendentemente dall'ordine in cui si considerano i punti. 
È possibile utilizzare ''ABS'' all'interno delle condizioni per verificare se
un valore è maggiore o minore di una certa soglia, ignorando il segno. 
In molte applicazioni, è necessario lavorare con valori assoluti per evitare 
errori o risultati imprevisti.

Il comando ''ABS'' può essere usato solo con valori interi.

@syntax = ABS(expression)

@example ' Calculate the distance between two abscissa
@example distance = ABS(x1 - x2)

@usedInExample maths_abs_01.bas
@usedInExample contrib_if_test_speed.bas

@target all
</usermanual> */
Variable * absolute( Environment * _environment, char * _value ) {
    Variable * value = variable_retrieve( _environment, _value );

    Variable * result = variable_temporary( _environment, VT_UNSIGN( value->type ), "(result of ABS)");

    MAKE_LABEL

    char positiveLabel[MAX_TEMPORARY_STORAGE]; sprintf(positiveLabel, "%spos", label );
    char negativeLabel[MAX_TEMPORARY_STORAGE]; sprintf(negativeLabel, "%snev", label );
    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label );

    switch( VT_BITWIDTH( value->type ) ) {
        case 32:
            if ( VT_SIGNED( value->type ) ) {

                #if CPU_BIG_ENDIAN
                    cpu_less_than_and_branch_8bit_const( _environment, value->realName, 0x80, positiveLabel, 0, 0 );
                #else
                    cpu_less_than_and_branch_8bit_const( _environment, address_displacement( _environment, value->realName, "3" ), 0x80, positiveLabel, 0, 0 );
                #endif

                cpu_label( _environment, negativeLabel );
                cpu_complement2_32bit( _environment, value->realName, result->realName );
                cpu_jump( _environment, endLabel );

                cpu_label( _environment, positiveLabel );
                variable_move( _environment, value->name, result->name );
                cpu_label( _environment, endLabel );

            } else {
                variable_move( _environment, value->name, result->name );
            }
            break;
        case 16:
            if ( VT_SIGNED( value->type ) ) {
                Variable * compareResult = variable_temporary( _environment, VT_SBYTE, "(result of ABS)");

                #if CPU_BIG_ENDIAN
                    cpu_less_than_and_branch_8bit_const( _environment, value->realName, 0x80, positiveLabel, 0, 0 );
                #else
                    cpu_less_than_and_branch_8bit_const( _environment, address_displacement( _environment, value->realName, "1" ), 0x80, positiveLabel, 0, 0 );
                #endif

                cpu_label( _environment, negativeLabel );
                cpu_complement2_16bit( _environment, value->realName, result->realName );
                cpu_jump( _environment, endLabel );

                cpu_label( _environment, positiveLabel );
                variable_move( _environment, value->name, result->name );
                cpu_label( _environment, endLabel );

            } else {
                variable_move( _environment, value->name, result->name );
            }
            break;
        case 8:
            if ( VT_SIGNED( value->type ) ) {
                Variable * compareResult = variable_temporary( _environment, VT_SBYTE, "(result of ABS)");

                cpu_less_than_and_branch_8bit_const( _environment, value->realName, 0x80, positiveLabel, 0, 0 );

                cpu_label( _environment, negativeLabel );
                cpu_complement2_8bit( _environment, value->realName, result->realName );
                cpu_jump( _environment, endLabel );

                cpu_label( _environment, positiveLabel );
                variable_move( _environment, value->name, result->name );
                cpu_label( _environment, endLabel );

            } else {
                variable_move( _environment, value->name, result->name );
            }
            break;
        case 0:
            CRITICAL_ABS_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type] );
            break;
    }

    return result;
}

