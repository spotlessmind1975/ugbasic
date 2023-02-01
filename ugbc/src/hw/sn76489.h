#ifndef __UGBC_SN76489__
#define __UGBC_SN76489__

/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

void sn76489_initialization( Environment * _environment );
void sn76489_finalization( Environment * _environment );

void sn76489_start( Environment * _environment, int _channel );
void sn76489_set_volume( Environment * _environment, int _channel, int _volume );
void sn76489_set_program( Environment * _environment, int _channel, int _program );
void sn76489_set_parameter( Environment * _environment, int _channel, int _parameter, int _value );
void sn76489_set_frequency( Environment * _environment, int _channel, int _frequency );
void sn76489_set_pitch( Environment * _environment, int _channel, int _pitch );
void sn76489_set_note( Environment * _environment, int _channel, int _note );
void sn76489_stop( Environment * _environment, int _channel );

void sn76489_start_var( Environment * _environment, char * _channel );
void sn76489_set_volume_semi_var( Environment * _environment, char * _channel, int _volume );
void sn76489_set_volume_vars( Environment * _environment, char * _channel, char * _volume );
void sn76489_set_program_semi_var( Environment * _environment, char * _channel, int _program );
void sn76489_set_frequency_vars( Environment * _environment, char * _channel, char * _frequency );
void sn76489_set_pitch_vars( Environment * _environment, char * _channel, char * _pitch );
void sn76489_set_note_vars( Environment * _environment, char * _channel, char * _note );
void sn76489_stop_vars( Environment * _environment, char * _channel );

void sn76489_music( Environment * _environment, char * _music, int _size );

#endif