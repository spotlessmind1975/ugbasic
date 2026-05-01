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
 * @brief Emit code for <strong>GPRINT...</strong> instruction
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword GPRINT

@english

The ''GPRINT'' (''G''raphic ''PRINT'') statement is used to print a text 
string, in graphical mode, at a specific position on the screen, with the 
option to specify the font to use.

Unlike the traditional ''PRINT'' statement, which prints text in the 
console's character grid, ''GPRINT'' is designed to work in graphical 
mode. It prints text pixel by pixel, treating it as a graphic element.

The text is positioned precisely at the pixel level, making it ideal 
for games, custom interfaces, and designs that require precise control 
over position. The ''x'' and ''y'' coordinates typically refer to the 
upper-left corner of the first letter of the text.

Using the ''WITH font'' argument allows you to dynamically select 
different character sets or fonts that have been previously loaded 
into the program or are available internally, using the ''LOAD ATLAS'' statement.

@italian

L'istruzione ''GPRINT'' (''G''raphic ''PRINT'') è utilizzata stampare una 
stringa di testo, in modalità grafica, in una posizione specifica sullo 
schermo, con la possibilità di specificare il font da utilizzare.

A differenza della tradizionale istruzione ''PRINT'', che stampa testo 
nella griglia di caratteri della console, ''GPRINT'' è progettata per 
funzionare in modalità grafica. Stampa quindi il testo pixel per pixel, 
trattandolo come un elemento grafico.

Il testo viene posizionato in modo preciso a livello di pixel, il che 
lo rende ideale per giochi, interfacce personalizzate e disegni che 
richiedono un controllo esatto della posizione. Le coordinate ''x'' e 
''y'' si riferiscono tipicamente all'angolo in alto a sinistra della 
prima lettera del testo.

L'utilizzo dell'argomento ''WITH font'' permette di selezionare 
dinamicamente diversi set di caratteri o font che sono stati 
precedentemente caricati nel programma o sono disponibili internamente, 
con l'istruzione ''LOAD ATLAS''.

@syntax GPRINT text [AT x,y] WITH font

@example myFont := LOAD ATLAS("font.png") FRAME SIZE(4,8)
@example GPRINT "HELLO WORLD!" WITH myFont

