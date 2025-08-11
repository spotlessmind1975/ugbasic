; ; /*****************************************************************************
; ;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
; ;  *****************************************************************************
; ;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
; ;  *
; ;  * Licensed under the Apache License, Version 2.0 (the "License");
; ;  * you may not use this file except in compliance with the License.
; ;  * You may obtain a copy of the License at
; ;  *
; ;  * http://www.apache.org/licenses/LICENSE-2.0
; ;  *
; ;  * Unless required by applicable law or agreed to in writing, software
; ;  * distributed under the License is distributed on an "AS IS" BASIS,
; ;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; ;  * See the License for the specific language governing permissions and
; ;  * limitations under the License.
; ;  *----------------------------------------------------------------------------
; ;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
; ;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
; ;  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
; ;  *
; ;  * http://www.apache.org/licenses/LICENSE-2.0
; ;  *
; ;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
; ;  * il software distribuito nei termini della Licenza è distribuito
; ;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
; ;  * implicite. Consultare la Licenza per il testo specifico che regola le
; ;  * autorizzazioni e le limitazioni previste dalla medesima.
; ;  ****************************************************************************/
; ;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
; ;*                                                                             *
; ;*                         CHAR GIVEN POSITION ON TMS9918                      *
; ;*                                                                             *
; ;*                             by Marco Spedaletti                             *
; ;*                                                                             *
; ;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SCREEN:

;     PUSH DE
;     PUSH BC

;     LD A, (CURRENTTILESWIDTH)
;     LD E, A
;     LD D, 0

;     LD HL, (TEXTADDRESS)
;     LD (COPYOFTEXTADDRESS), HL

;     LD A, B
;     CP 0
;     JR Z, SCREENSKIP
;     LD C, A
;     LD HL, (COPYOFTEXTADDRESS)
; SCREENLOOP1:
;     ADD HL, DE
;     DEC C
;     JR NZ, SCREENLOOP1
;     LD (COPYOFTEXTADDRESS), HL

; SCREENSKIP:
;     POP BC

;     LD A, C
;     LD E, A
;     LD A, 0
;     LD D, 0
;     LD HL, (COPYOFTEXTADDRESS)
;     ADD HL, DE
;     LD (COPYOFTEXTADDRESS), HL

;     POP DE
    
; SCREENSP0:
;     LD HL, (COPYOFTEXTADDRESS)

;     PUSH DE
;     PUSH BC
;     LD DE, HL
;     LD BC, 1
;     CALL VDPINCHAR
;     POP BC
;     POP DE

;     RET