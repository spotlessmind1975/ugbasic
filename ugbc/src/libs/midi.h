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
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#ifndef _UGBASIC_LIBS_MIDI_H
#define _UGBASIC_LIBS_MIDI_H

#include <stdint.h>

typedef enum _MidiMessage {
	messageNoteOff				= 0x80,
	messageNoteOn				= 0x90,
	messageNoteKeyPressure		= 0xa0,
	messageSetParameter			= 0xb0,
	messageSetProgram			= 0xc0,
	messageChangePressure		= 0xd0,
	messageSetPitchWheel		= 0xe0,	
	messageMetaEvent			= 0xff,
	messageSysEx1				= 0xf0,
	messageSysEx2				= 0xf7,
	messagePatchChange			= messageSetProgram,
	messageControlChange		= messageSetParameter,
	messageSysMask				= 0xf0,
} MidiMessage;

typedef enum _ControlCommand {
	controlCommandBankSelect			= 0,
	controlCommandModulation			= 1,
	controlCommandBreathControl			= 2,
	controlCommandUndefined3			= 3,
	controlCommandFootControl				= 4,
	controlCommandPortamentoTime		= 5,
	controlCommandDateEntry				= 6,
	controlCommandVolume				= 7,
	controlCommandBalance				= 8,
	controlCommandUndefined9			= 9,
	controlCommandPan					= 10,
	controlCommandExpression			= 11,
	controlCommandEffectControl1		= 12,
	controlCommandEffectControl2		= 13,
	controlCommandUndefined14			= 14,
	controlCommandUndefined15			= 15,
	controlCommandGeneralPurpose1		= 16,
	controlCommandGeneralPurpose2		= 17,
	controlCommandGeneralPurpose3		= 18,
	controlCommandGeneralPurpose4		= 19,
	controlCommandUndefined20			= 20,
	controlCommandUndefined21			= 21,
	controlCommandUndefined22			= 22,
	controlCommandUndefined23			= 23,
	controlCommandUndefined24			= 24,
	controlCommandUndefined25			= 25,
	controlCommandUndefined26			= 26,
	controlCommandUndefined27			= 27,
	controlCommandUndefined28			= 28,
	controlCommandUndefined29			= 29,
	controlCommandUndefined30			= 30,
	controlCommandUndefined31			= 31,
	controlCommandBankSelectLSB			= 32,
	controlCommandModulationLSB			= 33,
	controlCommandBreathControlLSB		= 34,
	controlCommandUndefined35			= 35,
	controlCommandFootControlLSB		= 36,
	controlCommandPortamentoTimeLSB		= 37,
	controlCommandDateEntryLSB			= 38,
	controlCommandVolumeLSB			= 39,
	controlCommandBalanceLSB			= 40,
	controlCommandUndefined41			= 41,
	controlCommandPanLSB			= 42,
	controlCommandExpressionLSB			= 43,
	controlCommandEffectControl1LSB		= 44,
	controlCommandEffectControl2LSB		= 45,
	controlCommandUndefined46			= 46,
	controlCommandUndefined47			= 47,
	controlCommandGeneralPurpose1LSB		= 48,
	controlCommandGeneralPurpose2LSB		= 49,
	controlCommandGeneralPurpose3LSB		= 50,
	controlCommandGeneralPurpose4LSB		= 51,
	controlCommandUndefined52			= 52,
	controlCommandUndefined53			= 53,
	controlCommandUndefined54			= 54,
	controlCommandUndefined55			= 55,
	controlCommandUndefined56			= 56,
	controlCommandUndefined57			= 57,
	controlCommandUndefined58			= 58,
	controlCommandUndefined59			= 59,
	controlCommandUndefined60			= 60,
	controlCommandUndefined61			= 61,
	controlCommandUndefined62			= 62,
	controlCommandUndefined63			= 63,
	controlCommandSustainPedal			= 64,
	controlCommandPortamento			= 65,
	controlCommandPedalSustenuto		= 66,
	controlCommandPedalSoft				= 67,
	controlCommandLegatoFootSwitch		= 68,
	controlCommandHold2					= 69,
	controlCommandSoundVariation		= 70,
	controlCommandTimbre			= 71,
	controlCommandReleaseTime			= 72,
	controlCommandAttackTime			= 73,
	controlCommandBrightness			= 74,
	controlCommandReverb				= 75,
	controlCommandDelay					= 76,
	controlCommandPitchTranspose		= 77,
	controlCommandFlange				= 78,
	controlCommandSpecialFX				= 79,
	controlCommandGeneralPurpose5		= 80,
	controlCommandGeneralPurpose6		= 81,
	controlCommandGeneralPurpose7		= 82,
	controlCommandGeneralPurpose8		= 83,
	controlCommandPortamentoControl		= 84,
	controlCommandUndefined85			= 85,
	controlCommandUndefined86			= 86,
	controlCommandUndefined87			= 87,
	controlCommandUndefined88			= 88,
	controlCommandUndefined89			= 89,
	controlCommandUndefined90			= 90,
	controlCommandFXDepth				= 91,
	controlCommandTremeloDepth			= 92,
	controlCommandChorusDepth			= 93,
	controlCommandCelestaDepth			= 94,
	controlCommandPhaserDepth			= 95,
	controlCommandDataInc				= 96,
	controlCommandDataDec				= 97,
	controlCommandNonRegParamLSB		= 98,
	controlCommandNonRefParamMSB		= 99,
	controlCommandRegParamLSB			= 100,
	controlCommandRegParamMSB			= 101,
	controlCommandUndefined102			= 102,
	controlCommandUndefined103			= 103,
	controlCommandUndefined104			= 104,
	controlCommandUndefined105			= 105,
	controlCommandUndefined106			= 106,
	controlCommandUndefined107			= 107,
	controlCommandUndefined108			= 108,
	controlCommandUndefined109			= 109,
	controlCommandUndefined110			= 110,
	controlCommandUndefined111			= 111,
	controlCommandUndefined112			= 112,
	controlCommandUndefined113			= 113,
	controlCommandUndefined114			= 114,
	controlCommandUndefined115			= 115,
	controlCommandUndefined116			= 116,
	controlCommandUndefined117			= 117,
	controlCommandUndefined118			= 118,
	controlCommandUndefined119			= 119,
	controlCommandAllSoundOff			= 120,
	controlCommandResetAllControllers	= 121,
	controlCommandLocalControl			= 122,
	controlCommandAllNotesOff			= 123,
	controlCommandOmniModeOff			= 124,
	controlCommandOmniModeOn			= 125,
	controlCommandMonoModeOn			= 126,
	controlCommandPolyModeOn			= 127,
	controlCommandModWheel				= 1,
	controlCommandHarmContent			= 71,
	controlCommandSoundController1			= 70,
	controlCommandSoundController2			= 71,
	controlCommandSoundController3			= 72,
	controlCommandSoundController4			= 73,
	controlCommandSoundController5			= 74,
	controlCommandSoundController6			= 75,
	controlCommandSoundController7			= 76,
	controlCommandSoundController8			= 77,
	controlCommandSoundController9			= 78,
	controlCommandSoundController10			= 79,
	controlCommandEffect1Depth				= 91,
	controlCommandEffect2Depth				= 92,
	controlCommandEffect3Depth				= 93,
	controlCommandEffect4Depth				= 94,
	controlCommandEffect5Depth				= 95,
	controlCommandDetuneDepth			= 94,
} MidiControlCommand;

