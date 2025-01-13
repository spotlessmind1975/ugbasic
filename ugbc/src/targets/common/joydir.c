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

Variable * joydir_semivars( Environment * _environment, char * _port ) {

    MAKE_LABEL

    Variable * joymove = variable_temporary( _environment, VT_BYTE, "(joymove)");
    variable_store( _environment, joymove->name, 0 );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)");
    variable_store( _environment, result->name, 0 );

    char detectedLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedLabel, "%sdetected", label );
    char detectedDownLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedDownLabel, "%sdetecteddown", label );
    char detectedLeftLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedLeftLabel, "%sdetectedleft", label );
    char detectedRightLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedRightLabel, "%sdetectedright", label );

    variable_move( _environment, joy_direction_semivars( _environment, _port, JOY_UP )->name, joymove->name );
    variable_compare_and_branch_const( _environment, joymove->name, 0, detectedDownLabel, 1 );
    variable_store( _environment, result->name, 1 );
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedDownLabel );
    variable_move( _environment, joy_direction_semivars( _environment, _port, JOY_DOWN )->name, joymove->name );
    variable_compare_and_branch_const( _environment, joymove->name, 0,  detectedLeftLabel, 1 );
    variable_store( _environment, result->name, 2 );
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedLeftLabel );
    variable_move( _environment, joy_direction_semivars( _environment, _port, JOY_LEFT )->name, joymove->name );
    variable_compare_and_branch_const( _environment, joymove->name, 0,  detectedRightLabel, 1 );
    variable_store( _environment, result->name, 4 );
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedRightLabel );
    variable_move( _environment, joy_direction_semivars( _environment, _port, JOY_RIGHT )->name, joymove->name );
    variable_compare_and_branch_const( _environment, joymove->name, 0,  detectedLabel, 1 );
    variable_store( _environment, result->name, 8 );
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedLabel );

    return result;

}

Variable * joydir( Environment * _environment, int _port ) {

    MAKE_LABEL

    Variable * joymove = variable_temporary( _environment, VT_BYTE, "(joymove)");
    variable_store( _environment, joymove->name, 0 );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)");
    variable_store( _environment, result->name, 0 );

    char detectedLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedLabel, "%sdetected", label );
    char detectedDownLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedDownLabel, "%sdetecteddown", label );
    char detectedLeftLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedLeftLabel, "%sdetectedleft", label );
    char detectedRightLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedRightLabel, "%sdetectedright", label );

    variable_move( _environment, joy_direction( _environment, _port, JOY_UP )->name, joymove->name );
    variable_compare_and_branch_const( _environment, joymove->name, 0, detectedDownLabel, 1 );
    variable_store( _environment, result->name, 1 );
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedDownLabel );
    variable_move( _environment, joy_direction( _environment, _port, JOY_DOWN )->name, joymove->name );
    variable_compare_and_branch_const( _environment, joymove->name, 0,  detectedLeftLabel, 1 );
    variable_store( _environment, result->name, 2 );
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedLeftLabel );
    variable_move( _environment, joy_direction( _environment, _port, JOY_LEFT )->name, joymove->name );
    variable_compare_and_branch_const( _environment, joymove->name, 0,  detectedRightLabel, 1 );
    variable_store( _environment, result->name, 4 );
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedRightLabel );
    variable_move( _environment, joy_direction( _environment, _port, JOY_RIGHT )->name, joymove->name );
    variable_compare_and_branch_const( _environment, joymove->name, 0,  detectedLabel, 1 );
    variable_store( _environment, result->name, 8 );
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedLabel );

    return result;

}
