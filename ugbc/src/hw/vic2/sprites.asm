; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                              SPRITES FOR VIC-II                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SET SPRITE DATA(Y,MATHPTR1:2)
SPRITEDATAFROM:
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
SPRITEDATAL1:
    LDA (TMPPTR), Y
    STA (TMPPTR2), Y
    INY
    CPY #63
    BNE SPRITEDATAL1
    LDA (TMPPTR), Y
    TAX

    PLA
    PHA
    TAY

    CLC
    LDA #$27
    STA TMPPTR2
    LDA #$D0
    STA TMPPTR2+1
    TXA
    STA (TMPPTR2),Y

    LDA #$00
    STA TMPPTR
    LDA #$84
    STA TMPPTR+1

    CLC
    LDA TMPPTR
    ADC #$F8
    STA TMPPTR
    LDA TMPPTR+1
    ADC #$03
    STA TMPPTR+1

    PLA
    STA (TMPPTR), Y
    PHA

    LDA #$00
    STA TMPPTR
    LDA #$88
    STA TMPPTR+1

    CLC
    LDA TMPPTR
    ADC #$F8
    STA TMPPTR
    LDA TMPPTR+1
    ADC #$03
    STA TMPPTR+1

    PLA
    STA (TMPPTR), Y

    RTS

; SET SPRITE DISABLE(Y)
SPRITEDISABLE:
    TYA
    AND #$F0
    BEQ SPRITEDISABLESINGLE
    JMP SPRITEDISABLEMULTIPLE
SPRITEDISABLESINGLE:
    LDA #<BITMASKN
    STA TMPPTR
    LDA #>BITMASKN
    STA TMPPTR+1
    LDA $D015
    AND (TMPPTR),Y
    STA $D015
    RTS
SPRITEDISABLEMULTIPLE:
    JSR SPRITEDECODEY
    LDY MATHPTR4
SPRITEDISABLEMULTIPLEL1:
    JSR SPRITEDISABLESINGLE
    INY
    CPY MATHPTR5
    BNE SPRITEDISABLEMULTIPLEL1
    RTS
    

; SET SPRITE ENABLE(Y)
SPRITEENABLE:
    TYA
    AND #$F0
    BEQ SPRITEENABLESINGLE
    JMP SPRITEENABLEMULTIPLE
SPRITEENABLESINGLE:
    LDA #<BITMASK
    STA TMPPTR
    LDA #>BITMASK
    STA TMPPTR+1
    LDA $D015
    ORA (TMPPTR),Y
    STA $D015
    RTS
SPRITEENABLEMULTIPLE:
    JSR SPRITEDECODEY
    LDY MATHPTR4
SPRITEENABLEMULTIPLEL1:
    JSR SPRITEENABLESINGLE
    INY
    CPY MATHPTR5
    BNE SPRITEENABLEMULTIPLEL1
    RTS

; SPRITE AT(Y,MATHPTR0:1,X)
SPRITEAT:
    TYA
    AND #$F0
    BEQ SPRITEATSINGLE
    JMP SPRITEATMULTIPLE
SPRITEATSINGLE:
    TYA
    ASL
    TAY
    LDA #$00
    STA TMPPTR2
    LDA #$D0
    STA TMPPTR2+1
    LDA MATHPTR0
    STA (TMPPTR2),Y
    INY
    TXA
    STA (TMPPTR2),Y
    DEY
    TYA
    LSR
    TAY
    LDA MATHPTR1
    BEQ SPRITEATX0
SPRITEATX1:
    LDA #<BITMASK
    STA TMPPTR
    LDA #>BITMASK
    STA TMPPTR+1
    LDA $D010
    ORA (TMPPTR),Y
    STA $D010
    RTS
SPRITEATX0:
    LDA #<BITMASKN
    STA TMPPTR
    LDA #>BITMASKN
    STA TMPPTR+1
    LDA $D010
    AND (TMPPTR),Y
    STA $D010
    RTS
SPRITEATMULTIPLE:
    JSR SPRITEDECODEY
SPRITEATMULTIPLEL1:
    LDY MATHPTR4
    JSR SPRITEATSINGLE
    INC MATHPTR4
    LDY MATHPTR4
    CPY MATHPTR5
    BNE SPRITEATMULTIPLEL1
    RTS

; SPRITE EXPAND(Y)
SPRITEEXPAND:
    TYA
    AND #$F0
    BEQ SPRITEEXPANDSINGLE
    JMP SPRITEEXPANDMULTIPLE
SPRITEEXPANDSINGLE:
    LDA #<BITMASK
    STA TMPPTR
    LDA #>BITMASK
    STA TMPPTR+1
    LDA $D01D
    ORA (TMPPTR),Y
    STA $D01D
    LDA $D017
    ORA (TMPPTR),Y
    STA $D017
    RTS
SPRITEEXPANDMULTIPLE:
    JSR SPRITEDECODEY
    LDY MATHPTR4
