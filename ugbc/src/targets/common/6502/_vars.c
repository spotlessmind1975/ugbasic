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

#if defined(__atari__) || defined(__atarixl__) || defined(__c64__) || defined(__c64reu__) || defined(__c128__) || defined(__plus4__) || defined(__vic20__) || defined(__c16__)

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

void vars_emit_constant_integer( Environment * _environment, char * _name, int _value ) {

    outhead2("%s = $%4.4x", _name, _value );

}

void vars_emit_constant_integer_relative( Environment * _environment, char * _name, char * _relative, int _value ) {

    outhead3("%s = %s+$%4.4x", _name, _relative, _value );

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
        outline2("%s: .byte $%2.2x", _name, (unsigned char)( _value & 0xff ) );
    } else {
        outline1(" .byte $%2.2x", (unsigned char)( _value & 0xff ) );
    }
}

void vars_emit_word( Environment * _environment, char * _name, int _value ) {
    if ( _name ) {
        outline2("%s:  .word $%4.4x", _name, (unsigned int)( _value & 0xffff ) );
    } else {
        outline1(" .word $%4.4x", (unsigned int)( _value & 0xffff ) );
    }
}

void vars_emit_dword( Environment * _environment, char * _name, int _value ) {
    if ( _name ) {
        outline2("%s:  .dword $%8.8x", _name, (unsigned int)( _value & 0xffffffff ) );
    } else {
        outline1(" .dword $%8.8x", (unsigned int)( _value & 0xffffffff ) );
    }
}

void vars_emit_number( Environment * _environment, char * _name, int _value ) {
    if ( _name ) {
        outline2("%s:  .dword $%8.8x", _name, (unsigned int)( _value & 0xffffffff ) );
        outline1("  .res %d", _environment->numberConfig.maxBytes - 4 );
    } else {
        outline1(" .dword $%8.8x", (unsigned int)( _value & 0xffffffff ) );
        outline1("  .res %d", _environment->numberConfig.maxBytes - 4 );
    }
}

#endif