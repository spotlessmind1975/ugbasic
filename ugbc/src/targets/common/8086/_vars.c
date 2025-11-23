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

#if defined(__pccga__)

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

void vars_emit_constant_integer( Environment * _environment, char * _name, int _value ) {

    outhead2("%s EQU 0x%4.4x", _name, _value );

}

void vars_emit_constant_integer_relative( Environment * _environment, char * _name, char * _relative, int _value ) {

    outhead3("%s EQU %s+0x%4.4x", _name, _relative, _value );

}

void vars_emit_constants( Environment * _environment ) {

    int i=0;

    if ( _environment->constants ) {
        Constant * actual = _environment->constants;
        while( actual ) {
            if ( ! actual->emitted ) {
                switch( actual->type ) {
                    case CT_INTEGER:
                        if ( actual->relative ) {
                            vars_emit_constant_integer_relative( _environment, actual->realName, actual->relative, actual->value );
                        } else {
                            vars_emit_constant_integer( _environment, actual->realName, actual->value );
                        }
                        break;
                    case CT_STRING:
                    break;
                }
            }
            actual = actual->next;
        }
    }

}

void vars_emit_byte( Environment * _environment, char * _name, int _value ) {
    if ( _name ) {
        outhead2("%s: db 0x%2.2x", _name, (unsigned char)( _value & 0xff ) );
    } else {
        outline1(" db 0x%2.2x", (unsigned char)( _value & 0xff ) );
    }
}

void vars_emit_word( Environment * _environment, char * _name, int _value ) {
    if ( _name ) {
        outhead2("%s:  dw 0x%4.4x", _name, (unsigned short)( _value & 0xffff ) );
    } else {
        outline1(" dw 0x%4.4x", (unsigned short)( _value & 0xffff ) );
    }
}

void vars_emit_dword( Environment * _environment, char * _name, int _value ) {
    if ( _name ) {
        outhead3("%s:  dw 0x%4.4x,0x%4.4x", _name, (unsigned short)( _value & 0xffff ), (unsigned short)( (_value>>16) & 0xffffffff ) );
    } else {
        outhead2(" dw 0x%4.4x,0x%4.4x", (unsigned short)( _value & 0xffff ), (unsigned short)( (_value>>16) & 0xffffffff ) );
    }
}

void vars_emit_number( Environment * _environment, char * _name, int _value ) {
    if ( _name ) {
        outhead3("%s:  dw 0x%4.4x,0x%4.4x", _name, (unsigned short)( _value & 0xffff ), (unsigned short)( (_value>>16) & 0xffffffff ) );
        outhead1("    times %d db 0x00", _environment->numberConfig.maxBytes - 4 );
    } else {
        outhead2(" dw 0x%4.4x,0x%4.4x", (unsigned short)( _value & 0xffff ), (unsigned short)( (_value>>16) & 0xffffffff ) );
        outhead1("    times %d db 0x00", _environment->numberConfig.maxBytes - 4 );
    }
}

void vars_emit_strips( Environment * _environment, char * _name, Strip * _strips ) {

    int maxId = 0;
    Strip * actual = _strips;
    while( actual ) {
        if ( maxId < actual->id ) {
            maxId = actual->id+1;
        }
        actual = actual->next;
    }
    int i=0;
    for( i=0; i<maxId; ++i ) {
        Strip * actual = _strips;
        while( actual ) {
            if ( actual->id == i ) {
                outhead2("%sstrip%d:", _name, i );
                for( int j=0; j<actual->count; ++j ) {
                    outline1( "db 0x%2.2x", actual->frames[j] );
                }
            }
            actual = actual->next;
        }
    }
    
    actual = _strips;
    i = 0;
    outhead1("%sstrip:", _name );

    for( i=0; i<maxId; ++i ) {
        Strip * actual = _strips;
        while( actual ) {
            if ( actual->id == i ) {
                outline2("dw %sstrip%d", _name, i );
                break;
            }
            actual = actual->next;
        }
        if ( ! actual ) {
            outline0("dw 0x0000" );
        }
    }

}

#endif