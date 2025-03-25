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

    switch( resource->type ) {
        case VT_SEQUENCE:
            if ( image->bankAssigned != -1 ) {
                
                char alreadyLoadedLabel[MAX_TEMPORARY_STORAGE];
                sprintf(alreadyLoadedLabel, "%salready", label );

                char bankWindowId[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowId, "(BANKWINDOW%2.2x-2)", image->residentAssigned );

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

                // Variable * frameSize = variable_temporary( _environment, VT_WORD, "(temporary)");
                // variable_store( _environment, frameSize->name, image->frameSize );
                // Variable * bank = variable_temporary( _environment, VT_BYTE, "(temporary)");
                // variable_store( _environment, bank->name, image->bankAssigned );
                // Variable * offset = variable_temporary( _environment, VT_ADDRESS, "(temporary)");

                outline1("LDY #$%4.4x", image->absoluteAddress );

                if ( !_sequence ) {
                    if ( !_frame ) {
                        ef936x_calculate_sequence_frame_offset_regy(_environment, "", "", image->frameSize, image->frameCount );
                    } else {
                        ef936x_calculate_sequence_frame_offset_regy(_environment, "", _frame, image->frameSize, image->frameCount );
                    }
                } else {
                    if ( !_frame ) {
                        ef936x_calculate_sequence_frame_offset_regy(_environment, _sequence, "", image->frameSize, image->frameCount );
                    } else {
                        ef936x_calculate_sequence_frame_offset_regy(_environment, _sequence, _frame, image->frameSize, image->frameCount );
                    }
                }

                // Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                // variable_store( _environment, address->name, image->absoluteAddress );
                // variable_add_inplace_vars( _environment, address->name, offset->name );
                // bank_read_vars_direct( _environment, bank->name, address->name, bankWindowName, frameSize->name );
                // cpu_math_add_16bit_const( _environment, offset->realName, image->absoluteAddress, offset->realName );

                // Optimization: inline read from bank.

                // bank_read_vars_bank_direct_size_vars( _environment, image->bankAssigned, offset->name, bankWindowName, image->frameSize );

                deploy_preferred( duff, src_hw_6809_duff_asm );
                deploy_preferred( msc1, src_hw_6809_msc1_asm );
                deploy_preferred( bank, src_hw_pc128op_bank_asm );

                outline1("LDU #$%4.4x", image->frameSize );
                if ( banks_get_default_resident( _environment, image->bankAssigned ) == image->residentAssigned ) {
                    outline1("JSR BANKREADBANK%2.2xXSDR", image->bankAssigned );
                } else {
                    outline1("LDX #%s", bankWindowName );
                    outline1("JSR BANKREADBANK%2.2xXS", image->bankAssigned );
                };

                if ( _environment->residentDetectionEnabled ) {
                    // Optimization: D = $FFFF at the end of any BANKREAD
                    outline1( "STD %s", bankWindowId );
                }

                Resource resource;
                resource.realName = strdup( bankWindowName );
                resource.isAddress = 0;

                ef936x_put_image( _environment, &resource, _x1, _y1, NULL, NULL, image->frameSize, 0, _flags );

            } else {
                Variable * frame = NULL;
                if ( _frame) {
                    frame = variable_retrieve_or_define( _environment, _frame, VT_BYTE, 0 );
                }
                Variable * sequence = NULL;
                if ( _sequence) {
                    sequence = variable_retrieve_or_define( _environment, _sequence, VT_BYTE, 0 );
                }

                if ( !sequence ) {
                    if ( !frame ) {
                        ef936x_put_image( _environment, resource, _x1, _y1, "", "", image->frameSize, image->frameCount, _flags );
                    } else {
                        ef936x_put_image( _environment, resource, _x1, _y1, frame->realName, "", image->frameSize, image->frameCount, _flags );
                    }
                } else {
                    if ( !frame ) {
                        ef936x_put_image( _environment, resource, _x1, _y1, "", sequence->realName, image->frameSize, image->frameCount, _flags );
                    } else {
                        ef936x_put_image( _environment, resource, _x1, _y1, frame->realName, sequence->realName, image->frameSize, image->frameCount, _flags );
                    }
                }
            }
            break;
        case VT_IMAGES:
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

                // Variable * frameSize = variable_temporary( _environment, VT_WORD, "(temporary)");
                // variable_store( _environment, frameSize->name, image->frameSize );
                // Variable * bank = variable_temporary( _environment, VT_BYTE, "(temporary)");
                // variable_store( _environment, bank->name, image->bankAssigned );
                // Variable * offset = variable_temporary( _environment, VT_ADDRESS, "(temporary)");

                outline1("LDY #$%4.4x", image->absoluteAddress );

                if ( !_frame ) {
                    ef936x_calculate_sequence_frame_offset_regy(_environment, NULL, "", image->frameSize, 0 );
                } else {
                    ef936x_calculate_sequence_frame_offset_regy(_environment, NULL, _frame, image->frameSize, 0 );
                }

                // Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                // variable_store( _environment, address->name, image->absoluteAddress );
                // variable_add_inplace_vars( _environment, address->name, offset->name );
                // cpu_math_add_16bit_const( _environment, offset->realName, image->absoluteAddress, offset->realName );

                deploy_preferred( duff, src_hw_6809_duff_asm );
                deploy_preferred( msc1, src_hw_6809_msc1_asm );
                deploy_preferred( bank, src_hw_pc128op_bank_asm );

                // outline1("LDY %s", offset->realName );
                outline1("LDU #$%4.4x", image->frameSize );
                if ( banks_get_default_resident( _environment, image->bankAssigned ) == image->residentAssigned ) {
                    outline1("JSR BANKREADBANK%2.2xXSDR", image->bankAssigned );
                } else {
                    outline1("LDX #%s", bankWindowName );
                    outline1("JSR BANKREADBANK%2.2xXS", image->bankAssigned );
                };

                if ( _environment->residentDetectionEnabled ) {
                    // Optimization: D = $FFFF at the end of any BANKREAD
                    outline1( "STD %s", bankWindowId );
                }

                Resource resource;
                resource.realName = strdup( bankWindowName );
                resource.isAddress = 0;

                ef936x_put_image( _environment, &resource, _x1, _y1, NULL, NULL, image->frameSize, 0, _flags );
                
            } else {
                Variable * frame = NULL;
                if ( _frame) {
                    frame = variable_retrieve_or_define( _environment, _frame, VT_BYTE, 0 );
                }

                if ( !frame ) {
                    ef936x_put_image( _environment, resource, _x1, _y1, "", NULL, image->frameSize, 0, _flags );
                } else {
                    ef936x_put_image( _environment, resource, _x1, _y1, frame->realName, NULL, image->frameSize, 0, _flags );
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

                deploy_preferred( duff, src_hw_6809_duff_asm );
                deploy_preferred( msc1, src_hw_6809_msc1_asm );
                deploy_preferred( bank, src_hw_pc128op_bank_asm );

                if ( _environment->residentDetectionEnabled ) {
                    cpu_compare_and_branch_16bit_const( _environment, bankWindowId, image->variableUniqueId, alreadyLoadedLabel, 1 );
                }
                if ( image->uncompressedSize ) {
                    outline1("LDX #$%4.4x", image->absoluteAddress );
                    // bank_uncompress_semi_var( _environment, image->bankAssigned, image->absoluteAddress, bankWindowName );
                     if ( banks_get_default_resident( _environment, image->bankAssigned ) == image->residentAssigned ) {
                        outline1("JSR BANKUNCOMPRESS%2.2xXSDR", image->bankAssigned );
                    } else {
                        outline1("LDY #%s", bankWindowName );
                        outline1("JSR BANKUNCOMPRESS%2.2xXS", image->bankAssigned );
                    };                    
                } else {
                    // bank_read_semi_var( _environment, image->bankAssigned, image->absoluteAddress, bankWindowName, image->size );
                    outline1("LDY #$%4.4x", image->absoluteAddress );
                    outline1("LDU #$%4.4x", image->size );
                    if ( banks_get_default_resident( _environment, image->bankAssigned ) == image->residentAssigned ) {
                        outline1("JSR BANKREADBANK%2.2xXSDR", image->bankAssigned );
                    } else {
                        outline1("LDX #%s", bankWindowName );
                        outline1("JSR BANKREADBANK%2.2xXS", image->bankAssigned );
                    };            
                }
                if ( _environment->residentDetectionEnabled ) {
                    cpu_store_16bit(_environment, bankWindowId, image->variableUniqueId );
                    cpu_label( _environment, alreadyLoadedLabel );
                }

                Resource resource;
                resource.realName = strdup( bankWindowName );
                resource.isAddress = 0;

                ef936x_put_image( _environment, &resource, _x1, _y1, NULL, NULL, 1, 0, _flags );
            } else {
                ef936x_put_image( _environment, resource, _x1, _y1, NULL, NULL, 1, 0, _flags );
            }
            break;
        default:
            CRITICAL_PUT_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }


}

