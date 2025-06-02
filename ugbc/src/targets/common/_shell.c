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

void shell_injection( Environment * _environment ) {

    char versionString[MAX_TEMPORARY_STORAGE]; sprintf( versionString, "ugBASIC Runtime version %s", UGBASIC_VERSION );

    Variable * presentationLine = variable_define( _environment, "SHELL_PRESENTATION", VT_STRING, 0 );
    variable_store_string( _environment, presentationLine->name, versionString );
    Variable * prompt = variable_define( _environment, "SHELL_PROMPT", VT_STRING, 0 );
    variable_store_string( _environment, prompt->name, "READY" );
    Variable * command = variable_define( _environment, "SHELL_COMMAND", VT_DSTRING, 0 );
    Variable * loweredCommand = variable_define( _environment, "SHELL_LOWERED_COMMAND", VT_DSTRING, 0 );
    Variable * commandRun = variable_define( _environment, "SHELL_COMMAND_RUN", VT_STRING, 0 );
    variable_store_string( _environment, commandRun->name, "run" );
    Variable * commandList = variable_define( _environment, "SHELL_COMMAND_LIST", VT_STRING, 0 );
    variable_store_string( _environment, commandList->name, "list" );
    Variable * syntaxError = variable_define( _environment, "SHELL_SYNTAX_ERROR", VT_STRING, 0 );
    variable_store_string( _environment, syntaxError->name, "? SYNTAX ERROR" );
    Variable * source = variable_retrieve( _environment, "SHELL_SOURCE" );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)");

    cls( _environment, NULL );
    
    cpu_label( _environment, "SHELL" );

    print( _environment, presentationLine->name, 1, _environment->printRaw );

    begin_do_loop( _environment );

        cpu_label( _environment, "SHELLPROMPT" );

        print_newline( _environment );

        print( _environment, prompt->name, 1, _environment->printRaw );

        input( _environment, command->name, VT_DSTRING );

        outline0("; lowered");
        loweredCommand = variable_string_lower( _environment, command->name );

        outline0("; compare");
        result = variable_compare( _environment, loweredCommand->name, commandRun->name );

        outline0("; compare and branch");
        cpu_compare_and_branch_8bit_const( _environment, result->realName, 0xff, "PROGSTART", 1 );

        outline0("; compare2");
        result = variable_compare( _environment, loweredCommand->name, commandList->name );

        outline0("; compare and branch2");
        cpu_compare_and_branch_8bit_const( _environment, result->realName, 0xff, "PROGLIST", 1 );

        print( _environment, syntaxError->name, 1, _environment->printRaw );

        cpu_dsfree( _environment, loweredCommand->realName );
        cpu_dsfree( _environment, command->realName );

    end_do_loop( _environment );

    cpu_label( _environment, "PROGLIST" );

    print_newline( _environment );
    
    print_buffer( _environment, source->name, 1, 1 );

    cpu_jump( _environment, "SHELLPROMPT" );

    cpu_label( _environment, "PROGSTART" );

    home( _environment );

    cls( _environment, NULL );

}