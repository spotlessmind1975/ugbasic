; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
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
;*                           STARTUP ROUTINE ON SIDZ                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SIDZTMPPTR2: defw $0000

SIDZMANAGER:
    PUSH AF
    LD A, (SIDZTIMER)
    CP 0
    JR Z, SIDZMANAGER0
    DEC A
    LD (SIDZTIMER), A
    CP 0
    JR NZ, SIDZMANAGER0
    CALL SIDZSTOP0
SIDZMANAGER0:
    LD A, (SIDZTIMER+1)
    CP 0
    JR Z, SIDZMANAGER1
    DEC A
    LD (SIDZTIMER+1), A
    CP 0
    JR NZ, SIDZMANAGER1
    CALL SIDZSTOP1
SIDZMANAGER1:
    LD A, (SIDZTIMER+2)
    CP 0
    JR Z, SIDZMANAGER2
    DEC A
    LD (SIDZTIMER+2), A
    CP 0
    JR NZ, SIDZMANAGER2
    CALL SIDZSTOP2
SIDZMANAGER2:
    POP AF
    RET

SIDZSTARTUP:
    LD A, $7
    LD C, $30
    CALL SIDZPROGCTR
    LD A, $7
    LD C, 1
    LD B, 1
    CALL SIDZPROGAD
    LD A, $7
    LD C, 2
    LD B, 6
    CALL SIDZPROGSR
    LD HL, SIDZFREQTABLE
    LD (SIDZTMPPTR2), HL
@IF deployed.music
    LD A, $0
    LD (SIDZTMPPTR), A
    LD (SIDZTMPPTR+1), A
    LD (SIDZJIFFIES), A
    LD (SIDZJIFFIES+1), A
@ENDIF
    LD C, $0f
    CALL SIDZSTARTVOL
    RET

SIDZSTART:
    SRL A
    JR NC, SIDZSTART0X
    CALL SIDZSTART0
SIDZSTART0X:
    SRL A
    JR NC, SIDZSTART1X
    CALL SIDZSTART1
SIDZSTART1X:
    SRL A
    JR NC, SIDZSTART2X
    CALL SIDZSTART2
SIDZSTART2X:
    RET

SIDZSTART0:
    PUSH AF
    LD A, (SIDZSHADOW)
    AND $F7
    OR $1
    LD (SIDZSHADOW), A
    LD ($D404), A
    POP AF
    RET

SIDZSTART1:
    PUSH AF
    LD A, (SIDZSHADOW+1)
    AND $F7
    OR $1
    LD (SIDZSHADOW+1), A
    LD ($D40B), A
    POP AF
    RET

SIDZSTART2:
    PUSH AF
    LD A, (SIDZSHADOW+2)
    AND $F7
    OR $1
    LD (SIDZSHADOW+2), A
    LD ($D412), A
    POP AF
    RET

SIDZSTARTVOL:
    PUSH AF
    LD A, C
    LD ($D418), A
    POP AF
    RET

SIDZFREQ:
    CALL SIDZCALCFREQ
    SRL A
    JR NC, SIDZFREQ0X
    CALL SIDZFREQ0T
SIDZFREQ0X:
    SRL A
    JR NC, SIDZFREQ1X
    CALL SIDZFREQ1T
SIDZFREQ1X:
    SRL A
    JR NC, SIDZFREQ2X
    CALL SIDZFREQ2T
SIDZFREQ2X:
    RET

SIDZCALCFREQ:
    RL C
    SLA B
    RL C
    SLA B
    RL C
    SLA B
    RL C
    SLA B
    RET

SIDZFREQ0:
    CALL SIDZCALCFREQ
SIDZFREQ0T:
    JP SIDZPROGFREQ0

SIDZFREQ1:
    CALL SIDZCALCFREQ
SIDZFREQ1T:
    JP SIDZPROGFREQ1

SIDZFREQ2:
    CALL SIDZCALCFREQ
SIDZFREQ2T:
    JP SIDZPROGFREQ2

SIDZPROGFREQ:
    SRL A
    JR NC, SIDZPROGFREQ0X
    CALL SIDZPROGFREQ0
SIDZPROGFREQ0X:
    SRL A
    JR NC, SIDZPROGFREQ1X
    CALL SIDZPROGFREQ1
SIDZPROGFREQ1X:
    SRL A
    JR NC, SIDZPROGFREQ2X
    CALL SIDZPROGFREQ2
SIDZPROGFREQ2X:
    RET

