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

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../ugbc.h"
#include <math.h>

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __pc128op__

void pc128op_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF60");    
    outline1("STA %s+1", _destination);
    outline0("LDA #0");
    outline1("STA %s", _destination);

}

void pc128op_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF61");    
    outline1("STA %s+1", _destination);
    outline0("LDA #0");
    outline1("STA %s", _destination);
   
}

void pc128op_color_border( Environment * _environment, char * _color ) {

}

void pc128op_vscroll( Environment * _environment, int _displacement ) {

}

void pc128op_text_at( Environment * _environment, char * _text, char * _text_size, char * _pen, char * _paper ) {

}

void pc128op_cls( Environment * _environment, char * _pen, char * _paper ) {

}

void pc128op_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    pc128op_scancode( _environment, _pressed, _key );

    outline1("LDA %s", _pressed );
    outline0("CMPA #0" );
    outline1("BEQ %sskip", label );
    outline1("LDA %s", _key );
    outline0("ANDA #$80" );
    outline0("CMPA #0" );
    outline1("BNE %snoascii", label );
    outline1("LDA %s", _key );
    outline0("CMPA $011d" );
    outline1("BNE %sdifferent", label );
    outline0("INC $011f" );
    outline0("LDB $011f" );
    outline0("CMPB #$7f" );
    outline1("BEQ %sascii", label );
    outline0("LDA #0" );
    outline1("STA %s", _pressed );
    outline1("JMP %sdone", label );
    outhead1("%snoascii", label );
    outline0("LDA #0" );
    outline1("STA %s", _key );
    outline1("JMP %sdone", label );
    outhead1("%sdifferent", label );
    outline0("STA $011d" );
    outhead1("%sascii", label );
    outline0("LDB #0" );
    outline0("STB $011f" );
    outhead1("%sskip", label );
    outline0("LDA #0" );
    outline0("STA $011d" );
    outhead1("%sdone", label );
}

void pc128op_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    deploy( scancode, src_hw_pc128op_scancode_asm );

    outline0("LDA #0" );
    outline1("STA %s", _pressed );
    outline1("STA %s", _scancode );

    outline0("JSR SCANCODE" );
    outline0("CMPB #$0" );
    outline1("BEQ %snokey", label );
    outline1("STB %s", _scancode );
    outline0("LDA #$FF" );
    outline1("STA %s", _pressed );
    outhead1("%snokey", label );

}

void pc128op_scanshift( Environment * _environment, char * _shifts ) {

    pc128op_keyshift( _environment, _shifts );
    
}

void pc128op_keyshift( Environment * _environment, char * _shifts ) {

    MAKE_LABEL

    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(pressed)" );
    Variable * scancode = variable_temporary( _environment, VT_BYTE, "(scancode)" );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)");
    
    pc128op_scancode( _environment, pressed->realName, scancode->realName );

}

void pc128op_clear_key( Environment * _environment ) {

}

void pc128op_initialization( Environment * _environment ) {

}

int pc128op_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    
}

void pc128op_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void pc128op_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {
    
}

void pc128op_back( Environment * _environment ) {

}

/**
 * @brief Calculate the luminance of a color
 * 
 * This function calculates the luminance of a color. 
 * By luminance we mean the modulus of the three-dimensional 
 * vector, drawn in the space composed of the three components 
 * (red, green and blue). The returned value is normalized to
 * the nearest 8-bit value.
 * 
 * @param _a 
 * @return int 
 */
// 

static int calculate_luminance(RGBi _a) {

    // Extract the vector's components 
    // (each partecipate up to 1/3 of the luminance).
    double red = (double) _a.red / 3;
    double green = (double)_a.green / 3;
    double blue = (double)_a.blue / 3;

    // Calculate luminance using Pitagora's Theorem
    return (int)sqrt(pow(red, 2) + pow(green, 2) + pow(blue, 2));

}

