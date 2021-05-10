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

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Emit code to raise a variable to a given variable
 * 
 * This function allows you to emit a code that raise a variable
 * to a given variable.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @return Variable* The result of calculation
 */
Variable * powering( Environment * _environment, char * _source, char * _destination ) {

    Variable * source = variable_retrieve( _environment, _source );

    Variable * target = variable_cast( _environment, _destination, source->type );
    if ( ! target ) {
        CRITICAL_VARIABLE(_destination);
    }

    Variable * result;

    if ( source->type == VT_DWORD || target->type == VT_DWORD ) {
        CRITICAL_POW_UNSUPPORTED( _source, DATATYPE_AS_STRING[source->type]);
    }

    if ( source->type == VT_STRING || target->type == VT_STRING ) {
        CRITICAL_POW_UNSUPPORTED( _source, DATATYPE_AS_STRING[source->type]);
    }

    if ( source->type == VT_BUFFER || target->type == VT_BUFFER ) {
        CRITICAL_POW_UNSUPPORTED( _source, DATATYPE_AS_STRING[source->type]);
    }

    MAKE_LABEL

    char endLabel[16]; sprintf(endLabel, "%send", label);

    Variable * counter = variable_cast( _environment, target->name, VT_BYTE );
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
        case 16:
            result = variable_temporary( _environment, VT_DWORD, "(result of pow)");
            variable_store( _environment, result->name, 1 );
            cpu_bveq( _environment, counter->realName, endLabel );
            cpu_label( _environment, label );
            cpu_math_mul_16bit_to_32bit( _environment, source->realName, result->realName, result->realName );
            cpu_dec( _environment, counter->realName );
            cpu_bvneq( _environment, counter->realName, label );
            cpu_label( _environment, endLabel );
            break;
        case 8:
            result = variable_temporary( _environment, VT_DWORD, "(result of pow)");
            variable_store( _environment, result->name, 1 );
            cpu_bveq( _environment, counter->realName, endLabel );
            cpu_label( _environment, label );
            cpu_math_mul_8bit_to_16bit( _environment, source->realName, result->realName, result->realName );
            cpu_dec( _environment, counter->realName );
            cpu_bvneq( _environment, counter->realName, label );
            cpu_label( _environment, endLabel );
            break;
    }
    return result;
}