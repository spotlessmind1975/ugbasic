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

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#if defined(__pc1403__)

//////////////////////////////////////////////////////////////////////////////
/// COMMON USED OPCODES
//////////////////////////////////////////////////////////////////////////////

static void op_addxl( Environment * _environment, int _offset ) {

    // Xl += low(_offset)
    outline0("LP 0x04" );
    outline1("ADIM 0x%2.2x", (unsigned char)(_offset & 0xff) );

}

static void op_addba( Environment * _environment ) {

    outline0("LP 0x03");
    outline0("ADM");

}

static void op_addab( Environment * _environment ) {

    outline0("LP 0x03");
    outline0("ADM");
    outline0("EXAM");

}

static void op_addabc( Environment * _environment ) {

    outline0("LP 0x03");
    outline0("ADCM");
    outline0("EXAM");

}

static void op_addx_direct( Environment * _environment, int _offset ) {

    // Yl += low(_offset)
    outline0("LP 0x04" );
    outline1("ADIM 0x%2.2x", (unsigned char)(_offset & 0xff) );

    // Yh += high(_offset)
    outline0("LP 0x05" );
    outline1("ADIM 0x%2.2x", (unsigned char)((_offset>>8) & 0xff) );

}

static void op_anda_direct( Environment * _environment, int _direct ) {

    outline1("ANIA 0x%2.2x", _direct );

}

static void op_andab( Environment * _environment ) {

    outline0("LP 0x03" );
    outline0("ANMA");

}

static void op_addya( Environment * _environment ) {

    outline0("LP 0x06" );
    outline0("ADM");
    outline0("LIA 0");
    outline0("LP 0x07" );
    outline0("ADCM");

}

static void op_addyl_direct( Environment * _environment, int _offset ) {

    // Yl += low(_offset)
    outline0("LP 0x06" );
    outline1("ADIM 0X%2.2x", (unsigned char)(_offset & 0xff) );

}

static void op_addy_direct( Environment * _environment, int _offset ) {

    // Yl += low(_offset)
    outline0("LP 0x06" );
    outline1("ADIM 0X%2.2x", (unsigned char)(_offset & 0xff) );

    // Yh += high(_offset)
    outline0("LP 0x07" );
    outline1("ADIM 0X%2.2x", (unsigned char)((_offset>>8) & 0xff) );

}

static void op_call( Environment * _environment, char * _label ) {

    outline1("CALL %s", _label );

}

static void op_clc( Environment * _environment ) {

    outline0("RC");

}

static void op_cpb( Environment * _environment ) {

    outline0("LIP 0x03");
    outline0("CPMA");

}

static void op_cp_direct( Environment * _environment, int _value ) {

    outline1("CPIA 0x%2.2x", (unsigned char)(_value & 0xff));

}

static void op_deca( Environment * _environment ) {

    outline0("DECA");

}

static void op_decjnz( Environment * _environment, char * _label ) {

    outline0("DECJ");
    outline1("JRNZ %s", _label);

}

static void op_decjz( Environment * _environment, char * _label ) {

    outline0("DECJ");
    outline1("JRZ %s", _label);

}

static void op_decinz( Environment * _environment, char * _label ) {

    outline0("DECI");
    outline1("JRNZ %s", _label);

}

static void op_decijnz( Environment * _environment, char * _label ) {

    outline0("DECI");
    outline1("JRNZ %s", _label);
    outline0("DECJ");
    outline1("JRNZ %s", _label);

}

static void op_deciz( Environment * _environment, char * _label ) {

    outline0("DECI");
    outline1("JRZ %s", _label);

}

static void op_decijz( Environment * _environment, char * _label ) {

    outline0("DECI");
    outline1("JRZ %s", _label);
    outline0("DECJ");
    outline1("JRZ %s", _label);

}

static void op_fild_direct( Environment * _environment, int _value ) {

    outline1("LII 0x%2.2x", (unsigned char)( _value & 0xff ) );
    outline0("FILD");

}

static void op_fild( Environment * _environment ) {

    outline0("FILD");

}

static void op_inca( Environment * _environment ) {

    outline0("INCA");

}

static void op_lda( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );
    outline0("LDD");

}

static void op_lda_direct( Environment * _environment, int _value ) {

    outline1("LIA 0x%2.2x", (unsigned char)(_value & 0xff) );

}

static void op_ldb( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x03" );
    outline0("MVWD");

}

static void op_ldb_direct( Environment * _environment, int _value ) {

    outline1("LIB 0x%2.2x", (unsigned char)(_value & 0xff) );

}

static void op_lda_address_low( Environment * _environment, char * _address ) {

    outline1("LIA %s", _address );

}

static void op_lda_address_high( Environment * _environment, char * _address ) {

    outline1("LIA >%s", _address );

}

static void op_lda_x( Environment * _environment ) {

    // A <- (X)
    outline0("DX");
    outline0("IXL");

}

static void op_lda_xn( Environment * _environment ) {

    outline0("IXL");

}

static void op_ldklmn( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x03" );
    outline0("LP 0x08" );
    outline0("MVWD");

}

static void op_ldk( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x08" );
    outline0("MVWD");

}

static void op_ldl( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x09" );
    outline0("MVWD");

}

static void op_ldm( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x0a" );
    outline0("MVWD");

}

static void op_ldn( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x0b" );
    outline0("MVWD");

}

static void op_ldklmn_direct( Environment * _environment, int _value ) {

    outline1("LIA 0x%2.2x", (unsigned char)( _value & 0xff ) );
    outline0("LP 0x08" );
    outline0("EXAM");

    outline1("LIA 0x%2.2x", (unsigned char)( (_value>>8) & 0xff ) );
    outline0("LP 0x09" );
    outline0("EXAM");

    outline1("LIA 0x%2.2x", (unsigned char)( (_value>>16) & 0xff ) );
    outline0("LP 0x0a" );
    outline0("EXAM");

    outline1("LIA 0x%2.2x", (unsigned char)( (_value>>24) & 0xff ) );
    outline0("LP 0x0b" );
    outline0("EXAM");

}

static void op_stxl( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x04" );
    outline0("MVDM");

}

static void op_stxh( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x05" );
    outline0("MVDM");

}

static void op_ldxl_direct( Environment * _environment, int _value ) {

    outline1("LIA 0x%2.2x", (unsigned char)( _value & 0xff ) );
    outline0("LP 0x04" );
    outline0("EXAM");

}

static void op_ldxl( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x04" );
    outline0("MVWD");

}

static void op_ldxh_direct( Environment * _environment, int _value ) {

    outline1("LIA 0x%2.2x", (unsigned char)( _value & 0xff ) );
    outline0("LP 0x05" );
    outline0("EXAM");
    
}

static void op_ldxh( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x05" );
    outline0("MVWD");

}

static void op_ldx_direct( Environment * _environment, int _value ) {

    outline1("LIA 0x%2.2x", (unsigned char)( _value & 0xff ) );
    outline0("LP 0x04" );
    outline0("EXAM");

    outline1("LIA 0x%2.2x", (unsigned char)( (_value >> 8) & 0xff ) );
    outline0("LP 0x05" );
    outline0("EXAM");

}

static void op_ldyl_direct( Environment * _environment, int _value ) {

    outline0("PUSH" );
    outline1("LIA 0x%2.2x", (unsigned char)( _value & 0xff ) );
    outline0("LP 0x06" );
    outline0("EXAM");
    outline0("POP" );

}

static void op_ldyl( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x06" );
    outline0("MVWD");

}

static void op_ldyh_direct( Environment * _environment, int _value ) {

    outline0("PUSH" );
    outline1("LIA 0x%2.2x", (unsigned char)( _value & 0xff ) );
    outline0("LP 0x07" );
    outline0("EXAM");
    outline0("POP" );
    
}

static void op_ldyh( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x07" );
    outline0("MVWD");

}

static void op_styl( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x06" );
    outline0("MVDM");

}

static void op_styh( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x07" );
    outline0("MVDM");

}

static void op_ldy_direct( Environment * _environment, int _value ) {

    outline1("LIA 0x%2.2x", (unsigned char)( _value & 0xff ) );
    outline0("LP 0x06" );
    outline0("EXAM");

    outline1("LIA 0x%2.2x", (unsigned char)( (_value >> 8) & 0xff ) );
    outline0("LP 0x07" );
    outline0("EXAM");

}

static void op_jc( Environment * _environment, char * _label ) {

    MAKE_LABEL
    
    char longJump[MAX_TEMPORARY_STORAGE];
    sprintf( longJump, "%slong", label );

    outhead1(".ifgt 128 - ( %s-. ) ", _label);
    outline1("JRCP %s", _label);
    outhead0(".else");
    outline1("JRNCP %s", longJump);
    outline1("JP %s", _label);
    outhead1("%s:", longJump);
    outhead0(".endif");

}

static void op_jnc( Environment * _environment, char * _label ) {

    MAKE_LABEL
    
    char longJump[MAX_TEMPORARY_STORAGE];
    sprintf( longJump, "%slong", label );

    outhead1(".ifgt 128 - ( %s-. ) ", _label);
    outline1("JRNCP %s", _label);
    outhead0(".else");
    outline1("JRCP %s", longJump);
    outline1("JP %s", _label);
    outhead1("%s:", longJump);
    outhead0(".endif");

}

static void op_jp( Environment * _environment, char * _label ) {

    outline1("JP %s", _label);

}

static void op_jz( Environment * _environment, char * _label ) {

    MAKE_LABEL

    char longJump[MAX_TEMPORARY_STORAGE];
    sprintf( longJump, "%slong", label );

    outhead1(".ifgt 128 - ( %s-. ) ", _label);
    outline1("JRZP %s", _label);
    outhead0(".else");
    outline1("JRNZP %s", longJump);
    outline1("JP %s", _label);
    outhead1("%s:", longJump);
    outhead0(".endif");

}

static void op_jnz( Environment * _environment, char * _label ) {
    
    MAKE_LABEL

    char longJump[MAX_TEMPORARY_STORAGE];
    sprintf( longJump, "%slong", label );

    outhead1(".ifgt 128 - ( %s-. ) ", _label);
    outline1("JRNZP %s", _label);
    outhead0(".else");
    outline1("JRZP %s", longJump);
    outline1("JP %s", _label);
    outhead1("%s:", longJump);
    outhead0(".endif");

}

static void op_ldi( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x00" );
    outline0("MVWD");

}

static void op_sti( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x00" );
    outline0("MVDM");

}

static void op_ldi_direct( Environment * _environment, int _value ) {

    outline1("LII 0x%2.2x", (unsigned char)(_value & 0xff ) );

}

static void op_ldj( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x01" );
    outline0("MVWD");

}

static void op_stj( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x01" );
    outline0("MVDM");

}

static void op_ldj_direct( Environment * _environment, int _value ) {

    outline1("LIJ 0x%2.2x", (unsigned char)(_value & 0xff ) );

}

static void op_ldij( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x01" );
    outline0("LP 0x00" );
    outline0("MVWD");

}

static void op_ldijab( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x03" );
    outline0("LP 0x00" );
    outline0("MVWD");

}

static void op_ldij_direct( Environment * _environment, int _value ) {

    outline1("LII 0x%2.2x", (unsigned char)(_value&0xff) );
    outline1("LIJ 0x%2.2x", (unsigned char)((_value>>8)&0xff) );

}

static void op_ldab( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x01" );
    outline0("LP 0x02" );
    outline0("MVWD");
    outline0("EXAB");

}

static void op_ldab_direct( Environment * _environment, int _value ) {

    outline1("LIB 0x%2.2x", (unsigned char)(_value&0xff) );
    outline1("LIA 0x%2.2x", (unsigned char)((_value>>8)&0xff) );

}

static void op_ldk_direct( Environment * _environment, int _value ) {

    outline1("LIA 0x%2.2x", (unsigned char)(_value) );
    outline0("LP 0x08" );
    outline0("EXAM");

}


static void op_stk( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x08" );
    outline0("MVDM");

}

static void op_ldl_direct( Environment * _environment, int _value ) {

    outline1("LIA 0x%2.2x", (unsigned char)(_value) );
    outline0("LP 0x09" );
    outline0("EXAM");

}

static void op_stl( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x09" );
    outline0("MVDM");

}

static void op_ldm_direct( Environment * _environment, int _value ) {

    outline1("LIA 0x%2.2x", (unsigned char)(_value) );
    outline0("LP 0x0a" );
    outline0("EXAM");

}

static void op_stm( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x0a" );
    outline0("MVDM");

}

static void op_ldn_direct( Environment * _environment, int _value ) {

    outline1("LIA 0x%2.2x", (unsigned char)(_value) );
    outline0("LP 0x0b" );
    outline0("EXAM");

}

static void op_stn( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x00" );
    outline0("LP 0x0b" );
    outline0("MVDM");

}

static void op_ldx( Environment * _environment, char * _address ) {

    // DP <- address
    outline1("LIDP %s", _address );

    // X <- (DP)
    outline0("LII 0x01" );
    outline0("LP 0x04" );
    outline0("MVWD");

}

static void op_ldy( Environment * _environment, char * _address ) {

    // DP <- address
    outline1("LIDP %s", _address );

    // Y <- (DP)
    outline0("LII 0x01" );
    outline0("LP 0x06" );
    outline0("MVWD");

}

static void op_lddp_direct( Environment * _environment, char * _address ) {

    // DP <- address
    outline1("LIDP %s", _address);

}

static void op_lddp( Environment * _environment, char * _address ) {

    // DP <- address
    outline1("LIDP %s", _address);
    // X <- (address)
    outline0("LII 0x01" );
    outline0("LP 0x04" );
    outline0("MVWD");
    outline0("DX");
    outline0("IX");

}

static void op_orab( Environment * _environment ) {

    outline0("LP 0x03" );
    outline0("ORMA");

}

static void op_push( Environment * _environment ) {

    outline0("PUSH");

}

static void op_pop( Environment * _environment ) {

    outline0("POP");

}

static void op_sla( Environment * _environment ) {

    outline0("SL");

}

static void op_sra( Environment * _environment ) {

    outline0("SR");

}

static void op_sta( Environment * _environment, char * _address ) {

    // DP <- target
    outline1("LIDP %s", _address );

    // (DP) <- A
    outline0("STD");

}

static void op_stab( Environment * _environment, char * _address ) {

    // DP <- target
    outline1("LIDP %s", _address );

    // (DP) <- A
    outline0("EXAB");
    outline0("STD");
    outline0("EXAB");

    // DP <- target
    outline1("LIDP %s", address_displacement( _environment, _address, "1" ) );

    // (DP) <- A
    outline0("STD");

}

static void op_stb( Environment * _environment, char * _address ) {

    outline1("LIDP %s", _address );

    outline0("LII 0x01" );
    outline0("LP 0x01" );
    outline0("MVDM");

}

static void op_sta_y( Environment * _environment ) {

    outline0("DY");
    outline0("IYS");

}

static void op_sta_yn( Environment * _environment ) {

    outline0("IYS");

}

static void op_subba( Environment * _environment ) {

    outline0("LP 0x03");
    outline0("SBM");

}

static void op_subab( Environment * _environment ) {

    outline0("LP 0x03");
    outline0("SBM");
    outline0("EXAM");

}

static void op_subabc( Environment * _environment ) {

    outline0("LP 0x03");
    outline0("SBCM");
    outline0("EXAM");

}

static void op_swab( Environment * _environment ) {

    outline0("EXAB");

}

static void op_xab( Environment * _environment ) {

    outline0("LIP 0x03");
    outline0("EXAM");

}

static void op_xxla( Environment * _environment ) {

    outline0("LIP 0x04");
    outline0("EXAM");

}

static void op_xxha( Environment * _environment ) {

    outline0("LIP 0x05");
    outline0("EXAM");

}

static void op_wait_direct( Environment * _environment, int _value ) {

    outline1("WAIT %2.2x", _value );

}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void sc61860_nop( Environment * _environment ) {

    outline0("NOPW");

}

void sc61860_init( Environment * _environment ) {

}

void sc61860_ztoa( Environment * _environment ) {

    MAKE_LABEL

    outline1("JRZP %syes", label );
    outline0("LIA 0");
    outline1("JRP %s", label );
    outhead1("%syes:", label );
    outline0("LIA 0xff");
    outhead1("%s:", label );

}

void sc61860_ctoa( Environment * _environment ) {

    MAKE_LABEL

    outline1("JRC %syes", label );
    outline0("LIA 0");
    outline1("JRP %s", label );
    outhead1("%syes:", label );
    outline0("LIA 0xff");
    outhead1("%s:", label );

}

/**
 * @brief <i>SC616860</i>: emit code to make long conditional jump
 * 
 * This function outputs a code that guarantees an arbitrary distance jump 
 * with conditional check on equality. In fact, the opcode BEQ of the 
 * SC616860 processor allows to make a jump of maximum +/- 128 bytes with 
 * respect to the address where the processor is at that moment. 
 * To overcome this problem, this function will make a conditional jump to
 * a very close location, which (in turn) will make an unconditional jump 
 * to the true destination.
 * 
 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void sc61860_beq( Environment * _environment, char * _label ) {

    MAKE_LABEL

    outline1("JRZP %syes", label );
    outline1("JRP %s", label );
    outhead1("%syes:", label );
    outline1("JP %s", _label);
    outhead1("%s:", label );

}

/**
 * @brief <i>SC616860</i>: emit code to make long conditional jump

 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void sc61860_bneq( Environment * _environment, char * _label ) {

    MAKE_LABEL

    outline1("JRNZP %syes", label );
    outline1("JRP %s", label );
    outhead1("%syes:", label );
    outline1("JP %s", _label);
    outhead1("%s:", label );

}

void sc61860_bveq( Environment * _environment, char * _value, char * _label ) {

    outline1("LIDP %s", _value);
    outline0("LDD");
    outline0("CPIA 0");
    sc61860_beq( _environment, _label );

}

void sc61860_bvneq( Environment * _environment, char * _value, char * _label ) {

    outline1("LIDP %s", _value);
    outline0("LDD");
    outline0("CPIA 0");
    sc61860_bneq( _environment, _label );

}

void sc61860_label( Environment * _environment, char * _label ) {
    outhead1("%s:", _label);
}

void sc61860_peek( Environment * _environment, char * _address, char * _target ) {

    op_ldx( _environment, _address );

    op_lda_x( _environment );

    op_sta( _environment, _target );

}

void sc61860_poke( Environment * _environment, char * _address, char * _source ) {

    op_ldy( _environment, _address );

    op_lda( _environment, _source );

    op_sta_y( _environment );

}

void sc61860_peekw( Environment * _environment, char * _address, char * _target ) {

    op_ldx( _environment, _address );

    op_lda_x( _environment );

    op_sta( _environment, _target );

    op_lda_xn( _environment );

    op_sta( _environment, address_displacement( _environment, _target, "1" ) );

}

void sc61860_pokew( Environment * _environment, char * _address, char * _source ) {

    op_ldy( _environment, _address );

    op_lda( _environment, _source );

    op_sta_y( _environment );

    op_lda( _environment, address_displacement( _environment, _source, "1" ) );

    op_sta_yn( _environment );


}

void sc61860_peekd( Environment * _environment, char * _address, char * _target ) {

    op_ldx( _environment, _address );

    op_lda_x( _environment );

    op_sta( _environment, _target );

    op_lda_xn( _environment );

    op_sta( _environment, address_displacement( _environment, _target, "1" ) );

    op_lda_xn( _environment );

    op_sta( _environment, address_displacement( _environment, _target, "2" ) );

    op_lda_xn( _environment );

    op_sta( _environment, address_displacement( _environment, _target, "3" ) );


}

void sc61860_poked( Environment * _environment, char * _address, char * _source ) {

    op_ldy( _environment, _address );

    op_lda( _environment, _source );

    op_sta_y( _environment );

    op_lda( _environment, address_displacement( _environment, _source, "1" ) );

    op_sta_yn( _environment );

    op_lda( _environment, address_displacement( _environment, _source, "2" ) );

    op_sta_yn( _environment );

    op_lda( _environment, address_displacement( _environment, _source, "3" ) );

    op_sta_yn( _environment );

    op_lda( _environment, address_displacement( _environment, _source, "4" ) );

    op_sta_yn( _environment );

}

/**
 * @brief <i>SC616860</i>: emit code to fill up a memory area
 * 
 * This function can be used to output a piece of code that fills a given 
 * memory area with a given pattern (pattern size: 1 byte). The starting 
 * address must be contained in a variable, while the area must be a multiple 
 * of 256 bytes.
 * 
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _blocks Number of 256 bytes blocks to fill
 * @param _pattern Pattern to use
 */
void sc61860_fill_blocks( Environment * _environment, char * _address, char * _blocks, char * _pattern ) {

    MAKE_LABEL

    op_ldj( _environment, _blocks );

    op_lda( _environment, _pattern );

    op_lddp( _environment, _address );

    outhead1("%s:", label );

    op_fild_direct( _environment, 0xff );

    op_decjnz( _environment, label );

}

/**
 * @brief <i>SC616860</i>: emit code to fill up a memory area
 * 
 * This function can be used to output a piece of code that fills a given 
 * memory area with a given pattern (pattern size: 1 byte). The starting 
 * address must be contained in a variable, while the area must be a multiple 
 * of 256 bytes.
 * 
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _pattern Pattern to use
 */
void sc61860_fill( Environment * _environment, char * _address, char * _bytes, int _bytes_width, char * _pattern ) {

    MAKE_LABEL

    if ( _bytes_width == 8 ) {

        op_ldi( _environment, _bytes );

        op_lda( _environment, _pattern );

        op_lddp( _environment, _address );

        op_fild( _environment );

    } else {

        char repeatLabel[MAX_TEMPORARY_STORAGE];
        sprintf( repeatLabel, "%srepeat", label );

        op_ldi( _environment, _bytes );

        op_lda( _environment, _pattern );

        op_lddp( _environment, _address );

        op_fild( _environment );

        op_decjz( _environment, label);

        outhead1("%s:", repeatLabel );

        op_fild_direct( _environment, 0xff );
        op_decjnz( _environment, repeatLabel );

        outhead1("%s", label );

    }

}

/**
 * @brief <i>SC616860</i>: emit code to fill up a memory area
 * 
 * This function can be used to output a piece of code that fills a given 
 * memory area with a given pattern (pattern size: 1 byte). The starting 
 * address must be contained in a variable, while the area must be a multiple 
 * of 256 bytes.
 * 
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _pattern Pattern to use
 */
void sc61860_fill_size( Environment * _environment, char * _address, int _bytes, char * _pattern ) {

    MAKE_LABEL

    if ( _bytes < 256 ) {

        op_lda( _environment, _pattern );

        op_lddp( _environment, _address );

        op_fild_direct( _environment, (unsigned char)(_bytes&0xff) );

    } else {

        char repeatLabel[MAX_TEMPORARY_STORAGE];
        sprintf( repeatLabel, "%srepeat", label );

        op_ldij_direct( _environment, _bytes );

        op_lda( _environment, _pattern );

        op_lddp( _environment, _address );

        op_fild( _environment );
        op_decjz( _environment, label );

        outhead1("%s:", repeatLabel );

        op_fild_direct( _environment, 0xff );

        op_decjnz( _environment, repeatLabel );

        outhead1("%s:", label );

    }

}

/**
 * @brief <i>SC616860</i>: emit code to fill up a memory area
 * 
 * This function can be used to output a piece of code that fills a given 
 * memory area with a given pattern (pattern size: 1 byte). The starting 
 * address must be contained in a variable, while the area must be a multiple 
 * of 256 bytes.
 * 
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _pattern Pattern to use
 */
void sc61860_fill_size_value( Environment * _environment, char * _address, int _bytes, int _pattern ) {

    MAKE_LABEL

    if ( _bytes < 256 ) {

        op_lda_direct( _environment, _pattern );

        op_lddp( _environment, _address );

        op_fild_direct( _environment, _bytes );

    } else {

        char repeatLabel[MAX_TEMPORARY_STORAGE];
        sprintf( repeatLabel, "%srepeat", label );

        op_ldij_direct( _environment, _bytes );

        op_lda_direct( _environment, _pattern );

        op_lddp( _environment, _address );

        op_fild( _environment );

        op_decjz( _environment, label );

        outhead1("%s:", repeatLabel );

        op_fild_direct( _environment, 0xff );
        op_decjnz( _environment, label );

        outhead1("%s:", label );
    }

}

/**
 * @brief <i>SC616860</i>: emit code to fill up a memory area
 * 
 * This function can be used to output a piece of code that fills a given 
 * memory area with a given pattern (pattern size: 1 byte). The starting 
 * address must be contained in a variable, while the area must be a multiple 
 * of 256 bytes.
 * 
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _pattern Pattern to use
 */
void sc61860_fill_direct( Environment * _environment, char * _address, char * _bytes, char * _pattern ) {

    MAKE_LABEL

    char repeatLabel[MAX_TEMPORARY_STORAGE];
    sprintf( repeatLabel, "%srepeat", label );

    op_ldij( _environment, _bytes );

    op_lda( _environment, _pattern );

    op_lddp_direct( _environment, _address );

    op_fild( _environment );
    op_decjz( _environment, label );

    outhead1("%s:", repeatLabel );

    op_fild_direct( _environment, 0xff );
    op_decjnz( _environment, repeatLabel );

    outhead1("%sdone:", label );

}

/**
 * @brief <i>SC616860</i>: emit code to fill up a memory area
 * 
 * This function can be used to output a piece of code that fills a given 
 * memory area with a given pattern (pattern size: 1 byte). The starting 
 * address must be contained in a variable, while the area must be a multiple 
 * of 256 bytes.
 * 
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _pattern Pattern to use
 */
void sc61860_fill_direct_size( Environment * _environment, char * _address, int _bytes, char * _pattern ) {

    MAKE_LABEL

    char repeatLabel[MAX_TEMPORARY_STORAGE];
    sprintf( repeatLabel, "%srepeat", label );

    op_ldij_direct( _environment, _bytes );

    op_lda( _environment, _pattern );

    op_lddp_direct( _environment, _address );

    op_fild( _environment );
    op_decjz( _environment, label );

    outhead1("%s:", repeatLabel );

    op_fild_direct( _environment, 0xff );
    op_decjnz( _environment, repeatLabel );

    outhead1("%sdone:", label );


}

