/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

static void blit_define_bltu( Environment * _environment, int _op, char * _a, char * _c ) {

    if ( _op == ( 1 << _environment->currentModeBW ) + 3 ) {

        MAKE_LABEL
        outline0("; bltu C = (2^bpp-1) if A > 0 (threshold)");
        switch( _environment->currentModeBW ) {
            case 1:
                outline1("LD A, %s", _a );
                outline1("LD %s, A", _c );
                break;
            case 2:
                outline0("LD A, 0" );
                outline1("LD %s, A", _c );
                outline1("LD A, %s", _a );
                outline0("AND $11" );
                outline0("CMP 0" );
                outline1("JR Z, %sthreshold1", label );
                outline0("LD A, $11" );
                outline1("LD %s, A", _c );
                outhead1("%sthreshold1:", label );
                outline1("LD A, %s", _a );
                outline0("AND $22" );
                outline0("CMP 0" );
                outline1("JR Z, %sthreshold2", label );
                outline0("LD A, $22" );
                outline1("OR %s", _c );
                outline1("LD %s, A", _c );
                outhead1("%sthreshold2:", label );
                outline1("LD A, %s", _a );
                outline0("AND $44" );
                outline0("CMP 0" );
                outline1("JR Z, %sthreshold3", label );
                outline0("LD A, $44" );
                outline1("OR %s", _c );
                outline1("LD %s, A", _c );
                outhead1("%sthreshold3:", label );
                outline1("LD A, %s", _a );
                outline0("AND $88" );
                outline0("CMP 0" );
                outline1("JR Z, %sthreshold4", label );
                outline0("LD A, $88" );
                outline1("OR %s", _c );
                outline1("LD %s, A", _c );
                outhead1("%sthreshold4:", label );
                break;
            case 4:
                outline0("LD A, 0" );
                outline1("LD %s, A", _c );
                outline1("LD A, %s", _a );
                outline0("AND $aa" );
                outline0("CMP 0" );
                outline1("JR Z, %sthreshold1", label );
                outline0("LD A, $aa" );
                outline1("LD %s, A", _c );
                outhead1("%sthreshold1:", label );
                outline1("LD A, %s", _a );
                outline0("AND $55" );
                outline0("CMP 0" );
                outline1("JR Z, %sthreshold2", label );
                outline0("LD A, $55" );
                outline1("OR %s", _c );
                outline1("LD %s, A", _c );
                outhead1("%sthreshold2:", label );
                break;
        }
    } else if ( _op == ( 1 << _environment->currentModeBW ) + 2 ) {
        outline0("; bltu C = 0 (ignore)");
        outline0("LD A, 0" );
        outline1("LD %s, A", _c );
    } else if ( _op == ( 1 << _environment->currentModeBW ) + 1 ) {
        outline0("; bltu C = !A (not)");
        outline1("LD A, %s", _a );
        outline0("XOR $ff");
        outline1("LD %s, A", _c );
    } else if ( _op == ( 1 << _environment->currentModeBW ) ) {
        outline0("; bltu C = A (copy)");
        outline1("LD A, %s", _a );
        outline1("LD %s, A", _c );
    } else if ( _op < ( 1 << _environment->currentModeBW ) ) {
        unsigned char value = 0;
        switch( _environment->currentModeBW ) {
            case 1:
                if ( _op ) {
                    value = 0xff;
                } else {
                    value = 0x00;
                }
                break;
            case 2:
                value = ( ( _op & 0x1 ) );
                value |= ( ( ( _op & 0x2 ) ) << 3 );
                value = value | ( value << 1 ) | ( value << 2 ) | ( value << 3 );
                break;
            case 4:
                value = ( ( _op & 0x8 ) >> 3 );
                value |= ( ( ( _op & 0x2 ) ) << 1 );
                value |= ( ( ( _op & 0x4 ) ) << 2 );
                value |= ( ( ( _op & 0x1 ) ) << 6 );
                value = value | ( value << 1 );
                break;
        }        
        outline0("; bltu C = value");
        outline1("LD A, $%2.2x", value );
        outline1("LD %s, A", _c );
    }

}

