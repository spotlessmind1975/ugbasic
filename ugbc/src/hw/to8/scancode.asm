; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                      KEYBOARD MATRIX DETECTION ON THOMSON TO8               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODECOUNTER     
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0
    fcb $0, $0, $0, $0, $0, $0, $0, $0

KBDMANAGER
    PSHS X, D
    JSR $E809
    BCC KBDMANAGERDONE
    JSR $E806
    LDX #SCANCODECOUNTER
    LDA #16
    ANDB #$7F
    STA B, X
    PULS X, D
    RTS
KBDMANAGERDONE
    LDX #SCANCODECOUNTER
    LDB #$7F
KBDMANAGERDONEL1
    LDA B, X
    BEQ KBDMANAGERDONEL2
    DEC B, X
KBDMANAGERDONEL2
    DECB
    BNE KBDMANAGERDONEL1
    PULS X, D
    RTS

KEYPRESSED
    LDX #SCANCODECOUNTER
    ANDA #$7F
    LDB A,X
    RTS
    
SCANCODE
    JSR $E806
    BCC SCANCODEDONE
    LDA #$FF
    RTS
SCANCODEDONE
    LDA #$00
    RTS

INKEY
    JSR SCANCODE
    RTS

WAITKEY
    JSR SCANCODE
    CMPA #$FF
    BNE WAITKEY
    RTS
WAITKEYRELEASE
    JSR WAITKEY
WAITKEYRELEASE2
    JSR SCANCODE
    CMPA #$FF
    BNE WAITKEYRELEASE2
    RTS
