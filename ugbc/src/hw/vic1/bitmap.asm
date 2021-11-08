; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                          BITMAP EMULATION   FOR VIC-I                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

BITMAPPREPARE:
    LDA TEXTADDRESS
    STA TMPPTR
    LDA TEXTADDRESS+1
    STA TMPPTR+1

    LDY #0
    LDA #255
BITMAPONL1:
    STA (TMPPTR),Y
    CLC
    ADC #1
    INY
    BNE BITMAPONL1

    INC TMPPTR+1
BITMAPONL2:
    STA (TMPPTR),Y
    CLC
    ADC #1
    INY
    CPY #250
    BNE BITMAPONL2

    RTS
    
BITMAPON1:

    LDA $9002
    AND #$80
    ORA #16
    STA $9002
    LDA $9003
    AND #$81
    ORA #32
    STA $9003

    LDA $9005
    AND #$F0
    ORA #$0E
    STA $9005

    LDA $9000
    ADC #6
    STA $9000
    LDA $9001
    ADC #16
    STA $9001

    JSR BITMAPPREPARE

    LDA TEXTADDRESS
    STA TMPPTR
    LDA TEXTADDRESS+1
    STA TMPPTR+1

    LDY #0
    LDA #0
BITMAPONL3:
    STA (TMPPTR),Y
    CLC
    ADC #1
    INY
    BNE BITMAPONL3
    RTS

BITMAPON2:

    LDA $9002
    AND #$80
    ORA #22
    STA $9002
    LDA $9003
    AND #$81
    ORA #44
    STA $9003

    ; LDA $9005
    ; AND #$F0
    ; ORA #$0D
    ; STA $9005

    ; LDA $9000
    ; ADC #6
    ; STA $9000
    ; LDA $9001
    ; ADC #16
    ; STA $9001

    ; JSR BITMAPPREPARE

    LDA TEXTADDRESS
    STA TMPPTR
    LDA TEXTADDRESS+1
    STA TMPPTR+1

    LDY #0
    LDA #0
BITMAPONL4:
    STA (TMPPTR),Y
    CLC
    ADC #1
    INY
    CPY #242
    BNE BITMAPONL4

    CLC
    LDA #242
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1

    LDY #0
    LDA #0
BITMAPONL5:
    STA (TMPPTR),Y
    CLC
    ADC #1
    INY
    CPY #242
    BNE BITMAPONL5

    RTS

BITMAPOFF:
    LDA $9002
    AND #$80
    ORA #22
    STA $9002
    LDA $9003
    ORA #23
    STA $9003

    LDA $9005
    AND #$F0
    ORA #$0F
    STA $9005

    SEC
    LDA $9000
    SBC #6
    STA $9000
    SEC
    LDA $9001
    SBC #16
    STA $9001

    LDA $9003
    AND #$FE
    STA $9003
    RTS
