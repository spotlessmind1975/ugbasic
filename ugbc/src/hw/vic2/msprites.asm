; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                         SPRITE MULTIPLEXING FOR VIC-II                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Source code ispired from 
;  - Spritemultiplexing example V2.1
;     by Lasse Loorni (loorni@gmail.com)
;  Available at http://cadaver.github.io

IRQ1LINE        = $FC
IRQ2LINE        = $2a
MAXSPR          = 32
NUMSPRITES      = $02
SPRUPDATEFLAG:   .BYTE $00
SORTEDSPRITES:   .BYTE $00
TEMPVARIABLE:   .BYTE $00
SPRIRQCOUNTER:  .BYTE 0
SORTORDER       = $26
SORTORDERLAST   = $46

MSPRITESINIT:
    LDA #$00
    STA SORTEDSPRITES
    STA SPRUPDATEFLAG
    LDX #MAXSPR-1
MSPRITESINITISORDERLIST:
    TXA
    STA SORTORDER, X
    DEX
    BPL MSPRITESINITISORDERLIST
    RTS

MSPRITESMANAGER:
    DEC $d019
    
    PHA
    TXA
    PHA
    TYA
    PHA

    LDA #$ff
    STA $D001
    STA $D003
    STA $D005
    STA $D007
    STA $D009
    STA $D00B
    STA $D00D
    STA $D00F

    LDA SPRUPDATEFLAG
    BEQ MSPRITESMANAGERNONEWSPRITES
    LDA #$00
    STA SPRUPDATEFLAG
    LDA SPRITECOUNT
    STA NUMSPRITES
    LDA NUMSPRITES
    STA SORTEDSPRITES
    BNE MSPRITESMANAGERBEGINSORT
    
MSPRITESMANAGERNONEWSPRITES:
    LDX SORTEDSPRITES
    CPX #$09
    BCC MSPRITESMANAGERNOMORE8
    LDX #$08
MSPRITESMANAGERNOMORE8:
    LDA D015TBL, X
    STA $d015
    BEQ MSPRITESMANAGERNOSPRITESATALL
    LDA #$00
    STA SPRIRQCOUNTER
    LDA #<MSPRITESMANAGER2
    STA MSPRITESMANAGERADDRESS+1
    LDA #>MSPRITESMANAGER2
    STA MSPRITESMANAGERADDRESS+2
    JMP MSPRITESMANAGER2DIRECT
MSPRITESMANAGERNOSPRITESATALL:
    PLA
    TAY
    PLA
    TAX
    PLA
    RTS

MSPRITESMANAGERBEGINSORT:
    LDX #MAXSPR
    DEX
    CPX SORTEDSPRITES
    BCC MSPRITESMANAGERCLEARDONE
    LDA #$ff
MSPRITESMANAGERCLEARLOOP: 
    STA SPRY, X
    ; STA SPROY, X
    DEX
    CPX SORTEDSPRITES
    BCS MSPRITESMANAGERCLEARLOOP
MSPRITESMANAGERCLEARDONE: 
    LDX #$00
MSPRITESMANAGERSORTLOOP:  
    LDY SORTORDER+1, X
    LDA SPRY, Y
    LDY SORTORDER, X
    CMP SPRY, Y
    BCS MSPRITESMANAGERSORTSKIP
    STX MSPRITESMANAGERSORTRELOAD+1
MSPRITESMANAGERSORTSWAP:  
    LDA SORTORDER+1, X
    STA SORTORDER, X
    STY SORTORDER+1, X
    CPX #$00
    BEQ MSPRITESMANAGERSORTRELOAD
    DEX
    LDY SORTORDER+1, X
    LDA SPRY, Y
    LDY SORTORDER, X
    CMP SPRY, Y
    BCC MSPRITESMANAGERSORTSWAP
MSPRITESMANAGERSORTRELOAD:
    LDX #$00
MSPRITESMANAGERSORTSKIP:  
    INX
    CPX #MAXSPR-1
    BCC MSPRITESMANAGERSORTLOOP
    LDX SORTEDSPRITES
    LDA #$ff
    STA SORTSPRY, X
    LDX #$00
