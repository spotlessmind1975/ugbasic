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
;*                      KEYBOARD MATRIX DETECTION ON DRAGON 32/64              *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODE
    ; CLR $FF01
    ; CLR $FF00
    ; CLR $FF03
    LDA #$FF
    STA $FF02
    LDX #SCANCODEMATRIX
    LDA #$FE
SCANCODE0
    STA $FF02
    LDB $FF00
    EORB #$FF
    ANDB #$7F
    CMPB #$0
    BEQ SCANCODENEXT
    TFR B, A
SCANCODENEXT2A
    TFR A, B
    ANDA #1
    CMPA #1
    BNE SCANCODENEXT2
    LDA , X
    JMP SCANCODEE
SCANCODENEXT2
    TFR B, A
    LSRA
    LEAX 1, X
    CMPA #0
    BNE SCANCODENEXT2A
    LDA #0
    JMP SCANCODEE
SCANCODENEXT
    ORCC #$01
    ROLA
    LEAX 8, X
    CMPX #SCANCODEMATRIXE
    BLS SCANCODE0
    LDA #0
SCANCODEE
    RTS

SCANCODEMATRIX
    fcb '0','8','@','H','P','X',$0d,$00     ; // UNUSED
    fcb '1','9','A','I','Q','Y',$F9,$00     ; // CLR, UNUSED
    fcb '2','*','B','J','R','Z',$00,$00     ; // BRK, UNUSED
    fcb '3',',','C','K','S',$FA,$00,$00     ; // UP, UNUSED, UNUSED
    fcb '4','-','D','L','T',$FB,$00,$00     ; // DOWN, UNUSED, UNUSED
    fcb '5',$00,'E','M','U',$FC,$00,$00     ; // ??, .., LEFT, UNUSED, UNUSED
    fcb '6','/','F','N','V',$FD,$00,$00     ; // RIGHT, UNUSED, UNUSED
SCANCODEMATRIXE
    fcb '7',' ','G','O','W',' ',$00,$FE     ; // UNUSED, SHIFT
