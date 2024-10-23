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
/* <usermanual>
@keyword PUT IMAGE

@english
This function draws an image at a specific position on the screen.
The programmer can draw on the screen a single image (''IMAGE''), a 
frame of a series of images (''ATLAS'') or a frame of a strip of a 
sequence of images (''SEQUENCE''). In all cases the syntax changes 
slightly.

Every ''PUT IMAGE'' can be followed by a flag that modify the
wayt the image will be drawn on the screen. The ''WITH TRANSPARENCY''
will enable the transparency effect when the image is drawn,
while ''DOUBLE Y'' will double the vertical size of the image. Both
flags could be not available on all targerts and graphical modes.

Another syntax is more compatible with other BASICs, that requires
that the ''PUT IMAGE'' is followed with the bounds to draw to. This
is only a syntatic equivalence, there is no "clipping" around the
bounds. Moreover, it is possible to give a flag that alter the
default behaviour of ''PUT IMAGE''. The ''PSET'' is the standard
behaviour of ''PUT IMAGE'', while ''PRESET'' will put only the
bitmap part of the image (if possible). The ''AND'' and ''OR''
flags will activate the same logical operation between the
image and the background. ''NOT'' is not currently supported.

@italian
Questa funzione disegna una immagine in una specifica posizione dello schermo.
Il programmatore può disegnare sullo schermo una singola immagine 
(''IMAGE''), un frame di una serie di immagini (''ATLAS'') oppure 
un frame di una posa di una sequenza di immagini (''SEQUENCE''). 
In tutti i casi la sintassi cambia leggermente.

Ogni ''PUT IMAGE'' può essere seguito da un flag che modifica il
modo in cui l'immagine verrà disegnata sullo schermo. ''WITH TRANSPARENCY''
abilita l'effetto trasparenza quando l'immagine viene disegnata,
mentre ''DOUBLE Y'' raddoppia la dimensione verticale dell'immagine. Entrambi i
flag potrebbero non essere disponibili su tutti i target e le modalità grafiche.

Un'altra sintassi è più compatibile con altri BASIC, che richiede
che ''PUT IMAGE'' sia seguito dai limiti su cui disegnare. Questa
è solo un'equivalenza sintattica, non c'è alcun "clipping" attorno ai
limiti. Inoltre, è possibile fornire un flag che alteri il
comportamento predefinito di ''PUT IMAGE''. ''PSET'' è il comportamento
standard di ''PUT IMAGE'', mentre ''PRESET'' inserirà solo la
parte bitmap dell'immagine (se possibile). I flag ''AND'' e ''OR''
attiveranno la stessa operazione logica tra l'immagine e lo sfondo. 
''NOT'' non è attualmente supportato.

@syntax PUT IMAGE resource [ AT [x],[y] ] [fl]
@syntax PUT IMAGE resource FRAME f [ AT [x],[y] ] [fl]
@syntax PUT IMAGE resource STRIP s FRAME f [ AT [x],[y] ] [fl]
@syntax   fl: [WITH TRANSPARENCY] [DOUBLE Y]
@syntax PUT ([x1],[y1])-(x2,y2),resource[,fl2]
@syntax   fl2: PSET|PRESET|AND|OR|NOT

@example PUT IMAGE airplane AT 10,10

@usedInExample contrib_themill.bas
@usedInExample defines_screen_01.bas
@usedInExample images_load_05.bas

@seeAlso PUT BITMAP

</usermanual> */
/* <usermanual>
@keyword PUT BITMAP

@english
This function draws the bitmap component of an image at a specific position on the screen.
The programmer can draw on the screen a single bitmap (''IMAGE''), a 
frame of a series of bitmaps (''ATLAS'') or a frame of a strip of a 
sequence of bitmaps (''SEQUENCE''). In all cases the syntax changes 
slightly.

Every ''PUT BITMAP'' can be followed by a flag that modify the
wayt the image will be drawn on the screen. The ''DOUBLE Y''
flag will double the vertical size of the image. This flag
could be not available on all targerts and graphical modes.

@italian
Questa funzione disegna una bitmap (immagine senza colori) in una specifica posizione dello schermo.
Il programmatore può disegnare sullo schermo una singola bitmap 
(''IMAGE''), un frame di una serie di bitmap (''ATLAS'') oppure 
un frame di una posa di una sequenza di bitmap (''SEQUENCE''). 
In tutti i casi la sintassi cambia leggermente.

Ogni ''PUT BITMAP'' può essere seguito da un flag che modifica il
modo in cui l'immagine verrà disegnata sullo schermo. Il flag
''DOUBLE Y'' raddoppia la dimensione verticale della bitmap, ma
potrebbe non essere disponibile su tutti i target e le modalità grafiche.

@syntax PUT BITMAP resource [ AT [x],[y] ] [DOUBLE Y]
@syntax PUT BITMAP resource FRAME f [ AT [x],[y] ] [DOUBLE Y]
@syntax PUT BITMAP resource STRIP s FRAME f [ AT [x],[y] ] [DOUBLE Y]

@example PUT BITMAP airplane AT 10,10

@usedInExample contrib_themill.bas
@usedInExample defines_screen_01.bas
@usedInExample images_load_05.bas

@seeAlso PUT IMAGE

</usermanual> */

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
                        ted_calculate_sequence_frame_offset(_environment, offset->realName, "", "", image->frameSize, image->frameCount );
                    } else {
                        ted_calculate_sequence_frame_offset(_environment, offset->realName, "", frame->realName, image->frameSize, image->frameCount );
                    }
                } else {
                    if ( !frame ) {
                        ted_calculate_sequence_frame_offset(_environment, offset->realName, sequence->realName, "", image->frameSize, image->frameCount );
                    } else {
                        ted_calculate_sequence_frame_offset(_environment, offset->realName, sequence->realName, frame->realName, image->frameSize, image->frameCount );
                    }
                }

                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                variable_store( _environment, address->name, image->absoluteAddress );
                variable_add_inplace_vars( _environment, address->name, offset->name );
                bank_read_vars_direct( _environment, bank->name, address->name, bankWindowName, frameSize->name );

                Resource resource;
                resource.realName = strdup( bankWindowName );
                resource.isAddress = 0;

                ted_put_image( _environment, &resource, x1->realName, y1->realName, NULL, NULL, image->frameSize, 0, _flags );

            } else {
                if ( !sequence ) {
                    if ( !frame ) {
                        ted_put_image( _environment, resource, x1->realName, y1->realName, "", "", image->frameSize, image->frameCount, _flags );
                    } else {
                        ted_put_image( _environment, resource, x1->realName, y1->realName, frame->realName, "", image->frameSize, image->frameCount, _flags );
                    }
                } else {
                    if ( !frame ) {
                        ted_put_image( _environment, resource, x1->realName, y1->realName, "", sequence->realName, image->frameSize, image->frameCount, _flags );
                    } else {
                        ted_put_image( _environment, resource, x1->realName, y1->realName, frame->realName, sequence->realName, image->frameSize, image->frameCount, _flags );
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
                    ted_calculate_sequence_frame_offset(_environment, offset->realName, NULL, "", image->frameSize, 0 );
                } else {
                    ted_calculate_sequence_frame_offset(_environment, offset->realName, NULL, frame->realName, image->frameSize, 0 );
                }

                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary)");
                variable_store( _environment, address->name, image->absoluteAddress );
                variable_add_inplace_vars( _environment, address->name, offset->name );
                bank_read_vars_direct( _environment, bank->name, address->name, bankWindowName, frameSize->name );

                Resource resource;
                resource.realName = strdup( bankWindowName );
                resource.isAddress = 0;

                ted_put_image( _environment, &resource, x1->realName, y1->realName, NULL, NULL, image->frameSize, 0, _flags );
                
            } else {
                if ( !frame ) {
                    ted_put_image( _environment, resource, x1->realName, y1->realName, "", NULL, image->frameSize, 0, _flags );
                } else {
                    ted_put_image( _environment, resource, x1->realName, y1->realName, frame->realName, NULL, image->frameSize, 0, _flags );
                }
            }
            break;
        case VT_IMAGE:
        case VT_TARRAY:
            if ( image->residentAssigned ) {

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

                ted_put_image( _environment, &resource, x1->realName, y1->realName, NULL, NULL, 1, 0, _flags );
            } else {
                ted_put_image( _environment, resource, x1->realName, y1->realName, NULL, NULL, 1, 0, _flags );
            }
            break;
        default:
            CRITICAL_PUT_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }


}

void put_image_vars_imageref( Environment * _environment, char * _image, char * _x1, char * _y1, char * _x2, char * _y2, char * _frame, char * _sequence, char * _flags ) {

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

    if ( _sequence ) {

        outline1("LDA %s", image->realName );
        outline0("STA TMPPTR" );
        outline1("LDA %s", address_displacement( _environment, image->realName, "1") );
        outline0("STA TMPPTR+1" );

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

        outline0("LDA TMPPTR" );
        outline1("STA %s", address->realName );
        outline0("LDA TMPPTR+1" );
        outline1("STA %s", address_displacement(_environment, address->realName, "1") );

    } else {

        if ( _frame ) {

            outline1("LDA %s", image->realName );
            outline0("STA TMPPTR" );
            outline1("LDA %s", address_displacement( _environment, image->realName, "1") );
            outline0("STA TMPPTR+1" );

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
            outline0("STA TMPPTR+1" );
            outline1("STA %s", address_displacement(_environment, address->realName, "1") );

        }

    }

    Resource resource;
    resource.realName = strdup( address->realName );
    resource.isAddress = 1;

    ted_put_image( _environment, &resource, x1->realName, y1->realName, NULL, NULL, 0, 0, _flags );

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