typedef enum _MidiSystemCommand {
	systemCommandUndefinedF1			= 0xf1,
	systemCommandSongPosition			= 0xf2,
	systemCommandSongSelect				= 0xf3,
	systemCommandUndefinedF4			= 0xf4,
	systemCommandUndefinedF5			= 0xf5,
	systemCommandTuneRequest			= 0xf6,
	systemCommandEOX					= 0xf7,
} MidiSystemCommand;

typedef enum _MidiRealTime {
	realTimeTimingClock			= 0xf8,
	realTimeUndefinedF9			= 0xf9,
	realTimeStart				= 0xfa,
	realTimeContinue			= 0xfb,
	realTimeStop				= 0xfc,
	realTimeUndefinedFD			= 0xfd,
	realTimeActiveSensing		= 0xfe,
	realTimeSystemReset			= 0xff,
} MidiRealTime;

typedef enum _MidiSystemExclusive {
	systemExclusiveEOX				= 0xf7,
} MidiSystemExclusive;

typedef enum _MidiNote {
	noteCFlatMaj				= 0x87,
	noteGFlatMaj				= 0x86,
	noteDFlatMaj				= 0x85,
	noteAFlatMaj				= 0x84,
	noteEFlatMaj				= 0x83,
	noteBFlatMaj				= 0x82,
	noteFMaj					= 0x81,
	noteCMaj					= 0x00,
	noteGMaj					= 0x01,
	noteDMaj					= 0x02,
	noteAMaj					= 0x03,
	noteEMaj					= 0x04,
	noteBMaj					= 0x05,
	noteFSharpMaj				= 0x06,
	noteCSharpMaj				= 0x07,
	noteCFlatMin				= 0xc7,
	noteGFlatMin				= 0xc6,
	noteDFlatMin				= 0xc5,
	noteAFlatMin				= 0xc4,
	noteEFlatMin				= 0xc3,
	noteBFlatMin				= 0xc2,
	noteFMin					= 0xc1,
	noteCMin					= 0x40,
	noteGMin					= 0x41,
	noteDMin					= 0x42,
	noteAMin					= 0x43,
	noteEMin					= 0x44,
	noteBMin					= 0x45,
	noteFSharpMin				= 0x46,
	noteCSharpMin				= 0x47,
	noteMaskNeg					= 0x80,
	noteMaskFlatKeys			= 0x80,
	noteMaskMin					= 0x40,
	noteMaskKey					= 0x07,
} MidiNote;

