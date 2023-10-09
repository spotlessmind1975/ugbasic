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

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Return the distance between two (screen) positions
 *  
 * @param _environment Current calling environment
 * @param _x1 Abscissa of the first point
 * @param _y1 Ordinate of the first point
 * @param _x1 Abscissa of the second point
 * @param _y1 Ordinate of the second point
 * @return Variable* The distance (integer part)
 */
/* <usermanual>
@keyword DISTANCE

@english

The ''DISTANCE'' function calculates the geometric distance between two points. 
The distance is calculated with the application of the Pythagorean theorem, 
the result of which is however returned with the nnly integer part. If any 
component is omitted, the last screen position is used, instead.

@italian
La funzione ''DISTANCE'' calcola la distanza geometrica tra due punti. 
La distanza viene calcolata con l'applicazione del teorema di Pitagora, il cui 
risultato viene comunque restituito con la sola parte intera. Se viene omessa
una qualsiasi delle componenti, viene usata quella corrispondente all'ultima
position dello schermo.

@syntax = DISTANCE( [x1], [y1] TO [x2], [y2] )

@example result = DISTANCE( x1, y1 TO x2, y2 )

@usedInExample maths_distance_01.bas

@target all
@verified
</usermanual> */
Variable * distance( Environment * _environment, char * _x1, char * _y1, char * _x2, char * _y2 ) {

    Variable * x1 = variable_retrieve_or_define( _environment, _x1, VT_POSITION, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_POSITION, 0 );
    Variable * x2 = variable_retrieve_or_define( _environment, _x2, VT_POSITION, 0 );
    Variable * y2 = variable_retrieve_or_define( _environment, _y2, VT_POSITION, 0 );
    Variable * two = variable_resident( _environment, VT_POSITION, "(two)");
    
    variable_store( _environment, two->name, 2 );

    Variable * sum = variable_add( 
                    _environment,
                    powering( _environment, 
                        variable_sub( _environment,
                            x1->name,
                            x2->name
                        )->name, 
                        two->name 
                    )->name,
                    powering( _environment, 
                        variable_sub( _environment,
                            y1->name,
                            y2->name
                        )->name, 
                        two->name
                    )->name
                );

    Variable * result = variable_cast( _environment, sum->name, VT_POSITION );

    MAKE_LABEL

    variable_move(
            _environment,
            sqroot(
                _environment,
                result->name                 
            )->name,
            result->name
    );

    return result;
}