@target all
@verified
</usermanual> */
void gprint( Environment * _environment, char * _atlas, char * _text, char * _x, char * _y ) {

    if ( _environment->gprintInline ) {

        MAKE_LABEL

        char doneLabel[MAX_TEMPORARY_STORAGE];
        sprintf( doneLabel, "%sdone", label );

        // PROCEDURE print[ text AS STRING, x AS BYTE, y AS BYTE ]
        //     SHARED letters
        //     len = LEN(text)

        Variable * atlas = variable_retrieve( _environment, _atlas );
        Variable * atlasFrameWidth = NULL;
        if ( atlas->type == VT_IMAGEREF ) {
            atlasFrameWidth = variable_temporary( _environment, VT_BYTE, "(frame width)");
            cpu_move_8bit( _environment, address_displacement( _environment, atlas->realName, "12" ), atlasFrameWidth->realName );
        }
        Variable * text = variable_retrieve( _environment, _text );
        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(text address)" );
        Variable * size = variable_temporary( _environment, VT_BYTE, "(text size)" );
        Variable * letter = variable_temporary( _environment, VT_BYTE, "(text size)" );

        switch( text->type ) {
            case VT_STRING:
                cpu_move_8bit( _environment, text->realName, size->realName );
                cpu_addressof_16bit( _environment, text->realName, address->realName );
                cpu_inc_16bit( _environment, address->realName );
                break;
            case VT_DSTRING:
                cpu_dsdescriptor( _environment, text->realName, address->realName, size->realName );
                break;
            case VT_CHAR:
                cpu_addressof_16bit( _environment, text->realName, address->realName );
                cpu_store_8bit( _environment, size->realName, 1 );
                break;            
            default:
                CRITICAL_PRINT_UNSUPPORTED( _text, DATATYPE_AS_STRING[text->type]);
        }

        Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
        Variable * dx = variable_temporary( _environment, VT_POSITION, "(dx)" );
        Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

        cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, doneLabel, 1 );

        variable_move( _environment, x->name, dx->name );
        
        //     i = 0: DO

        Variable * i = variable_temporary( _environment, VT_BYTE, "(i)");
        cpu_store_8bit( _environment, i->realName, 0 );

        cpu_label( _environment, label );

        //         PUT IMAGE letters FRAME ASC(MID$(text,i))-64 AT x+i*4,y

            cpu_move_8bit_indirect2( _environment, address->realName, letter->realName );

            put_image( _environment, _atlas, dx->name, y->name, NULL, NULL, letter->name, NULL, FLAG_WITH_PALETTE );

            if ( atlas->type == VT_IMAGEREF ) {
                variable_add_inplace_vars( _environment, dx->name, atlasFrameWidth->name );
            } else {
                variable_add_inplace( _environment, dx->name, atlas->frameWidth );
            }

            cpu_inc_16bit( _environment, address->realName );

        //         INC i

            cpu_inc( _environment, i->realName );

        //     LOOP UNTIL i = len	

        cpu_compare_and_branch_8bit( _environment, i->realName, size->realName, label, 0 );
            
        cpu_label( _environment, doneLabel );

        // END PROCEDURE

    } else {

        MAKE_LABEL

        variable_global( _environment, "gprint_atlas" );
        Variable * paramAtlas = variable_define( _environment, "gprint_atlas", VT_IMAGEREF, 0 );
        variable_global( _environment, "gprint_address" );
        Variable * paramAddress = variable_define( _environment, "gprint_address", VT_ADDRESS, 0 );
        variable_global( _environment, "gprint_size" );
        Variable * paramSize = variable_define( _environment, "gprint_size", VT_BYTE, 0 );
        variable_global( _environment, "gprint_frame_width" );
        Variable * paramFrameWidth = variable_define( _environment, "gprint_frame_width", VT_BYTE, 0 );
        variable_global( _environment, "gprint_x" );
        Variable * paramX = variable_define( _environment, "gprint_x", VT_POSITION, 0 );
        variable_global( _environment, "gprint_y" );
        Variable * paramY = variable_define( _environment, "gprint_y", VT_POSITION, 0 );

        deploy_begin( gprint )

            char doneLabel[MAX_TEMPORARY_STORAGE];
            sprintf( doneLabel, "%sdone", label );

            // PROCEDURE print[ text AS STRING, x AS BYTE, y AS BYTE ]
            //     SHARED letters
            //     len = LEN(text)

            Variable * letter = variable_temporary( _environment, VT_BYTE, "(text size)" );

            Variable * x = variable_retrieve( _environment, paramX->name );
            Variable * dx = variable_temporary( _environment, VT_POSITION, "(dx)" );
            Variable * y = variable_retrieve( _environment, paramY->name );

            cpu_compare_and_branch_8bit_const( _environment, paramSize->realName, 0, doneLabel, 1 );

            variable_move( _environment, x->name, dx->name );
            
            //     i = 0: DO

            Variable * i = variable_temporary( _environment, VT_BYTE, "(i)");
            cpu_store_8bit( _environment, i->realName, 0 );

            cpu_label( _environment, label );

            //         PUT IMAGE letters FRAME ASC(MID$(text,i))-64 AT x+i*4,y

                cpu_move_8bit_indirect2( _environment, paramAddress->realName, letter->realName );

                put_image( _environment, paramAtlas->name, dx->name, y->name, NULL, NULL, letter->name, NULL, FLAG_WITH_PALETTE );

                outline0(";variable_add_inplace_vars");
                variable_add_inplace_vars( _environment, dx->name, paramFrameWidth->name );
                outline0(";variable_add_inplace_vars");

                cpu_inc_16bit( _environment, paramAddress->realName );

            //         INC i

                cpu_inc( _environment, i->realName );

            //     LOOP UNTIL i = len	

            cpu_compare_and_branch_8bit( _environment, i->realName, paramSize->realName, label, 0 );
                
            cpu_label( _environment, doneLabel );

            cpu_return( _environment );

            // END PROCEDURE

        deploy_end( gprint )

        Variable * atlas = variable_retrieve( _environment, _atlas );

        if ( atlas->type == VT_IMAGEREF ) {
            variable_move( _environment, atlas->name, paramAtlas->name );
        } else {
            variable_move( _environment, image_ref( _environment, atlas->name )->name, paramAtlas->name );
        }

        Variable * text = variable_retrieve( _environment, _text );
        switch( text->type ) {
            case VT_STRING:
                cpu_move_8bit( _environment, text->realName, paramSize->realName );
                cpu_addressof_16bit( _environment, text->realName, paramAddress->realName );
                cpu_inc_16bit( _environment, paramAddress->realName );
                break;
            case VT_DSTRING:
                cpu_dsdescriptor( _environment, text->realName, paramAddress->realName, paramSize->realName );
                break;
            case VT_CHAR:
                cpu_addressof_16bit( _environment, text->realName, paramAddress->realName );
                cpu_store_8bit( _environment, paramSize->realName, 1 );
                break;            
            default:
                CRITICAL_PRINT_UNSUPPORTED( _text, DATATYPE_AS_STRING[text->type]);
        }

        if ( atlas->type == VT_IMAGEREF ) {
            cpu_move_8bit( _environment, address_displacement( _environment, atlas->realName, "12" ), paramFrameWidth->realName );
        } else {
            variable_store( _environment, paramFrameWidth->name, atlas->frameWidth );
        }

        Variable * x = variable_retrieve( _environment, _x );
        Variable * y = variable_retrieve( _environment, _y );

        variable_move( _environment, x->name, paramX->name );
        variable_move( _environment, y->name, paramY->name );

        cpu_call( _environment, "lib_gprint" );

    }
    
}