/**
 * @brief <i>SC616860</i>: emit code to fill up a memory area
 * 
 * This function can be used to output a piece of code that fills a given 
 * memory area with a given pattern (pattern size: 1 byte). The starting 
 * address must be contained in a variable, while the area must be a multiple 
 * of 256 bytes.
 * 
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _pattern Pattern to use
 */
void sc61860_fill_direct_size_value( Environment * _environment, char * _address, int _bytes, int _pattern ) {

    MAKE_LABEL

    char repeatLabel[MAX_TEMPORARY_STORAGE];
    sprintf( repeatLabel, "%srepeat", label );

    op_ldij_direct( _environment, _bytes );

    op_lda_direct( _environment, _pattern );

    op_lddp_direct( _environment, _address );

    op_fild( _environment );
    op_decjz( _environment, label );

    outhead1("%s:", repeatLabel );

    op_fild_direct( _environment, 0xff );
    op_decjnz( _environment, repeatLabel );

    outhead1("%sdone:", label );
    
}

/*****************************************************************************
 * 8 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>SC616860</i>: emit code to move 8 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void sc61860_move_8bit( Environment * _environment, char *_source, char *_destination ) {
    
    op_lda( _environment, _source );

    op_sta( _environment, _destination );

}

/**
 * @brief <i>SC616860</i>: emit code to store 8 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void sc61860_store_8bit( Environment * _environment, char *_destination, int _value ) {

    op_lda_direct( _environment, _value );
    
    op_sta( _environment, _destination );

}

/**
 * @brief <i>SC616860</i>: emit code to store 8 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void sc61860_store_char( Environment * _environment, char *_destination, int _value ) {

    op_lda_direct( _environment, _value );
    
    op_sta( _environment, _destination );

}

void sc61860_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset ) {

    op_ldy( _environment, _destination );

    op_addy_direct( _environment, _offset );

    op_lda_direct( _environment, _value );

    op_sta_y( _environment );

}

void sc61860_store_8bit_with_offset2( Environment * _environment, char *_destination, char * _offset, int _value ) {

    op_lda( _environment, _offset );

    op_ldy( _environment, _destination );

    op_addya( _environment );

    op_lda_direct( _environment, _value );

    op_sta_y( _environment );

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Meaning of comparison
 */
void sc61860_compare_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    char doneLabel[MAX_TEMPORARY_STORAGE];
    sprintf( doneLabel, "%sb2", label );

    op_lda( _environment, _destination );

    op_xab( _environment );

    op_lda( _environment, _source );

    op_cpb( _environment );

    op_jnz( _environment, label );

    op_lda_direct( _environment, 0xff*_positive );

    if ( _other ) {
        op_sta( _environment, _other );
    } else {
        op_sta( _environment, _destination );
    }

    op_jp( _environment, doneLabel );

    outhead1("%s:", label);
    
    op_lda_direct( _environment, 0xff*(1-_positive) );

    if ( _other ) {
        op_sta( _environment, _other );
    }
    
    outhead1("%s:", doneLabel);

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Meaning of comparison
 */
void sc61860_compare_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

    MAKE_LABEL

    char doneLabel[MAX_TEMPORARY_STORAGE];
    sprintf( doneLabel, "%sb2", label );

    op_lda( _environment, _source );

    op_cp_direct( _environment, _destination );

    op_jnz( _environment, label );

    op_lda_direct( _environment, 0xff*_positive );

    if ( _other ) {
        op_sta( _environment, _other );
    }

    op_jp( _environment, doneLabel );

    outhead1("%s:", label);
    
    op_lda_direct( _environment, 0xff*(1-_positive) );

    op_sta( _environment, _other );
    
    outhead1("%s:", doneLabel);

}

void sc61860_compare_and_branch_8bit( Environment * _environment, char *_source, char * _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    op_ldx( _environment, _destination );

    op_lda_x( _environment );

    op_xab( _environment );

    op_lda( _environment, _source );

    op_cpb( _environment );

    if ( _positive ) {
        op_jnz( _environment, label );
        op_jp( _environment, _label );
    } else {
        op_jz( _environment, label );
        op_jp( _environment, _label );
    }

    outhead1("%s:", label);

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void sc61860_compare_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    op_lda( _environment, _source );

    op_cp_direct( _environment, _destination );

    if ( _positive ) {
        op_jnz( _environment, label );
        op_jp( _environment, _label );
    } else {
        op_jz( _environment, label );
        op_jp( _environment, _label );
    }

    outhead1("%s:", label);

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void sc61860_prepare_for_compare_and_branch_8bit( Environment * _environment, char *_source ) {

    op_lda( _environment, _source );

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void sc61860_execute_compare_and_branch_8bit_const( Environment * _environment, int _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    op_cp_direct( _environment, _destination );

    if ( _positive ) {
        op_jnz( _environment, label );
        op_jp( _environment, _label );
    } else {
        op_jz( _environment, label );
        op_jp( _environment, _label );
    }

    outhead1("%s:", label);

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void sc61860_compare_and_branch_char_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    sc61860_compare_and_branch_8bit_const( _environment, _source, _destination, _label, _positive );

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void sc61860_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_8bit )

    embedded( cpu_less_than_8bit, src_hw_sc61860_cpu_less_than_8bit_asm );

        if ( _signed ) {

            op_ldi( _environment, _source );
            op_lda( _environment, _destination );
            if ( _equal ) {
                op_call( _environment, "CPULTE8S" );
            } else {
                op_call( _environment, "CPULT8S" );
            }
            if ( _other ) {
                op_sta( _environment, _other );
            } else {
                op_sta( _environment, _destination );
            }

        } else {

            op_ldi( _environment, _source );
            op_lda( _environment, _destination );
            if ( _equal ) {
                op_call( _environment, "CPULTE8U" );
            } else {
                op_call( _environment, "CPULT8U" );
            }
            if ( _other ) {
                op_sta( _environment, _other );
            } else {
                op_sta( _environment, _destination );
            }

        }

    done(  )
	
}

void sc61860_less_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_8bit )

    embedded( cpu_less_than_8bit, src_hw_sc61860_cpu_less_than_8bit_asm );

        if ( _signed ) {

            op_ldi( _environment, _source );

            op_lda_direct( _environment, _destination );

            if ( _equal ) {
                op_call( _environment, "CPULTE8S" );
            } else {
                op_call( _environment, "CPULT8S" );
            }

            op_sta( _environment, _other );

        } else {

            op_ldi( _environment, _source );

            op_lda_direct( _environment, _destination );

            if ( _equal ) {
                op_call( _environment, "CPULTE8U" );
            } else {
                op_call( _environment, "CPULT8U" );
            }

            op_sta( _environment, _other );

        }

    done(  )

}

void sc61860_less_than_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _equal, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        char positiveLabel[MAX_TEMPORARY_STORAGE];
        sprintf( positiveLabel, "%spos", label );

        char doneLabel[MAX_TEMPORARY_STORAGE];
        sprintf( doneLabel, "%sb2", label );

        op_lda( _environment, _source );

        op_anda_direct( _environment, 0x80 );
        op_cp_direct( _environment, 0x00 );
        op_jz( _environment, positiveLabel );

        op_cp_direct( _environment, _destination );

        if ( _equal ) {
            op_jz( _environment, label );
        }
        op_jnc( _environment, label );

        op_jp( _environment, doneLabel );

        outhead1("%s:", positiveLabel);

        op_cp_direct( _environment, _destination );

        op_jc( _environment, label );
        if ( _equal ) {
            op_jnz( _environment, label );
        }

        op_jp( _environment, doneLabel );

        outhead1("%s:", label);

        op_jp( _environment, _label );

        outhead1("%s:", doneLabel);

    } else {

        char doneLabel[MAX_TEMPORARY_STORAGE];
        sprintf( doneLabel, "%sb2", label );

        op_lda( _environment, _source );

        op_cp_direct( _environment, _destination );

        op_jc( _environment, label );
        if ( _equal ) {
            op_jnz( _environment, label );
        }

        op_jp( _environment, doneLabel );

        outhead1("%s:", label);

        op_jp( _environment, _label );

        outhead1("%s:", doneLabel);

    }

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void sc61860_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    sc61860_less_than_8bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        sc61860_not_8bit( _environment, _other, _other );
    } else {
        sc61860_not_8bit( _environment, _destination, _destination );
    }

}

void sc61860_greater_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    sc61860_less_than_8bit_const( _environment, _source, _destination, _other, !_equal, _signed );
    sc61860_not_8bit( _environment, _other, _other );

}

/**
 * @brief <i>SC616860</i>: emit code to add two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sc61860_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    MAKE_LABEL

    op_lda( _environment, _source );

    op_xab( _environment );

    op_lda( _environment, _destination );     

    op_addab( _environment );

    if ( _other ) {
        op_sta( _environment, _other );
    } else {
        op_sta( _environment, _destination );
    }

}

void sc61860_math_add_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    MAKE_LABEL

    op_lda( _environment, _source );

    op_xab( _environment );

    op_lda_direct( _environment, _destination );     

    op_addab( _environment );

    if ( _other ) {
        op_sta( _environment, _other );
    }

}

/**
 * @brief <i>SC616860</i>: emit code to subtract two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sc61860_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    MAKE_LABEL

    op_lda( _environment, _source );

    op_xab( _environment );

    op_lda( _environment, _destination );     

    op_subab( _environment );

    if ( _other ) {
        op_sta( _environment, _other );
    } else {
        op_sta( _environment, _destination );
    }

}

/**
 * @brief <i>SC616860</i>: emit code to double a 8 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sc61860_math_double_8bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    if ( _signed ) {

        op_lda( _environment, _source );
        op_anda_direct( _environment, 0x80 );
        op_swab( _environment );

        op_lda( _environment, _source );
        op_sla( _environment );
        op_orab( _environment );
        if ( _other ) {
            op_sta( _environment, _other );
        } else {
            op_sta( _environment, _source );
        }

    } else {

        op_lda( _environment, _source );
        op_sla( _environment );
        if ( _other ) {
            op_sta( _environment, _other );
        } else {
            op_sta( _environment, _source );
        }
    }

}

/**
 * @brief <i>SC616860</i>: emit code to multiply two 8bit values in a 16 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (8 bit)
 * @param _destination Second value to multipy (8 bit)
 * @param _other Destination address for result (16 bit)
 */

void sc61860_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_math_mul_8bit_to_16bit )

    embedded( cpu_math_mul_8bit_to_16bit, src_hw_sc61860_cpu_math_mul_8bit_to_16bit_asm );

        if ( _signed ) {

            op_ldi( _environment, _source );

            op_lda( _environment, _destination );

            op_call( _environment, "CPUMUL8B8T16S");
            
            op_sta( _environment, _other );

            op_xab( _environment );

            op_sta( _environment, address_displacement( _environment, _other, "1" ) );

        } else {

            op_ldi( _environment, _source );

            op_lda( _environment, _destination );

            op_call( _environment, "CPUMUL8B8T16U");
            
            op_sta( _environment, _other );

            op_xab( _environment );

            op_sta( _environment, address_displacement( _environment, _other, "1" ) );

        }

    done(  )

}

/**
 * @brief <i>SC616860</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void sc61860_math_div2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

    MAKE_LABEL

    no_inline( cpu_math_div2_const_8bit )

    embedded( cpu_math_div2_const_8bit, src_hw_sc61860_cpu_math_div2_const_8bit_asm );

        if ( _remainder ) {
            op_lda( _environment, _source );
            op_anda_direct( _environment, 0x01 );
            op_sta( _environment, _remainder );
        }

        if ( _signed ) {

            op_ldi_direct( _environment, _steps );

            op_lda( _environment, _source );

            op_call( _environment, "CPUDIV2CONST8S" );

            op_sta( _environment, _source );

        } else {

            op_ldi_direct( _environment, _steps );

            op_lda( _environment, _source );

            op_call( _environment, "CPUDIV2CONST8U" );

            op_sta( _environment, _source );

        }

    done(  )

}

/**
 * @brief <i>SC616860</i>: emit code to double for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void sc61860_math_mul2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_math_mul2_const_8bit )

    embedded( cpu_math_mul2_const_8bit, src_hw_sc61860_cpu_math_mul2_const_8bit_asm );

        if ( _signed ) {

            op_ldi_direct( _environment, _steps );

            op_lda( _environment, _source );

            op_call( _environment, "CPUMUL2CONST8S" );

            op_sta( _environment, _source );

        } else {

            op_ldi_direct( _environment, _steps );

            op_lda( _environment, _source );

            op_call( _environment, "CPUMUL2CONST8U" );

            op_sta( _environment, _source );

        }

    done(  )

}

/**
 * @brief <i>SC616860</i>: emit code to calculate an 8 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void sc61860_math_complement_const_8bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_8bit )

        op_lda( _environment, _source );

        op_xab( _environment );

        op_lda_direct( _environment, _value );

        op_subab( _environment );

        op_sta( _environment, _source );

    no_embedded( cpu_math_complement_const_8bit )

}

/**
 * @brief <i>SC616860</i>: emit code to mask with "and" a value of 8 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void sc61860_math_and_const_8bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_8bit )

        op_lda( _environment, _source );

        op_anda_direct( _environment, _mask );

        op_sta( _environment, _source );

    no_embedded( cpu_math_and_const_8bit )

}

/*****************************************************************************
 * 16 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>SC616860</i>: emit code to move 16 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void sc61860_move_16bit( Environment * _environment, char *_source, char *_destination ) {
    
    inline( cpu_move_16bit )

        op_lda( _environment, _source );

        op_sta( _environment, _destination );

        op_lda( _environment, address_displacement( _environment, _source, "1" ) );

        op_sta( _environment, address_displacement( _environment, _destination, "1" ) );

    no_embedded( cpu_move_16bit )

}

void sc61860_addressof_16bit( Environment * _environment, char *_source, char *_destination ) {
    
    inline( cpu_addressof_16bit )

        op_lda_address_low( _environment, _source );

        op_sta( _environment, _destination );

        op_lda_address_high( _environment, _source );

        op_sta( _environment, address_displacement( _environment, _destination, "1" ) );

    no_embedded( cpu_addressof_16bit )

}

/**
 * @brief <i>SC616860</i>: emit code to store 16 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void sc61860_store_16bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_16bit )

        op_lda_direct( _environment, _value & 0xff );

        op_sta( _environment, _destination );

        op_lda_direct( _environment, (_value >> 8) & 0xff );

        op_sta( _environment, address_displacement( _environment, _destination, "1" ) );

    no_embedded( cpu_store_16bit )

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sc61860_compare_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    no_inline( cpu_compare_16bit )

    embedded( cpu_compare_16bit, src_hw_sc61860_cpu_compare_16bit_asm )

        op_ldk_direct( _environment, (0xff*_positive) );
        op_ldl_direct( _environment, ( 0xff*(1-_positive)) );

        op_ldij( _environment, _source );

        op_ldab( _environment, _destination );

        op_call( _environment, "CPUCOMPARE16");
        if ( _other ) {
            op_sta( _environment, _other );
        } else {
            op_sta( _environment, _destination );
        }

    done( )

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sc61860_compare_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

    MAKE_LABEL

    no_inline( cpu_compare_16bit )

    embedded( cpu_compare_16bit, src_hw_sc61860_cpu_compare_16bit_asm )

        op_ldk_direct( _environment, (0xff*_positive) );
        op_ldl_direct( _environment, ( 0xff*(1-_positive)) );

        op_ldij( _environment, _source );

        op_ldab_direct( _environment, _destination );

        op_call( _environment, "CPUCOMPARE16");

        op_sta( _environment, _other );

    done( )

}

void sc61860_compare_and_branch_16bit( Environment * _environment, char *_source, char *_destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_16bit )

        MAKE_LABEL

        op_ldk_direct( _environment, (0xff*_positive) );
        op_ldl_direct( _environment, ( 0xff*(1-_positive)) );

        op_ldij( _environment, _source );

        op_ldab( _environment, _destination );

        op_call( _environment, "CPUCOMPARE16");
        op_cp_direct( _environment, (0xff*_positive) );
        op_jnz( _environment, label );
        op_jp( _environment, _label );
        outhead1("%s", label );

    no_embedded( cpu_compare_and_branch_16bit )

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 16 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void sc61860_compare_and_branch_16bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_16bit_const )

        MAKE_LABEL

        op_ldk_direct( _environment, (0xff*_positive) );
        op_ldl_direct( _environment, ( 0xff*(1-_positive)) );

        op_ldij( _environment, _source );

        op_ldab_direct( _environment, _destination );

        op_call( _environment, "CPUCOMPARE16");
        op_cp_direct( _environment, (0xff*_positive) );
        op_jnz( _environment, label );
        op_jp( _environment, _label );
        outhead1("%s", label );

    no_embedded( cpu_compare_and_branch_16bit_const )

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void sc61860_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_16bit )

    embedded( cpu_less_than_16bit, src_hw_sc61860_cpu_less_than_16bit_asm );

        if ( _signed ) {

            op_ldij( _environment, _source );

            op_ldab( _environment, _destination );

            if ( _equal ) {
                op_call( _environment, "CPULTE16S" );
            } else {
                op_call( _environment, "CPULT16S" );
            }
            if ( _other ) {
                op_sta( _environment, _other );
            } else {
                op_sta( _environment, _destination );
            }

        } else {

            op_ldij( _environment, _source );

            op_ldab( _environment, _destination );

            if ( _equal ) {
                op_call( _environment, "CPULTE16U" );
            } else {
                op_call( _environment, "CPULT16U" );
            }
            if ( _other ) {
                op_sta( _environment, _other );
            } else {
                op_sta( _environment, _destination );
            }

        }

    done(  )

}

void sc61860_less_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_16bit )

    embedded( cpu_less_than_16bit, src_hw_sc61860_cpu_less_than_16bit_asm );

        if ( _signed ) {

            op_ldij( _environment, _source );

            op_ldab_direct( _environment, _destination );

            if ( _equal ) {
                op_call( _environment, "CPULTE16S" );
            } else {
                op_call( _environment, "CPULT16S" );
            }

            op_sta( _environment, _other );

        } else {

            op_ldij( _environment, _source );

            op_ldab_direct( _environment, _destination );

            if ( _equal ) {
                op_call( _environment, "CPULTE16U" );
            } else {
                op_call( _environment, "CPULT16U" );
            }

            op_sta( _environment, _other );

        }

    done(  )

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void sc61860_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    sc61860_less_than_16bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        sc61860_not_8bit( _environment, _other, _other );
    } else {
        sc61860_not_8bit( _environment, _destination, _destination );
    }

}

void sc61860_greater_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    sc61860_less_than_16bit_const( _environment, _source, _destination, _other, !_equal, _signed );
    sc61860_not_8bit( _environment, _other, _other );

}

/**
 * @brief <i>SC616860</i>: emit code to add two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add (memory)
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sc61860_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit )

        MAKE_LABEL

        op_lda( _environment, _source );

        op_xab( _environment );

        op_lda( _environment, _destination );     

        op_addab( _environment );

        if ( _other ) {
            op_sta( _environment, _other );
        } else {
            op_sta( _environment, _destination );
        }

        op_lda( _environment, address_displacement( _environment, _source, "1" ) );

        op_xab( _environment );

        op_lda( _environment, address_displacement( _environment, _destination, "1" ) );     

        op_addabc( _environment );

        if ( _other ) {
            op_sta( _environment, address_displacement( _environment, _other, "1" )  );
        } else {
            op_sta( _environment, address_displacement( _environment, _destination, "1" ) );
        }

    no_embedded( cpu_math_add_16bit )

}

void sc61860_math_add_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_16bit_const )

        MAKE_LABEL

        op_lda( _environment, _source );

        op_xab( _environment );

        op_lda_direct( _environment, _destination );     

        op_addab( _environment );

        op_sta( _environment, _other );

        op_lda( _environment, address_displacement( _environment, _source, "1" ) );

        op_xab( _environment );

        op_lda_direct( _environment, _destination>>8 );     

        op_addabc( _environment );

        op_sta( _environment, address_displacement( _environment, _other, "1" )  );

    no_embedded( cpu_math_add_16bit_const )

}

void sc61860_math_add_16bit_with_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit_with_16bit )

        MAKE_LABEL

        op_lda( _environment, _source );

        op_xab( _environment );

        op_lda_address_low( _environment, _destination );     

        op_addab( _environment );

        op_sta( _environment, _other );

        op_lda( _environment, address_displacement( _environment, _source, "1" ) );

        op_xab( _environment );

        op_lda_address_high( _environment, _destination );     

        op_addabc( _environment );

        op_sta( _environment, address_displacement( _environment, _other, "1" )  );

    no_embedded( cpu_math_add_16bit_with_16bit )

}

/**
 * @brief <i>SC616860</i>: emit code to double a 16 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sc61860_math_double_16bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    if ( _signed ) {

        op_ldab( _environment, _source );
        op_xab( _environment );
        op_clc( _environment );
        op_sla( _environment );
        op_xab( _environment );
        op_sla( _environment );
        op_anda_direct( _environment, 0x7f );
        if ( _other ) {
            op_stab( _environment, _other );
        } else {
            op_stab( _environment, _source );
        }

    } else {

        op_ldab( _environment, _source );
        op_xab( _environment );
        op_clc( _environment );
        op_sla( _environment );
        op_xab( _environment );
        op_sla( _environment );
        if ( _other ) {
            op_stab( _environment, _other );
        } else {
            op_stab( _environment, _source );
        }
    }

}

/**
 * @brief <i>SC616860</i>: emit code to multiply two 16 bit values in a 32 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (16 bit)
 * @param _destination Second value to multipy (16 bit)
 * @param _other Destination address for result (32 bit)
 */
void sc61860_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_math_mul_8bit_to_16bit ) // aliasing

    embedded( cpu_math_mul_8bit_to_16bit, src_hw_sc61860_cpu_math_mul_8bit_to_16bit_asm );

        if ( _signed ) {

            CRITICAL_UNIMPLEMENTED( "sc61860_math_mul_16bit_to_32bit(signed)" );

            // outline1("LD IX, (%s)", _source );
            // outline1("LD IY, (%s)", _destination );
            // outline0("CALL CPUMUL16B16T32S")
            // outline1("LD (%s), HL", _other );
            // outline1("LD (%s), BC", address_displacement( _environment, _other, "2" ) );

        } else {

            MAKE_LABEL

            op_ldij( _environment, _source );

            op_ldab( _environment, _destination );

            op_call( _environment, "CPUMUL16B16T16U");
            
            op_stab( _environment, _other );

        }

    done(  )

}

/**
 * @brief <i>SC616860</i>: emit code to subtract two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sc61860_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_16bit )

        MAKE_LABEL

        op_lda( _environment, _source );

        op_xab( _environment );

        op_lda( _environment, _destination );     

        op_subab( _environment );

        if ( _other ) {
            op_sta( _environment, _other );
        } else {
            op_sta( _environment, _destination );
        }

        op_lda( _environment, address_displacement( _environment, _source, "1" ) );

        op_xab( _environment );

        op_lda( _environment, address_displacement( _environment, _destination, "1" ) );     

        op_subabc( _environment );

        if ( _other ) {
            op_sta( _environment, address_displacement( _environment, _other, "1" )  );
        } else {
            op_sta( _environment, address_displacement( _environment, _destination, "1" ) );
        }

    no_embedded( cpu_math_sub_16bit )

}

/**
 * @brief <i>SC616860</i>: emit code to calculate a 16 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void sc61860_math_complement_const_16bit( Environment * _environment, char *_source, int _value ) {

    op_lda( _environment, _source );

    op_ldab( _environment, _source );

    op_lda_direct( _environment, _value & 0xff );

    op_subab( _environment );

    op_sta( _environment, _source );

    op_ldab( _environment, address_displacement( _environment, _source, "1" ) );

    op_lda_direct( _environment, ( _value >> 8 ) );

    op_subabc( _environment );

    op_sta( _environment, address_displacement( _environment, _source, "1" ) );

}

/**
 * @brief <i>SC616860</i>: emit code to halves for several times a 16 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void sc61860_math_div2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

    MAKE_LABEL

    no_inline( cpu_math_div2_const_16bit )

    embedded( cpu_math_div2_const_16bit, src_hw_sc61860_cpu_math_div2_const_16bit_asm );

        if ( _remainder ) {
            op_lda( _environment, _source );
            op_anda_direct( _environment, 0x01 );
            op_sta( _environment, _remainder );
        }

        if ( _signed ) {

            op_ldi_direct( _environment, _steps );

            op_ldab( _environment, _source );

            op_call( _environment, "CPUDIV2CONST16S" );

            op_stab( _environment, _source );

        } else {

            op_ldi_direct( _environment, _steps );

            op_ldab( _environment, _source );

            op_call( _environment, "CPUDIV2CONST16U" );

            op_stab( _environment, _source );

        }

    done(  )

}

/**
 * @brief <i>SC616860</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void sc61860_math_mul2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

MAKE_LABEL

    no_inline( cpu_math_mul2_const_16bit )

    embedded( cpu_math_mul2_const_16bit, src_hw_sc61860_cpu_math_mul2_const_16bit_asm );

        if ( _signed ) {

            op_ldi_direct( _environment, _steps );

            op_ldab( _environment, _source );

            op_call( _environment, "CPUMUL2CONST16S" );

            op_stab( _environment, _source );

        } else {

            op_ldi_direct( _environment, _steps );

            op_ldab( _environment, _source );

            op_call( _environment, "CPUMUL2CONST16U" );

            op_stab( _environment, _source );

        }

    done(  )
}

/**
 * @brief <i>SC616860</i>: emit code to mask with "and" a value of 16 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void sc61860_math_and_const_16bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_16bit )

        op_ldab( _environment, _source );

        op_anda_direct( _environment, _mask >> 8 );

        op_swab( _environment );

        op_anda_direct( _environment, _mask );

        op_swab( _environment );

        op_stab( _environment, _source );

    no_embedded( cpu_math_and_const_16bit )

}

/*****************************************************************************
 * 32 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>SC616860</i>: emit code to move 32 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void sc61860_move_32bit( Environment * _environment, char *_source, char *_destination ) {

    inline( cpu_move_16bit )

        op_lda( _environment, _source );

        op_sta( _environment, _destination );

        op_lda( _environment, address_displacement( _environment, _source, "1" ) );

        op_sta( _environment, address_displacement( _environment, _destination, "1" ) );

        op_lda( _environment, address_displacement( _environment, _source, "2" ) );

        op_sta( _environment, address_displacement( _environment, _destination, "2" ) );

        op_lda( _environment, address_displacement( _environment, _source, "3" ) );

        op_sta( _environment, address_displacement( _environment, _destination, "3" ) );

    no_embedded( cpu_move_16bit )

}

/**
 * @brief <i>SC616860</i>: emit code to store 32 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void sc61860_store_32bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_16bit )

        op_lda_direct( _environment, _value );

        op_sta( _environment, _destination );

        op_lda_direct( _environment, (_value >> 8) );

        op_sta( _environment, address_displacement( _environment, _destination, "1" ) );

        op_lda_direct( _environment, (_value >> 16) );

        op_sta( _environment, address_displacement( _environment, _destination, "2" ) );

        op_lda_direct( _environment, (_value >> 24) );

        op_sta( _environment, address_displacement( _environment, _destination, "3" ) );

    no_embedded( cpu_store_16bit )

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Meaning of comparison
 */
