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

void remember( Environment * _environment ) {
    
    Variable * xcursys = variable_retrieve( _environment, "XCURSYS" );
    Variable * ycursys = variable_retrieve( _environment, "YCURSYS" );

    MAKE_LABEL
    
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(consoles)" );
    cpu_addressof_16bit( _environment, "CONSOLES", address->realName  );

    Variable * actualNumber = variable_temporary( _environment, VT_BYTE, 0 );
    cpu_addressof_16bit( _environment, "CONSOLES", address->realName  );
    cpu_move_8bit( _environment, "CONSOLEID", actualNumber->realName );
    cpu_math_mul2_const_8bit( _environment, actualNumber->realName, 1, 0 );
    cpu_math_add_16bit_with_8bit( _environment, address->realName, actualNumber->realName, address->realName );

    cpu_move_8bit_indirect2( _environment, address->realName, xcursys->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect2( _environment, address->realName, ycursys->realName );

}
