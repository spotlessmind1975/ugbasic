; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;*                             DLOAD ROUTINE ON CPC                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; HL: filename, B: filename length
; DE: address
CPCDLOAD:

    PUSH DE
    PUSH HL
    PUSH BC

    CALL CPCIRQSYSTEM

    LD DE, $40
    LD HL, $B0FF
    CALL $BCCB
    POP BC
    POP HL

    LD DE, $C000
    CALL $BC77
    POP DE

    JR NC, CPCDLOADERROR

    LD HL, DE
    CALL $BC83
    
    CALL $BC7A

    JP CPCDLOADDONE

CPCDLOADERROR:
    LD (DLOADERROR), A

CPCDLOADDONE:

    CALL CPCIRQUGBASIC
    
	DI
	LD HL, IRQTIMERVOID
	LD A, L
	LD (IRQTIMERADDR+1), A
	LD A, H
	LD (IRQTIMERADDR+2), A
	EXX
	LD B, $7F
	LD A, (GAVALUE)
	OR A, $0C
	LD (GAVALUE), A
	LD C, A
	OUT (C), C
	EXX
	EI

    RET

