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

void dojo_serial_init( Environment * _environment ) {

}

void dojo_serial_begin( Environment * _environment ) {

}

void dojo_serial_put_request0( Environment * _environment, int _command, char * _param1, char * _param2, char * _result ) {

    atari_dojo_serial_put_request0( _environment, _command, _param1, _param2, _result );
}

void dojo_serial_put_request( Environment * _environment, int _command, char * _param1, char * _param2, char * _address, char * _size, char * _result ) {

    atari_dojo_serial_put_request( _environment, _command, _param1, _param2, _address, _size, _result );

}

void dojo_serial_put_requestd( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, char * _size, char * _result ) {

    atari_dojo_serial_put_requestd( _environment, _command, _param1, _param2, _data, _size, _result );

}

void dojo_serial_put_requestds( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, int _size, char * _result ) {

    atari_dojo_serial_put_requestds( _environment, _command, _param1, _param2, _data, _size, _result );

}

void dojo_serial_get_response0( Environment * _environment, char * _status ) {

    atari_dojo_serial_get_response0( _environment, _status );

}

void dojo_serial_get_response( Environment * _environment, char * _status, char * _address, char * _size ) {

    atari_dojo_serial_get_response( _environment, _status, _address, _size );

}

void dojo_serial_get_responsed( Environment * _environment, char * _status, char * _data, char * _size ) {

    atari_dojo_serial_get_responsed( _environment, _status, _data, _size );

}

void dojo_serial_get_response_size( Environment * _environment, char * _status, char * _size ) {

    atari_dojo_serial_get_response_size( _environment, _status, _size );

}

void dojo_serial_get_response_payload( Environment * _environment, char * _address ) {

    atari_dojo_serial_get_response_payload( _environment, _address );

}

void dojo_serial_get_response_payloadd( Environment * _environment, char * _data ) {

    atari_dojo_serial_get_response_payloadd( _environment, _data );

}

void dojo_serial_end( Environment * _environment ) {

}
