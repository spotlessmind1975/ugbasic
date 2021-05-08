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

extern char DATATYPE_AS_STRING[][16];

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

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

@english
Outputs a string with the value contained in the indicated expression.
For speed of implementation 
it uses the function of the KERNAL, so it cannot work if the ROM is disabled.

@italian
Stampa una stringa con il valore contenuto nella espressione indicata.
Per velocità di implementazione
usa la funzione del KERNAL, quindi non può funzionare se la ROM è disabilitata.

@syntax DEBUG [expression]

@example DEBUG someValue

@target c64
</usermanual> */
void debug_var( Environment * _environment, char * _name ) {

    MAKE_LABEL

    // Safety check
    Variable * var = variable_retrieve( _environment, _name );
    switch( VT_BITWIDTH( var->type ) ) {
        case 8:
            if ( VT_SIGNED( var->type ) ) {
                outline0( "LDA #$7" );
                outline0( "STA $22" );
                outline1( "LDX %s", var->realName );
                outline1( "LDA %s", var->realName );
                outline0( "BIT $22" );
                outline1( "BEQ %spos", label );
                outline0( "LDA #45");
                outline0( "JSR $FFD2");
                outhead1( "%spos:", label );
                outline0( "LDA #$0" );
                outhead1( "%sout:", label );
                outline0( "JSR $BDCD" );
            } else {
                outline0( "LDA #$0" );
                outline1( "LDX %s", var->realName );
                outline0( "JSR $BDCD" );
            }
            break;
        case 16:
            if ( VT_SIGNED( var->type ) ) {
                outline0( "LDA #$7" );
                outline0( "STA $22" );
                outline1( "LDA %s+1", var->realName );
                outline0( "BIT $22" );
                outline1( "BEQ %spos", label );
                outhead1( "%sneg:", label );
                outline0( "LDA #45");
                outline0( "JSR $FFD2");
                outline1( "LDA %s", var->realName );
                outline0( "EOR #$ff" );
                outline0( "TAX" );
                outline1( "LDA %s+1", var->realName );
                outline0( "EOR #$ff" );
                outline1( "JMP %sout", label );
                outhead1( "%spos:", label );
                outline1( "LDA %s+1", var->realName );
                outline1( "LDX %s", var->realName );
                outline1( "JMP %sout", label );
                outhead1( "%sout:", label );
                outline0( "JSR $BDCD" );
            } else {
                outline1( "LDA %s+1", var->realName );
                outline1( "LDX %s", var->realName );
                outline0( "JSR $BDCD" );
            }
            break;
        case 32: {

            Variable * result = variable_temporary( _environment, VT_BUFFER, "(buffer for DEBUG)");
            variable_resize_buffer( _environment, result->name, 10 );

            outline1("JSR %shex2dec", label);
            outline0("LDX #9");
            outhead1("%sl1:", label);
            outline1("LDA %s,x", result->realName);
            outline1("BNE %sl2", label );
            outline0("DEX");
            outline1("BNE %sl1", label );
            outhead1("%sl2:", label);
            outline1("LDA %s,x", result->realName);
            outline0("ORA #$30");
            outline0("JSR $FFD2");
            outline0("DEX");
            outline1("BPL %sl2", label );
            outline1("JMP %send", label );
            outhead1("%shex2dec:", label);
            outline0("LDX #0" );
            outhead1("%sl3:", label);
            outline1("JSR %sdiv10", label );
            outline1("STA %s, X", result->realName );
            outline0("INX" );
            outline0("CPX #10" );
            outline1("BNE %sl3", label );
            outline0("RTS" );
            outhead1("%sdiv10:", label);
            if ( VT_SIGNED( result->type ) ) {
                outline0("LDY #31" );
            } else {
                outline0("LDY #32" );
            }
            outline0("LDA #0" );
            outline0("CLC" );
            outhead1("%sl4:", label);
            outline0("ROL" );
            outline0("CMP #10" );
            outline1("BCC %sskip", label );
            outline0("SBC #10" );
            outhead1("%sskip:", label);
            outline1("ROL %s", var->realName );
            outline1("ROL %s+1", var->realName );
            outline1("ROL %s+2", var->realName );
            outline1("ROL %s+3", var->realName );
            outline0("DEY" );
            outline1("BPL %sl4", label );
            outline0("RTS" );
            outhead1("%send:", label);
            break;
        }
        default:
            switch( var->type ) {
                case VT_STRING: {

                    MAKE_LABEL

                    outline1( "LDA %s+1", var->realName );
                    outline0( "STA $22" );
                    outline1( "LDA %s+2", var->realName );
                    outline0( "STA $23" );
                    outline0( "LDY #$0" );
                    outhead1( "%s:", label);
                    outline0( "LDA ($22),Y" );
                    outline0( "JSR $FFD2" );
                    outline0( "INY" );
                    outline1( "CPY %s", var->realName );
                    outline1( "BNE %s", label );
                    break;
                }
                case VT_BUFFER:
                    CRITICAL_DATATYPE_UNSUPPORTED("DEBUG", DATATYPE_AS_STRING[var->type]);
            }
    }
    outline0("LDA #32");
    outline0("JSR $FFD2");
    
}