SIDZPROGFREQ0:
    PUSH AF
    LD A, C
    LD ($D400), A
    LD A, B
    LD ($D401), A
    LD A, (SIDZSHADOW)
    OR $1
    LD (SIDZSHADOW), A
    LD ($D404), A
    POP AF
    RET

SIDZPROGFREQ1:
    PUSH AF
    LD A, C
    LD ($D407), A
    LD A, B
    LD ($D408), A
    LD A, (SIDZSHADOW+1)
    OR $1
    LD (SIDZSHADOW+1), A
    LD ($D40B), A
    POP AF
    RET

SIDZPROGFREQ2:
    PUSH AF
    LD A, C
    LD ($D40E), A
    LD A, B
    LD ($D40F), A
    LD A, (SIDZSHADOW+2)
    OR $1
    LD (SIDZSHADOW+2), A
    LD ($D412), A
    POP AF
    RET

SIDZPROGPULSE:
    SRL A
    JR NC, SIDZPROGPULSE0X
    CALL SIDZPROGPULSE0
SIDZPROGPULSE0X:
    SRL A
    JR NC, SIDZPROGPULSE1X
    CALL SIDZPROGPULSE1
SIDZPROGPULSE1X:
    SRL A
    JR NC, SIDZPROGPULSE2X
    CALL SIDZPROGPULSE2
SIDZPROGPULSE2X:
    RET

SIDZPROGPULSE0:
    PUSH AF
    LD A, C
    LD ($D402), A
    LD A, B
    LD ($D403), A
    LD A, (SIDZSHADOW)
    AND $0F
    OR $40
    LD (SIDZSHADOW), A
    LD ($D404), A
    POP AF
    RET

SIDZPROGPULSE1:
    PUSH AF
    LD A, C
    LD ($D409), A
    LD A, B
    LD ($D40A), A
    LD A, (SIDZSHADOW)
    AND $0F
    OR $40
    LD (SIDZSHADOW), A
    LD ($D40B), A
    POP AF
    RET

SIDZPROGPULSE2:
    PUSH AF
    LD A, C
    LD ($D410), A
    LD A, B
    LD ($D411), A
    LD A, (SIDZSHADOW)
    AND $0F
    OR $40
    LD (SIDZSHADOW), A
    LD ($D412), A
    POP AF
    RET

SIDZPROGCTR:
    PUSH AF
    SRL A
    JR NC, SIDZPROGCTR0X
    CALL SIDZPROGCTR0
SIDZPROGCTR0X:
    SRL A
    JR NC, SIDZPROGCTR1X
    CALL SIDZPROGCTR1
SIDZPROGCTR1X:
    SRL A
    JR NC, SIDZPROGCTR2X
    CALL SIDZPROGCTR2
SIDZPROGCTR2X:
    POP AF
    RET

SIDZPROGCTR0:
    PUSH AF
    LD A, (SIDZSHADOW)
    AND $0F
    LD (SIDZSHADOW), A
    OR C
    LD (SIDZSHADOW), A
    LD ($D404), A
    POP AF
    RET

SIDZPROGCTR1:
    PUSH AF
    LD A, (SIDZSHADOW+1)
    AND $0F
    LD (SIDZSHADOW+1), A
    OR C
    LD (SIDZSHADOW+1), A
    LD ($D40B), A
    POP AF
    RET

SIDZPROGCTR2:
    PUSH AF
    LD A, (SIDZSHADOW+2)
    AND $0F
    LD (SIDZSHADOW+2), A
    OR C
    LD (SIDZSHADOW+2), A
    LD ($D412), A
    POP AF
    RET

SIDZPROGAD:
    PUSH AF
    SRL A
    JR NC, SIDZPROGAD0X
    CALL SIDZPROGAD0
SIDZPROGAD0X:
    SRL A
    JR NC, SIDZPROGAD1X
    CALL SIDZPROGAD1
SIDZPROGAD1X:
    SRL A
    JR NC, SIDZPROGAD2X
    CALL SIDZPROGAD2
SIDZPROGAD2X:
    POP AF
    RET

SIDZPROGAD0:
    PUSH AF
    LD A, C
    SLA A
    SLA A
    SLA A
    SLA A
    LD C, A
    LD A, B
    AND $0F
    OR C
    LD ($D405), A
    POP AF
    RET

SIDZPROGAD1:
    PUSH AF
    LD A, C
    SLA A
    SLA A
    SLA A
    SLA A
    LD C, A
    LD A, B
    AND $0F
    OR C
    LD ($D40C), A
    POP AF
    RET

