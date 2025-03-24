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

static void read_data_safe( Environment * _environment, char * _variable ) {

    _environment->dataNeeded = 1;

    MAKE_LABEL

    char typeMismatchDuringReadLabel[MAX_TEMPORARY_STORAGE]; sprintf( typeMismatchDuringReadLabel, "%stm", label );
    char doneReadLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneReadLabel, "%sdone", label );
    char completeReadLabel[MAX_TEMPORARY_STORAGE]; sprintf( completeReadLabel, "%scm", label );
    char byteReadLabel[MAX_TEMPORARY_STORAGE]; sprintf( byteReadLabel, "%sby", label );
    char wordReadLabel[MAX_TEMPORARY_STORAGE]; sprintf( wordReadLabel, "%swo", label );
    char dwordReadLabel[MAX_TEMPORARY_STORAGE]; sprintf( dwordReadLabel, "%sdw", label );
    char stringReadLabel[MAX_TEMPORARY_STORAGE]; sprintf( stringReadLabel, "%sst", label );

    Variable * variable = NULL;

    if ( variable_exists( _environment, _variable ) ) {
        variable = variable_retrieve( _environment, _variable );
    } else {
        variable = variable_define( _environment, _variable, _environment->defaultVariableType, 0 );
    }
    Variable * dataptr = variable_retrieve( _environment, "DATAPTR" );
    Variable * dataptre = NULL;
    Variable * datatype = variable_temporary( _environment, VT_BYTE, "(type)" );

    VariableType type = variable->type;

    if ( type == VT_DSTRING ) {
        type = VT_STRING;
    }

    dataptre = variable_temporary( _environment, VT_ADDRESS, "(dataptre)" );
    cpu_addressof_16bit( _environment, "DATAPTRE", dataptre->realName );
    cpu_compare_16bit( _environment, dataptr->realName, dataptre->realName, datatype->realName, 1 );
    cpu_compare_and_branch_8bit_const( _environment, datatype->realName, 0xff, doneReadLabel, 1 );

    cpu_move_8bit_indirect2( _environment, dataptr->realName, datatype->realName );

    cpu_compare_and_branch_8bit_const( _environment, datatype->realName, type, typeMismatchDuringReadLabel, 0 );

    switch( VT_BITWIDTH( variable->type ) ) {
        case 32:
            cpu_inc_16bit( _environment, dataptr->realName );
            cpu_move_32bit_indirect2( _environment, dataptr->realName, variable->realName );
            cpu_inc_16bit( _environment, dataptr->realName );
            cpu_inc_16bit( _environment, dataptr->realName );
            cpu_inc_16bit( _environment, dataptr->realName );
            cpu_inc_16bit( _environment, dataptr->realName );
            break;
        case 16:
            cpu_inc_16bit( _environment, dataptr->realName );
            cpu_move_16bit_indirect2( _environment, dataptr->realName, variable->realName );
            cpu_inc_16bit( _environment, dataptr->realName );
            cpu_inc_16bit( _environment, dataptr->realName );
            break;
        case 8:
            cpu_inc_16bit( _environment, dataptr->realName );
            cpu_move_8bit_indirect2( _environment, dataptr->realName, variable->realName );
            cpu_inc_16bit( _environment, dataptr->realName );
            break;
        case 1:
            CRITICAL_READ_DATA_TYPE_NOT_SUPPORTED( _variable, DATATYPE_AS_STRING[variable->type] );
            break;
        case 0:
            switch( variable->type ) {
                case VT_DSTRING: {
                    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
                    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );
                    cpu_inc_16bit( _environment, dataptr->realName );
                    cpu_move_8bit_indirect2( _environment, dataptr->realName, size->realName );
                    cpu_inc_16bit( _environment, dataptr->realName );
                    cpu_dsfree( _environment, variable->realName );
                    cpu_dsalloc( _environment, size->realName, variable->realName );
                    cpu_dsdescriptor( _environment, variable->realName, address->realName, size->realName );
                    cpu_mem_move( _environment, dataptr->realName, address->realName, size->realName );
                    cpu_math_add_16bit_with_8bit( _environment, dataptr->realName, size->realName, dataptr->realName );
                    break;
                }
                case VT_TYPE: {
                    Field * field = variable->typeType->first;
                    while( field ) {
                        Variable * data = variable_temporary( _environment, field->type, "(data)");
                        read_data_safe( _environment, data->name );
                        variable_move_type( _environment, variable->name, field->name, data->name );
                        field = field->next;
                    }
                    break;
                }
                default:
                    CRITICAL_READ_DATA_TYPE_NOT_SUPPORTED( _variable, DATATYPE_AS_STRING[variable->type] );
            }
            break;
    }

    cpu_jump( _environment, doneReadLabel );

    cpu_label( _environment, typeMismatchDuringReadLabel );

    if ( variable->type != VT_DSTRING && variable->type != VT_TYPE ) {

        cpu_compare_and_branch_8bit_const( _environment, datatype->realName, VT_BYTE, byteReadLabel, 1 );
        cpu_compare_and_branch_8bit_const( _environment, datatype->realName, VT_SBYTE, byteReadLabel, 1 );

        cpu_compare_and_branch_8bit_const( _environment, datatype->realName, VT_WORD, wordReadLabel, 1 );
        cpu_compare_and_branch_8bit_const( _environment, datatype->realName, VT_SWORD, wordReadLabel, 1 );

        cpu_compare_and_branch_8bit_const( _environment, datatype->realName, VT_DWORD, dwordReadLabel, 1 );
        cpu_compare_and_branch_8bit_const( _environment, datatype->realName, VT_SDWORD, dwordReadLabel, 1 );

        cpu_compare_and_branch_8bit_const( _environment, datatype->realName, VT_STRING, stringReadLabel, 1 );

        cpu_jump( _environment, doneReadLabel );

        cpu_label( _environment, dwordReadLabel );

        Variable * data32 = variable_temporary( _environment, VT_SIGNED( variable->type ) ? VT_SDWORD : VT_DWORD, "(data)" );

        cpu_inc_16bit( _environment, dataptr->realName );
        cpu_move_32bit_indirect2( _environment, dataptr->realName, data32->realName );
        cpu_inc_16bit( _environment, dataptr->realName );
        cpu_inc_16bit( _environment, dataptr->realName );
        cpu_inc_16bit( _environment, dataptr->realName );
        cpu_inc_16bit( _environment, dataptr->realName );

        variable_move( _environment, data32->name, variable->name );

        cpu_jump( _environment, completeReadLabel );

        cpu_label( _environment, wordReadLabel );

        Variable * data16 = variable_temporary( _environment, VT_SIGNED( variable->type ) ? VT_SWORD : VT_WORD, "(data)" );

        cpu_inc_16bit( _environment, dataptr->realName );
        cpu_move_16bit_indirect2( _environment, dataptr->realName, data16->realName );
        cpu_inc_16bit( _environment, dataptr->realName );
        cpu_inc_16bit( _environment, dataptr->realName );

        variable_move( _environment, data16->name, variable->name );

        cpu_jump( _environment, completeReadLabel );

        cpu_label( _environment, byteReadLabel );

        Variable * data8 = variable_temporary( _environment, VT_SIGNED( variable->type ) ? VT_SBYTE : VT_BYTE, "(data)" );

        cpu_inc_16bit( _environment, dataptr->realName );
        cpu_move_8bit_indirect2( _environment, dataptr->realName, data8->realName );
        cpu_inc_16bit( _environment, dataptr->realName );

        variable_move( _environment, data8->name, variable->name );

        cpu_jump( _environment, completeReadLabel );

        cpu_label( _environment, stringReadLabel );
        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
        Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );
        cpu_inc_16bit( _environment, dataptr->realName );
        cpu_move_8bit_indirect2( _environment, dataptr->realName, size->realName );
        cpu_inc_16bit( _environment, dataptr->realName );
        cpu_dsfree( _environment, variable->realName );
        cpu_dsalloc( _environment, size->realName, variable->realName );
        cpu_dsdescriptor( _environment, variable->realName, address->realName, size->realName );
        cpu_mem_move( _environment, dataptr->realName, address->realName, size->realName );
        cpu_math_add_16bit_with_8bit( _environment, dataptr->realName, size->realName, dataptr->realName );
        cpu_jump( _environment, doneReadLabel );

        cpu_label( _environment, completeReadLabel );

    }

    cpu_label( _environment, doneReadLabel );

}

