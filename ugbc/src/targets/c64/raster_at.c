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

/**
 * @brief Emit ASM code for <b>RASTER AT [int] WITH [label]</b>
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
/* <usermanual>
@keyword RASTER AT

@english
Initialize a raster routine. In other words, asynchronously and in parallel 
with the execution of the main program, the routine starting from the label 
provided will be executed when the video raster on the screen reaches the 
value given. 

@italian
Inizializza una routine raster. In altre parole, in modo asincrono e in parallelo
con l'esecuzione del programma principale, viene impostata una routine a partire 
dall'etichetta fornita. Questa sarà eseguita quando il raster video sullo 
schermo raggiunge il valore dato. 

@syntax RASTER AT [integer] WITH [label]

@example RASTER AT #$42 WITH rasterRoutine

@target c64
</usermanual> */
void raster_at( Environment * _environment, char * _label, int _position ) {
    
    

    char positionlo[MAX_TEMPORARY_STORAGE]; sprintf( positionlo, "#$%2.2x", (unsigned char) ( _position & 0xff )  );
    char positionhi[MAX_TEMPORARY_STORAGE]; sprintf( positionhi, "#$%2.2x", (unsigned char) ( ( ( _position >> 8 ) & 0x01 ) << 8 ) );

    vic2_raster_at( _environment, _label, positionlo, positionhi );

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
/* <usermanual>
@keyword RASTER AT

@syntax RASTER AT [expression] WITH [label]

@example RASTER AT (rasterLine+1) WITH rasterRoutine
</usermanual> */
void raster_at_var( Environment * _environment, char * _label, char * _position ) {
   
    

    MAKE_LABEL

    Variable * var = variable_retrieve( _environment, _position );

    char positionlo[MAX_TEMPORARY_STORAGE]; sprintf( positionlo, "%s", var->realName );
    char positionhi[MAX_TEMPORARY_STORAGE]; sprintf( positionhi, "%s", address_displacement(_environment, var->realName, "1") );

    vic2_raster_at( _environment, _label, positionlo, positionhi );

}

