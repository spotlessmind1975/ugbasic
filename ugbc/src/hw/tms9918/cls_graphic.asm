; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                      CLEAR SCREEN ROUTINE FOR TMS9918 (graphic mode)        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; 			        NAME		COLOR		PATTERN
; VDPUPDATE0: 		$1800		            $0000 (coleco)
; VDPUPDATE1:		$1800		$0480		$0000 (coleco)
; VDPUPDATE2:		$3800		$2000
; VDPUPDATE3:		$3800		$2000		$0000

if __coleco__

CLSG:
    CALL WAIT_VDP_HOOK
    LD HL, CLSGNMI
    CALL SET_VDP_HOOK0
    CALL WAIT_VDP_HOOK
    RET

CLSGNMI:

else

CLSG:

endif

    LD A, 0
    LD DE, $3800
    LD BC, 256*3
    CALL VDPFILLA

    LD BC, 256*8*3
    LD DE, $0000
    LD A, 0
    CALL VDPFILL

    LD BC, 32*24*8
    LD DE, $2000
    LD A, (_PAPER)
    CALL VDPFILL

    RET
