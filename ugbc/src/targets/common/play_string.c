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
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/* <usermanual>
@keyword PLAY (program)

@english

@italian

@syntax PLAY instructions

@example PLAY "O1V31T2L4GGL8GGL4B-AAGGF+G"

@usedInExample audio_play_02.bas

@target all
</usermanual> */
void play_string( Environment * _environment, char * _string ) {

    deploy_begin( play_string );

        MAKE_LABEL

        char doneCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneCommandLabel, "%sdone", label );
        char duration4CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( duration4CommandLabel, "%sduration4", label );
        char duration4DefaultLabel[MAX_TEMPORARY_STORAGE]; sprintf( duration4DefaultLabel, "%sduration4d", label );
        char durationCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( durationCommandLabel, "%sdurationc", label );
        char durationDoneCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( durationDoneCommandLabel, "%sdonec", label );
        char durationDotCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( durationDotCommandLabel, "%sdot", label );
        char note2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( note2CommandLabel, "%snote2", label );
        char noteACommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noteACommandLabel, "%snotea", label );
        char noteBCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noteBCommandLabel, "%snoteb", label );
        char noteCCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noteCCommandLabel, "%snotec", label );
        char noteCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noteCommandLabel, "%snote1", label );
        char noteDCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noteDCommandLabel, "%snoted", label );
        char noteECommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noteECommandLabel, "%snotee", label );
        char noteFCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noteFCommandLabel, "%snotef", label );
        char NoteFlatCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( NoteFlatCommandLabel, "%snoteflat", label );
        char noteGCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noteGCommandLabel, "%snoteg", label );
        char NoteHashCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( NoteHashCommandLabel, "%snotehash", label );
        char noteNCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noteNCommandLabel, "%snoten", label );
        char noteNxCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noteNxCommandLabel, "%snotenx", label );
        char octave2DefaultLabel[MAX_TEMPORARY_STORAGE]; sprintf( octave2DefaultLabel, "%soctave2", label );
        char octaveCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( octaveCommandLabel, "%soctave", label );
        char pause2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( pause2CommandLabel, "%spause2", label );
        char pauseCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( pauseCommandLabel, "%spause", label );
        char playCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( playCommandLabel, "%splaycommand", label );
        char playStringLabel[MAX_TEMPORARY_STORAGE]; sprintf( playStringLabel, "%splaystring", label );
        char readParameter2DoneLabel[MAX_TEMPORARY_STORAGE]; sprintf( readParameter2DoneLabel, "%spar2done", label );
        char readParameter2Label[MAX_TEMPORARY_STORAGE]; sprintf( readParameter2Label, "%spar2", label );
        char readParameter3Label[MAX_TEMPORARY_STORAGE]; sprintf( readParameter3Label, "%spar3", label );
        char readParameterAdd1[MAX_TEMPORARY_STORAGE]; sprintf( readParameterAdd1, "%sparadd1", label );
        char readParameterDiv2[MAX_TEMPORARY_STORAGE]; sprintf( readParameterDiv2, "%spardiv2", label );
        char readParameterLabel[MAX_TEMPORARY_STORAGE]; sprintf( readParameterLabel, "%spar", label );
        char readParameterMul2[MAX_TEMPORARY_STORAGE]; sprintf( readParameterMul2, "%sparmul2", label );
        char readParameterSub1[MAX_TEMPORARY_STORAGE]; sprintf( readParameterSub1, "%sparsub1", label );
        char tempo2DefaultLabel[MAX_TEMPORARY_STORAGE]; sprintf( tempo2DefaultLabel, "%stempo2", label );
        char tempoCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( tempoCommandLabel, "%stempo", label );
        char volume15DefaultLabel[MAX_TEMPORARY_STORAGE]; sprintf( volume15DefaultLabel, "%svolume15", label );
        char volumeCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( volumeCommandLabel, "%svolume", label );

        // Move to the start of routine
        cpu_jump( _environment, playStringLabel );

        // ----------------------------[ SUBROUTINE: READ PARAMETER ]

        // string -> (address, size)
        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
        Variable * size = variable_temporary( _environment, VT_BYTE, "(address)" );

        // xxx, -> (paddress, psize)
        Variable * paddress = variable_temporary( _environment, VT_ADDRESS, "(address)" );
        Variable * psize = variable_temporary( _environment, VT_BYTE, "(size)" );
        Variable * digit = variable_temporary( _environment, VT_BYTE, "(digit)" );
        Variable * parameter = variable_temporary( _environment, VT_POSITION, "(parameter)" );
        Variable * eos = variable_temporary( _environment, VT_BYTE, "(eos)" );

        cpu_label( _environment, readParameterLabel );

        // Take current address as starting of parameter
        cpu_move_16bit( _environment, address->realName, paddress->realName );

        // The parameter starts with a zero length.
        cpu_store_8bit( _environment, psize->realName, 0 );

        // You can use one of the following
        // suffixes instead of adding a numeral:
        // Suffix Purpose
        // + Adds 1 to the current value.
        // Subtracts 1 from the current value.
        // > Multiplies the current value by 2.
        // < Divides the current value by 2.

        cpu_move_8bit_indirect2( _environment, address->realName, digit->realName );
        cpu_compare_and_branch_8bit_const( _environment, digit->realName, '+', readParameterAdd1, 1 );
        cpu_compare_and_branch_8bit_const( _environment, digit->realName, '-', readParameterSub1, 1 );
        cpu_compare_and_branch_8bit_const( _environment, digit->realName, '>', readParameterMul2, 1 );
        cpu_compare_and_branch_8bit_const( _environment, digit->realName, '<', readParameterDiv2, 1 );

        // Let's retrieve the parameter. We know that the parameter should end
        // with a ',' so we are looking for that character, or for the end
        // of the original string, as well -- note that the end of the string
        // means end of the parameter itself.
        begin_do_loop( _environment );

            // Exit if playing string is ended
            cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, readParameter2Label, 1 );

            // Exit from this loop if the letter is not a digit.
            cpu_move_8bit_indirect2( _environment, address->realName, digit->realName );
            cpu_greater_than_8bit_const( _environment, digit->realName, '9', eos->realName, 0, 0 );
            cpu_compare_and_branch_8bit_const( _environment, eos->realName, 0xff, readParameter3Label, 1 );
            cpu_less_than_8bit_const( _environment, digit->realName, '0', eos->realName, 0, 0 );
            cpu_compare_and_branch_8bit_const( _environment, eos->realName, 0xff, readParameter3Label, 1 );

            cpu_dec( _environment, size->realName );
            cpu_inc_16bit( _environment, address->realName );

            // Increment the length of the parameter, and move along the
            // playing commands string
            cpu_inc( _environment, psize->realName );

        end_do_loop( _environment );

        cpu_label( _environment, readParameter3Label );

        // If we arrived here, it means that we are able to read and decode
        // the parameter as number.
        cpu_label( _environment, readParameter2Label );
        cpu_convert_string_into_8bit( _environment, paddress->realName, psize->realName, parameter->realName );

        cpu_return( _environment );

        cpu_label( _environment, readParameterAdd1 );
        cpu_inc( _environment, parameter->realName );
        cpu_jump( _environment, readParameter2DoneLabel );

        cpu_label( _environment, readParameterSub1 );
        cpu_dec( _environment, parameter->realName );
        cpu_jump( _environment, readParameter2DoneLabel );

        cpu_label( _environment, readParameterMul2 );
        cpu_math_mul2_const_8bit( _environment, parameter->realName, 1, 0 );
        cpu_jump( _environment, readParameter2DoneLabel );

        cpu_label( _environment, readParameterDiv2 );
        cpu_math_div2_const_8bit( _environment, parameter->realName, 1, 0 );
        cpu_jump( _environment, readParameter2DoneLabel );

        cpu_label( _environment, readParameter2DoneLabel );
        cpu_dec( _environment, size->realName );
        cpu_inc_16bit( _environment, address->realName );
        cpu_inc( _environment, psize->realName );
        cpu_return( _environment );

        // ------------------------------------ STARTING ROUTINE
        cpu_label( _environment, playStringLabel );

        // Temporary variable
        Variable * temp  = variable_temporary( _environment, VT_BYTE, "(temp)" );
        Variable * remainder  = variable_temporary( _environment, VT_BYTE, "(remainder)" );

        // Period and periodEquivalent
        Variable * period  = variable_temporary( _environment, VT_BYTE, "(period)" );
        variable_store( _environment, period->name, 0xff );
        Variable * periodEquivalent  = variable_temporary( _environment, VT_BYTE, "(periodEquivalent)" );
        variable_store( _environment, periodEquivalent->name, 0x80 );
        
        // String with the playing commands,
        Variable * string = variable_define( _environment, "playstring__string", VT_DSTRING, 0 );

        // Letter with command
        Variable * command = variable_temporary( _environment, VT_BYTE, "(command)" );

        // Note
        Variable * note8 = variable_temporary( _environment, VT_BYTE, "(note8)" );
        Variable * note16 = variable_temporary( _environment, VT_WORD, "(note16)" );
        Variable * duration16 = variable_temporary( _environment, VT_WORD, "(duration16)" );

        // Octave.
        Variable * octave = variable_retrieve( _environment, "PLAYOCTAVE" );

        // Duration
        Variable * duration = variable_retrieve( _environment, "PLAYDURATION" );

        // Tempo
        Variable * tempo = variable_retrieve( _environment, "PLAYTEMPO" );

        // Volume
        Variable * volume = variable_retrieve( _environment, "PLAYVOLUME" );

        // Retrieve the effective address of the string with the playing commands.

        cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );

        // ------------------------------------ FETCH AND DECODE LOOP
        begin_do_loop( _environment );

            // Are playing commands ended? Exit fetch and decode loop.
            cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, label, 1 );

            // Retrieve command letter.
            outline0("; command = ...");

            cpu_move_8bit_indirect2( _environment, address->realName, command->realName );
            cpu_dec( _environment, size->realName );
            cpu_inc_16bit( _environment, address->realName );

            // Is it 'O' ? -> OCTAVE
            cpu_compare_and_branch_char_const( _environment, command->realName, 'O', octaveCommandLabel, 1 );

            // Is it 'L' ? -> DURATION
            cpu_compare_and_branch_char_const( _environment, command->realName, 'L', durationCommandLabel, 1 );

            // Is it 'T' ? -> TEMPO
            cpu_compare_and_branch_char_const( _environment, command->realName, 'T', tempoCommandLabel, 1 );

            // Is it 'V' ? -> VOLUME
            cpu_compare_and_branch_char_const( _environment, command->realName, 'V', volumeCommandLabel, 1 );

            // Is it 'P' ? -> PAUSE
            cpu_compare_and_branch_char_const( _environment, command->realName, 'P', pauseCommandLabel, 1 );

            // Is it 'A'-'G' ? -> NOTE A-G
            cpu_compare_and_branch_char_const( _environment, command->realName, 'A', noteACommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, 'B', noteBCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, 'C', noteCCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, 'D', noteDCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, 'E', noteECommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, 'F', noteFCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, 'G', noteGCommandLabel, 1 );

            // Is it '1'-'9'? -> NOTE A-G in numeric notation
            cpu_compare_and_branch_char_const( _environment, command->realName, 'N', noteNxCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, '1', noteNCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, '2', noteNCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, '3', noteNCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, '4', noteNCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, '5', noteNCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, '6', noteNCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, '7', noteNCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, '8', noteNCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, command->realName, '9', noteNCommandLabel, 1 );

            // No command was recognized: silently, move to the next character.
            cpu_jump( _environment, doneCommandLabel );

            // ----------------------------[ OCTAVE ]

            // Our single octave (Octdve 2) sounds fine, but, variety being 
            // the spice of music as well as Irish stely, it gets a little 
            // boring when played over and over (like a piano with only 12 keys).
            // To change octaves, use the letter O followed by a number in the range
            // 1 to 5. If you don't specify the octave, the computer automatically 
            // uses Octave 2 (O2), which includes middle-C.

            cpu_label( _environment, octaveCommandLabel );
            cpu_move_8bit( _environment, octave->realName, parameter->realName );
            cpu_call( _environment, readParameterLabel );
            cpu_compare_and_branch_8bit_const( _environment, psize->realName, 0, octave2DefaultLabel, 1 );

            cpu_move_8bit( _environment, parameter->realName, octave->realName );

            cpu_jump( _environment, playCommandLabel );

            cpu_label( _environment, octave2DefaultLabel );
            cpu_store_8bit( _environment, parameter->realName, 2 );

            cpu_jump( _environment, playCommandLabel );

            // ----------------------------[ DURATION ]

            // The computer automatically uses quarter notes, the initial
            // "current value" for duration. To choose the note-length, 
            // use L followed by a number from 1 to 255. The number 1, 
            // for instance, denotes a whole note, 2 a half note, 
            // 4 a quarter note, 8 an eighth note, 16 a sixteenth note, 
            // and so on. In fact, you can use any number from 1 to 255. 

            cpu_label( _environment, durationCommandLabel );

            cpu_move_8bit( _environment, duration->realName, parameter->realName );
            cpu_call( _environment, readParameterLabel );
            cpu_compare_and_branch_8bit_const( _environment, psize->realName, 0, duration4DefaultLabel, 1 );

            cpu_label( _environment, duration4CommandLabel );

            cpu_math_div_8bit_to_8bit( _environment, period->realName, parameter->realName, duration->realName, remainder->realName, 0 );

            // If you read music, you already know about "dotted notes." The dot tells
            // you to increase the length of the note by one half its normal value. For
            // example, a dotted quarter note is equal to a "3/8" note.
            // You can play such a note by adding a period) or a series of periods
            // (...) to the number. Each period increases the note-length by 1/2 its
            // normal value. For example:

            cpu_label( _environment, durationDotCommandLabel );

            cpu_move_8bit_indirect2( _environment, address->realName, command->realName );
            cpu_compare_and_branch_char_const( _environment, command->realName, '.', durationDoneCommandLabel, 0 );
            cpu_dec( _environment, size->realName );
            cpu_inc_16bit( _environment, address->realName );

            cpu_move_8bit( _environment, duration->realName, temp->realName );
            cpu_math_div2_const_8bit( _environment, temp->realName, 1, 0 );
            cpu_math_add_8bit( _environment, duration->realName, temp->realName, duration->realName );

            cpu_jump( _environment, durationDotCommandLabel );

            cpu_label( _environment, durationDoneCommandLabel );
            cpu_jump( _environment, playCommandLabel );

            cpu_label( _environment, duration4DefaultLabel );
            cpu_store_8bit( _environment, duration->realName, 4 );
            cpu_jump( _environment, duration4CommandLabel );

            // ----------------------------[ TEMPO ]

            // You can increase or decrease the tempo with T and a 
            // number from 1 to 255.11 You don't specify a tempo, 
            // your computer automatically uses T2. 

            cpu_label( _environment, tempoCommandLabel );

            cpu_move_8bit( _environment, tempo->realName, parameter->realName );
            cpu_call( _environment, readParameterLabel );
            cpu_compare_and_branch_8bit_const( _environment, psize->realName, 0, tempo2DefaultLabel, 1 );
            cpu_move_8bit( _environment, parameter->realName, tempo->realName );
            cpu_math_div_8bit_to_8bit( _environment, period->realName, parameter->realName, periodEquivalent->realName, remainder->realName, 0 );

            cpu_jump( _environment, playCommandLabel );

            cpu_label( _environment, tempo2DefaultLabel );
            cpu_store_8bit( _environment, tempo->realName, 2 );
            cpu_store_8bit( _environment, periodEquivalent->realName, 0x80 );
            
            cpu_jump( _environment, playCommandLabel );

            // ----------------------------[ VOLUME ]

            // Sure, you can adjust the volume of your music by using the TV volume
            // control, but who wants to sit by the set all of the time? Especially when the
            // computer can adjust the volume for you.
            // Yourcornputer does this with the V (volume) feature. All you need to do is
            // use V followed by a numeral between 0 and 31. If you don't specify the
            // value of V, your computer automatically uses V15.

            cpu_label( _environment, volumeCommandLabel );

            cpu_move_8bit( _environment, volume->realName, parameter->realName );
            cpu_call( _environment, readParameterLabel );
            cpu_compare_and_branch_8bit_const( _environment, psize->realName, 0, volume15DefaultLabel, 1 );

            cpu_move_8bit( _environment, parameter->realName, volume->realName );

            cpu_jump( _environment, playCommandLabel );

            cpu_label( _environment, volume15DefaultLabel );
            cpu_store_8bit( _environment, volume->realName, 15 );            
            cpu_jump( _environment, playCommandLabel );

            // ----------------------------[ PAUSE ]

            // To put a pause between notes, use P followed by a number from 1 to 255.
            // Pause-lengths correspond to note-lengths with one important difference.
            // You can't use dots (periods) with P. To compensate, just type a series of
            // pauses. For example, to get a 3/8 pause, type P4P8 (= 1/4 + 1/8)

            cpu_label( _environment, pauseCommandLabel );

            cpu_call( _environment, readParameterLabel );

            cpu_math_div_8bit_to_8bit( _environment, period->realName, parameter->realName, temp->realName, remainder->realName, 0 );
            cpu_label( _environment, pause2CommandLabel );
            wait_milliseconds_var( _environment, periodEquivalent->name );
            cpu_dec( _environment, temp->realName );
            cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, pause2CommandLabel, 0 );

            cpu_jump( _environment, playCommandLabel );

            // ----------------------------[ NOTE (numeric) ]

            cpu_label( _environment, noteNCommandLabel );

            cpu_dec_16bit( _environment, address->realName );
            cpu_inc( _environment, size->realName );

            cpu_label( _environment, noteNxCommandLabel );

            cpu_call( _environment, readParameterLabel );

            cpu_move_8bit( _environment, parameter->realName, temp->realName );

            cpu_jump( _environment, note2CommandLabel );

            // ----------------------------[ NOTE ]

            cpu_label( _environment, noteACommandLabel );
            cpu_store_8bit( _environment, temp->realName, 9 );
            cpu_jump( _environment, noteCommandLabel );

            cpu_label( _environment, noteBCommandLabel );
            cpu_store_8bit( _environment, temp->realName, 11 );
            cpu_jump( _environment, noteCommandLabel );

            cpu_label( _environment, noteCCommandLabel );
            cpu_store_8bit( _environment, temp->realName, 0 );
            cpu_jump( _environment, noteCommandLabel );

            cpu_label( _environment, noteDCommandLabel );
            cpu_store_8bit( _environment, temp->realName, 2 );
            cpu_jump( _environment, noteCommandLabel );

            cpu_label( _environment, noteECommandLabel );
            cpu_store_8bit( _environment, temp->realName, 4 );
            cpu_jump( _environment, noteCommandLabel );

            cpu_label( _environment, noteFCommandLabel );
            cpu_store_8bit( _environment, temp->realName, 5 );
            cpu_jump( _environment, noteCommandLabel );

            cpu_label( _environment, noteGCommandLabel );
            cpu_store_8bit( _environment, temp->realName, 7 );
            cpu_jump( _environment, noteCommandLabel );

            // The first-and probably easier-way to play the 
            // note you want is to enter one of the standard 
            // musical notes-A, B, C, D, E, For G. 

            cpu_label( _environment, noteCommandLabel );

            cpu_move_8bit_indirect2( _environment, address->realName, parameter->realName );
            // To indicate a
            // sharp note, follow the note with a plus sign (+) or with the
            // pound sign (#). 
            cpu_compare_and_branch_char_const( _environment, parameter->realName, '#', NoteHashCommandLabel, 1 );
            cpu_compare_and_branch_char_const( _environment, parameter->realName, '+', NoteHashCommandLabel, 1 );
            // To indicate a flat, follow it with a minus sign (~).
            cpu_compare_and_branch_char_const( _environment, parameter->realName, '-', NoteFlatCommandLabel, 1 );
            cpu_jump( _environment, note2CommandLabel );

            // To indicate a
            // sharp note, follow the note with a plus sign (+) or with the
            // pound sign (#). 

            cpu_label( _environment, NoteHashCommandLabel );
            cpu_inc( _environment, temp->realName );
            cpu_inc_16bit( _environment, address->realName );
            cpu_jump( _environment, note2CommandLabel );

            // To indicate a flat, follow it with a minus sign (~).

            cpu_label( _environment, NoteFlatCommandLabel );
            cpu_dec( _environment, temp->realName );
            cpu_inc_16bit( _environment, address->realName );
            cpu_jump( _environment, note2CommandLabel );

            cpu_label( _environment, note2CommandLabel );
            cpu_store_8bit( _environment, note8->realName, 12 );
            cpu_math_mul_8bit_to_16bit( _environment, note8->realName, octave->realName, note16->realName, 0  );
            cpu_math_add_16bit_with_8bit( _environment, note16->realName, temp->realName, note16->realName );
            cpu_math_mul_8bit_to_16bit( _environment, duration->realName, periodEquivalent->realName, duration16->realName, 0  );

            // For example, A represents A natural; A# is A sharp; and A- is A flat.

            bell_vars( _environment, note16->name, duration16->name, NULL );

            cpu_label( _environment, playCommandLabel );

            cpu_label( _environment, doneCommandLabel );

        end_do_loop( _environment );
        // ------------------------------------ FETCH AND DECODE LOOP (end)

        cpu_label( _environment, label );
        cpu_return( _environment );

    deploy_end( play_string );

    Variable * string = variable_retrieve( _environment, _string );

    if ( ( string->type != VT_STRING ) && ( string->type != VT_DSTRING ) ) {
        CRITICAL_CANNOT_USE_PLAY_WITHOUT_STRING( _string );
    }

    if( string->type == VT_STRING ) {
        Variable * dstring = variable_temporary( _environment, VT_DSTRING, "(dstring)" );
        cpu_dsdefine( _environment, string->realName, dstring->realName );
        string = dstring;
    }

    Variable * parameter = variable_retrieve( _environment, "playstring__string" );
    
    variable_move( _environment, string->name, parameter->name );
    cpu_call( _environment, "lib_play_string");

}