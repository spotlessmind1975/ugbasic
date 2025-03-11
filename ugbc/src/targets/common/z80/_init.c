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

#if defined(__c128z__) || defined(__msx1__) || defined(__coleco__) || defined(__cpc__) || defined(__sc3000__) || defined(__sg1000__) || defined(__vg5000__) || defined(__zx__) || defined(__vtech__)

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

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
    _environment->embedded.cpu_string_sub = 1;
    _environment->embedded.cpu_less_than_8bit = 1;
    _environment->embedded.cpu_less_than_16bit = 1;
    _environment->embedded.cpu_less_than_32bit = 1;
    _environment->embedded.cpu_math_div2_const_16bit = 1;
    _environment->embedded.cpu_msc1_uncompress = 1;
    _environment->embedded.cpu_compare_16bit = 1;
    _environment->embedded.cpu_compare_32bit = 1;
    _environment->embedded.cpu_bit_inplace = 1;
    _environment->embedded.cpu_bit_check_extended = 1;
    _environment->embedded.cpu_flip = 1;
    _environment->embedded.cpu_combine_nibbles = 1;
    _environment->embedded.cpu_swap_8bit = 1; // useless, cpu_swap_8bit shares code
    _environment->embedded.cpu_swap_16bit = 1; // useless, cpu_swap_8bit shares code
    _environment->embedded.cpu_swap_32bit = 1; // useless, cpu_swap_8bit shares code
    
}

#endif