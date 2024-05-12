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

	// - CONSOLE ASSIGNMENT
	// 	 - X1 = x1
	// 	 - X2 = x2
	// 	 - Y1 = y1
	// 	 - Y2 = y2

    _environment->consoleX1 = _x1;
    _environment->consoleY1 = _y1;
    _environment->consoleX2 = _x2;
    _environment->consoleY2 = _y2;

	// - CONSOLE NORMALIZATION
	// 	 RULE 1) x2 <> x1	->	X2 = ( SW - 1 )

    if ( _environment->consoleX1 == _environment->consoleX2 ) {
        _environment->consoleX2 = _environment->screenTilesWidth - 1;
    }

	// 	 RULE 2) x2 > x1	->	X2 = ( SW - 1 )

    if ( _environment->consoleX1 >= _environment->consoleX2 ) {
        _environment->consoleX2 = _environment->screenTilesWidth - 1;
    }

	// 	 RULE 3) x2 < SW	->	X2 = ( SW - 1 )

    if ( _environment->consoleX2 >= _environment->screenTilesWidth ) {
        _environment->consoleX2 = _environment->screenTilesWidth - 1;
    }

	// 	 RULE 4) ( y2 >= y1 ) ->	Y2 = y1

    if ( _environment->consoleY2 < _environment->consoleY1 ) {
        _environment->consoleY2 = _environment->consoleY1;
    }

	// - CONSOLE COMPUTATION
	// 	 - W = ( ( X2 - X1 ) + 1 )

    _environment->consoleW = ( _environment->consoleX2 - _environment->consoleX1 ) + 1;
    
	// 	 - H = ( ( y2 - y1 ) + 1 )

    _environment->consoleH = ( _environment->consoleY2 - _environment->consoleY1 ) + 1;

	// 	(+ graphical if needed)

    variable_store( _environment, "XCURSYS", _environment->consoleX1 );
    variable_store( _environment, "YCURSYS", _environment->consoleY1 );

    console_calculate( _environment );

    variable_store( _environment, "CONSOLEX1", _environment->consoleX1 );
    variable_store( _environment, "CONSOLEY1", _environment->consoleY1 );
    variable_store( _environment, "CONSOLEX2", _environment->consoleX2);
    variable_store( _environment, "CONSOLEY2", _environment->consoleY2 );
    variable_store( _environment, "CONSOLEW", _environment->consoleW );
    variable_store( _environment, "CONSOLEH", _environment->consoleH );

}

