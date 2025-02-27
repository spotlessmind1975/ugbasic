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

#include "../../../ugbc.h"
 
extern char DATATYPE_AS_STRING[][16];

/* <usermanual>
@keyword OPEN PORT

@english

The ''OPEN PORT'' instruction allows you to open a port previously created with the 
''CREATE PORT'' command. This command accepts, as a parameter, the string with the 
unique and printable identification code of the port, equivalent to an 8-digit hexadecimal 
code. The result of the call will be the same identifier, which can be used for other 
instructions. The instruction will issue an error if the port is unknown. In case the 
provided port is an empty string, this command will behave like ''CREATE PORT''.

@italian

L'istruzione ''OPEN PORT'' permette di aprire una porta creata in precedenza con il comando
''CREATE PORT''. Questo comando accetta, come parametro, la stringa con il codice 
identificativo univoco e stampabile della porta, equivalente a un codice di 8 cifre esadecimali.
Il risultato della chiamata sarà il medesimo identificativo, utilizzabile per le altre istruzioni. 
L'istruzione emetterà un errore nel caso in cui la porta sia sconosciuta. Nel caso in cui la 
porta fornita sia una stringa vuota, questo comando si comporterà come ''CREATE PORT''.

@syntax [DOJO] OPEN PORT( id )

@example handle = OPEN PORT( "ce420000" )

@alias DOJO OPEN PORT

@seeAlso CREATE PORT

@target atari, coco
</usermanual> */

/* <usermanual>
@keyword DOJO OPEN PORT

@english

@italian

@alias OPEN PORT

@target atari, coco
</usermanual> */

Variable * dojo_open_port( Environment * _environment, char * _port ) {

    MAKE_LABEL

    Variable * port = variable_retrieve( _environment, _port );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );

    switch( port->type ) {
        case VT_STRING: {            
            cpu_move_8bit( _environment, port->realName, size->realName );
            cpu_addressof_16bit( _environment, port->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        }
        case VT_DSTRING: {            
            cpu_dsdescriptor( _environment, port->realName, address->realName, size->realName );
            break;
        }
        default:
            DOJO_OPEN_PORT_STRING_REQUIRED( _port, DATATYPE_AS_STRING[port->type]);
            break;
    }            
    
    Variable * dojoHandle = variable_temporary( _environment, VT_DOJOKA, "(dojo handle)" );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(unique id)" );

    dojo_begin( _environment );
    dojo_put_request( _environment, DOJO_CMD_OPEN_PORT, NULL, NULL, address->realName, size->realName, result->realName );
    cpu_compare_and_branch_8bit_const( _environment, result->realName, 0, label, 0 );
    dojo_partial( _environment );
    dojo_get_responsed( _environment, result->realName, dojoHandle->realName, NULL );

    cpu_label( _environment, label );
    dojo_end( _environment );

    cpu_move_8bit( _environment, result->realName, "DOJOERROR" );

    return dojoHandle;

}
