; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza ANDCC #$01ondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                      TEXT AT GIVEN POSITION ON 6847                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTPTR equ $01
TEXTSIZE equ $03
TABSTODRAW equ $04
TEXTWW equ $05
TEXTPEN equ $06
TEXTPAPER equ $07
SCREENCODE equ $08

TEXTATDECODE
    CMPA #$1F
    BHI TEXTATDECODEX1F
    LDA #$60
    JMP TEXTATDECODE0
TEXTATDECODEX1F
    CMPA #$40
    BHS TEXTATDECODEX39
    ADDA #$40
    JMP TEXTATDECODE0
TEXTATDECODEX39
    CMPA #$5F
    BHI TEXTATDECODEX5A
    SUBA #$40
    JMP TEXTATDECODE0
TEXTATDECODEX5A
    CMPA #$7F
    BHI TEXTATDECODEX7F
    SUBA #$20
    JMP TEXTATDECODE0
TEXTATDECODEX7F
    LDA #$60
    JMP TEXTATDECODE0
TEXTATDECODE0
    STA SCREENCODE
    RTS

TEXTAT
    LDA TEXTSIZE
    BNE TEXTATGO
    RTS

TEXTATGO
    LDY TEXTPTR
    LDA CURRENTMODE
    CMPA #2
    BHI TEXTATGO0X
    JMP TEXTATTILEMODE
TEXTATGO0X
    JMP TEXTATBITMAPMODE
    
;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

TEXTATBITMAPMODE
    RTS

;     LDX XCURSYS
;     LDY YCURSYS

;     ANDCC #$FE

;     LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
;     ADDA PLOT8LO,X              ;+ (8 * Xcell)
;     STA PLOTDEST               ;= cell address

;     LDA PLOTVBASEHI,Y          ;do the high byte
;     ADDA PLOT8HI,X
;     STA PLOTDEST+1

;     ANDCC #$FE

;     TXA
;     ADDA PLOTCVBASELO,Y          ;table of $8400 row base addresses
;     STA PLOTCDEST               ;= cell address

;     LDA #0
;     ADDA PLOTCVBASEHI,Y          ;do the high byte
;     STA PLOTCDEST+1

;     LDX TEXTSIZE
;     LDY #$0
; TEXTATBMLOOP2

;     LDA TABSTODRAW
;     BEQ TEXTATBMNSKIPTAB
;     JMP TEXTATBMSKIPTAB

; TEXTATBMNSKIPTAB
;     LDA (TEXTPTR),Y

;     CMPA #31
;     BHI TEXTATBMXCC
;     JMP TEXTATBMCC

; TEXTATBMXCC
;     JSR TEXTATDECODE
;     JMP TEXTATBMSP0

; TEXTATBMTAB
;     LDA XCURSYS
; TEXTATBMTAB2
;     CMPA TABCOUNT
;     BLO TEXTATBMTAB3
;     ANDCC #$01
;     SUBA TABCOUNT
;     JMP TEXTATBMTAB2
; TEXTATBMTAB3
;     STA TMPPTR
;     LDA TABCOUNT
;     ANDCC #$01
;     SUBA TMPPTR
;     STA TABSTODRAW
;     JMP TEXTATBMNEXT

; TEXTATBMCC
;     CMPA #09
;     BEQ TEXTATBMTAB
;     CMPA #01
;     BEQ TEXTATBMPEN
;     CMPA #02
;     BEQ TEXTATBMPAPER
;     CMPA #03
;     BEQ TEXTATBMCMOVEPREPARE
;     CMPA #04
;     BEQ TEXTATBMXAT
;     JMP TEXTATBMNEXT

; TEXTATBMXAT
;     JMP TEXTATBMAT

; TEXTATBMPEN
;     LEAY 1,Y
;     DECB
;     LDA TEXTWW
;     AND #$2
;     BEQ TEXTATBMPENDISABLED
;     LDA , Y
;     ASL A
;     ASL A
;     ASL A
;     ASL A
;     STA TEXTPEN
; TEXTATBMPENDISABLED
;     LEAY 1,Y
;     DECB
;     JMP TEXTATBMNEXT

