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
;  * Unless required by applicable law or agreed to in writQing, software
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
;*                             FILE WRITE ON C=128                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

FILEWRITENEWLINE:
    LDA #13
    STA FILECHAR
    JSR FILEWRITECHAR
    RTS

FILEWRITETAB:
    LDA #9
    STA FILECHAR
    JSR FILEWRITECHAR
    RTS

FILEWRITECHAR:

    ; SYSTEM CALL: CHKOUT ($FFC9)
    LDX FILENUM
    PHA
    LDA #$C9
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    ; SYSTEM CALL: READST ($FFB7)
    PHA
    LDA #$B7
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL
    BNE FILEWRITEERROR

    ; SYSTEM CALL: CHROUT ($FFD2)
    LDA FILECHAR
    PHA
    LDA #$D2
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    RTS

FILEWRITEBUFFER:

    ; SYSTEM CALL: CHKOUT ($FFC9)
    LDX FILENUM
    PHA
    LDA #$C9
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    LDA FILEPTR
    STA TMPPTR
    LDA FILEPTR+1
    STA TMPPTR+1
    LDX FILESIZE

FILEWRITEBUFFERL1:

    ; SYSTEM CALL: READST ($FFB7)
    PHA
    LDA #$B7
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL
    BNE FILEWRITEERROR

    ; SYSTEM CALL: CHROUT ($FFD2)
    LDA (TMPPTR), Y
    PHA
    LDA #$D2
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL
    INY
    DEX
    BNE FILEWRITEBUFFERL1
    LDA #0
    STA FILEERROR
    RTS

FILEWRITEERROR:
    STA FILEERROR
    RTS
