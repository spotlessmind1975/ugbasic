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

#if defined(__atari__) || defined(__atarixl__) || defined(__c64__) || defined(__c64reu__) || defined(__c128__) || defined(__plus4__) || defined(__vic20__)

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

void setup_embedded( Environment * _environment ) {

    _environment->embedded.cpu_fill_blocks = 1;
    _environment->embedded.cpu_fill = 1;
    _environment->embedded.cpu_math_div2_const_8bit = 1;
    _environment->embedded.cpu_math_mul_8bit_to_16bit = 1;
    _environment->embedded.cpu_math_div_8bit_to_8bit = 1;
    _environment->embedded.cpu_math_div2_const_8bit = 1;
    _environment->embedded.cpu_math_mul2_const_8bit = 1;
    _environment->embedded.cpu_math_mul_16bit_to_32bit = 1;
    _environment->embedded.cpu_math_div_16bit_to_16bit = 1;
    _environment->embedded.cpu_math_div_32bit_to_16bit = 1;
    _environment->embedded.cpu_random = 1;
    _environment->embedded.cpu_mem_move = 1;
    _environment->embedded.cpu_uppercase = 1;
    _environment->embedded.cpu_lowercase = 1;
    _environment->embedded.cpu_hex_to_string = 1;
    _environment->embedded.cpu_msc1_uncompress = 1;
    _environment->embedded.cpu_string_sub = 1;
    _environment->embedded.cpu_convert_string_into_16bit = 1;
    _environment->embedded.cpu_bit_inplace = 1;
    _environment->embedded.cpu_bit_check_extended = 1;
    _environment->embedded.cpu_flip = 1;
    _environment->embedded.cpu_swap_8bit = 0; // 8 bit inline
    _environment->embedded.cpu_swap_16bit = 1; // 16/32 bit code shared
    _environment->embedded.cpu_swap_32bit = 1; // 16/32 bit code shared
    
}


#endif