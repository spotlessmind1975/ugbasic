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
 * @brief Emit ASM code for <b>NEXT RASTER AT [int] WITH [label]</b>
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
/* <usermanual>
@keyword NEXT RASTER AT

@english
Wait for the next raster at a specific, new, raster position
and to execute the code at the given label. Meanwhile, the 
execution of the main code will resume where it left off.

@italian
Attendi il raster successivo in una nuova posizione raster specifica
ed esegui il codice in corrispondenza dell'etichetta data. Nel 
frattempo, l'esecuzione del codice principale riprenderà da dove 
era stata interrotta.

@syntax NEXT RASTER AT # [integer] WITH [label]

@example NEXT RASTER AT #$42 WITH myRasterRoutine

@target vic20
</usermanual> */
void next_raster_at_with( Environment * _environment, int _position, char * _label ) {
    
    

    char positionlo[MAX_TEMPORARY_STORAGE]; sprintf( positionlo, "%2.2x", (unsigned char) ( _position & 0xff )  );
    char positionhi[MAX_TEMPORARY_STORAGE]; sprintf( positionhi, "%2.2x", (unsigned char) ( ( ( _position >> 8 ) & 0x01 ) << 8 ) );

    vic1_next_raster_at( _environment, _label, positionlo, positionhi );

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
/* <usermanual>
@keyword NEXT RASTER AT

@syntax NEXT RASTER AT [expression] WITH [label]

@example NEXT RASTER AT newRaterLine WITH myRasterRoutine
</usermanual> */
void next_raster_at_with_var( Environment * _environment, char * _position, char * _label ) {

    

    MAKE_LABEL

    Variable * var = variable_retrieve( _environment, _position );

    char positionlo[MAX_TEMPORARY_STORAGE]; sprintf( positionlo, "%s", var->realName );
    char positionhi[MAX_TEMPORARY_STORAGE]; sprintf( positionhi, "%s", address_displacement(_environment, var->realName, "1") );

    vic1_next_raster_at( _environment, _label, positionlo, positionhi );

}