void pc128op_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDD %s", _timing );
    outline0("LDX PC128TIMER");
    outline0("LEAX D, X");
    outhead1("%sfirst", label );
    interleaved_instructions( _environment );
    outline0("CMPX PC128TIMER");
    outline1("BGT %sfirst", label);
}

void pc128op_irq_at( Environment * _environment, char * _label ) {

    outline1("LDX #%s", _label );
    outline0("STX PC128IRQN" );
    
}

void pc128op_follow_irq( Environment * _environment ) {

    outline0("JMP [PC128IRQO]" );
    
}

void pc128op_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    deploy( scancode, src_hw_pc128op_scancode_asm );

    outline1("LDA %s", _scancode );
    outline0("JSR KEYPRESSED");
    outline1("BEQ %snopressed", label );
    outline0("LDA #1" );
    outline1("STA %s", _result );
    outline1("BRA %sfinish", label );
    outhead1("%snopressed", label );
    outline0("LDA #0" );
    outline1("STA %s", _result );
    outhead1("%sfinish", label );

}

void pc128op_joystick( Environment * _environment, char * _joystick, char * _result ) {

    MAKE_LABEL

    deploy( joystick, src_hw_pc128op_joystick_asm );

    outline1("LDA %s", _joystick );
    outline0("JSR JOYSTICK");
    outline1("STA %s", _result );

}

/** audio section **/

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

void pc128opaudio_initialization( Environment * _environment ) {

    cpu_call( _environment, "PC128OPAUDIOSTARTUP" );

}

void pc128opaudio_finalization( Environment * _environment ) {

    if ( ! _environment->deployed.pc128audiostartup ) {
        cpu_label( _environment, "PC128OPAUDIOSTARTUP" );
        outline0( "RTS" );
        cpu_label( _environment, "PC128AUDIOOPSAMPLE" );
        outline0( "RTS" );
        cpu_label( _environment, "MUSICPLAYER" );
        outline0( "RTS" );
    }

}

void pc128opaudio_start( Environment * _environment, int _channels ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    if ( _channels & 0x01 ) {
        outline0("JSR PC128OPAUDIOSTART0");
    }

}

void pc128opaudio_set_volume( Environment * _environment, int _channels, int _volume ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    outline1("LDA #%2.2x", ( _volume & 0x0f ) );
    outline0("JSR PC128OPAUDIOSTARTVOL");

}

