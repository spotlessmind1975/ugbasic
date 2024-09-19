#ifndef __UGBC_C64REU__
#define __UGBC_C64REU__

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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include "../ugbc.h"

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define         JOY_COUNT           2

#define DEFAULT_PAINT_BUCKET_SIZE   512

#define BANK_COUNT          0   // dynamic
#define BANK_SIZE           0   // dynamic

#define MAX_AUDIO_CHANNELS  3

void c64reu_xpen( Environment * _environment, char * _destination );
void c64reu_ypen( Environment * _environment, char * _destination );

void c64reu_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void c64reu_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void c64reu_sys_call( Environment * _environment, int _destination );

void c64reu_timer_set_status_on( Environment * _environment, char * _timer );
void c64reu_timer_set_status_off( Environment * _environment, char * _timer );
void c64reu_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void c64reu_timer_set_init( Environment * _environment, char * _timer, char * _init );
void c64reu_timer_set_address( Environment * _environment, char * _timer, char * _address );

void c64reu_dojo_ready( Environment * _environment, char * _value );
void c64reu_dojo_read_byte( Environment * _environment, char * _value );
void c64reu_dojo_write_byte( Environment * _environment, char * _value );

void c64reu_dojo_ping( Environment * _environment, char * _result );
void c64reu_dojo_login( Environment * _environment, char * _name, char * _name_size, char * _password, char * _size, char * _unique_id );
void c64reu_dojo_success( Environment * _environment, char * _id, char * _result );
void c64reu_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id );
void c64reu_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _port_id );
void c64reu_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result );
void c64reu_dojo_peek_message( Environment * _environment, char * _port_id, char * _result );
void c64reu_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message );
void c64reu_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result );

#endif