; TEXTATBMPAPER
;     LEAY 1,Y
;     DECB
;     LDA TEXTWW
;     AND #$1
;     BEQ TEXTATBMPAPERDISABLED
;     LDA , Y
;     STA TEXTPAPER
; TEXTATBMPAPERDISABLED
;     LEAY 1,Y
;     DECB
;     JMP TEXTATBMNEXT

; TEXTATBMCMOVEPREPARE
;     LEAY 1,Y
;     DECB
;     LDA , Y
;     STA CLINEX
;     LEAY 1,Y
;     DECB
;     LDA , Y
;     STA CLINEY

; TEXTATBMCMOVE
;     ANDCC #$FE
;     LDA CLINEX
;     ADDA XCURSYS
;     STA XCURSYS
;     LDA CLINEY
;     ADDA YCURSYS
;     STA YCURSYS

;     JMP TEXTATBMNEXT

; TEXTATBMAT
;     LEAY 1,Y
;     DECB
;     LDA , Y
;     ANDCC #$01
;     SUBA XCURSYS
;     STA CLINEX
;     LEAY 1,Y
;     DECB
;     LDA , Y
;     ANDCC #$01
;     SUBA YCURSYS
;     STA CLINEY
;     JMP TEXTATBMCMOVE

; TEXTATBMSP0

;     TYA
;     PHA

;     TXA
;     PHA

;     LDX XCURSYS
;     LDY YCURSYS

;     ANDCC #$FE

;     LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
;     ADDA PLOT8LO,X              ;+ (8 * Xcell)
;     STA PLOTDEST               ;= cell address

;     LDA PLOTVBASEHI,Y          ;do the high byte
;     ADDA PLOT8HI,X
;     STA PLOTDEST+1

;     ANDCC #$FE

;     TXA
;     ADDA PLOTCVBASELO,Y          ;table of $8400 row base addresses
;     STA PLOTCDEST               ;= cell address

;     LDA #0
;     ADDA PLOTCVBASEHI,Y          ;do the high byte
;     STA PLOTCDEST+1

;     ANDCC #$FE

;     TXA
;     ADDA PLOTC2VBASELO,Y          ;table of $8400 row base addresses
;     STA PLOTC2DEST               ;= cell address

;     LDA #0
;     ADDA PLOTC2VBASEHI,Y          ;do the high byte
;     STA PLOTC2DEST+1

;     PLA
;     TAX
    
;     PLA
;     TAY

;     TYA
;     PHA
;     LDY #0

;     LDA SCREENCODE
;     STA TMPPTR
;     LDA #0
;     STA TMPPTR+1

;     ANDCC #$FE
;     ASL TMPPTR
;     ROL TMPPTR+1
;     ANDCC #$FE
;     ASL TMPPTR
;     ROL TMPPTR+1
;     ANDCC #$FE
;     ASL TMPPTR
;     ROL TMPPTR+1

;     ANDCC #$FE
;     LDA #$0
;     ADDA TMPPTR
;     STA TMPPTR
;     LDA #$90
;     ADDA TMPPTR+1
;     STA TMPPTR+1
; TEXTATBMSP0L1
;     LDA CURRENTMODE
;     CMPA #3
;     BEQ TEXTATBMSP0L1B3

; TEXTATBMSP0L1B2
;     LDA (TMPPTR),Y
;     STA (PLOTDEST),Y
;     JMP TEXTATBMSP0L1X

; TEXTATBMSP0L1B3
;     LDA (TMPPTR),Y
;     ANDCC #$FE
;     ASL
;     ORA (TMPPTR),Y
;     STA (PLOTDEST),Y
;     JMP TEXTATBMSP0L1X

; TEXTATBMSP0L1X
;     LEAX 1, X
;     CPY #8
;     BNE TEXTATBMSP0L1