void put_image_vars_imageref( Environment * _environment, char * _image, char * _x1, char * _y1, char * _x2, char * _y2, char * _frame, char * _sequence, char * _flags ) {

    MAKE_LABEL

    char labelNoBank[MAX_TEMPORARY_STORAGE]; sprintf( labelNoBank, "%snobank", label );
    char labelNoBankCompressed[MAX_TEMPORARY_STORAGE]; sprintf( labelNoBankCompressed, "%snocompressed", label );
    char labelDecompressionDone[MAX_TEMPORARY_STORAGE]; sprintf( labelDecompressionDone, "%sdecompression", label );
    char labelDone[MAX_TEMPORARY_STORAGE]; sprintf( labelDone, "%sdone", label );

    Variable * image = variable_retrieve( _environment, _image );

    Variable * frame = NULL;
    if ( _frame) {
        frame = variable_retrieve_or_define( _environment, _frame, VT_BYTE, 0 );
    }
    Variable * sequence = NULL;
    if ( _sequence) {
        sequence = variable_retrieve_or_define( _environment, _sequence, VT_BYTE, 0 );
    }

    // Y = OFFSET

    if ( _sequence ) {
        outline0("LDY #$3" );
        if ( strlen(_sequence) == 0 ) {
        } else {
            outline1("LDB %s", sequence->realName );
            outline1("JSR [%s+10]", image->realName );
        }
        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {
            } else {
                outline1("LDB %s", frame->realName );
                outline1("JSR [%s+8]", image->realName );
            }
        }
    } else {
        if ( _frame ) {
            outline0("LDY #$3" );
            if ( strlen(_frame) == 0 ) {
            } else {
                outline1("LDB %s", frame->realName );
                outline1("JSR [%s+8]", image->realName );
            }
        } else {
            outline0("LDY #$0" );
        }
    }

    // Y = BASE + OFFSET
    outline0( "TFR Y, D" );
    outline1( "ADDD %s", image->realName );
    outline0( "TFR D, Y" );

    // Bank assigned?
    outline1( "LDA %s+5", image->realName );
    outline0( "ANDA #$04" );
    outline1( "BEQ %s", labelNoBank );

    // Image compressed?
    outline1( "LDA %s+5", image->realName );
    outline0( "ANDA #$40" );
    outline1( "BEQ %s", labelNoBankCompressed );

    // ; U : number of bank 
    // ; Y : address on bank 
    // ; D : size to read
    // ; X : address on memory 

    deploy_preferred( duff, src_hw_6809_duff_asm );
    deploy_preferred( msc1, src_hw_6809_msc1_asm );
    deploy_preferred( bank, src_hw_pc128op_bank_asm );

    // outline0("; bank uncompress (1)")
    // Variable * previous = bank_get( _environment );
    // bank_set( _environment, _bank );
    // int realAddress = 0x6000 + _address1;
    // char realAddressAsString[MAX_TEMPORARY_STORAGE];
    // sprintf(realAddressAsString, "$%4.4x", realAddress);
    // cpu_msc1_uncompress_direct_direct( _environment, realAddressAsString, _address2 );
    // bank_set_var( _environment, previous->name );
    // outline0("; end bank uncompress (1)")

    outline1("LDB %s+4", image->realName );
    outline0("CLRA" );
    outline0("TFR D, U" );
    outline0("TFR Y, X" );
    // outline0("LEAX $6000, X" );
    outline1("LDY %s+6", image->realName );
    outline1("LDD %s+2", image->realName );
    outline0("JSR BANKUNCOMPRESS");

    cpu_jump( _environment, labelDecompressionDone );

    cpu_label( _environment, labelNoBankCompressed );

    outline1("LDB %s+4", image->realName );
    outline1("LDX %s+6", image->realName );
    outline1("LDU %s+2", image->realName );
    outline0("JSR BANKREAD");
    
    cpu_label( _environment, labelDecompressionDone );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(stub)" );

    outline1("LDX %s+6", image->realName );
    outline1("STX %s", address->realName );
    if ( _environment->residentDetectionEnabled ) {
        outline0("LEAX -2, X");
        outline0("LDD #$FFFF");
        outline0("STD , X");
    }

    Resource resource;
    resource.realName = strdup( address->realName );
    resource.isAddress = 1;

    ef936x_put_image( _environment, &resource, _x1, _y1, NULL, NULL, 1, 0, _flags );

    cpu_jump( _environment, labelDone );

    cpu_label( _environment, labelNoBank );

    outline1("STY %s", address->realName );

    resource.realName = strdup( address->realName );
    resource.isAddress = 1;

    ef936x_put_image( _environment, &resource, _x1, _y1, NULL, NULL, 1, 0, _flags );

    cpu_label( _environment, labelDone );
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

    _flags = _flags & ( ( FLAG_DOUBLE_Y << 8 ) | FLAG_TRANSPARENCY );

    char flagsConstantName[MAX_TEMPORARY_STORAGE]; sprintf( flagsConstantName, "PUTIMAGEFLAGS%4.4x", _flags );
    char flagsConstantParameter[MAX_TEMPORARY_STORAGE]; sprintf( flagsConstantParameter, "#PUTIMAGEFLAGS%4.4x", _flags );
    
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

