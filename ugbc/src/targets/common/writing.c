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
 * @brief Emit code for <strong>WRITING</strong>
 * 
 * @param _environment Current calling environment
 * @param _mode Expression with the writing mode
 * @param _parts Expression with the writings parts
 */
/* <usermanual>
@keyword WRITING

@english
The WRITING command is used to control how the text is presented on the screen. 
The first value selects one of five writing modes:

 * ''REPLACE'' (0) – new text replaces any existing screen data;
 * ''OR'' (1) – merge new text with screen data, using logical OR;
 * ''XOR'' (2) – combine new text with screen data, using XOR;
 * ''AND'' (3) – Combine new text and screen data, using logical AND;
 * ''IGNORE'' (4) – ignore all subsequent printing instructions.

A number set as the optional second value selects which parts of the
text are to be printed on the screen, as follows:

 * ''NORMAL'' (3) – Print text and background together;
 * ''PAPER'' or ''PAPER ONLY'' (1) – paper only the background to be drawn on screen;
 * ''PEN'' or ''PEN ONLY'' (2) – ignore paper colour and print text on actual background.

The default value for both of the ''WRITING'' parameters is three (''3''), 
giving normal printed output.

@italian
Il comando ''WRITING'' viene utilizzato per controllare come 
il testo viene presentato sullo schermo. Il primo valore seleziona
una delle cinque modalità di scrittura:

  * ''REPLACE'' (0) - il nuovo testo sostituisce i dati dello schermo esistenti;
  * ''OR'' (1) - unisce il nuovo testo con i dati dello schermo, usando l'OR logico;
  * ''XOR'' (2) - combina il nuovo testo con i dati dello schermo, usando XOR;
  * ''AND'' (3) - Combina nuovo testo e dati sullo schermo, usando AND logico;
  * ''IGNORE'' (4) - ignora tutte le istruzioni di stampa successive.

Un numero impostato come secondo valore opzionale seleziona quali parti di
il testo deve essere stampato sullo schermo, come segue:

  * ''NORMAL'' (3) - Stampa testo e sfondo insieme;
  * ''PAPER'' o ''PAPER ONLY'' (1) - colora solo lo sfondo;
  * ''PEN'' o ''PEN ONLY'' (2) - colora solo il testo.

Il valore predefinito per entrambi i parametri di ''WRITING'' è tre ('' 3 ''),
che danno un output stampato normale.

@syntax WRITE {[mode]},{[parts]}

@example WRITING REPLACE,PEN
@example WRITING 3,

@UsedInExample texts_options_06.bas

@seeAlso PEN
@seeAlso PAPER
@target all
</usermanual> */
void writing( Environment * _environment, char * _mode, char * _parts ) {

    setup_text_variables( _environment );

    Variable * ww = variable_retrieve( _environment, "TEXTWW" );
    Variable * mode = variable_retrieve_or_define( _environment, _mode, VT_BYTE, WRITING_REPLACE );
    Variable * parts = variable_retrieve_or_define( _environment, _parts, VT_BYTE, WRITING_NORMAL );

    variable_move( _environment, mode->name, ww->name );
    cpu_math_mul2_const_8bit( _environment, ww->realName, 4, 0  );
    cpu_math_add_8bit( _environment, ww->realName, parts->realName, ww->realName );
    
}