void sc61860_compare_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    no_inline( cpu_compare_32bit )

    embedded( cpu_compare_32bit, src_hw_sc61860_cpu_compare_32bit_asm )

        op_ldx_direct( _environment, (0xff*_positive)||(0xff00*(1-_positive)) );

        op_ldijab( _environment, _source );
        op_ldklmn( _environment, _destination );

        op_call( _environment, "CPUCOMPARE32");
        if ( _other ) {
            op_sta( _environment, _other );
        } else {
            op_sta( _environment, _destination );
        }

    done( )

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Meaning of comparison
 */
void sc61860_compare_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

    MAKE_LABEL

    no_inline( cpu_compare_32bit )

    embedded( cpu_compare_32bit, src_hw_sc61860_cpu_compare_32bit_asm )

        op_ldx_direct( _environment, (0xff*_positive)||(0xff00*(1-_positive)) );

        op_ldijab( _environment, _source );
        op_ldklmn_direct( _environment, _destination );

        op_call( _environment, "CPUCOMPARE32");
        op_sta( _environment, _other );

    done( )
    
}

/**
 * @brief <i>SC616860</i>: emit code to compare two 32 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void sc61860_compare_and_branch_32bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    no_inline( cpu_compare_32bit )

    embedded( cpu_compare_32bit, src_hw_sc61860_cpu_compare_32bit_asm )

        MAKE_LABEL
        
        op_ldx_direct( _environment, (0xff*_positive)||(0xff00*(1-_positive)) );

        op_ldijab( _environment, _source );
        op_ldklmn_direct( _environment, _destination );

        op_call( _environment, "CPUCOMPARE32");
        op_cp_direct( _environment, (0xff*_positive) );
        op_jnz( _environment, label );
        op_jp( _environment, _label );
        outhead1("%s", label );

    done( )

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void sc61860_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_32bit )

    embedded( cpu_less_than_32bit, src_hw_sc61860_cpu_less_than_32bit_asm );

        if ( _signed ) {

            CRITICAL_UNIMPLEMENTED( "sc61860_less_than_32bit(signed)" );

        } else {

            op_ldijab( _environment, _source );

            op_ldklmn( _environment, _destination );

            if ( _equal ) {
                op_call( _environment, "CPULTE32U" );
            } else {
                op_call( _environment, "CPULT32U" );
            }

            if ( _other ) {
                op_sta( _environment, _other );
            } else {
                op_sta( _environment, _destination );
            }

        }

    done(  )

}

void sc61860_less_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_32bit )

    embedded( cpu_less_than_32bit, src_hw_sc61860_cpu_less_than_32bit_asm );

        if ( _signed ) {

            CRITICAL_UNIMPLEMENTED( "sc61860_less_than_32bit_const(signed)" );

        } else {

            op_ldijab( _environment, _source );

            op_ldklmn_direct( _environment, _destination );

            if ( _equal ) {
                op_call( _environment, "CPULTE32U" );
            } else {
                op_call( _environment, "CPULT32U" );
            }

            op_sta( _environment, _other );

        }

    done(  )

}

/**
 * @brief <i>SC616860</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void sc61860_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    sc61860_less_than_32bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        sc61860_not_8bit( _environment, _other, _other );
    } else {
        sc61860_not_8bit( _environment, _destination, _destination );
    }

}

void sc61860_greater_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    sc61860_less_than_32bit_const( _environment, _source, _destination, _other, !_equal, _signed );
    sc61860_not_8bit( _environment, _other, _other );

}

/**
 * @brief <i>SC616860</i>: emit code to add two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sc61860_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit )

        MAKE_LABEL

        op_lda( _environment, _source );

        op_xab( _environment );

        op_lda( _environment, _destination );     

        op_addab( _environment );

        if ( _other ) {
            op_sta( _environment, _other );
        } else {
            op_sta( _environment, _destination );
        }

        op_lda( _environment, address_displacement( _environment, _source, "1" ) );

        op_xab( _environment );

        op_lda( _environment, address_displacement( _environment, _destination, "1" ) );     

        op_addabc( _environment );

        if ( _other ) {
            op_sta( _environment, address_displacement( _environment, _other, "1" )  );
        } else {
            op_sta( _environment, address_displacement( _environment, _destination, "1" ) );
        }

        op_lda( _environment, address_displacement( _environment, _source, "2" ) );

        op_xab( _environment );

        op_lda( _environment, address_displacement( _environment, _destination, "2" ) );     

        op_addabc( _environment );

        if ( _other ) {
            op_sta( _environment, address_displacement( _environment, _other, "2" )  );
        } else {
            op_sta( _environment, address_displacement( _environment, _destination, "2" ) );
        }
        
        op_lda( _environment, address_displacement( _environment, _source, "3" ) );

        op_xab( _environment );

        op_lda( _environment, address_displacement( _environment, _destination, "3" ) );     

        op_addabc( _environment );

        if ( _other ) {
            op_sta( _environment, address_displacement( _environment, _other, "3" )  );
        } else {
            op_sta( _environment, address_displacement( _environment, _destination, "3" ) );
        }

    no_embedded( cpu_math_add_16bit )

}

void sc61860_math_add_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_16bit )

        MAKE_LABEL

        op_lda( _environment, _source );

        op_xab( _environment );

        op_lda_direct( _environment, _destination );     

        op_addab( _environment );

        op_sta( _environment, _other );

        op_lda( _environment, address_displacement( _environment, _source, "1" ) );

        op_xab( _environment );

        op_lda_direct( _environment,_destination >> 8 );     

        op_addabc( _environment );

        op_sta( _environment, address_displacement( _environment, _other, "1" )  );

        op_lda( _environment, address_displacement( _environment, _source, "2" ) );

        op_xab( _environment );

        op_lda_direct( _environment,_destination >> 16 );

        op_addabc( _environment );

        op_sta( _environment, address_displacement( _environment, _other, "2" )  );
        
        op_lda( _environment, address_displacement( _environment, _source, "3" ) );

        op_xab( _environment );

        op_lda_direct( _environment,_destination >> 24 );

        op_addabc( _environment );

        op_sta( _environment, address_displacement( _environment, _other, "3" )  );

    no_embedded( cpu_math_add_16bit )

}

/**
 * @brief <i>SC616860</i>: emit code to double a 32 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 * @todo Not yet implemented
 */
void sc61860_math_double_32bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    if ( _other ) {
        sc61860_math_add_32bit( _environment, _source, _source, _other );
    } else {
        sc61860_math_add_32bit( _environment, _source, _source, _source );
    }

}

/**
 * @brief <i>SC616860</i>: emit code to subtract two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sc61860_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_16bit )

        MAKE_LABEL

        op_lda( _environment, _source );

        op_xab( _environment );

        op_lda( _environment, _destination );     

        op_subab( _environment );

        if ( _other ) {
            op_sta( _environment, _other );
        } else {
            op_sta( _environment, _destination );
        }

        op_lda( _environment, address_displacement( _environment, _source, "1" ) );

        op_xab( _environment );

        op_lda( _environment, address_displacement( _environment, _destination, "1" ) );     

        op_subabc( _environment );

        if ( _other ) {
            op_sta( _environment, address_displacement( _environment, _other, "1" )  );
        } else {
            op_sta( _environment, address_displacement( _environment, _destination, "1" ) );
        }

        op_lda( _environment, address_displacement( _environment, _source, "2" ) );

        op_xab( _environment );

        op_lda( _environment, address_displacement( _environment, _destination, "2" ) );     

        op_subabc( _environment );

        if ( _other ) {
            op_sta( _environment, address_displacement( _environment, _other, "2" )  );
        } else {
            op_sta( _environment, address_displacement( _environment, _destination, "2" ) );
        }

        op_lda( _environment, address_displacement( _environment, _source, "3" ) );

        op_xab( _environment );

        op_lda( _environment, address_displacement( _environment, _destination, "3" ) );

        op_subabc( _environment );

        if ( _other ) {
            op_sta( _environment, address_displacement( _environment, _other, "3" )  );
        } else {
            op_sta( _environment, address_displacement( _environment, _destination, "3" ) );
        }

    no_embedded( cpu_math_sub_16bit )

}

/**
 * @brief <i>SC616860</i>: emit code to calculate a 32 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void sc61860_math_complement_const_32bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_sub_16bit )

        MAKE_LABEL

        op_lda( _environment, _source );

        op_xab( _environment );

        op_lda_direct( _environment, _value );     

        op_subab( _environment );

        op_sta( _environment, _source );

        op_lda( _environment, address_displacement( _environment, _source, "1" ) );

        op_xab( _environment );

        op_lda_direct( _environment, _value >> 8 );     

        op_subabc( _environment );

        op_sta( _environment, address_displacement( _environment, _source, "1" )  );

        op_lda( _environment, address_displacement( _environment, _source, "2" ) );

        op_xab( _environment );

        op_lda_direct( _environment, _value >> 16 );

        op_subabc( _environment );

        op_sta( _environment, address_displacement( _environment, _source, "2" ) );

        op_lda( _environment, address_displacement( _environment, _source, "3" ) );

        op_xab( _environment );

        op_lda_direct( _environment, _value >> 24 );

        op_subabc( _environment );

        op_sta( _environment, address_displacement( _environment, _source, "3" )  );

    no_embedded( cpu_math_sub_16bit )
}

/**
 * @brief <i>SC616860</i>: emit code to halves for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void sc61860_math_div2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

    MAKE_LABEL

    if ( _remainder ) {
        op_lda( _environment, _source );
        op_anda_direct( _environment, 0x01 );
        op_sta( _environment, _remainder );
    }

    if ( _signed ) {

        CRITICAL_UNIMPLEMENTED( "sc61860_math_div2_const_16bit(signed)" );

    } else {

        while( _steps ) {
            op_ldab( _environment, _source );
            op_swab( _environment );
            op_sra( _environment );
            op_swab( _environment );
            op_sra( _environment );
            op_stab( _environment, _source );
            op_ldab( _environment, address_displacement( _environment, _source, "2" ) );
            op_swab( _environment );
            op_sra( _environment );
            op_swab( _environment );
            op_sra( _environment );
            op_stab( _environment, address_displacement( _environment, _source, "2" ) );
            --_steps;
        }
        
    }

}

/**
 * @brief <i>SC616860</i>: emit code to double for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 * @todo Not yet implemented
 */
void sc61860_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        CRITICAL_UNIMPLEMENTED( "sc61860_math_div2_const_16bit(signed)" );

    } else {

        while( _steps ) {
            op_ldab( _environment, _source );
            op_sla( _environment );
            op_swab( _environment );
            op_sla( _environment );
            op_swab( _environment );
            op_stab( _environment, _source );
            op_ldab( _environment, address_displacement( _environment, _source, "2" ) );
            op_sla( _environment );
            op_swab( _environment );
            op_sla( _environment );
            op_swab( _environment );
            op_stab( _environment, address_displacement( _environment, _source, "2" ) );
            --_steps;
        }

    }
    
}

/**
 * @brief <i>SC616860</i>: emit code to mask with "and" a value of 32 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 * @todo Not yet implemented
 */
void sc61860_math_and_const_32bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_32bit )

        op_ldab( _environment, _source );

        op_anda_direct( _environment, _mask >> 8 );

        op_swab( _environment );

        op_anda_direct( _environment, _mask );

        op_swab( _environment );

        op_stab( _environment, _source );

        op_ldab( _environment, address_displacement( _environment, _source, "2" ) );

        op_anda_direct( _environment, _mask >> 24 );

        op_swab( _environment );

        op_anda_direct( _environment, _mask >> 16 );

        op_swab( _environment );

        op_stab( _environment, address_displacement( _environment, _source, "2" ) );

    no_embedded( cpu_math_and_const_32bit )

}

/**
 * @brief <i>SC616860</i>: emit code to combine nibbles
 * 
 * @todo Not yet implemented
 */
void sc61860_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_combine_nibbles" );

}

void sc61860_jump( Environment * _environment, char * _label ) {

    outline1("JP %s", _label );

}

void sc61860_call_addr( Environment * _environment, int _address ) {

    outline1("CALL 0x%4.4x", _address );

}

void sc61860_call( Environment * _environment, char * _label ) {

    outline1("CALL %s", _label );

}

void sc61860_call_indirect( Environment * _environment, char * _value ) {

    MAKE_LABEL

    char indirectLabel[MAX_TEMPORARY_STORAGE]; sprintf( indirectLabel, "%sindirect", label );

    sc61860_jump( _environment, label );
    sc61860_label( _environment, indirectLabel );
    sc61860_jump( _environment, "0x0000" );
    sc61860_label( _environment, label );
    op_ldab( _environment, _value );
    op_stab( _environment, address_displacement( _environment, indirectLabel, "1" ) );
    sc61860_call( _environment, indirectLabel );

}

void sc61860_jump_indirect( Environment * _environment, char * _value ) {

    MAKE_LABEL

    char indirectLabel[MAX_TEMPORARY_STORAGE]; sprintf( indirectLabel, "%sindirect", label );

    sc61860_jump( _environment, label );

    sc61860_label( _environment, indirectLabel );
    sc61860_jump( _environment, "0x0000" );

    sc61860_label( _environment, label );
    op_ldab( _environment, _value );
    op_stab( _environment, address_displacement( _environment, indirectLabel, "1" ) );
    sc61860_jump( _environment, indirectLabel );

}

int sc61860_register_decode( Environment * _environment, char * _register ) {

    SC61860Register result = REGISTER_NONE;

    if ( !_environment->emptyProcedure ) {

        if ( strcmp( _register, "A" ) == 0 ) {
            result = REGISTER_A;
        } else if ( strcmp( _register, "B" ) == 0 ) {
            result = REGISTER_B;
        } else if ( strcmp( _register, "XL" ) == 0 ) {
            result = REGISTER_XL;
        } else if ( strcmp( _register, "XH" ) == 0 ) {
            result = REGISTER_XH;
        } else if ( strcmp( _register, "YL" ) == 0 ) {
            result = REGISTER_YL;
        } else if ( strcmp( _register, "YH" ) == 0 ) {
            result = REGISTER_YH;
        } else if ( strcmp( _register, "K" ) == 0 ) {
            result = REGISTER_K;
        } else if ( strcmp( _register, "L" ) == 0 ) {
            result = REGISTER_L;
        } else if ( strcmp( _register, "M" ) == 0 ) {
            result = REGISTER_M;
        } else if ( strcmp( _register, "N" ) == 0 ) {
            result = REGISTER_N;
        } else {

        }

    }

    return (int)result;

}

void sc61860_set_asmio( Environment * _environment, int _asmio, int _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        SC61860Register reg = (SC61860Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
            case REGISTER_J:
                op_ldj_direct( _environment, _value );
                break;
            case REGISTER_A:
                op_lda_direct( _environment, _value );
                break;
            case REGISTER_B:
                op_ldb_direct( _environment, _value );
                break;
            case REGISTER_XL:
                op_push( _environment );
                op_ldxl_direct( _environment, _value );
                op_pop( _environment );
                break;
            case REGISTER_XH:
                op_push( _environment );
                op_ldxh_direct( _environment, _value );
                op_pop( _environment );
                break;
            case REGISTER_YL:
                op_push( _environment );
                op_ldyl_direct( _environment, _value );
                op_pop( _environment );
                break;
            case REGISTER_YH:
                op_push( _environment );
                op_ldyh_direct( _environment, _value );
                op_pop( _environment );
                break;
            case REGISTER_K:
                op_push( _environment );
                op_ldk_direct( _environment, _value );
                op_pop( _environment );
                break;
            case REGISTER_L:
                op_push( _environment );
                op_ldl_direct( _environment, _value );
                op_pop( _environment );
                break;
            case REGISTER_M:
                op_push( _environment );
                op_ldm_direct( _environment, _value );
                op_pop( _environment );
                break;
            case REGISTER_N:
                op_push( _environment );
                op_ldn_direct( _environment, _value );
                op_pop( _environment );
                break;
        }

    } else {

        SC61860Stack stk = (SC61860Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                op_lda_direct( _environment, _value );
                op_push( _environment );
                break;
            case STACK_WORD:
                op_lda_direct( _environment, _value );
                op_push( _environment );
                op_lda_direct( _environment, _value >> 8 );
                op_push( _environment );
                break;
            case STACK_DWORD:
                op_lda_direct( _environment, _value );
                op_push( _environment );
                op_lda_direct( _environment, _value >> 8 );
                op_push( _environment );
                op_lda_direct( _environment, _value >> 16 );
                op_push( _environment );
                op_lda_direct( _environment, _value >> 24 );
                op_push( _environment );
                break;
        }

    }

}

void sc61860_set_asmio_indirect( Environment * _environment, int _asmio, char * _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        SC61860Register reg = (SC61860Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
            case REGISTER_J:
                op_ldj( _environment, _value );
                break;
            case REGISTER_A:
                op_lda( _environment, _value );
                break;
            case REGISTER_B:
                op_ldb( _environment, _value );
                break;
            case REGISTER_XL:
                op_ldxl( _environment, _value );
                break;
            case REGISTER_XH:
                op_ldxh( _environment, _value );
                break;
            case REGISTER_YL:
                op_ldyl( _environment, _value );
                break;
            case REGISTER_YH:
                op_ldyh( _environment, _value );
                break;
            case REGISTER_K:
                op_ldk( _environment, _value );
                break;
            case REGISTER_L:
                op_ldl( _environment, _value );
                break;
            case REGISTER_M:
                op_ldm( _environment, _value );
                break;
            case REGISTER_N:
                op_ldn( _environment, _value );
                break;
        }

    } else {

        SC61860Stack stk = (SC61860Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                op_lda( _environment, _value );
                op_push( _environment );
                break;
            case STACK_WORD:
                op_lda( _environment, _value );
                op_push( _environment );
                op_lda( _environment, address_displacement( _environment, _value, "1" ) );
                op_push( _environment );
                break;
            case STACK_DWORD:
                op_lda( _environment, _value );
                op_push( _environment );
                op_lda( _environment, address_displacement( _environment, _value, "1" ) );
                op_push( _environment );
                op_lda( _environment, address_displacement( _environment, _value, "2" ) );
                op_push( _environment );
                op_lda( _environment, address_displacement( _environment, _value, "3" ) );
                op_push( _environment );
                break;
        }

    }

}

void sc61860_get_asmio_indirect( Environment * _environment, int _asmio, char * _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        SC61860Register reg = (SC61860Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
            case REGISTER_I:
                op_sti( _environment, _value );
                break;
            case REGISTER_J:
                op_stj( _environment, _value );
                break;
            case REGISTER_A:
                op_sta( _environment, _value );
                break;
            case REGISTER_B:
                op_stb( _environment, _value );
                break;
            case REGISTER_XL:
                op_stxl( _environment, _value );
                break;
            case REGISTER_XH:
                op_stxh( _environment, _value );
                break;
            case REGISTER_YL:
                op_styl( _environment, _value );
                break;
            case REGISTER_YH:
                op_styh( _environment, _value );
                break;
            case REGISTER_K:
                op_stk( _environment, _value );
                break;
            case REGISTER_L:
                op_stl( _environment, _value );
                break;
            case REGISTER_M:
                op_stm( _environment, _value );
                break;
            case REGISTER_N:
                op_stn( _environment, _value );
                break;
        }

    } else {

        SC61860Stack stk = (SC61860Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                op_lda( _environment, _value );
                op_push( _environment );
                break;
            case STACK_WORD:
                op_lda( _environment, _value );
                op_push( _environment );
                op_lda( _environment, address_displacement( _environment, _value, "1" ) );
                op_push( _environment );
                break;
            case STACK_DWORD:
                op_lda( _environment, _value );
                op_push( _environment );
                op_lda( _environment, address_displacement( _environment, _value, "1" ) );
                op_push( _environment );
                op_lda( _environment, address_displacement( _environment, _value, "2" ) );
                op_push( _environment );
                op_lda( _environment, address_displacement( _environment, _value, "3" ) );
                op_push( _environment );
                break;
        }

    }

}

void sc61860_return( Environment * _environment ) {

    outline0("RTN" );

}

void sc61860_pop( Environment * _environment ) {

    outline0("POP" );

}

void sc61860_halt( Environment * _environment ) {

    MAKE_LABEL

    outhead1("%s:", label );
    outline1("JP %s", label );

}

void sc61860_end( Environment * _environment ) {

    sc61860_halt( _environment );

}

void sc61860_random( Environment * _environment, char * _entropy ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_random" );

    MAKE_LABEL

    // inline( cpu_random )

        if ( _entropy ) {
            // outline0("LD HL, (CPURANDOM_SEED)");
            // outline0("LD B, (HL)");
            // outline0("INC HL");
            // outline0("LD A, (HL)");
            // outline0("XOR B");
            // outline1("LD DE, (%s)", _entropy);
            // // outline0("LD B, H");
            // outline0("LD C, L");
            // outline0("ADD HL, HL");
            // outline0("RL E");
            // outline0("RL D");
            // outline0("ADD HL, DE");
            // outline0("RL E");
            // outline0("RL D");
            // outline0("INC L");
            // outline0("ADD HL, BC");
            // outline0("LD (CPURANDOM_SEED), HL");
            // outline0("LD HL, (CPURANDOM_SEED+2)");
            // outline0("ADD HL, DE");
            // outline0("LD (CPURANDOM_SEED+1), HL");
            // outline0("EX DE, HL");
            // outline0("LD HL, (CPURANDOM_SEED)");
            // outline1("LD DE, (%s)", _entropy);
            // outline0("ADD HL, HL");
            // outline0("RL C");
            // outline0("RL B");
            // outline0("LD (CPURANDOM_SEED+1), BC");
            // outline0("SBC A, A");
            // outline0("AND %11000101");
            // outline0("XOR L");
            // outline0("LD L, A");
            // outline0("LD (CPURANDOM_SEED+1), HL");
            // outline0("EX DE, HL");
            // outline0("ADD HL, BC");
        }

    // embedded( cpu_random, src_hw_sc61860_cpu_random_asm );
       
    // done()


}

void sc61860_random_8bit( Environment * _environment, char * _entropy, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_random_8bit" );

    sc61860_random( _environment, _entropy );

    if ( _result ) {
        // outline0("CALL CPURANDOM16" );
        // outline0("LD A, H" );
        // outline1("LD (%s), A", _result );
    }

}

void sc61860_random_16bit( Environment * _environment, char * _entropy, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_random_16bit" );

    sc61860_random( _environment, _entropy );

    if ( _result ) {
        // outline0("CALL CPURANDOM16" );
        // outline1("LD (%s), HL", _result );
    }

}

void sc61860_random_32bit( Environment * _environment, char * _entropy, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_random_32bit" );

    sc61860_random( _environment, _entropy );

    if ( _result ) {
        // outline0("CALL CPURANDOM32" );
        // outline1("LD (%s), HL", _result );
        // outline1("LD (%s), BC", address_displacement( _environment, _result, "2" ) );
    }

}

void sc61860_limit_16bit( Environment * _environment, char * _variable, int _value ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_limit_16bit" );

    MAKE_LABEL

    // outline1( "LD A, (%s)", _variable );
    // outline1( "CP 0x%2.2x", _value );
    // outline1( "JR C, %s", label );
    // outline1( "SUB 0x%2.2x", _value );
    // outline1( "LD (%s), A", _variable );
    // outhead1( "%s:", label );

}

void sc61860_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    char waitLabel[MAX_TEMPORARY_STORAGE];
    sprintf( waitLabel, "%swait", label );
    char waitValueLabel[MAX_TEMPORARY_STORAGE];
    sprintf( waitValueLabel, "%swait+1", label );

    op_lda( _environment, _timing );
    op_sta( _environment, waitValueLabel );
    outhead1("%s:", waitLabel );
    op_wait_direct( _environment, 0 );

}

/**
 * @brief <i>SC616860</i>: emit code to send one byte throught a I/O port
 * 
 * @param _environment Current calling environment
 * @param _port Port to connect
 * @param _value Value to send
 */
void sc61860_port_out( Environment * _environment, char * _port, char * _value ) {

    // outline1("LD A, (%s)", _value );
    // outline1("OUT (%s), A", _port );

}

void sc61860_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    char doneLabel[MAX_TEMPORARY_STORAGE];
    sprintf( doneLabel, "%sdone", label );

    op_lda( _environment, _left );
    op_cp_direct( _environment, 0 );
    op_jz( _environment, label );
    op_lda( _environment, _right );
    op_cp_direct( _environment, 0 );
    op_jz( _environment, label );
    op_lda_direct( _environment, 0xff );
    op_sta( _environment, _result );
    op_jp( _environment, doneLabel );
    sc61860_label( _environment, label );
    op_lda_direct( _environment, 0 );
    op_sta( _environment, _result );
    sc61860_label( _environment, doneLabel );

}

