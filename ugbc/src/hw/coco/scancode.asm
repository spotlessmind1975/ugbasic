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
;*                      KEYBOARD MATRIX DETECTION ON TRS-80 COLOR COMPUTER     *
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
    fcb '@','H','P','X','0','8',$0d,$E3     ; // UNUSED
    fcb 'A','I','Q','Y','1','9',$F9,$E4     ; // CLR, UNUSED
    fcb 'B','J','R','Z','2',':',$D5,$E5     ; // BRK, UNUSED
    fcb 'C','K','S',$FA,'3',';',$D6,$E6     ; // UP $FA, UNUSED, UNUSED
    fcb 'D','L','T',$FB,'4',',',$D7,$E7     ; // DOWN $FB, UNUSED, UNUSED
    fcb 'E','M','U',8,'5','-',$D8,$E8     ; // ?? $FC, .., LEFT, UNUSED, UNUSED
    fcb 'F','N','V',$FD,'6','.',$D9,$E9     ; // RIGHT $FD, UNUSED, UNUSED
SCANCODEMATRIXE
    fcb '7','O','W',' ','7','/',$F0,$FE     ; // UNUSED, SHIFT
