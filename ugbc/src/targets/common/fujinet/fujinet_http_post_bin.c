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

 #include "../../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/* <usermanual>
@keyword FUJINET HTTP POST BIN

@english

The ''FUJINET HTTP POST BIN'' function allows you to write binary data 
to a HTTP connection.

@italian

La funzione ''FUJINET HTTP POST BIN'' consente di scrivere dati (binar)
su una connessione HTTP.

@syntax res = FUJINET HTTP POST BIN(var [AS type])
@syntax FUJINET HTTP POST BIN var [AS type]

@example err = FUJINET HTTP POST BIN(variable AS BYTE)
@example FUJINET HTTP POST BIN variable 

@target atari coco
</usermanual> */

Variable * fujinet_http_post_bin( Environment * _environment, char * _value ) {

    MAKE_LABEL

    char errorLabel[MAX_TEMPORARY_STORAGE]; sprintf(errorLabel, "%serr", label );

    Variable * err = variable_temporary( _environment, VT_BYTE, "(result)");

    variable_move( _environment, fujinet_set_channel_mode( _environment, 4 )->name, err->name );

    variable_compare_and_branch_const( _environment, err->name, 0, errorLabel, 0 );

    variable_move( _environment, fujinet_write( _environment, _value )->name, err->name );

    variable_compare_and_branch_const( _environment, err->name, 0, errorLabel, 0 );

    variable_move( _environment, fujinet_set_channel_mode( _environment, 0 )->name, err->name );

    cpu_label( _environment, errorLabel );
    
    return err;

}
