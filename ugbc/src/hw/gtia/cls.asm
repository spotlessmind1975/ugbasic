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
;*                      CLEAR SCREEN ROUTINE FOR GTIA                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLS:
    LDA CURRENTMODE
    CMP #9
    BNE CLSANTIC9X
    JMP CLSANTIC9
CLSANTIC9X:
    CMP #10
    BNE CLSANTIC10X
    JMP CLSANTIC10
CLSANTIC10X:
    CMP #11
    BNE CLSANTIC11X
    JMP CLSANTIC11
CLSANTIC11X:
    CMP #13
    BNE CLSANTIC13X
    JMP CLSANTIC13
CLSANTIC13X:
    CMP #15
    BNE CLSANTIC15X
    JMP CLSANTIC15
CLSANTIC15X:
    CMP #12
    BNE CLSANTIC12X
    JMP CLSANTIC12
CLSANTIC12X:
    CMP #14
    BNE CLSANTIC14X
    JMP CLSANTIC14
CLSANTIC14X:
    CMP #2
    BNE CLSANTIC2X
    JMP CLSANTIC2
CLSANTIC2X:
    CMP #6
    BNE CLSANTIC6X
    JMP CLSANTIC6
CLSANTIC6X:    
    CMP #7
    BNE CLSANTIC7X
    JMP CLSANTIC7
CLSANTIC7X:    
    CMP #3
    BNE CLSANTIC3X
    JMP CLSANTIC3
CLSANTIC3X:    
    CMP #4
    BNE CLSANTIC4X
    JMP CLSANTIC4
CLSANTIC4X:    
    CMP #5
    BNE CLSANTIC5X
    JMP CLSANTIC5
CLSANTIC5X:
    CMP #8
    BNE CLSANTIC8X
    JMP CLSANTIC8
CLSANTIC8X:
    RTS    

CLSANTIC8:
    LDA #0
    STA TMPPTR
    LDA #200
    STA TMPPTR+1
    JMP CLSG
CLSANTIC9:
    LDA #1
    STA TMPPTR
    LDA #224
    STA TMPPTR+1
    JMP CLSG
CLSANTIC10:
    LDA #3
    STA TMPPTR
    LDA #3
    STA TMPPTR+1
    JMP CLSG
CLSANTIC11:
    LDA #7
    STA TMPPTR
    LDA #128
    STA TMPPTR+1
    JMP CLSG
CLSANTIC13:
    LDA #15
    STA TMPPTR
    LDA #0
    STA TMPPTR+1
    JMP CLSG
CLSANTIC15:
CLSANTIC12:
CLSANTIC14:
    LDA #30
    STA TMPPTR
    LDA #0
    STA TMPPTR+1
    JMP CLSG

CLSG:
    LDA BITMAPADDRESS
    STA COPYOFBITMAPADDRESS
    LDA BITMAPADDRESS+1
    STA COPYOFBITMAPADDRESS+1
    LDX TMPPTR
    LDY #0
    LDA #$0
CLSGY:
    STA (COPYOFBITMAPADDRESS),Y
    INY
    BNE CLSGY
    INC COPYOFBITMAPADDRESS+1
    DEX
    BNE CLSGY
    LDX TMPPTR+1
CLSGY2:
    STA (COPYOFBITMAPADDRESS),Y
    INY
    DEX
    BNE CLSGY2

    RTS

CLSANTIC2:
CLSANTIC3:
    LDA #3
    STA TMPPTR
    LDA #192
    STA TMPPTR+1
    JMP CLST
CLSANTIC6:
CLSANTIC4:
CLSANTIC5:
    LDA #1
    STA TMPPTR
    LDA #224
    STA TMPPTR+1
    JMP CLSG
CLSANTIC7:
    LDA #0
    STA TMPPTR
    LDA #242
    STA TMPPTR+1
    JMP CLSG


CLST:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDX TMPPTR
    LDY #0
    LDA EMPTYTILE
    CPX #0
    JMP CLST2XA
CLST2:
    STA (COPYOFTEXTADDRESS),Y
    INY
    BNE CLST2
    INC COPYOFTEXTADDRESS+1
    CPX #1
    BNE CLSTNB
CLST2X:
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY TMPPTR+1
    BNE CLST2X
CLSTNB:
    DEX
    BNE CLST2

    RTS

CLST2XA:
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY TMPPTR+1
    BNE CLST2XA

    RTS
