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

#if defined(__pc128op__) || defined(__coco__) || defined(__coco3__)

#include "../ugbc.h"

static unsigned int SOUND_FREQUENCIES[] = {
    255,		255,		255,		255,		255,		255,		255,		255,		255,		255,
    255,		255,		255,		255,		255,		255,		255,		255,		255,		255,
    255,		255,		255,        255,        255,        255,        255,        255,        255,        255,
    255,        240,        227,        214,        202,        191,        180,        170,        160,        151,
    143,        135,        127,        120,        113,        107,        101,        95,         90,         85,
    80,         75,         71,         67,         63,         60,         56,         53,         50,         47,
    45,         42,         40,         37,         35,         33,         31,         30,         28,         26,
    25,         23,         22,         21,         20,         18,         17,         16,         15,         15,
    14,         13,         12,         11,         11,         10,         10,         9,          8,          8,
    7,          7,          7,          6,          6,          5,          5,          5,          5,          4,
    4,          4,          3,          3,          3,          3,          3,          2,          2,          2,
    2,          2,          2,          2,          1,          1,          1,          1,          1           
};

void sn76489m_initialization( Environment * _environment ) {

    variable_import( _environment, "SN76489MUSICREADY", VT_BYTE, 0 );
    variable_global( _environment, "SN76489MUSICREADY" );
    variable_import( _environment, "SN76489MUSICPAUSE", VT_BYTE, 0 );
    variable_global( _environment, "SN76489MUSICPAUSE" );
    variable_import( _environment, "SN76489MUSICLOOP", VT_BYTE, 0 );
    variable_global( _environment, "SN76489MUSICLOOP" );
    variable_import( _environment, "SN76489BLOCKS", VT_BYTE, 0 );
    variable_global( _environment, "SN76489BLOCKS" );
    variable_import( _environment, "SN76489LASTBLOCK", VT_BYTE, 0 );
    variable_global( _environment, "SN76489LASTBLOCK" );
    variable_import( _environment, "SN76489TMPPTR2", VT_ADDRESS, 0 );
    variable_global( _environment, "SN76489TMPPTR2" );
    variable_import( _environment, "SN76489TMPPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "SN76489TMPPTR" );
    variable_import( _environment, "SN76489TMPOFS", VT_BYTE, 0 );
    variable_global( _environment, "SN76489TMPOFS" );
    variable_import( _environment, "SN76489BANK", VT_BYTE, 0xff );
    variable_global( _environment, "SN76489BANK" );
    variable_import( _environment, "SN76489TMPLEN", VT_BYTE, 0 );
    variable_global( _environment, "SN76489TMPLEN" );
    variable_import( _environment, "SN76489JIFFIES", VT_BYTE, 0 );
    variable_global( _environment, "SN76489JIFFIES" );

    variable_import( _environment, "SN76489BLOCKS_BACKUP", VT_BYTE, 0 );
    variable_global( _environment, "SN76489BLOCKS_BACKUP" );
    variable_import( _environment, "SN76489LASTBLOCK_BACKUP", VT_BYTE, 0 );
    variable_global( _environment, "SN76489LASTBLOCK_BACKUP" );
    variable_import( _environment, "SN76489TMPPTR_BACKUP", VT_ADDRESS, 0 );
    variable_global( _environment, "SN76489TMPPTR_BACKUP" );

    cpu_call( _environment, "SN76489STARTUP" );

}

void sn76489m_finalization( Environment * _environment ) {

    if ( ! _environment->deployed.sn76489startup ) {
        cpu_label( _environment, "SN76489STARTUP" );
        outline0( "RTS" );
        cpu_label( _environment, "MUSICPLAYER" );
        outline0( "RTS" );
    } else {
        deploy( sn76489startup2, src_hw_sn76489m_startup2_asm );
    }

}

void sn76489m_start( Environment * _environment, int _channels ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    if ( _channels & 0x01 ) {
        outline0("JSR SN76489START0");
    }
    if ( _channels & 0x02 ) {
        outline0("JSR SN76489START1");
    }
    if ( _channels & 0x04 ) {
        outline0("JSR SN76489START2");
    }

}

void sn76489m_set_volume( Environment * _environment, int _channels, int _volume ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    outline1("LDB #$%2.2x", ( _volume & 0x0f ) );
    outline1("LDA #$%2.2x", ( _channels ) );
    outline0("JSR SN76489STARTVOL");

}

#define     PROGRAM_FREQUENCY( c, f ) \
    outline1("LDU #$%4.4x", ( f ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SN76489PROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SN76489PROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SN76489PROGFREQ2" );

#define     PROGRAM_FREQUENCY_V( c, f ) \
    outline1("LDU %s", f ); \
    if ( c == NULL ) { \
        outline0("LDA #$7"); \
    } else { \
        outline1("LDA %s", c ); \
    } \
    outline0("JSR SN76489FREQ" );

#define     PROGRAM_FREQUENCY_SV( c, f ) \
    outline1("LD U #$%4.4x", f ); \
    if ( c == NULL ) { \
        outline0("LDA #$7"); \
    } else { \
        outline1("LDA %s", c ); \
    } \
    outline0("JSR SN76489FREQ" );

#define     PROGRAM_DURATION( c, d ) \
    outline1("LDU #$%4.4x", ( d ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SN76489PROGDUR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SN76489PROGDUR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SN76489PROGDUR2" );

#define     WAIT_DURATION( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SN76489WAITDUR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SN76489WAITDUR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SN76489WAITDUR2" );

#define     PROGRAM_PITCH( c, f ) \
    outline1("LDU $%4.4x", ( f & 0xff ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL SN76489PROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL SN76489PROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL SN76489PROGFREQ2" );

#define     PROGRAM_PITCH_V( c, f ) \
    outline1("LDU %s", f ); \
    if ( c == NULL ) { \
        outline0("LDA #$7"); \
    } else { \
        outline1("LDA %s", c ); \
    } \
    outline0("CALL SN76489PROGFREQ" );

#define     PROGRAM_PITCH_SV( c, f ) \
    outline1("LDU #$%4.4x", f); \
    if ( c == NULL ) { \
        outline0("LDA #$7"); \
    } else { \
        outline1("LDA %s", c ); \
    } \
    outline0("CALL SN76489PROGFREQ" );

#define     STOP_FREQUENCY( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("JSR SN76489STOP0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR SN76489STOP1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR SN76489STOP2" );

#define     STOP_FREQUENCY_V( c ) \
    if ( c == NULL ) { \
        outline0("LDA #$7"); \
    } else { \
        outline1("LDA %s", c ); \
    } \
    outline0("JSR SN76489STOP" );

#define     STOP_FREQUENCY_SV( c ) \
    if ( c == NULL ) { \
        outline0("LDA #$7"); \
    } else { \
        outline1("LDA %s", c ); \
    } \
    outline0("JSR SN76489STOP" );

void sn76489m_set_program( Environment * _environment, int _channels, int _program ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            // PROGRAM_NOISE(_channels);
            // PROGRAM_ATTACK_DECAY(_channels, 2, 11);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_GUNSHOT:
            // PROGRAM_NOISE(_channels);
            // PROGRAM_ATTACK_DECAY(_channels, 2, 4);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 0, 1);
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
            // PROGRAM_TRIANGLE(_channels);
            // PROGRAM_ATTACK_DECAY(_channels, 4, 2);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
            // PROGRAM_PULSE(_channels, 1024);
            // PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 14, 3);
            break;

        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
            // PROGRAM_TRIANGLE(_channels);
            // PROGRAM_ATTACK_DECAY(_channels, 2, 10);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 12, 14);
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
            // PROGRAM_TRIANGLE(_channels);
            // PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
            // PROGRAM_PULSE(_channels, 128);
            // PROGRAM_ATTACK_DECAY(_channels, 10, 10);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
            // PROGRAM_PULSE(_channels, 128);
            // PROGRAM_ATTACK_DECAY(_channels, 1, 2);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 4, 3);
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
            // PROGRAM_TRIANGLE(_channels);
            // PROGRAM_ATTACK_DECAY(_channels, 2, 10);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 12, 14);
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
            // PROGRAM_PULSE(_channels, 128);
            // PROGRAM_ATTACK_DECAY(_channels, 10, 10);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
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
            // PROGRAM_NOISE(_channels);
            // PROGRAM_ATTACK_DECAY(_channels, 1, 14);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
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
            // PROGRAM_SAW(_channels);
            // PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
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
            // PROGRAM_SAW(_channels);
            // PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            // PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;
    }

}

void sn76489m_set_parameter( Environment * _environment, int _channels, int _parameter, int _value ) {

}

void sn76489m_set_frequency( Environment * _environment, int _channels, int _frequency ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    PROGRAM_FREQUENCY( _channels, _frequency );

}

void sn76489m_set_pitch( Environment * _environment, int _channels, int _pitch ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    PROGRAM_PITCH( _channels, _pitch );

}

void sn76489m_set_note( Environment * _environment, int _channels, int _note ) {

    sn76489m_set_pitch( _environment, _channels, SOUND_FREQUENCIES[_note] );

}

void sn76489m_stop( Environment * _environment, int _channels ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    STOP_FREQUENCY( _channels );

}

void sn76489m_start_var( Environment * _environment, char * _channels ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }
    outline0("JSR SN76489START");

}

void sn76489m_set_volume_vars( Environment * _environment, char * _channels, char * _volume ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    outline1("LDB %s", _volume );
    outline0("LSRB" );
    outline0("LSRB" );
    outline0("LSRB" );
    outline0("LSRB" );
    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA $%2.2x" );
    }
    outline0("JSR SN76489STARTVOL");

}

void sn76489m_set_volume_semi_var( Environment * _environment, char * _channel, int _volume ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    outline1("LDB #$%2.2x", _volume );
    if ( _channel ) {
        outline1("LDA %s", _channel );
    } else {
        outline0("LDA $%2.2x" );
    }
    outline0("JSR SN76489STARTVOL");

}

void sn76489m_set_program_semi_var( Environment * _environment, char * _channels, int _program ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            // PROGRAM_NOISE_SV(_channels);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 2, 11);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_GUNSHOT:
            // PROGRAM_NOISE_SV(_channels);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 2, 4);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 0, 1);
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
            // PROGRAM_TRIANGLE_SV(_channels);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 4, 2);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
            // PROGRAM_PULSE_SV(_channels, 1024);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 3);
            break;

        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
            // PROGRAM_TRIANGLE_SV(_channels);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 2, 10);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 12, 14);
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
            // PROGRAM_TRIANGLE_SV(_channels);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
            // PROGRAM_PULSE_SV(_channels, 128);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 10, 10);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
            // PROGRAM_PULSE_SV(_channels, 128);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 1, 2);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 4, 3);
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
            // PROGRAM_TRIANGLE_SV(_channels);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 2, 10);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 12, 14);
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
            // PROGRAM_PULSE_SV(_channels, 128);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 10, 10);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
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
            // PROGRAM_NOISE_SV(_channels);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 1, 14);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
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
            // PROGRAM_SAW_SV(_channels);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
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
            // PROGRAM_SAW_SV(_channels);
            // PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            // PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;
    }

}

void sn76489m_set_frequency_vars( Environment * _environment, char * _channels, char * _frequency ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    outline1("LDU %s", _frequency );
    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }

    outline0("JSR SN76489FREQ");

}

void sn76489m_set_pitch_vars( Environment * _environment, char * _channels, char * _pitch ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    outline1("LDU %s", _pitch );
    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }

    outline0("JSR SN76489PROGFREQ");

}

void sn76489m_set_note_vars( Environment * _environment, char * _channels, char * _note ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    outline0("LDX SN76489FREQTABLE");
    outline1("LDB %s", _note);
    outline0("CLRA");
    outline0("LSLB");
    outline0("ROLA");
    outline0("LDU D,X");
    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }

    outline0("JSR SN76489PROGFREQ");

}