;     LDA CURRENTMODE
;     CMPA #3
;     BEQ TEXTATBMC3

    
;     LDA #$36
;     STA $01
;     LDA TEXTWW
;     AND #$2
;     BEQ TEXTATBMCNOPEN
;     LDY #0
;     LDA (PLOTCDEST),Y
;     ORA TEXTPEN
;     STA (PLOTCDEST),Y
; TEXTATBMCNOPEN
;     LDA TEXTWW
;     AND #$1
;     BEQ TEXTATBMCNOPAPER
;     LDA (PLOTCDEST),Y
;     AND #$f0
;     ORA TEXTPAPER
;     STA (PLOTCDEST),Y
; TEXTATBMCNOPAPER
;     LDA #$37
;     STA $01
    
;     JMP TEXTATBMF

; TEXTATBMC3
    
;     LDA #$36
;     STA $01
;     LDA TEXTWW
;     AND #$2
;     BEQ TEXTATBMC3NOPEN
;     LDY #0
;     LDA TEXTPEN
;     STA (PLOTC2DEST),Y
;     LDA #0
;     STA (PLOTCDEST),Y
;     LDA TEXTPEN
;     ASL
;     ASL
;     ASL
;     ASL
;     ORA (PLOTCDEST),Y
;     STA (PLOTCDEST),Y
; TEXTATBMC3NOPEN
;     LDA #$37
;     STA $01
    
;     JMP TEXTATBMF

; TEXTATBMF
;     PLA
;     TAY
;     JMP TEXTATBMINCX

; TEXTATBMSKIPTAB
;     DEC TABSTODRAW
;     JMP TEXTATBMINCX

; TEXTATBMINCX
;     INC XCURSYS
;     LDA XCURSYS
;     CMPA #32
;     BEQ TEXTATBMNEXT2
;     JMP TEXTATBMNEXT
; TEXTATBMNEXT2
;     LDA #0
;     STA XCURSYS
;     INC YCURSYS
;     LDA YCURSYS
;     CMPA #25

;     BEQ TEXTATBMNEXT3
;     JMP TEXTATBMNEXT
; TEXTATBMNEXT3

;     ; scrolling ?

; TEXTATBMNEXT
;     LDA TABSTODRAW
;     BEQ TEXTATBMXLOOP2
;     JMP TEXTATBMLOOP2
; TEXTATBMXLOOP2
;     LEAX 1, X
;     DECB
;     BEQ TEXTATBMEND
;     JMP TEXTATBMLOOP2
; TEXTATBMEND
    ; 
    ; RTS

;-----------------------------------------------------------------------------
; TILE MODE
;-----------------------------------------------------------------------------

TEXTATTILEMODE
    LDB YCURSYS
    BEQ TEXTATSKIP
TEXTATLOOP1
    ANDCC #$FE
    LDX COPYOFTEXTADDRESS
    LEAX 32, X
    STX COPYOFTEXTADDRESS
    DECB
    BNE TEXTATLOOP1

TEXTATSKIP
    ANDCC #$FE
    LDA #0
    LDB XCURSYS
    ADDD COPYOFTEXTADDRESS
    STD COPYOFTEXTADDRESS

    LDX COPYOFTEXTADDRESS
    LDB TEXTSIZE
TEXTATLOOP2

    LDA TABSTODRAW
    BEQ TEXTATNSKIPTAB
    JMP TEXTATSKIPTAB

TEXTATNSKIPTAB
    LDA ,Y

    CMPA #31
    BHI TEXTATXCC
    JMP TEXTATCC

TEXTATXCC
    JSR TEXTATDECODE
    JMP TEXTATSP0

TEXTATTAB
    LDA XCURSYS
TEXTATTAB2
    CMPA TABCOUNT
    BLO TEXTATTAB3
    ANDCC #$01
    SUBA TABCOUNT
    JMP TEXTATTAB2
TEXTATTAB3
    STA TMPPTR
    LDA TABCOUNT
    ANDCC #$01
    SUBA TMPPTR
    STA TABSTODRAW
    JMP TEXTATNEXT

