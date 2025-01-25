/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

/**
 * @brief Emit ASM code for <b>PUT IMAGE [image] AT [int],[int]</b>
 * 
 * This function outputs a code that draws an image on a bitmap. 
 * 
 * @param _environment Current calling environment
 * @param _image Image to draw
 * @param _x Abscissa of the point to draw
 * @param _y Ordinate of the point
 */

void put_image_vars_original( Environment * _environment, char * _image, char * _x1, char * _y1, char * _x2, char * _y2, char * _frame, char * _sequence, char * _flags ) {

    if ( _environment->emptyProcedure ) {
        return;
    }

    MAKE_LABEL
    
    Variable * image = variable_retrieve( _environment, _image );

    Resource * resource = build_resource_for_sequence( _environment, _image, _frame, _sequence );

    Variable * x1 = variable_retrieve_or_define( _environment, _x1, VT_POSITION, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_POSITION, 0 );
    Variable * frame = NULL;
    if ( _frame) {
        frame = variable_retrieve_or_define( _environment, _frame, VT_BYTE, 0 );
    }
    Variable * sequence = NULL;
    if ( _sequence) {
        sequence = variable_retrieve_or_define( _environment, _sequence, VT_BYTE, 0 );
    }

    switch( resource->type ) {
        case VT_SEQUENCE:
            return;
            if ( image->bankAssigned != -1 ) {
                
                char alreadyLoadedLabel[MAX_TEMPORARY_STORAGE];
                sprintf(alreadyLoadedLabel, "%salready", label );

                char bankWindowId[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowId, "BANKWINDOWID%2.2x", image->residentAssigned );

                char bankWindowName[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                // cpu_compare_and_branch_16bit_const( _environment, bankWindowId, image->variableUniqueId, alreadyLoadedLabel, 1 );
                // if ( image->uncompressedSize ) {
                //     bank_uncompress_semi_var( _environment, image->bankAssigned, image->absoluteAddress, bankWindowName );
                // } else {
                //     bank_read_semi_var( _environment, image->bankAssigned, image->absoluteAddress, bankWindowName, image->size );
                // }
                // cpu_store_16bit(_environment, bankWindowId, image->variableUniqueId );
                // cpu_label( _environment, alreadyLoadedLabel );

                Variable * frameSize = variable_temporary( _environment, VT_WORD, "(temporary)");
                variable_store( _environment, frameSize->name, image->frameSize );
                Variable * bank = variable_temporary( _environment, VT_BYTE, "(temporary)");
                variable_store( _environment, bank->name, image->bankAssigned );
                Variable * offset = variable_temporary( _environment, VT_ADDRESS, "(temporary)");

                if ( !sequence ) {
                    if ( !frame ) {
                        gb_calculate_sequence_frame_offset(_environment, offset->realName, "", "", image->frameSize, image->frameCount );
                    } else {
                        gb_calculate_sequence_frame_offset(_environment, offset->realName, "", frame->realName, image->frameSize, image->frameCount );
                    }
                } else {
                    if ( !frame ) {
                        gb_calculate_sequence_frame_offset(_environment, offset->realName, sequence->realName, "", image->frameSize, image->frameCount );
                    } else {
                        gb_calculate_sequence_frame_offset(_environment, offset->realName, sequence->realName, frame->realName, image->frameSize, image->frameCount );
                    }
                }

                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                variable_store( _environment, address->name, image->absoluteAddress );
                variable_add_inplace_vars( _environment, address->name, offset->name );
                bank_read_vars_direct( _environment, bank->name, address->name, bankWindowName, frameSize->name );

                Resource resource;
                resource.realName = strdup( bankWindowName );
                resource.isAddress = 0;

                gb_put_image( _environment, &resource, x1->realName, y1->realName, NULL, NULL, image->frameSize, 0, _flags );

            } else {
                if ( !sequence ) {
                    if ( !frame ) {
                        gb_put_image( _environment, resource, x1->realName, y1->realName, "", "", image->frameSize, image->frameCount, _flags );
                    } else {
                        gb_put_image( _environment, resource, x1->realName, y1->realName, frame->realName, "", image->frameSize, image->frameCount, _flags );
                    }
                } else {
                    if ( !frame ) {
                        gb_put_image( _environment, resource, x1->realName, y1->realName, "", sequence->realName, image->frameSize, image->frameCount, _flags );
                    } else {
                        gb_put_image( _environment, resource, x1->realName, y1->realName, frame->realName, sequence->realName, image->frameSize, image->frameCount, _flags );
                    }
                }
            }
            break;
        case VT_IMAGES:
            return;
            if ( image->bankAssigned != -1 ) {
                
                char alreadyLoadedLabel[MAX_TEMPORARY_STORAGE];
                sprintf(alreadyLoadedLabel, "%salready", label );

                char bankWindowId[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowId, "BANKWINDOWID%2.2x", image->residentAssigned );

                char bankWindowName[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                // cpu_compare_and_branch_16bit_const( _environment, bankWindowId, image->variableUniqueId, alreadyLoadedLabel, 1 );
                // if ( image->uncompressedSize ) {
                //     bank_uncompress_semi_var( _environment, image->bankAssigned, image->absoluteAddress, bankWindowName );
                // } else {
                //     bank_read_semi_var( _environment, image->bankAssigned, image->absoluteAddress, bankWindowName, image->size );
                // }
                // cpu_store_16bit(_environment, bankWindowId, image->variableUniqueId );
                // cpu_label( _environment, alreadyLoadedLabel );

                Variable * frameSize = variable_temporary( _environment, VT_WORD, "(temporary)");
                variable_store( _environment, frameSize->name, image->frameSize );
                Variable * bank = variable_temporary( _environment, VT_BYTE, "(temporary)");
                variable_store( _environment, bank->name, image->bankAssigned );
                Variable * offset = variable_temporary( _environment, VT_ADDRESS, "(temporary)");

                if ( !frame ) {
                    gb_calculate_sequence_frame_offset(_environment, offset->realName, NULL, "", image->frameSize, 0 );
                } else {
                    gb_calculate_sequence_frame_offset(_environment, offset->realName, NULL, frame->realName, image->frameSize, 0 );
                }

                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                variable_store( _environment, address->name, image->absoluteAddress );
                variable_add_inplace_vars( _environment, address->name, offset->name );
                bank_read_vars_direct( _environment, bank->name, address->name, bankWindowName, frameSize->name );

                Resource resource;
                resource.realName = strdup( bankWindowName );
                resource.isAddress = 0;

                gb_put_image( _environment, &resource, x1->realName, y1->realName, NULL, NULL, image->frameSize, 0, _flags );
                
            } else {
                if ( !frame ) {
                    gb_put_image( _environment, resource, x1->realName, y1->realName, "", NULL, image->frameSize, 0, _flags );
                } else {
                    gb_put_image( _environment, resource, x1->realName, y1->realName, frame->realName, NULL, image->frameSize, 0, _flags );
                }
            }
            break;
        case VT_IMAGE:
        case VT_TARRAY:
            if ( image->bankAssigned != -1 ) {

                char alreadyLoadedLabel[MAX_TEMPORARY_STORAGE];
                sprintf(alreadyLoadedLabel, "%salready", label );

                char bankWindowId[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowId, "BANKWINDOWID%2.2x", image->residentAssigned );

                char bankWindowName[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                cpu_compare_and_branch_16bit_const( _environment, bankWindowId, image->variableUniqueId, alreadyLoadedLabel, 1 );
                if ( image->uncompressedSize ) {
                    bank_uncompress_semi_var( _environment, image->bankAssigned, image->absoluteAddress, bankWindowName );
                } else {
                    bank_read_semi_var( _environment, image->bankAssigned, image->absoluteAddress, bankWindowName, image->size );
                }
                cpu_store_16bit(_environment, bankWindowId, image->variableUniqueId );
                cpu_label( _environment, alreadyLoadedLabel );

                Resource resource;
                resource.realName = strdup( bankWindowName );
                resource.isAddress = 0;

                gb_put_image( _environment, &resource, x1->realName, y1->realName, NULL, NULL, 1, 0, _flags );
            } else {
                gb_put_image( _environment, resource, x1->realName, y1->realName, NULL, NULL, 1, 0, _flags );
            }
            break;
        default:
            CRITICAL_PUT_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }


}

void put_image_vars_imageref( Environment * _environment, char * _image, char * _x1, char * _y1,  char * _x2, char * _y2, char * _frame, char * _sequence, char * _flags ) {

    MAKE_LABEL

    Variable * image = variable_retrieve( _environment, _image );

    Variable * x1 = variable_retrieve_or_define( _environment, _x1, VT_POSITION, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_POSITION, 0 );
    Variable * frame = NULL;
    if ( _frame) {
        frame = variable_retrieve_or_define( _environment, _frame, VT_BYTE, 0 );
    }
    Variable * sequence = NULL;
    if ( _sequence) {
        sequence = variable_retrieve_or_define( _environment, _sequence, VT_BYTE, 0 );
    }

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(stub)" );

    // Y = OFFSET

    if ( !_sequence && !_frame ) {
        outline1("LD HL, (%s)", image->realName );
    } else {
        outline1("LD HL, (%s)", image->realName );

        if ( _sequence ) {
            outline0("LD DE, $0003" );
            outline0("ADD HL, DE" );
            if ( strlen(_sequence) == 0 ) {

            } else {
                outline1("LD A, (%s)", sequence->realName );
                outline0("PUSH HL" );
                outline0("POP IX" );
                cpu_call_indirect( _environment, address_displacement( _environment, image->realName, "10") );
            }
            if ( _frame ) {
                if ( strlen(_frame) == 0 ) {

                } else {
                    outline1("LD A, (%s)", frame->realName );
                    outline0("PUSH HL" );
                    outline0("POP IX" );
                    cpu_call_indirect( _environment, address_displacement( _environment, image->realName, "8") );
                }
            }

        } else {

            if ( _frame ) {
                outline0("LD DE, $0003" );
                outline0("ADD HL, DE" );
                if ( strlen(_frame) == 0 ) {

                } else {
                    outline0("PUSH HL" );
                    outline0("POP IX" );
                    outline1("LD A, (%s)", frame->realName );
                    cpu_call_indirect( _environment, address_displacement( _environment, image->realName, "8") );
                }
            }

        }

    }
    outline1("LD (%s), HL", address->realName );

    Resource resource;
    resource.realName = strdup( address->realName );
    resource.isAddress = 1;

    gb_put_image( _environment, &resource, x1->realName, y1->realName, NULL, NULL, 0, 0, _flags );

}

void put_image_vars( Environment * _environment, char * _image, char * _x1, char * _y1, char * _x2, char * _y2, char * _frame, char * _sequence, char * _flags ) {
    
    if ( _environment->emptyProcedure ) {
        return;
    }

    Variable * image = variable_retrieve( _environment, _image );

    switch( image->type ) {
        case VT_IMAGE:
        case VT_IMAGES:
        case VT_SEQUENCE:
        case VT_ADDRESS:
            put_image_vars_original( _environment, _image, _x1, _y1, _x2, _y2, _frame, _sequence, _flags );
            break;
        case VT_IMAGEREF:
            put_image_vars_imageref( _environment, _image, _x1, _y1, _x2, _y2, _frame, _sequence, _flags );
            break;            
        default:
            CRITICAL_PUT_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }

}

void put_image_vars_flags( Environment * _environment, char * _image, char * _x1, char * _y1, char * _x2, char * _y2, char * _frame, char * _sequence, int _flags ) {

    char flagsConstantName[MAX_TEMPORARY_STORAGE]; sprintf( flagsConstantName, "PUTIMAGEFLAGS%4.4x", _flags );
    char flagsConstantParameter[MAX_TEMPORARY_STORAGE]; sprintf( flagsConstantParameter, "PUTIMAGEFLAGS%4.4x", _flags );
    
    Constant * flagsConstant = constant_find( _environment->constants, flagsConstantName );
    
    if ( !flagsConstant ) {
        flagsConstant = malloc( sizeof( Constant ) );
        memset( flagsConstant, 0, sizeof( Constant ) );
        flagsConstant->name = strdup( flagsConstantName );
        flagsConstant->realName = strdup( flagsConstantName );
        flagsConstant->value = _flags;
        flagsConstant->type = CT_INTEGER;
        flagsConstant->next = _environment->constants;
        _environment->constants = flagsConstant;
    }

    put_image_vars( _environment, _image, _x1, _y1, _x2, _y2, _frame, _sequence, flagsConstantParameter );
}