MSPRITESMANAGERSORTLOOP3:
    LDY SORTORDER, X
    LDA SPRY, Y
    STA SORTSPRY, X
    LDA SPRX, Y
    STA SORTSPRX, x
    LDA SPRF, Y
    STA SORTSPRF, X
    LDA SPRC, Y
    STA SORTSPRC, X
    LDA SPRE, Y
    STA SORTSPRE, X
    INX
    CPX SORTEDSPRITES
    BCC MSPRITESMANAGERSORTLOOP3
    JMP MSPRITESMANAGERNONEWSPRITES

MSPRITESMANAGER2:
    DEC $D019

    PHA
    TXA
    PHA
    TYA
    PHA

MSPRITESMANAGER2DIRECT:    
    LDY SPRIRQCOUNTER               
    LDA SORTSPRY, Y                 
    CLC
    ADC #$10                        
    BCC MSPRITESMANAGER2NOTOVER     
    LDA #$ff                        
MSPRITESMANAGER2NOTOVER:   
    STA TEMPVARIABLE
MSPRITESMANAGER2SPRITELOOP:
    LDA SORTSPRY, Y
    CMP TEMPVARIABLE                
    BCS MSPRITESMANAGER2ENDSPR
    LDX PHYSICALSPRTBL2, Y          
    STA $D001, X                    
    LDA SORTSPRX, y
    ASL
    STA $D000, X
    BCC MSPRITESMANAGER2LOWMSB
    LDA $D010
    ORA ORTBL, X
    STA $D010
    JMP MSPRITESMANAGER2MSBOK
MSPRITESMANAGER2LOWMSB:    
    LDA $D010
    AND ANDTBL, X
    STA $D010
MSPRITESMANAGER2MSBOK:     
    LDX PHYSICALSPRTBL1, Y           
    LDA SORTSPRF, Y
MSPRITESMANAGER2MSBOKADDRESS:
    STA $83f8, X                     
    LDA SORTSPRC, Y
    STA $D027, X

    LDA SORTSPRE, Y
    AND #$2
    BEQ MSPRITESMANAGER2NOYDOUBLE
    LDA $D017
    ORA ORTBL, X
    STA $D017
    JMP MSPRITESMANAGER2YDOUBLEDONE
MSPRITESMANAGER2NOYDOUBLE:
    LDA $D017
    AND ORTBL, X
    STA $D017
MSPRITESMANAGER2YDOUBLEDONE:

    LDA SORTSPRE, Y
    AND #$1
    BEQ MSPRITESMANAGER2NOXDOUBLE
    LDA $D01D
    ORA ORTBL, X
    STA $D01D
    JMP MSPRITESMANAGER2XDOUBLEDONE
MSPRITESMANAGER2NOXDOUBLE:
    LDA $D01D
    AND ORTBL, X
    STA $D01D
MSPRITESMANAGER2XDOUBLEDONE:

    INY
    BNE MSPRITESMANAGER2SPRITELOOP
MSPRITESMANAGER2ENDSPR:    
    CMP #$ff                        
    BEQ MSPRITESMANAGER2LASTSPR
    STY SPRIRQCOUNTER
    SEC                             
    SBC #$10                        
    CMP $d012                       
    BCS MSPRITESMANAGER2DIRECTX
    JMP MSPRITESMANAGER2DIRECT
MSPRITESMANAGER2DIRECTX:
    STA $d012

    PLA
    TAY
    PLA
    TAX
    PLA

    RTS
MSPRITESMANAGER2LASTSPR:   
    LDA #<MSPRITESMANAGER           
    STA MSPRITESMANAGERADDRESS+1    
    LDA #>MSPRITESMANAGER           
    STA MSPRITESMANAGERADDRESS+2
    LDA #IRQ1LINE
    STA $D012

    PLA
    TAY
    PLA
    TAX
    PLA

    RTS

