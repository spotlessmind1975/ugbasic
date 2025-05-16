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

#if !(defined(__pc128op__) || defined(__mo5__) || defined(__to8__))

/**
 * @brief Emit code for <strong>FADE</strong>
 */

/* <usermanual>
@keyword FADE OUT

@english

The ''FADE OUT'' command is a fundamental tool for creating smooth visual 
transitions, allowing you to gradually modulate the disappearance of 
elements. The ''FADE OUT'' command, in its simplest form, starts a fade-out 
process, which will gradually decrease in opacity until it becomes completely 
invisible. The duration of this transition, in the absence of further 
specifications, is determined by default. However, it is possible to exert 
more precise control over the duration of the fade-out through the syntax 
''FADE OUT PERIOD time'', where the keyword ''PERIOD'' introduces the time 
specification time. The latter defines the time interval within which the 
element will pass from its full visibility to absolute invisibility.

@italian

Il comando ''FADE OUT'' rappresenta uno strumento fondamentale per la creazione 
di transizioni visive fluide, permettendo di modulare gradualmente la sparizione 
degli elementi. Il comando ''FADE OUT'', nella sua forma più semplice, avvia un 
processo di dissolvenza in uscita, il quale inizierà progressivamente a diminuire 
la propria opacità fino a diventare completamente invisibile. La durata di questa 
transizione, in assenza di specificazioni ulteriori, è determinata da impostazioni 
predefinite. Tuttavia, è possibile esercitare un controllo più preciso sulla durata 
della dissolvenza in uscita attraverso la sintassi ''FADE OUT PERIOD time'', dove 
la parola chiave ''PERIOD'' introduce la specifica temporale time. Quest'ultima 
definisce l'intervallo di tempo entro il quale l'elemento passerà dalla sua piena 
visibilità all'assoluta invisibilità.

@syntax FADE OUT[PERIOD time]

@example FADE OUT
@example FADE OUT PERIOD 10

@seeAlso FADE IN
@target atari
@target atarixl
@target pc128op
@target mo5
@target to8
</usermanual> */

void fade_out( Environment * _environment, char * _period  ) {

}

#endif