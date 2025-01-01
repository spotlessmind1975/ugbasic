/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>SCREEN SWAP</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword SCREEN PAGE

@english

The semantics of this keyword is different, depending on whether double buffering 
is enabled or not. If double buffering is enabled, the ''SCREEN PAGE'' function
allows to know which page the program is on. There are two pages, page 0 (''PAGE 0'' 
or ''PAGE A'') and page 1 (''PAGE 1'' or ''PAGE B''). When you draw on page 0, 
page 1 is visible, and vice versa.

On the other hand, if doube buffering is not enabled, this function will return
the actual screen page in use, as set by ''SCREEN PAGE'' command.

@italian

La semantica di questa funzione cambia, a seconda se è abilitato o meno il
double buffering. Se è abilitato, la funzione ''SCREEN PAGE'' permette di
sapere su quale pagina (delle due) ci si trova. Le pagine sono due, 
la pagina 0 (''PAGE 0'' or ''PAGE A'') e la pagina 1 (''PAGE 1'' or ''PAGE B''). 
Quando si disegna sulla pagina 0, la pagina 1 è visibile, e viceversa.

D'altra parte, se il double buffering non è abilitato, questa funzione
restituirà la pagina attuale in uso, così come impostata dal comando 
''SCREEN PAGE''.

@syntax = SCREEN PAGE

@example IF SCREEN PAGE = PAGE 0 THEN
@example    PRINT "first page"
@example ENDIF

@target coco3
@version
</usermanual> */
Variable * screen_page( Environment * _environment ) {

    Variable * page = variable_retrieve( _environment, "GIMESCREENCURRENT" );

    return page;
    
}