typedef enum _MidiMetaInfo {
	metaInfoSequenceNumber		= 0,
	metaInfoTextEvent			= 1,
	metaInfoCopyright			= 2,
	metaInfoTrackName			= 3,
	metaInfoInstrument			= 4,
	metaInfoLyric				= 5,
	metaInfoMarker				= 6,
	metaInfoCuePoint			= 7,
	metaInfoMIDIPort			= 0x21,
	metaInfoEndSequence			= 0x2f,
	metaInfoSetTempo			= 0x51,
	metaInfoSMPTEOffset			= 0x54,
	metaInfoTimeSig				= 0x58,
	metaInfoKeySig				= 0x59,
	metaInfoSequencerSpecific	= 0x7f,
} MidiMetaInfo;	

typedef enum _MidiTextInfo {
	textInfoTextEvent			= 1,
	textInfoCopyright			= 2,
	textInfoTrackName			= 3,
	textInfoInstrument			= 4,
	textInfoLyric				= 5,
	textInfoMarker				= 6,
	textInfoCuePoint			= 7,
} MidiTextInfo;	

#define MIDI_WHEEL_CENTRE			8192

#define MIDI_CHANNEL_1			1
#define MIDI_CHANNEL_2			2
#define MIDI_CHANNEL_3			3
#define MIDI_CHANNEL_4			4
#define MIDI_CHANNEL_5			5
#define MIDI_CHANNEL_6			6
#define MIDI_CHANNEL_7			7
#define MIDI_CHANNEL_8			8
#define MIDI_CHANNEL_9			9
#define MIDI_CHANNEL_10			10
#define MIDI_CHANNEL_11			11
#define MIDI_CHANNEL_12			12
#define MIDI_CHANNEL_13			13
#define MIDI_CHANNEL_14			14
#define MIDI_CHANNEL_15			15
#define MIDI_CHANNEL_16			16

#define MIDI_CHANNEL_DRUMS		10

#define MIDI_OCTAVE			12

#define MIDI_NOTE_MIDDLE_C	MIDI_NOTE_C5

#define MIDI_NOTE_C			0
#define MIDI_NOTE_C_SHARP	1
#define MIDI_NOTE_C_FLAT	-11
#define MIDI_NOTE_D			2
#define MIDI_NOTE_D_SHARP	3
#define MIDI_NOTE_D_FLAT	1
#define MIDI_NOTE_E			4
#define MIDI_NOTE_E_SHARP	5
#define MIDI_NOTE_E_FLAT	3
#define MIDI_NOTE_F			5
#define MIDI_NOTE_F_SHARP	6
#define MIDI_NOTE_F_FLAT	5
#define MIDI_NOTE_G			7
#define MIDI_NOTE_G_SHARP	8
#define MIDI_NOTE_G_FLAT	6
#define MIDI_NOTE_A			9
#define MIDI_NOTE_A_SHARP	10
#define MIDI_NOTE_A_FLAT	8
#define MIDI_NOTE_B			11
#define MIDI_NOTE_B_SHARP	12
#define MIDI_NOTE_B_FLAT	10

#define MIDI_NOTE_C0		0 
#define MIDI_NOTE_C1		12
#define MIDI_NOTE_C2		24
#define MIDI_NOTE_C3		36
#define MIDI_NOTE_C4		48
#define MIDI_NOTE_C5		60
#define MIDI_NOTE_C6		72
#define MIDI_NOTE_C7		84
#define MIDI_NOTE_C8		96
#define MIDI_NOTE_C9		108
#define MIDI_NOTE_C10		120

