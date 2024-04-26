; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                           STARTUP ROUTINE ON SN-76489                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF COCO || COCO3
@IF gmc.slot.static || gmc.slot.dynamic
@EMIT gmc.slot.value AS GMC_SLOT_STATIC
GMC_SLOT        fcb  GMC_SLOT_STATIC
@ENDIF
@ENDIF

@IF PC128OP
@IF sn76489.address.static || sn76489.address.dynamic 
@EMIT sn76489.address.value AS CSG_OUT
@ELSE
CSG_OUT EQU         BASE_SEGMENT+$FF
@ENDIF
@ENDIF

@IF COCO || COCO3
@IF sn76489.address.static || sn76489.address.dynamic 
@EMIT sn76489.address.value AS CSG_OUT
@ELSE
CSG_OUT EQU         $FF41
@ENDIF
@ENDIF

SN76489WRITE
    STB CSG_OUT
@IF COCO || COCO3
    NOP
    NOP
@ENDIF
    RTS

SN76489STARTUP
@IF COCO || COCO3

	LDA	#$30
	STA	$FF7F
    LDD #$F00
    JSR SN76489STARTVOL

	LDA	#$31
	STA	$FF7F
    LDD #$F00
    JSR SN76489STARTVOL

	LDA	#$32
	STA	$FF7F
    LDD #$F00
    JSR SN76489STARTVOL

	LDA	#$30
@IF gmc.slot.static || gmc.slot.dynamic
    ORA GMC_SLOT
@ENDIF
	STA	$FF7F

@ENDIF

    LDX #SN76489FREQTABLE
    STX SN76489TMPPTR2
    LDX #SN76489TMPPTR
    CLRA
    CLRB
    STD ,X
    LDX #SN76489JIFFIES
    STA ,X

@IF COCO || COCO3

    LDA #$34
	STA $FF01
	LDA #$3F
	STA $FF03
    LDA #$38
	STA $FF23

@ENDIF

    RTS
