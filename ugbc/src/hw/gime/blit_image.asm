; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                          IMAGES ROUTINE FOR GIME                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

BLITIMAGEBLITADDR  fdb $0

; ----------------------------------------------------------------------------
; - Blit image on bitmap
; ----------------------------------------------------------------------------

BLITIMAGE

    ; We must do nothing if we are in text mode!
    LDA CURRENTTILEMODE
    BEQ BLITIMAGEGO
    RTS

BLITIMAGEGO

    LDY BLITTMPPTR

    ; Convert PLOTX, PLOTY into the first byte of video RAM.

    LDD IMAGEX
    STD PLOTX
    LDD IMAGEY
    STD PLOTY

    JSR GIMECALCPOSBM

    ; Based on bpp, we 

    LDB PALETTELIMIT
    CMPB #2
    BEQ BLITIMAGEGOS3
    CMPB #4
    BEQ BLITIMAGEGOS2
    CMPB #16
    BEQ BLITIMAGEGOS1
    RTS

    ; Load the width from the header, and calculate
    ; the size of the writing in bytes.

BLITIMAGEGOS3
    LDD , Y
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    JMP BLITIMAGEGOSX

BLITIMAGEGOS2
    LDD , Y
    LSRA
    RORB
    LSRA
    RORB
    JMP BLITIMAGEGOSX

BLITIMAGEGOS1
    LDD , Y
    LSRA
    RORB
    JMP BLITIMAGEGOSX

BLITIMAGEGOSX
    STD IMAGEW
    LDA 2, Y
    STA IMAGEH
    
    LEAY 3, Y
    STY BLITTMPPTR

    LDY BLITTMPPTR2
    LEAY 3, Y
    STY BLITTMPPTR2

    LDY BLITTMPPTR

    ; The PUT IMAGE primitive must have control if it is necessary to bank 
    ; in the RAM and, if necessary, to differentiate the drawing logic.

    PSHS D
    LDA IMAGEW
    LDB IMAGEH
    MUL
    TFR D, U
    PULS D

    JSR GIMEBANKISNEEDED
    CMPA #0
    LBEQ BLITIMAGEGOSXNOBANK

    ; This is the banked logic.

    LDU IMAGEW
BLITIMAGEL1   
BLITIMAGEDEF

    JSR GIMEBANKVIDEO
    LDA , X
    JSR GIMEBANKROM
    STA BLITS0
    LDY BLITTMPPTR
    LDA , Y+
    STY BLITTMPPTR
    STA BLITS1
    LDY BLITTMPPTR2
    LDA , Y+
    STY BLITTMPPTR2
    STA BLITS2
    PSHS B
    JSR [BLITIMAGEBLITADDR]
    PULS B
    JSR GIMEBANKVIDEO
    STA  ,X+

    LEAU -1, U
    CMPU #0
    LBNE BLITIMAGEL1
    
    LDA IMAGEF
    ANDA #64
    CMPA #0
    BEQ BLITIMAGEL1N

    LDA IMAGEF
    ANDA #1
    CMPA #1
    BEQ BLITIMAGEL1N0

    ORA #65
    STA IMAGEF

    LDD IMAGEW
    NEGA
    NEGB
    SBCA #0
    LDY BLITTMPPTR
    LEAY D, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY D, Y
    STY BLITTMPPTR2

    CLRA
    LDB CURRENTSL
    SUBD IMAGEW
    LEAX D, X
    
    LDU IMAGEW
    JMP BLITIMAGEL1

BLITIMAGEL1N0
    LDA IMAGEF
    ANDA #$FE
    STA IMAGEF

BLITIMAGEL1N
    CLRA
    LDB CURRENTSL
    SUBD IMAGEW
    LEAX D, X

    LDD IMAGEY
    ADDD #1
    STD IMAGEY
    CMPD CURRENTHEIGHT
    BGE BLITIMAGECOMMONESKIP

    DEC IMAGEH
    LDB IMAGEH
    CMPB #0
    BEQ BLITIMAGECOMMONE

    LDU IMAGEW
    JMP BLITIMAGEL1

BLITIMAGECOMMONESKIP
    LDD IMAGEW
    LDY BLITTMPPTR
BLITIMAGECOMMONESKIPL1    
    DEC IMAGEH
    BNE BLITIMAGECOMMONESKIPL1

    STY BLITTMPPTR

BLITIMAGECOMMONE
    JSR GIMEBANKROM
    LDA #0
    LDY BLITTMPPTR
BLITIMAGECOMMONEL1
    LDB , Y+
    JSR GIMEUPDATEPALETTE
    INCA
    CMPA PALETTELIMIT
    BNE BLITIMAGECOMMONEL1
    RTS


    ; This is the "not banked" logic.

BLITIMAGEGOSXNOBANK
    JSR GIMEBANKVIDEO
    LDU IMAGEW
BLITIMAGEL1NOBANK

    LDA , X
    STA BLITS0
    LDY BLITTMPPTR
    LDA , Y+
    STY BLITTMPPTR
    STA BLITS1
    LDY BLITTMPPTR2
    LDA , Y+
    STY BLITTMPPTR2
    STA BLITS2
    PSHS B
    JSR [BLITIMAGEBLITADDR]
    PULS B
    STA  ,X+

    LEAU -1, U
    CMPU #0
    LBNE BLITIMAGEL1NOBANK
    
    LDA IMAGEF
    ANDA #64
    CMPA #0
    BEQ BLITIMAGEL1NNOBANK

    LDA IMAGEF
    ANDA #1
    CMPA #1
    BEQ BLITIMAGEL1N0NOBANK

    ORA #65
    STA IMAGEF

    LDD IMAGEW
    NEGA
    NEGB
    SBCA #0
    LDY BLITTMPPTR
    LEAY D, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY D, Y
    STY BLITTMPPTR2

    CLRA
    LDB CURRENTSL
    SUBD IMAGEW
    LEAX D, X
    
    LDU IMAGEW
    JMP BLITIMAGEL1NOBANK

BLITIMAGEL1N0NOBANK
    LDA IMAGEF
    ANDA #$FE
    STA IMAGEF

BLITIMAGEL1NNOBANK
    CLRA
    LDB CURRENTSL
    SUBD IMAGEW
    LEAX D, X

    LDD IMAGEY
    ADDD #1
    CMPD CURRENTHEIGHT
    BEQ BLITIMAGECOMMONESKIPNOBANK

    DEC IMAGEH
    LDB IMAGEH
    CMPB #0
    BEQ BLITIMAGECOMMONENOBANK

    LDU IMAGEW
    JMP BLITIMAGEL1NOBANK

BLITIMAGECOMMONESKIPNOBANK
    LDD IMAGEW
    LDY BLITTMPPTR
BLITIMAGECOMMONESKIPL1NOBANK    
    LEAY D, Y
    DEC IMAGEH
    BNE BLITIMAGECOMMONESKIPL1NOBANK

    STY BLITTMPPTR

BLITIMAGECOMMONENOBANK
    LDA #0
    LDY BLITTMPPTR
BLITIMAGECOMMONEL1NOBANK
    LDB , Y+
    JSR GIMEUPDATEPALETTE
    INCA
    CMPA PALETTELIMIT
    BNE BLITIMAGECOMMONEL1NOBANK
    JSR GIMEBANKROM
    RTS

