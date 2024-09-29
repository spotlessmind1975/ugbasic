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

/**
 * @brief Emit ASM code for <b>WAIT VBL/b>
 * 
 * This function outputs a code that waits for a vertical blank.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword WAIT VBL

@english

The ''WAIT VBL'' command pauses program execution until a "vertical blank" is encountered. 
This is a signal that is triggered at each screen refresh, which usually occurs at 50 Hz 
in PAL standard and 60 Hz in NTSC standard.

Some video chipsets also allow you to specify a specific raster line, so execution will 
continue when that specific line is reached. If the chipset does not allow this, this 
constraint will be ignored, while still respecting the arrival of a vertical blank.

@italian

Il comando ''WAIT VBL'' mette in pausa l'esecuzione del programma fino all'arrivo di 
un "vertical blank". Si tratta di un segnale che viene innescato ad ogni aggiornamento 
della schermata, che di solito avviene a 50 Hz in standard PAL e 60 Hz in standard NTSC. 

Alcuni chipset video consentono di indicare anche una specifica linea di raster, 
per cui l'esecuzione continuerà al raggiungimento di quella specifica linea. Se il 
chipset non lo consente, tale vincolo sarà ignorato, pur rispettando l'arrivo di 
un blank verticale.

@syntax WAIT VBL [raster line]

@example WAIT VBL 100

@target c128
</usermanual> */

void wait_vbl( Environment * _environment, char * _raster_line ) {

    vic2_wait_vbl( _environment, _raster_line );

}