void sc61860_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    op_ldb( _environment, _right );
    op_lda( _environment, _left );
    op_andab( _environment );
    op_stb( _environment, _result );

}

void sc61860_and_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    op_ldb_direct( _environment, _right );
    op_lda( _environment, _left );
    op_andab( _environment );
    op_stb( _environment, _result );

}

void sc61860_and_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    sc61860_and_8bit( _environment, _left, _right, _result );
    sc61860_and_8bit( _environment, address_displacement( _environment, _left, "1" ), address_displacement( _environment, _right, "1" ), address_displacement( _environment, _result, "1" ) );

}

void sc61860_and_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    sc61860_and_8bit( _environment, _left, _right, _result );
    sc61860_and_8bit( _environment, address_displacement( _environment, _left, "1" ), address_displacement( _environment, _right, "1" ), address_displacement( _environment, _result, "1" ) );
    sc61860_and_8bit( _environment, address_displacement( _environment, _left, "2" ), address_displacement( _environment, _right, "2" ), address_displacement( _environment, _result, "2" ) );
    sc61860_and_8bit( _environment, address_displacement( _environment, _left, "3" ), address_displacement( _environment, _right, "2" ), address_displacement( _environment, _result, "3" ) );

}

void sc61860_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    char doneLabel[MAX_TEMPORARY_STORAGE];
    sprintf( doneLabel, "%sdone", label );

    op_lda( _environment, _left );
    op_cp_direct( _environment, 0 );
    op_jnz( _environment, label );
    op_lda( _environment, _right );
    op_cp_direct( _environment, 0 );
    op_jnz( _environment, label );
    op_lda_direct( _environment, 0 );
    op_sta( _environment, _result );
    op_jp( _environment, doneLabel );
    sc61860_label( _environment, label );
    op_lda_direct( _environment, 0xff );
    op_sta( _environment, _result );
    sc61860_label( _environment, doneLabel );
    
}

void sc61860_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    op_ldb( _environment, _right );
    op_lda( _environment, _left );
    op_orab( _environment );
    op_stb( _environment, _result );

}

void sc61860_or_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    op_ldb_direct( _environment, _right );
    op_lda( _environment, _left );
    op_orab( _environment );
    op_stb( _environment, _result );

}

void sc61860_or_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    sc61860_or_8bit( _environment, _left, _right, _result );
    sc61860_or_8bit( _environment, address_displacement( _environment, _left, "1" ), address_displacement( _environment, _right, "1" ), address_displacement( _environment, _result, "1" ) );

}

void sc61860_or_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    sc61860_or_8bit( _environment, _left, _right, _result );
    sc61860_or_8bit( _environment, address_displacement( _environment, _left, "1" ), address_displacement( _environment, _right, "1" ), address_displacement( _environment, _result, "1" ) );
    sc61860_or_8bit( _environment, address_displacement( _environment, _left, "2" ), address_displacement( _environment, _right, "2" ), address_displacement( _environment, _result, "2" ) );
    sc61860_or_8bit( _environment, address_displacement( _environment, _left, "3" ), address_displacement( _environment, _right, "2" ), address_displacement( _environment, _result, "3" ) );

}

void sc61860_xor_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_xor_8bit" );

    MAKE_LABEL

    // outline1("LD HL, %s", _left );
    // outline1("LD IX, %s", _right );
    // outline1("LD DE, %s", _result );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX)" );
    // outline0("LD (DE), A" );

}

void sc61860_xor_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_xor_8bit_const" );

    MAKE_LABEL

    // outline1("LD HL, %s", _left );
    // outline1("LD IX, %s", _right );
    // outline1("LD DE, %s", _result );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX)" );
    // outline0("LD (DE), A" );

}

void sc61860_xor_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_xor_16bit" );

    MAKE_LABEL

    // outline1("LD HL, %s", _left );
    // outline1("LD IX, %s", _right );
    // outline1("LD DE, %s", _result );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX)" );
    // outline0("LD (DE), A" );
    // outline0("INC HL" );
    // outline0("INC DE" );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX+1)" );
    // outline0("LD (DE), A" );
    // outline0("INC HL" );
    // outline0("INC DE" );

}

void sc61860_xor_16bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_xor_16bit_const" );

    MAKE_LABEL

    // outline1("LD HL, %s", _left );
    // outline1("LD IX, %s", _right );
    // outline1("LD DE, %s", _result );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX)" );
    // outline0("LD (DE), A" );
    // outline0("INC HL" );
    // outline0("INC DE" );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX+1)" );
    // outline0("LD (DE), A" );
    // outline0("INC HL" );
    // outline0("INC DE" );

}

void sc61860_xor_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_xor_32bit" );

    MAKE_LABEL

    // outline1("LD HL, %s", _left );
    // outline1("LD IX, %s", _right );
    // outline1("LD DE, %s", _result );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX)" );
    // outline0("LD (DE), A" );
    // outline0("INC HL" );
    // outline0("INC DE" );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX+1)" );
    // outline0("LD (DE), A" );
    // outline0("INC HL" );
    // outline0("INC DE" );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX+2)" );
    // outline0("LD (DE), A" );
    // outline0("INC HL" );
    // outline0("INC DE" );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX+3)" );
    // outline0("LD (DE), A" );

}

void sc61860_xor_32bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_xor_32bit_const" );

    MAKE_LABEL

    // outline1("LD HL, %s", _left );
    // outline1("LD IX, %s", _right );
    // outline1("LD DE, %s", _result );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX)" );
    // outline0("LD (DE), A" );
    // outline0("INC HL" );
    // outline0("INC DE" );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX+1)" );
    // outline0("LD (DE), A" );
    // outline0("INC HL" );
    // outline0("INC DE" );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX+2)" );
    // outline0("LD (DE), A" );
    // outline0("INC HL" );
    // outline0("INC DE" );
    // outline0("LD A, (HL)" );
    // outline0("XOR (IX+3)" );
    // outline0("LD (DE), A" );

}

void sc61860_swap_8bit( Environment * _environment, char * _left, char * _right ) {

    op_lda( _environment, _left );
    op_ldb( _environment, _right );
    op_xab( _environment );
    op_sta( _environment, _left );
    op_sta( _environment, _right );

}    

void sc61860_swap_16bit( Environment * _environment, char * _left, char * _right ) {

    sc61860_swap_8bit( _environment, _left,  _right );
    sc61860_swap_8bit( _environment, address_displacement( _environment, _left, "1" ),  address_displacement( _environment, _right, "1" ) );

}

void sc61860_swap_32bit( Environment * _environment, char * _left, char * _right ) {

    sc61860_swap_8bit( _environment, _left,  _right );
    sc61860_swap_8bit( _environment, address_displacement( _environment, _left, "1" ),  address_displacement( _environment, _right, "1" ) );
    sc61860_swap_8bit( _environment, address_displacement( _environment, _left, "2" ),  address_displacement( _environment, _right, "2" ) );
    sc61860_swap_8bit( _environment, address_displacement( _environment, _left, "3" ),  address_displacement( _environment, _right, "3" ) );
    
}

void sc61860_logical_not_8bit( Environment * _environment, char * _value, char * _result ) {

    // NOT(A) = (-1) - A

    op_lda_direct( _environment, 0xff );
    op_xab( _environment );
    op_lda( _environment, _value );
    op_subab( _environment );
    op_sta( _environment, _result );

}

void sc61860_not_8bit( Environment * _environment, char * _value, char * _result ) {

    op_lda_direct( _environment, 0xff );
    op_xab( _environment );
    op_lda( _environment, _value );
    op_subab( _environment );
    op_sta( _environment, _result );

}

void sc61860_not_16bit( Environment * _environment, char * _value, char * _result ) {

    sc61860_not_8bit( _environment, _value, _result );
    sc61860_not_8bit( _environment, address_displacement( _environment, _value, "1" ), address_displacement( _environment, _result, "1" ) );

}

void sc61860_not_32bit( Environment * _environment, char * _value, char * _result ) {

    sc61860_not_8bit( _environment, _value, _result );
    sc61860_not_8bit( _environment, address_displacement( _environment, _value, "1" ), address_displacement( _environment, _result, "1" ) );
    sc61860_not_8bit( _environment, address_displacement( _environment, _value, "2" ), address_displacement( _environment, _result, "2" ) );
    sc61860_not_8bit( _environment, address_displacement( _environment, _value, "3" ), address_displacement( _environment, _result, "3" ) );

}

void sc61860_di( Environment * _environment ) {

    // outline0("DI" );

}

void sc61860_ei( Environment * _environment ) {

    // outline0("EI" );

}

void sc61860_inc( Environment * _environment, char * _variable ) {

    op_lda( _environment, _variable );
    op_inca( _environment );
    op_sta( _environment, _variable );

}

void sc61860_dec( Environment * _environment, char * _variable ) {

    op_lda( _environment, _variable );
    op_deca( _environment );
    op_sta( _environment, _variable );

}

void sc61860_inc_16bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    op_lda( _environment, _variable );
    op_inca( _environment );
    op_sta( _environment, _variable );
    op_cp_direct( _environment, 0 );
    op_jnz( _environment, label );
    op_lda( _environment, address_displacement( _environment, _variable, "1" ) );
    op_inca( _environment );
    op_sta( _environment, address_displacement( _environment, _variable, "1" ) );
    outhead1("%s:", label );

}

void sc61860_inc_32bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    op_lda( _environment, _variable );
    op_inca( _environment );
    op_sta( _environment, _variable );
    op_cp_direct( _environment, 0 );
    op_jnz( _environment, label );

    op_lda( _environment, address_displacement( _environment, _variable, "1" ) );
    op_inca( _environment );
    op_sta( _environment, address_displacement( _environment, _variable, "1" ) );
    op_cp_direct( _environment, 0 );
    op_jnz( _environment, label );

    op_lda( _environment, address_displacement( _environment, _variable, "2" ) );
    op_inca( _environment );
    op_sta( _environment, address_displacement( _environment, _variable, "2" ) );
    op_cp_direct( _environment, 0 );
    op_jnz( _environment, label );

    op_lda( _environment, address_displacement( _environment, _variable, "3" ) );
    op_inca( _environment );
    op_sta( _environment, address_displacement( _environment, _variable, "3" ) );

    outhead1("%s:", label );

}

void sc61860_dec_16bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    op_lda( _environment, _variable );
    op_deca( _environment );
    op_sta( _environment, _variable );
    op_cp_direct( _environment, 0xff );
    op_jnz( _environment, label );

    op_lda( _environment, address_displacement( _environment, _variable, "1" ) );
    op_deca( _environment );
    op_sta( _environment, address_displacement( _environment, _variable, "1" ) );
    op_cp_direct( _environment, 0 );
    op_jnz( _environment, label );

    outhead1("%s:", label );

}

void sc61860_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    MAKE_LABEL

    op_ldi( _environment, _size );
    op_ldx( _environment, _source );
    op_ldy( _environment, _destination );

    outline0("DX");
    outline0("DY");

    sc61860_label( _environment, label );
    outline0("IXL")
    outline0("LDD")
    outline0("IYL")
    outline0("STD")
    op_decinz( _environment, label );

}

void sc61860_mem_move_16bit( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    MAKE_LABEL

    op_ldij( _environment, _size );
    op_ldx( _environment, _source );
    op_ldy( _environment, _destination );

    outline0("DX");
    outline0("DY");

    sc61860_label( _environment, label );
    outline0("IXL")
    outline0("LDD")
    outline0("IYL")
    outline0("STD")
    op_decijnz( _environment, label );

}

void sc61860_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_mem_move_direct" );

    // deploy( duff, src_hw_sc61860_duff_asm );

    // outline1("LD HL, %s", _source);
    // outline1("LD DE, %s", _destination);
    // outline1("LD A, (%s)", _size);
    // outline0("LD C, A");
    // outline0("LD B, 0");
    // outline0("CALL DUFFDEVICE");

}

void sc61860_mem_move_direct2( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_mem_move_direct2" );

    // deploy( duff, src_hw_sc61860_duff_asm );

    // outline1("LD HL, (%s)", _source);
    // outline1("LD DE, %s", _destination);
    // outline1("LD BC, (%s)", _size);
    // outline0("CALL DUFFDEVICE");

}

void sc61860_mem_move_direct2_size( Environment * _environment, char *_source, char *_destination,  int _size ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_mem_move_direct2_size" );

    // deploy( duff, src_hw_sc61860_duff_asm );

    // outline1("LD HL, (%s)", _source);
    // outline1("LD DE, %s", _destination);
    // outline1("LD BC, 0x%4.4x", _size);
    // outline0("CALL DUFFDEVICE");

}

void sc61860_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size > 0 ) {

        MAKE_LABEL

        op_ldij_direct( _environment, _size );
        op_ldx( _environment, _source );
        op_ldy( _environment, _destination );

        outline0("DX");
        outline0("DY");

        sc61860_label( _environment, label );
        outline0("IXL")
        outline0("LDD")
        outline0("IYL")
        outline0("STD")
        op_decijnz( _environment, label );

    }

}

void sc61860_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_mem_move_direct_size" );

    if ( _size > 0 ) {

        // deploy( duff, src_hw_sc61860_duff_asm );

        // outline1("LD HL, %s", _source);
        // outline1("LD DE, %s", _destination);
        // outline1("LD A, 0x%2.2x", ( _size & 0xff ) );
        // outline0("LD C, A");
        // outline1("LD B, 0x%2.2x", ( _size >> 8 ) & 0xff );
        // outline0("CALL DUFFDEVICE");
    }

}

void sc61860_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_mem_move_direct_indirect_size" );

    if ( _size ) {

        // deploy( duff, src_hw_sc61860_duff_asm );

        // outline1("LD HL, %s", _source);
        // outline1("LD DE, (%s)", _destination);
        // outline1("LD A, 0x%2.2x", ( _size & 0xff ) );
        // outline0("LD C, A");
        // outline1("LD B, 0x%2.2x", ( _size >> 8 ) & 0xff );
        // outline0("CALL DUFFDEVICE");
    }

}

void sc61860_mem_move_indirect_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_mem_move_indirect_direct_size" );

    if ( _size ) {

        // deploy( duff, src_hw_sc61860_duff_asm );

        // outline1("LD HL, (%s)", _source);
        // outline1("LD DE, %s", _destination);
        // outline1("LD A, 0x%2.2x", ( _size & 0xff ) );
        // outline0("LD C, A");
        // outline1("LD B, 0x%2.2x", ( _size >> 8 ) & 0xff );
        // outline0("CALL DUFFDEVICE");
    }

}

void sc61860_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_compare_memory" );

    MAKE_LABEL

    // outline1("LD A, (%s)", _size);
    // outline0("CP 0");
    // outline1("JR Z, %sequal", label);
    // outline0("LD C, A");
    // outline1("LD HL, (%s)", _source);
    // outline1("LD DE, (%s)", _destination);
    // outhead1("%s:", label );
    // outline0("LD A, (HL)");
    // outline0("LD B, A");
    // outline0("LD A, (DE)");
    // outline0("CP B");
    // outline1("JR NZ, %sdiff", label);
    // outline0("INC DE");
    // outline0("INC HL");
    // outline0("DEC C");
    // outline1("JR NZ, %s", label);
    // outhead1("%sequal:", label );
    // outline1("LD A, 0x%2.2x", _equal ? 255 : 0 );
    // outline1("LD (%s), A", _result );
    // outline1("JMP %sfinal", label );
    // outhead1("%sdiff:", label );
    // outline1("LD A, 0x%2.2x", _equal ? 0 : 255 );
    // outline1("LD (%s), A", _result );
    // outhead1("%sfinal:", label );

}

void sc61860_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_compare_memory_size" );

    MAKE_LABEL

    // outline1("LD HL, (%s)", _source);
    // outline1("LD DE, (%s)", _destination);
    // outline1("LD A, 0x%2.2x", ( _size & 0xff ) );
    // outline0("LD C, A");
    // outhead1("%s:", label );
    // outline0("LD A, (HL)");
    // outline0("LD B, A");
    // outline0("LD A, (DE)");
    // outline0("CP B");
    // outline1("JR NZ, %sdiff", label);
    // outline0("INC DE");
    // outline0("INC HL");
    // outline0("DEC C");
    // outline1("JR NZ, %s", label);
    // outline1("LD A, 0x%2.2x", _equal ? 255 : 0 );
    // outline1("LD (%s), A", _result );
    // outline1("JMP %sfinal", label );
    // outhead1("%sdiff:", label );
    // outline1("LD A, 0x%2.2x", _equal ? 0 : 255 );
    // outline1("LD (%s), A", _result );
    // outhead1("%sfinal:", label );

}

void sc61860_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_less_than_memory" );

    MAKE_LABEL

    // outline1("LD HL, (%s)", _source);
    // outline1("LD DE, (%s)", _destination);
    // outline1("LD A, (%s)", _size);
    // outline0("LD C, A");
    // outhead1("%s:", label );
    // outline0("LD A, (DE)");
    // outline0("LD B, A");
    // outline0("LD A, (HL)");
    // outline0("CP B");
    if ( _equal ) {
        // outline1("JR Z, %seq", label);
    }
    // outline1("JR NC, %sdiff", label);
    if ( ! _equal ) {
        // outline1("JR Z, %sdiff", label);
    }
    // outhead1("%seq:", label );
    // outline0("INC DE");
    // outline0("INC HL");
    // outline0("DEC C");
    // outline1("JR NZ, %s", label);
    // outline0("LD A, 0xff" );
    // outline1("LD (%s), A", _result );
    // outline1("JMP %sfinal", label );
    // outhead1("%sdiff:", label );
    // outline0("LD A, 0" );
    // outline1("LD (%s), A", _result );
    // outhead1("%sfinal:", label );

}

void sc61860_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_less_than_memory_size" );

    MAKE_LABEL

    // outline1("LD HL, (%s)", _source);
    // outline1("LD DE, (%s)", _destination);
    // outline1("LD A, 0x%2.2x", ( _size & 0xff ) );
    // outline0("LD C, A");
    // outhead1("%s:", label );
    // outline0("LD A, (DE)");
    // outline0("LD B, A");
    // outline0("LD A, (HL)");
    // outline0("CP B");
    if ( _equal ) {
        // outline1("JR Z, %seq", label);
    }
    // outline1("JR NC, %sdiff", label);
    if ( ! _equal ) {
        // outline1("JR Z, %sdiff", label);
    }
    // outhead1("%seq:", label );
    // outline0("INC DE");
    // outline0("INC HL");
    // outline0("DEC C");
    // outline1("JR NZ, %s", label);
    // outline0("LD A, 0xff" );
    // outline1("LD (%s), A", _result );
    // outline1("JMP %sfinal", label );
    // outhead1("%sdiff:", label );
    // outline0("LD A, 0" );
    // outline1("LD (%s), A", _result );
    // outhead1("%sfinal:", label );

}

void sc61860_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_greater_than_memory" );

    MAKE_LABEL

    // outline1("LD HL, (%s)", _source);
    // outline1("LD DE, (%s)", _destination);
    // outline1("LD A, (%s)", _size);
    // outline0("LD C, A");
    // outhead1("%s:", label );
    // outline0("LD A, (DE)");
    // outline0("LD B, A");
    // outline0("LD A, (HL)");
    // outline0("CP B");
    if ( !_equal ) {
        // outline1("JR Z, %sdiff", label);
    }
    // outline1("JR C, %sdiff", label);
    // outline0("INC DE");
    // outline0("INC HL");
    // outline0("DEC C");
    // outline1("JR NZ, %s", label);
    // outline1("LD A, 0x%2.2x", 255 );
    // outline1("LD (%s), A", _result );
    // outline1("JMP %sfinal", label );
    // outhead1("%sdiff:", label );
    // outline1("LD A, 0x%2.2x", 0 );
    // outline1("LD (%s), A", _result );
    // outhead1("%sfinal:", label );

}

void sc61860_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_greater_than_memory_size" );

    MAKE_LABEL

    // outline1("LD HL, (%s)", _source);
    // outline1("LD DE, (%s)", _destination);
    // outline1("LD A, 0x%2.2x", ( _size & 0xff ) );
    // outline0("LD C, A");
    // outhead1("%s:", label );
    // outline0("LD A, (DE)");
    // outline0("LD B, A");
    // outline0("LD A, (HL)");
    // outline0("CP B");
    if ( ! _equal ) {
        // outline1("JR Z, %sdiff", label);
    }
    // outline1("JR C, %sdiff", label);
    // outline0("INC DE");
    // outline0("INC HL");
    // outline0("DEC C");
    // outline1("JR NZ, %s", label);
    // outline1("LD A, 0x%2.2x", 255 );
    // outline1("LD (%s), A", _result );
    // outline1("JMP %sfinal", label );
    // outhead1("%sdiff:", label );
    // outline1("LD A, 0x%2.2x", 0 );
    // outline1("LD (%s), A", _result );
    // outhead1("%sfinal:", label );

}

void sc61860_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_math_add_16bit_with_8bit" );

    // outline1("LD HL, (%s)", _source );
    // outline0("LD DE, 0" );
    // outline1("LD A, (%s)", _destination );
    // outline0("LD E, A" );
    // outline0("ADD HL, DE" );
    if ( _other ) {
        // outline1("LD (%s), HL", _other );
    } else {
        // outline1("LD (%s), HL", _destination );
    }

}

void sc61860_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_math_sub_16bit_with_8bit" );

    // outline1("LD HL, (%s)", _source );
    // outline0("LD DE, 0" );
    // outline1("LD A, (%s)", _destination );
    // outline0("LD E, A" );
    // outline0("SBC HL, DE" );
    if ( _other ) {
        // outline1("LD (%s), HL", _other );
    } else {
        // outline1("LD (%s), HL", _destination );
    }

}

void sc61860_uppercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_uppercase" );

    MAKE_LABEL

    // outline1("LD A, (%s)", _size);
    // outline0("LD C, A" );
    // outline1("LD HL, (%s)", _source );
    if ( _result ) {
        // outline1("LD DE, (%s)", _result );
    } else {
        // outline1("LD DE, (%s)", _source );
    }
    // outhead1("%supper:", label );
    // outline0("LD A, (HL)" );

    // outline0("CP 97");
    // outline1("JR C, %snext", label);

    // outline0("CP 122");
    // outline1("JR NC, %snext", label);

    // outline0("SUB A, 32");
    // outline0("LD (DE), A" );
    // outline1("JP %s// done", label );

    // outhead1("%snext:", label );
    // outline0("LD (DE), A" );
    // outhead1("%s// done:", label );
    // outline0("INC HL" );
    // outline0("INC DE" );
    // outline0("DEC C" );
    // outline0("LD A, C" );
    // outline0("CP 0" );
    // outline1("JR NZ, %supper", label);

}

void sc61860_lowercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    CRITICAL_UNIMPLEMENTED( "sc61860_lowercase" );

    // outline1("LD A, (%s)", _size);
    // outline0("LD C, A" );
    // outline1("LD HL, (%s)", _source );
    if ( _result ) {
        // outline1("LD DE, (%s)", _result );
    } else {
        // outline1("LD DE, (%s)", _source );
    }
    // outhead1("%slower:", label );
    // outline0("LD A, (HL)" );

    // outline0("CP 65");
    // outline1("JR C, %snext", label);

    // outline0("CP 91");
    // outline1("JR NC, %snext", label);

    // outline0("ADC A, 31");
    // outline0("LD (DE), A" );
    // outline1("JP %s// done", label );
    // outhead1("%snext:", label );
    // outline0("LD (DE), A" );
    // outhead1("%s// done:", label );
    // outline0("INC HL" );
    // outline0("INC DE" );
    // outline0("DEC C" );
    // outline0("LD A, C" );
    // outline0("CP 0" );
    // outline1("JR NZ, %slower", label);

}

void sc61860_convert_string_into_8bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    Variable * temp = variable_temporary( _environment, VT_WORD, "(temp)" );

    sc61860_convert_string_into_16bit( _environment, _string, _len, temp->realName );

    sc61860_move_8bit( _environment, temp->realName, _value );
  
}

void sc61860_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_convert_string_into_16bit" );

    MAKE_LABEL

    // outline1("LD A, (%s)", _len );
    // outline0("LD IX, 0" );
    // outline0("LD IXL, A" );

    // outline0("LD A, 0" );
    // outline1("LD (%s), A", _value );
    // outline1("LD (%s+1), A", _value );

    // outline1("LD HL, (%s)", _string );

    // outhead1("%srepeat:", label );

    // outline0("LD A, (HL)" );
    // outline0("CP 0x40" );
    // outline1("JR NC, %send", label);
    // outline0("CP 0x30" );
    // outline1("JR C, %send", label);
    // outline0("SBC A, 0x30" );

    // outline0("PUSH AF" );
    // outline1("LD A, (%s)", address_displacement(_environment, _value, "1") );
    // outline0("LD B, A"  );
    // outline1("LD A, (%s)", _value );
    // outline0("LD C, A" );
    // outline0("POP AF" );
    // outline0("LD E, A" );
    // outline0("LD D, 0" );
    // outline0("PUSH HL" );
    // outline0("LD HL, 0" );
    // outline0("ADC HL, DE" );
    // outline0("ADC HL, BC" );
    // outline1("LD (%s), HL", _value );
    // outline0("POP HL" );


    // MULT x 10

    // outline0("INC HL" );
    // outline0("DEC IX" );
    // outline0("LD A, 0" );
    // outline0("CP IXL" );
    // outline1("JR Z,%send", label );

    // outline0("PUSH HL" );

    // outline1("LD DE, (%s)", _value );
    // outline0("LD A, 10" );
    // outline0("LD B, 8" );
    // outline0("LD HL, 0" );
    // outline0("ADD HL, HL" );
    // outline0("RLCA" );
    // outline0("JR NC,0x+3" );
    // outline0("ADD HL, DE" );
    // outline0("DJNZ 0x-5" );
    // outline1("LD (%s), HL", _value );

    // outline0("POP HL" );

    // outline1("JMP %srepeat", label );

    // outhead1("%send:", label );
  
}

