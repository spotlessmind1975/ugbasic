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
@keyword PUT IMAGE

@english
This function draws an image at a specific position on the screen.
The programmer can draw on the screen a single image (''IMAGE''), a 
frame of a series of images (''IMAGES'') or a frame of a pose of a 
sequence of images (''SEQUENCES''). In all cases the syntax changes 
slightly.

@italian
Questa funzione disegna una immagine in una specifica posizione dello schermo.
Il programmatore può disegnare sullo schermo una singola immagine 
(''IMAGE''), un frame di una serie di immagini (''IMAGES'') oppure 
un frame di una posa di una sequenza di immagini (''SEQUENCES''). 
In tutti i casi la sintassi cambia leggermente.

@syntax PUT IMAGE resource AT [x],[y]
@syntax PUT IMAGE resource FRAME frame AT [x],[y]
@syntax PUT IMAGE resource STRIP sequence FRAME frame AT [x],[y]

@example PUT IMAGE airplane AT 10,10

@usedInExample contrib_themill.bas
@usedInExample defines_screen_01.bas
@usedInExample images_load_05.bas

@target all
</usermanual> */
void put_image_vars_original( Environment * _environment, char * _image, char * _x1, char * _y1, char * _x2, char * _y2, char * _frame, char * _sequence, char * _flags ) {

    if ( _environment->emptyProcedure ) {
        return;
    }

    MAKE_LABEL
    
    Variable * image = variable_retrieve( _environment, _image );

    image->usedImage = 1;

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
            if ( image->bankAssigned != -1 ) {

                Variable * frameSize = variable_temporary( _environment, VT_WORD, "(temporary)");
                variable_store( _environment, frameSize->name, image->frameSize );
                Variable * offset = variable_temporary( _environment, VT_ADDRESS, "(temporary)");

                if ( !sequence ) {
                    if ( !frame ) {
                        vic2_calculate_sequence_frame_offset(_environment, offset->realName, "", "", image->frameSize, image->frameCount );
                    } else {
                        vic2_calculate_sequence_frame_offset(_environment, offset->realName, "", frame->realName, image->frameSize, image->frameCount );
                    }
                } else {
                    if ( !frame ) {
                        vic2_calculate_sequence_frame_offset(_environment, offset->realName, sequence->realName, "", image->frameSize, image->frameCount );
                    } else {
                        vic2_calculate_sequence_frame_offset(_environment, offset->realName, sequence->realName, frame->realName, image->frameSize, image->frameCount );
                    }
                }

                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                variable_store( _environment, address->name, image->absoluteAddress );
                variable_add_inplace_vars( _environment, address->name, offset->name );

                Resource resource;
                resource.realName = strdup( address->realName );
                resource.bankNumber = image->bankAssigned;
                resource.isAddress = 1;

                vic2_put_image( _environment, &resource, x1->name, y1->name, NULL, NULL, image->frameSize, 0, _flags );

            } else {
                if ( !sequence ) {
                    if ( !frame ) {
                        vic2_put_image( _environment, resource, x1->name, y1->name, "", "", image->frameSize, image->frameCount, _flags );
                    } else {
                        vic2_put_image( _environment, resource, x1->name, y1->name, frame->realName, "", image->frameSize, image->frameCount, _flags );
                    }
                } else {
                    if ( !frame ) {
                        vic2_put_image( _environment, resource, x1->name, y1->name, "", sequence->realName, image->frameSize, image->frameCount, _flags );
                    } else {
                        vic2_put_image( _environment, resource, x1->name, y1->name, frame->realName, sequence->realName, image->frameSize, image->frameCount, _flags );
                    }
                }
            }
            break;
        case VT_IMAGES:
            if ( image->bankAssigned != -1 ) {
                
                Variable * frameSize = variable_temporary( _environment, VT_WORD, "(temporary)");
                variable_store( _environment, frameSize->name, image->frameSize );
                Variable * offset = variable_temporary( _environment, VT_ADDRESS, "(temporary)");

                if ( !frame ) {
                    vic2_calculate_sequence_frame_offset(_environment, offset->realName, NULL, "", image->frameSize, 0 );
                } else {
                    vic2_calculate_sequence_frame_offset(_environment, offset->realName, NULL, frame->realName, image->frameSize, 0 );
                }

                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                variable_store( _environment, address->name, image->absoluteAddress );
                variable_add_inplace_vars( _environment, address->name, offset->name );

                Resource resource;
                resource.realName = strdup( address->realName );
                resource.bankNumber = image->bankAssigned;
                resource.isAddress = 1;

                vic2_put_image( _environment, &resource, x1->name, y1->name, NULL, NULL, image->frameSize, 0, _flags );
                
            } else {
                if ( !frame ) {
                    vic2_put_image( _environment, resource, x1->name, y1->name, "", NULL, image->frameSize, 0, _flags );
                } else {
                    vic2_put_image( _environment, resource, x1->name, y1->name, frame->realName, NULL, image->frameSize, 0, _flags );
                }
            }
            break;
        case VT_IMAGE:
        case VT_TARRAY:
            if ( image->bankAssigned != -1 ) {

                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                variable_store( _environment, address->name, image->absoluteAddress );

                Resource resource;
                resource.realName = strdup( address->realName );
                resource.bankNumber = image->bankAssigned;
                resource.isAddress = 1;

                vic2_put_image( _environment, &resource, x1->name, y1->name, NULL, NULL, 1, 0, _flags );
            } else {
                vic2_put_image( _environment, resource, x1->name, y1->name, NULL, NULL, 1, 0, _flags );
            }
            break;
        default:
            CRITICAL_PUT_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }


}

