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
;*                       INTERNAL VARIABLES FOR 6847 HARDWARE                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
PLOTDEST equ $0b ; $29
PLOTCDEST equ $0d ; $27
PLOTC2DEST equ $0f ; $25

XGR    fdb 0
YGR    fdb 0
LINE   fcb $ff, $ff

ORIGINX    fdb 0
ORIGINY    fdb 0
RESOLUTIONX    fdb 0
RESOLUTIONY    fdb 0

CLIPX1    fdb 0
CLIPY1    fdb 0
CLIPX2    fdb 319
CLIPY2    fdb 199

LASTCOLOR fcb 0
CURRENTWIDTH      fdb 32
CURRENTHEIGHT      fdb 16
CURRENTTILESWIDTH      fcb 32
CURRENTTILESHEIGHT      fcb 16
CURRENTTILES            fcb 128
CURRENTFRAMESIZE   fdb 32*16
CURRENTSL          fcb 32
FONTWIDTH       fcb 8
FONTHEIGHT      fcb 8

;       (x1,y1)  w (chars) / wb (bytes)
;       +----------------+
;  sa ->|*               | h (chars) / hb (bytes)
;       |                |
;       +----------------+ (x2, y2)
;
CONSOLEID     fcb $ff       ; <-- actual
;
; Text mode
;
CONSOLEX1     fcb 0         ; <-- input from program (chars)
CONSOLEY1     fcb 0         ; <-- input from program (chars)
CONSOLEX2     fcb 31        ; <-- recalculated (chars)
CONSOLEY2     fcb 15        ; <-- recalculated (chars)
CONSOLEW      fcb 32        ; <-- calculated (chars)
CONSOLEH      fcb 16        ; <-- calculated (chars)
;
; Graphic mode
;
CONSOLESA     fdb 0         ; <-- calculated (address)
CONSOLEWB     fcb 32        ; <-- calculated (bytes)
CONSOLEHB     fcb 16        ; <-- calculated (bytes)
;
CONSOLES      rzb 4*8        ; <-- storage for virtual consoles
CONSOLES2     rzb 4*2        ; <-- storage for memorize / remember on console

IMAGEW2 EQU $40
IMAGEX EQU $41 ; $42
IMAGEY EQU $43 ; $44
IMAGEW EQU $45
IMAGEH EQU $46
IMAGEH2 EQU $47
IMAGET EQU $48
IMAGEF EQU $49

BLITTMPPTR EQU $50 ; $51
BLITTMPPTR2 EQU $52 ; $53
BLITS0 EQU $54
BLITS1 EQU $55
BLITS2 EQU $56
BLITR0 EQU $57
BLITR1 EQU $58
BLITR2 EQU $59
BLITR3 EQU $60

DOUBLEBUFFERENABLED     fcb     $00
SCREENVISIBLE           fcb     $00

