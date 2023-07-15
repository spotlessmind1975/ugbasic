; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

SYSIRQADDR: 
    .word   $0

    ; ...
    ; ; **** Gestore IRQ personalizzato

IRQWRAPPER:

    PHA
    TXA
    PHA

    LDA $FF1C
    LSR A
    BCS IRQWRAPPEREND2

    LDA $FF1D
    CMP #206
    BCC IRQWRAPPEREND2

    TSX
    LDA $101,X ; recupero il registro di stato salvato nello stack
    TAX
    LDA #>IRQWRAPPEREND ; prima il byte alto
    PHA
    LDA #<IRQWRAPPEREND ; poi il byte basso
    PHA
    TXA
    PHA ; infine il registro di stato
    
    ; ... ; abilita ROM

    LDA #$42
    STA $FF3E

    JMP (SYSIRQADDR)

IRQWRAPPEREND:

    SEI
    
IRQWRAPPEREND2:

    ; myEndIRQ:
    ; ... ; disabilita ROM

    LDA #$42
    STA $FF3F

    PLA
    TAX
    PLA

    RTI

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

    SEI

    LDA $FFFE
    STA SYSIRQADDR
    LDA $FFFF
    STA SYSIRQADDR+1

    LDA #$42
    STA $FF3F

    LDA #<IRQWRAPPER
    STA $FFFE
    LDA #>IRQWRAPPER
    STA $FFFF
    CLI

SYSCALLDONE:
    LDA #$42
    STA $FF3F
    CLI
    
    RTS
SYSCALL:
    SEI
    LDA #$42
    STA $FF3E
SYSCALL0:
    JSR $0000
    JMP SYSCALLDONE
