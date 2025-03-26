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
;*                            8BITx8BIT = 16BIT UNDER SM83                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; IX x IY -> BC:HL
CPUMUL16B16T32S:
    LD A, (IXR+1)
    AND $80
    LD B, A
    LD A, (IYR+1)
    AND $80
    XOR A, B
    PUSH AF

    LD A, (IXR+1)
    AND $80
    CP 0
    JR Z, CPUMUL16B16T32SPOS 

    LD A, (IXR)
    XOR $FF
    LD (IXR), A
    
    LD A, (IXR+1)
    XOR $FF
    LD (IXR+1), A

    LD HL, (IXR)
    INC HL
    LD (IXR), HL
    LD A, L
    CP 0
    JR NZ,CPUMUL16B16T32SPOS
    LD (IXR+1), A
    INC A
    LD A, (IXR+1)

CPUMUL16B16T32SPOS:
    LD A, (IYR+1)
    AND $80
    CP 0
    JR Z, CPUMUL16B16T32SPOS2

    LD A, (IYR)
    XOR $FF
    LD (IYR), A
    
    LD A, (IYR+1)
    XOR $FF
    LD (IYR+1), A

    LD HL, (IYR)
    INC HL
    LD (IYR), HL

CPUMUL16B16T32SPOS2:
    LD A, (IXR+1)
    LD B, A
    LD A, (IXR)
    LD C, A
    LD A, (IYR+1)
    LD D, A
    LD A, (IYR)
    LD E, A
    LD A, C
    LD C, B
    LD HL, 0
    LD B, 16
CPUMUL16B16T32SL:
    ADD HL, HL
    RLA
    RL C
    JR NC, CPUMUL16B16T32SB2
    ADD HL, DE
    ADC A, 0
    JP NC, CPUMUL16B16T32SB2
    INC C
CPUMUL16B16T32SB2:            
    DJNZ CPUMUL16B16T32SL
    LD B, C
    LD C, A

    POP AF
    JR Z, CPUMUL16B16T32SREPOS

    LD A, B
    XOR $FF
    LD B, A

    LD A, C
    XOR $FF
    LD C, A

    LD A, H
    XOR $FF
    LD H, A

    LD A, L
    XOR $FF
    LD L, A
    
    INC HL
    LD A, H
    OR L
    CP 0
    JR NC, CPUMUL16B16T32SREPOS
    INC BC

CPUMUL16B16T32SREPOS:
    RET

; BC x DE -> BC:HL
CPUMUL16B16T32U:
    LD A, C
    LD C, B
    LD HL, 0
    LD B, 16
CPUMUL16B16T32UL:
    ADD HL, HL
    RLA
    RL C
    JR NC, CPUMUL16B16T32ULB2
    ADD HL, DE
    ADC A, 0
    JP NC, CPUMUL16B16T32ULB2
    INC C
CPUMUL16B16T32ULB2:
    DJNZ CPUMUL16B16T32UL
    LD B, C
    LD C, A
    RET