#define MIDI_OCTAVE_0		MIDI_NOTE_C0
#define MIDI_OCTAVE_1		MIDI_NOTE_C1
#define MIDI_OCTAVE_2		MIDI_NOTE_C2
#define MIDI_OCTAVE_3		MIDI_NOTE_C3
#define MIDI_OCTAVE_4		MIDI_NOTE_C4
#define MIDI_OCTAVE_5		MIDI_NOTE_C5
#define MIDI_OCTAVE_6		MIDI_NOTE_C6
#define MIDI_OCTAVE_7		MIDI_NOTE_C7
#define MIDI_OCTAVE_8		MIDI_NOTE_C8
#define MIDI_OCTAVE_9		MIDI_NOTE_C9
#define MIDI_OCTAVE_10		MIDI_NOTE_C10

#define MIDI_DURATION_BREVE					1536
#define MIDI_DURATION_MINIM					 768
#define MIDI_DURATION_CROCHET				 384
#define MIDI_DURATION_QUAVER				 192
#define MIDI_DURATION_SEMIQUAVER			  96
#define MIDI_DURATION_SEMIDEMIQUAVER		  48

#define MIDI_DURATION_DOTTED_MINIM			 (768+384)
#define MIDI_DURATION_DOTTED_CROCHET		 (384+192)
#define MIDI_DURATION_DOTTED_QUAVER			 (192+96)
#define MIDI_DURATION_DOTTED_SEMIQUAVER		  (96+48)
#define MIDI_DURATION_DOTTED_SEMIDEMIQUAVER	  (48+24)

#define MIDI_DURATION_TRIPLE_CROCHET			256			

#define MIDI_VOL_FULL		127
#define MIDI_VOL_HALF		64
#define MIDI_VOL_OFF		0

