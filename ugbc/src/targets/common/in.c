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
 * @brief Emit ASM code for <b>IN</b>
 * 
 * @param _environment Current calling environment
 * @param _port Expression with the port to receive input from
 * @return _value Valure read
 */
/* <usermanual>
@keyword IN

@english
This command allows you to receive a byte from an I/O port, provided that the underlying hardware 
allows it. If it wasn't allowed, the statement will do nothing.

@italian
Questo comando permette di ricevere un byte a una porta di I/O, sempre che ciò sia consentito 
dall'hardware sottostante. Se non fosse consentito, l'istruzione non farà nulla. 

@syntax = IN( [port] )

@example x = IN( &HBC00 )

@target c128z
@target coleco
@target cpc
@target msx1
@target sc3000
@target sg1000
@target vg5000
@target zx
</usermanual> */

Variable * in_var( Environment * _environment, char * _port ) {

    Variable * port = variable_retrieve_or_define( _environment, _port, VT_WORD, 0 );

    Variable * value = variable_temporary( _environment, VT_BYTE, "(value)" );

    cpu_in( _environment, port->realName, value->realName );

    return value;
    
}
