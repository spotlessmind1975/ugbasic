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
;*                           FADE ROUTINE FOR VIC-II                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

FADETOBLACKCOLORS:
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00
    .BYTE $0d, $03, $0c, $04, $02, $09, $00, $00
    .BYTE $09, $00, $00, $00, $00, $00, $00, $00
    .BYTE $0c, $04, $02, $09, $00, $00, $00, $00
    .BYTE $02, $09, $00, $00, $00, $00, $00, $00
    .BYTE $08, $02, $09, $00, $00, $00, $00, $00
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00
    .BYTE $0f, $05, $08, $02, $09, $00, $00, $00
    .BYTE $02, $09, $00, $00, $00, $00, $00, $00
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00
    .BYTE $08, $02, $09, $00, $00, $00, $00, $00
    .BYTE $09, $00, $00, $00, $00, $00, $00, $00
    .BYTE $04, $02, $09, $00, $00, $00, $00, $00
    .BYTE $03, $0c, $04, $02, $09, $00, $00, $00
    .BYTE $04, $02, $09, $00, $00, $00, $00, $00
    .BYTE $05, $08, $02, $09, $00, $00, $00, $00

FADESTEP:   .BYTE 7
FADEOFFS:   .BYTE 0
FADEDURATION: .WORD 0
FADERESETDURATION: .WORD 0

FADET:
    PHA
    TXA
    PHA
    TYA
    PHA

    LDA FADESTEP
    CMP #7
    BNE FADET2
    JMP FADETDONE

FADET2:
    DEC FADEDURATION
    LDA FADEDURATION
    CMP #$FF
    BEQ FADET3
    JMP FADETDONE

FADET3:
    DEC FADEDURATION+1
    LDA FADEDURATION+1
    CMP #$FF
    BEQ FADET4
    JMP FADETDONE

FADET4:
    LDA COLORMAPADDRESS+1
    STA FADETL1ADDR1+2
    STA FADETL1ADDR2+2

@IF ( currentMode == 2 ) || ( currentMode == 3 )
    STA FADETL1ADDR1B+2
    STA FADETL1ADDR2B+2
@ENDIF

    CLC
    ADC #3
    STA FADETL2ADDR1+2
    STA FADETL2ADDR2+2

@IF ( currentMode == 2 ) || ( currentMode == 3 )
    STA FADETL2ADDR1B+2
    STA FADETL2ADDR2B+2
@ENDIF

    LDX #0
    STX FADEOFFS

    LDY #3

FADETL1:
    LDX FADEOFFS

FADETL1ADDR1:
    LDA $D800,X
    PHA
    AND #$0F
    ASL
    ASL
    ASL
    CLC
    ADC FADESTEP
    TAX
    LDA FADETOBLACKCOLORS, X
    LDX FADEOFFS
FADETL1ADDR2:
    STA $D800,X
    PLA

@IF ( currentMode == 2 ) || ( currentMode == 3 )

    AND #$F0
    LSR
    CLC
    ADC FADESTEP
    TAX
    LDA FADETOBLACKCOLORS, X
    LDX FADEOFFS
    ASL
    ASL
    ASL
    ASL
FADETL1ADDR1B:
    ORA $D800,X
FADETL1ADDR2B:
    STA $D800,X

@ENDIF

    INC FADEOFFS
    BNE FADETL1 
    INC FADETL1ADDR1+2
    INC FADETL1ADDR2+2
@IF ( currentMode == 2 ) || ( currentMode == 3 )
    INC FADETL1ADDR1B+2
    INC FADETL1ADDR2B+2
@ENDIF
    DEY
    BNE FADETL1

    LDX #0
    STX FADEOFFS

FADETL2:
    LDX FADEOFFS
FADETL2ADDR1:
    LDA $DB00,X
    PHA
    AND #$0F
    ASL
    ASL
    ASL
    CLC
    ADC FADESTEP
    TAX
    LDA FADETOBLACKCOLORS, X
    LDX FADEOFFS
FADETL2ADDR2:
    STA $DB00,X
    PLA

@IF ( currentMode == 2 ) || ( currentMode == 3 )

    AND #$F0
    LSR
    CLC
    ADC FADESTEP
    TAX
    LDA FADETOBLACKCOLORS, X
    LDX FADEOFFS
    ASL
    ASL
    ASL
    ASL
FADETL2ADDR1B:
    ORA $D800,X
FADETL2ADDR2B:
    STA $D800,X

@ENDIF

    INC FADEOFFS
    CPX #232
    BNE FADETL2 

    LDA FADERESETDURATION
    STA FADEDURATION
    LDA FADERESETDURATION+1
    STA FADEDURATION+1
    INC FADESTEP
    
FADETDONE:

    PLA
    TAY
    PLA
    TAX
    PLA
    RTS

    