static void read_data_unsafe_common( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    Variable * variable;
    if ( variable_exists( _environment, _variable ) ) {
        variable = variable_retrieve( _environment, _variable );
    } else {
        variable = variable_define( _environment, _variable, _environment->defaultVariableType, 0 );
    }

    read_data_unsafe( _environment, _variable );

}

/**
 * @brief Emit code for <strong>READ</strong> instruction
 * 
 * @param _environment Current calling environment
 * @param _variable Variable to store to
 */
/* <usermanual>
@keyword READ

@english

The ''READ'' is used for reading constant values from ''DATA'' lines into the
given variables. This command is able to read more constants at once with a 
variable list separated by commas.

If using the wrong type of variable (for example read a character string into a
numerical variable like float or integer), the variable will be untouched.
Such behavior can be prevented by generally using a variable of the same type
like the ''DATA AS'' used.

With a value that falls outside the expected range of a ''READ'' variable, 
e.g. the value is outside the range of an integer, ugBASIC will implicitly
convert it, with a precision lost, but only if ''SAFE'' keyword is used. 
If more constants are read than values
exist in ''DATA'' lines, garbare will be read. It can be avoided by using
''SAFE'' keyword or using ''READ END'' function. Using ''SAFE'' the
variable will not be touched if last value is already read.

A succeeding ''READ'' searches for the first ''DATA'' statement where the
''DATA'' read pointer is adjusted to.

@italian

Il comando ''READ'' viene utilizzato per leggere valori costanti dalle righe ''DATA'' 
nelle variabili indicate. Questo comando è in grado di leggere più costanti 
contemporaneamente con un elenco di variabili separate da virgole.

Se si utilizza il tipo sbagliato di variabile (ad esempio leggere una stringa di caratteri
in una variabile numerica come float o intero), la variabile non verrà modificata. 
Tale comportamento può essere evitato utilizzando generalmente una variabile dello stesso 
tipo di quello indicato nel ''DATA AS''.

Con un valore che non rientra nell'intervallo previsto di una variabile ''READ'', ad es.
il valore non è compreso nell'intervallo di un numero intero, ugBASIC lo convertirà 
implicitamente, perdendo precisione, ma solo se si usa la parola chiave ''SAFE''. 
Se vengono lette più costanti di quanti siano i
valori presenti nelle righe ''DATA'', verranno lette. Può essere evitato utilizzando la
parola chiave ''SAFE'' o utilizzando la funzione ''READ END''. Utilizzando ''SAFE'' 
la variabile non verrà toccata se l'ultimo valore è stato già letto.

Un ''READ'' successivo cerca la prima istruzione ''DATA'' su cui è regolato il puntatore di
lettura di ''DATA''.

@syntax READ var

@example READ nextStep

@usedInExample data_example_01.bas
@usedInExample data_example_02.bas
@usedInExample data_example_03.bas

@target all
@verified
</usermanual> */
void read_data( Environment * _environment, char * _variable, int _safe ) {

    _environment->readDataUsed = 1;

    if ( _safe ) {
        read_data_safe( _environment, _variable );
    } else {
        read_data_unsafe_common( _environment, _variable );
    }

}