void console_vars( Environment * _environment, char * _x1, char * _y1, char * _x2, char * _y2 ) {

    MAKE_LABEL

    char consoleX1X2DifferentLabel[MAX_TEMPORARY_STORAGE]; sprintf( consoleX1X2DifferentLabel, "%sx1x2diff", label );
    char consoleX1LTX2Label[MAX_TEMPORARY_STORAGE]; sprintf( consoleX1LTX2Label, "%sx1ltx2", label );
    char consoleX1LTSWLabel[MAX_TEMPORARY_STORAGE]; sprintf( consoleX1LTSWLabel, "%sx1ltsw", label );
    char consoleY2LTY1Label[MAX_TEMPORARY_STORAGE]; sprintf( consoleY2LTY1Label, "%sy2lty1", label );

    Variable * x1 = variable_retrieve_or_define( _environment, _x1, VT_SBYTE, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_SBYTE, 0 );
    Variable * x2 = variable_retrieve_or_define( _environment, _x2, VT_SBYTE, 0 );
    Variable * y2 = variable_retrieve_or_define( _environment, _y2, VT_SBYTE, 0 );

    // _environment->consoleSA = 0;
    // _environment->consoleWB = 0;
    // _environment->consoleHB = 0;

	// - CONSOLE ASSIGNMENT
	// 	 - X1 = x1
	// 	 - X2 = x2
	// 	 - Y1 = y1
	// 	 - Y2 = y2

    // _environment->consoleX1 = _x1;

    variable_move( _environment, x1->name, "CONSOLEX1" );

    // _environment->consoleY1 = _y1;

    variable_move( _environment, y1->name, "CONSOLEY1" );

    // _environment->consoleX2 = _x2;

    variable_move( _environment, x2->name, "CONSOLEX2" );

    // _environment->consoleY2 = _y2;

    variable_move( _environment, y2->name, "CONSOLEY2" );

	// - CONSOLE NORMALIZATION
	// 	 RULE 1) x2 <> x1	->	X2 = ( SW - 1 )

    // if ( _environment->consoleX1 == _environment->consoleX2 ) {
    //     _environment->consoleX2 = _environment->screenTilesWidth - 1;
    // }

    outline0("; compare (a)");

    cpu_compare_and_branch_8bit_const( 
        _environment, 
        variable_compare( _environment, "CONSOLEX1", "CONSOLEX2" )->realName, 
        0, 
        consoleX1X2DifferentLabel,
        1 
    );
        variable_move( 
            _environment, 
            variable_sub_const( 
                _environment, 
                "CURRENTTILESWIDTH",
                1 )->name, 
            "CONSOLEX2" );
    cpu_label( _environment, consoleX1X2DifferentLabel );

    outline0("; compare (b)");

	// 	 RULE 2) x2 > x1	->	X2 = ( SW - 1 )

    // if ( _environment->consoleX1 >= _environment->consoleX2 ) {
    //     _environment->consoleX2 = _environment->screenTilesWidth - 1;
    // }

    cpu_compare_and_branch_8bit_const( 
        _environment, 
        variable_greater_than( _environment, "CONSOLEX1", "CONSOLEX2", 1 )->realName,
        0, 
        consoleX1LTX2Label,
        1 
    );
        variable_move( 
            _environment, 
            variable_sub_const( 
                _environment, 
                "CURRENTTILESWIDTH",
                1 )->name, 
            "CONSOLEX2" );
    cpu_label( _environment, consoleX1LTX2Label );

	// 	 RULE 3) x2 < SW	->	X2 = ( SW - 1 )

    // if ( _environment->consoleX2 >= _environment->screenTilesWidth ) {
    //     _environment->consoleX2 = _environment->screenTilesWidth - 1;
    // }

    cpu_compare_and_branch_8bit_const( 
        _environment, 
        variable_greater_than( _environment, "CONSOLEX2", "CURRENTTILESWIDTH", 1 )->realName,
        0, 
        consoleX1LTSWLabel,
        1 
    );
        variable_move( 
            _environment, 
            variable_sub_const( 
                _environment, 
                "CURRENTTILESWIDTH",
                1 )->name, 
            "CONSOLEX2" );
    cpu_label( _environment, consoleX1LTSWLabel );

	// 	 RULE 4) ( y2 >= y1 ) ->	Y2 = y1

    // if ( _environment->consoleY2 > _environment->consoleY1 ) {
    //     _environment->consoleY2 = _environment->consoleY1;
    // }

    cpu_compare_and_branch_8bit_const( 
        _environment, 
        variable_less_than( _environment, "CONSOLEY2", "CONSOLEY1", 1 )->realName,
        0, 
        consoleY2LTY1Label,
        1 
    );
        variable_move( 
            _environment, 
            "CONSOLEY1",
            "CONSOLEY2" );
    cpu_label( _environment, consoleY2LTY1Label );

	// - CONSOLE COMPUTATION
	// 	 - W = ( ( X2 - X1 ) + 1 )

    // _environment->consoleW = ( _environment->consoleX2 - _environment->consoleX1 ) + 1;

    variable_move( 
        _environment, 
        variable_sub( _environment,
            "CONSOLEX2",
            "CONSOLEX1" )->name,
        "CONSOLEW" );
    cpu_inc( _environment, "CONSOLEW" );

	// 	 - H = ( ( y2 - y1 ) + 1 )

    // _environment->consoleH = ( _environment->consoleY2 - _environment->consoleY1 ) + 1;

    variable_move( 
        _environment, 
        variable_sub( _environment,
            "CONSOLEY2",
            "CONSOLEY1" )->name,
        "CONSOLEH" );
    cpu_inc( _environment, "CONSOLEH" );

	// 	(+ graphical if needed)

    variable_move( _environment, "CONSOLEX1", "XCURSYS" );
    variable_move( _environment, "CONSOLEY1", "YCURSYS" );

    console_calculate_vars( _environment );

}
