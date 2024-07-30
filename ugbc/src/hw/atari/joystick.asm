; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;*                          JOYSTICK HANDLER ON ATARI                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Read the joystick port.
;  X = port number
;  A = value read
JOYSTICK:
    CPX #0
    BEQ JOYSTICK0
    DEX
    BEQ JOYSTICK1
    DEX
    BEQ JOYSTICK2
    DEX
    BEQ JOYSTICK3
    RTS

JOYSTICK0:
    LDA $D300
    AND #$0F
    ASL
    STA MATHPTR0
    LDA $D010
    AND #$01
    ORA MATHPTR0
    STA MATHPTR0
    JMP JOYSTICKDONE

JOYSTICK1:
    LDA $D300
    AND #$F0
    LSR
    LSR
    LSR
    STA MATHPTR0
    LDA $D011
    AND #$01
    ORA MATHPTR0
    STA MATHPTR0
    JMP JOYSTICKDONE

JOYSTICK2:
    LDA $D301
    AND #$0F
    ASL
    STA MATHPTR0
    LDA $D012
    AND #$01
    ORA MATHPTR0
    STA MATHPTR0
    JMP JOYSTICKDONE

JOYSTICK3:
    LDA $D301
    AND #$F0
    LSR
    LSR
    LSR
    STA MATHPTR0
    LDA $D013
    AND #$01
    ORA MATHPTR0
    STA MATHPTR0
    JMP JOYSTICKDONE

JOYSTICKDONE:
    LDA MATHPTR0
    EOR #$ff
    AND #$1f

@IF joystickConfig.values

    JMP JOYSTICKDONE1

JOYSTICKTSBREMAP:
    .BYTE   $0, $1, $5, $0
    .BYTE   $7, $8, $6, $0
    .BYTE   $3, $2, $4, $0
    .BYTE   $0, $0, $0, $0

JOYSTICKDONE1:
    PHA
    ROR
    TAY
    LDA JOYSTICKTSBREMAP, Y
    TAX
    PLA
    ROR
    BCC JOYSTICKNOFIRE
    TXA
    ORA #$80
    TAX
JOYSTICKNOFIRE:
    TXA
@ENDIF

    RTS

