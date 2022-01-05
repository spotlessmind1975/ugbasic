/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

#if defined(__atari__) || defined(__atarixl__)

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

/**
 * @brief <i>ANTIC</i>: emit code to set raster irq
 * 
 * This function outputs assembly code needed to initialize a raster routine. 
 * In other words, asynchronously and in parallel with the execution of the 
 * main program, the routine starting from the label provided will be executed
 * when the vertical brush on the screen reaches the value of _position. 
 * This function is particularly useful when the position is communicated 
 * is given as an integer.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _positionlo The vertical position to wait for (bits 7..0)
 * @param _positionhi The vertical position to wait for (bit 8)
 */
void antic_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

    deploy( raster, src_hw_antic_raster_asm );

    outline1("LDA %s", _positionlo);
    outline0("STA RASTERLO");
    outline1("LDA %s", _positionhi);
    outline0("STA RASTERHI");
    outline1("LDA #<%s", _label);
    outline0("STA TMPPTR");
    outline1("LDA #>%s", _label);
    outline0("STA TMPPTR+1");
    outline0("JSR RASTERAT");

}

/**
 * @brief <i>ANTIC</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void antic_next_raster( Environment * _environment ) {

    outline0("RTI");

}

/**
 * @brief <i>ANTIC</i>: emit code to wait for next raster irq at different position
 * 
 * This function outputs assembly code needed to wait for the
 * next raster on a different position with a different code to
 * execute. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _positionlo The vertical position to wait for (bits 7..0)
 * @param _positionhi The vertical position to wait for (bit 8)
 */
void antic_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

    deploy( raster, src_hw_antic_raster_asm );

    outline1("LDA %s", _positionlo);
    outline0("STA RASTERLO");
    outline1("LDA %s", _positionhi);
    outline0("STA RASTERHI");
    outline1("LDA #<%s", _label);
    outline0("STA TMPPTR");
    outline1("LDA #>%s", _label);
    outline0("STA TMPPTR+1");
    outline0("JSR RASTERAT");
    outline0("RTI");

}

void antic_initialization( Environment * _environment ) {

    deploy( anticstartup, src_hw_antic_startup_asm );

    outline0("JSR ANTICSTARTUP");

}

void antic_finalization( Environment * _environment ) {

}

#endif