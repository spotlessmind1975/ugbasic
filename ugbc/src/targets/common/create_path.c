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
 * @brief Emit ASM code to implement <strong>CREATE PATH</strong> command
 * 
 * @param _environment Current calling environment
 * @param _x1 Left abscissa of the line
 * @param _y1 Left ordinate of the line
 * @param _x2 Right abscissa of the line
 * @param _y2 Right ordinate of the line
 */
/* <usermanual>
@keyword CREATE PATH

@english

The ''CREATE PATH'' command is designed to define a straight path between two specified points. 
Instead of immediately drawing the line, this command is intended to prepare an internal 
"data structure" that contains the information needed to "travel" this path, point by point, 
later, using the ''TRAVEL'' command. It therefore separates the logic of "where to go" from the 
logic of "how to get there", making the code more modular and readable.

The main goal is to separate the definition of the path from its actual graphical 
implementation. This approach can be useful in several situations: you can define paths 
once, and then have an object move along that path in an animated way, you can update the 
position of an object at regular intervals using ''TRAVEL''.

@italian

Il comando ''CREATE PATH'' è progettato per definire un percorso rettilineo tra due punti 
specificati. Invece di disegnare immediatamente la linea, questo comando ha lo scopo di 
preparare una "struttura dati" interna che contiene le informazioni necessarie per 
"percorrere" questo tragitto, punto per punto, in un secondo momento, utilizzando il 
comando ''TRAVEL''. Separa quindi la logica del "dove andare" dalla logica del "come 
arrivare", rendendo il codice più modulare e leggibile.

L'obiettivo principale è scindere la definizione del percorso dalla sua effettiva 
realizzazione grafica. Questo approccio può essere utile in diverse situazioni: si 
possono definire percorsi una sola volta, e poi far muovere un oggetto lungo quel 
percorso in modo animato, si può aggiornare la posizione di un oggetto a intervalli 
regolari utilizzando ''TRAVEL''.

@syntax = CREATE PATH( x0, y0 TO x1, y1 )
@syntax = CREATE PATH( x0, y0,  x1, y1 )

@example DIM p AS PATH
@example    p = CREATE PATH( 0, 0 TO 100, 100 )
@example    p = CREATE PATH( 0, 0, 100, 100 )

</usermanual> */

Variable * create_path( Environment * _environment, char * _x0, char * _y0, char * _x1, char * _y1 ) {

    deploy_begin( create_path );

        Variable * path = variable_define( _environment, "createpath__path", VT_PATH, 0 );
        path->bankReadOrWrite = 1;

        Variable * x0 = variable_define( _environment, "createpath__x0", VT_POSITION, 0 );
        Variable * y0 = variable_define( _environment, "createpath__y0", VT_POSITION, 0 );
        Variable * x1 = variable_define( _environment, "createpath__x1", VT_POSITION, 0 );
        Variable * y1 = variable_define( _environment, "createpath__y1", VT_POSITION, 0 );

        Variable * dx = variable_temporary( _environment, VT_POSITION, "(dx2)");
        Variable * dy = variable_temporary( _environment, VT_POSITION, "(dy2)");
        Variable * dx2 = variable_temporary( _environment, VT_POSITION, "(dx2)");
        Variable * dy2 = variable_temporary( _environment, VT_POSITION, "(dy2)");
        Variable * stepx = variable_temporary( _environment, VT_SBYTE, "(stepx)");
        Variable * stepy = variable_temporary( _environment, VT_SBYTE, "(stepy)");
        Variable * fraction = variable_temporary( _environment, VT_POSITION, "(fraction)" );

        variable_move( _environment, variable_sub( _environment, x1->name, x0->name )->name, dx->name );
            
        variable_move( _environment, variable_sub( _environment, y1->name, y0->name )->name, dy->name );

        if_then( _environment, variable_less_than_const( _environment, dy->name, 0, 0 )->name );
            variable_move( _environment, variable_complement_const( _environment, dy->name, 0 )->name, dy->name );
            variable_store( _environment, stepy->name, -1 );
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
            variable_store( _environment, stepy->name, 1 );
        end_if_then( _environment );

        if_then( _environment, variable_less_than_const( _environment, dx->name, 0, 0 )->name );
            variable_move( _environment, variable_complement_const( _environment, dx->name, 0 )->name, dx->name );
            variable_store( _environment, stepx->name, -1 );
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
            variable_store( _environment, stepx->name, 1 );
        end_if_then( _environment );

        variable_move_naked( _environment, dy->name, dy2->name );
        variable_move_naked( _environment, variable_sl_const( _environment, dy2->name, 1 )->name, dy2->name );
        variable_move_naked( _environment, dx->name, dx2->name );
        variable_move_naked( _environment, variable_sl_const( _environment, dx2->name, 1 )->name, dx2->name );;

        if_then( _environment, variable_greater_than( _environment, dx2->name, dy2->name, 0 )->name );
            variable_move( _environment, variable_sub( _environment, dy2->name, dx->name)->name, fraction->name);
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
            variable_move( _environment, variable_sub( _environment, dx2->name, dy->name)->name, fraction->name);
        end_if_then( _environment );

        cpu_move_16bit( _environment, x0->realName, path->realName );
        cpu_move_16bit( _environment, y0->realName, address_displacement( _environment, path->realName, "2" ) );
        cpu_move_16bit( _environment, dx2->realName, address_displacement( _environment, path->realName, "4" ) );
        cpu_move_16bit( _environment, dy2->realName, address_displacement( _environment, path->realName, "6" ) );
        cpu_move_8bit( _environment, stepx->realName, address_displacement( _environment, path->realName, "8" ) );
        cpu_move_8bit( _environment, stepy->realName, address_displacement( _environment, path->realName, "9" ) );
        cpu_move_16bit( _environment, fraction->realName, address_displacement( _environment, path->realName, "10" ) );
        cpu_move_16bit( _environment, x1->realName, address_displacement( _environment, path->realName, "12" ) );
        cpu_move_16bit( _environment, y1->realName, address_displacement( _environment, path->realName, "14" ) );

        cpu_return( _environment );

    deploy_end( create_path )

    Variable * x0p = variable_retrieve_or_define( _environment, _x0, VT_POSITION, 0 );
    Variable * y0p = variable_retrieve_or_define( _environment, _y0, VT_POSITION, 0 );
    Variable * x1p = variable_retrieve_or_define( _environment, _x1, VT_POSITION, 0 );
    Variable * y1p = variable_retrieve_or_define( _environment, _y1, VT_POSITION, 0 );

    Variable * path = variable_retrieve( _environment, "createpath__path" );

    Variable * x0 = variable_retrieve( _environment, "createpath__x0" );
    Variable * y0 = variable_retrieve( _environment, "createpath__y0" );
    Variable * x1 = variable_retrieve( _environment, "createpath__x1" );
    Variable * y1 = variable_retrieve( _environment, "createpath__y1" );
    
    variable_move( _environment, x0p->name, x0->name );
    variable_move( _environment, y0p->name, y0->name );
    variable_move( _environment, x1p->name, x1->name );
    variable_move( _environment, y1p->name, y1->name );

    cpu_call( _environment, "lib_create_path" );

    return path;

}