static void blit_define_bltb( Environment * _environment, int _op, char * _a, char * _b, char * _d ) {

    if ( _op == 0 ) {
        outline0("; bltb C = A and B");
        outline1("LD A, %s", _a );
        outline1("LD %s, A", _d );
        outline1("LD A, %s", _b );
        outline1("AND %s", _d );
        outline1("LD %s, A", _d );
    } else if ( _op == 1 ) {
        outline0("; bltb C = A or B");
        outline1("LD A, %s", _a );
        outline1("LD %s, A", _d );
        outline1("LD A, %s", _b );
        outline1("OR %s", _d );
        outline1("LD %s, A", _d );
    } else if ( _op == 2 ) {
        outline0("; bltb C = A xor B");
        outline1("LD A, %s", _a );
        outline1("LD %s, A", _d );
        outline1("LD A, %s", _b );
        outline1("XOR %s", _d );
        outline1("LD %s, A", _d );
    } else if ( _op == 3 ) {
        outline0("; bltb C = A");
        outline1("LD A, %s", _a );
        outline1("LD %s, A", _d );
    } else if ( _op == 4 ) {
        outline0("; bltb C = B");
        outline1("LD A, %s", _b );
        outline1("LD %s, A", _d );
    } else if ( _op == 5 ) {
        outline0("; bltb C = A if B>0, 0 if B=0");
        MAKE_LABEL
        switch( _environment->currentModeBW ) {
            case 1:
                outline1("LD A, %s", _a );
                outline1("AND %s", _b );
                outline1("LD %s, A", _d );
                break;
            case 2:
                outline1("LD A, %s", _a );
                outline1("LD %s, A", _d );
                outline1("LD A, %s", _b );
                outline0("AND $11" );
                outline0("CMP 0" );
                outline1("JR NZ, %smask1", label );
                outline1("LD A, %s", _d );
                outline0("AND $ee" );
                outline1("LD %s, A", _d );
                outhead1("%smask1:", label );
                outline1("LD A, %s", _b );
                outline0("AND $22" );
                outline0("CMP 0" );
                outline1("JR NZ, %smask2", label );
                outline1("LD A, %s", _d );
                outline0("AND $dd" );
                outline1("LD %s, A", _d );
                outhead1("%smask2:", label );
                outline1("LD A, %s", _b );
                outline0("AND $44" );
                outline0("CMP 0" );
                outline1("JR NZ, %smask3", label );
                outline1("LD A, %s", _d );
                outline0("AND $bb" );
                outline1("LD %s, A", _d );
                outhead1("%smask3:", label );
                outline1("LD A, %s", _b );
                outline0("AND $88" );
                outline0("CMP 0" );
                outline1("JR NZ, %smask4", label );
                outline1("LD A, %s", _d );
                outline0("AND $77" );
                outline1("LD %s, A", _d );
                outhead1("%smask4:", label );
                break;
            case 4:
                outline1("LD A, %s", _a );
                outline1("LD %s, A", _d );
                outline1("LD A, %s", _b );
                outline0("AND $aa" );
                outline0("CMP 0" );
                outline1("JR NZ, %smask1", label );
                outline1("LD A, %s", _d );
                outline0("AND $55" );
                outline1("LD %s, A", _d );
                outhead1("%smask1:", label );
                outline1("LD A, %s", _b );
                outline0("AND $55" );
                outline0("CMP 0" );
                outline1("JR NZ, %smask2", label );
                outline1("LD A, %s", _d );
                outline0("AND $aa" );
                outline1("LD %s, A", _d );
                outhead1("%smask2:", label );
                break;
        }
    }

}

/**
 * @brief Emit ASM code for <b>BLIT IMAGE [image] AT [int],[int]</b>
 * 
 * This function outputs a code that draws an image on a bitmap. 
 * 
 * @param _environment Current calling environment
 * @param _image Image to draw
 * @param _x Abscissa of the point to draw
 * @param _y Ordinate of the point
 */