SPRX:           .RES MAXSPR,0                   
SPRY:           .RES MAXSPR,0
SPROY:          .RES MAXSPR,$FF
SPRC:           .RES MAXSPR,0
SPRF:           .RES MAXSPR,0
SPRE:           .RES MAXSPR,0

SORTSPRX:       .RES MAXSPR,0                   
SORTSPRY:       .RES MAXSPR,0                   
                .BYTE $FF                       
SORTSPRC:       .RES MAXSPR,0
SORTSPRF:       .RES MAXSPR,0
SORTSPRE:       .RES MAXSPR,0

D015TBL:        .BYTE %00000000                  
                .BYTE %00000001                  
                .BYTE %00000011
                .BYTE %00000111
                .BYTE %00001111
                .BYTE %00011111
                .BYTE %00111111
                .BYTE %01111111
                .BYTE %11111111

PHYSICALSPRTBL1:.BYTE 0,1,2,3,4,5,6,7            
                .BYTE 0,1,2,3,4,5,6,7            
                .BYTE 0,1,2,3,4,5,6,7
                .BYTE 0,1,2,3,4,5,6,7
                .BYTE 0,1,2,3,4,5,6,7
                .BYTE 0,1,2,3,4,5,6,7
                .BYTE 0,1,2,3,4,5,6,7
                .BYTE 0,1,2,3,4,5,6,7

PHYSICALSPRTBL2:.BYTE 0,2,4,6,8,10,12,14
                .BYTE 0,2,4,6,8,10,12,14
                .BYTE 0,2,4,6,8,10,12,14
                .BYTE 0,2,4,6,8,10,12,14
                .BYTE 0,2,4,6,8,10,12,14
                .BYTE 0,2,4,6,8,10,12,14
                .BYTE 0,2,4,6,8,10,12,14
                .BYTE 0,2,4,6,8,10,12,14

ANDTBL:         .BYTE 255-1
ORTBL:          .BYTE 1
                .BYTE 255-2
                .BYTE 2
                .BYTE 255-4
                .BYTE 4
                .BYTE 255-8
                .BYTE 8
                .BYTE 255-16
                .BYTE 16
                .BYTE 255-32
                .BYTE 32
                .BYTE 255-64
                .BYTE 64
                .BYTE 255-128
                .BYTE 128

MSPRITEDUPLICATESINGLE:
    CLC
    LDA #<SPRC
    STA TMPPTR2
    LDA #>SPRC
    STA TMPPTR2+1
MSPRITEDUPLICATEY0:
    LDY #00
    LDA (TMPPTR2),Y
MSPRITEDUPLICATEY1:
    LDY #00
    STA (TMPPTR2),Y
    LDA #<SPRF
    STA TMPPTR2
    LDA #>SPRF
    STA TMPPTR2+1
MSPRITEDUPLICATEY2:
    LDY #00
    LDA (TMPPTR2),Y
MSPRITEDUPLICATEY3:
    LDY #00
    STA (TMPPTR2),Y
    LDA #<SPRE
    STA TMPPTR2
    LDA #>SPRE
    STA TMPPTR2+1
MSPRITEDUPLICATEY4:
    LDY #00
    LDA (TMPPTR2),Y
MSPRITEDUPLICATEY5:
    LDY #00
    STA (TMPPTR2),Y
    RTS

MSPRITEDUPLICATE:
    JSR MSPRITEDECODEX
    ; DECODE: X -> MATHPTR3(c), MATHPTR4(y), MATHPTR5(x), MATHPTR6(y*x*c), MATHPTR7(w)    
    LDA MATHPTR4
    STA MATHPTR1    
MSPRITEDUPLICATEL00:

MSPRITEDUPLICATEL10:
    LDX MATHPTR5
MSPRITEDUPLICATEL1:
    JSR MSPRITEDUPLICATESINGLE
    INC MSPRITEDUPLICATEY0+1
    INC MSPRITEDUPLICATEY1+1
    INC MSPRITEDUPLICATEY2+1
    INC MSPRITEDUPLICATEY3+1
    INC MSPRITEDUPLICATEY4+1
    INC MSPRITEDUPLICATEY5+1
    INY
    DEX
    BEQ MSPRITEDUPLICATEL1B

    JMP MSPRITEDUPLICATEL1

