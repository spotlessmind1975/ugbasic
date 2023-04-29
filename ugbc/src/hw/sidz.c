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

#if defined(__c128z__)

#include "../ugbc.h"

static unsigned int SOUND_FREQUENCIES[] = {
    0,		0,		0,		0,		0,		0,		0,		0,		0,		0,
    0,		0,		0,		0,		0,		0,		0,		0,		0,		0,
    0,		0,		0,		268,	284,	301,	318,	337,	358,	379,
    401,	425,	451,	477,	506,	536,	568,	602,	637,	675,
    716,	758,	803,	851,	902,	955,	1012,	1072,	1136,	1204,
    1275,	1351,	1432,	1517,	1607,	1703,	1804,	1911,	2025,	2145,
    2273,	2408,	2551,	2703,	2864,	3034,	3215,	3406,	3608,	3823,
    4050,	4291,	4547,	4817,	5103,	5407,	5728,	6069,	6430,	6812,
    7217,	7647,	8101,	8583,	9094,	9634,	10207,	10814,	11457,	12139,
    12860,	13625,	14435,	15294,	16203,	17167,	18188,	19269,	20415,	21629,
    22915,	24278,	25721,	27251,	28871,	30588,	32407,	34334,	36376,	38539,
    40830,	43258,	45830,	48556,	51443,	54502,	57743,	61176,	64814
};

void sidz_initialization( Environment * _environment ) {

}

void sidz_finalization( Environment * _environment ) {

}

void sidz_start( Environment * _environment, int _channels ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_volume( Environment * _environment, int _channels, int _volume ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_program( Environment * _environment, int _channels, int _program ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_parameter( Environment * _environment, int _channels, int _parameter, int _value ) {

}

void sidz_set_frequency( Environment * _environment, int _channels, int _frequency ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_pitch( Environment * _environment, int _channels, int _pitch ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_note( Environment * _environment, int _channels, int _note ) {

    sidz_set_pitch( _environment, _channels, SOUND_FREQUENCIES[_note] );

}

void sidz_stop( Environment * _environment, int _channels ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_start_var( Environment * _environment, char * _channels ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_volume_vars( Environment * _environment, char * _channels, char * _volume ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_volume_semi_var( Environment * _environment, char * _channel, int _volume ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_program_semi_var( Environment * _environment, char * _channels, int _program ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_frequency_vars( Environment * _environment, char * _channels, char * _frequency ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_pitch_vars( Environment * _environment, char * _channels, char * _pitch ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_set_note_vars( Environment * _environment, char * _channels, char * _note ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_stop_vars( Environment * _environment, char * _channels ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

void sidz_music( Environment * _environment, char * _music, int _size ) {

    deploy( sidvars, src_hw_sidz_vars_asm );
    deploy( sidstartup, src_hw_sidz_startup_asm );

}

#endif