/* <usermanual>
@keyword BLIT IMAGE
</usermanual> */
void blit_define( Environment * _environment, char * _name, int _sop, int _mop, int _smop, int _iop, int _dop, int _idop, int _top ) {

    char blitLabel[MAX_TEMPORARY_STORAGE]; sprintf( blitLabel, "_%sblit", _name );
    char skipLabel[MAX_TEMPORARY_STORAGE]; sprintf( skipLabel, "_%sskip", _name );

    cpu_jump( _environment, skipLabel );
    cpu_label( _environment, blitLabel );

    // B = s(x,y)
    // IYL = d(x, y)
    // IYH = m(x, y)

    outline0("PUSH HL");
    outline0("PUSH DE");

    // BLITSU
    blit_define_bltu( _environment, _sop, "B", "H" );

    // BLITMU
    blit_define_bltu( _environment, _mop, "IYH", "L" );

    // BLITSM
    blit_define_bltb( _environment, _smop, "H", "L", "D" );

    // BLITSMU
    blit_define_bltu( _environment, _iop, "D", "H" );

    // BLITDU
    blit_define_bltu( _environment, _dop, "IYL", "L" );

    // BLITT
    blit_define_bltb( _environment, _idop, "H", "L", "D" );

    // BLITTU
    blit_define_bltu( _environment, _top, "D", "E" );

    outline0("LD A, E");
    outline0("POP DE");
    outline0("POP HL");

    cpu_return( _environment );
    cpu_label( _environment, skipLabel );

}

static const char BLIT_SOURCES_REGISTER[][4] = {
    "IYL",  // destination
    "B",    // source 1
    "IYH",  // source 2
};

void blit_define_begin_compound( Environment * _environment, char * _name ) {

    char blitLabel[MAX_TEMPORARY_STORAGE]; sprintf( blitLabel, "_%sblit", _name );
    char skipLabel[MAX_TEMPORARY_STORAGE]; sprintf( skipLabel, "_%sskip", _name );

    if ( variable_exists( _environment, _name ) ) {
        CRITICAL_BLIT_ALREADY_DEFINED( _name );   
    }
    Variable * var = variable_define( _environment, _name, VT_BLIT, 0 );
    
    memset( &_environment->blit, 0, sizeof( Blit ) );

    _environment->blit.name = strdup( _name );
    _environment->blit.realName = strdup( var->realName );

    cpu_jump( _environment, skipLabel );
    cpu_label( _environment, blitLabel );

    cpu_blit_initialize( _environment );

}

void blit_define_compound_operand_to_register( Environment * _environment, int _register, int _source ) {

    char * reg = cpu_blit_register_name( _environment, _register ) ;

    outline1( "LD A, %s", &BLIT_SOURCES_REGISTER[_source][0] );
    outline1( "LD %s, A", reg );

}

void blit_define_compound_unary( Environment * _environment, int _operation, int _operand, int _result ) {

    blit_define_bltu( _environment, _operation, cpu_blit_register_name( _environment, _operand ), cpu_blit_register_name( _environment, _result ) );

}

void blit_define_compound_binary( Environment * _environment, int _operation, int _operand1, int _operand2, int _result ) {

    blit_define_bltb( _environment, _operation, cpu_blit_register_name( _environment, _operand1 ), cpu_blit_register_name( _environment, _operand2 ), cpu_blit_register_name( _environment, _result ) );

}

void blit_define_end_compound( Environment * _environment, int _result ) {
    
    char skipLabel[MAX_TEMPORARY_STORAGE]; sprintf( skipLabel, "_%sskip", _environment->blit.name );
    char blitStageAreaName[MAX_TEMPORARY_STORAGE]; sprintf( blitStageAreaName, "%sbs", _environment->blit.name );

    Variable * blitStageArea = variable_define( _environment, blitStageAreaName, VT_BUFFER, 0 );
    variable_resize_buffer( _environment, blitStageArea->name, _environment->blit.usedMemory );

    char * reg = cpu_blit_register_name( _environment, _result ) ;

    outline1( "LD A, %s", reg );

    cpu_blit_finalize( _environment );

    cpu_return( _environment );
    cpu_label( _environment, skipLabel );

}
