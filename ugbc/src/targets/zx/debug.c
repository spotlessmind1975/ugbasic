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

    switch( var->type ) {
        case VT_BYTE:
        case VT_COLOR:
            outline1( "LD A, (%s)", var->realName );
            outline0( "LD B, 0" );
            outline0( "LD C, A" );
            outline0( "CALL 6683" );
            break;
        case VT_ADDRESS:
        case VT_WORD:
        case VT_POSITION:
            outline1( "LD BC, (%s)", var->realName );
            outline0( "CALL 6683" );
            break;
        case VT_DWORD:
            outline1( "LD BC, (%s+2)", var->realName );
            outline0( "CALL 6683" );
            outline1( "LD BC, (%s)", var->realName );
            outline0( "CALL 6683" );
            break;
        case VT_STRING: {

            char stringAddress[16]; sprintf(stringAddress, "%s+1", var->realName );

            outline1( "LD DE, (%s)", stringAddress );
            outline1( "LD A, (%s)", var->realName );
            outline0( "LD C, A" );
            outline0( "LD B, 0" );
            outline0( "CALL 8252" );
            break;
        }

    }

    outline0( "LD A, 32");
    outline0( "RST $10" );
}

