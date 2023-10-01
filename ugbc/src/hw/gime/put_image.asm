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

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

PUTIMAGE

    ; We must do nothing if we are in text mode!
    LDA CURRENTTILEMODE
    BEQ PUTIMAGEGO
    RTS

PUTIMAGEGO

    ; Convert PLOTX, PLOTY into the first byte of video RAM.

    LDD IMAGEX
    STD PLOTX
    LDD IMAGEY
    STD PLOTY

    JSR GIMECALCPOSBM

    ; Based on bpp, we 

    LDB PALETTELIMIT
    CMPB #2
    BEQ PUTIMAGEGOS3
    CMPB #4
    BEQ PUTIMAGEGOS2
    CMPB #16
    BEQ PUTIMAGEGOS1
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
    JMP PUTIMAGEGOSX

PUTIMAGEGOS2
    LDD , Y
    LSRA
    RORB
    LSRA
    RORB
    JMP PUTIMAGEGOSX

PUTIMAGEGOS1
    LDD , Y
    LSRA
    RORB
    JMP PUTIMAGEGOSX

PUTIMAGEGOSX
    STD IMAGEW
    LDA 2, Y
    STA IMAGEH
    
    LEAY 3,Y

    LDU IMAGEW
PUTIMAGEL1
    LDA IMAGEF
    ANDA #32
    CMPA #0 
    BEQ PUTIMAGEDEF

    LDA PALETTELIMIT
    CMPA #2
    BEQ PUTIMAGEL1T2
    CMPA #4
    BEQ PUTIMAGEL1T4

PUTIMAGEL1T16
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
    LDA <MATHPTR5
    EORA #$FF
    STA <MATHPTR6
    LDA , X
    ANDA <MATHPTR6
    STA <MATHPTR6
    LDA , Y+
    ANDA <MATHPTR5
    ORA <MATHPTR6
    JMP PUTIMAGEDEFFINAL

PUTIMAGEL1T2
PUTIMAGEDEF
    LDA , Y+
PUTIMAGEDEFFINAL    
    STA , X+
    LEAU -1, U
    CMPU #0
    LBNE PUTIMAGEL1
    
    LDA IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGEL1N

    LDA IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGEL1N0

    ORA #65
    STA IMAGEF

    CLRA
    CLRB
    SUBD IMAGEW
    LEAX D, Y

    CLRA
    LDB CURRENTSL
    SUBD IMAGEW
    LEAX D, X
    
    LDU IMAGEW
    JMP PUTIMAGEL1

PUTIMAGEL1N0
    LDA IMAGEF
    ANDA #$FE
    STA IMAGEF

PUTIMAGEL1N
    CLRA
    LDB CURRENTSL
    SUBD IMAGEW
    LEAX D, X

    LDD IMAGEY
    ADDD #1
    CMPD CURRENTHEIGHT
    BEQ PUTIMAGECOMMONESKIP

    DEC IMAGEH
    LDB IMAGEH
    CMPB #0
    BEQ PUTIMAGECOMMONE

    LDU IMAGEW
    JMP PUTIMAGEL1

PUTIMAGECOMMONESKIP
    LDD IMAGEW
PUTIMAGECOMMONESKIPL1    
    LEAY D, Y
    DEC IMAGEH
    BNE PUTIMAGECOMMONESKIPL1

PUTIMAGECOMMONE
    LDA #0
PUTIMAGECOMMONEL1
    LDB , Y+
    JSR GIMEUPDATEPALETTE
    INCA
    CMPA PALETTELIMIT
    BNE PUTIMAGECOMMONEL1
    RTS

