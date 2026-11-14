; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                      STARTUP ROUTINE FOR COLECO                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COLECOSTARTUP2:

@IF dataSegment
    LD HL, DATAFIRSTSEGMENT
    LD (DATAPTR), HL
@ENDIF

    RET

@IF deployed.random
section data_user
CPURANDOM_SEED:  defw $ff42,$ffea
section code_user
@ENDIF

@IF deployed.sn76489startup
section data_user
SN76489TIMER: defs 6
section code_user
@ENDIF

@IF deployed.embedded.cpu_call_indirect
section data_user
CALLINDIRECT:           DEFB $c3,$00,	$00
CALLINDIRECTSAVEHL:     DEFW $0000
section code_user
@ENDIF

@IF consoleUsed
section data_user
CONSOLEX1:           DEFB   0
CONSOLEY1:           DEFB   0
CONSOLESA:           DEFW   0
section code_user
@ELSE
CONSOLEX1: EQU 0
CONSOLEY1: EQU 0
CONSOLESA: EQU TEXTADDRESS
@ENDIF