void sc61860_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern, int _size_size ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_fill_indirect" );

    MAKE_LABEL

    // Use the current bitmap address as starting address for filling routine.
    // outline1("LD DE, (%s)", _address);
    // outline1("LD HL, (%s)", _pattern);

    // Fill the bitmap with the given pattern.
    if ( _size_size >= 16 ) {
        // outline1("LD A, (%s)", _size);
        // outline0("LD C, A" );
        // outline1("LD A, (%s+1)", _size);
        // outline0("LD B, A" );
        // outhead1("%sx:", label);
        // outline0("LD A, (HL)");
        // outline0("LD (DE),A");
        // outline0("INC DE");
        // outline0("DEC BC");
        // outline0("LD A, B");
        // outline0("OR C");
        // outline1("JR NZ,%sx", label);
    } else {
        // outline1("LD A, (%s)", _size);
        // outline0("LD C, A" );
        // outhead1("%sx:", label);
        // outline0("LD A, (HL)");
        // outline0("LD (DE),A");
        // outline0("INC DE");
        // outline0("DEC C");
        // outline1("JR NZ,%sx", label);
    }

}

void sc61860_flip( Environment * _environment, char * _source, char * _size, char * _destination ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_flip" );

    // no_inline( cpu_flip )

    // embedded( cpu_flip, src_hw_sc61860_cpu_flip_asm );

        // outline1("LD HL, (%s)", _source);
        // outline1("LD DE, (%s)", _destination);
        // outline1("LD A, (%s)", _size);
        // outline0("CALL CPUFLIP");

    // done(  )

}

void sc61860_move_8bit_indirect( Environment * _environment, char *_source, char * _value ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_indirect" );

    // outline1("LD DE, (%s)", _value);
    // outline1("LD A, (%s)", _source);
    // outline0("LD (DE), A");

}

void sc61860_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_with_offset2" );

    // outline1("LD HL, %s", _value);
    // outline1("LD A, (%s)", _offset );
    // outline0("LD E, A" );
    // outline0("LD D, 0" );
    // outline0("ADD HL, DE" );
    // outline1("LD A, (%s)", _source);
    // outline0("LD (HL), A");

}

void sc61860_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_indirect_with_offset" );

    // outline1("LD HL, (%s)", _value);
    // outline1("LD DE, 0x%2.2x", ( _offset & 0xff ) );
    // outline0("ADD HL, DE" );
    // outline1("LD A, (%s)", _source);
    // outline0("LD (HL), A");

}

void sc61860_move_8bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_indirect2" );

    // outline1("LD DE, (%s)", _value);
    // outline0("LD A, (DE)");
    // outline1("LD (%s), A", _source);

}

void sc61860_move_8bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_indirect2_8bit" );

    // outline1("LD HL, %s", _value);
    // outline1("LD A, (%s)", _offset);
    // outline0("LD E, A");
    // outline0("LD A, 0");
    // outline0("LD D, A");
    // outline0("ADD HL, DE");
    // outline0("LD A, (HL)");
    // outline1("LD (%s), A", _source );

}

void sc61860_move_8bit_indirect2_16bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_indirect2_16bit" );

    // outline1("LD HL, %s", _value);
    // outline1("LD DE, (%s)", _offset);
    // outline0("ADD HL, DE");
    // outline0("LD A, (HL)");
    // outline1("LD (%s), A", _source );

}

void sc61860_move_16bit_indirect( Environment * _environment, char *_source, char * _value ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_16bit_indirect" );

    // outline1("LD DE, (%s)", _value);
    // outline1("LD HL, (%s)", _source);
    // outline0("LD A, L");
    // outline0("LD (DE), A");
    // outline0("INC DE");
    // outline0("LD A, H");
    // outline0("LD (DE), A");

}

void sc61860_move_16bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_16bit_indirect2" );

    // outline1("LD DE, (%s)", _value);
    // outline0("LD A, (DE)");
    // outline1("LD (%s), A", _source);
    // outline0("INC DE");
    // outline0("LD A, (DE)");
    // outline1("LD (%s), A", address_displacement(_environment, _source, "1"));

}

void sc61860_move_16bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_16bit_indirect2_8bit" );

    // outline1("LD HL, %s", _value);
    // outline1("LD A, (%s)", _offset);
    // outline0("LD E, A");
    // outline0("LD A, 0");
    // outline0("LD D, A");
    // outline0("ADD HL, DE");
    // outline0("ADD HL, DE");
    // outline0("LD A, (HL)");
    // outline1("LD (%s), A", _source );
    // outline0("INC HL");
    // outline0("LD A, (HL)");
    // outline1("LD (%s), A", address_displacement(_environment, _source, "1") );

}

void sc61860_move_32bit_indirect( Environment * _environment, char *_source, char * _value ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_32bit_indirect" );

    // outline1("LD DE, (%s)", _value);
    // outline1("LD HL, (%s)", _source);
    // outline0("LD A, L");
    // outline0("LD (DE), A");
    // outline0("INC DE");
    // outline0("LD A, H");
    // outline0("LD (DE), A");
    // outline0("INC DE");
    // outline1("LD HL, (%s)", address_displacement(_environment, _source, "2"));
    // outline0("LD A, L");
    // outline0("LD (DE), A");
    // outline0("INC DE");
    // outline0("LD A, H");
    // outline0("LD (DE), A");
    // outline0("INC DE");

}

void sc61860_move_nbit_indirect( Environment * _environment, int _n, char *_source, char * _value ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_nbit_indirect" );

    // outline1("LD DE, (%s)", _value);

    char step[MAX_TEMPORARY_STORAGE];
    char step2[MAX_TEMPORARY_STORAGE];

    int stepIndex = 0;
    while( _n ) {
        sprintf( step, "%d", stepIndex );
        sprintf( step2, "%d", stepIndex+2 );
        if ( _n >= 32 ) {
            // outline1("LD HL, (%s)", address_displacement(_environment, _source, step));
            // outline0("LD A, L");
            // outline0("LD (DE), A");
            // outline0("INC DE");
            // outline0("LD A, H");
            // outline0("LD (DE), A");
            // outline0("INC DE");
            // outline1("LD HL, (%s)", address_displacement(_environment, _source, step2));
            // outline0("LD A, L");
            // outline0("LD (DE), A");
            // outline0("INC DE");
            // outline0("LD A, H");
            // outline0("LD (DE), A");
            // outline0("INC DE");
            stepIndex += 4;
            _n -= 32;
            break;
        } else {
            switch( _n ) {
                case 32: case 31: case 30: case 29:
                case 28: case 27: case 26: case 25:
                    // outline1("LD HL, (%s)", address_displacement(_environment, _source, step));
                    // outline0("LD A, L");
                    // outline0("LD (DE), A");
                    // outline0("INC DE");
                    // outline0("LD A, H");
                    // outline0("LD (DE), A");
                    // outline0("INC DE");
                    // outline1("LD HL, (%s)", address_displacement(_environment, _source, step2));
                    // outline0("LD A, L");
                    // outline0("LD (DE), A");
                    // outline0("INC DE");
                    // outline0("LD A, H");
                    // outline0("LD (DE), A");
                    // outline0("INC DE");
                    break;
                case 24: case 23: case 22: case 21:
                case 20: case 19: case 18: case 17:
                    // outline1("LD HL, (%s)", address_displacement(_environment, _source, step));
                    // outline0("LD A, L");
                    // outline0("LD (DE), A");
                    // outline0("INC DE");
                    // outline0("LD A, H");
                    // outline0("LD (DE), A");
                    // outline0("INC DE");
                    // outline1("LD A, (%s)", address_displacement(_environment, _source, step2));
                    // outline0("LD (DE), A");
                    // outline0("INC DE");
                    break;
                case 16: case 15: case 14: case 13:
                case 12: case 11: case 10: case 9:
                    // outline1("LD HL, (%s)", address_displacement(_environment, _source, step));
                    // outline0("LD A, L");
                    // outline0("LD (DE), A");
                    // outline0("INC DE");
                    // outline0("LD A, H");
                    // outline0("LD (DE), A");
                    // outline0("INC DE");
                    break;
                case 8: case 7: case 6: case 5:
                case 4: case 3: case 2: case 1:
                    // outline1("LD A, (%s)", address_displacement(_environment, _source, step));
                    // outline0("LD (DE), A");
                    // outline0("INC DE");
                    break;
            }
            _n = 0;
        }
    }
}

void sc61860_move_32bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_32bit_indirect2" );

    // outline1("LD DE, (%s)", _value);
    // outline0("LD A, (DE)");
    // outline0("LD L, A");
    // outline0("INC DE");
    // outline0("LD A, (DE)");
    // outline0("LD H, A");
    // outline0("INC DE");
    // outline1("LD (%s), HL", _source);
    // outline0("LD A, (DE)");
    // outline0("LD L, A");
    // outline0("INC DE");
    // outline0("LD A, (DE)");
    // outline0("LD H, A");
    // outline0("INC DE");
    // outline1("LD (%s), HL", address_displacement( _environment, _source, "2" ) );

}

void sc61860_move_nbit_indirect2( Environment * _environment, int _n, char * _value, char *_source ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_nbit_indirect2" );

    // outline1("LD DE, (%s)", _value);

    char step[MAX_TEMPORARY_STORAGE];
    char step2[MAX_TEMPORARY_STORAGE];

    int stepIndex = 0;
    while( _n ) {
        sprintf( step, "%d", stepIndex );
        sprintf( step2, "%d", stepIndex+2 );
        if ( _n >= 32 ) {
            // outline0("LD A, (DE)");
            // outline0("LD L, A");
            // outline0("INC DE");
            // outline0("LD A, (DE)");
            // outline0("LD H, A");
            // outline0("INC DE");
            // outline1("LD (%s), HL", address_displacement( _environment, _source, step ) );
            // outline0("LD A, (DE)");
            // outline0("LD L, A");
            // outline0("INC DE");
            // outline0("LD A, (DE)");
            // outline0("LD H, A");
            // outline0("INC DE");
            // outline1("LD (%s), HL", address_displacement( _environment, _source, step2 ) );
            stepIndex += 4;
            _n -= 32;
            break;
        } else {
            switch( _n ) {
                case 32: case 31: case 30: case 29:
                case 28: case 27: case 26: case 25:
                    // outline0("LD A, (DE)");
                    // outline0("LD L, A");
                    // outline0("INC DE");
                    // outline0("LD A, (DE)");
                    // outline0("LD H, A");
                    // outline0("INC DE");
                    // outline1("LD (%s), HL", address_displacement( _environment, _source, step ) );
                    // outline0("LD A, (DE)");
                    // outline0("LD L, A");
                    // outline0("INC DE");
                    // outline0("LD A, (DE)");
                    // outline0("LD H, A");
                    // outline0("INC DE");
                    // outline1("LD (%s), HL", address_displacement( _environment, _source, step2 ) );
                    break;
                case 24: case 23: case 22: case 21:
                case 20: case 19: case 18: case 17:
                    // outline0("LD A, (DE)");
                    // outline0("LD L, A");
                    // outline0("INC DE");
                    // outline0("LD A, (DE)");
                    // outline0("LD H, A");
                    // outline0("INC DE");
                    // outline1("LD (%s), HL", address_displacement( _environment, _source, step ) );
                    // outline0("LD A, (DE)");
                    // outline0("INC DE");
                    // outline1("LD (%s), A", address_displacement( _environment, _source, step2 ) );
                    break;
                case 16: case 15: case 14: case 13:
                case 12: case 11: case 10: case 9:
                    // outline0("LD A, (DE)");
                    // outline0("LD L, A");
                    // outline0("INC DE");
                    // outline0("LD A, (DE)");
                    // outline0("LD H, A");
                    // outline0("INC DE");
                    // outline1("LD (%s), HL", address_displacement( _environment, _source, step ) );
                    break;
                case 8: case 7: case 6: case 5:
                case 4: case 3: case 2: case 1:
                    // outline0("LD A, (DE)");
                    // outline0("INC DE");
                    // outline1("LD (%s), A", address_displacement( _environment, _source, step ) );
                    break;
            }
            _n = 0;
        }
    }

}

void sc61860_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_math_div_32bit_to_16bit" );

    MAKE_LABEL

    if ( _signed ) {

        // outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));
        // outline0("AND 0x80");
        // outline0("CP 0" );
        // outline0("PUSH AF");
        // outline1("JR Z,%spositive", label);
        sc61860_complement2_32bit( _environment, _source, NULL );
        // outhead1("%spositive:", label);
        // outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        // outline0("AND 0x80");
        // outline0("CP 0" );
        // outline0("PUSH AF");
        // outline1("JR Z,%spositive2", label);
        sc61860_complement2_16bit( _environment, _destination, NULL );
        // outhead1("%spositive2:", label);

        // // outline1("LD HL, %s", _source);
        // // outline0("LD A, (HL)");
        // // outline0("PUSH AF");
        // // outline0("POP IX");
        // // outline0("INC HL");
        // // outline0("INC HL");
        // // outline0("LD A, (HL)");
        // // outline0("LD C, A");
        // // outline0("INC HL");
        // // outline0("LD A, (HL)");
        // // outline1("LD DE, (%s)", _destination);

        // // outline0("LD HL, 0");
        // // outline0("LD B, 32");
        // // outhead1("%sloop:", label);
        // // outline0("ADD IX, IX");
        // // outline0("RL C");
        // // outline0("RLA");
        // // outline0("ADC HL, HL");
        // // outline1("JR C, %soverflow", label);
        // // outline0("SBC HL, DE");
        // // outline1("JR NC, %ssetbit", label);
        // // outline0("ADD HL, DE");
        // // outline1("DJNZ %sloop", label);
        // // outline1("JMP %send", label);
        // // outhead1("%soverflow:", label);
        // // outline0("OR A");
        // // outline0("SBC HL, DE");
        // // outhead1("%ssetbit:", label);
        // // outline0("INC IXL");
        // // outline1("DJNZ %sloop", label);
        // // outhead1("%send:", label);
        // // outline1("LD (%s), HL", _other_remainder);
        // // outline1("LD HL, %s", _other);
        // // outline0("PUSH AF");
        // // outline0("PUSH IX");
        // // outline0("POP AF");
        // // outline0("LD (HL), A");
        // // outline0("POP AF");
        // // outline0("INC HL");
        // // outline0("INC HL");
        // // outline0("INC HL");
        // // outline0("LD (HL), A");
        // // outline0("DEC HL");
        // // outline0("LD C, (HL)");

        // outline1("LD A, (%s)", _destination);
        // outline0("LD E, A");
        // outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        // outline0("LD D, A");
        // outline1("LD IX, (%s)", _source);
        // outline1("LD A, (%s)", address_displacement(_environment, _source, "2"));
        // outline0("LD C, A");
        // outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));

        // outline0("LD HL, 0");
        // outline0("LD B, 32");
        // outhead1("%sdiv32a:", label);
        // outline0("ADD IX, IX");
        // outline0("RL C");
        // outline0("RLA");
        // outline0("ADC HL, HL");
        // outline1("JR C, %sdiv32ov", label);
        // outline0("SBC HL, DE");
        // outline1("JR NC, %sdiv32setbit", label);
        // outline0("ADD HL, DE");
        // outline1("DJNZ %sdiv32a", label);
        // outline1("JR %sdiv32end", label);
        // outhead1("%sdiv32ov:", label);
        // outline0("OR A");
        // outline0("SBC HL, DE");
        // outhead1("%sdiv32setbit:", label);
        // outline0("INC IX");
        // outline1("DJNZ %sdiv32a", label);
        // outhead1("%sdiv32end:", label);

        // outline1("LD (%s), A", address_displacement(_environment, _other, "3"));
        // outline0("LD A, C" );
        // outline1("LD (%s), A", address_displacement(_environment, _other, "2"));
        // outline1("LD (%s), IX", _other);
        // outline0("LD A, L");
        // outline1("LD (%s), A", _other_remainder);
        // outline0("LD A, H");
        // outline1("LD (%s), A", address_displacement(_environment, _other_remainder, "1"));

        // outline0("POP AF");
        // outline0("LD B, A");
        // outline0("CMP 0x80");
        // outline1("JR NZ, %srepositive", label);
        sc61860_complement2_16bit( _environment, _destination, NULL );
        // outhead1("%srepositive:", label);
        // outline0("POP AF");
        // outline0("LD C, A");
        // outline0("CMP 0x80");
        // outline1("JR NZ, %srepositive2", label );
        sc61860_complement2_32bit( _environment, _source, NULL );
        // outhead1("%srepositive2:", label);
        // outline0("LD A, B");
        // outline0("XOR C");
        // outline0("AND 0x80");
        // outline0("CP 0x80");
        // outline1("JR NZ, %srepositive3", label );
        sc61860_complement2_32bit( _environment, _other, NULL );
        // outhead1("%srepositive3:", label);

    } else {

        // // outline1("LD HL, %s", _source);
        // // outline0("LD A, (HL)");
        // // outline0("PUSH AF");
        // // outline0("POP IX");
        // // outline0("INC HL");
        // // outline0("INC HL");
        // // outline0("LD A, (HL)");
        // // outline0("LD C, A");
        // // outline0("INC HL");
        // // outline0("LD A, (HL)");
        // // outline1("LD DE, (%s)", _destination);

        // // outline0("LD HL, 0");
        // // outline0("LD B, 32");
        // // outhead1("%sloop:", label);
        // // outline0("ADD IX, IX");
        // // outline0("RL C");
        // // outline0("RLA");
        // // outline0("ADC HL, HL");
        // // outline1("JR C, %soverflow", label);
        // // outline0("SBC HL, DE");
        // // outline1("JR NC, %ssetbit", label);
        // // outline0("ADD HL, DE");
        // // outline1("DJNZ %sloop", label);
        // // outline1("JMP %send", label);
        // // outhead1("%soverflow:", label);
        // // outline0("OR A");
        // // outline0("SBC HL, DE");
        // // outhead1("%ssetbit:", label);
        // // outline0("INC IXL");
        // // outline1("DJNZ %sloop", label);
        // // outhead1("%send:", label);
        // // outline1("LD (%s), HL", _other_remainder);
        // // outline1("LD HL, %s", _other);
        // // outline0("PUSH AF");
        // // outline0("PUSH IX");
        // // outline0("POP AF");
        // // outline0("LD (HL), A");
        // // outline0("POP AF");
        // // outline0("INC HL");
        // // outline0("INC HL");
        // // outline0("INC HL");
        // // outline0("LD (HL), A");
        // // outline0("DEC HL");
        // // outline0("LD C, (HL)");
        // ; IN:	ACIX=dividend, DE=divisor
        // ; OUT:	ACIX=quotient, DE=divisor, HL=remainder, B=0

	    // outline1("LD HL, (%s)", _source);
	    // outline0("LD IX, HL");
	    // outline1("LD HL, (%s)", address_displacement(_environment, _source, "2"));
	    // outline0("LD A, L");
	    // outline0("LD C, A");
	    // outline0("LD A, H");
	    // outline1("LD DE, (%s)", _destination);

	    // outline0("LD HL, 0");
        // outline0("LD B, 32");
        // outhead1("%sloop1:", label);
        // outline0("ADD IX, IX");
        // outline0("RL C");
        // outline0("RLA");
        // outline0("ADC HL, HL");
        // outline1("JR C, %sloop2", label);
        // outline0("SBC HL, DE");
        // outline1("JR NC, %sloop3", label);
        // outline0("ADD HL, DE");
        // outline1("DJNZ %sloop1", label);
        // outline1("JR %s// done", label);
        // outhead1("%sloop2:", label);
        // outline0("OR A");
        // outline0("SBC HL, DE");
        // outhead1("%sloop3:", label);
        // outline0("INC IXL");
        // outline1("DJNZ %sloop1", label);
        // outhead1("%s// done:", label);

	    // outline1("LD (%s), HL", _other_remainder);
	    // outline0("LD H, A");
	    // outline0("LD A, C");
	    // outline0("LD L, C");
	    // outline1("LD (%s), HL", _other);
	    // outline0("LD HL, IX");
	    // outline1("LD (%s), HL", _other);

    }
 
}

void sc61860_math_div_32bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_math_div_32bit_to_16bit_const" );

}

void sc61860_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_math_div_16bit_to_16bit" );

    MAKE_LABEL

    if ( _signed ) {

        // outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        // outline0("AND 0x80");
        // outline0("CP 0" );
        // outline0("PUSH AF");
        // outline1("JR Z,%spositive", label);
        sc61860_complement2_16bit( _environment, _source, NULL );
        // outhead1("%spositive:", label);
        // outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        // outline0("AND 0x80");
        // outline0("CP 0" );
        // outline0("PUSH AF");
        // outline1("JR Z,%spositive2", label);
        sc61860_complement2_16bit( _environment, _destination, NULL );
        // outhead1("%spositive2:", label);

        // outline1("LD HL, %s", _source);
        // outline0("LD A, (HL)");
        // outline0("LD C, A");
        // outline0("INC HL");
        // outline0("LD A, (HL)");
        // outline1("LD DE, (%s)", _destination);

        // outline0("LD HL, 0");
        // outline0("LD B, 16");
        // outhead1("%sloop:", label );
        // outline0("SLL C");
        // outline0("RLA");
        // outline0("ADC HL, HL");
        // outline0("SBC HL, DE");
        // outline0("JR NC, 0x+4");
        // outline0("ADD HL, DE");
        // outline0("DEC C");
        // outline1("DJNZ %sloop", label);
        // outline1("LD (%s), HL", _other_remainder);
        // outline1("LD DE, %s", _other);
        // outline0("LD B, A");
        // outline0("LD A, C");
        // outline0("LD (DE), A");
        // outline0("INC DE");
        // outline0("LD A, B");
        // outline0("LD (DE), A");

        // outline0("POP AF");
        // outline0("LD B, A");
        // outline0("CMP 0x80");
        // outline1("JR NZ, %srepositive", label);
        sc61860_complement2_16bit( _environment, _destination, NULL );
        // outhead1("%srepositive:", label);
        // outline0("POP AF");
        // outline0("LD C, A");
        // outline0("CMP 0x80");
        // outline1("JR NZ, %srepositive2", label );
        sc61860_complement2_16bit( _environment, _source, NULL );
        // outhead1("%srepositive2:", label);
        // outline0("LD A, B");
        // outline0("XOR C");
        // outline0("AND 0x80");
        // outline0("CP 0x80");
        // outline1("JR NZ, %srepositive3", label );
        sc61860_complement2_16bit( _environment, _other, NULL );
        // outhead1("%srepositive3:", label);

    } else {

        // outline1("LD HL, %s", _source);
        // outline0("LD A, (HL)");
        // outline0("LD C, A");
        // outline0("INC HL");
        // outline0("LD A, (HL)");
        // outline1("LD DE, (%s)", _destination);

        // outline0("LD HL, 0");
        // outline0("LD B, 16");
        // outhead1("%sloop:", label );
        // outline0("SLL C");
        // outline0("RLA");
        // outline0("ADC HL, HL");
        // outline0("SBC HL, DE");
        // outline0("JR NC, 0x+4");
        // outline0("ADD HL, DE");
        // outline0("DEC C");
        // outline1("DJNZ %sloop", label);
        // outline1("LD (%s), HL", _other_remainder);
        // outline1("LD DE, %s", _other);
        // outline0("LD B, A");
        // outline0("LD A, C");
        // outline0("LD (DE), A");
        // outline0("INC DE");
        // outline0("LD A, B");
        // outline0("LD (DE), A");

    }
    
}

void sc61860_math_div_16bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_math_div_16bit_to_16bit_const" );

}

void sc61860_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_math_div_8bit_to_8bit" );

    MAKE_LABEL

    if ( _signed ) {

        // outline1("LD A, (%s)", _source );
        // outline0("LD B, A" );
        // outline1("LD A, (%s)", _destination );
        // outline0("XOR A, B" );
        // outline0("AND 0x80" );
        // outline0("PUSH AF" );
        // outline1("LD A, (%s)", _source );
        // outline0("AND 0x80" );
        // outline0("CP 0" );
        // outline1("JR Z,%spos", label );
        // outline1("LD A, (%s)", _source );
        // outline0("XOR 0xFF" );
        // outline0("ADC 0x1" );
        // outline1("JMP %spos2", label );
        // outhead1("%spos:", label );
        // outline1("LD A, (%s)", _source );
        // outhead1("%spos2:", label );
        // outline0("LD D, A");
        
        // outline1("LD A, (%s)", _destination );
        // outline0("AND 0x80" );
        // outline0("CP 0" );
        // outline1("JR Z,%sposx", label );
        // outline1("LD A, (%s)", _destination );
        // outline0("XOR 0xFF" );
        // outline0("ADC 0x1" );
        // outline1("JMP %sposx2", label );
        // outhead1("%sposx:", label );
        // outline1("LD A, (%s)", _destination );
        // outhead1("%sposx2:", label );
        // outline0("LD E, A");

        // outline0("XOR A");
        // outline0("AND A");
        // outline0("LD B, 8");
        // outhead1("%sloop:", label);
        // outline0("SLA D");
        // outline0("RLA");
        // outline0("CP E");
        // outline0("JR C, 0x+4");
        // outline0("SUB E");
        // outline0("INC D");
        // outline1("DJNZ %sloop", label );

        // outline1("LD (%s), A", _other_remainder);
        // outline0("LD A, D");
        // outline1("LD (%s), A", _other);

        // outline0("POP AF" );
        // outline0("AND 0x80" );
        // outline0("CP 0" );
        // outline1("JR Z,%spos3", label );
        // outline1("LD A, (%s)", _other );
        // outline0("XOR 0xFF" );
        // outline0("ADC 0x1" );
        // outline1("LD (%s), A", _other );
        // outhead1("%spos3:", label );
        
    } else {

        // outline1("LD A, (%s)", _source);
        // outline0("LD D, A");
        // outline1("LD A, (%s)", _destination);
        // outline0("LD E, A");

        // outline0("XOR A");
        // outline0("LD B, 8");
        // outhead1("%sloop:", label);

        // outline0("SLA D");
        // outline0("RLA");
        // outline0("CP E");
        // outline0("JR C, 0x+4");
        // outline0("SUB E");
        // outline0("INC D");
        // outline1("DJNZ %sloop", label );

        // outline1("LD (%s), A", _other_remainder);
        // outline0("LD A, D");
        // outline1("LD (%s), A", _other);

    }
}

