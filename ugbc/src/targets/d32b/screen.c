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
 
Variable * screen_var( Environment * _environment, char * _x, char * _y, int _as_string ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );
    Variable * c = variable_temporary( _environment, VT_BYTE, "(c)" );

    c6847_screen( _environment, x->realName, y->realName, c->realName );

    if ( _as_string ) {
        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
        Variable * string = variable_temporary( _environment, VT_DSTRING, "(address)" );
        cpu_dsfree( _environment, c->realName );
        cpu_dsalloc_size( _environment, 1, string->realName );
        cpu_dsdescriptor( _environment, string->realName, address->realName, NULL );
        poke_var( _environment, address->name, c->name );
        return string;
    } else {
        return c;
    }

}