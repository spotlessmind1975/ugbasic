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

/* <usermanual>
@keyword PLAY (program)

@english

@italian

@syntax PLAY instructions

@example PLAY "O1V31T2L4GGL8GGL4B-AAGGF+G"

@usedInExample audio_play_02.bas

@target all
</usermanual> */
void play_string( Environment * _environment, char * _string ) {

    deploy_begin( play_string );

        MAKE_LABEL

        cpu_return( _environment );

    deploy_end( draw_string );

    Variable * string = variable_retrieve( _environment, _string );

    if ( ( string->type != VT_STRING ) && ( string->type != VT_DSTRING ) ) {
        CRITICAL_CANNOT_USE_PLAY_WITHOUT_STRING( _string );
    }

    if( string->type == VT_STRING ) {
        Variable * dstring = variable_temporary( _environment, VT_DSTRING, "(dstring)" );
        cpu_dsdefine( _environment, string->realName, dstring->realName );
        string = dstring;
    }

    Variable * parameter = variable_retrieve( _environment, "playstring__string" );
    
    variable_move( _environment, string->name, parameter->name );
    cpu_call( _environment, "lib_play_string");

}