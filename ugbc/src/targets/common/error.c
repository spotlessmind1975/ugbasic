/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>ERROR</b>
 * 
 * This function will stop completely everything.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword ERROR

@english

The ''ERROR'' command allows you to print a custom error message, halting program 
execution and also displaying the line number where the problem occurred. The line 
number is that of the original source code, and does not refer to the line number 
of the ugBASIC program as written on a modern computer. The message will be
print in the top left position of the screen.

@italian

Il comando ''ERROR'' permette di stampare un messaggio di errore personalizzato,
interrompendo l'esecuzione del programma e visualizzando anche il numero di linea 
dove il problema è avvenuto. Il numero di linea è quello del sorgente originale, e 
non fa riferimento al numero di linea del programma ugBASIC così come scritto sul
computer moderno. Il messaggio sarà stampato nella posizione in alto a sinistra
dello schermo.

@syntax ERROR ["message"]

@example ERROR "array out of bound" 

</usermanual> */
void error( Environment * _environment, char * _message ) {

    Variable * line = variable_temporary( _environment, VT_WORD, "(line)" );
    Variable * at = variable_temporary( _environment, VT_STRING, "(at)" );

    variable_store( _environment, line->name, ((Environment *)_environment)->yylineno );
    variable_store_string( _environment, at->name, " at " );

    home( _environment );
    print( _environment, _message, 0, 0 );
    print( _environment, at->name, 0, 0 );
    print( _environment, line->name, 1, 0 );
    halt( _environment );
    
}