#define     PROGRAM_FREQUENCY( c, f ) \
    outline1("LDX #$%4.4x", f ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR PC128OPAUDIOPROGFREQ0" );

#define     PROGRAM_FREQUENCY_V( c, f ) \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline1("LDX %s", f ); \
    outline0("JSR PC128OPAUDIOFREQ" );

#define     PROGRAM_FREQUENCY_SV( c, f ) \
    outline1("LDX #$%4.4x", f ); \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR PC128OPAUDIOFREQ2" );

#define     PROGRAM_PITCH( c, f ) \
    outline1("LDX #$%4.4x", f ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR PC128OPAUDIOPROGFREQ0" );

#define     PROGRAM_PITCH_V( c, f ) \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline1("LDX %s", f ); \
    outline0("JSR PC128OPAUDIOPROGFREQ" );

#define     PROGRAM_PITCH_SV( c, f ) \
    outline1("LDX #$%4.4x", f ); \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline0("JSR PC128OPAUDIOPROGFREQ" );

#define     PROGRAM_PULSE( c, p ) \
    outline1("LDX #$%4.4x", p ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR PC128OPAUDIOPROGPULSE0" );
        
#define     PROGRAM_PULSE_V( c, p ) \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline1("LDX %s", p ); \
    outline0("JSR PC128OPAUDIOPROGPULSE" );

#define     PROGRAM_PULSE_SV( c, p ) \
    outline1("LDX #$%4.4x", p ); \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline0("JSR PC128OPAUDIOPROGPULSE" );

#define     PROGRAM_NOISE( c ) \
    outline0("LDB #$82" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR PC128OPAUDIOPROGCTR0" );
        
#define     PROGRAM_NOISE_V( c, p ) \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline0("LDB #$82" ); \
    outline0("JSR PC128OPAUDIOPROGCTR" );

#define     PROGRAM_NOISE_SV( c ) \
    outline0("LDB #$82" ); \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline0("JSR PC128OPAUDIOPROGCTR" );

#define     PROGRAM_SAW( c ) \
    outline0("LDB #$22" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR PC128OPAUDIOPROGCTR0" );
        
#define     PROGRAM_SAW_V( c) \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline0("LDB #$22" ); \
    outline0("JSR PC128OPAUDIOPROGCTR" );

#define     PROGRAM_SAW_SV( c ) \
    outline0("LDB #$22" ); \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline0("JSR PC128OPAUDIOPROGCTR" );

#define     PROGRAM_TRIANGLE( c ) \
    outline0("LDB #$12" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR PC128OPAUDIOPROGCTR0" ); 

#define     PROGRAM_TRIANGLE_V( c ) \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline0("LDB #$12" ); \
    outline0("JSR PC128OPAUDIOPROGCTR" );

#define     PROGRAM_TRIANGLE_SV( c ) \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline0("LDB #$12" ); \
    outline0("JSR PC128OPAUDIOPROGCTR" );

#define     PROGRAM_SAW_TRIANGLE( c ) \
    outline0("LDB #$32" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR PC128OPAUDIOPROGCTR0" ); 

#define     PROGRAM_SAW_TRIANGLE_V( c ) \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline0("LDB #$32" ); \
    outline0("JSR PC128OPAUDIOPROGCTR" );

#define     PROGRAM_SAW_TRIANGLE_SV( c ) \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline0("LDB #$32" ); \
    outline0("JSR PC128OPAUDIOPROGCTR" );

#define     PROGRAM_ATTACK_DECAY( c, a, d ) \
    outline1("LDX #$%4.4x", ( ( a << 8 ) | d )  ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR PC128OPAUDIOPROGAD0" ); 

#define     PROGRAM_ATTACK_DECAY_V( c, a, d ) \
    outline1("LDA %s", ( c == NULL ? "#$1" : c ) ); \
    outline1("LDX %s", a ); \
    outline1("LDY %s", d ); \
    outline0("JSR PC128OPAUDIOPROGAD" );

#define     PROGRAM_ATTACK_DECAY_SV( c, a, d ) \
    outline1("LDX #$%2.2x", ( a & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( d & 0x0f ) ); \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR PC128OPAUDIOPROGAD" );

#define     PROGRAM_SUSTAIN_RELEASE( c, s, r ) \
    outline1("LDX #$%2.2x", ( s & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( r & 0x0f ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR PC128OPAUDIOPROGSR0" ); 

#define     PROGRAM_SUSTAIN_RELEASE_V( c, s, r ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline1("LDX %s", s ); \
    outline1("LDY %s", r ); \
    outline0("JSR PC128OPAUDIOPROGSR" );

#define     PROGRAM_SUSTAIN_RELEASE_SV( c, s, r ) \
    outline1("LDX #$%2.2x", ( s & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( r & 0x0f ) ); \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR PC128OPAUDIOPROGSR" );

#define     STOP_FREQUENCY( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("JSR PC128OPAUDIOSTOP0" ); 

#define     STOP_FREQUENCY_V( c ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR PC128OPAUDIOSTOP" );

#define     STOP_FREQUENCY_SV( c ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR PC128OPAUDIOSTOP" );

void pc128opaudio_set_program( Environment * _environment, int _channels, int _program ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

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

void pc128opaudio_set_parameter( Environment * _environment, int _channels, int _parameter, int _value ) {

}

void pc128opaudio_set_frequency( Environment * _environment, int _channels, int _frequency ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    PROGRAM_FREQUENCY( _channels, _frequency );

}

void pc128opaudio_set_pitch( Environment * _environment, int _channels, int _pitch ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    PROGRAM_PITCH( _channels, _pitch );

}

void pc128opaudio_set_note( Environment * _environment, int _channels, int _note ) {

    pc128opaudio_set_pitch( _environment, _channels, SOUND_FREQUENCIES[_note] );

}

void pc128opaudio_stop( Environment * _environment, int _channels ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    STOP_FREQUENCY( _channels );

}

void pc128opaudio_start_var( Environment * _environment, char * _channels ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$1" );
    }
    outline0("JSR PC128OPAUDIOSTART");

}

void pc128opaudio_set_volume_vars( Environment * _environment, char * _channels, char * _volume ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    outline1("LDA %s", _volume );
    outline0("LSRA" );
    outline0("LSRA" );
    outline0("LSRA" );
    outline0("LSRA" );
    outline0("JSR PC128OPAUDIOSTARTVOL");

}

void pc128opaudio_set_volume_semi_var( Environment * _environment, char * _channel, int _volume ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    outline1("LDA #$%2.2x", _volume );
    outline0("JSR PC128OPAUDIOSTARTVOL");

}

void pc128opaudio_set_program_semi_var( Environment * _environment, char * _channels, int _program ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

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

void pc128opaudio_set_frequency_vars( Environment * _environment, char * _channels, char * _frequency ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$1" );
    }
    outline1("LDX %s", _frequency );

    outline0("JSR PC128OPAUDIOFREQ");

}

void pc128opaudio_set_pitch_vars( Environment * _environment, char * _channels, char * _pitch ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$1" );
    }
    outline1("LDX %s", _pitch );

    outline0("JSR PC128OPAUDIOPROGFREQ");

}

void pc128opaudio_set_note_vars( Environment * _environment, char * _channels, char * _note ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    // outline0("LDA #<PC128OPAUDIOFREQTABLE");
    // outline0("STA TMPPTR");
    // outline0("LDA #>PC128OPAUDIOFREQTABLE");
    // outline0("STA TMPPTR+1");
    // outline1("LDY %s", _note);
    // outline0("TYA");
    // outline0("ASL");
    // outline0("TAY");
    // outline0("LDA (TMPPTR),Y");
    // outline0("TAX");
    // outline0("INY");
    // outline0("LDA (TMPPTR),Y");
    // outline0("TAY");

    // if ( _channels ) {
    //     outline1("LDA %s", _channels );
    // } else {
    //     outline0("LDA #$7" );
    // }

    outline0("JSR PC128OPAUDIOPROGFREQ");

}

void pc128opaudio_stop_vars( Environment * _environment, char * _channels ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    outline1("LDA %s", _channels );
    outline0("JSR PC128OPAUDIOSTOP");

}

void pc128opaudio_music( Environment * _environment, char * _music, int _size ) {

    deploy( pc128audiostartup, src_hw_pc128op_audio_asm );

    // outline0("SEI");
    // outline0("LDA #$0");
    // outline0("STA PC128OPAUDIOJIFFIES");
    // outline0("STA PC128OPAUDIOTMPOFS");
    // outline0("LDA #$1");
    // outline0("STA PC128OPAUDIOMUSICREADY");
    // outline1("LDA #<%s", _music);
    // outline0("STA PC128OPAUDIOTMPPTR");
    // outline1("LDA #>%s", _music);
    // outline0("STA PC128OPAUDIOTMPPTR+1");
    // outline1("LDA #$%2.2x", ( _size>>8 ) & 0xff);
    // outline0("STA PC128OPAUDIOBLOCKS");
    // outline1("LDA #$%2.2x", _size & 0xff );
    // outline0("STA PC128OPAUDIOLASTBLOCK");
    // if ( _size > 255 ) {
    //     outline0("LDA #$ff");
    // }
    // outline0("STA PC128OPAUDIOTMPLEN");
    // outline0("CLI");

}

#endif