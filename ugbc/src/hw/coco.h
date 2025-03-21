#ifndef __UGBC_COCO__
#define __UGBC_COCO__

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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include "../ugbc.h"

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define DEFAULT_PAINT_BUCKET_SIZE   512

#define BANK_COUNT          1
#define BANK_SIZE           4096

#define MAX_AUDIO_CHANNELS  1

void coco_xpen( Environment * _environment, char * _destination );
void coco_ypen( Environment * _environment, char * _destination );
void coco_spen( Environment * _environment, char * _destination );

void coco_busy_wait( Environment * _environment, char * _timing );

void coco_sys_call( Environment * _environment, int _destination );

void coco_timer_set_status_on( Environment * _environment, char * _timer );
void coco_timer_set_status_off( Environment * _environment, char * _timer );
void coco_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void coco_timer_set_init( Environment * _environment, char * _timer, char * _init );
void coco_timer_set_address( Environment * _environment, char * _timer, char * _address );
void coco_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void coco_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );

void coco_serial_read( Environment * _environment, char * _address, char * _size );
void coco_serial_write( Environment * _environment, char * _address, char * _size, char * _result );

void coco_dojo_serial_put_request0( Environment * _environment, int _command, char * _param1, char * _param2, char * _result );
void coco_dojo_serial_put_request( Environment * _environment, int _command, char * _param1, char * _param2, char * _address, char * _size, char * _result );
void coco_dojo_serial_put_requestd( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, char * _size, char * _result );
void coco_dojo_serial_put_requestds( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, int _size, char * _result );
void coco_dojo_serial_get_response0( Environment * _environment, char * _status );
void coco_dojo_serial_get_response( Environment * _environment, char * _status, char * _address, char * _size );
void coco_dojo_serial_get_responsed( Environment * _environment, char * _status, char * _data, char * _size );
void coco_dojo_serial_get_response_size( Environment * _environment, char * _status, char * _data );
void coco_dojo_serial_get_response_payload( Environment * _environment, char * _address );
void coco_dojo_serial_get_response_payloadd( Environment * _environment, char * _data );

void coco_dojo_fujinet_put_request0( Environment * _environment, int _command, char * _param1, char * _param2, char * _result );
void coco_dojo_fujinet_put_request( Environment * _environment, int _command, char * _param1, char * _param2, char * _address, char * _size, char * _result );
void coco_dojo_fujinet_put_requestd( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, char * _size, char * _result );
void coco_dojo_fujinet_put_requestds( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, int _size, char * _result );
void coco_dojo_fujinet_get_response0( Environment * _environment, char * _status );
void coco_dojo_fujinet_get_response( Environment * _environment, char * _status, char * _address, char * _size );
void coco_dojo_fujinet_get_responsed( Environment * _environment, char * _status, char * _data, char * _size );
void coco_dojo_fujinet_get_response_size( Environment * _environment, char * _status, char * _data );
void coco_dojo_fujinet_get_response_payload( Environment * _environment, char * _address );
void coco_dojo_fujinet_get_response_payloadd( Environment * _environment, char * _data );

void coco_fujinet_set_device( Environment * _environment, int _device_id );
void coco_fujinet_set_device_var( Environment * _environment, char * _device_id );
void coco_fujinet_get_bytes_waiting( Environment * _environment, char * _bytes_waiting );
void coco_fujinet_is_connected( Environment * _environment, char * _is_connected );
void coco_fujinet_get_error( Environment * _environment, char * _error );
void coco_fujinet_is_ready( Environment * _environment, char * _ready );
void coco_fujinet_open( Environment * _environment, char * _url, char * _size, char * _mode, char * _trans, char * _result );
void coco_fujinet_close( Environment * _environment );
void coco_fujinet_get_status( Environment * _environment );
void coco_fujinet_read( Environment * _environment, char * _buffer, char * _size );
void coco_fujinet_write( Environment * _environment, char * _buffer, char * _size, char * _result );
void coco_fujinet_set_channel_mode( Environment * _environment, int _mode, char * _result );
void coco_fujinet_set_channel_mode_var( Environment * _environment, char * _mode, char * _result );
void coco_fujinet_parse_json( Environment * _environment, char * _result );
void coco_fujinet_json_query( Environment * _environment, char * _query, char * _size );
void coco_fujinet_login( Environment * _environment, char * _login, char * _size );
void coco_fujinet_password( Environment * _environment, char * _password, char * _size );

#endif