#define MIDI_INSTRUMENT_ACOUSTIC_GRAND_PIANO         0 
#define MIDI_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO        1
#define MIDI_INSTRUMENT_ELECTRIC_GRAND_PIANO         2
#define MIDI_INSTRUMENT_HONKY_TONK_PIANO             3
#define MIDI_INSTRUMENT_ELECTRIC_PIANO_1				4
#define MIDI_INSTRUMENT_ELECTRIC_PIANO_2             5
#define MIDI_INSTRUMENT_HARPSICHORD                  6
#define MIDI_INSTRUMENT_CLAVI						7
#define MIDI_INSTRUMENT_CELESTA   					8
#define MIDI_INSTRUMENT_GLOCKENSPIEL					9
#define MIDI_INSTRUMENT_MUSIC_BOX					10
#define MIDI_INSTRUMENT_VIBRAPHONE					11
#define MIDI_INSTRUMENT_MARIMBA						12
#define MIDI_INSTRUMENT_XYLOPHONE       				13
#define MIDI_INSTRUMENT_TUBULAR_BELLS                14
#define MIDI_INSTRUMENT_DULCIMER						15
#define MIDI_INSTRUMENT_DRAWBAR_ORGAN                16
#define MIDI_INSTRUMENT_PERCUSSIVE_ORGAN             17
#define MIDI_INSTRUMENT_ROCK_ORGAN					18
#define MIDI_INSTRUMENT_CHURCH_ORGAN					19
#define MIDI_INSTRUMENT_REED_ORGAN					20
#define MIDI_INSTRUMENT_ACCORDION					21
#define MIDI_INSTRUMENT_HARMONICA					22
#define MIDI_INSTRUMENT_TANGO_ACCORDION              23
#define MIDI_INSTRUMENT_ACOUSTIC_GUITAR_NYLON        24
#define MIDI_INSTRUMENT_ACOUSTIC_GUITAR_STEEL        25
#define MIDI_INSTRUMENT_ELECTRIC_GUITAR_JAZZ         26
#define MIDI_INSTRUMENT_ELECTRIC_GUITAR_CLEAN        27
#define MIDI_INSTRUMENT_ELECTRIC_GUITAR_MUTED        28
#define MIDI_INSTRUMENT_OVERDRIVEN_GUITAR			29
#define MIDI_INSTRUMENT_DISTORTION_GUITAR			30
#define MIDI_INSTRUMENT_GUITAR_HARMONICS				31
#define MIDI_INSTRUMENT_ACOUSTIC_BASS				32
#define MIDI_INSTRUMENT_ELECTRIC_BASS_FINGER			33
#define MIDI_INSTRUMENT_ELECTRIC_BASS_PICK			34
#define MIDI_INSTRUMENT_FRETLESS_BASS                35
#define MIDI_INSTRUMENT_SLAP_BASS_1                  36
#define MIDI_INSTRUMENT_SLAP_BASS_2                  37
#define MIDI_INSTRUMENT_SYNTH_BASS_1                 38
#define MIDI_INSTRUMENT_SYNTH_BASS_2					39
#define MIDI_INSTRUMENT_VIOLIN						40
#define MIDI_INSTRUMENT_VIOLA						41
#define MIDI_INSTRUMENT_CELLO 						42
#define MIDI_INSTRUMENT_CONTRABASS            		43
#define MIDI_INSTRUMENT_TREMOLO_STRINGS         		44
#define MIDI_INSTRUMENT_PIZZICATO_STRINGS			45
#define MIDI_INSTRUMENT_ORCHESTRAL_HARP				46
#define MIDI_INSTRUMENT_TIMPANI        				47
#define MIDI_INSTRUMENT_STRING_ENSEMBLE_1			48
#define MIDI_INSTRUMENT_STRING_ENSEMBLE_2            49
#define MIDI_INSTRUMENT_SYNTHSTRINGS_1               50
#define MIDI_INSTRUMENT_SYNTHSTRINGS_2               51
#define MIDI_INSTRUMENT_CHOIR_AAHS					52
#define MIDI_INSTRUMENT_VOICE_OOHS					53
#define MIDI_INSTRUMENT_SYNTH_VOICE					54
#define MIDI_INSTRUMENT_ORCHESTRA_HIT				55
#define MIDI_INSTRUMENT_TRUMPET						56
#define MIDI_INSTRUMENT_TROMBONE						57
#define MIDI_INSTRUMENT_TUBA							58
#define MIDI_INSTRUMENT_MUTED_TRUMPET				59
#define MIDI_INSTRUMENT_FRENCH_HORN					60
#define MIDI_INSTRUMENT_BRASS_SECTION				61
#define MIDI_INSTRUMENT_SYNTHBRASS_1					62
#define MIDI_INSTRUMENT_SYNTHBRASS_2					63
#define MIDI_INSTRUMENT_SOPRANO_SAX					64
#define MIDI_INSTRUMENT_ALTO_SAX						65
#define MIDI_INSTRUMENT_TENOR_SAX           			66
#define MIDI_INSTRUMENT_BARITONE_SAX        			67
#define MIDI_INSTRUMENT_OBOE            				68
#define MIDI_INSTRUMENT_ENGLISH_HORN    		  		69
#define MIDI_INSTRUMENT_BASSOON            			70
#define MIDI_INSTRUMENT_CLARINET            			71
#define MIDI_INSTRUMENT_PICCOLO              		72
#define MIDI_INSTRUMENT_FLUTE              			73
#define MIDI_INSTRUMENT_RECORDER           		    74
#define MIDI_INSTRUMENT_PAN_FLUTE					75
#define MIDI_INSTRUMENT_BLOWN_BOTTLE				    76
#define MIDI_INSTRUMENT_SHAKUHACHI					77
#define MIDI_INSTRUMENT_WHISTLE						78
#define MIDI_INSTRUMENT_OCARINA					    79
#define MIDI_INSTRUMENT_LEAD_1_SQUARE	            80
#define MIDI_INSTRUMENT_LEAD_2_SAWTOOTH				81
#define MIDI_INSTRUMENT_LEAD_3_CALLIOPE				82
#define MIDI_INSTRUMENT_LEAD_4_CHIFF					83
#define MIDI_INSTRUMENT_LEAD_5_CHARANG				84
#define MIDI_INSTRUMENT_LEAD_6_VOICE 				85
#define MIDI_INSTRUMENT_LEAD_7_FIFTHS				86
#define MIDI_INSTRUMENT_LEAD_8_BASS_AND_LEAD			87
#define MIDI_INSTRUMENT_PAD_1_NEW_AGE				88
#define MIDI_INSTRUMENT_PAD_2_WARM					89
#define MIDI_INSTRUMENT_PAD_3_POLYSYNTH				90
#define MIDI_INSTRUMENT_PAD_4_CHOIR					91
#define MIDI_INSTRUMENT_PAD_5_BOWED					92
#define MIDI_INSTRUMENT_PAD_6_METALLIC				93
#define MIDI_INSTRUMENT_PAD_7_HALO					94
#define MIDI_INSTRUMENT_PAD_8_SWEEP					95
#define MIDI_INSTRUMENT_FX_1_RAIN					96
#define MIDI_INSTRUMENT_FX_2_SOUNDTRACK				97
#define MIDI_INSTRUMENT_FX_3_CRYSTAL					98
#define MIDI_INSTRUMENT_FX_4_ATMOSPHERE				99
#define MIDI_INSTRUMENT_FX_5_BRIGHTNESS				100
#define MIDI_INSTRUMENT_FX_6_GOBLINS					101
#define MIDI_INSTRUMENT_FX_7_ECHOES					102
#define MIDI_INSTRUMENT_FX_8_SCIFI					103
#define MIDI_INSTRUMENT_SITAR						104
#define MIDI_INSTRUMENT_BANJO						105
#define MIDI_INSTRUMENT_SHAMISEN						106
#define MIDI_INSTRUMENT_KOTO							107
#define MIDI_INSTRUMENT_KALIMBA						108
#define MIDI_INSTRUMENT_BAG_PIPE						109
#define MIDI_INSTRUMENT_FIDDLE						110
#define MIDI_INSTRUMENT_SHANAI						111
#define MIDI_INSTRUMENT_TINKLE_BELL					112
#define MIDI_INSTRUMENT_AGOGO						113
#define MIDI_INSTRUMENT_STEEL_DRUMS					114
#define MIDI_INSTRUMENT_WOODBLOCK					115
#define MIDI_INSTRUMENT_TAIKO_DRUM					116
#define MIDI_INSTRUMENT_MELODIC_TOM					117
#define MIDI_INSTRUMENT_SYNTH_DRUM					118
#define MIDI_INSTRUMENT_REVERSE_CYMBAL				119
#define MIDI_INSTRUMENT_GUITAR_FRET NOISE			120	
#define MIDI_INSTRUMENT_BREATH_NOISE					121
#define MIDI_INSTRUMENT_SEASHORE						122
#define MIDI_INSTRUMENT_BIRD_TWEET					123
#define MIDI_INSTRUMENT_TELEPHONE_RING				124
#define MIDI_INSTRUMENT_HELICOPTER					125
#define MIDI_INSTRUMENT_APPLAUSE						126
#define MIDI_INSTRUMENT_GUNSHOT						127
	
