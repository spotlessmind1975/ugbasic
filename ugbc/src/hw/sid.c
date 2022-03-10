/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

#ifdef __c64__

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

void sid_initialization( Environment * _environment ) {

    cpu_call( _environment, "SIDSTARTUP" );

}

void sid_finalization( Environment * _environment ) {

    if ( ! _environment->deployed.sidstartup ) {
        cpu_label( _environment, "SIDSTARTUP" );
        outline0( "RTS" );
    }

}

void sid_start( Environment * _environment, int _channels ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    if ( _channels & 0x01 ) {
        outline0("JSR SIDSTART0");
    }
    if ( _channels & 0x02 ) {
        outline0("JSR SIDSTART1");
    }
    if ( _channels & 0x04 ) {
        outline0("JSR SIDSTART2");
    }

}

void sid_set_volume( Environment * _environment, int _channels, int _volume ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    outline1("LDX #%2.2x", ( _volume & 0x0f ) );
    outline0("JSR SIDSTARTVOL");

}

#define     PROGRAM_FREQUENCY( c, f ) \
    outline1("LDX #$%2.2x", ( ( ( f * 0xffff ) / 4000 ) & 0xff ) ); \
    outline1("LDY #$%2.2x", ( ( ( ( f * 0xffff ) / 4000 ) >> 8 ) & 0xff ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SIDPROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SIDPROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SIDPROGFREQ2" );

#define     PROGRAM_FREQUENCY_V( c, f ) \
    outline1("LDA %s", c ); \
    outline1("LDX %s", f ); \
    outline1("LDY %s+1", f ); \
    outline0("JSR SIDFREQ" );

#define     PROGRAM_PITCH( c, f ) \
    outline1("LDX #$%2.2x", ( f & 0xff ) ); \
    outline1("LDY #$%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SIDPROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SIDPROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SIDPROGFREQ2" );

#define     PROGRAM_PITCH_V( c, f ) \
    outline1("LDA %s", c ); \
    outline1("LDX %s", f ); \
    outline1("LDY %s+1", f ); \
    outline0("JSR SIDPROGFREQ" );

#define     PROGRAM_PULSE( c, p ) \
    outline1("LDX #$%2.2x", ( p & 0xff ) ); \
    outline1("LDY #$%2.2x", ( ( p >> 8 ) & 0xff ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SIDPROGPULSE0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SIDPROGPULSE1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SIDPROGPULSE2" );

#define     PROGRAM_PULSE_V( c, p ) \
    outline1("LDA %s", c ); \
    outline1("LDX %s", p ); \
    outline1("LDY %s+1", p ); \
    outline0("JSR SIDPROGPULSE" );

#define     PROGRAM_NOISE( c ) \
    outline0("LDX #$82" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SIDPROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SIDPROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SIDPROGCTR2" );

#define     PROGRAM_NOISE_V( c, p ) \
    outline1("LDA %s", c ); \
    outline0("LDX #$82" ); \
    outline0("JSR SIDPROGCTR" );

#define     PROGRAM_SAW( c ) \
    outline0("LDX #$22" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SIDPROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SIDPROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SIDPROGCTR2" );

#define     PROGRAM_SAW_V( c, p ) \
    outline1("LDA %s", c ); \
    outline0("LDX #$22" ); \
    outline0("JSR SIDPROGCTR" );

#define     PROGRAM_TRIANGLE( c ) \
    outline0("LDX #$12" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SIDPROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SIDPROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SIDPROGCTR2" );

#define     PROGRAM_TRIANGLE_V( c ) \
    outline1("LDA %s", c ); \
    outline0("LDX #$12" ); \
    outline0("JSR SIDPROGCTR" );

#define     PROGRAM_SAW_TRIANGLE( c ) \
    outline0("LDX #$32" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SIDPROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SIDPROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SIDPROGCTR2" );

#define     PROGRAM_SAW_TRIANGLE_V( c ) \
    outline1("LDA %s", c ); \
    outline0("LDX #$32" ); \
    outline0("JSR SIDPROGCTR" );

#define     PROGRAM_ATTACK_DECAY( c, a, d ) \
    outline1("LDX #$%2.2x", ( a & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( d & 0x0f ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SIDPROGAD0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SIDPROGAD1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SIDPROGAD2" );

#define     PROGRAM_ATTACK_DECAY_V( c, a, d ) \
    outline1("LDA %s", c ); \
    outline1("LDX %s", a ); \
    outline1("LDY %s", d ); \
    outline0("JSR SIDPROGAD" );

#define     PROGRAM_SUSTAIN_RELEASE( c, s, r ) \
    outline1("LDX #$%2.2x", ( s & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( r & 0x0f ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SIDPROGSR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SIDPROGSR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SIDPROGSR2" );

#define     PROGRAM_SUSTAIN_RELEASE_V( c, s, r ) \
    outline1("LDA %s", c ); \
    outline1("LDX %s", s ); \
    outline1("LDY %s", r ); \
    outline0("JSR SIDPROGSR" );

#define     STOP_FREQUENCY( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SIDSTOP0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SIDSTOP1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SIDSTOP2" );

#define     STOP_FREQUENCY_V( c ) \
    outline1("LDA %s", c ); \
    outline0("JSR SIDSTOP" );

void sid_set_program( Environment * _environment, int _channels, int _program ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            PROGRAM_NOISE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 11);
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
        case IMF_INSTRUMENT_GUNSHOT:
            PROGRAM_SAW(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;
    }

}

void sid_set_parameter( Environment * _environment, int _channels, int _parameter, int _value ) {

}

void sid_set_frequency( Environment * _environment, int _channels, int _frequency ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    PROGRAM_FREQUENCY( _channels, _frequency );

}

void sid_set_pitch( Environment * _environment, int _channels, int _pitch ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    PROGRAM_PITCH( _channels, _pitch );

}

void sid_set_note( Environment * _environment, int _channels, int _note ) {

    sid_set_pitch( _environment, _channels, SOUND_FREQUENCIES[_note] );

}

void sid_stop( Environment * _environment, int _channels ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    STOP_FREQUENCY( _channels );

}

void sid_start_var( Environment * _environment, char * _channels ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }
    outline0("JSR SIDSTART");

}

void sid_set_volume_vars( Environment * _environment, char * _channels, char * _volume ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    outline1("LDX %s", _volume );
    outline0("JSR SIDSTARTVOL");

}

void sid_set_frequency_vars( Environment * _environment, char * _channels, char * _frequency ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }
    outline1("LDX %s", _frequency );
    outline1("LDY %s+1", _frequency );

    outline0("JSR SIDFREQ");

}

void sid_set_pitch_vars( Environment * _environment, char * _channels, char * _pitch ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }
    outline1("LDX %s", _pitch );
    outline1("LDY %s+1", _pitch );

    outline0("JSR SIDPROGFREQ");

}

void sid_set_note_vars( Environment * _environment, char * _channels, char * _note ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    outline0("LDA #<SIDFREQTABLE");
    outline0("STA TMPPTR");
    outline0("LDA #>SIDFREQTABLE");
    outline0("STA TMPPTR+1");
    outline1("LDY %s", _note);
    outline0("TYA");
    outline0("ASL");
    outline0("TAY");
    outline0("LDA (TMPPTR),Y");
    outline0("TAX");
    outline0("INY");
    outline0("LDA (TMPPTR),Y");
    outline0("TAY");

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }

    outline0("JSR SIDPROGFREQ");

}

void sid_stop_vars( Environment * _environment, char * _channels ) {

    deploy( sidvars, src_hw_sid_vars_asm );
    deploy( sidstartup, src_hw_sid_startup_asm );

    outline1("LDA %s", _channels );
    outline0("JSR SIDSTOP");

}

#endif