; ------------------------------------------------------------------------------
; BITMAP MODE (MODE #2)
; ------------------------------------------------------------------------------

; PLOTVBASELO
;     fcb <($A000+(0*320)),<($A000+(1*320)),<($A000+(2*320)),<($A000+(3*320))
;     fcb <($A000+(4*320)),<($A000+(5*320)),<($A000+(6*320)),<($A000+(7*320))
;     fcb <($A000+(8*320)),<($A000+(9*320)),<($A000+(10*320)),<($A000+(11*320))
;     fcb <($A000+(12*320)),<($A000+(13*320)),<($A000+(14*320)),<($A000+(15*320))
;     fcb <($A000+(16*320)),<($A000+(17*320)),<($A000+(18*320)),<($A000+(19*320))
;     fcb <($A000+(20*320)),<($A000+(21*320)),<($A000+(22*320)),<($A000+(23*320))
;     fcb <($A000+(24*320))

; PLOTVBASEHI
;     fcb >($A000+(0*320)),>($A000+(1*320)),>($A000+(2*320)),>($A000+(3*320))
;     fcb >($A000+(4*320)),>($A000+(5*320)),>($A000+(6*320)),>($A000+(7*320))
;     fcb >($A000+(8*320)),>($A000+(9*320)),>($A000+(10*320)),>($A000+(11*320))
;     fcb >($A000+(12*320)),>($A000+(13*320)),>($A000+(14*320)),>($A000+(15*320))
;     fcb >($A000+(16*320)),>($A000+(17*320)),>($A000+(18*320)),>($A000+(19*320))
;     fcb >($A000+(20*320)),>($A000+(21*320)),>($A000+(22*320)),>($A000+(23*320))
;     fcb >($A000+(24*320))

; PLOT8LO
;     fcb <(0*8),<(1*8),<(2*8),<(3*8),<(4*8),<(5*8),<(6*8),<(7*8),<(8*8),<(9*8)
;     fcb <(10*8),<(11*8),<(12*8),<(13*8),<(14*8),<(15*8),<(16*8),<(17*8),<(18*8),<(19*8)
;     fcb <(20*8),<(21*8),<(22*8),<(23*8),<(24*8),<(25*8),<(26*8),<(27*8),<(28*8),<(29*8)
;     fcb <(30*8),<(31*8),<(32*8),<(33*8),<(34*8),<(35*8),<(36*8),<(37*8),<(38*8),<(39*8)

; PLOT8HI
;     fcb >(0*8),>(1*8),>(2*8),>(3*8),>(4*8),>(5*8),>(6*8),>(7*8),>(8*8),>(9*8)
;     fcb >(10*8),>(11*8),>(12*8),>(13*8),>(14*8),>(15*8),>(16*8),>(17*8),>(18*8),>(19*8)
;     fcb >(20*8),>(21*8),>(22*8),>(23*8),>(24*8),>(25*8),>(26*8),>(27*8),>(28*8),>(29*8)
;     fcb >(30*8),>(31*8),>(32*8),>(33*8),>(34*8),>(35*8),>(36*8),>(37*8),>(38*8),>(39*8)

; PLOTCVBASELO
;     fcb <($8400+(0*40)),<($8400+(1*40)),<($8400+(2*40)),<($8400+(3*40))
;     fcb <($8400+(4*40)),<($8400+(5*40)),<($8400+(6*40)),<($8400+(7*40))
;     fcb <($8400+(8*40)),<($8400+(9*40)),<($8400+(10*40)),<($8400+(11*40))
;     fcb <($8400+(12*40)),<($8400+(13*40)),<($8400+(14*40)),<($8400+(15*40))
;     fcb <($8400+(16*40)),<($8400+(17*40)),<($8400+(18*40)),<($8400+(19*40))
;     fcb <($8400+(20*40)),<($8400+(21*40)),<($8400+(22*40)),<($8400+(23*40))
;     fcb <($8400+(24*40))

; PLOTCVBASEHI
;     fcb >($8400+(0*40)),>($8400+(1*40)),>($8400+(2*40)),>($8400+(3*40))
;     fcb >($8400+(4*40)),>($8400+(5*40)),>($8400+(6*40)),>($8400+(7*40))
;     fcb >($8400+(8*40)),>($8400+(9*40)),>($8400+(10*40)),>($8400+(11*40))
;     fcb >($8400+(12*40)),>($8400+(13*40)),>($8400+(14*40)),>($8400+(15*40))
;     fcb >($8400+(16*40)),>($8400+(17*40)),>($8400+(18*40)),>($8400+(19*40))
;     fcb >($8400+(20*40)),>($8400+(21*40)),>($8400+(22*40)),>($8400+(23*40))
;     fcb >($8400+(24*40))

; PLOTC2VBASELO
;     fcb <($D800+(0*40)),<($D800+(1*40)),<($D800+(2*40)),<($D800+(3*40))
;     fcb <($D800+(4*40)),<($D800+(5*40)),<($D800+(6*40)),<($D800+(7*40))
;     fcb <($D800+(8*40)),<($D800+(9*40)),<($D800+(10*40)),<($D800+(11*40))
;     fcb <($D800+(12*40)),<($D800+(13*40)),<($D800+(14*40)),<($D800+(15*40))
;     fcb <($D800+(16*40)),<($D800+(17*40)),<($D800+(18*40)),<($D800+(19*40))
;     fcb <($D800+(20*40)),<($D800+(21*40)),<($D800+(22*40)),<($D800+(23*40))
;     fcb <($D800+(24*40))

; PLOTC2VBASEHI
;     fcb >($D800+(0*40)),>($D800+(1*40)),>($D800+(2*40)),>($D800+(3*40))
;     fcb >($D800+(4*40)),>($D800+(5*40)),>($D800+(6*40)),>($D800+(7*40))
;     fcb >($D800+(8*40)),>($D800+(9*40)),>($D800+(10*40)),>($D800+(11*40))
;     fcb >($D800+(12*40)),>($D800+(13*40)),>($D800+(14*40)),>($D800+(15*40))
;     fcb >($D800+(16*40)),>($D800+(17*40)),>($D800+(18*40)),>($D800+(19*40))
;     fcb >($D800+(20*40)),>($D800+(21*40)),>($D800+(22*40)),>($D800+(23*40))
;     fcb >($D800+(24*40))

; ------------------------------------------------------------------------------
; MULTICOLOR MODE (MODE #3)
; ------------------------------------------------------------------------------

; PLOT4LO
;     fcb <(0*4),<(1*4),<(2*4),<(3*4),<(4*4),<(5*4),<(6*4),<(7*4),<(8*4),<(9*4)
;     fcb <(10*4),<(11*4),<(12*4),<(13*4),<(14*4),<(15*4),<(16*4),<(17*4),<(18*4),<(19*4)
;     fcb <(20*4),<(21*4),<(22*4),<(23*4),<(24*4),<(25*4),<(26*4),<(27*4),<(28*4),<(29*4)
;     fcb <(30*4),<(31*4),<(32*4),<(33*4),<(34*4),<(35*4),<(36*4),<(37*4),<(38*4),<(39*4)
;     fcb <(40*4),<(41*4),<(42*4),<(43*4),<(44*4),<(45*4),<(46*4),<(47*4),<(48*4),<(49*4)
;     fcb <(50*4),<(51*4),<(52*4),<(53*4),<(54*4),<(55*4),<(56*4),<(57*4),<(58*4),<(59*4)
;     fcb <(60*4),<(61*4),<(62*4),<(63*4),<(64*4),<(65*4),<(66*4),<(67*4),<(68*4),<(69*4)
;     fcb <(70*4),<(71*4),<(72*4),<(73*4),<(74*4),<(75*4),<(76*4),<(77*4),<(78*4),<(79*4)

; PLOT4HI
;     fcb >(0*4),>(1*4),>(2*4),>(3*4),>(4*4),>(5*4),>(6*4),>(7*4),>(8*4),>(9*4)
;     fcb >(10*4),>(11*4),>(12*4),>(13*4),>(14*4),>(15*4),>(16*4),>(17*4),>(18*4),>(19*4)
;     fcb >(20*4),>(21*4),>(22*4),>(23*4),>(24*4),>(25*4),>(26*4),>(27*4),>(28*4),>(29*4)
;     fcb >(30*4),>(31*4),>(32*4),>(33*4),>(34*4),>(35*4),>(36*4),>(37*4),>(38*4),>(39*4)
;     fcb >(40*4),>(41*4),>(42*4),>(43*4),>(44*4),>(45*4),>(46*4),>(47*4),>(48*4),>(49*4)
;     fcb >(50*4),>(51*4),>(52*4),>(53*4),>(54*4),>(55*4),>(56*4),>(57*4),>(58*4),>(59*4)
;     fcb >(60*4),>(61*4),>(62*4),>(63*4),>(64*4),>(65*4),>(66*4),>(67*4),>(68*4),>(69*4)
;     fcb >(70*4),>(71*4),>(72*4),>(73*4),>(74*4),>(75*4),>(76*4),>(77*4),>(78*4),>(79*4)

CALCPOSG
    PSHS D
    BSR CALCPOSGR
    PULS D
    RTS
    
CALCPOSGR
    LDA CURRENTMODE
    CMPA #7
    BNE CALCPOS7X
    JSR CALCPOS7
    RTS
CALCPOS7X
    CMPA #8
    BNE CALCPOS8X
    JSR CALCPOS8
    RTS
CALCPOS8X
    CMPA #9
    BNE CALCPOS9X
    JSR CALCPOS9
    RTS
CALCPOS9X
    CMPA #10
    BNE CALCPOS10X
    JSR CALCPOS10
    RTS
CALCPOS10X
    CMPA #11
    BNE CALCPOS11X
    JSR CALCPOS11
    RTS
CALCPOS11X
    CMPA #12
    BNE CALCPOS12X
    JSR CALCPOS12
    RTS
CALCPOS12X
    CMPA #13
    BNE CALCPOS13X
    JSR CALCPOS13
    RTS
CALCPOS13X
    CMPA #14
    BNE CALCPOS14X
    JSR CALCPOS14
    RTS
CALCPOS14X
    RTS

CALCPOS7

    LDA #1
    STA <PATTERN

    LDX BITMAPADDRESS
    LDB <MATHPTR1
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <MATHPTR0
    LDA #0
    LSLB
    ROLA
    LEAX D, X

    RTS

CALCPOS8

    LDA #0
    STA <PATTERN

    LDX BITMAPADDRESS
    LDB <MATHPTR1
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <MATHPTR0
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    RTS

CALCPOS9

    LDA #1
    STA <PATTERN

    LDX BITMAPADDRESS
    LDB <MATHPTR1
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <MATHPTR0
    LDA #0
    LSLB
    ROLA
    LEAX D, X

    RTS

CALCPOS10

    LDA #0
    STA <PATTERN

    LDX BITMAPADDRESS
    LDB <MATHPTR1
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <MATHPTR0
    LDA #0
    LSLB
    ROLA
    LEAX D, X

    RTS

CALCPOS11

    LDA #1
    STA <PATTERN

    LDX BITMAPADDRESS
    LDB <MATHPTR1
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <MATHPTR0
    LDA #0
    LSLB
    ROLA
    LEAX D, X

    RTS

CALCPOS12

    LDA #0
    STA <PATTERN

    LDX BITMAPADDRESS
    LDB <MATHPTR1
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <MATHPTR0
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    RTS

CALCPOS13

    LDA #1
    STA <PATTERN

    LDX BITMAPADDRESS
    LDB <MATHPTR1
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <MATHPTR0
    LDA #0
    LSLB
    ROLA
    LEAX D, X

    RTS

CALCPOS14

    LDA #0
    STA <PATTERN

    LDX BITMAPADDRESS
    LDB <MATHPTR1
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <MATHPTR0
    LDA #0
    LEAX D, X

    RTS

CONSOLECALCULATE
    LDA CONSOLEX1
    STA MATHPTR0
    LDA CONSOLEY1
    STA MATHPTR1
    JSR CALCPOSG
    STX CONSOLESA

    LDA CONSOLEW
    STA CONSOLEWB

    LDA CURRENTMODE
    CMPA #8
    BEQ CONSOLECALCULATESKIPD
    CMPA #10
    BEQ CONSOLECALCULATESKIPD
    CMPA #12
    BEQ CONSOLECALCULATESKIPD

    ASL CONSOLEWB
CONSOLECALCULATESKIPD
    LDA CONSOLEH
    STA CONSOLEHB
    ASL CONSOLEHB
    ASL CONSOLEHB
    ASL CONSOLEHB

    RTS    

CALCPOST0
    PSHS D
    LDX TEXTADDRESS
    STX <COPYOFTEXTADDRESS
    CMPB #0
    BEQ CALCPOST0SKIP
CALCPOST0LOOP1
    ANDCC #$FE
    LDX <COPYOFTEXTADDRESS
    LDA CURRENTTILESWIDTH
    LEAX A, X
    STX <COPYOFTEXTADDRESS
    DECB
    BNE CALCPOST0LOOP1
CALCPOST0SKIP
    PULS D
    ANDCC #$FE
    TFR A, B
    LDA #0
    ADDD <COPYOFTEXTADDRESS
    STD <COPYOFTEXTADDRESS
    LDY <COPYOFTEXTADDRESS
    RTS