MSPRITEDUPLICATEL1B:

    LDX MATHPTR5

    SEC
    LDA MATHPTR4
    SBC #1
    STA MATHPTR4
    BNE MSPRITEDUPLICATEL10

    LDA MATHPTR1
    STA MATHPTR4

    SEC
    LDA MATHPTR3
    SBC #1
    STA MATHPTR3
    BNE MSPRITEDUPLICATEL00

    CLC
    LDA SPRITECOUNT
    ADC MATHPTR6
    STA SPRITECOUNT

@IF ! multiplexingSpriteConfig.async
    LDA #1
    STA SPRUPDATEFLAG
MSPRITEDUPLICATEL1W2:
    LDA SPRUPDATEFLAG
    BNE MSPRITEDUPLICATEL1W2
@ENDIF

    RTS

MSPRITEDATAFROM:
    TYA
    STA MATHPTR3
    LDA #$0
    STA MATHPTR4

    ASL MATHPTR3
    ROL MATHPTR4
    ASL MATHPTR3
    ROL MATHPTR4
    ASL MATHPTR3
    ROL MATHPTR4
    ASL MATHPTR3
    ROL MATHPTR4
    ASL MATHPTR3
    ROL MATHPTR4
    ASL MATHPTR3
    ROL MATHPTR4

    LDA MATHPTR3
    STA TMPPTR2
    LDA MATHPTR4
    STA TMPPTR2+1

    CLC
    LDA TMPPTR2
    ADC #$00
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #$80
    STA TMPPTR2+1

    LDA MATHPTR1
    STA TMPPTR
    LDA MATHPTR2
    STA TMPPTR+1

    TYA
    PHA
    LDY #0
MSPRITEDATAL1:
    LDA (TMPPTR), Y
    STA (TMPPTR2), Y
    INY
    CPY #63
    BNE MSPRITEDATAL1
    LDA (TMPPTR), Y
    TAX

    PLA
    PHA
    TAY   

    CLC
    LDA #<SPRC
    STA TMPPTR2
    LDA #>SPRC
    STA TMPPTR2+1
    TXA
    STA (TMPPTR2),Y
    LDA #<SPRF
    STA TMPPTR
    LDA #>SPRF
    STA TMPPTR+1

    PLA
    STA (TMPPTR), Y

@IF ! multiplexingSpriteConfig.async
    LDA #1
    STA SPRUPDATEFLAG
MSPRITEDATAL1W2:
    LDA SPRUPDATEFLAG
    BNE MSPRITEDATAL1W2
@ENDIF

    RTS

; //                   +---+------------- width in sprites (00 = 1, 01 = 2, 10 = 3, 11 = 4)
; //                   |   |   +---+----- height in sprites (00 = 1, 01 = 2, 10 = 3, 11 = 4)
; //                   |   |   |   |
; // +---+---+---+---+---+---+---+---+ +---+---+---+---+---+---+---+---+
; // | M | c | c | c | x | x | y | y | | n | n | n | n | n | n | n | n |
; // +---+---+---+---+---+---+---+---+ +---+---+---+---+---+---+---+---+
; // +-+---+---+---------------------+ +-------------------------------+
; //   |   |   |   | (VT_MSPRITE+1)                    (VT_MSPRITE+0)
; //   |   |   |   |
; //   |   +---+---+-- number of colors
; //   +-------------- multicolor (0 = no / 1 = yes)    

; DECODE: X -> MATHPTR3(c), MATHPTR4(y), MATHPTR5(x), MATHPTR6(y*x*c), MATHPTR7(w)
MSPRITEDECODEX:
    TYA
    PHA
    TXA
    AND #$70
    LSR
    LSR
    LSR
    LSR
    ADC #1
    STA MATHPTR3
    TXA
    AND #$80
    BEQ MSPRITEDECODEXN1
    LDA #12
    STA MATHPTR7
    JMP MSPRITEDECODEXND
