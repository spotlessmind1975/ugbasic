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
/* <usermanual>
@keyword FLIP IMAGE
@target to8
</usermanual> */
void flip_image_vars( Environment * _environment, char * _image, char * _frame, char * _sequence, char * _direction ) {

    if ( _environment->emptyProcedure ) {
        return;
    }

    MAKE_LABEL
    
    Variable * image = variable_retrieve( _environment, _image );

    if ( image->uncompressedSize ) {
        CRITICAL_CANNOT_FLIP_COMPRESSED_IMAGE( _image );
    }

    Resource * resource = build_resource_for_sequence( _environment, _image, _frame, _sequence );

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
                        ef936x_calculate_sequence_frame_offset(_environment, offset->realName, "", "", image->frameSize, image->frameCount );
                    } else {
                        ef936x_calculate_sequence_frame_offset(_environment, offset->realName, "", frame->realName, image->frameSize, image->frameCount );
                    }
                } else {
                    if ( !frame ) {
                        ef936x_calculate_sequence_frame_offset(_environment, offset->realName, sequence->realName, "", image->frameSize, image->frameCount );
                    } else {
                        ef936x_calculate_sequence_frame_offset(_environment, offset->realName, sequence->realName, frame->realName, image->frameSize, image->frameCount );
                    }
                }

                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                variable_store( _environment, address->name, image->absoluteAddress );
                variable_add_inplace_vars( _environment, address->name, offset->name );
                // bank_read_vars_direct( _environment, bank->name, address->name, bankWindowName, frameSize->name );

                Resource resource;
                // resource.realName = strdup( bankWindowName );
                resource.realName = address->realName;
                resource.bankNumber = image->bankAssigned;
                resource.isAddress = 1;

                ef936x_flip_image( _environment, &resource, NULL, NULL, image->frameSize, 0, _direction );

                // if ( ! image->readonly ) {
                //     bank_write_vars_direct( _environment, bankWindowName, bank->name, address->name, frameSize->name );
                // }

            } else {
                if ( !sequence ) {
                    if ( !frame ) {
                        ef936x_flip_image( _environment, resource, "", "", image->frameSize, image->frameCount, _direction );
                    } else {
                        ef936x_flip_image( _environment, resource, frame->realName, "", image->frameSize, image->frameCount, _direction );
                    }
                } else {
                    if ( !frame ) {
                        ef936x_flip_image( _environment, resource, "", sequence->realName, image->frameSize, image->frameCount, _direction );
                    } else {
                        ef936x_flip_image( _environment, resource, frame->realName, sequence->realName, image->frameSize, image->frameCount, _direction );
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

                Variable * frameSize = variable_temporary( _environment, VT_WORD, "(temporary)");
                variable_store( _environment, frameSize->name, image->frameSize );
                Variable * bank = variable_temporary( _environment, VT_BYTE, "(temporary)");
                variable_store( _environment, bank->name, image->bankAssigned );
                Variable * offset = variable_temporary( _environment, VT_ADDRESS, "(temporary)");

                if ( !frame ) {
                    ef936x_calculate_sequence_frame_offset(_environment, offset->realName, NULL, "", image->frameSize, 0 );
                } else {
                    ef936x_calculate_sequence_frame_offset(_environment, offset->realName, NULL, frame->realName, image->frameSize, 0 );
                }

                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                variable_store( _environment, address->name, image->absoluteAddress );
                variable_add_inplace_vars( _environment, address->name, offset->name );
                // bank_read_vars_direct( _environment, bank->name, address->name, bankWindowName, frameSize->name );

                Resource resource;
                //resource.realName = strdup( bankWindowName );
                resource.realName = address->realName;
                resource.bankNumber = image->bankAssigned;
                resource.isAddress = 1;

                ef936x_flip_image( _environment, &resource, NULL, NULL, image->frameSize, 0, _direction );

                // if ( ! image->readonly ) {
                //     bank_write_vars_direct( _environment, bankWindowName, bank->name, address->name, frameSize->name );
                // }

            } else {
                if ( !frame ) {
                    ef936x_flip_image( _environment, resource, "", NULL, image->frameSize, 0, _direction );
                } else {
                    ef936x_flip_image( _environment, resource, frame->realName, NULL, image->frameSize, 0, _direction );
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

                bank_set( _environment, image->bankAssigned );
                ef936x_flip_image( _environment, &resource, NULL, NULL, 0, 0, _direction );
                bank_set( _environment, 7 );

                if ( ! image->readonly && ( image->uncompressedSize == 0 ) ) {
                    bank_write_semi_var( _environment, bankWindowName, image->bankAssigned, image->absoluteAddress, image->size );
                }

            } else {
                ef936x_flip_image( _environment, resource, NULL, NULL, 0, 0, _direction );
            }
            break;
        default:
            CRITICAL_PUT_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }

}

