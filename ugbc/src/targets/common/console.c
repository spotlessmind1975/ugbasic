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
 * @brief Emit code for <strong>CONSOLE</strong>
 * 
 * @param _environment 
 */
/* <usermanual>
@keyword CONSOLE

@english
The ''CONSOLE'' command allows you to define an area of the screen where the
text output will take place. This area can be defined in both text and graphical
mode. Normally, it is set to the entire screen surface, but can be limited with this
command. This command works only with texts. The parameters describe the four vertices.

Note that the number of rows (''ROWS'') and columns (''COLUMNS'') will be updated conseguently.
If you need the screen rows and columns, you need to use ''SCREEN ROWS'' and ''SCREEN COLUMNS''.

@italian
Il comando ''CONSOLE'' permette di define un'area dello schermo dove avverrà 
l'output dei testi. Quest'area può essere definita sia in modalità testuale che grafica.
Normalmente, viene impostata sull'intera superficie dello schermo, ma può essere
limitato con questo comando. Questo comando lavora solo con i testi. 
I parametri descrivono i quattro vertici.

Nota che il numero di righe (''ROWS'') e di colonne (''COLUMNS'') saranno di conseguenza allineate.
Se hai bisogno di avere le righe e le colonne dell'intero schermo, devi usare i comandi 
''SCREEN ROWS'' e ''SCREEN COLUMNS''.

@syntax CONSOLE x1, y1 TO x2, y2

@example CONSOLE 0,0,SCREEN COLUMNS-1,2

@target all
</usermanual> */
void console( Environment * _environment, int _x1, int _y1, int _x2, int _y2 ) {

    int realWidth = ( _x2 - _x1 ) > 0 ? ( ( _x2 - _x1 ) + 1 ) : ( ( _environment->screenTilesWidth - _x1 ) + 1 );
    int realHeight = ( _x2 - _x1 ) > 0 ? ( ( _x2 - _x1 ) + 1 ) : ( ( _environment->screenTilesHeight - _y1 ) + 1 );

    variable_store( _environment, "XCURSYS", _x1 );
    variable_store( _environment, "YCURSYS", _y1 );
    variable_store( _environment, "CONSOLEX1", _x1 );
    variable_store( _environment, "CONSOLEY1", _y1 );
    variable_store( _environment, "CONSOLEW", realWidth );
    variable_store( _environment, "CONSOLEH", realHeight );
    variable_store( _environment, "CONSOLEX2", _x1 + realWidth - 1 );
    variable_store( _environment, "CONSOLEY2", _y2 + realHeight - 1 );

}

void console_vars( Environment * _environment, char * _x1, char * _y1, char * _x2, char * _y2 ) {

    MAKE_LABEL

    char consoleWPositiveLabel[MAX_TEMPORARY_STORAGE]; sprintf( consoleWPositiveLabel, "%scw", label );
    char consoleHPositiveLabel[MAX_TEMPORARY_STORAGE]; sprintf( consoleHPositiveLabel, "%sch", label );

    Variable * x1 = variable_retrieve_or_define( _environment, _x1, VT_SBYTE, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_SBYTE, 0 );
    Variable * x2 = variable_retrieve_or_define( _environment, _x2, VT_SBYTE, 0 );
    Variable * y2 = variable_retrieve_or_define( _environment, _y2, VT_SBYTE, 0 );

    Variable * w = variable_temporary( _environment, VT_SBYTE, "(w)" );
    Variable * h = variable_temporary( _environment, VT_SBYTE, "(h)" );

    variable_move( _environment, x1->name, "CONSOLEX1" );
    variable_move( _environment, y1->name, "CONSOLEY1");
    variable_move( _environment, x1->name, "XCURSYS" );
    variable_move( _environment, y1->name, "YCURSYS");

    variable_move( _environment, variable_sub( _environment, x2->name, x1->name )->name, "CONSOLEW" );
    variable_move( _environment, variable_sub( _environment, y2->name, y1->name )->name, "CONSOLEH" );

    cpu_compare_and_branch_8bit_const( _environment, variable_less_than_const( _environment, "CONSOLEW", 0, 1 )->realName, 0, consoleWPositiveLabel, 1 );

    variable_move( _environment, variable_sub( _environment, "CURRENTTILESWIDTH", x1->name )->name, "CONSOLEW" );

    cpu_label( _environment, consoleWPositiveLabel );

    cpu_inc( _environment, "CONSOLEW" );

    cpu_compare_and_branch_8bit_const( _environment, variable_less_than_const( _environment, "CONSOLEH", 0, 1 )->realName, 0, consoleHPositiveLabel, 1 );

    variable_move( _environment, variable_sub( _environment, "CURRENTTILESHEIGHT", y1->name )->name, "CONSOLEH" );

    cpu_label( _environment, consoleHPositiveLabel );

    console_update_width_in_bytes( _environment );

    cpu_inc( _environment, "CONSOLEH" );

    cpu_math_add_8bit( _environment, "CONSOLEX1", "CONSOLEW", "CONSOLEX2" );
    cpu_dec( _environment, "CONSOLEX2" );
    cpu_math_add_8bit( _environment, "CONSOLEY1", "CONSOLEW", "CONSOLEY2" );
    cpu_dec( _environment, "CONSOLEY2" );

}