MSPRITEDECODEXN1:
    LDA #24
    STA MATHPTR7
MSPRITEDECODEXND:
    TXA
    AND #$03
    ADC #1
    STA MATHPTR6
    STA MATHPTR4
    TXA
    AND #$0C
    LSR
    LSR
    ADC #1
    STA MATHPTR5
    TAY
    LDA #0
MSPRITEDECODEXL1:
    ADC MATHPTR6
    DEY
    BNE MSPRITEDECODEXL1
    STA MATHPTR6
    LDY MATHPTR3
    LDA #0
MSPRITEDECODEXL2:
    ADC MATHPTR6
    DEY
    BNE MSPRITEDECODEXL2
    STA MATHPTR6
MSPRITEDECODEDONE:
    PLA
    TAY
    RTS

MSPRITEENABLE:
    LDA #<SPROY
    STA TMPPTR
    LDA #>SPROY
    STA TMPPTR+1
    LDA #<SPRY
    STA TMPPTR2
    LDA #>SPRY
    STA TMPPTR2+1    
    JSR MSPRITEDECODEX
MSPRITEENABLEL00:
MSPRITEENABLEL10:
    LDX MATHPTR6
MSPRITEENABLEL1:
    LDA (TMPPTR), Y
    STA (TMPPTR2), Y
    INY
    DEX
    BNE MSPRITEENABLEL1

@IF ! multiplexingSpriteConfig.async
    LDA #1
    STA SPRUPDATEFLAG
MSPRITEENABLEL1BW2:   
    LDA SPRUPDATEFLAG
    BNE MSPRITEENABLEL1BW2
@ENDIF

    RTS

MSPRITEDISABLE:
    LDA #<SPRY
    STA TMPPTR
    LDA #>SPRY
    STA TMPPTR+1
    LDA #<SPROY
    STA TMPPTR2
    LDA #>SPROY
    STA TMPPTR2+1    
    JSR MSPRITEDECODEX
    LDA MATHPTR4
    STA MSPRITETEMP
MSPRITEDISABLEL00:
MSPRITEDISABLEL10:
    LDX MATHPTR6
MSPRITEDISABLEL1:
    LDA (TMPPTR), Y
    STA (TMPPTR2), Y
    LDA #$FF
    STA (TMPPTR), Y
    INY
    DEX
    BNE MSPRITEDISABLEL1

@IF ! multiplexingSpriteConfig.async
    LDA #1
    STA SPRUPDATEFLAG
MSPRITEDISABLEL1BW2:
    LDA SPRUPDATEFLAG
    BNE MSPRITEDISABLEL1BW2
@ENDIF

    RTS

MSPRITETEMP: .BYTE 0

MSPRITEAT:
    LDA #<SPRX
    STA TMPPTR
    LDA #>SPRX
    STA TMPPTR+1
    LDA #<SPRY
    STA TMPPTR2
    LDA #>SPRY
    STA TMPPTR2+1
    LDA #<SPROY
    STA COPYOFTEXTADDRESS
    LDA #>SPROY
    STA COPYOFTEXTADDRESS+1
    LDA #<SPRE
    STA COPYOFCOLORMAPADDRESS
    LDA #>SPRE
    STA COPYOFCOLORMAPADDRESS+1
    
    JSR MSPRITEDECODEX
    LDA MATHPTR4
    STA MATHPTR1
    LDA MATHPTR2
    STA MSPRITETEMP
    LDA MATHPTR0
    PHA

MSPRITEATL00:

MSPRITEATL10:
    LDX MATHPTR5
MSPRITEATL1:
    LDA MATHPTR0
    STA (TMPPTR), Y
    LDA MATHPTR2
    STA (TMPPTR2), Y
    STA (COPYOFTEXTADDRESS), Y

    INY
    DEX
    BEQ MSPRITEATL1B

    LDA (COPYOFCOLORMAPADDRESS), Y
    AND #$1
    BEQ MSPRITEATXDNO

    CLC
    LDA MATHPTR0
    ADC #24
    STA MATHPTR0

    JMP MSPRITEATXD

