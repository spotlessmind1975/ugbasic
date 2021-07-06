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
    cfgline0("STARTADDRESS: default = $0801;");
    cfghead0("}");
    cfghead0("SYMBOLS {");
    cfgline0("__LOADADDR__: type = import;");
    cfghead0("}");
    cfghead0("MEMORY {");
    cfgline0("ZP:       file = \"\", start = $0002,  size = $00FE,      define = yes;");
    cfgline0("LOADADDR: file = %O, start = %S - 2, size = $0002;");
    cfgline0("MAIN:     file = %O, start = %S,     size = $D000 - %S;");
    cfghead0("}");
    cfghead0("SEGMENTS {");
    cfgline0("ZEROPAGE: load = ZP,       type = zp,  optional = yes;");
    cfgline0("LOADADDR: load = LOADADDR, type = ro;");
    cfgline0("EXEHDR:   load = MAIN,     type = ro,  optional = yes;");
    cfgline0("CODE:     load = MAIN,     type = rw;");
    cfgline0("RODATA:   load = MAIN,     type = ro,  optional = yes;");
    cfgline0("DATA:     load = MAIN,     type = rw,  optional = yes;");
    cfgline0("BSS:      load = MAIN,     type = bss, optional = yes, define = yes;");
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