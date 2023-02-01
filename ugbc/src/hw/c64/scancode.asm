; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                      KEYBOARD MATRIX DETECTION ON C=64                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODE:
	LDA	#$00
	STA	$028D
	LDY	#$40
	STY	MATHPTR5
	STA	$DC00
	LDX	$DC01
	CPX	#$FF
	BEQ	SCANCODEDONE
	TAY
	LDA	#<KEYS_STANDARD
	STA	TMPPTR
	LDA	#>KEYS_STANDARD
	STA	TMPPTR+1
	LDA	#$FE
	STA	$DC00
SCANCODEL1:
	LDX	#$08
	PHA
SCANCODEL2:
	LDA	$DC01
	CMP	$DC01
	BNE	SCANCODEL2
SCANCODEL3:
	LSR
	BCS	SCANCODEL4
	PHA
	LDA	(TMPPTR),Y
	CMP	#$05
	BCS	SCANCODEL4S
	CMP	#$03
	BEQ	SCANCODEL4S
	ORA	$028D
	STA	$028D
	BPL	SCANCODEL5
SCANCODEL4S:
	STY	MATHPTR5
SCANCODEL5:
	PLA
SCANCODEL4:
	INY
	CPY	#$41
	BCS	SCANCODEL7
	DEX
	BNE	SCANCODEL3
	SEC
	PLA
	ROL
	STA	$DC00
	BNE	SCANCODEL1
SCANCODEL7:
	PLA
	JMP	SCANCODEEVA

SCANCODEEVA2:
	LDY	MATHPTR5
	LDA	(TMPPTR),Y
	TAX
	CPY	$C5
	BEQ	SCANCODEL6
	LDY	#$10
	STY	$028C
	BNE	SCANCODEL10
SCANCODEL6:
	AND	#$7F
	BIT	$028A
	BMI	SCANCODEL12
	BVS	SCANCODEL13
	CMP	#$7F
SCANCODEDONE:
	BEQ	SCANCODEL10
	CMP	#$14
	BEQ	SCANCODEL12
	CMP	#' '
	BEQ	SCANCODEL12
	CMP	#$1D
	BEQ	SCANCODEL12
	CMP	#$11
	BNE	SCANCODEL13
SCANCODEL12:
	LDY	$028C
	BEQ	SCANCODEL14
    DEC	$028C
	BNE	SCANCODEL13
SCANCODEL14:
	DEC	$028B
	BNE	SCANCODEL13
	LDY	#$04
	STY	$028B
	LDY	$C6
	DEY
	BPL	SCANCODEL13
SCANCODEL10:
	LDY	MATHPTR5
	STY	$C5
	LDY	$028D
	STY	$028E
	CPX	#$FF
	BEQ	SCANCODEL13
	TXA
	LDX	$C6
	CPX	$0289
	BCS	SCANCODEL13
	STA	$0277,X
	INX
	STX	$C6
SCANCODEL13:
	LDA	#$7F
	STA	$DC00
	RTS

SCANCODEEVA:
	LDA	$028D
	CMP	#$03
	BNE	SCANCODEEVA1
	CMP	$028E
	BEQ	SCANCODEL13
	LDA	$0291
	BMI	SCANCODEEVA3
	LDA	$D018
	EOR	#$02
	STA	$D018
	JMP	SCANCODEEVA3

SCANCODEEVA1:
	ASL
	CMP	#$08
	BCC	SCANCODEEVA4
	LDA	#$06
SCANCODEEVA4:
	TAX
	LDA	KEYSTABLE,X
	STA	TMPPTR
	LDA	KEYSTABLE+1,X
	STA	TMPPTR+1
SCANCODEEVA3:
	JMP	SCANCODEEVA2

KEYSTABLE:
	.word	KEYS_STANDARD
	.word	KEYS_SHIFTED
	.word	KEYS_CBM
	.word	KEYS_CTRL

KEYS_STANDARD:
	.byte	$14,$0D,$1D,$88,$85,$86,$87,$11
	.byte	$33,$57,$41,$34,$5A,$53,$45,$01
	.byte	$35,$52,$44,$36,$43,$46,$54,$58
	.byte	$37,$59,$47,$38,$42,$48,$55,$56
	.byte	$39,$49,$4A,$30,$4D,$4B,$4F,$4E
	.byte	$2B,$50,$4C,$2D,$2E,$3A,$40,$2C
	.byte	$5C,$2A,$3B,$13,$01,$3D,$5E,$2F
	.byte	$31,$5F,$04,$32,$20,$02,$51,$03
	.byte	$FF

KEYS_SHIFTED:
	.byte	$94,$8D,$9D,$8C,$89,$8A,$8B,$91
	.byte	$23,$D7,$C1,$24,$DA,$D3,$C5,$01
	.byte	$25,$D2,$C4,$26,$C3,$C6,$D4,$D8
	.byte	$27,$D9,$C7,$28,$C2,$C8,$D5,$D6
	.byte	$29,$C9,$CA,$30,$CD,$CB,$CF,$CE
	.byte	$DB,$D0,$CC,$DD,$3E,$5B,$BA,$3C
	.byte	$A9,$C0,$5D,$93,$01,$3D,$DE,$3F
	.byte	$21,$5F,$04,$22,$A0,$02,$D1,$83
	.byte	$FF

KEYS_CBM:
	.byte	$94,$8D,$9D,$8C,$89,$8A,$8B,$91
	.byte	$96,$B3,$B0,$97,$AD,$AE,$B1,$01
	.byte	$98,$B2,$AC,$99,$BC,$BB,$A3,$BD
	.byte	$9A,$B7,$A5,$9B,$BF,$B4,$B8,$BE
	.byte	$29,$A2,$B5,$30,$A7,$A1,$B9,$AA
	.byte	$A6,$AF,$B6,$DC,$3E,$5B,$A4,$3C
	.byte	$A8,$DF,$5D,$93,$01,$3D,$DE,$3F
	.byte	$81,$5F,$04,$95,$A0,$02,$AB,$83
	.byte	$FF

KEYS_CTRL:
	.byte	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
	.byte	$1C,$17,$01,$9F,$1A,$13,$05,$FF
	.byte	$9C,$12,$04,$1E,$03,$06,$14,$18
	.byte	$1F,$19,$07,$9E,$02,$08,$15,$16
	.byte	$12,$09,$0A,$92,$0D,$0B,$0F,$0E
	.byte	$FF,$10,$0C,$FF,$FF,$1B,$00,$FF
	.byte	$1C,$FF,$1D,$FF,$FF,$1F,$1E,$FF
	.byte	$90,$06,$FF,$05,$FF,$FF,$11,$FF
	.byte	$FF