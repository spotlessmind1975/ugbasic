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

#include "../../../ugbc.h"

#if defined(__coco__) || defined(__coco3__) || defined(__d32__) || defined(__d64__) || defined(__mo5__) || defined(__pc128op__) || defined(__to8__)

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

void flip_image_vars_direction( Environment * _environment, char * _image, char * _frame, char * _sequence, int _direction ) {

    char directionConstantName[MAX_TEMPORARY_STORAGE]; sprintf( directionConstantName, "FLIPIMAGEDIRECTION%4.4x", _direction );
    char directionConstantParameter[MAX_TEMPORARY_STORAGE]; sprintf( directionConstantParameter, "#FLIPIMAGEDIRECTION%4.4x", _direction );
    
    Constant * directionConstant = constant_find( _environment->constants, directionConstantName );
    
    if ( !directionConstant ) {
        directionConstant = malloc( sizeof( Constant ) );
        memset( directionConstant, 0, sizeof( Constant ) );
        directionConstant->name = strdup( directionConstantName );
        directionConstant->realName = strdup( directionConstantName );
        directionConstant->value = _direction;
        directionConstant->type = CT_INTEGER;
        directionConstant->next = _environment->constants;
        _environment->constants = directionConstant;
    }

    flip_image_vars( _environment, _image, _frame, _sequence, directionConstantParameter );
    
}

void flip_image_vars_indirection( Environment * _environment, char * _image, char * _frame, char * _sequence, char * _direction ) {
    Variable * direction = variable_retrieve_or_define( _environment, _direction, VT_BYTE, 0 );
    flip_image_vars( _environment, _image, _frame, _sequence, direction->realName );
}

#endif