TEXTATCC
    CMPA #09
    BEQ TEXTATTAB
    CMPA #01
    BEQ TEXTATPEN
    CMPA #02
    BEQ TEXTATPAPER
    CMPA #03
    BEQ TEXTATCMOVEPREPARE
    CMPA #04
    BEQ TEXTATXAT
    JMP TEXTATNEXT

TEXTATXAT
    JMP TEXTATAT

TEXTATPEN
    LEAY 1,Y
    DECB
    LDA TEXTWW
    ANDA #$2
    BEQ TEXTATPENDISABLED
    LDA , Y
    STA TEXTPEN
TEXTATPENDISABLED
    LEAY 1,Y
    DECB
    JMP TEXTATNEXT

TEXTATPAPER
    LEAY 1,Y
    DECB
    LDA TEXTWW
     ANDA #$1
    BEQ TEXTATPAPERDISABLED
    LDA , Y
    STA $d021
    STA $d020
TEXTATPAPERDISABLED
    LEAY 1,Y
    DECB
    JMP TEXTATNEXT

TEXTATCMOVEPREPARE
    LEAY 1,Y
    DECB
    LDA , Y
    STA CLINEX
    LEAY 1,Y
    DECB
    LDA , Y
    STA CLINEY

TEXTATCMOVE
    ANDCC #$FE
    LDA CLINEX
    ADDA XCURSYS
    CMPA #$0
    BLT TEXTATCMOVESKIPX
    CMPA CURRENTWIDTH+1
    BGE TEXTATCMOVESKIPX
    STA XCURSYS
    LDA CLINEX
    LDX COPYOFTEXTADDRESS
    LEAX A, X
    STX COPYOFTEXTADDRESS

TEXTATCMOVESKIPX
    ANDCC #$FE
    LDA CLINEY
    ADDA YCURSYS
    CMPA #$0
    BLT TEXTATCMOVESKIPY
    CMPA CURRENTHEIGHT+1
    BGE TEXTATCMOVESKIPY
    STA YCURSYS

    LDB YCURSYS
    LDA CURRENTWIDTH+1
TEXTATCMOVELOOPY
    ANDCC #$FE
    LDX COPYOFTEXTADDRESS
    LEAX A, X
    STX COPYOFTEXTADDRESS
    DECB
    BNE TEXTATCMOVELOOPY

TEXTATCMOVESKIPY
    LEAY 1,Y
    DECB
    JMP TEXTATNEXT

TEXTATAT
    LEAY 1,Y
    DECB
    LDA , Y
    ANDCC #$01
    SUBA XCURSYS
    STA CLINEX
    LEAY 1,Y
    DECB
    LDA , Y
    ANDCC #$01
    SUBA YCURSYS
    STA CLINEY
    JMP TEXTATCMOVE

TEXTATSP0
    STA , X
    LEAY 1, Y
    LDA TEXTWW
    ANDA #$2
    BEQ TEXTATCNOPEN
    LDA TEXTPEN
    ; STA (COPYOFCOLORMAPADDRESS),Y
TEXTATCNOPEN
    JMP TEXTATINCX

TEXTATSKIPTAB
    DEC TABSTODRAW
    JMP TEXTATINCX

TEXTATINCX
    INC XCURSYS
    LDA XCURSYS
    CMPA #32
    BEQ TEXTATNEXT2
    JMP TEXTATNEXT
TEXTATNEXT2
    LDA #0
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMPA #16

    BEQ TEXTATNEXT3
    JMP TEXTATNEXT
TEXTATNEXT3

    LDA #$FE
    STA DIRECTION
    JSR VSCROLLT

    DEC YCURSYS
    ANDCC #$01
    LDX COPYOFTEXTADDRESS
    LEAX -32, X
    STX COPYOFTEXTADDRESS

TEXTATNEXT
    LDA TABSTODRAW
    BEQ TEXTATXLOOP2
    JMP TEXTATLOOP2
TEXTATXLOOP2
    LEAX 1, X
    DECB
    BEQ TEXTATEND
    JMP TEXTATLOOP2
TEXTATEND
    
    RTS
