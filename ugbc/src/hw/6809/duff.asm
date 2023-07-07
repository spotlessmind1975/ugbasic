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
;*                               DUFF'S DEVICE                                 *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DUFFDEVICE
    CMPD #0
    BEQ DUFFDEVICEDONE

    LDU #$1212
    STU DUFFDEVICEL0C

    LSRA
    RORB
    BCC DUFFDEVICELX
    PSHS D
    LDA , Y+
    STA , X+
    PULS D

DUFFDEVICELX
    PSHS D
    ; 2
    ; Xxxx000       xxxx111
    ANDB #7
    LSLB
    STB DUFFDEVICEL0A+2
    STB DUFFDEVICEL0B+2
    LSRB
    ; 2
    STB DUFFDELTA
    ; 8
    LDB #8
    ; 8 - 2 = 6
    SUBB DUFFDELTA
    ; 6
    LDA #4
    ; 6 * 4 = 24
    MUL
    STB DUFFDEVICEL0+1
    PULS D
DUFFDEVICEL0
    BRA DUFFDEVICEL1

DUFFDEVICEL1
    LDU 14, Y    ; +0
    STU 14, X
    LDU 12, Y    ; +6
    STU 12, X
    LDU 10, Y    ; +12
    STU 10, X
    LDU 8, Y    ; +18
    STU 8, X
    LDU 6, Y    ; +24
    STU 6, X
    LDU 4, Y    ; +30
    STU 4, X
    LDU 2, Y    ; +36
    STU 2, X
    LDU , Y
    STU , X

DUFFDEVICEL0A
    LEAX 16,X
DUFFDEVICEL0B
    LEAY 16,Y
    SUBD #$8
    BMI DUFFDEVICEDONE
    BEQ DUFFDEVICEDONE
DUFFDEVICEL0C
    BRA DUFFDEVICEL1
    PSHS D
    LDB #16
    STB DUFFDEVICEL0A+2
    STB DUFFDEVICEL0B+2
    LDD #$20D1
    STA DUFFDEVICEL0C
    PULS D
    BRA DUFFDEVICEL1

DUFFDEVICEDONE
    RTS

DUFFDELTA
    FCB $0