SPRITEEXPANDMULTIPLEL1:
    JSR SPRITEEXPANDSINGLE
    INY
    CPY MATHPTR5
    BNE SPRITEEXPANDMULTIPLEL1
    RTS

; SPRITE COMPRESS(Y)
SPRITECOMPRESS:
    TYA
    AND #$F0
    BEQ SPRITECOMPRESSSINGLE
    JMP SPRITECOMPRESSMULTIPLE
SPRITECOMPRESSSINGLE:
    LDA #<BITMASKN
    STA TMPPTR
    LDA #>BITMASKN
    STA TMPPTR+1
    LDA $D01D
    AND (TMPPTR),Y
    STA $D01D
    LDA $D017
    AND (TMPPTR),Y
    STA $D017
    RTS
SPRITECOMPRESSMULTIPLE:
    JSR SPRITEDECODEY
    LDY MATHPTR4
SPRITECOMPRESSMULTIPLEL1:
    JSR SPRITECOMPRESSSINGLE
    INY
    CPY MATHPTR5
    BNE SPRITECOMPRESSMULTIPLEL1
    RTS

; SPRITE COLOR(Y,A)
SPRITECOLOR:
    TAX
    TYA
    AND #$F0
    BEQ SPRITECOLORSINGLE
    JMP SPRITECOLORMULTIPLE
SPRITECOLORSINGLE:
    CLC
    LDA #$27
    STA TMPPTR2
    LDA #$D0
    STA TMPPTR2+1
    TXA
    STA (TMPPTR2),Y
    RTS
SPRITECOLORMULTIPLE:
    JSR SPRITEDECODEY
    LDY MATHPTR4
SPRITECOLORMULTIPLEL1:
    JSR SPRITECOLORSINGLE
    INY
    CPY MATHPTR5
    BNE SPRITECOLORMULTIPLEL1
    RTS

SPRITECOL:
    LDA $D01E
    BNE SPRITECOL2
    RTS
SPRITECOL2:
    PHA
    LDA MATHPTR3
    AND #$0F
    BEQ SPRITECOLSINGLE
    LDY MATHPTR3
    JSR SPRITEDECODEY
    LDA MATHPTR1
    STA MATHPTR3
    LDA MATHPTR2
    STA MATHPTR6
    JMP SPRITECOL3
SPRITECOLSINGLE:
    LDA MATHPTR3
    STA MATHPTR6
    JMP SPRITECOL3
SPRITECOL3:
    LDY MATHPTR3
    LDA #<BITMASK
    STA TMPPTR
    LDA #>BITMASK
    STA TMPPTR+1
    LDA (TMPPTR),Y
    LDY MATHPTR3
    CPY MATHPTR6
    BNE SPRITECOL3L1
    JMP SPRITECOL4
SPRITECOL3L1:
    INY
    ORA (TMPPTR),Y
    CPY MATHPTR6
    BNE SPRITECOL3L1
SPRITECOL4:
    STA MATHPTR0
    PLA
    AND MATHPTR0
    LDX #$0
    STX $D01E
    RTS

; SPRITE MULTICOLOR(Y)
SPRITEMULTICOLOR:
    TYA
    AND #$F0
    BEQ SPRITEMULTICOLORSINGLE
    JMP SPRITEMULTICOLORMULTIPLE
SPRITEMULTICOLORSINGLE:
    LDA #<BITMASK
    STA TMPPTR
    LDA #>BITMASK
    STA TMPPTR+1
    LDA $D01C
    ORA (TMPPTR),Y
    STA $D01C
    RTS
SPRITEMULTICOLORMULTIPLE:
    JSR SPRITEDECODEY
    LDY MATHPTR4
SPRITEMULTICOLORL1:
    JSR SPRITEMULTICOLORSINGLE
    INY
    CPY MATHPTR5
    BNE SPRITEMULTICOLORL1
    RTS

; SPRITE MONOCOLOR(Y)
SPRITEMONOCOLOR:
    TYA
    AND #$F0
    BEQ SPRITEMONOCOLORSINGLE
    JMP SPRITEMONOCOLORMULTIPLE
SPRITEMONOCOLORSINGLE:
    LDA #<BITMASKN
    STA TMPPTR
    LDA #>BITMASKN
    STA TMPPTR+1
    LDA $D01C
    AND (TMPPTR),Y
    STA $D01C
    RTS
SPRITEMONOCOLORMULTIPLE:
    JSR SPRITEDECODEY
    LDY MATHPTR4
SPRITEMONOCOLORL1:
    JSR SPRITEMONOCOLORSINGLE
    INY
    CPY MATHPTR5
    BNE SPRITEMONOCOLORL1
    RTS

SPRITEDECODEY:
    TYA
    AND #$0F
    STA MATHPTR4
    TYA
    AND #$F0
    LSR
    LSR
    LSR
    LSR
    STA MATHPTR5    
    RTS