void sn76489m_stop_vars( Environment * _environment, char * _channels ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }
    outline0("JSR SN76489STOP");

}

void sn76489m_music( Environment * _environment, char * _music, int _size, int _loop, int _type, int _bank ) {

    deploy_deferred( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy_deferred( sn76489startup, src_hw_sn76489m_startup_asm );

    outline0("ORCC #$50");
    outline1("LDA #$%2.2x", _bank );
    outline0("STA SN76489BANK");
    outline1("LDA #$%2.2x", _loop );
    outline0("STA SN76489MUSICLOOP");
    outline1("LDX %s", _music);
    outline1("LDB #$%4.4x", _size);
    outline0("JSR MUSICPLAYERRESET");
    outline1("LDA #$%2.2x", _type );
    outline0("STA SN76489MUSICTYPE" );
    outline0("ANDCC #$AF");

}

void sn76489m_set_duration( Environment * _environment, int _channel, int _duration ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    PROGRAM_DURATION( _channel, _duration );

}

void sn76489m_wait_duration( Environment * _environment, int _channel ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    WAIT_DURATION( _channel );

}

void sn76489m_set_duration_vars( Environment * _environment, char * _channel, char * _duration ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    if ( _duration ) {
        outline1("LDU %s", _duration );
    } else {
        outline0("LDU #50" );
    }
    if ( _channel ) {
        outline1("LDA %s", _channel );
    } else {
        outline0("LDA #$7" );
    }

    outline0("JSR SN76489PROGDUR" );

}

void sn76489m_wait_duration_vars( Environment * _environment, char *  _channel ) {

    deploy( sn76489vars, src_hw_sn76489m_vars_asm );
    deploy( sn76489startup, src_hw_sn76489m_startup_asm );

    if ( _channel ) {
        outline1("LDA %s", _channel );
    } else {
        outline0("LDA #$7" );
    }
    
    outline0("JSR SN76489WAITDUR" );

}

#endif