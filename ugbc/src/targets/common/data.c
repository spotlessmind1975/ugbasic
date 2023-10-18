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

void data_numeric( Environment * _environment, int _value ) {

    VariableType type = variable_type_from_numeric_value( _environment, _value );

    int bytes = VT_BITWIDTH( type ) >> 3;

    DataSegment * data;

    if ( _environment->lastDefinedLabel ) {
        data = data_segment_define_or_retrieve( _environment, _environment->lastDefinedLabel );
    } else {
        data = data_segment_define_or_retrieve( _environment, "DATA" );
    }

    if ( !data->dataBuffer ) {
        data->dataBuffer = malloc( 1 + bytes );
    } else {
        data->dataBuffer = realloc( data->dataBuffer, data->size + 1 + bytes );
    }

    *(data->dataBuffer + data->size) = type;
    memcpy( data->dataBuffer + data->size + 1, &_value, bytes );
    data->size += ( 1 + bytes );

}

void data_floating( Environment * _environment, double _value ) {

    VariableType type = VT_FLOAT;

    int bytes = VT_FLOAT_BITWIDTH( _environment->floatType.precision ) >> 3;

    DataSegment * data;

    if ( _environment->lastDefinedLabel ) {
        data = data_segment_define_or_retrieve( _environment, _environment->lastDefinedLabel );
    } else {
        data = data_segment_define_or_retrieve( _environment, "DATA" );
    }

    int result[32];
    cpu_float_single_from_double_to_int_array( _environment, _value, result );

    if ( !data->dataBuffer ) {
        data->dataBuffer = malloc( 2 + bytes );
    } else {
        data->dataBuffer = realloc( data->dataBuffer, data->size + 2 + bytes );
    }

    *(data->dataBuffer + data->size) = type;
    *(data->dataBuffer + data->size + 1) = _environment->floatType.precision;
    for( int i=0; i<bytes; ++i ) {
        *(data->dataBuffer + data->size + 2 + i) = (char)(result[i] & 0xff );
    }
    data->size += ( 2 + bytes );

}

void data_string( Environment * _environment, char * _value ) {

    VariableType type = VT_STRING;

    int bytes = strlen( _value );

    DataSegment * data;

    if ( _environment->lastDefinedLabel ) {
        data = data_segment_define_or_retrieve( _environment, _environment->lastDefinedLabel );
    } else {
        data = data_segment_define_or_retrieve( _environment, "DATA" );
    }

    if ( !data->dataBuffer ) {
        data->dataBuffer = malloc( 2 + bytes );
    } else {
        data->dataBuffer = realloc( data->dataBuffer, data->size + 2 + bytes );
    }

    *(data->dataBuffer + data->size) = type;
    *(data->dataBuffer + data->size + 1) = bytes;
    memcpy( data->dataBuffer + data->size + 1, _value, bytes );
    data->size += ( 2 + bytes );

}