void sc61860_math_div_8bit_to_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_math_div_8bit_to_8bit_const" );

    MAKE_LABEL

}

void sc61860_bit_check( Environment * _environment, char *_value, int _position, char * _result, int _bitwidth ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_bit_check" );

    // no_inline( cpu_bit_check_extended )

    // embedded( cpu_bit_check_extended, src_hw_sc61860_cpu_bit_check_extended_asm );

        // outline1("LD DE, %s", _value);
        // outline1("LD A, 0x%2.2x", _position );
        // outline0("CALL CPUBITCHECKEXTENDED" );

        if ( _result ) {
            // outline1("LD (%s), A", _result);
        }

    // done( )

}

void sc61860_bit_check_extended( Environment * _environment, char *_value, char * _position, char * _result, int _bitwidth ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_bit_check_extended" );

    MAKE_LABEL

    // no_inline( cpu_bit_check_extended )

    // embedded( cpu_bit_check_extended, src_hw_sc61860_cpu_bit_check_extended_asm );

        // outline1("LD DE, %s", _value);
        // outline1("LD A, (%s)", _position );
        // outline0("CALL CPUBITCHECKEXTENDED" );

        if ( _result ) {
            // outline1("LD (%s), A", _result);
        }

    // done( )
    
}

void sc61860_bit_inplace_8bit( Environment * _environment, char * _value, int _position, int * _bit ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_bit_inplace_8bit" );

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    // no_inline( cpu_bit_inplace )

    // embedded( cpu_bit_inplace, src_hw_sc61860_cpu_bit_inplace_asm );

        if ( _bit ) {
            if ( * _bit ) {
                // outline0("LD A, 0xff" );
            } else {
                // outline0("LD A, 0x0" );
            }
            // outline0("SRL A" );
        }
        // outline1("LD DE, %s", _value );
        // outline1("LD A, 0x%2.2x", _position);
        // outline0("CALL CPUBITINPLACE");

    // done( )

}

void sc61860_bit_inplace_8bit_extended_indirect( Environment * _environment, char * _address, char * _position, char * _bit ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_bit_inplace_8bit_extended_indirect" );

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    // no_inline( cpu_bit_inplace )

    // embedded( cpu_bit_inplace, src_hw_sc61860_cpu_bit_inplace_asm );

        if ( _bit ) {
            // outline1("LD A, (%s)", _bit );
            // outline0("CP 0x0" );
            // outline1("JR Z, %s", label );
            // outline0("LD A, 1" );;
            // outline0("SRL A" );
            // outhead1("%s:", label );
        }
        // outline1("LD DE, (%s)", _address );
        // outline1("LD A, (%s)", _position);
        // outline0("CALL CPUBITINPLACE");

    // done( )

}

void sc61860_number_to_string_vars( Environment * _environment ) {

    variable_import( _environment, "N2DINV", VT_BUFFER, 8 );
    variable_import( _environment, "N2DBUF", VT_BUFFER, 20 );
    variable_import( _environment, "N2DEND", VT_BUFFER, 1 );

}

void sc61860_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_number_to_string" );

    MAKE_LABEL
        
    // deploy_with_vars( numberToString, src_hw_sc61860_number_to_string_asm, sc61860_number_to_string_vars );

    switch( _bits ) {
        case 8:
            // outline1("LD A, (%s)", _number);
            if ( _signed ) {
                // outline0("AND 0x80");
                // outline0("LD B, A");
                // outline0("PUSH BC");
                // outline0("CP 0");
                // outline1("JR Z, %sp81", label);
                // outline1("LD A, (%s)", _number);
                // outline0("XOR 0xFF");
                // outline0("ADC 0x1");
                // outline1("JP %sp82", label);
                // outhead1("%sp81:", label);
                // outline1("LD A, (%s)", _number);
                // outhead1("%sp82:", label);
            } else {
                // outline0("LD B, 0" );
                // outline0("PUSH BC");
            }
            // outline0("POP IX");
            // outline0("CALL N2D8");
            break;
        case 16:
            // outline1("LD HL, (%s)", _number);
            if ( _signed ) {
                // outline0("LD A, H");
                // outline0("AND 0x80");
                // outline0("LD B, A");
                // outline0("PUSH BC");
                // outline0("CP 0");
                // outline1("JR Z, %sp161", label);
                // outline0("LD A, H");
                // outline0("XOR 0xFF");
                // outline0("LD H, A");
                // outline0("LD A, L");
                // outline0("XOR 0xFF");
                // outline0("LD L, A");
                // outline0("LD DE, 1" );
                // outline0("ADD HL, DE" );
                // outline0("LD DE, 0" );
                // outline1("JP %sp162", label);
                // outhead1("%sp161:", label);
                // outline1("LD HL, (%s)", _number);
                // outhead1("%sp162:", label);
            } else {
                // outline0("LD B, 0" );
                // outline0("PUSH BC");
            }
            // outline0("POP IX");
            // outline0("CALL N2D16");
            break;
        case 32:
            // outline1("LD HL, (%s)", _number);
            // outline1("LD DE, (%s)", address_displacement(_environment, _number, "2"));
            if ( _signed ) {
                // outline0("LD A, D");
                // outline0("AND 0x80");
                // outline0("LD B, A");
                // outline0("PUSH BC");
                // outline0("CP 0");
                // outline1("JR Z, %sp321", label);
                // outline0("LD A, D");
                // outline0("XOR 0xFF");
                // outline0("LD D, A");
                // outline0("LD A, E");
                // outline0("XOR 0xFF");
                // outline0("LD E, A");
                // outline0("LD A, H");
                // outline0("XOR 0xFF");
                // outline0("LD H, A");
                // outline0("LD A, L");
                // outline0("XOR 0xFF");
                // outline0("LD L, A");
                // outline0("AND A");
                // outline0("INC HL");
                // outline0("LD A, L");
                // outline0("OR H");
                // outline1("JR NZ, %sp322", label);
                // outline0("INC DE");
                // outline1("JP %sp322", label);
                // outhead1("%sp321:", label);
                // outline1("LD HL, (%s)", _number);
                // outline1("LD DE, (%s)", address_displacement(_environment, _number, "2"));
                // outhead1("%sp322:", label);
            } else {
                // outline0("LD B, 0" );
                // outline0("PUSH BC");
            }
            // outline0("POP IX");
            // outline0("CALL N2D32");
            break;
        default:
            CRITICAL_DEBUG_UNSUPPORTED( _number, "unknown");
    }

    // outline1("LD DE, (%s)", _string);
    // outline0("LD A, IXH");
    // outline0("CP 0");
    // outline1("JR Z, %spos", label);
    // outline0("LD A, '-'");
    // outline0("LD (DE), A");
    // outline0("INC DE");
    // outline0("INC C");
    // outhead1("%spos:", label);
    // outline0("LD A, C");
    // outline1("LD (%s), A", _string_size);
    // outline0("LDIR");

}

void sc61860_bits_to_string_vars( Environment * _environment ) {

    variable_import( _environment, "BINSTRBUF", VT_BUFFER, 32 );
    
}

void sc61860_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_bits_to_string" );

    // deploy_with_vars( bitsToString,src_hw_sc61860_bits_to_string_asm, sc61860_bits_to_string_vars );

    switch( _bits ) {
        case 32:
            // outline1("LD BC, (%s)", address_displacement(_environment, _number, "2") );
            // outline1("LD DE, (%s)", _number );
            break;
        case 16:
            // outline0("LD BC, 0" );
            // outline1("LD DE, (%s)", _number );
            break;
        case 8:        
            // outline0("LD BC, 0" );
            // outline0("LD D, 0" );
            // outline1("LD A, (%s)", _number );
            // outline0("LD E, A" );
            // outline0("LD A, 0" );
            break;
    }

    // outline1("LD A, 0x%2.2x", ( _bits & 0xff ) );
    // outline0("CALL BINSTR");
    
    // outline1("LD DE, (%s)", _string);
    // outline1("LD A, 0x%2.2x", ( (_bits) & 0xff ) );
    // outline0("LD C, A");
    // outline0("LD B, 0");
    // outline0("LDIR");

    // outline1("LD A, 0x%2.2x", ( _bits & 0xff ) );
    // outline1("LD HL, %s", _string_size );
    // outline0("LD (HL), A" );

}

void sc61860_hex_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_hex_to_string" );

    MAKE_LABEL

    // inline( cpu_hex_to_string )

    // embedded( cpu_hex_to_string, src_hw_sc61860_cpu_hex_to_string_asm );

        // outline1("LD A, 0x%2.2x", _bits);
        // outline0("LD IXL, A");

        switch( _bits ) {
            case 8:
                // outline1("LD A, (%s)", _number );
                // outline0("LD L, A" );
                // outline0("LD H, 0" );
                // outline1("LD DE, (%s)", _string );

                // outline0("CALL H2STRING" );
                break;
            case 16:

                // outline1("LD HL, (%s)", _number );
                // outline1("LD DE, (%s)", _string );

                // outline0("CALL H2STRING" );
                break;

            case 32:

                // outline1("LD HL, (%s)", address_displacement(_environment, _number, "2") );
                // outline1("LD DE, (%s)", _string );

                // outline0("CALL H2STRING" );

                // outline1("LD HL, (%s)", _number );
                // outline1("LD DE, (%s)", _string );
                // outline0("INC DE" );
                // outline0("INC DE" );
                // outline0("INC DE" );
                // outline0("INC DE" );

                // outline0("CALL H2STRING" );
                break;

        }

        // outline1("LD A, 0x%2.2x", ( _bits >> 2 ) );
        // outline1("LD (%s), A", _string_size );

    // done()

}


void sc61860_dsdefine( Environment * _environment, char * _string, char * _index ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dsdefine" );

    // deploy( dstring,src_hw_sc61860_dstring_asm );

    // outline1( "LD HL, %s", _string );
    // outline0( "CALL DSDEFINE" );
    // outline0( "LD A, B" );
    // outline1( "LD (%s), A", _index );
    
}

void sc61860_dsalloc( Environment * _environment, char * _size, char * _index ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dsalloc" );

    // deploy( dstring,src_hw_sc61860_dstring_asm );

    // outline1( "LD A, (%s)", _size );
    // outline0( "LD C, A" );
    // outline0( "CALL DSALLOC" );
    // outline0( "LD A, B" );
    // outline1( "LD (%s), A", _index );

}

void sc61860_dsalloc_size( Environment * _environment, int _size, char * _index ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dsalloc_size" );

    // deploy( dstring,src_hw_sc61860_dstring_asm );

    // outline1( "LD A, 0x%2.2x", ( _size & 0xff ) );
    // outline0( "LD C, A" );
    // outline0( "CALL DSALLOC" );
    // outline0( "LD A, B" );
    // outline1( "LD (%s), A", _index );

}

void sc61860_dsfree( Environment * _environment, char * _index ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dsfree" );

    // deploy( dstring,src_hw_sc61860_dstring_asm );

    // outline1( "LD A, (%s)", _index );
    // outline0( "LD B, A" );
    // outline0( "CALL DSFREE" );

}

void sc61860_dswrite( Environment * _environment, char * _index ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dswrite" );

    // deploy( dstring,src_hw_sc61860_dstring_asm );

    // outline1( "LD A, (%s)", _index );
    // outline0( "LD B, A" );
    // outline0( "CALL DSWRITE" );

}

void sc61860_dsresize( Environment * _environment, char * _index, char * _resize ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dsresize" );

    // deploy( dstring,src_hw_sc61860_dstring_asm );

    // outline1( "LD A, (%s)", _index );
    // outline0( "LD B, A" );
    // outline1( "LD A, (%s)", _resize );
    // outline0( "LD C, A" );
    // outline0( "CALL DSRESIZE" );

}

void sc61860_dsresize_size( Environment * _environment, char * _index, int _resize ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dsresize_size" );

    // deploy( dstring,src_hw_sc61860_dstring_asm );

    // outline1( "LD A, (%s)", _index );
    // outline0( "LD B, A" );
    // outline1( "LD A, 0x%2.2x", ( _resize & 0xff ) );
    // outline0( "LD C, A" );
    // outline0( "CALL DSRESIZE" );

}

void sc61860_dsinit( Environment * _environment ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dsinit" );

    // deploy( dstring,src_hw_sc61860_dstring_asm );

    // outline0( "CALL DSGC" );

}

void sc61860_dsgc( Environment * _environment ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dsgc" );

    // deploy( dstring,src_hw_sc61860_dstring_asm );

    // outline0( "CALL DSGC" );

}

void sc61860_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dsdescriptor" );

    // deploy( dstring,src_hw_sc61860_dstring_asm );

    // outline1( "LD A, (%s)", _index );
    // outline0( "LD B, A" );
    // outline0( "CALL DSDESCRIPTOR" );
    // outline0( "LD A, (IX)" );
    // outline1( "LD (%s), A", _size );
    // outline0( "LD A, (IX+1)" );
    // outline1( "LD (%s), A", _address );
    // outline0( "LD A, (IX+2)" );
    // outline1( "LD (%s), A", address_displacement(_environment, _address, "1") );

}

void sc61860_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_indirect_with_offset2" );

    // outline1("LD HL, (%s)", _value);
    // outline1("LD A, (%s)", _offset );
    // outline0("LD E, A" );
    // outline0("LD A, 0" );
    // outline0("LD D, A" );
    // outline0("ADD HL, DE" );
    // outline1("LD A, (%s)", _source);
    // outline0("LD (HL), A");

}

void sc61860_complement2_8bit( Environment * _environment, char * _source, char * _destination ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_complement2_8bit" );

    // outline1( "LD A, (%s)", _source );
    // outline0( "XOR 0xFF" );
    if ( _destination ) {
        // outline1( "LD (%s), A", _destination );        
    } else {
        // outline1( "LD (%s), A", _source );        
    }
    if ( _destination ) {
        sc61860_inc( _environment, _destination );
    } else {
        sc61860_inc( _environment, _source );
    }
}

void sc61860_complement2_16bit( Environment * _environment, char * _source, char * _destination ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_complement2_16bit" );

    // outline1( "LD A, (%s)", _source );
    // outline0( "XOR 0xFF" );
    if ( _destination ) {
        // outline1( "LD (%s), A", _destination );        
    } else {
        // outline1( "LD (%s), A", _source );        
    }
    // outline1( "LD A, (%s)", address_displacement(_environment, _source, "1") );
    // outline0( "XOR 0xFF" );
    if ( _destination ) {
        // outline1( "LD (%s), A", address_displacement(_environment, _destination, "1") );        
    } else {
        // outline1( "LD (%s), A", address_displacement(_environment, _source, "1") );        
    }
    if ( _destination ) {
        sc61860_inc_16bit( _environment, _destination );
    } else {
        sc61860_inc_16bit( _environment, _source );
    }
}

void sc61860_complement2_32bit( Environment * _environment, char * _source, char * _destination ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_complement2_32bit" );
    
    // outline1( "LD A, (%s)", _source );
    // outline0( "XOR 0xFF" );
    if ( _destination ) {
        // outline1( "LD (%s), A", _destination );        
    } else {
        // outline1( "LD (%s), A", _source );        
    }
    // outline1( "LD A, (%s)", address_displacement(_environment, _source, "1") );
    // outline0( "XOR 0xFF" );
    if ( _destination ) {
        // outline1( "LD (%s), A", address_displacement(_environment, _destination, "1") );        
    } else {
        // outline1( "LD (%s), A", address_displacement(_environment, _source, "1") );        
    }
    // outline1( "LD A, (%s)", address_displacement(_environment, _source, "2") );
    // outline0( "XOR 0xFF" );
    if ( _destination ) {
        // outline1( "LD (%s), A", address_displacement(_environment, _destination, "2") );        
    } else {
        // outline1( "LD (%s), A", address_displacement(_environment, _source, "2") );        
    }
    // outline1( "LD A, (%s)", address_displacement(_environment, _source, "3") );
    // outline0( "XOR 0xFF" );
    if ( _destination ) {
        // outline1( "LD (%s), A", address_displacement(_environment, _destination, "3") );        
    } else {
        // outline1( "LD (%s), A", address_displacement(_environment, _source, "3") );        
    } 
    if ( _destination ) {
        sc61860_inc_32bit( _environment, _destination );
    } else {
        sc61860_inc_32bit( _environment, _source );
    }
}

void sc61860_sqroot( Environment * _environment, char * _number, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_sqroot" );

    // deploy( sqr, src_hw_sc61860_sqr_asm );

    // outline1("LD HL, (%s)", _number );

    // outline0("CALL SQROOT" );

    // outline1("LD (%s),A", _result );

}

void sc61860_dstring_vars( Environment * _environment ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_dstring_vars" );

    int count = _environment->dstring.count == 0 ? DSTRING_DEFAULT_COUNT : _environment->dstring.count;
    int space = _environment->dstring.space == 0 ? DSTRING_DEFAULT_SPACE : _environment->dstring.space;

#if !defined(__vg5000__) && !defined(__cpc__) && !defined(__c128z__) && !defined(__zx__)
    // outhead0("section data_user" );
#endif
    // outhead1("MAXSTRINGS:                   DB %d", count );
    // outhead1("DESCRIPTORS:                  DEFS %d", count * 4 );
    // outhead1("WORKING:                      DEFS %d", space );
    // outhead1("TEMPORARY:                    DEFS %d", space );
    // outhead2("FREE_STRING:                  DB 0x%2.2X, 0x%2.2x", ((space-1)& 0xff), ((space-1)>>8)& 0xff );
#if !defined(__vg5000__) && !defined(__cpc__) && !defined(__c128z__) && !defined(__zx__)
    // outhead0("section code_user" );
#endif

}

void sc61860_protothread_vars( Environment * _environment ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_vars" );

    int count = _environment->protothreadConfig.count;

    variable_import( _environment, "PROTOTHREADLC", VT_BUFFER, count );
    // // outhead1("PROTOTHREADLC:      DEFS        %d", count );
    variable_import( _environment, "PROTOTHREADST", VT_BUFFER, count );
    // // outhead1("PROTOTHREADST:      DEFS        %d", count );
    variable_import( _environment, "PROTOTHREADCT", VT_BYTE, 0 );
    // // outhead0("PROTOTHREADCT:      DEFB        0" );
    variable_import( _environment, "PROTOTHREADLOOP", VT_BUFFER, 1 + count * 8 );
    variable_import( _environment, "PROTOTHREADCOUNT", VT_BYTE, count );

}


void sc61860_protothread_loop( Environment * _environment ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_loop" );

    // deploy_with_vars( protothread, src_hw_sc61860_protothread_asm, cpu_protothread_vars );

    // outline0("CALL PROTOTHREADLOOP" );

}

void sc61860_protothread_register_at( Environment * _environment, char * _index, char * _label ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_register_at" );

    // deploy_with_vars( protothread, src_hw_sc61860_protothread_asm, cpu_protothread_vars );

    // outline1("LD HL, %s", _label );
    // outline1("LD A, (%s)", _index );
    // outline0("LD B, A");

    // outline0("CALL PROTOTHREADREGAT" );

}

void sc61860_protothread_register( Environment * _environment, char * _label, char * _index ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_register" );

    // deploy_with_vars( protothread, src_hw_sc61860_protothread_asm, cpu_protothread_vars );

    // outline1("LD HL, %s", _label );

    // outline0("CALL PROTOTHREADREG" );

    // outline0("LD A, B" );
    // outline1("LD (%s), A", _index );

}

void sc61860_protothread_unregister( Environment * _environment, char * _index ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_unregister" );

    // deploy_with_vars( protothread, src_hw_sc61860_protothread_asm, cpu_protothread_vars );

    // outline1("LD A, (%s)", _index );
    // outline0("LD B, A" );

    // outline0("CALL PROTOTHREADUNREG" );

}

void sc61860_protothread_save( Environment * _environment, char * _index, int _step ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_save" );

    // deploy_with_vars( protothread, src_hw_sc61860_protothread_asm, cpu_protothread_vars );

    // outline1("LD A, (%s)", _index );
    // outline0("LD B, A" );
    // outline1("LD A, 0x%2.2x", ( _step & 0xff ) );

    // outline0("CALL PROTOTHREADSAVE" );

}

void sc61860_protothread_restore( Environment * _environment, char * _index, char * _step ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_restore" );

    // deploy_with_vars( protothread, src_hw_sc61860_protothread_asm, cpu_protothread_vars );

    // outline1("LD A, (%s)", _index );
    // outline0("LD B, A" );

    // outline0("CALL PROTOTHREADRESTORE" );

    // outline1("LD (%s), A", _step );
    
}

void sc61860_protothread_set_state( Environment * _environment, char * _index, int _state ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_set_state" );

    // deploy_with_vars( protothread, src_hw_sc61860_protothread_asm, cpu_protothread_vars );

    // outline1("LD A, (%s)", _index );
    // outline0("LD B, A" );
    // outline1("LD A, 0x%2.2x", ( _state & 0xff ) );

    // outline0("CALL PROTOTHREADSETSTATE" );

}

void sc61860_protothread_get_state( Environment * _environment, char * _index, char * _state ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_get_state" );

    // deploy_with_vars( protothread, src_hw_sc61860_protothread_asm, cpu_protothread_vars );

    // outline1("LD A, (%s)", _index );
    // outline0("LD B, A" );

    // outline0("CALL PROTOTHREADGETSTATE" );

    // outline1("LD (%s), A", _state );

}

void sc61860_protothread_current( Environment * _environment, char * _current ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_current" );

    // deploy_with_vars( protothread, src_hw_sc61860_protothread_asm, cpu_protothread_vars );

    // outline0("LD A, (PROTOTHREADCT)" );
    // outline1("LD (%s), A", _current );

}

void sc61860_protothread_get_address( Environment * _environment, char * _index, char * _address ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_protothread_get_address" );

}

void sc61860_set_callback( Environment * _environment, char * _callback, char * _label ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_set_callback" );

    // outline1("LD DE, %s", _label );
    // outline1("LD HL, %s", _callback );
    // outline0("INC HL" );
    // outline0("LD (HL), E" );
    // outline0("INC HL" );
    // outline0("LD (HL), D" );

}

void sc61860_msc1_uncompress_direct_direct( Environment * _environment, char * _input, char * _output ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_msc1_uncompress_direct_direct" );

    MAKE_LABEL

    // inline( cpu_msc1_uncompress )

    // embedded( cpu_msc1_uncompress, src_hw_sc61860_msc1_asm );

        // outline1("LD HL, %s", _input);
        // outline1("LD DE, %s", _output);
        // outline0("CALL MSC1UNCOMPRESS");

    // done()

}

void sc61860_msc1_uncompress_direct_indirect( Environment * _environment, char * _input, char * _output ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_msc1_uncompress_direct_indirect" );

    MAKE_LABEL

    // inline( cpu_msc1_uncompress )

    // embedded( cpu_msc1_uncompress, src_hw_sc61860_msc1_asm );

        // outline1("LD HL, %s", _input);
        // outline1("LD DE, (%s)", _output);
        // outline0("CALL MSC1UNCOMPRESS");

    // done()

}

void sc61860_msc1_uncompress_indirect_direct( Environment * _environment, char * _input, char * _output ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_msc1_uncompress_indirect_direct" );

    MAKE_LABEL

    // inline( cpu_msc1_uncompress )

    // embedded( cpu_msc1_uncompress, src_hw_sc61860_msc1_asm );

        // outline1("LD HL, (%s)", _input);
        // outline1("LD DE, %s", _output);
        // outline0("CALL MSC1UNCOMPRESS");

    // done()

}

void sc61860_msc1_uncompress_indirect_indirect( Environment * _environment, char * _input, char * _output ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_msc1_uncompress_indirect_indirect" );

    MAKE_LABEL

    // inline( cpu_msc1_uncompress )

    // embedded( cpu_msc1_uncompress, src_hw_sc61860_msc1_asm );

        // outline1("LD HL, (%s)", _input);
        // outline1("LD DE, (%s)", _output);
        // outline0("CALL MSC1UNCOMPRESS");

    // done()

}

void sc61860_out( Environment * _environment, char * _port, char * _value ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_out" );

    // outline1("LD A, (%s)", _value );
    // outline1("LD BC, (%s)", _port );
    // outline0("OUT (C), A" );

}

void sc61860_in( Environment * _environment, char * _port, char * _value ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_in" );

    // outline1("LD BC, (%s)", _port );
    // outline0("IN A, (C)" );
    // outline1("LD (%s), A", _value );
        
}

void sc61860_out_direct( Environment * _environment, char * _port, char * _value ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_out_direct" );

    // outline1("LD A, (%s)", _value );
    // outline1("LD BC, %s", _port );
    // outline0("OUT (C), A" );

}

void sc61860_in_direct( Environment * _environment, char * _port, char * _value ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_in_direct" );

    // outline1("LD BC, %s", _port );
    // outline0("IN A, (C)" );
    // outline1("LD (%s), A", _value );
        
}

void sc61860_string_sub( Environment * _environment, char * _source, char * _source_size, char * _pattern, char * _pattern_size, char * _destination, char * _destination_size ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_string_sub" );

    MAKE_LABEL

    // inline( cpu_string_sub )

    // embedded( cpu_string_sub, src_hw_sc61860_cpu_string_sub_asm );

        // outline1("LD A, (%s)", _source);
        // outline0("LD L, A");
        // outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        // outline0("LD H, A");
        // outline1("LD A, (%s)", _source_size);
        // outline0("LD IYL, A");

        // outline1("LD A, (%s)", _pattern);
        // outline0("LD IXL, A");
        // outline1("LD A, (%s)", address_displacement(_environment, _pattern, "1"));
        // outline0("LD IXH, A");
        // outline1("LD A, (%s)", _pattern_size);
        // outline0("LD IYH, A");

        // outline1("LD A, (%s)", _destination);
        // outline0("LD E, A");
        // outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        // outline0("LD D, A");

        // outline0("CALL CPUSTRINGSUB");

        // outline0("LD A, IYL");
        // outline1("LD (%s), A", _destination_size);

    // done()
}

