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

void file_write( Environment * _environment, char * _number, char * _address, char * _size ) {

    Variable * number = variable_retrieve_or_define( _environment, _number, VT_BYTE, 0 );
    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_BYTE, 0 );

    deploy( file_vars, src_hw_c128_file_vars_asm );
    deploy( file_write, src_hw_c128_file_write_asm );

    outline1("LDA %s", number->realName );
    outline0("STA FILENUM" );
    outline1("LDA %s", address->realName );
    outline0("STA FILEPTR" );    
    outline1("LDA %s", address_displacement( _environment, address->realName, "1" ) );
    outline0("STA FILEPTR+1" );    
    outline1("LDA %s", size->realName );
    outline0("STA FILESIZE" );    
    outline0("JSR FILEWRITEBUFFER" );

}


