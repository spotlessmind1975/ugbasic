#ifndef __UGBC_8086__
#define __UGBC_8086__

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

#include "cpu.h"

#define VT_FLOAT_BITWIDTH( p ) \
        ( \
            VT_BW_24BIT( p, FT_FAST ) + \
            VT_BW_32BIT( p, FT_SINGLE ) \
        )

#define VT_FLOAT_NORMALIZED_BITWIDTH( p ) \
        ( \
            VT_BW_32BIT( p, FT_FAST ) + \
            VT_BW_32BIT( p, FT_SINGLE ) \
        )

#define VT_FLOAT_NORMALIZED_POW2_WIDTH( p ) \
        ( \
            VT_POW2_2( p, FT_FAST ) + \
            VT_POW2_2( p, FT_SINGLE ) \
        )

#define     CPU_LITTLE_ENDIAN      1
#define     REGISTER_BASE           0x1000
#define     IS_REGISTER(x)          ((x & REGISTER_BASE) == REGISTER_BASE)

typedef enum _Z80Register {

    REGISTER_NONE   =   REGISTER_BASE | 0,

    REGISTER_A      =   REGISTER_BASE | 1,
    REGISTER_B      =   REGISTER_BASE | 2,
    REGISTER_C      =   REGISTER_BASE | 3,
    REGISTER_D      =   REGISTER_BASE | 4,
    REGISTER_E      =   REGISTER_BASE | 5,
    REGISTER_H      =   REGISTER_BASE | 6, 
    REGISTER_L      =   REGISTER_BASE | 7, 
    REGISTER_F      =   REGISTER_BASE | 8, 
    REGISTER_I      =   REGISTER_BASE | 9, 
    REGISTER_R      =   REGISTER_BASE | 10,
    REGISTER_SP     =   REGISTER_BASE | 11,
    REGISTER_PC     =   REGISTER_BASE | 12,
    REGISTER_IX     =   REGISTER_BASE | 13,
    REGISTER_IY     =   REGISTER_BASE | 14,
    REGISTER_AF     =   REGISTER_BASE | 15,
    REGISTER_BC     =   REGISTER_BASE | 16,
    REGISTER_DE     =   REGISTER_BASE | 17,
    REGISTER_HL     =   REGISTER_BASE | 18,
    REGISTER_IXL    =   REGISTER_BASE | 19,
    REGISTER_IXH    =   REGISTER_BASE | 20,
    REGISTER_IYL    =   REGISTER_BASE | 21,
    REGISTER_IYH    =   REGISTER_BASE | 22,
    REGISTER_HLA    =   REGISTER_BASE | 23,

    REGISTER_CARRY  =   REGISTER_BASE | 24,
    REGISTER_ZERO  =   REGISTER_BASE | 25

} Z80Register;

typedef enum _Z80Stack {

    STACK_NONE      =   0,
    STACK_BYTE      =   1,
    STACK_WORD      =   2,
    STACK_DWORD     =   3

} Z80Stack;

void vars_emit_byte( Environment * _environment, char * _name, int _value );
void vars_emit_word( Environment * _environment, char * _name, int _value );
void vars_emit_dword( Environment * _environment, char * _name, int _value );

#endif