; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

PUTIMAGE

    ; We must do nothing if we are in text mode!
    LDA CURRENTTILEMODE
    BEQ PUTIMAGEGO
    RTS

PUTIMAGEGO

    ORCC #$50

    ; Convert <PLOTX, <PLOTY into the first byte of video RAM.

    LDD <IMAGEX
    STD <PLOTX
    LDD <IMAGEY
    STD <PLOTY

    JSR GIMECALCPOSBM

    ; Based on bpp, we 

    LDB PALETTELIMIT
    CMPB #2
    BEQ PUTIMAGEGOS3
    CMPB #4
    BEQ PUTIMAGEGOS2
    CMPB #16
    BEQ PUTIMAGEGOS1

    ANDA #$AF

    RTS

    ; Load the width from the header, and calculate
    ; the size of the writing in bytes.

PUTIMAGEGOS3
    LDD , Y
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    ANDCC #$FE
    JMP PUTIMAGEGOSX

PUTIMAGEGOS2
    LDD , Y
    LSRA
    RORB
    LSRA
    RORB
    ANDCC #$FE
    JMP PUTIMAGEGOSX

PUTIMAGEGOS1
    LDD , Y
    LSRA
    RORB
    ANDCC #$FE
    JMP PUTIMAGEGOSX

PUTIMAGEGOSX
    STD <IMAGEW
    LDB 2, Y
    CLRA
    STD <IMAGEH
    
    LEAY 3,Y

    ; The PUT IMAGE primitive must have control if it is necessary to bank 
    ; in the RAM and, if necessary, to differentiate the drawing logic.

    PSHS D
    LDA <IMAGEW+1
    LDB <IMAGEH+1
    MUL
    TFR D, U
    PULS D
    JSR GIMEBANKISNEEDED
    CMPA #0
    LBEQ PUTIMAGEGOSXNOBANK

    ; This is the banked logic.
PUTIMAGEGOBANK
    LDU <IMAGEW
PUTIMAGEL1
    LDA <IMAGEF
    ANDA #32
    CMPA #0 
    BEQ PUTIMAGEDEF

    LDA PALETTELIMIT
    CMPA #2
    BEQ PUTIMAGEL1T2
    CMPA #4
    BEQ PUTIMAGEL1T4

PUTIMAGEL1T16
    JSR GIMEBANKROM
    LDA #0
    STA <MATHPTR5
    LDA , Y
    ANDA #$F0
    BEQ PUTIMAGEL1T16P16A
    LDA <MATHPTR5
    ORA #$F0
    STA <MATHPTR5
PUTIMAGEL1T16P16A
    LDA ,Y
    ANDA #$0F
    BEQ PUTIMAGEL1T16P16B
    LDA <MATHPTR5
    ORA #$0F
    STA <MATHPTR5
PUTIMAGEL1T16P16B
    JMP PUTIMAGEL1TFINAL

PUTIMAGEL1T4
    JSR GIMEBANKROM
    LDA #0
    STA <MATHPTR5
    LDA , Y
    ANDA #$C0
    BEQ PUTIMAGEL1T4P4A
    LDA <MATHPTR5
    ORA #$C0
    STA <MATHPTR5
PUTIMAGEL1T4P4A
    LDA , Y
    ANDA #$30
    BEQ PUTIMAGEL1T4P4B
    LDA <MATHPTR5
    ORA #$30
    STA <MATHPTR5
PUTIMAGEL1T4P4B
    LDA , Y
    ANDA #$0C
    BEQ PUTIMAGEL1T4P4C
    LDA <MATHPTR5
    ORA #$0C
    STA <MATHPTR5
PUTIMAGEL1T4P4C
    LDA , Y
    ANDA #$03
    BEQ PUTIMAGEL1T4P4D
    LDA <MATHPTR5
    ORA #$03
    STA <MATHPTR5
PUTIMAGEL1T4P4D
    JMP PUTIMAGEL1TFINAL

PUTIMAGEL1TFINAL
    JSR GIMEBANKVIDEO
    LDA <MATHPTR5
    EORA #$FF
    STA <MATHPTR6
    LDA , X
    ANDA <MATHPTR6
    STA <MATHPTR6
    JSR GIMEBANKROM
    LDA , Y+
    ANDA <MATHPTR5
    ORA <MATHPTR6
    JMP PUTIMAGEDEFFINAL

PUTIMAGEL1T2
PUTIMAGEDEF
    JSR GIMEBANKROM
    LDA , Y+
PUTIMAGEDEFFINAL    
    JSR GIMEBANKVIDEO
    STA , X+
    LEAU -1, U
    CMPU #0
    LBNE PUTIMAGEL1
    
    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGEL1N

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGEL1N0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW
    NEGA
    NEGB
    SBCA #0
    LEAY D, Y

    CLRA
    LDB CURRENTSL
    SUBD <IMAGEW
    LEAX D, X
    
    LDU <IMAGEW
    JMP PUTIMAGEL1

PUTIMAGEL1N0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

PUTIMAGEL1N
    CLRA
    LDB CURRENTSL
    SUBD <IMAGEW
    LEAX D, X

    LDD <IMAGEY
    ADDD #1
    STD <IMAGEY
    CMPD CURRENTHEIGHT
    BGT PUTIMAGECOMMONESKIP

    LDD <IMAGEH
    SUBD #1
    STD <IMAGEH
    CMPD #0
    BEQ PUTIMAGECOMMONE

    LDU <IMAGEW
    JMP PUTIMAGEL1

PUTIMAGECOMMONESKIP
    LDD <IMAGEW
