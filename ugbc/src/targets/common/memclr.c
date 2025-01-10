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

/* <usermanual>
@keyword MEMCLR

@english

The ''MEMCLR'' instruction writes all ''num'' memory locations from the 
address ''adr'' with the value 0 (zero) or optionally with any 
other byte value ''value''.  The number zero for ''num'' is ignored (nothing 
is written to the memory, but no error appears either).

@italian

L'istruzione ''MEMCLR'' scrive in tutte le ''num'' posizioni di memoria dall'indirizzo 
''adr'' con il valore 0 (zero) o facoltativamente con qualsiasi altro valore 
di byte ''value''. Il numero zero per ''num'' viene ignorato (non viene scritto nulla 
nella memoria, ma non viene visualizzato alcun errore).

@syntax MEMCLR address, num[, value]

@example MEMCLR &Hc000, 128

</usermanual> */

void memclr( Environment * _environment, char * _address, char * _size, char * _value ) {

    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_WORD, 0 );

    if ( _value ) {
        Variable * value = variable_retrieve_or_define( _environment, _value, VT_BYTE, 0 );
        cpu_fill( _environment, address->realName, size->realName, 16, value->realName );
    } else {
        Variable * value = variable_temporary( _environment, VT_BYTE, "(value)" );
        cpu_store_8bit( _environment, value->realName, 0 );
        cpu_fill( _environment, address->realName, size->realName, 16, value->realName );
    }

}