void put_image_vars_imageref( Environment * _environment, char * _image, char * _x1, char * _y1, char * _x2, char * _y2, char * _frame, char * _sequence, char * _flags ) {

    MAKE_LABEL

    char labelNoBank[MAX_TEMPORARY_STORAGE]; sprintf( labelNoBank, "%snobank", label );
    char labelNoBankLong[MAX_TEMPORARY_STORAGE]; sprintf( labelNoBankLong, "%snobanklong", label );
    char labelDone[MAX_TEMPORARY_STORAGE]; sprintf( labelDone, "%sdone", label );

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

    if ( !_environment->putImageRefUnsafe ) {
        outline1("LDA %s", address_displacement( _environment, image->realName, "5") );
        outline1("BNE %sskipx", label );
        outline1("JMP %sskip", label );
        outhead1("%sskipx:", label );
    }

    // Y = OFFSET

    outline0("LDA #0" );
    outline0("STA TMPPTR" );
    outline0("STA TMPPTR+1" );

    if ( _sequence ) {

        outline0("CLC" );
        outline0("LDA TMPPTR" );
        outline0("ADC #3" );
        outline0("STA TMPPTR" );
        outline0("LDA TMPPTR+1" );
        outline0("ADC #0" );
        outline0("STA  TMPPTR+1" );

        if ( strlen(_sequence) == 0 ) {

        } else {
            outline1("LDA %s", sequence->realName );
            outline0("STA MATHPTR0" );
            cpu6502_call_indirect( _environment, address_displacement( _environment, image->realName, "10") );
        }
        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {

            } else {
                outline1("LDA %s", frame->realName );
                outline0("STA MATHPTR0" );
                cpu6502_call_indirect( _environment, address_displacement( _environment, image->realName, "8") );
            }
        }

    } else {

        if ( _frame ) {

            outline0("CLC" );
            outline0("LDA TMPPTR" );
            outline0("ADC #3" );
            outline0("STA TMPPTR" );
            outline0("LDA TMPPTR+1" );
            outline0("ADC #0" );
            outline0("STA  TMPPTR+1" );
            if ( strlen(_frame) == 0 ) {

            } else {
                outline1("LDA %s", frame->realName );
                outline0("STA MATHPTR0" );
                cpu6502_call_indirect( _environment, address_displacement( _environment, image->realName, "8") );
            }

            outline0("LDA TMPPTR" );
            outline1("STA %s", address->realName );
            outline0("LDA TMPPTR+1" );
            outline1("STA %s", address_displacement(_environment, address->realName, "1") );

        } else {

            outline1("LDA %s", image->realName );
            outline1("STA %s", address->realName );
            outline1("LDA %s", address_displacement( _environment, image->realName, "1") );
            outline1("STA %s", address_displacement(_environment, address->realName, "1") );

        }

    }

    // Bank assigned?
    outline1( "LDA %s", address_displacement( _environment, image->realName, "5" ) );
    outline0( "AND #$04" );
    outline1( "BNE %s", labelNoBank );
    outline1( "JMP %s", labelNoBankLong );

    cpu_label( _environment, labelNoBank );
    outline1( "LDA %s", address_displacement( _environment, image->realName, "4" ) );
    outline0( "STA BANKPTR" );
    outline0( "LDA #$FF" );
    outline0( "STA BANKUSE" );
    outline0( "CLC" );
    outline0( "LDA TMPPTR" );
    outline1( "ADC %s", address_displacement( _environment, image->realName, "0" ) );
    outline0( "STA TMPPTR" );
    outline0( "LDA TMPPTR+1" );
    outline1( "ADC %s", address_displacement( _environment, image->realName, "1" ) );
    outline0( "STA TMPPTR+1" );

    Resource resource;
    resource.realName = strdup( address->realName );
    resource.bankNumber = image->bankAssigned;
    resource.isAddress = 1;

    vic2_put_image( _environment, &resource, x1->name, y1->name, NULL, NULL, 0, 0, _flags );

    cpu_jump( _environment, labelDone );

    cpu_label( _environment, labelNoBankLong );

    resource.realName = strdup( address->realName );
    resource.isAddress = 1;

    vic2_put_image( _environment, &resource, x1->name, y1->name, NULL, NULL, 1, 0, _flags );

    cpu_label( _environment, labelDone );

    if ( !_environment->putImageRefUnsafe ) {
        outhead1("%sskip:", label );
    }
    
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