PUTIMAGECOMMONESKIPL1    
    LEAY D, Y

    LDD <IMAGEH
    SUBD #1
    STD <IMAGEH
    CMPD #0
    BNE PUTIMAGECOMMONESKIPL1

PUTIMAGECOMMONE
    JSR GIMEBANKROM
    LDA <IMAGET
    ANDA #$02
    BNE PUTIMAGECOMMONEWITHPALETTE

    ANDA #$AF

    RTS
PUTIMAGECOMMONEWITHPALETTE
    LDA #0
PUTIMAGECOMMONEL1
    LDB , Y+
    JSR GIMEUPDATEPALETTE
    INCA
    CMPA PALETTELIMIT
    BNE PUTIMAGECOMMONEL1

    ANDA #$AF

    RTS


    ; This is the "not banked" logic.

PUTIMAGEGOSXNOBANK
    JSR GIMEBANKVIDEO
    LDU <IMAGEW
PUTIMAGEL1NOBANK
    LDA <IMAGEF
    ANDA #32
    CMPA #0 
    BEQ PUTIMAGEDEFNOBANK

    LDA PALETTELIMIT
    CMPA #2
    BEQ PUTIMAGEL1T2NOBANK
    CMPA #4
    BEQ PUTIMAGEL1T4NOBANK

PUTIMAGEL1T16NOBANK
    LDA #0
    STA <MATHPTR5
    LDA , Y
    ANDA #$F0
    BEQ PUTIMAGEL1T16P16ANOBANK
    LDA <MATHPTR5
    ORA #$F0
    STA <MATHPTR5
PUTIMAGEL1T16P16ANOBANK
    LDA ,Y
    ANDA #$0F
    BEQ PUTIMAGEL1T16P16BNOBANK
    LDA <MATHPTR5
    ORA #$0F
    STA <MATHPTR5
PUTIMAGEL1T16P16BNOBANK
    JMP PUTIMAGEL1TFINALNOBANK

PUTIMAGEL1T4NOBANK
    LDA #0
    STA <MATHPTR5
    LDA , Y
    ANDA #$C0
    BEQ PUTIMAGEL1T4P4ANOBANK
    LDA <MATHPTR5
    ORA #$C0
    STA <MATHPTR5
PUTIMAGEL1T4P4ANOBANK
    LDA , Y
    ANDA #$30
    BEQ PUTIMAGEL1T4P4BNOBANK
    LDA <MATHPTR5
    ORA #$30
    STA <MATHPTR5
PUTIMAGEL1T4P4BNOBANK
    LDA , Y
    ANDA #$0C
    BEQ PUTIMAGEL1T4P4CNOBANK
    LDA <MATHPTR5
    ORA #$0C
    STA <MATHPTR5
PUTIMAGEL1T4P4CNOBANK
    LDA , Y
    ANDA #$03
    BEQ PUTIMAGEL1T4P4DNOBANK
    LDA <MATHPTR5
    ORA #$03
    STA <MATHPTR5
PUTIMAGEL1T4P4DNOBANK
    JMP PUTIMAGEL1TFINALNOBANK

PUTIMAGEL1TFINALNOBANK
    LDA <MATHPTR5
    EORA #$FF
    STA <MATHPTR6
    LDA , X
    ANDA <MATHPTR6
    STA <MATHPTR6
    LDA , Y+
    ANDA <MATHPTR5
    ORA <MATHPTR6
    JMP PUTIMAGEDEFFINALNOBANK

PUTIMAGEL1T2NOBANK
PUTIMAGEDEFNOBANK
    LDA , Y+
PUTIMAGEDEFFINALNOBANK    
    STA , X+
    LEAU -1, U
    CMPU #0
    LBNE PUTIMAGEL1NOBANK
    
    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGEL1NNOBANK

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGEL1N0NOBANK

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW
    NEGA
    NEGB
    SBCA #0
    LEAY D, Y

    CLRA
    LDB CURRENTSL
    SUBD <IMAGEW
    LEAX D, X
    
    LDU <IMAGEW
    JMP PUTIMAGEL1NOBANK

PUTIMAGEL1N0NOBANK
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

PUTIMAGEL1NNOBANK
    CLRA
    LDB CURRENTSL
    SUBD <IMAGEW
    LEAX D, X

    LDD <IMAGEY
    ADDD #1
    CMPD CURRENTHEIGHT
    BEQ PUTIMAGECOMMONESKIPNOBANK

    LDD <IMAGEH
    SUBD #1
    STD <IMAGEH
    CMPD #0
    BLE PUTIMAGECOMMONENOBANK

    LDU <IMAGEW
    JMP PUTIMAGEL1NOBANK

PUTIMAGECOMMONESKIPNOBANK
    LDD <IMAGEW
PUTIMAGECOMMONESKIPL1NOBANK    
    LEAY D, Y
    LDD <IMAGEH
    SUBD #1
    STD <IMAGEH
    CMPD #0    
    BNE PUTIMAGECOMMONESKIPNOBANK

PUTIMAGECOMMONENOBANK
    LDA <IMAGET
    ANDA #$02
    BNE PUTIMAGECOMMONEWITHPALETTENOBANK

    ANDA #$AF

    RTS
PUTIMAGECOMMONEWITHPALETTENOBANK
    LDA #0
PUTIMAGECOMMONEL1NOBANK
    LDB , Y+
    JSR GIMEUPDATEPALETTE
    INCA
    CMPA PALETTELIMIT
    BNE PUTIMAGECOMMONEL1NOBANK

    JSR GIMEBANKROM

    ANDA #$AF

    RTS

