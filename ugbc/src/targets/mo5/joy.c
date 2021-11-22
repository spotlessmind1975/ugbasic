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

Variable * joy( Environment * _environment, char * _port ) {
    MAKE_LABEL

    Variable * port = variable_retrieve_or_define( _environment, _port, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of JOY)" );
	
	outline0("LDA $A7CC");
    outline1("LDB %s", port->realName );
    outline1("BEQ %sjoy0", label );
	outline0("LDB #$40");
	outline0("LSRA");
	outline0("LSRA");
	outline0("LSRA");
	outline0("LSRA");
    outhead1("%sjoy0", label );
	outline0("ANDA #$0F");
	outline0("ADDB #$40");
	outline0("ANDB $A7CD");
    outline1("BEQ %sact0", label );
	outline0("ADDA #$10");
	outhead1("%sact0", label );
	outline0("EORA #$1F");
	outline1("STA %s", result->realName );

    return result;

}