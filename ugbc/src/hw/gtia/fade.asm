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
;*                           FADE ROUTINE FOR GTIA                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

FADESTEP:   .BYTE 15
FADEDURATION: .WORD 0
FADERESETDURATION: .WORD 0

FADET:
    PHA
    TXA
    PHA
    TYA
    PHA

    LDA FADESTEP
    CMP #15
    BNE FADET2
    JMP FADETDONE

FADET2:

    LDA #0
    STA PALETTEPRESERVEUSED
    
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
    LDA $02C4
    AND #$0F
    BEQ DONE02C4
    STA MATHPTR1
    DEC MATHPTR1
    LDA $02C4
    AND #$F0
    ORA MATHPTR1
    STA $02C4
    JMP DONE02C4B
DONE02C4:
    LDA #0
    STA $02C4
DONE02C4B:

    LDA $02C5
    AND #$0F
    BEQ DONE02C5
    STA MATHPTR1
    DEC MATHPTR1
    LDA $02C5
    AND #$F0
    ORA MATHPTR1
    STA $02C5
    JMP DONE02C5B
DONE02C5:
    LDA #0
    STA $02C5
DONE02C5B:

    LDA $02C6
    AND #$0F
    BEQ DONE02C6
    STA MATHPTR1
    DEC MATHPTR1
    LDA $02C6
    AND #$F0
    ORA MATHPTR1
    STA $02C6
    JMP DONE02C6B
DONE02C6:
    LDA #0
    STA $02C6
DONE02C6B:

    LDA $02C7
    AND #$0F
    BEQ DONE02C7
    STA MATHPTR1
    DEC MATHPTR1
    LDA $02C7
    AND #$F0
    ORA MATHPTR1
    STA $02C7
    JMP DONE02C7B
DONE02C7:
    LDA #0
    STA $02C7
DONE02C7B:

    LDA $02C8
    AND #$0F
    BEQ DONE02C8
    STA MATHPTR1
    DEC MATHPTR1
    LDA $02C8
    AND #$F0
    ORA MATHPTR1
    STA $02C8
    JMP DONE02C8B
DONE02C8:
    LDA #0
    STA $02C8
DONE02C8B:

FADET5:

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

    