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
 * @brief Emit ASM code for <b>HALT</b>
 * 
 * This function outputs the indefinite stop code. Note that even if the 
 * main program is suspended indefinitely, the raster and other functions 
 * will continue without problems.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
    @keyword HALT
    
    @english
    Stop the main process indefinitely.  Note that even if the 
    main program is suspended, the raster and other functions 
    will continue without problems.
    
    @italian
    Interrompi il processo principale a tempo indeterminato. Notare che 
    anche se il programma principale viene sospeso, il raster e altre 
    funzioni continueranno senza problemi.

    @syntax HALT

    @example HALT

    @target all

 </usermanual> */
void halt( Environment * _environment ) {

    outline0("; HALT");

    cpu_halt( _environment );
    
}
