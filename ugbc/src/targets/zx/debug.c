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

extern char DATATYPE_AS_STRING[][16];

Variable * vt_to_buffer( Environment * _environment, char * _input ) {

    Variable * input = variable_retrieve( _environment, _input );

    Variable * b2dinv = variable_temporary( _environment, VT_BUFFER, "(64-bit input value)");
    variable_resize_buffer( _environment, b2dinv->name, 8 );
    Variable * b2dbuf = variable_temporary( _environment, VT_BUFFER, "(up to 20 decimal digits + terminating null)");
    variable_resize_buffer( _environment, b2dbuf->name, 21 );

    MAKE_LABEL

    switch( VT_BITWIDTH( input->type ) ) {
        case 8:
            outline1("LD A,(%s)", input->realName);
            outline0("LD H,0");
            outline0("LD L,A");
            outline0("LD E,0");
            outline0("LD D,0");
            outline0("LD BC,0");
            outline0("LD IX,0");
            break;
        case 16:
            outline1("LD HL,(%s)", input->realName);
            outline0("LD E,0");
            outline0("LD D,0");
            outline0("LD BC,0");
            outline0("LD IX,0");
            break;
        case 32:
            outline1("LD HL,(%s)", input->realName);
            outline1("LD DE,(%s+2)", input->realName);
            outline0("LD BC,0");
            outline0("LD IX,0");
            break;
        default:
            CRITICAL_DEBUG_UNSUPPORTED( _input, DATATYPE_AS_STRING[input->type]);
    }

    outline1("LD (%s),HL", b2dinv->realName);
    outline1("LD (%s+2),DE", b2dinv->realName);
    outline1("LD (%s+4),BC", b2dinv->realName);
    outline1("LD (%s+6),IX", b2dinv->realName);
    outline1("LD HL,%s", b2dbuf->realName);
    outline1("LD DE,%s+1", b2dbuf->realName);
    outline0("LD (HL), 32" );
    outhead1("%sB2DFILC: EQU $-1", label );
    outline0("LD BC,18" );
    outline0("LDIR");
    outhead1("LD (%s+20),BC", b2dbuf->realName);
    outline0("LD E,1");
    outline1("LD HL,%s+8", b2dinv->realName);
    outline0("LD BC,$0909");
    outline0("XOR A");
    outhead1("%sB2DSKP0:", label );
    outline0("DEC B");
    outline1("JR Z,%sB2DSIZ", label );
    outline0("DEC HL");
    outline0("OR (HL)");
    outline1("JR Z,%sB2DSKP0", label);
    outhead1("%sB2DFND1:", label );
    outline0("DEC C");
    outline0("RLA");
    outline1("JR NC,%sB2DFND1", label );
    outline0("RRA");
    outline0("LD D,A");
    outhead1("%sB2DLUS2:", label );
    outline0("PUSH HL");
    outline0("PUSH BC");
    outhead1("%sB2DLUS1:", label );
    outline1("LD HL,%s+20", b2dbuf->realName);
    outline0("LD B,E" );
    outline0("RL D" );
    outhead1("%sB2DLUS0:", label );
    outline0("LD A,(HL)");
    outline0("ADC A,A" );
    outline0("DAA");
    outline0("LD (HL),A");
    outline0("DEC HL");
    outline1("DJNZ %sB2DLUS0", label);
    outline1("JR NC,%sB2DNXT", label);
    outline0("INC E");
    outline0("LD (HL),1");
    outhead1("%sB2DNXT:", label );
    outline0("DEC C");
    outline1("JR NZ,%sB2DLUS1", label );
    outline0("POP BC" );
    outline0("LD C,8" );
    outline0("POP HL" );
    outline0("DEC HL" );
    outline0("LD D,(HL)" );
    outline1("DJNZ %sB2DLUS2", label );
    outhead1("%sB2DSIZ:", label );
    outline1("LD HL,%s+21", b2dbuf->realName );
    outline0("LD C,E");
    outline0("OR A");
    outline0("SBC HL,BC");
    outline0("LD D,H");
    outline0("LD E,L");
    outline0("SBC HL,BC");
    outline0("EX DE,HL");
    outline0("LD B,C");
    outline0("SLA C");
    outline0("LD A, 48");
    outline0("RLD");
    outline0("CP 48");
    outline1("JR NZ,%sB2DEXPH", label);
    outline0("DEC C");
    outline0("INC DE");
    outline1("JR %sB2DEXPL", label );
    outhead1("%sB2DEXP:", label ); 
    outline0("RLD");
    outhead1("%sB2DEXPH:", label );
    outline0("LD (DE),A");
    outline0("INC DE");
    outhead1("%sB2DEXPL:", label );
    outline0("RLD");
    outline0("LD (DE),A");
    outline0("INC DE");
    outline0("INC HL");
    outline1("DJNZ %sB2DEXP", label );
    outline0("SBC HL,BC" );
       
    return b2dbuf;

}

/**
 * @brief Emit ASM implementation for <b>DEBUG [expression]</b> instruction 
 * 
 * This function outputs a string with the value contained in the indicated variable
 * (the variable must be up to 2 bytes longs). For speed of implementation it uses 
 * the function of the KERNAL, so it cannot work if the ROM is disabled.
 * 
 * @param _environment Current calling environment
 * @param _name Name of the variable to print
 * @throw EXIT_FAILURE "DWORD variables cannot be debugged"
 */
/* <usermanual>
@keyword DEBUG

@target zx
</usermanual> */

void debug_var( Environment * _environment, char * _name ) {

    MAKE_LABEL

    // Safety check
    Variable * var = variable_retrieve( _environment, _name );

    switch( VT_BITWIDTH( var->type ) ) {
        case 8:
        case 16:
        case 32: {
            Variable * buffer = vt_to_buffer( _environment, var->name );
            outline0( "LD DE, HL" );
            outline0( "CALL 8252" );
        }
            break;
        case 0:
            switch( var->type ) {
                case VT_STRING: {
                    char stringAddress[16]; sprintf(stringAddress, "%s+1", var->realName );
                    outline1( "LD DE, (%s)", stringAddress );
                    outline1( "LD A, (%s)", var->realName );
                    outline0( "LD C, A" );
                    outline0( "LD B, 0" );
                    outline0( "CALL 8252" );
                    break;
                }
                default:
                    CRITICAL_DEBUG_UNSUPPORTED( _name, DATATYPE_AS_STRING[var->type]);
            }
            break;

    }

    outline0( "LD A, 32");
    outline0( "RST $10" );

    variable_reset( _environment );

}

