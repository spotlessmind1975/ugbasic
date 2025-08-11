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
        { 0x00, 0x00, 0x00, 0xff,  0, "BLACK" },        
        { 0x00, 0x00, 0xff, 0xff,  1, "BLUE" },
        { 0x88, 0x00, 0x00, 0xff,  2, "RED" },
        { 0xff, 0x00, 0xff, 0xff,  3, "MAGENTA" },
        { 0x00, 0xcc, 0x00, 0xff,  4, "GREEN" },
        { 0xaa, 0xff, 0xe6, 0xff,  5, "CYAN" },
        { 0xee, 0xee, 0x77, 0xff,  6, "YELLOW" },
        { 0xff, 0xff, 0xff, 0xff,  7, "WHITE" }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __pccga__

void pccga_inkey( Environment * _environment, char * _pressed, char * _key ) {

}

void pccga_wait_key_or_fire( Environment * _environment, int _port, int _release ) {
   
}

void pccga_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {
   
}

void pccga_wait_fire( Environment * _environment, int _port, int _release ) {

}

void pccga_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

}

void pccga_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

}

void pccga_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

}

void pccga_scanshift( Environment * _environment, char * _shifts ) {

}

void pccga_keyshift( Environment * _environment, char * _shifts ) {

}

void pccga_clear_key( Environment * _environment ) {

}

void pccga_joy_vars( Environment * _environment, char * _port, char * _value ) {

}

void pccga_joy( Environment * _environment, int _port, char * _value ) {

}

void pccga_sys_call( Environment * _environment, int _destination ) {

}

void pccga_timer_set_status_on( Environment * _environment, char * _timer ) {
    
}

void pccga_timer_set_status_off( Environment * _environment, char * _timer ) {

}

void pccga_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

}

void pccga_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

}

void pccga_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

}

#endif