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
;*                          JOYSTICK DETECTION ON C64                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF joystickConfig.values

JOYSTICKTSBREMAP:

    .BYTE   $0, $1, $5, $0
    .BYTE   $7, $8, $6, $0
    .BYTE   $3, $2, $4, $0
    .BYTE   $0, $0, $0, $0

@ENDIF

JOYSTICKMANAGER:
    
    PHP
    PHA
    TXA
    PHA
    TYA
    PHA

    LDA #$7F
    STA $DC00
    LDA $DC01
    AND #$1F
    EOR #$1F

@IF joystickConfig.values
    PHA
    AND #$0F
    TAY
    LDA JOYSTICKTSBREMAP, Y
    TAX
    PLA
    AND #$10
    BEQ JOYSTICKNOFIRE0
    TXA
    ORA #$80
    TAX
JOYSTICKNOFIRE0:
    TXA
@ENDIF

    STA JOYSTICK0

    LDA #$E0
    LDY #$FF
    STA $DC02
    LDA $DC00
    STY $DC02
    AND #$1F
    EOR #$1F

@IF joystickConfig.values
    PHA
    AND #$0F
    TAY
    LDA JOYSTICKTSBREMAP, Y
    TAX
    PLA
    AND #$10
    BEQ JOYSTICKNOFIRE1
    TXA
    ORA #$80
    TAX
JOYSTICKNOFIRE1:
    TXA
@ENDIF

    STA JOYSTICK1

    PLA
    TAY
    PLA
    TAX
    PLA
    PLP

    RTS

WAITFIRE:
    LDA JOYSTICK0
    AND #$10
    STA MATHPTR0
    LDA JOYSTICK1
    AND #$10
    ORA MATHPTR0
    BEQ WAITFIRE
    RTS
    