#define MIDI_INSTRUMENT_DRUM_ACOUSTIC_BASS_DRUM		35
#define MIDI_INSTRUMENT_DRUM_BASS_DRUM					36
#define MIDI_INSTRUMENT_DRUM_SIDE_STICK				37
#define MIDI_INSTRUMENT_DRUM_ACOUSTIC_SNARE			38
#define MIDI_INSTRUMENT_DRUM_HAND_CLAP					39
#define MIDI_INSTRUMENT_DRUM_ELECTRIC_SNARE			40
#define MIDI_INSTRUMENT_DRUM_LOW_FLOOR_TOM				41
#define MIDI_INSTRUMENT_DRUM_CLOSED_HI_HAT				42
#define MIDI_INSTRUMENT_DRUM_HIGH_FLOOR_TOM			43
#define MIDI_INSTRUMENT_DRUM_PEDAL_HI_HAT				44
#define MIDI_INSTRUMENT_DRUM_LOW_TOM					45
#define MIDI_INSTRUMENT_DRUM_OPEN_HI_HAT				46
#define MIDI_INSTRUMENT_DRUM_LOW_MID_TOM				47
#define MIDI_INSTRUMENT_DRUM_HI_MID_TOM				48
#define MIDI_INSTRUMENT_DRUM_CRASH_CYMBAL_1			49
#define MIDI_INSTRUMENT_DRUM_HIGH_TOM					50
#define MIDI_INSTRUMENT_DRUM_RIDE_CYMBAL_1				51
#define MIDI_INSTRUMENT_DRUM_CHINESE_CYMBAL			52
#define MIDI_INSTRUMENT_DRUM_RIDE_BELL					53
#define MIDI_INSTRUMENT_DRUM_TAMBOURINE				54
#define MIDI_INSTRUMENT_DRUM_SPLASH_CYMBAL				55
#define MIDI_INSTRUMENT_DRUM_COWBELL					56
#define MIDI_INSTRUMENT_DRUM_CRASH_CYMBAL_2			57
#define MIDI_INSTRUMENT_DRUM_VIBRA_SLAP				58
#define MIDI_INSTRUMENT_DRUM_RIDE_CYMBAL_2				59
#define MIDI_INSTRUMENT_DRUM_HI_BONGO					60
#define MIDI_INSTRUMENT_DRUM_LOW_BONGO					61
#define MIDI_INSTRUMENT_DRUM_MUTE_HI_CONGA				62
#define MIDI_INSTRUMENT_DRUM_OPEN_HI_CONGA				63
#define MIDI_INSTRUMENT_DRUM_LOW_CONGA					64
#define MIDI_INSTRUMENT_DRUM_HIGH_TIMBALE				65
#define MIDI_INSTRUMENT_DRUM_LOW_TIMBALE				66
#define MIDI_INSTRUMENT_DRUM_HIGH_AGOGO				67
#define MIDI_INSTRUMENT_DRUM_LOW_AGOGO					68
#define MIDI_INSTRUMENT_DRUM_CABASA					69
#define MIDI_INSTRUMENT_DRUM_MARACAS					70
#define MIDI_INSTRUMENT_DRUM_SHORT_WHISTLE				71
#define MIDI_INSTRUMENT_DRUM_LONG_WHISTLE				72
#define MIDI_INSTRUMENT_DRUM_SHORT_GUIRO				73
#define MIDI_INSTRUMENT_DRUM_LONG_GUIRO				74
#define MIDI_INSTRUMENT_DRUM_CLAVES					75
#define MIDI_INSTRUMENT_DRUM_HI_WOOD_BLOCK				76
#define MIDI_INSTRUMENT_DRUM_LOW_WOOD_BLOCK			77
#define MIDI_INSTRUMENT_DRUM_MUTE_CUICA				78
#define MIDI_INSTRUMENT_DRUM_OPEN_CUICA				79
#define MIDI_INSTRUMENT_DRUM_MUTE_TRIANGLE				80
#define MIDI_INSTRUMENT_DRUM_OPEN_TRIANGLE				81