static char SC616860_BLIT_REGISTER[][2] = {
    "L",
    "H",
    "E",
    "D"
};

#define SC616860_BLII_REGISTER_COUNT ( sizeof( SC616860_BLIT_REGISTER ) / 2 )

void sc61860_blit_initialize( Environment * _environment ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_blit_initialize" );

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

    // outline0("PUSH HL");
    // outline0("PUSH DE");

}

void sc61860_blit_finalize( Environment * _environment ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_blit_finalize" );

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

    // outline0("POP DE");
    // outline0("POP HL");
    
}

char * sc61860_blit_register_name(  Environment * _environment, int _register ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_blit_register_name" );

    if ( _register < SC616860_BLII_REGISTER_COUNT ) {
        return &SC616860_BLIT_REGISTER[_register][0];
    } else {
        return &SC616860_BLIT_REGISTER[ (_register & 0xff00) >> 8][0];
    }
}

int sc61860_blit_alloc_register(  Environment * _environment ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_blit_alloc_register" );

    int reg = 0;

    for( reg = 0; reg < SC616860_BLII_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x01 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            _environment->blit.freeRegisters |= registerMask;
            // printf( "sc61860_blit_alloc_register() %4.4x -> 0x%4.4x\n", _environment->blit.freeRegisters, reg );
            return reg;
        }
    }

    int location = _environment->blit.usedMemory++;

    if ( location > 0xff ) {
        CRITICAL_BLIT_ALLOC_MEMORY_EXHAUSTED( );
    }

    for( reg = 0; reg < SC616860_BLII_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x10 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            // outline1( "LD A, %s", &SC616860_BLIT_REGISTER[reg][0] );
            // outline2( "LD (%sbs+0x%2.2x), A",  _environment->blit.realName, location );
            _environment->blit.freeRegisters |= registerMask;
            // printf( "sc61860_blit_alloc_register() -> %4.4x 0x%4.4x\n", _environment->blit.freeRegisters, ( ( reg << 8 ) | location ) );
            return ( ( reg << 8 ) | location );
        }
    }

    CRITICAL_BLIT_ALLOC_REGISTER_EXHAUSTED( );

}

void sc61860_blit_free_register(  Environment * _environment, int _register ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_blit_free_register" );

    // printf( "sc61860_blit_free_register(0x%4.4x)\n", _register );

    int location = _register & 0xff;
    int reg;

    if ( _register < SC616860_BLII_REGISTER_COUNT ) {
        int registerMask = ( 0x01 << _register );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( isRegisterUsed ) {
            _environment->blit.freeRegisters &= ~registerMask;
            return;
        } else {
            CRITICAL_BLIT_INVALID_FREE_REGISTER( _environment->blit.name, _register );
        }
    } else {
        int registerMask = 0x10 << ( ( _register >> 8 ) & 0xff );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( isRegisterUsed ) {
            // outline2( "LD A, (%sbs+0x%2.2x)",  _environment->blit.realName, location );
            // outline1( "LD %s, A", &SC616860_BLIT_REGISTER[reg][0] );
            _environment->blit.freeRegisters &= ~registerMask;
            return;
        }
    }

    CRITICAL_BLIT_INVALID_FREE_REGISTER( _environment->blit.name, _register );

}

/**
 * @brief <i>CPU SC616860</i>: emit code to store n bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _n bits to store (>32)
 * @param _value[] Value to store (segmented in 32 bit each)
 */
void sc61860_store_nbit( Environment * _environment, char *_destination, int _n, int _value[] ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_store_nbit" );

    int i = 0;
    while( _n ) {
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    sc61860_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff>>(8-_n)) ) );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    sc61860_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sc61860_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff>>(16-_n)) ) );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    sc61860_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sc61860_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sc61860_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff>>(24-_n)) ) );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    sc61860_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sc61860_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sc61860_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    sc61860_store_8bit( _environment, destinationAddress, ( _value[i+3] & (0xff>>(32-_n)) ) );
                    break;
            }
            _n = 0;
        } else {
            sc61860_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            sc61860_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            sc61860_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            sc61860_store_8bit( _environment, destinationAddress, ( _value[i+3] & (0xff>>(32-_n)) ) );
            _n -= 32;
        }
        ++i;
    }

}

/**
 * @brief <i>CPU SC616860</i>: emit code to store n bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _n bits to store (>32)
 * @param _value[] Value to store (segmented in 32 bit each)
 */
void sc61860_move_nbit( Environment * _environment, int _n, char * _source, char *_destination ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_nbit" );

    int i = 0;
    while( _n ) {
        char sourceAddress[MAX_TEMPORARY_STORAGE]; sprintf( sourceAddress, "%s+%d", _source, i*4 );
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
            }
            _n = 0;
        } else {
            sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            sc61860_move_8bit( _environment, sourceAddress, destinationAddress );
            _n -= 32;
        }
        ++i;
    }

}

/**
 * @brief <i>CPU SC616860</i>: emit code to compare n bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _n bits to store (>32)
 * @param _value[] Value to store (segmented in 32 bit each)
 */
void sc61860_compare_nbit( Environment * _environment, int _n, char *_source, char *_destination,  char *_name, int _positive ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_compare_nbit" );

    MAKE_LABEL

    char differentLabel[MAX_TEMPORARY_STORAGE];
    sprintf( differentLabel, "%sdifferent:", label );

    int i = 0;
    while( _n ) {
        char sourceAddress[MAX_TEMPORARY_STORAGE]; sprintf( sourceAddress, "%s+%d", _source, i*4 );
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    break;
            }
            _n = 0;
        } else {
            sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
            sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
            sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
            sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
            sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
            sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
            sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            sc61860_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
            sc61860_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
            _n -= 32;
        }
        ++i;
    }

    // outline1("LD A, 0x%2.2x", _positive * 0xff );
    // outline1("LD (%s), A", _name );
    // outline1("JP %s// done", label );

    // outhead0(differentLabel);
    // outline1("LD A, 0x%2.2x", (1-_positive) * 0xff );
    // outline1("LD (%s), A", _name );

    // outhead1("%s// done:", label );
    
}

//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// FAST	    (24)	seeeeeee mmmmmmmm mmmmmmmm

void sc61860_float_fast_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_from_double_to_int_array" );

    double value = 0.0;
    double integral = 0.0;
    double fractional = 0.0;
    int sign = 0;
    int left = 0;
    int right[2];
    int steps = 0;
    int exp = 0;
    int mantissa_bits = 16;

    memset( &right[0], 0, sizeof( int ) * 2 );

    // Step 1: Determine Sign
    // If the number is positive, then the sign bit will be 0. If the number is negative, then the sign bit 
    // will be 1. For the number zero, both positive and negative zero are possible, and these are considered 
    // different values (a quirk of using sign bits).

    if ( _value >= 0 ) {
        sign = 0;
    } else {
        sign = 1;
    }

    value = fabs( _value );

    // Step 2: Convert the Integral Portion to Unsigned Binary
    // Convert the integral portion of the floating-point value to unsigned binary (not two's complement). 
    // The integral portion is the part of the number before the decimal point. For example, if the 
    // number to convert is -0.75, then 0 is the integral portion, and it's unsigned binary representation 
    // is simply 0. As another example, if the number to convert is 127.99, then the integral portion would 
    // be 127, and it's unsigned binary representation is 1111111.

    fractional = modf(value, &integral);

    left = (unsigned int) integral;

    // Step 3: Convert the Fractional Portion to Binary
    // The fractional portion of the number must also be converted to binary, though the conversion process 
    // is much different from what you're used to. The algorithm you'll used is based on performing repeated 
    // multiplications by 2, and then checking if the result is >= 1.0. If the result is >= 1.0, then a 1 is 
    // recorded for the binary fractional component, and the leading 1 is chopped of the result. If the 
    // result is < 1.0, then a 0 is recorded for the binary fractional component, and the result is kept 
    // as-is. The recorded builds are built-up left-to-right. The result keeps getting chained along in this 
    // way until one of the following is true:
    //  - The result is exactly 1.0
    //  - 23 iterations of this process have occurred; i.e. the final converted binary value holds 23 bits
    // With the first possible terminating condition (the result is exactly 1.0), this means that the fractional 
    // component has been represented without any loss of precision. With the second possible terminating 
    // condition (23 iterations have passed), this means that we ran out of bits in the final result, which 
    // can never exceed 23. In this case, precision loss occurs (an unfortunate consequence of using a finite
    // number of bits).

    while( ( fractional != 1.0 ) && ( steps < mantissa_bits ) ) {

        // printf("%f %d %2.2x %2.2x\n", fractional, steps, (unsigned char) right[0], (unsigned char) right[1] );

        right[1] = right[1] << 1;
        right[0] = right[0] << 1;
        if ( ( right[1] & 0x100 )  ) {
            right[0] = right[0] | 0x1;
        }
        right[1] = right[1] & 0xff;
        right[0] = right[0] & 0xff;

        fractional = fractional * 2;

        if ( fractional >= 1.0 ) {
            right[1] |= 1;
            fractional = modf(fractional, &integral);
        }

        ++steps;

    }

    // Step 4: Normalize the Value via Adjusting the Exponent
    // A trick to encode an extra bit is to make it so that the binary scientific representation is always 
    // of the form 1.XXXX * 2YYYY. That is, a 1 always leads, so there is no need to explicitly encode it. 
    // In order to encode this properly, we need to move the decimal point to a position where it is 
    // immediately after the first 1, and then record exactly how we moved it. To see this in action, consider 
    // again the example of 0.75, which is encoded in binary as such (not IEEE-754 notation):
    // 0.11
    // In order to make the decimal point be after the first 1, we will need to move it one position to the right, like so:
    // 1.1
    // Most importantly, we need to record that we moved the decimal point by one position to the right. 
    // Moves to the right result in negative exponents, and moves to the left result in positive exponents. 
    // In this case, because we moved the decimal point one position to the right, the recorded exponent should be -1.
    // As another example, consider the following binary floating point representation (again, not IEEE-754):
    // 1111111.11100
    // In this case, we need to move the decimal point six positions to the left to make this begin with a single 1, like so:
    // 1.11111111100
    // Because this moves six positions to the left, the recorded exponent should be 6.

    int mantissa_high_bit = 0x80000000 >> ( 32 - mantissa_bits);
    int mantissa_mask = 0xffffffff >> ( 32 - mantissa_bits);

    if ( left == 0 ) {

        if ( value != 0 ) {

            while( left == 0 ) {

                // printf("exp = %d left = %2.2x right = %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1] );

                if ( ! right[0] && ! right[1] && ! right[2] ) {
                    left = 0x1;
                }

                if ( right[0] & 0x80 ) {
                    left = 0x1;
                }

                right[0] = right[0] << 1;
                right[1] = right[1] << 1;
                if ( ( right[1] & 0x100 )) {
                    right[0] = right[0] | 0x1;
                }
                right[0] = right[0] & 0xff;
                right[1] = right[1] & 0xff;

                --exp;
            }

        } else {

            exp = -63;
            
        }

        // printf("exp = %d left = %2.2x right = %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1] );

    } else {

        while( left ) {

            // printf("left = %8.8x right = %2.2x %2.2x\n", left, (unsigned char) right[0], (unsigned char) right[1] );

            if ( ( right[0] & 0x01 ) ) {
                right[1] = right[1] | 0x100;
            }
            right[0] = right[0] >> 1;
            right[1] = right[1] >> 1;
            if ( left & 0x1 ) {
                right[0] = right[0] | 0x80;
            }
            left = left >> 1;
            ++exp;
        }
        --exp;
        left = 1;
        right[1] = right[1] << 1;
        right[0] = right[0] << 1;
        if ( right[1] & 0x100 ) {
            right[0] = right[0] | 0x01;
        }
        right[1] = right[1] & 0xff;
        right[0] = right[0] & 0xff;
        
    }

    // Step 5: Add Bias to the Exponent
    // Internally, IEEE-754 values store their exponents in an unsigned representation, which may seem odd considering that 
    // the exponent can be negative. Negative exponents are accomodated by using a biased representation, wherein a 
    // pre-set number is always subtracted from the given unsigned number. Because the given unsigned number may be less 
    // than this number, this allows for negative values to be effectively encoded without resorting to two's complement. 
    // Specifically, for the binary32 representation, the number 127 will be subtracted from anything encoded in the 
    // exponent field of the IEEE-754 number. As such, in this step, we need to add 127 to the normalized exponent value 
    // from the previous step.

    exp += 63;

    // printf("exp = %2.2x\n", exp );

    // Step 6: Convert the Biased Exponent to Unsigned Binary
    // The biased exponent value from the previous step must be converted into unsigned binary, using the usual process.
    // The result must be exactly 8 bits. It should not be possible to need more than 8 bits. If fewer than 8 bits are 
    // needed in this conversion process, then leading zeros must be added to the front of the result to produce an 
    // 8-bit value.

    exp = exp & 0xff;

    // printf("exp = %2.2x\n", exp );

    // Step 7: Determine the Final Bits for the Mantissa
    // After step 4, there are a bunch of bits after the normalized decimal point. These bits will become the 
    // mantissa (note that we ignore the bits to the left of the decimal point - normalization allows us to do this, 
    // because it should always be just a 1). We need exactly 23 mantissa bits. If less than 23 mantissa bits follow the 
    // decimal point, and the algorithm in step 3 ended with a result that wasn't 1.0, then follow the algorithm in step 3 
    // until we can fill enough bits. If that's still not enough (eventually reaching 1.0 before we had enough bits, or 
    // perhaps it had ended with 1.0 already), then the right side can be padded with zeros until 23 bits is reached.
    // If there are more than 23 bits after the decimal point in step 4, then these extra bits are simply cutoff from the 
    // right. For example, if we had 26 bits to the right of the decimal point, then the last three would need to be cutoff 
    // to get us to 23 bits. Note that in this case we will necessarily lose some precision.

    // Step 8: Put it All Together
    // The sign bit from step 1 will be the first bit of the final result. The next 8 bits will be from the exponent from 
    // step 6. The last 23 bits will be from the mantissa from step 7. The result will be a 32-bit number encoded in 
    // IEEE-754 binary32 format, assuming no mistakes were made in the process.

    //                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
    // FAST	    (24)	seeeeeee mmmmmmmm mmmmmmmm

    _result[0] = ( sign << 7 ) | ( exp & 0x7f );
    _result[1] = ( right[0] );
    _result[2] = ( right[1] );

    // printf( "%2.2x %2.2x %2.2x\n", _result[0], _result[1], _result[2] );

}

//
//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// SINGLE	(32)  	seeeeeee emmmmmmm mmmmmmmm mmmmmmmm
//

void sc61860_float_single_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_from_double_to_int_array" );

    double value = 0.0;
    double integral = 0.0;
    double fractional = 0.0;
    int sign = 0;
    int left = 0;
    int right[3];
    int steps = 0;
    int exp = 0;
    int mantissa_bits = 23;

    memset( &right[0], 0, sizeof( int ) * 3 );

    // Step 1: Determine Sign
    // If the number is positive, then the sign bit will be 0. If the number is negative, then the sign bit 
    // will be 1. For the number zero, both positive and negative zero are possible, and these are considered 
    // different values (a quirk of using sign bits).

    if ( _value >= 0 ) {
        sign = 0;
    } else {
        sign = 1;
    }

    value = fabs( _value );

    // Step 2: Convert the Integral Portion to Unsigned Binary
    // Convert the integral portion of the floating-point value to unsigned binary (not two's complement). 
    // The integral portion is the part of the number before the decimal point. For example, if the 
    // number to convert is -0.75, then 0 is the integral portion, and it's unsigned binary representation 
    // is simply 0. As another example, if the number to convert is 127.99, then the integral portion would 
    // be 127, and it's unsigned binary representation is 1111111.

    fractional = modf(value, &integral);

    left = (unsigned int) integral;

    // Step 3: Convert the Fractional Portion to Binary
    // The fractional portion of the number must also be converted to binary, though the conversion process 
    // is much different from what you're used to. The algorithm you'll used is based on performing repeated 
    // multiplications by 2, and then checking if the result is >= 1.0. If the result is >= 1.0, then a 1 is 
    // recorded for the binary fractional component, and the leading 1 is chopped of the result. If the 
    // result is < 1.0, then a 0 is recorded for the binary fractional component, and the result is kept 
    // as-is. The recorded builds are built-up left-to-right. The result keeps getting chained along in this 
    // way until one of the following is true:
    //  - The result is exactly 1.0
    //  - 23 iterations of this process have occurred; i.e. the final converted binary value holds 23 bits
    // With the first possible terminating condition (the result is exactly 1.0), this means that the fractional 
    // component has been represented without any loss of precision. With the second possible terminating 
    // condition (23 iterations have passed), this means that we ran out of bits in the final result, which 
    // can never exceed 23. In this case, precision loss occurs (an unfortunate consequence of using a finite
    // number of bits).

    while( ( fractional != 1.0 ) && ( steps < mantissa_bits ) ) {

        // printf("%f %d %2.2x %2.2x %2.2x\n", fractional, steps, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );

        right[2] = right[2] << 1;
        right[1] = right[1] << 1;
        right[0] = right[0] << 1;
        if ( ( right[2] & 0x100 )  ) {
            right[1] = right[1] | 0x1;
        }
        if ( ( right[1] & 0x100 )  ) {
            right[0] = right[0] | 0x1;
        }
        right[2] = right[2] & 0xff;
        right[1] = right[1] & 0xff;
        right[0] = right[0] & 0x7f;

        fractional = fractional * 2;

        if ( fractional >= 1.0 ) {
            right[2] |= 1;
            fractional = modf(fractional, &integral);
        }

        ++steps;

    }

    // Step 4: Normalize the Value via Adjusting the Exponent
    // A trick to encode an extra bit is to make it so that the binary scientific representation is always 
    // of the form 1.XXXX * 2YYYY. That is, a 1 always leads, so there is no need to explicitly encode it. 
    // In order to encode this properly, we need to move the decimal point to a position where it is 
    // immediately after the first 1, and then record exactly how we moved it. To see this in action, consider 
    // again the example of 0.75, which is encoded in binary as such (not IEEE-754 notation):
    // 0.11
    // In order to make the decimal point be after the first 1, we will need to move it one position to the right, like so:
    // 1.1
    // Most importantly, we need to record that we moved the decimal point by one position to the right. 
    // Moves to the right result in negative exponents, and moves to the left result in positive exponents. 
    // In this case, because we moved the decimal point one position to the right, the recorded exponent should be -1.
    // As another example, consider the following binary floating point representation (again, not IEEE-754):
    // 1111111.11100
    // In this case, we need to move the decimal point six positions to the left to make this begin with a single 1, like so:
    // 1.11111111100
    // Because this moves six positions to the left, the recorded exponent should be 6.

    int mantissa_high_bit = 0x80000000 >> ( 32 - mantissa_bits);
    int mantissa_mask = 0xffffffff >> ( 32 - mantissa_bits);

    if ( left == 0 ) {

        if ( value != 0 ) {

            while( left == 0 ) {

                // printf("exp = %d left = %2.2x right = %2.2x %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );

                if ( right[0] & 0x40 ) {
                    left = 0x1;
                }

                right[0] = right[0] << 1;
                right[1] = right[1] << 1;
                right[2] = right[2] << 1;
                if ( ( right[1] & 0x100 )) {
                    right[0] = right[0] | 0x1;
                }
                if ( ( right[2] & 0x100 )) {
                    right[1] = right[1] | 0x1;
                }
                right[0] = right[0] & 0x7f;
                right[1] = right[1] & 0xff;
                right[2] = right[2] & 0xff;

                --exp;
            }

        } else {

            exp = -127;

        }

        // printf("exp = %d left = %2.2x right = %2.2x %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );

    } else {

        while( left ) {

            // printf("left = %8.8x right = %2.2x %2.2x %2.2x\n", left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );

            if ( ( right[0] & 0x01 ) ) {
                right[1] = right[1] | 0x100;
            }
            if ( ( right[1] & 0x01 ) ) {
                right[2] = right[2] | 0x100;
            }
            right[0] = right[0] >> 1;
            right[1] = right[1] >> 1;
            // right[2] = right[2] >> 1;
            if ( left & 0x1 ) {
                right[0] = right[0] | 0x40;
            }
            left = left >> 1;
            ++exp;
        }
        --exp;
        left = 1;
        right[2] = right[2] << 1;
        right[1] = right[1] << 1;
        right[0] = right[0] << 1;
        if ( right[2] & 0x100 ) {
            right[1] = right[1] | 0x01;
        }
        if ( right[1] & 0x100 ) {
            right[0] = right[0] | 0x01;
        }
        right[2] = right[2] & 0xff;
        right[1] = right[1] & 0xff;
        right[0] = right[0] & 0x7f;
        
    }

    // Step 5: Add Bias to the Exponent
    // Internally, IEEE-754 values store their exponents in an unsigned representation, which may seem odd considering that 
    // the exponent can be negative. Negative exponents are accomodated by using a biased representation, wherein a 
    // pre-set number is always subtracted from the given unsigned number. Because the given unsigned number may be less 
    // than this number, this allows for negative values to be effectively encoded without resorting to two's complement. 
    // Specifically, for the binary32 representation, the number 127 will be subtracted from anything encoded in the 
    // exponent field of the IEEE-754 number. As such, in this step, we need to add 127 to the normalized exponent value 
    // from the previous step.

    exp += 127;

    // printf("exp = %2.2x\n", exp );

    // Step 6: Convert the Biased Exponent to Unsigned Binary
    // The biased exponent value from the previous step must be converted into unsigned binary, using the usual process.
    // The result must be exactly 8 bits. It should not be possible to need more than 8 bits. If fewer than 8 bits are 
    // needed in this conversion process, then leading zeros must be added to the front of the result to produce an 
    // 8-bit value.

    exp = exp & 0xff;

    // printf("exp = %2.2x\n", exp );

    // Step 7: Determine the Final Bits for the Mantissa
    // After step 4, there are a bunch of bits after the normalized decimal point. These bits will become the 
    // mantissa (note that we ignore the bits to the left of the decimal point - normalization allows us to do this, 
    // because it should always be just a 1). We need exactly 23 mantissa bits. If less than 23 mantissa bits follow the 
    // decimal point, and the algorithm in step 3 ended with a result that wasn't 1.0, then follow the algorithm in step 3 
    // until we can fill enough bits. If that's still not enough (eventually reaching 1.0 before we had enough bits, or 
    // perhaps it had ended with 1.0 already), then the right side can be padded with zeros until 23 bits is reached.
    // If there are more than 23 bits after the decimal point in step 4, then these extra bits are simply cutoff from the 
    // right. For example, if we had 26 bits to the right of the decimal point, then the last three would need to be cutoff 
    // to get us to 23 bits. Note that in this case we will necessarily lose some precision.

    // Step 8: Put it All Together
    // The sign bit from step 1 will be the first bit of the final result. The next 8 bits will be from the exponent from 
    // step 6. The last 23 bits will be from the mantissa from step 7. The result will be a 32-bit number encoded in 
    // IEEE-754 binary32 format, assuming no mistakes were made in the process.

    //                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
    // SINGLE	(32)  	seeeeeee emmmmmmm mmmmmmmm mmmmmmmm

    _result[3] = ( sign << 7 ) | ( ( exp >> 1 ) & 0x7f );
    _result[2] = ( ( exp & 0x01 ) << 7 ) | ( right[0] );
    _result[1] = ( right[1] );
    _result[0] = ( right[2] );

    // printf( "%2.2x %2.2x %2.2x %2.2x\n", _result[0], _result[1], _result[2], _result[3] );

}

//
//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// EXTENDED (80)	seeeeeee eeeeeeee mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm
//

void sc61860_float_double_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_double_from_double_to_int_array" );

}

void sc61860_float_fast_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_to_string" );

    MAKE_LABEL

    // deploy( fp_mul16, src_hw_sc61860_fp_mul16_asm );
    // deploy( fp_fast_mul, src_hw_sc61860_fp_fast_mul_asm );
    // deploy( fp_fast_pow10_lut, src_hw_sc61860_fp_fast_pow10_lut_asm );
    // deploy( fp_format_str, src_hw_sc61860_fp_format_str_asm );
    // deploy( fp_fast_to_string, src_hw_sc61860_fp_fast_to_string_asm );

    // ;converts a 24-bit float to a string

    // ;Inputs:
    // ;   AHL is the float to convert

    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _x );

    // ;   DE points to where to write the string
    // outline1( "LD DE, (%s)", _string );

    // outline0( "CALL FPFASTTOA" );

    // ;Output:
    // ;   HL pointing to the string
    // outline0( "PUSH HL" );
    // outline0( "POP DE" );
    // outhead1( "%s:", label );
    // outline0( "LD A, (DE)" );
    // outline0( "CP 0" );
    // outline1( "JR Z, %s// done", label );
    // outline0( "INC DE" );
    // outline0( "INC C" );
    // outline1( "JR %s", label );
    // outhead1( "%s// done:", label );
    // outline0( "LD A, C" );
    // outline1( "LD (%s), A", _string_size );

    // ;Destroys:
    // ;   A,DE,BC
    // ;Notes:
    // ;   Uses up to 12 bytes to store the string

}

