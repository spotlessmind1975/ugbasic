#ifndef __UGBC_C64__
#define __UGBC_C64__

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
#define BANK_BASE_ADDRESS   0

#define MAX_AUDIO_CHANNELS  3

void c64_xpen( Environment * _environment, char * _destination );
void c64_ypen( Environment * _environment, char * _destination );

void c64_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void c64_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void c64_sys_call( Environment * _environment, int _destination );

void c64_timer_set_status_on( Environment * _environment, char * _timer );
void c64_timer_set_status_off( Environment * _environment, char * _timer );
void c64_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void c64_timer_set_init( Environment * _environment, char * _timer, char * _init );
void c64_timer_set_address( Environment * _environment, char * _timer, char * _address );

#endif