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
 
 /* <usermanual>
 @keyword JMOVE
 
 @english
 
 The ''JMOVE'' command allows you to update two variables (abscissa and ordinate) 
 according to the detected position of the joystick. In addition to indicating the 
 variables that will be updated, it is possible to indicate the minimum and maximum 
 movement limits. If the variables are already beyond the limits, no updates will 
 be made.
 
 @italian
 
Il comando JMOVE permette di aggiornare due variabili (ascissa e ordinata) secondo 
la posizione rilevata del joystick. Oltre ad indicare le variabili che saranno 
oggetto di aggiornamento, è possibile indicare i limiti minimo e massimo di 
movimento. Se le variabili sono già oltre i limiti, non saranno effettuati 
aggiornamenti.
 
@syntax JMOVE port,x,y,minx,maxx,miny,maxy

@example JMOVE 0, playerX, playerY, 0, 10, 0, 42

@target all
</usermanual> */

void jmove( Environment * _environment, char * _port, char * _x, char * _y, char * _minx, char * _maxx, char * _miny, char *_maxy, char * _xstep, char * _ystep  ) {

    MAKE_LABEL

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    Variable * xstep = NULL;
    if ( _xstep ) {
        xstep = variable_retrieve( _environment, _xstep );
    } else {
        xstep = variable_temporary( _environment, VT_BYTE, "(xstep)" );
        variable_store( _environment, xstep->name, 1 );
    }

    Variable * ystep = NULL;
    if ( _ystep ) {
        ystep = variable_retrieve( _environment, _ystep );
    } else {
        ystep = variable_temporary( _environment, VT_BYTE, "(ystep)" );
        variable_store( _environment, ystep->name, 1 );
    }

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(compare)" );
    
    Variable * joymove = joydir_semivars( _environment, _port );

    char detectedLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedLabel, "%sdetected", label );
    char detectedDownLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedDownLabel, "%sdetecteddown", label );
    char detectedLeftLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedLeftLabel, "%sdetectedleft", label );
    char detectedRightLabel[MAX_TEMPORARY_STORAGE]; sprintf(detectedRightLabel, "%sdetectedright", label );

    variable_compare_and_branch_const( _environment, joymove->name, 2, detectedDownLabel, 0 );
    add_complex_vars( _environment, y->name, ystep->name, _miny, _maxy, 1 );    
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedDownLabel );
    variable_compare_and_branch_const( _environment, joymove->name, 1, detectedLeftLabel, 0 );
    add_complex_vars( _environment, y->name, variable_complement_const( _environment, ystep->name, 0 )->name, _miny, _maxy, 1 );    
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedLeftLabel );
    variable_compare_and_branch_const( _environment, joymove->name, 8,  detectedRightLabel, 0 );
    add_complex_vars( _environment, x->name, xstep->name, _minx, _maxx, 1 );    
    cpu_jump( _environment, detectedLabel );

    cpu_label( _environment, detectedRightLabel );
    variable_compare_and_branch_const( _environment, joymove->name, 4,  detectedLabel, 0 );
    add_complex_vars( _environment, x->name,  variable_complement_const( _environment, xstep->name, 0 )->name, _minx, _maxx, 1 );    

    cpu_label( _environment, detectedLabel );

}