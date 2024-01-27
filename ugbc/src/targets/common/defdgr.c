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
 * @brief Emit code for <strong>DATA</strong> instruction (numeric values)
 * 
 * @param _environment Current calling environment
 * @param _value Numeric value to store
 */
 /* <usermanual>
@keyword DEFDGR

@english
This command allows you to customize a single character of those used for rendering texts
in graphic mode. Customization happens at runtime. If you want to customize the font at 
compile time, refer to the ''LOAD FONT'' command.

@italian
Questo comando permette di personalizzare un singolo carattere di quelli utilizzati per 
il rendering dei testi in modalità grafica. La personalizzazione avviene a runtime. Se
si vuole personalizzare il font al momento della compilazione, far riferimento al comando 
''LOAD FONT''.

@syntax DEFDGR[$](x) = b0, b1, ... , b7

@example DEFDGR(0) = $ff, $ff, $ff, $ff, $00, $00, $00, $00
@example DEFDGR$(1) = $ff, $ff, $ff, $ff, $00, $00, $00, $00

@usedInExample font_example_02.bas

@target all
@verified
</usermanual> */
void defdgr_vars( Environment * _environment, char * _character, char * _b0, char * _b1, char * _b2, char * _b3, char * _b4, char * _b5, char * _b6, char * _b7 ) {

    if ( _environment->descriptors ) {

        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)");

        Variable * offset = variable_retrieve_or_define( _environment, _character, VT_WORD, 0 );
        variable_mul2_const( _environment, offset->name, 3 );
        Variable * b0 = variable_retrieve_or_define( _environment, _b0, VT_BYTE, 0 );
        Variable * b1 = variable_retrieve_or_define( _environment, _b1, VT_BYTE, 0 );
        Variable * b2 = variable_retrieve_or_define( _environment, _b2, VT_BYTE, 0 );
        Variable * b3 = variable_retrieve_or_define( _environment, _b3, VT_BYTE, 0 );
        Variable * b4 = variable_retrieve_or_define( _environment, _b4, VT_BYTE, 0 );
        Variable * b5 = variable_retrieve_or_define( _environment, _b5, VT_BYTE, 0 );
        Variable * b6 = variable_retrieve_or_define( _environment, _b6, VT_BYTE, 0 );
        Variable * b7 = variable_retrieve_or_define( _environment, _b7, VT_BYTE, 0 );

        cpu_addressof_16bit( _environment, "UDCCHAR", address->realName );
        cpu_math_add_16bit( _environment, address->realName, offset->realName, address->realName );
        cpu_move_8bit_indirect_with_offset( _environment, b0->realName, address->realName, 0 );    
        cpu_move_8bit_indirect_with_offset( _environment, b1->realName, address->realName, 1 );    
        cpu_move_8bit_indirect_with_offset( _environment, b2->realName, address->realName, 2 );    
        cpu_move_8bit_indirect_with_offset( _environment, b3->realName, address->realName, 3 );    
        cpu_move_8bit_indirect_with_offset( _environment, b4->realName, address->realName, 4);    
        cpu_move_8bit_indirect_with_offset( _environment, b5->realName, address->realName, 5 );    
        cpu_move_8bit_indirect_with_offset( _environment, b6->realName, address->realName, 6);    
        cpu_move_8bit_indirect_with_offset( _environment, b7->realName, address->realName, 7 );    

    }

}
