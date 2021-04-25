/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

/**
 * @brief Emit ASM code for <b>RASTER AT [int]x WITH label</b>
 * 
 * This function outputs assembly code needed to initialize a raster routine. 
 * In other words, asynchronously and in parallel with the execution of the 
 * main program, the routine starting from the label provided will be executed
 * when the vertical brush on the screen reaches the value of _position. 
 * This function is particularly useful when the position is communicated 
 * is given as an integer.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _position The vertical position to wait for
 */
void raster_at( Environment * _environment, char * _label, int _position ) {
    
    outline2("; RASTER AT %d WITH %s (ignored)", _position, _label);

}

/**
 * @brief Emit ASM code for <b>RASTER AT [expression] WITH label</b>
 * 
 * This function outputs assembly code needed to initialize a raster routine. 
 * In other words, asynchronously and in parallel with the execution of the 
 * main program, the routine starting from the label provided will be executed
 * when the vertical brush on the screen reaches the value of _position. 
 * This function is particularly useful when the position is communicated 
 * is given as an expression
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _position The vertical position to wait for
 */
void raster_at_var( Environment * _environment, char * _label, char * _position ) {
   
    outline2("; RASTER AT %s WITH %s (ignored)", _position, _label);

}

/**
 * @brief Emit ASM code for <b>NEXT RASTER</b>
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 */
void next_raster( Environment * _environment ) {

    outline0("; NEXT RASTER (ignored)");

}

/**
 * @brief Emit ASM code for <b>NEXT RASTER AT [int]x WITH label</b>
 * 
 * This function outputs a code that puts the raster routine on hold for the 
 * vertical raster to arrive at a new _position with the execution of a different 
 * code from the previous one. This function is particularly useful when the 
 * position is communicated is given as an integer.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _position The vertical position to wait for
 */
void next_raster_at_with( Environment * _environment, int _position, char * _label ) {
    
    outline2("; RASTER AT %d WITH %s (ignored)", _position, _label);

}

/**
 * @brief Emit ASM code for <b>NEXT RASTER AT [expresssion] WITH label</b>
 * 
 * This function outputs a code that puts the raster routine on hold for the 
 * vertical raster to arrive at a new _position with the execution of a different 
 * code from the previous one. This function is particularly useful when the 
 * position is communicated is given as an expression.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _position The vertical position to wait for
 */
void next_raster_at_with_var( Environment * _environment, char * _position, char * _label ) {

    outline2("; NEXT RASTER AT %s WITH %s (ignored)", _position, _label);

}
