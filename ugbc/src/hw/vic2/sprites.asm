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

    TAY
    PHA
    LDY #0
SPRITEDATAL1:
    LDA (TMPPTR), Y
    STA (TMPPTR2), Y
    INY
    CPY #64
    BNE SPRITEDATAL1

    LDA TEXTADDRESS
    STA TMPPTR
    LDA TEXTADDRESS+1
    STA TMPPTR+1

    CLC
    LDA TMPPTR
    ADC #$F8
    STA TMPPTR
    LDA TMPPTR+1
    ADC #$03
    STA TMPPTR+1

    PLA
    ASL

    CLC
    ADC TMPPTR
    STA TMPPTR
    LDA #$00
    ADC TMPPTR+1
    STA TMPPTR+1

    TAY
    LDA MATHPTR3
    STA (TMPPTR), Y
    INY
    LDA MATHPTR4
    STA (TMPPTR), Y
    RTS

; SET SPRITE DISABLE(Y)
SPRITEDISABLE:
    LDA #<BITMASKN
    STA TMPPTR
    LDA #>BITMASKN
    STA TMPPTR+1
    LDA $D015
    AND (TMPPTR),Y
    STA $D015
    RTS

; SET SPRITE ENABLE(Y)
SPRITEENABLE:
    LDA #<BITMASK
    STA TMPPTR
    LDA #>BITMASK
    STA TMPPTR+1
    LDA $D015
    ORA (TMPPTR),Y
    STA $D015
    RTS

; SPRITE AT(Y,MATHPTR0:1,X)
SPRITEAT:
    LDA #$00
    STA TMPPTR2
    LDA #$D0
    STA TMPPTR2+1
    LDA MATHPTR0
    STA (TMPPTR2),Y
    INY
    TXA
    STA (TMPPTR2),Y
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

; SPRITE EXPAND(Y)
SPRITEEXPAND:
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

; SPRITE COMPRESS(Y)
SPRITECOMPRESS:
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

; SPRITE COLOR(Y,A)
SPRITECOLOR:
    TAX
    CLC
    LDA #$27
    STA TMPPTR2
    LDA #$D0
    STA TMPPTR2+1
    TXA
    STA (TMPPTR2),Y
    RTS

