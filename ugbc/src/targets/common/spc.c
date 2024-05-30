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
@keyword SPC

@english
The function ''SPC'' can be used to set a number of spaces, which are printed
onto screen. ''SPC'' can be used several times in a sentence.

Also note that ''SPC'' will not overwrite and erase things already printed 
on screen, so ''PRINT SPC(3)'' is not the same as ''PRINT" "'' in that respect.

@italian
La funzione ''SPC'' può essere utilizzata per impostare un numero di spazi, 
che verranno stampati sullo schermo. ''SPC'' può essere utilizzato più volte 
in un comando.

Si noti inoltre che ''SPC'' non sovrascriverà né cancellerà le cose già 
stampate sullo schermo, quindi ''PRINT SPC(3)'' non è la stessa cosa di 
''PRINT" "'' sotto questo aspetto.

@syntax PRINT SPC(spaces)

@example PRINT SPC(10);"*"

@usedInExample texts_position_11.bas

@target all
</usermanual> */
void spc( Environment * _environment, char * _spaces ) {
    
    Variable * spaces = variable_retrieve_or_define( _environment, _spaces, VT_BYTE, 0 );

    cmove( _environment, spaces->name, NULL );

}
