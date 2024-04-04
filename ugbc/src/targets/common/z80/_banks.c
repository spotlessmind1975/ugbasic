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

#include "../../../ugbc.h"

#if defined(__c128z__) || defined(__msx1__) || defined(__coleco__)

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

void banks_generate( Environment * _environment ) {
    
#if defined(__msx1__) || defined(__coleco__)
    outhead0("section data_user");
#endif

    int anyExpansionBank = 0;
    Bank * bank = _environment->expansionBanks;
    while( bank ) {
        outhead1("%s:", bank->name );
        if ( bank->type == BT_EXPANSION && bank->name && ( bank->space != bank->remains ) ) {
            int size = bank->space - bank->remains;
            if ( bank->data ) {
                out0("    db ");
                int i=0;
                for (i=0; i<(size-1); ++i ) {
                    out1("$%2.2x,", (unsigned char)( bank->data[i] & 0xff ) );
                }
                outline1("$%2.2x", (unsigned char)( bank->data[(size-1)] & 0xff ) );
            }
            anyExpansionBank = 1;
        }
        bank = bank->next;
    }

#if defined(__msx1__)
    outhead0("section code_user");
#endif

    if ( anyExpansionBank ) {

        int values[MAX_TEMPORARY_STORAGE];
        char * address[MAX_TEMPORARY_STORAGE];

        Bank * actual = _environment->expansionBanks;
        int count = 0;
        while( actual ) {
            values[count] = actual->id;
            address[count] = strdup( actual->name );
            actual = actual->next;
            ++count;
        }

        cpu_address_table_build( _environment, "EXPBANKS", values, address, (count-1) );

        cpu_address_table_lookup( _environment, "EXPBANKS", count );

    }
    
}

#endif