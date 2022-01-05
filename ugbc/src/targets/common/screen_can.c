/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>CAN SCREEN [mode]</b>
 * 
 * This function outputs assembly code to check if the given mode is available.
 * 
 * @param _environment Current calling environment
 * @param _mode Mode to check
 */
/* <usermanual>
@keyword CAN SCREEN

@english
This instruction allows you to check if a certain screen mode is available or
not. If that mode is available, the instruction will return the value ''TRUE''. 
Otherwise, the statement will return ''FALSE''.

@italian
Questa istruzione consente di verificare se una determinata modalità dello 
schermo è disponibile o meno. Se lo è, l'istruzione restituirà il valore ''TRUE''.
In caso contrario, l'istruzione restituirà ''FALSE''.

@syntax = CAN SCREEN [mode]

@example IF CAN SCREEN 2 THEN : PRINT "mode 2 is available": ENDIF

@usedInExample screens_cls_03.bas

@target all
 </usermanual> */
Variable * screen_can( Environment * _environment, int _mode ) {

    ScreenMode * mode = find_screen_mode_by_id( _environment, _mode );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(can screen)" );
    
    if ( mode ) {
        cpu_store_8bit( _environment, result->realName, 0xff );
    } else {
        cpu_store_8bit( _environment, result->realName, 0x0 );
    }

    return result;
    
}