#define CHORD_ROOT_MASK		0x000000ff
#define CHORD_TYPE_MASK		0x0000ff00
#define CHORD_BASS_MASK		0x00ff0000
#define CHORD_ADDITION_MASK	0xff000000

#define CHORD_TYPE_MAJOR	0x00000100
#define CHORD_TYPE_MINOR	0x00000200
#define CHORD_TYPE_AUG		0x00000300
#define CHORD_TYPE_DIM		0x00000400

#define CHORD_ADD_7TH		0x01000000
#define CHORD_ADD_9TH		0x02000000
#define CHORD_ADD_MAJ7TH	0x04000000

int			muGetInstrumentName(char *pName, int iInstr);
int			muGetDrumName(char *pName, int iInstr);
int			muGetMIDIMsgName(char *pName, MidiMessage iMsg);
int			muGetControlName(char *pName, MidiControlCommand iCC);
int			muGetKeySigName(char *pName, MidiNote iKey);
int			muGetTextName(char *pName, MidiTextInfo iEvent);
int			muGetMetaName(char *pName, MidiMetaInfo iEvent);
int		 	muGetNoteFromName(const char *pName);
char	*	muGetNameFromNote(char *pStr, int iNote);
float		muGetFreqFromNote(int iNote);
int			muGetNoteFromFreq(float fFreq);
int 		muGuessChord(const int *pNoteStatus, const int channel, const int lowRange, const int highRange);
char 	*	muGetChordName(char *str, int chord);

typedef	unsigned char		BYTE;
typedef	uint16_t 		WORD;
typedef	uint32_t 		DWORD;
#ifndef TRUE
	#define TRUE	1
#endif
#ifndef FALSE
	#define FALSE	0
#endif

#define MIDI_PPQN_DEFAULT		384
#define MIDI_VERSION_DEFAULT	1

#define MAX_MIDI_TRACKS			256
#define MAX_TRACK_POLYPHONY		64

