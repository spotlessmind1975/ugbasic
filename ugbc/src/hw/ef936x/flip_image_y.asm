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
;*                          FLIP X ROUTINE FOR EF936X                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Flip image
; ----------------------------------------------------------------------------

FLIPIMAGEY

@IF vestigialConfig.screenModeUnique

@ELSE

    LDA CURRENTMODE
    CMPA #0
    BNE FLIPIMAGEY0X
    JMP FLIPIMAGEY0
FLIPIMAGEY0X
    CMPA #1
    BNE FLIPIMAGEY1X
    JMP FLIPIMAGEY1
FLIPIMAGEY1X
    CMPA #2
    BNE FLIPIMAGEY2X
    JMP FLIPIMAGEY2
FLIPIMAGEY2X
    CMPA #3
    BNE FLIPIMAGEY3X
    JMP FLIPIMAGEY3
FLIPIMAGEY3X
    CMPA #4
    BNE FLIPIMAGEY4X
    JMP FLIPIMAGEY4
FLIPIMAGEY4X
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) )

FLIPIMAGEY1
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 4 ) )

FLIPIMAGEY4
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 2 ) )

FLIPIMAGEY0
FLIPIMAGEY2

    ORCC #$50
    
    ; Retrieve the width (in bytes) and the height 
    ; (in bytes) of the image to flip horizontally.

    LDD , Y
    STD <IMAGEW
    LSR <IMAGEW
    ROR <IMAGEW+1
    LSR <IMAGEW
    ROR <IMAGEW+1
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    ; Move the image pointer ahead of header.

    LEAY 3, Y

    ; This is the beginning of the line flip loop.

FLIPIMAGEYCOMMONCL0

    ; Copy the starting line pointer to the ending line pointer.

    TFR Y, X

    LDA <(IMAGEW+1)
    LDB <IMAGEH
    MUL
    LSRA
    RORB
    LEAX D, X
    LDD <IMAGEW
    LSRA
    RORB
    COMA
    COMB
    ADDD #1
    LEAX D,X

    LSR <IMAGEH
    
FLIPIMAGEYCOMMONCL10
    LDD <IMAGEW
    LSRA
    RORB
    TFR D, U
FLIPIMAGEYCOMMONCL1
    LDA , X
    LDB , Y
    STA , Y+
    STB , X+
    
    LEAU -1, U

    CMPU #0
    BNE FLIPIMAGEYCOMMONCL1

    LDD <IMAGEW
    LSRA
    RORB
    COMA
    COMB
    ADDD #1
    LEAX D,X
    LEAX D,X

    LDA <IMAGEH
    DECA
    STA <IMAGEH
    BNE FLIPIMAGEYCOMMONCL10

    ; This is the beginning of the line flip loop.

    LDA <IMAGEH2
    STA <IMAGEH
    
FLIPIMAGEYCOMMONCL0X

    LDA <(IMAGEW+1)
    LDB <IMAGEH
    MUL
    LSRA
    RORB
    LSRA
    RORB
    LEAY D, Y

    ; Copy the starting line pointer to the ending line pointer.

    TFR Y, X

    LDA <(IMAGEW+1)
    LDB <IMAGEH
    MUL
    LSRA
    RORB
    LEAX D, X
    LDD <IMAGEW
    LSRA
    RORB
    COMA
    COMB
    ADDD #1
    LEAX D,X

    LSR <IMAGEH

FLIPIMAGEYCOMMONCL10X
    LDD <IMAGEW
    LSRA
    RORB
    TFR D, U
FLIPIMAGEYCOMMONCL1X
    LDA , X
    LDB , Y
    STA , Y+
    STB , X+
    
    LEAU -1, U

    CMPU #0
    BNE FLIPIMAGEYCOMMONCL1X

    LDD <IMAGEW
    LSRA
    RORB    
    COMA
    COMB
    ADDD #1
    LEAX D,X
    LEAX D,X

    LDA <IMAGEH
    DECA
    STA <IMAGEH
    BNE FLIPIMAGEYCOMMONCL10X

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

FLIPIMAGEY3

    ; Retrieve the width (in bytes) and the height 
    ; (in bytes) of the image to flip horizontally.

    LDD , Y
    STD <IMAGEW
    LSR <IMAGEW
    ROR <IMAGEW+1
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    ; Move the image pointer ahead of header.

    LEAY 3, Y

    ; This is the beginning of the line flip loop.

FLIPIMAGEY3COMMONCL0

    ; Copy the starting line pointer to the ending line pointer.

    TFR Y, X

    LDA <(IMAGEW+1)
    LDB <IMAGEH
    MUL
    LSRA
    RORB
    LEAX D, X
    LDD <IMAGEW
    LSRA
    RORB
    COMA
    COMB
    ADDD #1
    LEAX D,X

    LSR <IMAGEH
    
FLIPIMAGEY3COMMONCL10
    LDD <IMAGEW
    LSRA
    RORB
    TFR D, U
FLIPIMAGEY3COMMONCL1
    LDA , X
    LDB , Y
    STA , Y+
    STB , X+
    
    LEAU -1, U

    CMPU #0
    BNE FLIPIMAGEY3COMMONCL1

    LDD <IMAGEW
    LSRA
    RORB
    COMA
    COMB
    ADDD #1
    LEAX D,X
    LEAX D,X

    LDA <IMAGEH
    DECA
    STA <IMAGEH
    BNE FLIPIMAGEY3COMMONCL10

    ; This is the beginning of the line flip loop.

    LDA <IMAGEH2
    STA <IMAGEH
    
FLIPIMAGEY3COMMONCL0X

    LDA <(IMAGEW+1)
    LDB <IMAGEH
    MUL
    LSRA
    RORB
    LSRA
    RORB
    LEAY D, Y

    ; Copy the starting line pointer to the ending line pointer.

    TFR Y, X

    LDA <(IMAGEW+1)
    LDB <IMAGEH
    MUL
    LSRA
    RORB
    LEAX D, X
    LDD <IMAGEW
    LSRA
    RORB
    COMA
    COMB
    ADDD #1
    LEAX D,X

    LSR <IMAGEH

FLIPIMAGEY3COMMONCL10X
    LDD <IMAGEW
    LSRA
    RORB
    TFR D, U
FLIPIMAGEY3COMMONCL1X
    LDA , X
    LDB , Y
    STA , Y+
    STB , X+
    
    LEAU -1, U

    CMPU #0
    BNE FLIPIMAGEY3COMMONCL1X

    LDD <IMAGEW
    LSRA
    RORB    
    COMA
    COMB
    ADDD #1
    LEAX D,X
    LEAX D,X

    LDA <IMAGEH
    DECA
    STA <IMAGEH
    BNE FLIPIMAGEY3COMMONCL10X

    RTS

@ENDIF