void sc61860_float_single_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_to_string" );

    MAKE_LABEL

    // deploy( fp_pushpop, src_hw_sc61860_fp_pushpop_asm );
    // deploy( fp_mul24_stack_based, src_hw_sc61860_fp_mul24_stack_based_asm );
    // deploy( fp_c_times_bde, src_hw_sc61860_fp_c_times_bde_asm );
    // deploy( fp_single_pow10_lut, src_hw_sc61860_fp_single_pow10_lut_asm );
    // deploy( fp_single_mul, src_hw_sc61860_fp_single_mul_asm );
    // deploy( fp_mov4, src_hw_sc61860_fp_mov4_asm );
    // deploy( fp_common_str, src_hw_sc61860_fp_common_str_asm );
    // deploy( fp_format_str, src_hw_sc61860_fp_format_str_asm );
    // deploy( fp_single_to_string, src_hw_sc61860_fp_single_to_string_asm );

    // ;converts a 32-bit float to a string

    // ;Inputs:
    // ;   HL points to the input float
    // ;   BC points to where the string gets written.

    // outline1( "LD HL, %s", _x );

    // outline1( "LD BC, (%s)", _string );

    // outline0( "CALL FPSINGLETOA" );

    // ;Output:
    // ;   HL pointing to the string
    // outline0( "PUSH HL" );
    // outline0( "POP DE" );
    // outhead1( "%s:", label );
    // outline0( "LD A, (DE)" );
    // outline0( "CP 0" );
    // outline1( "JR Z, %s// done", label );
    // outline0( "INC DE" );
    // outline0( "INC C" );
    // outline1( "JR %s", label );
    // outhead1( "%s// done:", label );
    // outline0( "LD A, C" );
    // outline1( "LD (%s), A", _string_size );

}

void sc61860_float_double_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_double_to_string" );

}

void sc61860_float_fast_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_from_16" );

    // deploy( fp_fast_from_16, src_hw_sc61860_fp_fast_from_16_asm );

    // outline1( "LD HL, (%s)", _value );
    if ( _signed ) {
        // outline0( "CALL FPFASTFROM16S");
    } else {
        // outline0( "CALL FPFASTFROM16U");
    }
    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_from_8" );

    // deploy( fp_fast_from_8, src_hw_sc61860_fp_fast_from_8_asm );

    // outline1( "LD A, (%s)", _value );
    if ( _signed ) {
        // outline0( "CALL FPFASTFROM8S");
    } else {
        // outline0( "CALL FPFASTFROM8U");
    }
    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_to_16" );

    // deploy( fp_fast_to_16, src_hw_sc61860_fp_fast_to_16_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _value );
    if ( _signed ) {
        // outline0( "CALL FPFASTTOS16");
    } else {
        // outline0( "CALL FPFASTTOU16");
    }
    // outline1( "LD (%s), HL", _result );

}

void sc61860_float_fast_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_to_8" );

    // deploy( fp_fast_to_8, src_hw_sc61860_fp_fast_to_8_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _value );
    if ( _signed ) {
        // outline0( "CALL FPFASTTOS8");
    } else {
        // outline0( "CALL FPFASTTOU8");
    }
    // outline1( "LD (%s), A", _result );

}

void sc61860_float_fast_add( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_add" );

    // deploy( fp_fast_add, src_hw_sc61860_fp_fast_add_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _y, "+2" ) );
    // outline0( "LD E, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _y, "+1" ) );
    // outline0( "LD D, A" );
    // outline1( "LD A, (%s)", _y );
    // outline0( "LD C, A" );

    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _x );
    // outline0( "CALL FPFASTADD");
    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_sub( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_sub" );

    // deploy( fp_fast_add, src_hw_sc61860_fp_fast_add_asm );
    // deploy( fp_fast_sub, src_hw_sc61860_fp_fast_sub_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _y, "+2" ) );
    // outline0( "LD E, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _y, "+1" ) );
    // outline0( "LD D, A" );
    // outline1( "LD A, (%s)", _y );
    // outline0( "LD C, A" );

    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _x );
    // outline0( "CALL FPFASTSUB");
    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_mul( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_mul" );

    // deploy( fp_mul16, src_hw_sc61860_fp_mul16_asm );
    // deploy( fp_fast_mul, src_hw_sc61860_fp_fast_mul_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _y, "+2" ) );
    // outline0( "LD E, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _y, "+1" ) );
    // outline0( "LD D, A" );
    // outline1( "LD A, (%s)", _y );
    // outline0( "LD C, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _x );
    // outline0( "CALL FPFASTMUL");
    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_div( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_div" );

    // deploy( fp_fast_div, src_hw_sc61860_fp_fast_div_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _y, "+2" ) );
    // outline0( "LD E, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _y, "+1" ) );
    // outline0( "LD D, A" );
    // outline1( "LD A, (%s)", _y );
    // outline0( "LD C, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _x );
    // outline0( "CALL FPFASTDIV");
    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_cmp" );

    MAKE_LABEL

    // deploy( fp_fast_add, src_hw_sc61860_fp_fast_add_asm );
    // deploy( fp_fast_sub, src_hw_sc61860_fp_fast_sub_asm );
    // deploy( fp_fast_cmp, src_hw_sc61860_fp_fast_cmp_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _y, "+2" ) );
    // outline0( "LD E, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _y, "+1" ) );
    // outline0( "LD D, A" );
    // outline1( "LD A, (%s)", _y );
    // outline0( "LD C, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _x );
    // outline0( "CALL FPFASTCMP");

    // outline1( "JR Z, %sequal", label );
    // outline1( "JR C, %sless", label );
    // outline0( "LD A, 1" );
    // outline1( "LD (%s), A", _result );
    // outline1( "JP %s// done", label );
    // outhead1( "%sequal:", label );
    // outline0( "LD A, 0" );
    // outline1( "LD (%s), A", _result );
    // outline1( "JP %s// done", label );
    // outhead1( "%sless:", label );
    // outline0( "LD A, 0xff" );
    // outline1( "LD (%s), A", _result );
    // outline1( "JP %s// done", label );
    // outhead1( "%s// done:", label );

}

void sc61860_float_fast_sin( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_sin" );

    MAKE_LABEL

    // deploy( fp_mul16, src_hw_sc61860_fp_mul16_asm );
    // deploy( fp_fast_add, src_hw_sc61860_fp_fast_add_asm );
    // deploy( fp_fast_sub, src_hw_sc61860_fp_fast_sub_asm );
    // deploy( fp_fast_mod1, src_hw_sc61860_fp_fast_mod1_asm );
    // deploy( fp_fast_sin, src_hw_sc61860_fp_fast_sin_asm );
    // deploy( fp_fast_mul, src_hw_sc61860_fp_fast_mul_asm );
    // deploy( fp_fast_sqr, src_hw_sc61860_fp_fast_sqr_asm );
    // deploy( fp_fast_cos, src_hw_sc61860_fp_fast_cos_asm );     
    // deploy( fp_fast_div, src_hw_sc61860_fp_fast_div_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _angle );

    // outline0( "CALL FPFASTSIN");

    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_cos( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_cos" );

    MAKE_LABEL

    // deploy( fp_mul16, src_hw_sc61860_fp_mul16_asm );
    // deploy( fp_fast_add, src_hw_sc61860_fp_fast_add_asm );
    // deploy( fp_fast_sub, src_hw_sc61860_fp_fast_sub_asm );
    // deploy( fp_fast_mod1, src_hw_sc61860_fp_fast_mod1_asm );
    // deploy( fp_fast_mul, src_hw_sc61860_fp_fast_mul_asm );
    // deploy( fp_fast_sqr, src_hw_sc61860_fp_fast_sqr_asm );
    // deploy( fp_fast_sin, src_hw_sc61860_fp_fast_cos_asm );
    // deploy( fp_fast_cos, src_hw_sc61860_fp_fast_sin_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _angle );
    
    // outline0( "CALL FPFASTCOS");

    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_tan( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_tan" );

    MAKE_LABEL

    // deploy( fp_fast_tan, src_hw_sc61860_fp_fast_tan_asm );
    // deploy( fp_fast_sin, src_hw_sc61860_fp_fast_sin_asm );
    // deploy( fp_fast_cos, src_hw_sc61860_fp_fast_cos_asm );     
    // deploy( fp_fast_div, src_hw_sc61860_fp_fast_div_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _angle );

    // outline0( "CALL FPFASTTAN");

    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_sqr( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_sqr" );

    MAKE_LABEL

    // deploy( fp_mul16, src_hw_sc61860_fp_mul16_asm );
    // deploy( fp_fast_mul, src_hw_sc61860_fp_fast_mul_asm );
    // deploy( fp_fast_sqr, src_hw_sc61860_fp_fast_sqr_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _value );
    
    // outline0( "CALL FPFASTSQR");

    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_mod1( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_mod1" );

    MAKE_LABEL

    // deploy( fp_fast_mod1, src_hw_sc61860_fp_fast_mod1_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _value );
    
    // outline0( "CALL FPFASTMOD1");

    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_fast_neg( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_fast_neg" );

    MAKE_LABEL

    // deploy( fp_fast_neg, src_hw_sc61860_fp_fast_neg_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _value );
    
    // outline0( "CALL FPFASTNEG");

    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_single_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_from_16" );

    // deploy( fp_pushpop, src_hw_sc61860_fp_pushpop_asm );
    // deploy( fp_single_from_16, src_hw_sc61860_fp_single_from_16_asm );

    // outline1( "LD HL, (%s)", _value );
    // outline1( "LD BC, %s", _result );
    if ( _signed ) {
        // outline0( "CALL FPSINGLEFROM16S");
    } else {
        // outline0( "CALL FPSINGLEFROM16U");
    }

}

void sc61860_float_single_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_from_8" );

    // deploy( fp_single_from_8, src_hw_sc61860_fp_single_from_8_asm );

    // outline1( "LD A, (%s)", _value );
    // outline1( "LD BC, %s", _result );
    if ( _signed ) {
        // outline0( "CALL FPSINGLEFROM8S");
    } else {
        // outline0( "CALL FPSINGLEFROM8U");
    }

}


void sc61860_float_single_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_to_16" );

    // deploy( fp_single_to_16, src_hw_sc61860_fp_single_to_16_asm );

    // outline1( "LD HL, %s", _value );
    if ( _signed ) {
        // outline0( "CALL FPSINGLETO16S");
    } else {
        // outline0( "CALL FPSINGLETO16U");
    }
    // outline1( "LD (%s), HL", _result );

}

void sc61860_float_single_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_to_8" );

    // deploy( fp_single_to_8, src_hw_sc61860_fp_single_to_8_asm );

    // outline1( "LD HL, %s", _value );
    if ( _signed ) {
        // outline0( "CALL FPSINGLETO8S");
    } else {
        // outline0( "CALL FPSINGLETO8U");
    }
    // outline1( "LD (%s), A", _result );

}

void sc61860_float_single_add( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_add" );

    // deploy( fp_pushpop, src_hw_sc61860_fp_pushpop_asm );
    // deploy( fp_single_add, src_hw_sc61860_fp_single_add_asm );

    // outline1( "LD DE, %s", _y );
    // outline1( "LD HL, %s", _x );
    // outline1( "LD BC, %s", _result );
    // outline0( "CALL FPSINGLEADD");
    
}

void sc61860_float_single_sub( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_sub" );

    // deploy( fp_pushpop, src_hw_sc61860_fp_pushpop_asm );
    // deploy( fp_single_sub, src_hw_sc61860_fp_single_sub_asm );
    // deploy( fp_single_add, src_hw_sc61860_fp_single_add_asm );

    // outline1( "LD DE, %s", _y );
    // outline1( "LD HL, %s", _x );
    // outline1( "LD BC, %s", _result );
    // outline0( "CALL FPSINGLESUB");
    
}

void sc61860_float_single_mul( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_mul" );

    // deploy( fp_pushpop, src_hw_sc61860_fp_pushpop_asm );
    // deploy( fp_single_mul, src_hw_sc61860_fp_single_mul_asm );

    // outline1( "LD DE, %s", _y );
    // outline1( "LD HL, %s", _x );
    // outline1( "LD BC, %s", _result );
    // outline0( "CALL FPSINGLEMUL");
    
}

void sc61860_float_single_div( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_div" );

    // deploy( fp_pushpop, src_hw_sc61860_fp_pushpop_asm );
    // deploy( fp_div24_24, src_hw_sc61860_fp_div24_24_asm );
    // deploy( fp_single_div, src_hw_sc61860_fp_single_div_asm );

    // outline1( "LD DE, %s", _y );
    // outline1( "LD HL, %s", _x );
    // outline1( "LD BC, %s", _result );
    // outline0( "CALL FPSINGLEDIV");
    
}

void sc61860_float_single_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_cmp" );

    MAKE_LABEL

    // deploy( fp_pushpop, src_hw_sc61860_fp_pushpop_asm );
    // deploy( fp_single_sub, src_hw_sc61860_fp_single_sub_asm );
    // deploy( fp_single_cmp, src_hw_sc61860_fp_single_cmp_asm );

    // outline1( "LD DE, %s", _y );
    // outline1( "LD HL, %s", _x );
    // outline0( "CALL FPSINGLECMP");

    // outline1( "JR Z, %sequal", label );
    // outline1( "JR C, %sless", label );
    // outline0( "LD A, 1" );
    // outline1( "LD (%s), A", _result );
    // outline1( "JP %s// done", label );
    // outhead1( "%sequal:", label );
    // outline0( "LD A, 0" );
    // outline1( "LD (%s), A", _result );
    // outline1( "JP %s// done", label );
    // outhead1( "%sless:", label );
    // outline0( "LD A, 0xff" );
    // outline1( "LD (%s), A", _result );
    // outline1( "JP %s// done", label );
    // outhead1( "%s// done:", label );

}

void sc61860_float_single_neg( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_neg" );

    // MAKE_LABEL

    // // deploy( fp_single_sub, src_hw_sc61860_fp_single_sub_asm );
    // // deploy( fp_single_mod1, src_hw_sc61860_fp_single_mod1_asm );
    // // deploy( fp_single_sin, src_hw_sc61860_fp_single_sin_asm );
    // // deploy( fp_single_mul, src_hw_sc61860_fp_single_mul_asm );
    // // deploy( fp_single_sqr, src_hw_sc61860_fp_single_sqr_asm );
    // // deploy( fp_single_cos, src_hw_sc61860_fp_single_cos_asm );     
    // // deploy( fp_single_div, src_hw_sc61860_fp_single_div_asm );

    // // outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+2" ) );
    // // outline0( "LD L, A" );
    // // outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+1" ) );
    // // outline0( "LD H, A" );
    // // outline1( "LD A, (%s)", _angle );

    // // outline0( "CALL FPFSINGLESIN");

    // // outline1( "LD (%s), A", _result );
    // // outline0( "LD A, H" );
    // // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // // outline0( "LD A, L" );
    // // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_single_sin( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_sin" );

    MAKE_LABEL

    // deploy( fp_single_vars, src_hw_sc61860_fp_single_vars_asm );
    // deploy( fp_single_sin, src_hw_sc61860_fp_single_sin_asm );
    // deploy( fp_single_cos, src_hw_sc61860_fp_single_cos_asm );
    // deploy( fp_single_sub, src_hw_sc61860_fp_single_sub_asm );
    // deploy( fp_single_mul, src_hw_sc61860_fp_single_mul_asm );
    // deploy( fp_single_add, src_hw_sc61860_fp_single_add_asm );
    // deploy( fp_single_neg, src_hw_sc61860_fp_single_neg_asm );
    // deploy( fp_single_mod1, src_hw_sc61860_fp_single_mod1_asm );
    // deploy( fp_single_abs, src_hw_sc61860_fp_single_abs_asm );
    // deploy( fp_single_horner_step, src_hw_sc61860_fp_single_horner_step_asm );

    // outline1( "LD HL, %s", _angle );
    // outline1( "LD BC, %s", _result );
    // outline0( "CALL FPSINGLESIN");
    // // outline0( "LD A, (HL)" );
    // // outline1( "LD (%s), A", _result );
    // // outline0( "INC HL" );
    // // outline0( "LD A, (HL)" );
    // // outline1( "LD (%s), A", _result );
    // // outline0( "INC HL" );
    // // outline0( "LD A, (HL)" );
    // // outline1( "LD (%s), A", _result );
    // // outline0( "INC HL" );
    // // outline0( "LD A, (HL)" );
    // // outline1( "LD (%s), A", _result );
    // // outline0( "INC HL" );

}

void sc61860_float_single_cos( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_cos" );

    MAKE_LABEL

    // deploy( fp_mul24_stack_based, src_hw_sc61860_fp_mul24_stack_based_asm );
    // deploy( fp_mov4, src_hw_sc61860_fp_mov4_asm );
    // deploy( fp_c_times_bde, src_hw_sc61860_fp_c_times_bde_asm );
    // deploy( fp_single_vars, src_hw_sc61860_fp_single_vars_asm );
    // deploy( fp_single_sin, src_hw_sc61860_fp_single_sin_asm );
    // deploy( fp_single_cos, src_hw_sc61860_fp_single_cos_asm );
    // deploy( fp_single_sub, src_hw_sc61860_fp_single_sub_asm );
    // deploy( fp_single_mul, src_hw_sc61860_fp_single_mul_asm );
    // deploy( fp_single_add, src_hw_sc61860_fp_single_add_asm );
    // deploy( fp_single_neg, src_hw_sc61860_fp_single_neg_asm );
    // deploy( fp_single_mod1, src_hw_sc61860_fp_single_mod1_asm );
    // deploy( fp_single_abs, src_hw_sc61860_fp_single_abs_asm );
    // deploy( fp_single_horner_step, src_hw_sc61860_fp_single_horner_step_asm );

    // outline1( "LD HL, %s", _angle );
    // outline1( "LD BC, %s", _result );
    // outline0( "CALL FPSINGLECOS");
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );

}

void sc61860_float_single_tan( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_tan" );

    MAKE_LABEL

    // deploy( fp_single_vars, src_hw_sc61860_fp_single_vars_asm );
    // deploy( fp_single_sin, src_hw_sc61860_fp_single_sin_asm );
    // deploy( fp_single_cos, src_hw_sc61860_fp_single_cos_asm );
    // deploy( fp_single_div, src_hw_sc61860_fp_single_div_asm );
    // deploy( fp_single_sin, src_hw_sc61860_fp_single_tan_asm );
    // deploy( fp_single_tan, src_hw_sc61860_fp_single_tan_asm );
    // deploy( fp_single_neg, src_hw_sc61860_fp_single_neg_asm );
    // deploy( fp_single_sub, src_hw_sc61860_fp_single_sub_asm );
    // deploy( fp_single_mul, src_hw_sc61860_fp_single_mul_asm );
    // deploy( fp_single_add, src_hw_sc61860_fp_single_add_asm );
    // deploy( fp_single_mod1, src_hw_sc61860_fp_single_mod1_asm );
    // deploy( fp_single_abs, src_hw_sc61860_fp_single_abs_asm );
    // deploy( fp_single_horner_step, src_hw_sc61860_fp_single_horner_step_asm );


    // outline1( "LD HL, %s", _angle );
    // outline1( "LD BC, %s", _result );
    // outline0( "CALL FPSINGLETAN");
    // // outline0( "LD A, (HL)" );
    // // outline1( "LD (%s), A", _result );
    // // outline0( "INC HL" );
    // // outline0( "LD A, (HL)" );
    // // outline1( "LD (%s), A", _result );
    // // outline0( "INC HL" );
    // // outline0( "LD A, (HL)" );
    // // outline1( "LD (%s), A", _result );
    // // outline0( "INC HL" );
    // // outline0( "LD A, (HL)" );
    // // outline1( "LD (%s), A", _result );
    // // outline0( "INC HL" );

}

void sc61860_float_single_sqr( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_sqr" );

    // MAKE_LABEL

    // // deploy( fp_single_mul, src_hw_sc61860_fp_single_mul_asm );
    // // deploy( fp_single_sqr, src_hw_sc61860_fp_single_sqr_asm );

    // // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    // // outline0( "LD L, A" );
    // // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    // // outline0( "LD H, A" );
    // // outline1( "LD A, (%s)", _value );
    
    // // outline0( "CALL FPsingleSQR");

    // // outline1( "LD (%s), A", _result );
    // // outline0( "LD A, H" );
    // // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // // outline0( "LD A, L" );
    // // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_float_single_mod1( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_float_single_mod1" );

    // MAKE_LABEL

    // // deploy( fp_single_mod1, src_hw_sc61860_fp_single_mod1_asm );

    // // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    // // outline0( "LD L, A" );
    // // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    // // outline0( "LD H, A" );
    // // outline1( "LD A, (%s)", _value );
    
    // // outline0( "CALL FPsingleMOD1");

    // // outline1( "LD (%s), A", _result );
    // // outline0( "LD A, H" );
    // // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // // outline0( "LD A, L" );
    // // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void sc61860_address_table_build( Environment * _environment, char * _table, int * _values, char *_address[], int _count ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_address_table_build" );

    // outhead1("%s:", _table );
    for( int i=0; i<_count; ++i ) {
        // outline2("DEFW 0x%4.4x, %s", _values[i], _address[i] );
    }

}

void sc61860_address_table_lookup( Environment * _environment, char * _table, int _count ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_address_table_lookup" );

    // outhead1("LOOKFOR%s:", _table );
    if ( _count ) {
        // outline1("LD HL, %s", _table );
        // outline0("LD C, 0" );
        // outhead1("LOOKFOR%sL1:", _table );
        // outline0("LD A, (HL)" );
        // outline0("INC HL" );
        // outline0("LD B, A" );
        // outline0("LD A, E" );
        // outline0("CP B" );
        // outline1("JR NZ, LOOKFOR%sNEXT3", _table );
        // outline0("LD A, (HL)" );
        // outline0("INC HL" );
        // outline0("LD B, A" );
        // outline0("LD A, D" );
        // outline0("CP B" );
        // outline1("JR NZ, LOOKFOR%sNEXT2", _table );
        // outline0("LD A, (HL)" );
        // outline0("INC HL" );
        // outline0("LD E, A" );
        // outline0("LD A, (HL)" );
        // outline0("INC HL" );
        // outline0("LD D, A" );
        // outline0("RET" );
        // outhead1("LOOKFOR%sNEXT3:", _table );
        // outline0("INC HL" );
        // outhead1("LOOKFOR%sNEXT2:", _table );
        // outline0("INC HL" );
        // outline0("INC HL" );
        // outline0("INC C" );
        // outline0("LD A, C" );
        // outline1("CP 0x%4.4x", (_count+1) );
        // outline1("JR NZ, LOOKFOR%sL1", _table );
    }
    // outline0("RET" );

}

void sc61860_address_table_call( Environment * _environment, char * _table, char * _value, char * _address ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_address_table_call" );

    // outline1("LD DE, (%s)", _value );
    // outline1("CALL LOOKFOR%s", _table );
    // outline1("LD (%s), DE", _address );

}

void sc61860_move_8bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination ) {

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_signed_16bit_signed(signed)" );

}

void sc61860_move_8bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_signed_16bit_unsigned(signed)" );

}

void sc61860_move_8bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_unsigned_16bit_signed(signed)" );

}

void sc61860_move_8bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    op_lda( _environment, _source );
    op_xab( _environment );
    op_lda_direct( _environment, 0 );
    op_stab( _environment, _destination );

}

void sc61860_move_8bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    MAKE_LABEL

    char positiveLabel[MAX_TEMPORARY_STORAGE];
    sprintf(positiveLabel, "%spos", label );

    op_lda(_environment, _source );
    op_sta(_environment, _destination );
    op_cp_direct(_environment, 0x80 );
    op_jc(_environment, positiveLabel );
    op_lda_direct( _environment, 0xff );
    op_jp( _environment, label );
    sc61860_label(_environment, positiveLabel );
    op_lda_direct( _environment, 0x00 );
    sc61860_label(_environment, label );
    op_sta(_environment, address_displacement( _environment, _destination, "1" ) );
    op_sta(_environment, address_displacement( _environment, _destination, "2" ) );
    op_sta(_environment, address_displacement( _environment, _destination, "3" ) );

}

void sc61860_move_8bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_signed_32bit_unsigned(signed)" );

}

void sc61860_move_8bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_unsigned_32bit_signed(signed)" );

}

void sc61860_move_8bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){
    
    CRITICAL_UNIMPLEMENTED( "sc61860_move_8bit_unsigned_32bit_unsigned" );

}

void sc61860_move_16bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_16bit_signed_8bit_signed(signed)" );

}
void sc61860_move_16bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    op_lda( _environment, _source );
    op_sta( _environment, _source );

}

void sc61860_move_16bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    op_lda( _environment, _source );
    op_sta( _environment, _source );

}

void sc61860_move_16bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    op_ldab( _environment, _source );
    op_xab( _environment );
    op_sta( _environment, _destination );

}

void sc61860_move_16bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_16bit_signed_32bit_signed(signed)" );

}

void sc61860_move_16bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_16bit_signed_32bit_unsigned(signed)" );

}

void sc61860_move_16bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_16bit_unsigned_32bit_signed(signed)" );

}

void sc61860_move_16bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){
    
    op_ldab( _environment, _source );
    op_stab( _environment, _destination );
    op_ldab_direct( _environment, 0 );
    op_stab( _environment, address_displacement( _environment, _destination, "2" ) );

}

void sc61860_move_32bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_32bit_signed_8bit_signed(signed)" );


}
void sc61860_move_32bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_32bit_signed_8bit_unsigned(signed)" );

}
void sc61860_move_32bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_32bit_unsigned_8bit_signed(signed)" );

}

void sc61860_move_32bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    op_lda( _environment, _source );
    op_sta( _environment, _destination );

}

void sc61860_move_32bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_32bit_signed_16bit_signed(signed)" );

}

void sc61860_move_32bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){


    CRITICAL_UNIMPLEMENTED( "sc61860_move_32bit_signed_16bit_unsigned(signed)" );

}

void sc61860_move_32bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    CRITICAL_UNIMPLEMENTED( "sc61860_move_32bit_unsigned_16bit_signed(signed)" );

}

void sc61860_move_32bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){
    
    op_ldab( _environment, _source );
    op_stab( _environment, _destination );

}

void sc61860_float_fast_log( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("LOG");

}

void sc61860_float_single_log( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("LOG");

}

void sc61860_float_fast_exp( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("EXP");

}

void sc61860_float_single_exp( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("EXP");

}


#endif