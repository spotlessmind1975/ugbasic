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

#if defined(__msx1__) || defined(__cpc__)

#include "../ugbc.h"

static unsigned int SOUND_FREQUENCIES[] = {
    6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841,
    6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841,
    6841,		6841,		6841,       6841,       6457,       6095,       5753,       5430,       5125,       4837,
    4566,       4310,       4068,       3839,       3624,       3420,       3229,       3047,       2876,       2715,
    2562,       2419,       2283,       2155,       2034,       1920,       1812,       1710,       1614,       1524,
    1438,       1357,       1281,       1209,       1141,       1077,       1017,       960,        906,        855,
    807,        762,        719,        679,        641,        605,        571,        539,        508,        480,
    453,        428,        404,        381,        360,        339,        320,        302,        285,        269,
    254,        240,        226,        214,        202,        190,        180,        170,        160,        151,
    143,        135,        127,        120,        113,        107,        101,        95,         90,         85,
    80,         76,         71,         67,         64,         60,         57,         53,         50,         48,
    45,         42,         40,         38,         36,         34,         32,         30,         28
};

void ay8910_initialization( Environment * _environment ) {

    variable_import( _environment, "AY8910MUSICREADY", VT_BYTE, 0 );
    variable_global( _environment, "AY8910MUSICREADY" );
    variable_import( _environment, "AY8910BLOCKS", VT_BYTE, 0 );
    variable_global( _environment, "AY8910BLOCKS" );
    variable_import( _environment, "AY8910LASTBLOCK", VT_BYTE, 0 );
    variable_global( _environment, "AY8910LASTBLOCK" );
    variable_import( _environment, "AY8910TMPPTR2", VT_ADDRESS, 0 );
    variable_global( _environment, "AY8910TMPPTR2" );
    variable_import( _environment, "AY8910TMPPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "AY8910TMPPTR" );
    variable_import( _environment, "AY8910TMPOFS", VT_BYTE, 0 );
    variable_global( _environment, "AY8910TMPOFS" );
    variable_import( _environment, "AY8910TMPLEN", VT_BYTE, 0 );
    variable_global( _environment, "AY8910TMPLEN" );
    variable_import( _environment, "AY8910JIFFIES", VT_BYTE, 0 );
    variable_global( _environment, "AY8910JIFFIES" );

    cpu_call( _environment, "AY8910STARTUP" );

}

void ay8910_finalization( Environment * _environment ) {

    if ( ! _environment->deployed.ay8910startup ) {
        cpu_label( _environment, "AY8910STARTUP" );
        outline0( "RET" );
        cpu_label( _environment, "MUSICPLAYER" );
        outline0( "RET" );
    }

}

void ay8910_start( Environment * _environment, int _channels ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    if ( _channels & 0x01 ) {
        outline0("CALL AY8910START0");
    }
    if ( _channels & 0x02 ) {
        outline0("CALL AY8910START1");
    }
    if ( _channels & 0x04 ) {
        outline0("CALL AY8910START2");
    }

}

void ay8910_set_volume( Environment * _environment, int _channels, int _volume ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    outline1("LD A, $%2.2x", ( _volume & 0x0f ) );
    outline0("LD B, A" );
    outline0("CALL AY8910STARTVOL");

}

#define     PROGRAM_FREQUENCY( c, f ) \
    outline1("LD A, $%2.2x", ( f & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL AY8910PROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL AY8910PROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL AY8910PROGFREQ2" );

#define     PROGRAM_FREQUENCY_V( c, f ) \
    outline1("LD A, (%s)", f ); \
    outline0("LD E, A" ); \
    outline1("LD A, (%s)", address_displacement(_environment, f, "1") ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910FREQ" );

#define     PROGRAM_FREQUENCY_SV( c, f ) \
    outline1("LD A, $%2.2x", ( f & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910FREQ2" );

#define     PROGRAM_PITCH( c, f ) \
    outline1("LD A, $%2.2x", ( f & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL AY8910PROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL AY8910PROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL AY8910PROGFREQ2" );

#define     PROGRAM_PITCH_V( c, f ) \
    outline1("LD A, (%s)", f ); \
    outline0("LD E, A" ); \
    outline1("LD A, (%s)", address_displacement(_environment, f, "1") ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGFREQ" );

#define     PROGRAM_PITCH_SV( c, f ) \
    outline1("LD A, $%2.2x", ( f & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGFREQ" );

#define     PROGRAM_PULSE( c, p ) \
    outline1("LD A, $%2.2x", ( p & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( p >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL AY8910PROGPULSE0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL AY8910PROGPULSE1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL AY8910PROGPULSE2" );

#define     PROGRAM_PULSE_V( c, p ) \
    outline1("LD A, (%s)", p ); \
    outline0("LD E, A" ); \
    outline1("LD A, (%s)", address_displacement(_environment, p, "1") ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGPULSE" );

#define     PROGRAM_PULSE_SV( c, p ) \
    outline1("LD A, $%2.2x", ( p & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( p >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGPULSE" );

#define     PROGRAM_NOISE( c ) \
    outline0("LD A, $82" ); \
    outline0("LD B, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL AY8910PROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL AY8910PROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL AY8910PROGCTR2" );

#define     PROGRAM_NOISE_V( c, p ) \
    outline0("LD A, $82" ); \
    outline0("LD B, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGCTR" );

#define     PROGRAM_NOISE_SV( c ) \
    outline0("LD A, $82" ); \
    outline0("LD B, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGCTR" );

#define     PROGRAM_SAW( c ) \
    outline0("LD A, $22" ); \
    outline0("LD B, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL AY8910PROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL AY8910PROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL AY8910PROGCTR2" );

#define     PROGRAM_SAW_V( c) \
    outline0("LD A, $22" ); \
    outline0("LD B, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGCTR" );

#define     PROGRAM_SAW_SV( c ) \
    outline0("LD A, $22" ); \
    outline0("LD B, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGCTR" );

#define     PROGRAM_TRIANGLE( c ) \
    outline0("LD A, $12" ); \
    outline0("LD B, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL AY8910PROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL AY8910PROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL AY8910PROGCTR2" );

#define     PROGRAM_TRIANGLE_V( c ) \
    outline0("LD A, $12" ); \
    outline0("LD B, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGCTR" );

#define     PROGRAM_TRIANGLE_SV( c ) \
    outline0("LD A, $12" ); \
    outline0("LD B, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGCTR" );

#define     PROGRAM_SAW_TRIANGLE( c ) \
    outline0("LD A, $32" ); \
    outline0("LD B, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL AY8910PROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL AY8910PROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL AY8910PROGCTR2" );

#define     PROGRAM_SAW_TRIANGLE_V( c ) \
    outline0("LD A, $32" ); \
    outline0("LD B, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGCTR" );

#define     PROGRAM_SAW_TRIANGLE_SV( c ) \
    outline0("LD A, $32" ); \
    outline0("LD B, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGCTR" );

#define     PROGRAM_ATTACK_DECAY( c, a, d ) \
    outline1("LD A, $%2.2x", ( a & 0x0f ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( d & 0x0f ) ); \
    outline0("LD D, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL AY8910PROGAD0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL AY8910PROGAD1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL AY8910PROGAD2" );

#define     PROGRAM_ATTACK_DECAY_V( c, a, d ) \
    outline1("LD A, %s", a ); \
    outline0("LD E, A" ); \
    outline1("LD A, %s", d ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGAD" );

#define     PROGRAM_ATTACK_DECAY_SV( c, a, d ) \
    outline1("LD A, $%2.2x", ( a & 0x0f ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( d & 0x0f ) ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGAD" );

#define     PROGRAM_SUSTAIN_RELEASE( c, s, r ) \
    outline1("LD A, $%2.2x", ( s & 0x0f ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( r & 0x0f ) ); \
    outline0("LD D, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL AY8910PROGSR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL AY8910PROGSR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL AY8910PROGSR2" );

#define     PROGRAM_SUSTAIN_RELEASE_V( c, s, r ) \
    outline1("LD A, %s", s ); \
    outline0("LD E, A" ); \
    outline1("LD A, %s", r ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGSR" );

#define     PROGRAM_SUSTAIN_RELEASE_SV( c, s, r ) \
    outline1("LD A, $%2.2x", ( s & 0x0f ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( r & 0x0f ) ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910PROGSR" );

#define     STOP_FREQUENCY( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("CALL AY8910STOP0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL AY8910STOP1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL AY8910STOP2" );

#define     STOP_FREQUENCY_V( c ) \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910STOP" );

#define     STOP_FREQUENCY_SV( c ) \
    if ( c == NULL ) { \
        outline0("LD A, $7"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL AY8910STOP" );

void ay8910_set_program( Environment * _environment, int _channels, int _program ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            PROGRAM_NOISE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 11);
            PROGRAM_SUSTAIN_RELEASE(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_GUNSHOT:
            PROGRAM_NOISE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 4);
            PROGRAM_SUSTAIN_RELEASE(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_PAD_5_BOWED:
        case IMF_INSTRUMENT_PAD_6_METALLIC:
        case IMF_INSTRUMENT_PAD_7_HALO:
        case IMF_INSTRUMENT_PAD_8_SWEEP:
        case IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:
        case IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:
        case IMF_INSTRUMENT_HONKY_TONK_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_PIANO1:
        case IMF_INSTRUMENT_ELECTRIC_PIANO2:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 4, 2);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
            PROGRAM_PULSE(_channels, 1024);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 3);
            break;

        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 12, 14);
            break;

        default:
        case IMF_INSTRUMENT_PAD_3_POLYSYNTH:
        case IMF_INSTRUMENT_DRAWBAR_ORGAN:
        case IMF_INSTRUMENT_PERCUSSIVE_ORGAN:
        case IMF_INSTRUMENT_ROCK_ORGAN:
        case IMF_INSTRUMENT_CHURCH_ORGAN:
        case IMF_INSTRUMENT_REED_ORGAN:
        case IMF_INSTRUMENT_ACCORDION:
        case IMF_INSTRUMENT_HARMONICA:
        case IMF_INSTRUMENT_TANGO_ACCORDION:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
            PROGRAM_PULSE(_channels, 128);
            PROGRAM_ATTACK_DECAY(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
            PROGRAM_PULSE(_channels, 128);
            PROGRAM_ATTACK_DECAY(_channels, 1, 2);
            PROGRAM_SUSTAIN_RELEASE(_channels, 4, 3);
            break;

        case IMF_INSTRUMENT_LEAD_8_BASS_LEAD:
        case IMF_INSTRUMENT_ACOUSTIC_BASS:
        case IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:
        case IMF_INSTRUMENT_ELECTRIC_BASS_PICK:
        case IMF_INSTRUMENT_FRETLESS_BASS:
        case IMF_INSTRUMENT_SLAP_BASS_1:
        case IMF_INSTRUMENT_SLAP_BASS_2:
        case IMF_INSTRUMENT_SYNTH_BASS_1:
        case IMF_INSTRUMENT_SYNTH_BASS_2:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 12, 14);
            break;

        case IMF_INSTRUMENT_LEAD_1_SQUARE:
        case IMF_INSTRUMENT_VIOLIN:
        case IMF_INSTRUMENT_VIOLA:
        case IMF_INSTRUMENT_CELLO:
        case IMF_INSTRUMENT_CONTRABASS:
        case IMF_INSTRUMENT_TREMOLO_STRINGS:
        case IMF_INSTRUMENT_PIZZICATO_STRINGS:
        case IMF_INSTRUMENT_ORCHESTRAL_HARP:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_1:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_2:
        case IMF_INSTRUMENT_SYNTHSTRINGS_1:
        case IMF_INSTRUMENT_SYNTHSTRINGS_2:
            PROGRAM_PULSE(_channels, 128);
            PROGRAM_ATTACK_DECAY(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_PAD_4_CHOIR:
        case IMF_INSTRUMENT_CHOIR_AAHS:
        case IMF_INSTRUMENT_VOICE_OOHS:
        case IMF_INSTRUMENT_SYNTH_VOICE:
        case IMF_INSTRUMENT_LEAD_4_CHIFF:
        case IMF_INSTRUMENT_LEAD_5_CHARANG:
        case IMF_INSTRUMENT_LEAD_6_VOICE:
        case IMF_INSTRUMENT_LEAD_7_FIFTHS:
        case IMF_INSTRUMENT_FX_1_RAIN:
        case IMF_INSTRUMENT_FX_2_SOUNDTRACK:
        case IMF_INSTRUMENT_FX_3_CRYSTAL:
        case IMF_INSTRUMENT_FX_4_ATMOSPHERE:
        case IMF_INSTRUMENT_FX_5_BRIGHTNESS:
        case IMF_INSTRUMENT_FX_6_GOBLINS:
        case IMF_INSTRUMENT_FX_7_ECHOES:
        case IMF_INSTRUMENT_FX_8_SCI_FI:
        case IMF_INSTRUMENT_TIMPANI:
        case IMF_INSTRUMENT_ORCHESTRA_HIT:
        case IMF_INSTRUMENT_APPLAUSE:
            PROGRAM_NOISE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 1, 14);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_LEAD_2_SAWTOOTH:
        case IMF_INSTRUMENT_PAD_1_NEW_AGE:
        case IMF_INSTRUMENT_PAD_2_WARM:
        case IMF_INSTRUMENT_TRUMPET:
        case IMF_INSTRUMENT_TROMBONE:
        case IMF_INSTRUMENT_TUBA:
        case IMF_INSTRUMENT_MUTED_TRUMPET:
        case IMF_INSTRUMENT_FRENCH_HORN:
        case IMF_INSTRUMENT_BRASS_SECTION:
        case IMF_INSTRUMENT_SYNTHBRASS_1:
        case IMF_INSTRUMENT_SYNTHBRASS_2:
        case IMF_INSTRUMENT_SOPRANO_SAX:
        case IMF_INSTRUMENT_ALTO_SAX:
        case IMF_INSTRUMENT_TENOR_SAX:
        case IMF_INSTRUMENT_BARITONE_SAX:
        case IMF_INSTRUMENT_OBOE:
        case IMF_INSTRUMENT_ENGLISH_HORN:
        case IMF_INSTRUMENT_BASSOON:
        case IMF_INSTRUMENT_CLARINET:
        case IMF_INSTRUMENT_PICCOLO:
        case IMF_INSTRUMENT_FLUTE:
        case IMF_INSTRUMENT_RECORDER:
        case IMF_INSTRUMENT_PAN_FLUTE:
        case IMF_INSTRUMENT_BLOWN_BOTTLE:
        case IMF_INSTRUMENT_SHAKUHACHI:
        case IMF_INSTRUMENT_WHISTLE:
        case IMF_INSTRUMENT_OCARINA:
            PROGRAM_SAW(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_SITAR:
        case IMF_INSTRUMENT_BANJO:
        case IMF_INSTRUMENT_SHAMISEN:
        case IMF_INSTRUMENT_KOTO:
        case IMF_INSTRUMENT_KALIMBA:
        case IMF_INSTRUMENT_BAG_PIPE:
        case IMF_INSTRUMENT_FIDDLE:
        case IMF_INSTRUMENT_SHANAI:
        case IMF_INSTRUMENT_TINKLE_BELL:
        case IMF_INSTRUMENT_AGOGO:
        case IMF_INSTRUMENT_STEEL_DRUMS:
        case IMF_INSTRUMENT_WOODBLOCK:
        case IMF_INSTRUMENT_TAIKO_DRUM:
        case IMF_INSTRUMENT_MELODIC_TOM:
        case IMF_INSTRUMENT_SYNTH_DRUM:
        case IMF_INSTRUMENT_REVERSE_CYMBAL:
        case IMF_INSTRUMENT_GUITAR_FRET_NOISE:
        case IMF_INSTRUMENT_BREATH_NOISE:
        case IMF_INSTRUMENT_SEASHORE:
        case IMF_INSTRUMENT_BIRD_TWEET:
        case IMF_INSTRUMENT_TELEPHONE_RING:
        case IMF_INSTRUMENT_HELICOPTER:
            PROGRAM_SAW(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;
    }

}

void ay8910_set_parameter( Environment * _environment, int _channels, int _parameter, int _value ) {

}

void ay8910_set_frequency( Environment * _environment, int _channels, int _frequency ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    PROGRAM_FREQUENCY( _channels, _frequency );

}

void ay8910_set_pitch( Environment * _environment, int _channels, int _pitch ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    PROGRAM_PITCH( _channels, _pitch );

}

void ay8910_set_note( Environment * _environment, int _channels, int _note ) {

    ay8910_set_pitch( _environment, _channels, SOUND_FREQUENCIES[_note] );

}

void ay8910_stop( Environment * _environment, int _channels ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    STOP_FREQUENCY( _channels );

}

void ay8910_start_var( Environment * _environment, char * _channels ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    if ( _channels ) {
        outline1("LD A, (%s)", _channels );
    } else {
        outline0("LD A, $7" );
    }
    outline0("CALL AY8910START");

}

void ay8910_set_volume_vars( Environment * _environment, char * _channels, char * _volume ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    outline1("LD A, (%s)", _volume );
    outline0("SRL A" );
    outline0("SRL A" );
    outline0("SRL A" );
    outline0("SRL A" );
    outline0("CALL AY8910STARTVOL");

}

void ay8910_set_volume_semi_var( Environment * _environment, char * _channel, int _volume ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    outline1("LD A, $%2.2x", _volume );
    outline0("CALL AY8910STARTVOL");

}

void ay8910_set_program_semi_var( Environment * _environment, char * _channels, int _program ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            PROGRAM_NOISE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 11);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_GUNSHOT:
            PROGRAM_NOISE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 4);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_PAD_5_BOWED:
        case IMF_INSTRUMENT_PAD_6_METALLIC:
        case IMF_INSTRUMENT_PAD_7_HALO:
        case IMF_INSTRUMENT_PAD_8_SWEEP:
        case IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:
        case IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:
        case IMF_INSTRUMENT_HONKY_TONK_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_PIANO1:
        case IMF_INSTRUMENT_ELECTRIC_PIANO2:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 4, 2);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
            PROGRAM_PULSE_SV(_channels, 1024);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 3);
            break;

        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 12, 14);
            break;

        default:
        case IMF_INSTRUMENT_PAD_3_POLYSYNTH:
        case IMF_INSTRUMENT_DRAWBAR_ORGAN:
        case IMF_INSTRUMENT_PERCUSSIVE_ORGAN:
        case IMF_INSTRUMENT_ROCK_ORGAN:
        case IMF_INSTRUMENT_CHURCH_ORGAN:
        case IMF_INSTRUMENT_REED_ORGAN:
        case IMF_INSTRUMENT_ACCORDION:
        case IMF_INSTRUMENT_HARMONICA:
        case IMF_INSTRUMENT_TANGO_ACCORDION:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
            PROGRAM_PULSE_SV(_channels, 128);
            PROGRAM_ATTACK_DECAY_SV(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
            PROGRAM_PULSE_SV(_channels, 128);
            PROGRAM_ATTACK_DECAY_SV(_channels, 1, 2);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 4, 3);
            break;

        case IMF_INSTRUMENT_LEAD_8_BASS_LEAD:
        case IMF_INSTRUMENT_ACOUSTIC_BASS:
        case IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:
        case IMF_INSTRUMENT_ELECTRIC_BASS_PICK:
        case IMF_INSTRUMENT_FRETLESS_BASS:
        case IMF_INSTRUMENT_SLAP_BASS_1:
        case IMF_INSTRUMENT_SLAP_BASS_2:
        case IMF_INSTRUMENT_SYNTH_BASS_1:
        case IMF_INSTRUMENT_SYNTH_BASS_2:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 12, 14);
            break;

        case IMF_INSTRUMENT_LEAD_1_SQUARE:
        case IMF_INSTRUMENT_VIOLIN:
        case IMF_INSTRUMENT_VIOLA:
        case IMF_INSTRUMENT_CELLO:
        case IMF_INSTRUMENT_CONTRABASS:
        case IMF_INSTRUMENT_TREMOLO_STRINGS:
        case IMF_INSTRUMENT_PIZZICATO_STRINGS:
        case IMF_INSTRUMENT_ORCHESTRAL_HARP:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_1:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_2:
        case IMF_INSTRUMENT_SYNTHSTRINGS_1:
        case IMF_INSTRUMENT_SYNTHSTRINGS_2:
            PROGRAM_PULSE_SV(_channels, 128);
            PROGRAM_ATTACK_DECAY_SV(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_PAD_4_CHOIR:
        case IMF_INSTRUMENT_CHOIR_AAHS:
        case IMF_INSTRUMENT_VOICE_OOHS:
        case IMF_INSTRUMENT_SYNTH_VOICE:
        case IMF_INSTRUMENT_LEAD_4_CHIFF:
        case IMF_INSTRUMENT_LEAD_5_CHARANG:
        case IMF_INSTRUMENT_LEAD_6_VOICE:
        case IMF_INSTRUMENT_LEAD_7_FIFTHS:
        case IMF_INSTRUMENT_FX_1_RAIN:
        case IMF_INSTRUMENT_FX_2_SOUNDTRACK:
        case IMF_INSTRUMENT_FX_3_CRYSTAL:
        case IMF_INSTRUMENT_FX_4_ATMOSPHERE:
        case IMF_INSTRUMENT_FX_5_BRIGHTNESS:
        case IMF_INSTRUMENT_FX_6_GOBLINS:
        case IMF_INSTRUMENT_FX_7_ECHOES:
        case IMF_INSTRUMENT_FX_8_SCI_FI:
        case IMF_INSTRUMENT_TIMPANI:
        case IMF_INSTRUMENT_ORCHESTRA_HIT:
        case IMF_INSTRUMENT_APPLAUSE:
            PROGRAM_NOISE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 1, 14);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_LEAD_2_SAWTOOTH:
        case IMF_INSTRUMENT_PAD_1_NEW_AGE:
        case IMF_INSTRUMENT_PAD_2_WARM:
        case IMF_INSTRUMENT_TRUMPET:
        case IMF_INSTRUMENT_TROMBONE:
        case IMF_INSTRUMENT_TUBA:
        case IMF_INSTRUMENT_MUTED_TRUMPET:
        case IMF_INSTRUMENT_FRENCH_HORN:
        case IMF_INSTRUMENT_BRASS_SECTION:
        case IMF_INSTRUMENT_SYNTHBRASS_1:
        case IMF_INSTRUMENT_SYNTHBRASS_2:
        case IMF_INSTRUMENT_SOPRANO_SAX:
        case IMF_INSTRUMENT_ALTO_SAX:
        case IMF_INSTRUMENT_TENOR_SAX:
        case IMF_INSTRUMENT_BARITONE_SAX:
        case IMF_INSTRUMENT_OBOE:
        case IMF_INSTRUMENT_ENGLISH_HORN:
        case IMF_INSTRUMENT_BASSOON:
        case IMF_INSTRUMENT_CLARINET:
        case IMF_INSTRUMENT_PICCOLO:
        case IMF_INSTRUMENT_FLUTE:
        case IMF_INSTRUMENT_RECORDER:
        case IMF_INSTRUMENT_PAN_FLUTE:
        case IMF_INSTRUMENT_BLOWN_BOTTLE:
        case IMF_INSTRUMENT_SHAKUHACHI:
        case IMF_INSTRUMENT_WHISTLE:
        case IMF_INSTRUMENT_OCARINA:
            PROGRAM_SAW_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_SITAR:
        case IMF_INSTRUMENT_BANJO:
        case IMF_INSTRUMENT_SHAMISEN:
        case IMF_INSTRUMENT_KOTO:
        case IMF_INSTRUMENT_KALIMBA:
        case IMF_INSTRUMENT_BAG_PIPE:
        case IMF_INSTRUMENT_FIDDLE:
        case IMF_INSTRUMENT_SHANAI:
        case IMF_INSTRUMENT_TINKLE_BELL:
        case IMF_INSTRUMENT_AGOGO:
        case IMF_INSTRUMENT_STEEL_DRUMS:
        case IMF_INSTRUMENT_WOODBLOCK:
        case IMF_INSTRUMENT_TAIKO_DRUM:
        case IMF_INSTRUMENT_MELODIC_TOM:
        case IMF_INSTRUMENT_SYNTH_DRUM:
        case IMF_INSTRUMENT_REVERSE_CYMBAL:
        case IMF_INSTRUMENT_GUITAR_FRET_NOISE:
        case IMF_INSTRUMENT_BREATH_NOISE:
        case IMF_INSTRUMENT_SEASHORE:
        case IMF_INSTRUMENT_BIRD_TWEET:
        case IMF_INSTRUMENT_TELEPHONE_RING:
        case IMF_INSTRUMENT_HELICOPTER:
            PROGRAM_SAW_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;
    }

}

void ay8910_set_frequency_vars( Environment * _environment, char * _channels, char * _frequency ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    outline1("LD A, (%s)", _frequency );
    outline0("LD E, A" );
    outline1("LD A, (%s)", address_displacement(_environment, _frequency, "1") );
    outline0("LD D, A" );
    if ( _channels ) {
        outline1("LD A, (%s)", _channels );
    } else {
        outline0("LD A, $7" );
    }

    outline0("CALL AY8910FREQ");

}

void ay8910_set_pitch_vars( Environment * _environment, char * _channels, char * _pitch ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    outline1("LD A, (%s)", _pitch );
    outline0("LD E, A" );
    outline1("LD A, (%s)", address_displacement(_environment, _pitch, "1") );
    outline0("LD D, A" );
    if ( _channels ) {
        outline1("LD A, (%s)", _channels );
    } else {
        outline0("LD A, $7" );
    }

    outline0("CALL AY8910PROGFREQ");

}

void ay8910_set_note_vars( Environment * _environment, char * _channels, char * _note ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    outline0("LD HL, AY8910FREQTABLE");
    outline1("LD A, (%s)", _note);
    outline0("LD E, A");
    outline0("LD A, 0");
    outline0("LD D, A");
    outline0("SLA E");
    outline0("RL D");
    outline0("ADD HL, DE");
    outline0("LD A, (HL)");
    outline0("LD E, A");
    outline0("INC HL");
    outline0("LD A, (HL)");
    outline0("LD D, A");

    if ( _channels ) {
        outline1("LD A, (%s)", _channels );
    } else {
        outline0("LD A, $7" );
    }

    outline0("CALL AY8910PROGFREQ");

}

void ay8910_stop_vars( Environment * _environment, char * _channels ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    outline1("LD A, (%s)", _channels );
    outline0("CALL AY8910STOP");

}

void ay8910_music( Environment * _environment, char * _music, int _size ) {

    deploy( ay8910vars, src_hw_ay8910_vars_asm );
    deploy( ay8910startup, src_hw_ay8910_startup_asm );

    outline0("LD A, $0");
    outline0("LD (AY8910JIFFIES), A");
    outline0("LD (AY8910TMPOFS), A");
    outline0("LD A, $1");
    outline0("LD (AY8910MUSICREADY), A");
    outline1("LD HL, %s", _music);
    outline0("LD (AY8910TMPPTR), HL");
    outline1("LD A, $%2.2x", ( _size>>8 ) & 0xff);
    outline0("LD (AY8910BLOCKS), A");
    outline1("LD A, $%2.2x", _size & 0xff );
    outline0("LD (AY8910LASTBLOCK), A");
    if ( _size > 255 ) {
        outline0("LD A, $ff");
    }
    outline0("LD (AY8910TMPLEN), A");

}

#endif