/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>IMAGE LOAD(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */
/* <usermanual>
@keyword MOB

@english
The ''MOB'' command allows you to define a movable object. In order to be used, 
you must have loaded the image. The simplest syntax provides, in fact, the 
definition of the object. It is possible to indicate a starting position 
for the object, different from (0,0) and whether the object is visible or not. 
Additional syntaxes are available for such situations.

@italian
Il comando ''MOB'' permette di definire un oggetto mobile (Movable OBject). 
Per poter essere utilizzato è necessario aver caricato l'immagine da utilizzare. 
La sintassi più semplice prevede, appunto, la definizione dell'oggetto. 
E' possibile indicare una posizione di partenza per l'oggetto, diversa da (0,0)
e che l'oggetto sia visibile o meno. Per tali situazioni sono disponibili
sintassi aggiuntive.

@syntax MOB [index],[image] {VISIBILE|HIDDEN}
@syntax MOB [index],[image] AT {[x]},{[y]} {VISIBILE|HIDDEN}

@example starship = 1: MOB starship, IMAGE LOAD("starship.png")
@example MOB 2, alien AT 100,100 HIDDEN

@usedInExample mobs_example_01.bas

@target all
</usermanual> */
Variable * mob_init( Environment * _environment, char * _image, char * _x, char * _y ) {

    Variable * index = variable_temporary( _environment, VT_MOB, "(mob index)" );
    Variable * image = variable_retrieve( _environment, _image );
    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );

    if ( _x ) {
        Variable * ox = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
        variable_move_naked( _environment, ox->name, x->name );
    } else {
        variable_store( _environment, x->name, 0 );
    }

    if ( _y ) {
        Variable * oy = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
        variable_move_naked( _environment, oy->name, y->name );
    } else {
        variable_store( _environment, y->name, 0 );
    }    

    cpu_inc( _environment, "MOBCOUNT" );
    cpu_mobcount( _environment, index->realName );
    cpu_mobinit( _environment, index->realName, x->realName, y->realName, image->realName );

    return index;

}
