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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 0, "BLACK" },        
        { 0x00, 0x00, 0xff, 1, "BLUE" },
        { 0x88, 0x00, 0x00, 2, "RED" },
        { 0xff, 0x00, 0xff, 3, "MAGENTA" },
        { 0x00, 0xcc, 0x00, 4, "GREEN" },
        { 0xaa, 0xff, 0xe6, 5, "CYAN" },
        { 0xee, 0xee, 0x77, 6, "YELLOW" },
        { 0xff, 0xff, 0xff, 7, "WHITE" }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __sc3000__

void sc3000_inkey( Environment * _environment, char * _pressed, char * _key ) {

  
}

void sc3000_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

}

void sc3000_scanshift( Environment * _environment, char * _shifts ) {

}

void sc3000_keyshift( Environment * _environment, char * _shifts ) {

}

void sc3000_clear_key( Environment * _environment ) {

}


void sc3000_irq_at( Environment * _environment, char * _label ) {

    // Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    outline0("DI" );
    cpu_set_callback( _environment, "IRQVECTOR", _label );
    outline0("EI" );
    
}

void sc3000_follow_irq( Environment * _environment ) {

    // Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    // outline1("LD HL, (%s)", irq->realName );
    // outline0("JP (HL)" );
    
    outline0("EI" );
    outline0("RET" );

}
#endif