MSPRITEATXDNO:

    CLC
    LDA MATHPTR0
    ADC #12
    STA MATHPTR0

MSPRITEATXD:

    JMP MSPRITEATL1

MSPRITEATL1B:
    PLA
    STA MATHPTR0
    PHA

    LDA (COPYOFCOLORMAPADDRESS), Y
    AND #$2
    BEQ MSPRITEATYDNO

    CLC
    LDA #42
    ADC MATHPTR2
    STA MATHPTR2
    JMP MSPRITEATYD

MSPRITEATYDNO:

    CLC
    LDA #21
    ADC MATHPTR2
    STA MATHPTR2

MSPRITEATYD:

    LDX MATHPTR5

    SEC
    LDA MATHPTR4
    SBC #1
    STA MATHPTR4
    BNE MSPRITEATL10

    LDA MATHPTR1
    STA MATHPTR4

    LDA MSPRITETEMP
    STA MATHPTR2

    SEC
    LDA MATHPTR3
    SBC #1
    STA MATHPTR3
    BNE MSPRITEATL00

    PLA

@IF ! multiplexingSpriteConfig.async
    LDA #1
    STA SPRUPDATEFLAG
MSPRITEATL1BW2:
    LDA SPRUPDATEFLAG
    BNE MSPRITEATL1BW2
@ENDIF

    RTS

MSPRITESETRESET:
    PHA
    LDA #<SPRE
    STA TMPPTR
    LDA #>SPRE
    STA TMPPTR+1
    PLA
    JSR MSPRITEDECODEX
    LDX MATHPTR6
MSPRITESETRESETL1:
    LDA (TMPPTR), Y
MSPRITESETRESETOP:
    ORA #1
    STA (TMPPTR), Y
    INY
    DEX
    BNE MSPRITESETRESETL1

@IF ! multiplexingSpriteConfig.async

    LDA #1
    STA SPRUPDATEFLAG
MSPRITESETRESETL1W2:
    LDA SPRUPDATEFLAG
    BNE MSPRITESETRESETL1W2

@ENDIF

    RTS

MSPRITEPRIORITY:
    RTS

MSPRITEEXPANDX:
    LDA #$09
    STA MSPRITESETRESETOP
    LDA #$01
    STA MSPRITESETRESETOP+1
    JSR MSPRITESETRESET
    RTS

MSPRITEEXPANDY:
    LDA #$09
    STA MSPRITESETRESETOP
    LDA #$02
    STA MSPRITESETRESETOP+1
    JSR MSPRITESETRESET
    RTS

MSPRITECOMPRESSX:
    LDA #$29
    STA MSPRITESETRESETOP
    LDA #$FE
    STA MSPRITESETRESETOP+1
    JSR MSPRITESETRESET
    RTS

MSPRITECOMPRESSY:
    LDA #$29
    STA MSPRITESETRESETOP
    LDA #$FD
    STA MSPRITESETRESETOP+1
    JSR MSPRITESETRESET
    RTS

MSPRITECOLOR:
    PHA
    LDA #<SPRC
    STA TMPPTR
    LDA #>SPRC
    STA TMPPTR+1
    PLA
    JSR MSPRITEDECODEX
    LDX MATHPTR6
MSPRITECOLORL1:
    STA (TMPPTR), Y
    INY
    DEX
    BNE MSPRITECOLORL1

@IF ! multiplexingSpriteConfig.async

    LDA #1
    STA SPRUPDATEFLAG
MSPRITECOLORL1W2:
    LDA SPRUPDATEFLAG
    BNE MSPRITECOLORL1W2

@ENDIF

    RTS

MSPRITECOL:
    RTS

MSPRITEMULTICOLOR:
    RTS

MSPRITEMONOCOLOR:
    RTS

MSPRITESUPDATE:

@IF multiplexingSpriteConfig.async
    LDA #1
    STA SPRUPDATEFLAG
MSPRITESUPDATEL1:
    LDA SPRUPDATEFLAG
    BNE MSPRITESUPDATEL1
@ENDIF

    RTS
