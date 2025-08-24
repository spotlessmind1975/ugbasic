; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                      STARTUP ROUTINE FOR PC IBM WITH CGA                    *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PCCGATIMER:     dw  $0000

TIMERISVC:
@IF deployed.timer
    CALL TIMERMANAGER
@ENDIF
    PUSH DX
    MOV DX, [PCCGATIMER]
    INC DX
    MOV [PCCGATIMER], DX
    POP DX
    IRET

@IF deployed.keyboard && !keyboardConfig.sync

KEYBOARDIRQSAVED:   dw 0, 0

@ENDIF

PCCGASTARTUP:
    MOV AX, 50
    MOV [TICKSPERSECOND], AX

@IF deployed.fp

    FINIT
    WAIT

@ENDIF

    CLI 

    PUSH DS
    MOV DX, 0
    MOV DS, DX
    MOV WORD [0x1C * 4], TIMERISVC 
    MOV DX, CS
    MOV WORD [0x1C * 4 + 2], DX
    POP DS

@IF deployed.keyboard

@IF !keyboardConfig.sync

    PUSH DS
    MOV DX, 0
    MOV DS, DX
    MOV DX, WORD [9*4]
    MOV CX, WORD [9*4+2]
    POP DS
    MOV WORD [KEYBOARDIRQSAVED], DX
    MOV WORD [KEYBOARDIRQSAVED+2], CX
    PUSH DS
    MOV DX, 0
    MOV DS, DX
    MOV DX, KEYBOARDMANAGER
    MOV WORD [9*4], DX
    MOV DX, CS
    MOV WORD [9*4+2], DX
    POP DS

@ELSE

    CLI
    MOV AL, 2
    OUT 0x21, AL
    STI

@ENDIF

@ENDIF

    STI

    RET