SIDZPROGAD2:
    PUSH AF
    LD A, C
    SLA A
    SLA A
    SLA A
    SLA A
    LD C, A
    LD A, B
    AND $0F
    OR C
    LD ($D413), A
    POP AF
    RET

SIDZPROGSR:
    PUSH AF
    SRL A
    JR NC, SIDZPROGSR0X
    CALL SIDZPROGSR0
SIDZPROGSR0X:
    SRL A
    JR NC, SIDZPROGSR1X
    CALL SIDZPROGSR1
SIDZPROGSR1X:
    SRL A
    JR NC, SIDZPROGSR2X
    CALL SIDZPROGSR2
SIDZPROGSR2X:
    POP AF
    RET

SIDZPROGSR0:
    PUSH AF
    LD A, C
    SLA A
    SLA A
    SLA A
    SLA A
    LD C, A
    LD A, B
    AND $0F
    OR C
    LD ($D406), A
    POP AF
    RET

SIDZPROGSR1:
    PUSH AF
    LD A, C
    SLA A
    SLA A
    SLA A
    SLA A
    LD C, A
    LD A, B
    AND $0F
    OR C
    LD ($D40D), A
    POP AF
    RET

SIDZPROGSR2:
    PUSH AF
    LD A, C
    SLA A
    SLA A
    SLA A
    SLA A
    LD C, A
    LD A, B
    AND $0F
    OR C
    LD ($D414), A
    POP AF
    RET

SIDZSTOP:
    SRL A
    JR NC, SIDZSTOP0X
    CALL SIDZSTOP0
SIDZSTOP0X:
    SRL A
    JR NC, SIDZSTOP1X
    CALL SIDZSTOP1
SIDZSTOP1X:
    SRL A
    JR NC, SIDZSTOP2X
    CALL SIDZSTOP2
SIDZSTOP2X:
    RET

SIDZSTOP0:
    PUSH AF
    LD A, (SIDZSHADOW)
    AND $F6
    LD (SIDZSHADOW), A
    LD ($D404), A
    LD A, 0
    LD ($D400), A
    LD ($D401), A
    POP AF
    RET

SIDZSTOP1:
    PUSH AF
    LD A, (SIDZSHADOW+1)
    AND $F6
    LD (SIDZSHADOW+1), A
    LD ($D40B), A
    LD A, 0
    LD ($D407), A
    LD ($D408), A
    POP AF
    RET

SIDZSTOP2:
    PUSH AF
    LD A, (SIDZSHADOW+2)
    AND $F6
    LD (SIDZSHADOW+2), A
    LD ($D412), A
    LD A, 0
    LD ($D40E), A
    LD ($D40F), A
    POP AF
    RET

SIDZSETDURATION:
    SRL A
    JR NC, SIDZSETDURATION0X
    CALL SIDZSETDURATION0
SIDZSETDURATION0X:
    SRL A
    JR NC, SIDZSETDURATION1X
    CALL SIDZSETDURATION1
SIDZSETDURATION1X:
    SRL A
    JR NC, SIDZSETDURATION2X
    CALL SIDZSETDURATION2
SIDZSETDURATION2X:
    RET

SIDZSETDURATION0:
    LD A, C
    LD (SIDZTIMER), A
    RET

SIDZSETDURATION1:
    LD A, C
    LD (SIDZTIMER+1), A
    RET

SIDZSETDURATION2:
    LD A, C
    LD (SIDZTIMER+2), A
    RET

SIDZWAITDURATION:
    SRL A
    JR NC, SIDZWAITDURATION0X
    CALL SIDZWAITDURATION0
SIDZWAITDURATION0X:
    SRL A
    JR NC, SIDZWAITDURATION1X
    CALL SIDZWAITDURATION1
SIDZWAITDURATION1X:
    SRL A
    JR NC, SIDZWAITDURATION2X
    CALL SIDZWAITDURATION2
SIDZWAITDURATION2X:
    RET

SIDZWAITDURATION0:
    LD A, (SIDZTIMER)
    CP 0
    JR NZ, SIDZWAITDURATION0
    RET

SIDZWAITDURATION1:
    LD A, (SIDZTIMER+1)
    CP 0
    JR NZ, SIDZWAITDURATION1
    RET

SIDZWAITDURATION2:
    LD A, (SIDZTIMER+2)
    CP 0
    JR NZ, SIDZWAITDURATION2
    RET