typedef	void 	MidiFile;
typedef struct _MidiMessagePayload {

	MidiMessage		iType;

	DWORD			dt;
	DWORD			dwAbsPos;
	DWORD			iMsgSize;

	int				bImpliedMsg;
	MidiMessage		iImpliedMsg;

	BYTE 		*	data;
	DWORD 			data_sz;
	
	union _MsgData {
		struct _NoteOn {
			int			iNote;
			int			iChannel;
			int			iVolume;
		} NoteOn;
		struct _NoteOff {
			int			iNote;
			int			iChannel;
		} NoteOff;
		struct _NoteKeyPressure {
			int			iNote;
			int			iChannel;
			int			iPressure;
		} NoteKeyPressure;
		struct _NoteParameter {
			int			iChannel;
			MidiControlCommand	iControl;
			int			iParam;
		} NoteParameter;
		struct _ChangeProgram {
			int			iChannel;
			int			iProgram;
		} ChangeProgram;
		struct _ChangePressure {
			int			iChannel;
			int			iPressure;
		} ChangePressure;
		struct _PitchWheel {
			int			iChannel;
			int			iPitch;
		} PitchWheel;
		struct _MetaEvent {
			MidiMetaInfo	iType;
			union _Data {
				int					iMIDIPort;
				int					iSequenceNumber;
				struct _Text {
					BYTE			*pData;
				} Text;
				struct _Tempo {
					int				iBPM;
				} Tempo;
				struct _SMPTE {
					int				iHours, iMins;
					int				iSecs, iFrames,iFF;
				} SMPTE;
				struct _KeySig {
					MidiNote	iKey;
				} KeySig;
				struct _TimeSig {
					int				iNom, iDenom;
				} TimeSig;
				struct _Sequencer {
					BYTE			*pData;
					int				iSize;
				} Sequencer;
			} Data;
		} MetaEvent;
		struct _SysEx {
			BYTE		*pData;
			int			iSize;
		} SysEx;
	} MsgData;

	MidiMessage	iLastMsgType;
	BYTE		iLastMsgChnl;

} MidiMessagePayload;

MidiFile  	*	midiFileCreate(const char *pFilename, int bOverwriteIfExists);
int				midiFileSetTracksDefaultChannel(MidiFile *pMF, int iTrack, int iChannel);
int				midiFileGetTracksDefaultChannel(const MidiFile *pMF, int iTrack);
int				midiFileFlushTrack(MidiFile *pMF, int iTrack, int bFlushToEnd, DWORD dwEndTimePos);
int				midiFileSyncTracks(MidiFile *pMF, int iTrack1, int iTrack2);
int				midiFileSetPPQN(MidiFile *pMF, int PPQN);
int				midiFileGetPPQN(const MidiFile *pMF);
int				midiFileSetVersion(MidiFile *pMF, int iVersion);
int				midiFileGetVersion(const MidiFile *pMF);
MidiFile  	*	midiFileOpen(const char *pFilename);
int				midiFileClose(MidiFile *pMF);

int				midiSongAddSMPTEOffset(MidiFile *pMF, int iTrack, int iHours, int iMins, int iSecs, int iFrames, int iFFrames);
int				midiSongAddSimpleTimeSig(MidiFile *pMF, int iTrack, int iNom, int iDenom);
int				midiSongAddTimeSig(MidiFile *pMF, int iTrack, int iNom, int iDenom, int iClockInMetroTick, int iNotated32nds);
int				midiSongAddKeySig(MidiFile *pMF, int iTrack, MidiNote iKey);
int				midiSongAddTempo(MidiFile *pMF, int iTrack, int iTempo);
int				midiSongAddMIDIPort(MidiFile *pMF, int iTrack, int iPort);
int				midiSongAddEndSequence(MidiFile *pMF, int iTrack);

int				midiTrackAddRaw(MidiFile *pMF, int iTrack, int iDataSize, const BYTE *pData, int bMovePtr, int iDeltaTime);
int				midiTrackIncTime(MidiFile *pMF, int iTrack, int iDeltaTime, int bOverridePPQN);
int				midiTrackAddText(MidiFile *pMF, int iTrack, MidiTextInfo iType, const char *pTxt);
int				midiTrackAddMsg(MidiFile *pMF, int iTrack, MidiMessage iMsg, int iParam1, int iParam2);
int				midiTrackSetKeyPressure(MidiFile *pMF, int iTrack, int iNote, int iAftertouch);
int				midiTrackAddControlChange(MidiFile *pMF, int iTrack, MidiControlCommand iCCType, int iParam);
int				midiTrackAddProgramChange(MidiFile *pMF, int iTrack, int iInstrPatch);
int				midiTrackChangeKeyPressure(MidiFile *pMF, int iTrack, int iDeltaPressure);
int				midiTrackSetPitchWheel(MidiFile *pMF, int iTrack, int iWheelPos);
int				midiTrackAddNote(MidiFile *pMF, int iTrack, int iNote, int iLength, int iVol, int bAutoInc, int bOverrideLength);
int				midiTrackAddRest(MidiFile *pMF, int iTrack, int iLength, int bOverridePPQN);
int				midiTrackGetEndPos(MidiFile *pMF, int iTrack);

int				midiReadGetNumTracks(const MidiFile *pMF);
int				midiReadGetNextMessage(const MidiFile *pMF, int iTrack, MidiMessagePayload *pMsg);
void			midiReadInitMessage(MidiMessagePayload *pMsg);
void			midiReadFreeMessage(MidiMessagePayload *pMsg);

#endif