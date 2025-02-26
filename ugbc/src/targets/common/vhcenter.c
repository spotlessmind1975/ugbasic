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
 * @brief Emit code for <strong>CENTRE ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _string String to center
 */
/* <usermanual>
@keyword VHCENTRE

@english

@italian

@syntax VHCENTRE text [;]

@example VHCENTRE "HELLO!"
@example VHCENTRE "HELLO!";

@target all

@alias VHCENTER

@verified
</usermanual> */
/* <usermanual>
@keyword VHCENTER

@english

The ''VHCENTER'' command aligns a text string in the center of the screen. In other 
words, it allows you to position a word or phrase so that it occupies the 
available space in a symmetrical manner, vertically and horizontally. If the statement is followed 
by a semicolon, the cursor will remain on the same line. Otherwise, it will move to 
the next line.

This command can be used to create aesthetically pleasing section or chapter titles,
to center menu options in the center of the screen and to format data neatly 
in a report. Centered text is easier to read and makes programs look neater.

By using VCENTER, you can ensure that text is aligned uniformly in different 
parts of the program, and on different targets. Moreover, reduce the need 
to manually calculate character positions. 

@italian

Il comando ''VHCENTER'' allinea una stringa di testo al centro dello schermo. 
In altre parole, consente di posizionare una parola o una frase in modo che 
occupi lo spazio disponibile in modo simmetrico, in verticale e orizzontale. Se l'istruzione 
è seguita da un punto e virgola, il cursore rimarrà sulla stessa riga. In caso 
contrario, si sposterà alla riga successiva.

Questo comando può essere utilizzato per creare titoli di sezioni o capitoli 
esteticamente gradevoli, per centrare le opzioni di menu al centro dello schermo 
e per formattare i dati in modo ordinato in un report. Il testo centrato è più facile
da leggere e rende i programmi più ordinati.

Utilizzando VHCENTER, è possibile assicurarsi che il testo sia allineato in modo 
uniforme in diverse parti del programma e su diversi target. Inoltre, si riduce 
la necessità di calcolare manualmente le posizioni dei caratteri.

@syntax VHCENTER text [;]

@example VHCENTER "HELLO!"
@example VHCENTER "HELLO!";

@target all

@alias VHCENTRE
</usermanual> */

void vhcenter( Environment * _environment, char * _string, int _newline, char * _width ) {

    MAKE_LABEL
    
    Variable * string = variable_retrieve( _environment, _string );
    Variable * currentHeight = variable_retrieve( _environment, "CONSOLEH");
        
    Variable * height = variable_div2_const( _environment, currentHeight->name, 2, NULL );

    locate( _environment, NULL, height->name );

    center( _environment, string->name, _newline, _width );

}
