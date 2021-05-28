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
 * @brief Emit ASM implementation for <b>DEBUG [expression]</b> instruction 
 * 
 * This function outputs a string with the value contained in the indicated variable
 * (the variable must be up to 2 bytes longs). For speed of implementation it uses 
 * the function of the KERNAL, so it cannot work if the ROM is disabled.
 * 
 * @param _environment Current calling environment
 * @param _name Name of the variable to print
 * @throw EXIT_FAILURE "DWORD variables cannot be debugged"
 */
/* <usermanual>
@keyword DEBUG

@target zx
</usermanual> */

void debug_var( Environment * _environment, char * _name ) {

    MAKE_LABEL

    // Safety check
    Variable * var = variable_retrieve( _environment, _name );

    switch( VT_BITWIDTH( var->type ) ) {
        case 8:
        case 16:
        case 32: {
            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
            Variable * string = variable_temporary( _environment, VT_DSTRING, "(string for debug)");
            variable_store_string( _environment, string->name,"                    ");
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            cpu_number_to_string( _environment, var->realName, address->realName, size->realName, VT_BITWIDTH( var->type ) );
            outline0( "LD DE, HL" );
            outline0( "CALL 8252" );
        }
            break;
        case 0:
            switch( var->type ) {
                case VT_STRING: {
                    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                    cpu_move_8bit( _environment, var->realName, size->realName );
                    cpu_move_16bit( _environment, var->realName, address->realName );
                    cpu_inc_16bit( _environment, address->realName );
                    outline1( "LD DE, %s", address->realName );
                    outline1( "LD A, (%s)", size->realName );
                    outline0( "LD C, A" );
                    outline0( "LD B, 0" );
                    outline0( "CALL 8252" );
                    break;
                }
                case VT_DSTRING: {
                    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                    cpu_dsdescriptor( _environment, var->realName, address->realName, size->realName );
                    outline1( "LD DE, %s", address->realName );
                    outline1( "LD A, (%s)", size->realName );
                    outline0( "LD C, A" );
                    outline0( "LD B, 0" );
                    outline0( "CALL 8252" );
                    break;
                }
                default:
                    CRITICAL_DEBUG_UNSUPPORTED( _name, DATATYPE_AS_STRING[var->type]);
            }
            break;

    }

    outline0( "LD A, 32");
    outline0( "RST $10" );

    variable_reset( _environment );

}

