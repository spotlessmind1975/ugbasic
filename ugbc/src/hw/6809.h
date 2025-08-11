#ifndef __UGBC_CPU6809__
#define __UGBC_CPU6809__

#define     cpu6809     1

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

#include "../cpu.h"

#define VT_FLOAT_BITWIDTH( p ) \
        ( \
            VT_BW_40BIT( p, FT_FAST ) + \
            VT_BW_40BIT( p, FT_SINGLE ) \
        )

#define VT_FLOAT_NORMALIZED_BITWIDTH( p ) \
        ( \
            VT_BW_64BIT( p, FT_FAST ) + \
            VT_BW_64BIT( p, FT_SINGLE ) \
        )

#define VT_FLOAT_NORMALIZED_POW2_WIDTH( p ) \
        ( \
            VT_POW2_3( p, FT_FAST ) + \
            VT_POW2_3( p, FT_SINGLE ) \
        )

#define     CPU_BIG_ENDIAN      1
#define     REGISTER_BASE           0x1000
#define     IS_REGISTER(x)          ((x & REGISTER_BASE) == REGISTER_BASE)

typedef enum _CPU6809Register {

    REGISTER_NONE   =   REGISTER_BASE | 0,
    REGISTER_A      =   REGISTER_BASE | 1,
    REGISTER_B      =   REGISTER_BASE | 2,
    REGISTER_CC     =   REGISTER_BASE | 3,
    REGISTER_DP     =   REGISTER_BASE | 4,
    REGISTER_X      =   REGISTER_BASE | 5,
    REGISTER_Y      =   REGISTER_BASE | 6,
    REGISTER_U      =   REGISTER_BASE | 7,
    REGISTER_S      =   REGISTER_BASE | 8,
    REGISTER_PC     =   REGISTER_BASE | 9,
    REGISTER_D      =   REGISTER_BASE | 10

} CPU6809Register;

typedef enum _CPU6809Stack {

    STACK_NONE      =   0,
    STACK_BYTE      =   1,
    STACK_WORD      =   2,
    STACK_DWORD     =   3

} CPU6809Stack;

void vars_emit_byte( Environment * _environment, char * _name, int _value );
void vars_emit_word( Environment * _environment, char * _name, int _value );
void vars_emit_dword( Environment * _environment, char * _name, int _value );

#endif