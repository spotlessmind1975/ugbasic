; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                          STARTUP ROUTINE ON PLUS/4                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

;     ; ...
;     ; ; **** Gestore IRQ personalizzato

; IRQWRAPPER:

;     PHP
;     PHA
;     TXA
;     PHA

;     LDA $FF1C
;     LSR A
;     BCS IRQWRAPPEREND2

;     LDA $FF1D
;     CMP #206
;     BCC IRQWRAPPEREND2

;     TSX
;     LDA $101,X ; recupero il registro di stato salvato nello stack
;     TAX
;     LDA #>IRQWRAPPEREND ; prima il byte alto
;     PHA
;     LDA #<IRQWRAPPEREND ; poi il byte basso
;     PHA
;     TXA
;     PHA ; infine il registro di stato
    
;     ; ... ; abilita ROM

;     LDA #$42
;     STA $FF3E

; SYSIRQADDR:
;     JMP $0000

; IRQWRAPPEREND:

;     SEI
    
; IRQWRAPPEREND2:

;     ; myEndIRQ:
;     ; ... ; disabilita ROM

;     LDA #$42
;     STA $FF3F

;     PLA
;     TAX
;     PLA
;     PLP

;     CLI

;     RTI

JIFFYUPDATE:
    PHP
    PHA
    TXA
    PHA
	LDX	#$00			; clear X
	INC	$A5		; increment the jiffy clock low byte
	BNE	JIFFYNORO		; if no rollover ??

	INC	$A4		; increment the jiffy clock mid byte
	BNE	JIFFYNORO		; branch if no rollover

	INC	$A3		; increment the jiffy clock high byte

					; now subtract a days worth of jiffies from current count
					; and remember only the Cb result
JIFFYNORO:
	SEC				; set carry for subtract
	LDA	$A5		; get the jiffy clock low byte
	SBC	#$01			; subtract $4F1A01 low byte
	LDA	$A4		; get the jiffy clock mid byte
	SBC	#$1A			; subtract $4F1A01 mid byte
	LDA	$A3		; get the jiffy clock high byte
	SBC	#$4F			; subtract $4F1A01 high byte
	BCC	JIFFYDAY		; if less than $4F1A01 jiffies skip the clock reset

					; else ..
	STX	$A3		; clear the jiffy clock high byte
	STX	$A4		; clear the jiffy clock mid byte
	STX	$A5		; clear the jiffy clock low byte
					; this is wrong, there are $4F1A00 jiffies in a day so
					; the reset to zero should occur when the value reaches
					; $4F1A00 and not $4F1A01. this would give an extra jiffy
					; every day and a possible TI value of 24:00:00
JIFFYDAY:
    PLA
    TAX
    PLA
    PLP
	RTS

PLUS4STARTUP:

    ; Innanzitutto: non conosco il Plus4, quindi potrebbero esserci questioni
    ; che non sto considerando. Immagino che la routine che serve l'irq termini 
    ; con l'istruzione RTI: questa istruzione preleva dallo stack il registro di 
    ; stato, e poi l'indirizzo di ritorno.

    ; Come suggerimento quindi ti proporrei di
    ; - avere un nuovo gestore IRQ
    ; - avere una nuova routine di "chiusura" IRQ
    ; - impostare l'indirizzo dell'IRQ al gestore dell'interrupt scritto da te
    ; - disabilitare le Rom
    ; - il gestore dell'interrupt dovrebbe
    ; -- recuperare il valore del registro di stato messo nello stack dall'IRQ (TSX, LDA $101,X)
    ; -- immettere nello stack l'indirizzo di ritorno ad una tua routine di chiusura irq
    ; -- reimmettere nello stack il valore del registro di stato recuperato in precedenza
    ; -- abilitare la ROM
    ; -- saltare (JMP) all'indirizzo del gestore IRQ di sistema
    ; - la routine di ritorno deve
    ; -- ri-disabilitare la ROM
    ; -- prelevare dallo stack i dati di ritorno di fine interrupt

    ; ; **** inizializzazioni del programma
    ; ...
    ; ; **** reindirizzamento IRQ

    LDA $F33F
    CMP #$48
    BEQ PLUS4NTSC

PLUS4PAL:
    LDA #50
    STA TICKSPERSECOND
    JMP PLUS4STARTUPDONE

PLUS4NTSC:
    LDA #60
    STA TICKSPERSECOND
    JMP PLUS4STARTUPDONE

PLUS4STARTUPDONE:
    RTS
    
    ; SEI

    ; LDA SYSIRQADDR+1
    ; BNE PLUS4STARTUPDONENOIRQ
    ; LDA SYSIRQADDR+2
    ; BNE PLUS4STARTUPDONENOIRQ

    ; LDA $FFFE
    ; STA SYSIRQADDR+1
    ; LDA $FFFF
    ; STA SYSIRQADDR+2

    ; LDA #$42
    ; STA $FF3F

    ; LDA #<IRQWRAPPER
    ; STA $FFFE
    ; LDA #>IRQWRAPPER
    ; STA $FFFF

PLUS4STARTUPDONENOIRQ:

    ; CLI

@IF dataSegment
    LDA #<DATAFIRSTSEGMENT
    STA DATAPTR
    LDA #>DATAFIRSTSEGMENT
    STA DATAPTR+1
    LDY #0
    STY DATAPTRY
@ENDIF

@IF sysCallUsed

SYSCALLDONE:

@ENDIF

    ; LDA #$42
    ; STA $FF3F
    ; CLI

@IF sysCallUsed

    RTS
SYSCALL:
    SEI
    LDA #$42
    STA $FF3E
SYSCALL0:
    JSR $0000
    JMP SYSCALLDONE

@ENDIF


WAITTIMER:
    LDA $A5
WAITTIMERL1:
    CMP $A5
    BEQ WAITTIMERL1
    DEX
    CPX #$FF
    BNE WAITTIMER
    DEY
    CPY #$FF
    BNE WAITTIMER
    RTS
    