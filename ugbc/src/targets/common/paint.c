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
 * @brief Emit ASM code for <b>PAIN</b>
 * 
 * @param _environment Current calling environment
 * @param _address Expression with the location to write to.
 * @param _value Expression to write.
 */
/* <usermanual>
@keyword PAINT

@english

The ''PAINT'' command is used in high resolution graphics modes, to fill a 
shape with a specified colour.

The ''x,y'' are the co−ordinates of the point where the painting is to start.
''c'' is the colour code of the colours to be used to paint. It must be 
between ''0'' and ''COLOR COUNT'' and be one of the available colour set 
for the working mode. If omitted, the current foreground colour is used.
''b'' is the colour code of the border at which painting is to stop. 
It must also be between ''0'' and ''8'', the painting will continue 
over a border of any other colour. If omitted, the current 
foreground colour is used.

@italian

Il comando ''PAINT'' viene utilizzato nelle modalità grafiche ad alta 
risoluzione, per riempire una forma con un colore specificato.

Le ''x,y'' sono le coordinate del punto in cui deve iniziare il 
dipinto. ''c'' è il codice colore dei colori da utilizzare per
dipingere. Deve essere compreso tra ''0'' e ''COLOR COUNT'' ed essere 
uno dei set di colori disponibili per la modalità di lavoro. 
Se omesso, viene utilizzato il colore di primo piano corrente. 
''b'' è il codice colore del bordo in cui si deve fermare il riempimento. 
Deve essere compreso anche tra ''0'' e ''8'', il dipinto proseguirà 
su un bordo di qualsiasi altro colore. Se omesso, viene utilizzato 
il colore di primo piano corrente.

@syntax PAINT (x,y)[, c[, b]]

@example PAINT(100,100),RED

@target all

</usermanual> */
void paint_var( Environment * _environment, char * _x, char * _y, char * _c, char *_b ) {

}
