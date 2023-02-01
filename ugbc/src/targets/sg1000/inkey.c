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

extern char DATATYPE_AS_STRING[][16];

Variable * inkey( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of INKEY$)");
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of temporary string)");
    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");
    Variable * key = variable_temporary( _environment, VT_CHAR, "(key pressed)");

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, " " );

    variable_store_string(_environment, result->name, resultString );

    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, pressed->realName );

    MAKE_LABEL

    char noKeyPressedLabel[MAX_TEMPORARY_STORAGE]; sprintf(noKeyPressedLabel, "%snokeyPressed", label );
    char finishedLabel[MAX_TEMPORARY_STORAGE]; sprintf(finishedLabel, "%sfinished", label );

    sg1000_inkey( _environment, pressed->realName, key->realName );

    cpu_bveq( _environment, pressed->realName, noKeyPressedLabel );

    cpu_move_8bit_indirect(_environment, key->realName, address->realName );
    cpu_dsresize_size(_environment, result->realName, 1 );

    cpu_jump( _environment, finishedLabel );

    cpu_label( _environment, noKeyPressedLabel );

    cpu_dsresize_size(_environment, result->realName, 0 );

    cpu_label( _environment, finishedLabel );
    
    return result;

}
