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

#if defined(__atari__) || defined(__atarixl__)

#include "../ugbc.h"

static unsigned int SOUND_FREQUENCIES[] = {
    256,		256,		256,		256,		256,		256,		256,		256,		256,		256,
    256,		256,		256,		256,		256,		256,		256,		256,		256,		256,
    256,		256,		256,		256,        256,        256,        256,        256,        256,        256,
    256,        256,        256,        256,        256,        256,        256,        256,        256,        256,
    256,        256,        256,        256,        256,        256,        256,        256,        256,        256,
    256,        256,        256,        256,        256,        256,        256,        256,        256,        243,
    230,        217,        204,        193,        182,        172,        162,        153,        144,        136,
    128,        121,        114,        108,        102,        96,         91,         85,         81,         76,
    72,         68,         64,         60,         57,         53,         50,         47,         45,         42,
    40,         37,         35,         33,         31,         30,         28,         26,         25,         23,
    22,         21,         19,         18,         17,         16,         15,         14,         13,         12,
    11,         10,         9,          8,          7,          6,          5,          4,          3,          2,
    1
};

void pokey_initialization( Environment * _environment ) {

    outline0("JSR POKEYSTARTUP");

}

void pokey_finalization( Environment * _environment ) {

    if ( ! _environment->deployed.pokeystartup ) {
        cpu_label( _environment, "POKEYSTARTUP" );
        outline0( "RTS" );
        cpu_label( _environment, "MUSICPLAYER" );
        outline0( "RTS" );
    }

}

void pokey_start( Environment * _environment, int _channels ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    if ( _channels & 0x01 ) {
        outline0("JSR POKEYSTART0");
    }
    if ( _channels & 0x02 ) {
        outline0("JSR POKEYSTART1");
    }
    if ( _channels & 0x04 ) {
        outline0("JSR POKEYSTART2");
    }
    if ( _channels & 0x08 ) {
        outline0("JSR POKEYSTART3");
    }

}

void pokey_set_volume( Environment * _environment, int _channels, int _volume ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    // The lower 4 bits of the audio control register contain a 4-bit number
    // that specifies the volume of the sound. A zero in these bits means 
    // zero volume, and a 15 means as loud as possible. The sum of the volumes 
    // of the four channels should not exceed 32, since this forces 
    // overmodulation of the audio output. The sound produced tends to actually
    // lose volume and assume a buzzing quality.

    outline1("LDA #%2.2x", _channels );
    outline1("LDX #%2.2x", ( _volume >> 5 ) & 0x07 );
    outline0("JSR POKEYSETVOL");

}

#define     PROGRAM_FREQUENCY( c, f ) \
    outline1("LDX #$%2.2x", ( f ) & 0xff ); \
    outline1("LDY #$%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR POKEYPROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR POKEYPROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR POKEYPROGFREQ2" ); \
    if ( ( c & 0x08 ) ) \
        outline0("JSR POKEYPROGFREQ3" );

#define     PROGRAM_FREQUENCY_V( c, f ) \
    outline1("LDA %s", ( c == NULL ? "#$f" : c ) ); \
    outline1("LDX %s", f ); \
    outline1("LDY %s", address_displacement(_environment, f, "1") ); \
    outline0("JSR POKEYFREQ" );

#define     PROGRAM_FREQUENCY_SV( c, f ) \
    outline1("LDX #$%2.2x", ( f ) & 0xff ) ); \
    outline1("LDY #$%2.2x", ( ( f ) >> 8 ) & 0xff ); \
    outline1("LDA %s", ( c == NULL ? "#$f" : c ) ); \
    outline0("JSR POKEYFREQ" );

#define     PROGRAM_PITCH( c, f ) \
    outline1("LDX #$%2.2x", ( f & 0xff ) ); \
    outline1("LDY #$%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR POKEYPROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR POKEYPROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR POKEYPROGFREQ2" ); \
    if ( ( c & 0x08 ) ) \
        outline0("JSR POKEYPROGFREQ3" );

