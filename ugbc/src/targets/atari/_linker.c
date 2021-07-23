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

/**
 * @brief Emit tail of linker's configuration file lines
 * 
 * This function emit the header of linker's configuration file.
 * 
 * @param _environment Current calling environment
 */
void linker_setup( Environment * _environment ) {
    cfghead0("FEATURES {");
    cfgline0("STARTADDRESS: default = $2000;");
    cfghead0("}");

    cfghead0("SYMBOLS {");
    cfghead0("}");

    cfghead0("MEMORY {");
    cfgline0("ZP:      	start = $0096, size = $007E, type = rw, define = yes;");
    cfgline0("HEADER:  	start = $0000, size = $0006, file = %O;");
    cfgline0("MAIN:     start = %S,    size = $8000, file = %O;");
    cfgline0("TRAILER:	start = $0000, size = $0006, file = %O;");
    cfghead0("}");

    cfghead0("FEATURES {");
    cfgline0("CONDES: segment = INIT,");
    cfgline0("   type = constructor,");
    cfgline0("   label = __CONSTRUCTOR_TABLE__,");
    cfgline0("   count = __CONSTRUCTOR_COUNT__;");
    cfgline0("CONDES: segment = RODATA,");
    cfgline0("   type = destructor,");
	cfgline0("   label = __DESTRUCTOR_TABLE__,");
	cfgline0("   count = __DESTRUCTOR_COUNT__;");
    cfgline0("CONDES: type = interruptor,");
    cfgline0("   segment = RODATA,");
	cfgline0("   label = __INTERRUPTOR_TABLE__,");
    cfgline0("count = __INTERRUPTOR_COUNT__;");
    cfghead0("}");

    cfghead0("SEGMENTS {");
    cfgline0("EXEHDR:   load = HEADER,  type = ro;");
    cfgline0("STARTUP:  load = MAIN,     type = ro, define = yes, optional = yes;");
    cfgline0("LOWCODE:  load = MAIN,     type = ro, define = yes, optional = yes;");
    cfgline0("INIT:     load = MAIN,     type = ro,               optional = yes;");
    cfgline0("CODE:     load = MAIN,     type = ro, define = yes;");
    cfgline0("RODATA:   load = MAIN,     type = ro;");
    cfgline0("DATA:     load = MAIN,     type = rw;");
    cfgline0("ZPSAVE:   load = MAIN,     type = bss, define = yes, optional = yes;");
    cfgline0("BSS:      load = MAIN,     type = bss, define = yes;");
    cfgline0("HEAP:     load = MAIN,     type = bss, optional = yes; # must sit just below stack");
    cfgline0("ZEROPAGE: load = ZP,      type = zp;");
    cfgline0("AUTOSTRT: load = TRAILER,	type = ro;");
 
}


/**
 * @brief Emit tail of linker's configuration file lines
 * 
 * This function emit the tail of linker's configuration file.
 * 
 * @param _environment Current calling environment
 */
void linker_cleanup( Environment * _environment ) {
 
    cfghead0("}");
    
}