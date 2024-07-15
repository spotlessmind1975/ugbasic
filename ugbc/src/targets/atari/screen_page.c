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

/* <usermanual>
@keyword SCREEN PAGE COUNT

@english

It returns the number of logical pages is available for the current mode
on this target. A logical page can be thought of just like an independent page of 
paper, holding both drawings and/or texts. The page is then placed on 
the screen, which then displays it to the user. 

@italian

Restituisce il numero di pagine logiche disponibili per la modalità corrente 
su questa piattaforma. Una pagina logica può essere pensata proprio come 
una pagina indipendente che contiene sia disegni che/o testi. La pagina viene quindi 
posizionata sullo schermo, che quindi la visualizza all'utente.

@syntax = SCREEN PAGE COUNT

@example IF SCREEN PAGE COUNT > 1 THEN
@example    PRINT "Multple pages available"
@example ENDIF

@target atari
</usermanual> */
Variable * screen_page_count( Environment * _environment ) {

    Variable * count = variable_temporary( _environment, VT_BYTE, 0 );

    variable_store( _environment, count->name, 0 );

    return count;
    
}

/* <usermanual>
@keyword SCREEN SHOW (function)

@english

The semantics of this keyword is different, depending on whether double buffering 
is enabled or not. If double buffering is enabled, the ''SCREEN SHOW'' function
allows to know which page is showed. There are two pages, page 0 (''PAGE 0'' 
or ''PAGE A'') and page 1 (''PAGE 1'' or ''PAGE B''). When you draw on page 0, 
page 1 is visible, and vice versa.

On the other hand, if double buffering is not enabled, this function will return
the actual screen page in use, as set by ''SCREEN SHOW'' command.

@italian

La semantica di questa parola chiave è diversa, a seconda che il doppio 
buffering sia abilitato o meno. Se il doppio buffering è abilitato, la funzione 
''SCREEN SHOW'' permette di sapere quale pagina viene visualizzata. Ci sono 
due pagine, la pagina 0 (''PAGE 0'' o ''PAGE A'') e la pagina 1 (''PAGE 1'' 
o ''PAGE B''). Quando si disegna sulla pagina 0, la pagina 1 è visibile e 
viceversa.

D'altra parte, se il double buffering non è abilitato, questa funzione restituirà 
la pagina dello schermo effettivamente in uso, come impostato dal comando 
''SCREEN SHOW''.

@syntax = SCREEN SHOW

@example IF SCREEN SHOW != SCREEN PAGE THEN
@example    PRINT "This string will be not visible!"
@example ENDIF

@target atari
</usermanual> */
Variable * screen_show( Environment * _environment ) {

    Variable * page = variable_retrieve( _environment, "CURRENTSHOW" );

    return page;
    
}

/* <usermanual>
@keyword SCREEN SHOW

@english

This command allows you to select the page of interest among 
those available for the current graphics mode, to show to the
user.

@italian

Questo comando permette di selezionare la pagina di interesse 
tra quelle disponibili per l'attuale modalità grafica,
da mostrare all'utente.

@syntax SCREEN SHOW #number

@example SCREEN SHOW #4

@target atari
</usermanual> */
void screen_show_set( Environment * _environment, int _page ) {

    Variable * page = variable_retrieve( _environment, "CURRENTSHOW" );

    variable_store( _environment, page->name, _page );

}

/* <usermanual>
@keyword SCREEN SHOW

@syntax SCREEN SHOW expression
@example SCREEN SHOW pagina+1

@target atari
</usermanual> */
void screen_show_set_vars( Environment * _environment, char * _page ) {

    Variable * value = variable_retrieve_or_define( _environment, _page, VT_BYTE, 0 );
    Variable * page = variable_retrieve( _environment, "CURRENTSHOW" );

    variable_move( _environment, value->name, page->name );

}

/* <usermanual>
@keyword SCREEN PAGE (function)

@english

The semantics of this keyword is different, depending on whether double buffering 
is enabled or not. If double buffering is enabled, the ''SCREEN PAGE'' function
allows to know which page is used for graphic output. There are two pages, page 
0 (''PAGE 0'' or ''PAGE A'') and page 1 (''PAGE 1'' or ''PAGE B''). When you
draw on page 0, page 1 is visible, and vice versa.

On the other hand, if doube buffering is not enabled, this function will return
the actual screen page in use for drawing, as set by ''SCREEN PAGE'' command.

@italian

La semantica di questa funzione cambia, a seconda se è abilitato o meno il
double buffering. Se è abilitato, la funzione ''SCREEN PAGE'' permette di
sapere su quale pagina (delle due) ci si trova a disegnare. Le pagine sono due, 
la pagina 0 (''PAGE 0'' or ''PAGE A'') e la pagina 1 (''PAGE 1'' or ''PAGE B''). 
Quando si disegna sulla pagina 0, la pagina 1 è visibile, e viceversa.

D'altra parte, se il double buffering non è abilitato, questa funzione
restituirà la pagina attuale in uso per l'output grafico, così come impostata
dal comando ''SCREEN PAGE''.

@syntax = SCREEN PAGE

@example IF SCREEN PAGE = PAGE 0 THEN
@example    PRINT "first page"
@example ENDIF

@target atari

</usermanual> */
Variable * screen_page( Environment * _environment ) {

    Variable * page = variable_retrieve( _environment, "CURRENTPAGE" );

    return page;
    
}

/* <usermanual>
@keyword SCREEN PAGE

@english

This command allows you to select the page of interest among 
those available for the current graphics mode.

@italian

Questo comando permette di selezionare la pagina di interesse 
tra quelle disponibili per l'attuale modalità grafica.

@syntax SCREEN PAGE #number

@example SCREEN PAGE #4

@target atari
</usermanual> */
void screen_page_set( Environment * _environment, int _page ) {

    Variable * page = variable_retrieve( _environment, "CURRENTPAGE" );

    variable_store( _environment, page->name, _page );

}

/* <usermanual>
@keyword SCREEN PAGE

@syntax SCREEN PAGE expression
@example SCREEN PAGE pagina+1

@target atari
</usermanual> */
void screen_page_set_vars( Environment * _environment, char * _page ) {

    Variable * value = variable_retrieve_or_define( _environment, _page, VT_BYTE, 0 );
    Variable * page = variable_retrieve( _environment, "CURRENTPAGE" );

    variable_move( _environment, value->name, page->name );

}