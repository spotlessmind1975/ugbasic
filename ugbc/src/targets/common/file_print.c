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

extern char DATATYPE_AS_STRING[][16];

void file_print_string( Environment * _environment, char * _number, char * _string ) {

    Variable * number = variable_retrieve_or_define( _environment, _number, VT_BYTE, 0 );

    Variable * string = variable_retrieve( _environment, _string );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(text address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(text size)" );

    switch( string->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, string->realName, size->realName );
            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            break;
        case VT_CHAR:
            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_store_8bit( _environment, size->realName, 1 );
            break;
    }

    file_write( _environment, number->name, address->name, size->name );

}

void file_print( Environment * _environment, char * _number, char * _value, int _new_line ) {

    Variable * number = variable_retrieve_or_define( _environment, _number, VT_BYTE, 0 );
    Variable * value = variable_retrieve_or_define( _environment, _value, VT_DSTRING, 0 );
    
    if ( value->type != VT_DSTRING && value->type != VT_STRING && value->type != VT_CHAR ) {
        switch( VT_BITWIDTH( value->type ) ) {
            case 32:
            case 16:
            case 8: {
                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary for PRINT)");
                Variable * size = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");
                Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                variable_store_string( _environment, tmp->name, "          " );

                cpu_dswrite( _environment, tmp->realName );

                cpu_dsdescriptor( _environment, tmp->realName, address->realName, size->realName );

                cpu_number_to_string( _environment, value->realName, address->realName, size->realName, VT_BITWIDTH( value->type ), VT_SIGNED( value->type ) );

                cpu_dsresize( _environment, tmp->realName, size->realName );

                value = tmp;
                
                break;
            }
            case 1: {
                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary for PRINT)");
                Variable * size = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");
                Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                Variable * bcheck = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");
                Variable * zero = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");
                Variable * one = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");

                cpu_store_8bit( _environment, zero->realName, '0' );
                cpu_store_8bit( _environment, one->realName, '1' );

                variable_store_string( _environment, tmp->name, " " );
                cpu_dswrite( _environment, tmp->realName );
                cpu_dsdescriptor( _environment, tmp->realName, address->realName, size->realName );

                MAKE_LABEL

                char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneLabel, "%sdone", label );

                outline0(" ; printing bit..." );
                cpu_bit_check( _environment, value->realName, value->bitPosition, bcheck->realName, 8 );
                cpu_compare_and_branch_8bit_const( _environment, bcheck->realName, 0, label, 1 );
                cpu_move_8bit_indirect( _environment, one->realName, address->realName );
                cpu_jump( _environment, doneLabel );
                cpu_label( _environment, label );
                cpu_move_8bit_indirect( _environment, zero->realName, address->realName );
                cpu_label( _environment, doneLabel );

                value = tmp;
                
                break;
            }
            case 0:
                switch( value->type ) {
                    case VT_FLOAT: {
                        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary for PRINT)");
                        Variable * size = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");
                        Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");

                        variable_store_string( _environment, tmp->name, "                              " );

                        cpu_dswrite( _environment, tmp->realName );

                        cpu_dsdescriptor( _environment, tmp->realName, address->realName, size->realName );

                        switch( value->precision ) {
                            case FT_FAST:
                                cpu_float_fast_to_string( _environment, value->realName, address->realName, size->realName );
                                break;
                            case FT_SINGLE:
                                cpu_float_single_to_string( _environment, value->realName, address->realName, size->realName );
                                break;
                        }

                        cpu_dsresize( _environment, tmp->realName, size->realName );

                        value = tmp;

                        break;
                    }
                    case VT_IMAGE: {
                        char bufferName[MAX_TEMPORARY_STORAGE];
                        sprintf(bufferName, "@image(%s)", value->name);
                        Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                        variable_store_string( _environment, tmp->name, bufferName );

                        value = tmp;

                        break;
                    }
                    case VT_IMAGES: {
                        char bufferName[MAX_TEMPORARY_STORAGE];
                        sprintf(bufferName, "@images(%s)", value->name);
                        Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                        variable_store_string( _environment, tmp->name, bufferName );

                        value = tmp;

                        break;
                    }
                    case VT_BUFFER: {
                        char bufferName[MAX_TEMPORARY_STORAGE];
                        sprintf(bufferName, "@buffer(%s)", value->name);
                        Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                        variable_store_string( _environment, tmp->name, bufferName );

                        value = tmp;

                        break;
                    }
                    case VT_SPRITE: {
                        char bufferName[MAX_TEMPORARY_STORAGE];
                        sprintf(bufferName, "@sprite(%s)", value->name);
                        Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                        variable_store_string( _environment, tmp->name, bufferName );

                        value = tmp;

                        break;
                    }
                    case VT_TILE: {
                        char bufferName[MAX_TEMPORARY_STORAGE];
                        sprintf(bufferName, "@tile(%s)", value->name);
                        Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                        variable_store_string( _environment, tmp->name, bufferName );

                        value = tmp;

                        break;
                    }
                    case VT_TILESET: {
                        char bufferName[MAX_TEMPORARY_STORAGE];
                        sprintf(bufferName, "@tileset(%s)", value->name);
                        Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                        variable_store_string( _environment, tmp->name, bufferName );

                        value = tmp;

                        break;
                    }
                    case VT_TILEMAP: {
                        char bufferName[MAX_TEMPORARY_STORAGE];
                        sprintf(bufferName, "@tilemap(%s)", value->name);
                        Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                        variable_store_string( _environment, tmp->name, bufferName );

                        value = tmp;

                        break;
                    }
                    case VT_TILES: {
                        char bufferName[MAX_TEMPORARY_STORAGE];
                        sprintf(bufferName, "@tiles(%s)", value->name);
                        Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                        variable_store_string( _environment, tmp->name, bufferName );

                        value = tmp;

                        break;
                    }
                    default:
                        CRITICAL_PRINT_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type]);
                }
        }

        file_print_string( _environment, number->name, value->name );

        cpu_dsfree( _environment, value->realName );
    } else {
        file_print_string( _environment, number->name, value->name );
    }

    if ( _new_line ) {
        file_print_newline( _environment, number->name );
    }

}

