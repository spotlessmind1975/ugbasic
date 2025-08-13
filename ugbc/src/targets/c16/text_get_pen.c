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
 * @brief Emit code for the <strong>PEN$(...)</strong>
 * 
 * @param _environment 
 * @param _color 
 * @return Variable* 
 */
/* <usermanual>
@keyword PEN (function)

@english

The ''PEN$'' command create a special control sequence (string) that define the foreground color of
the screen. This means that, whenever the string is printed on the screen, the pre-set pen colour 
is automatically assigned  to it. The format of the string returned by ''PEN$'' is not specific 
for the target.  The parameter ''color'' is represented  by a value in the available colors, 
from 0 to maximum (''PEN COLORS''). 

@italian

Il comando ''PEN$'' crea una sequenza di controllo speciale (stringa) che definisce il colore di
sfondo dello schermo. Ciò significa che, ogni volta che la stringa viene stampata sullo schermo, 
le viene automaticamente assegnato il colore della carta preimpostato. Il formato della stringa 
restituita da ''PEN$'' non è specifico per il target. Il parametro ''color'' è rappresentato 
da un valore nei colori disponibili, da 0 al massimo (''PEN COLORS'').

@syntax = PEN$(expression)

@example PRINT PEN$(RED)

@UsedInExample texts_options_02.bas

@seeAlso PEN (instruction)
@seeAlso PAPER (function)

@target all
</usermanual> */
Variable * get_pen( Environment * _environment, char * _color ) {
    
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_WHITE );

    Variable * result = variable_temporary( _environment, VT_DSTRING, 0 );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, 0 );
    Variable * size = variable_temporary( _environment, VT_BYTE, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x1 " );

    variable_store_string(_environment, result->name, resultString );

    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_move_8bit_indirect_with_offset(_environment, color->realName, address->realName, 1 );
        
    return result;

}