#define     PROGRAM_DURATION( c, d ) \
    outline1("LDX #$%2.2x", ( d & 0xff ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR POKEYSETDURATION0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR POKEYSETDURATION1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR POKEYSETDURATION2" ); \
    if ( ( c & 0x08 ) ) \
        outline0("JSR POKEYSETDURATION3" );

#define     PROGRAM_PITCH_V( c, f ) \
    outline1("LDA %s", ( c == NULL ? "#$f" : c ) ); \
    outline1("LDX %s", f ); \
    outline1("LDY %s", address_displacement(_environment, f, "1") ); \
    outline0("JSR POKEYPROGFREQ" );

#define     PROGRAM_PITCH_SV( c, f ) \
    outline1("LDX #$%2.2x", ( f & 0xff ) ); \
    outline1("LDY #$%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    outline1("LDA %s", ( c == NULL ? "#$f" : c ) ); \
    outline0("JSR POKEYPROGFREQ" );

#define     STOP_FREQUENCY( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("JSR POKEYSTOP0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR POKEYSTOP1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR POKEYSTOP2" ); \
    if ( ( c & 0x08 ) ) \
        outline0("JSR POKEYSTOP3" );

#define     STOP_FREQUENCY_V( c ) \
    outline1("LDA %s", ( c == NULL ? "#$f" : c ) ); \
    outline0("JSR POKEYSTOP" );

#define     STOP_FREQUENCY_SV( c ) \
    outline1("LDA %s", ( c == NULL ? "#$f" : c ) ); \
    outline0("JSR POKEYSTOP" );

#define     PROGRAM_DISTORTION( c, v ) \
    outline1("LDX #$%2.2x", v ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR POKEYPROGDIST0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR POKEYPROGDIST1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR POKEYPROGDIST2" );

#define     PROGRAM_DISTORTION_SV( c, v ) \
    outline1("LDA %s", ( c == NULL ? "#$f" : c ) ); \
    outline1("LDX #$%2.2x", v ); \
    outline0("JSR POKEYPROGDIST" );

void pokey_set_program( Environment * _environment, int _channels, int _program ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    switch (_program) {

        case IMF_INSTRUMENT_APPLAUSE:
        case IMF_INSTRUMENT_FX_4_ATMOSPHERE:
        case IMF_INSTRUMENT_TIMPANI:
        case IMF_INSTRUMENT_ORCHESTRA_HIT:
            PROGRAM_PITCH( _channels, 0 );
            PROGRAM_DISTORTION( _channels, 0x02 );
            break;

        case IMF_INSTRUMENT_EXPLOSION:
            PROGRAM_PITCH( _channels, 0 );
            PROGRAM_DISTORTION( _channels, 0x02 );
            break;

        case IMF_INSTRUMENT_GUNSHOT:
            PROGRAM_PITCH( _channels, 0x80 );
            PROGRAM_DISTORTION( _channels, 0x02 );
            break;

        case IMF_INSTRUMENT_FX_1_RAIN:
        case IMF_INSTRUMENT_FX_2_SOUNDTRACK:
        case IMF_INSTRUMENT_FX_3_CRYSTAL:
        case IMF_INSTRUMENT_FX_5_BRIGHTNESS:
        case IMF_INSTRUMENT_FX_6_GOBLINS:
        case IMF_INSTRUMENT_FX_7_ECHOES:
        case IMF_INSTRUMENT_FX_8_SCI_FI:
        case IMF_INSTRUMENT_PAD_5_BOWED:
        case IMF_INSTRUMENT_PAD_6_METALLIC:
        case IMF_INSTRUMENT_PAD_7_HALO:
        case IMF_INSTRUMENT_PAD_8_SWEEP:
            PROGRAM_PITCH( _channels, 0x0 );
            PROGRAM_DISTORTION( _channels, 0x09 );
            break;

        case IMF_INSTRUMENT_HELICOPTER:
            PROGRAM_PITCH( _channels, 0xd0 );
            PROGRAM_DISTORTION( _channels, 0x0d );
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:
        case IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:
        case IMF_INSTRUMENT_HONKY_TONK_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_PIANO1:
        case IMF_INSTRUMENT_ELECTRIC_PIANO2:
        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
        case IMF_INSTRUMENT_PAD_3_POLYSYNTH:
        case IMF_INSTRUMENT_DRAWBAR_ORGAN:
        case IMF_INSTRUMENT_PERCUSSIVE_ORGAN:
        case IMF_INSTRUMENT_ROCK_ORGAN:
        case IMF_INSTRUMENT_CHURCH_ORGAN:
        case IMF_INSTRUMENT_REED_ORGAN:
        case IMF_INSTRUMENT_ACCORDION:
        case IMF_INSTRUMENT_HARMONICA:
        case IMF_INSTRUMENT_TANGO_ACCORDION:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
        case IMF_INSTRUMENT_LEAD_8_BASS_LEAD:
        case IMF_INSTRUMENT_ACOUSTIC_BASS:
        case IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:
        case IMF_INSTRUMENT_ELECTRIC_BASS_PICK:
        case IMF_INSTRUMENT_FRETLESS_BASS:
        case IMF_INSTRUMENT_SLAP_BASS_1:
        case IMF_INSTRUMENT_SLAP_BASS_2:
        case IMF_INSTRUMENT_SYNTH_BASS_1:
        case IMF_INSTRUMENT_SYNTH_BASS_2:
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
        case IMF_INSTRUMENT_PAD_4_CHOIR:
        case IMF_INSTRUMENT_CHOIR_AAHS:
        case IMF_INSTRUMENT_VOICE_OOHS:
        case IMF_INSTRUMENT_SYNTH_VOICE:
        case IMF_INSTRUMENT_LEAD_4_CHIFF:
        case IMF_INSTRUMENT_LEAD_5_CHARANG:
        case IMF_INSTRUMENT_LEAD_6_VOICE:
        case IMF_INSTRUMENT_LEAD_7_FIFTHS:
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
            PROGRAM_DISTORTION( _channels, 0x0a );
            break;

        default:
            break;

    }

}

void pokey_set_parameter( Environment * _environment, int _channels, int _parameter, int _value ) {

}

void pokey_set_frequency( Environment * _environment, int _channels, int _frequency ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    PROGRAM_FREQUENCY( _channels, _frequency );

}

void pokey_set_pitch( Environment * _environment, int _channels, int _pitch ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    PROGRAM_PITCH( _channels, _pitch );

}

void pokey_set_duration( Environment * _environment, int _channels, int _duration ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    PROGRAM_DURATION( _channels, _duration );

}

void pokey_set_note( Environment * _environment, int _channels, int _note ) {

    pokey_set_pitch( _environment, _channels, SOUND_FREQUENCIES[_note] );

}

void pokey_stop( Environment * _environment, int _channels ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    STOP_FREQUENCY( _channels );

}

void pokey_start_var( Environment * _environment, char * _channels ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    outline1("LDA %s", ( _channels == NULL ? "#$f" : _channels ) );
    outline0("JSR POKEYSTART");

}

void pokey_set_volume_vars( Environment * _environment, char * _channels, char * _volume ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    outline1("LDA %s", _volume );
    outline0("LSR" );
    outline0("LSR" );
    outline0("LSR" );
    outline0("LSR" );
    outline0("LSR" );
    outline0("TAX" );
    outline0("JSR POKEYSETVOL");

}

void pokey_set_volume_semi_var( Environment * _environment, char * _channel, int _volume ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    outline1("LDA %s", _channel );
    outline1("LDX #$%2.2x", _volume );
    outline0("JSR POKEYSETVOL");

}

void pokey_set_program_semi_var( Environment * _environment, char * _channels, int _program ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    switch (_program) {

        case IMF_INSTRUMENT_APPLAUSE:
        case IMF_INSTRUMENT_FX_4_ATMOSPHERE:
        case IMF_INSTRUMENT_TIMPANI:
        case IMF_INSTRUMENT_ORCHESTRA_HIT:
            PROGRAM_PITCH_SV( _channels, 0 );
            PROGRAM_DISTORTION_SV( _channels, 0x01 );
            break;

        case IMF_INSTRUMENT_EXPLOSION:
            PROGRAM_PITCH_SV( _channels, 0xff );
            PROGRAM_DISTORTION_SV( _channels, 0x09 );
            break;

        case IMF_INSTRUMENT_GUNSHOT:
            PROGRAM_PITCH_SV( _channels, 0x80 );
            PROGRAM_DISTORTION_SV( _channels, 0x09 );
            break;

        case IMF_INSTRUMENT_FX_1_RAIN:
        case IMF_INSTRUMENT_FX_2_SOUNDTRACK:
        case IMF_INSTRUMENT_FX_3_CRYSTAL:
        case IMF_INSTRUMENT_FX_5_BRIGHTNESS:
        case IMF_INSTRUMENT_FX_6_GOBLINS:
        case IMF_INSTRUMENT_FX_7_ECHOES:
        case IMF_INSTRUMENT_FX_8_SCI_FI:
        case IMF_INSTRUMENT_PAD_5_BOWED:
        case IMF_INSTRUMENT_PAD_6_METALLIC:
        case IMF_INSTRUMENT_PAD_7_HALO:
        case IMF_INSTRUMENT_PAD_8_SWEEP:
            PROGRAM_PITCH_SV( _channels, 0x0 );
            PROGRAM_DISTORTION_SV( _channels, 0x09 );
            break;

        case IMF_INSTRUMENT_HELICOPTER:
            PROGRAM_PITCH_SV( _channels, 0xd0 );
            PROGRAM_DISTORTION_SV( _channels, 0x0d );
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:
        case IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:
        case IMF_INSTRUMENT_HONKY_TONK_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_PIANO1:
        case IMF_INSTRUMENT_ELECTRIC_PIANO2:
        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
        case IMF_INSTRUMENT_PAD_3_POLYSYNTH:
        case IMF_INSTRUMENT_DRAWBAR_ORGAN:
        case IMF_INSTRUMENT_PERCUSSIVE_ORGAN:
        case IMF_INSTRUMENT_ROCK_ORGAN:
        case IMF_INSTRUMENT_CHURCH_ORGAN:
        case IMF_INSTRUMENT_REED_ORGAN:
        case IMF_INSTRUMENT_ACCORDION:
        case IMF_INSTRUMENT_HARMONICA:
        case IMF_INSTRUMENT_TANGO_ACCORDION:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
        case IMF_INSTRUMENT_LEAD_8_BASS_LEAD:
        case IMF_INSTRUMENT_ACOUSTIC_BASS:
        case IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:
        case IMF_INSTRUMENT_ELECTRIC_BASS_PICK:
        case IMF_INSTRUMENT_FRETLESS_BASS:
        case IMF_INSTRUMENT_SLAP_BASS_1:
        case IMF_INSTRUMENT_SLAP_BASS_2:
        case IMF_INSTRUMENT_SYNTH_BASS_1:
        case IMF_INSTRUMENT_SYNTH_BASS_2:
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
        case IMF_INSTRUMENT_PAD_4_CHOIR:
        case IMF_INSTRUMENT_CHOIR_AAHS:
        case IMF_INSTRUMENT_VOICE_OOHS:
        case IMF_INSTRUMENT_SYNTH_VOICE:
        case IMF_INSTRUMENT_LEAD_4_CHIFF:
        case IMF_INSTRUMENT_LEAD_5_CHARANG:
        case IMF_INSTRUMENT_LEAD_6_VOICE:
        case IMF_INSTRUMENT_LEAD_7_FIFTHS:
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
            PROGRAM_DISTORTION_SV( _channels, 0x0a );
            break;

        default:
            break;

    }

}

void pokey_set_frequency_vars( Environment * _environment, char * _channels, char * _frequency ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$f" );
    }
    outline1("LDX %s", _frequency );
    outline1("LDY %s", address_displacement(_environment, _frequency, "1") );

    outline0("JSR POKEYFREQ");

}

void pokey_set_pitch_vars( Environment * _environment, char * _channels, char * _pitch ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$f" );
    }
    outline1("LDX %s", _pitch );
    outline1("LDY %s", address_displacement(_environment, _pitch, "1") );

    outline0("JSR POKEYPROGFREQ");

}

void pokey_set_duration_vars( Environment * _environment, char * _channels, char * _duration ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$f" );
    }
    outline1("LDX %s", _duration );

    outline0("JSR POKEYSETDURATION");

}

void pokey_set_note_vars( Environment * _environment, char * _channels, char * _note ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    outline0("LDA #<POKEYFREQTABLE");
    outline0("STA TMPPTR");
    outline0("LDA #>POKEYFREQTABLE");
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
        outline0("LDA #$f" );
    }

    outline0("JSR POKEYPROGFREQ");

}

void pokey_stop_vars( Environment * _environment, char * _channels ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$f" );
    }
    outline0("JSR POKEYSTOP");

}

void pokey_music( Environment * _environment, char * _music, int _size, int _loop ) {

    deploy( pokeyvars, src_hw_pokey_vars_asm );
    deploy( pokeystartup, src_hw_pokey_startup_asm );

    outline0("SEI");
    outline1("LDA #<%s", _music);
    outline0("STA POKEYTMPPTR_BACKUP");
    outline1("LDA #>%s", _music);
    outline0("STA POKEYTMPPTR_BACKUP+1");
    outline1("LDA #$%2.2x", ( _size>>8 ) & 0xff);
    outline0("STA POKEYBLOCKS_BACKUP");
    outline1("LDA #$%2.2x", _size & 0xff );
    outline0("STA POKEYLASTBLOCK_BACKUP");
    outline1("LDA #$%2.2x", _loop);
    outline0("STA POKEYMUSICLOOP");
    outline0("JSR MUSICPLAYERRESET");
    outline0("CLI");

}

#endif