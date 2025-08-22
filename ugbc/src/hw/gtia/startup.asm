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
;*                            STARTUP ROUTINE ON GTIA                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CPUMEMMOVE:
    LDY MATHPTR0+1
    BEQ CPUMEMMOVER
    LDY #$0
CPUMEMMOVE2:
    LDA (TMPPTR), Y
    STA (TMPPTR2), Y
    INY
    BNE CPUMEMMOVE2
    INC TMPPTR+1
    INC TMPPTR2+1
    DEC MATHPTR0+1
    BNE CPUMEMMOVE2

CPUMEMMOVER:
    LDY #$0
CPUMEMMOVER2:
    LDA (TMPPTR), Y
    STA (TMPPTR2), Y
    INY
    CPY MATHPTR0
    BNE CPUMEMMOVER2
    RTS

GTIAVBLIRQPREV: .word $0

GTIAVBLIRQ:
@IF deployed.pokeystartup
    JSR POKEYTIMERMANAGER
@ENDIF
@IF deployed.music
    JSR MUSICPLAYER
@ENDIF
@IF deployed.timer
    JSR TIMERMANAGER
@ENDIF
@IF deployed.fade
    JSR FADET
@ENDIF
@IF deployed.keyboard && !keyboardConfig.sync
    JSR KEYBOARDMANAGER
@ENDIF
@IF deployed.flash
    JSR FLASHMANAGER
@ENDIF
    JMP (GTIAVBLIRQPREV)

GTIASTARTUP:
    LDA #0
    STA XCURSYS
    STA YCURSYS
    STA $D404
    STA $D405
    SEI
    LDA GTIAVBLIRQPREV
    BNE GTIASTARTUPDONE
    LDA GTIAVBLIRQPREV+1
    BNE GTIASTARTUPDONE
    LDA $222
    STA GTIAVBLIRQPREV
    LDA $223
    STA GTIAVBLIRQPREV+1
    LDA #<GTIAVBLIRQ
    STA $222
    LDA #>GTIAVBLIRQ
    STA $223
GTIASTARTUPDONE:

@IF lmarginAtariBasicEnabled
    LDA #2
    STA CONSOLEX1
    LDA CONSOLEX1
    STA XCURSYS
    LDA CONSOLEY1
    STA YCURSYS
@ENDIF

    CLI

    LDA #$00
    STA $02c4
    LDA #$00
    STA $02c5
    LDA #$00
    STA $02c6
    LDA #$00
    STA $02c7
    LDA #$00
    STA $02c8
    
    RTS

GTIAAFTERINIT:
@IF vestigialConfig.clsImplicit
	JSR CLS
@ENDIF
    RTS    
