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

void sbpen_set( Environment * _environment, int _index, char * _color ) {
    Variable * sbink = NULL;
    switch( _index ) {
        case 0:
            sbink = variable_retrieve( _environment, "SBINK0" );
            break;
        case 1:
            sbink = variable_retrieve( _environment, "SBINK1" );
            break;
        case 2:
            sbink = variable_retrieve( _environment, "SBINK2" );
            break;
    }
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );
    variable_move( _environment, color->name, sbink->name );
}

void sbpaper_set( Environment * _environment, char * _color ) {
    Variable * sbpaper = variable_retrieve( _environment, "SBPAPER" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );
    variable_move( _environment, color->name, sbpaper->name );
}

Variable * sbpen_get( Environment * _environment, char * _index ) {
    
    MAKE_LABEL

    Variable * index = variable_retrieve_or_define( _environment, _index, VT_BYTE, 0 );
    Variable * color = variable_temporary( _environment, VT_COLOR, "(ink)" );

    char sbpenGet0Label[MAX_TEMPORARY_STORAGE]; sprintf( sbpenGet0Label, "%sl0", label );
    char sbpenGet1Label[MAX_TEMPORARY_STORAGE]; sprintf( sbpenGet1Label, "%sl1", label );
    char sbpenGet2Label[MAX_TEMPORARY_STORAGE]; sprintf( sbpenGet2Label, "%sl2", label );
    char sbpenGetDoneLabel[MAX_TEMPORARY_STORAGE]; sprintf( sbpenGetDoneLabel, "%sld", label );

    cpu_compare_8bit_const( _environment, index->realName, 1, sbpenGet1Label, 1 );
    cpu_compare_8bit_const( _environment, index->realName, 2, sbpenGet2Label, 1 );

    cpu_label( _environment, sbpenGet0Label );
    variable_move( _environment, "SBINK0", color->name );
    cpu_jump( _environment, sbpenGetDoneLabel );

    cpu_label( _environment, sbpenGet1Label );
    variable_move( _environment, "SBINK1", color->name );
    cpu_jump( _environment, sbpenGetDoneLabel );

    cpu_label( _environment, sbpenGet2Label );
    variable_move( _environment, "SBINK2", color->name );
    cpu_jump( _environment, sbpenGetDoneLabel );

    cpu_label( _environment, sbpenGetDoneLabel );

    return color;
}

Variable * sbpaper_get( Environment * _environment ) {
    return variable_retrieve( _environment, "SBPAPER" );
}
