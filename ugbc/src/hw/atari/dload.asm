; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;*                            DLOAD ROUTINE ON ATARI                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *



; TMPPTR : filename; 
; DCOM_ADDRESS: address, DCOM_SIZE: size
; DCOM_FROM: from
ATARIDLOAD:
    STA $C042
    JSR ATARIPREPAREFILENAME

    LDX #$10
    LDA #IOCB_OPEN
    STA	ICCOM, X
    LDA #$04
    STA	ICAUX1, X
    LDA #<ATARIFILENAME
    STA ICBADRL, X
    LDA #>ATARIFILENAME
    STA ICBADRH, X
    JSR CIOV

    CPY #127
    BCC ATARIDLOADERRX
    JMP ATARIDLOADERR
ATARIDLOADERRX:


    LDA DCOM_ADDRESS
    ORA DCOM_ADDRESS+1
    BNE ATARIDLOADDONEX
    JMP ATARIDLOADDONE
ATARIDLOADDONEX:

    LDA DCOM_SIZE
    ORA DCOM_SIZE+1
    BNE ATARIDLOADDONEX2
    JMP ATARIDLOADDONE
ATARIDLOADDONEX2:

    LDA DCOM_FROM
    ORA DCOM_FROM+1
    BEQ ATARIDLOADL1

ATARIDLOADLSKIP:

    LDX #$10
    LDA #IOCB_GETCHR
    STA	ICCOM, X
    LDA #<ATARIFILENAME0
    STA ICBADRL, X
    LDA #>ATARIFILENAME0
    STA ICBADRH, X
    LDA #1
    STA ICBLENL, X
    LDA #0
    STA ICBLENH, X
    JSR CIOV

    DEC DCOM_FROM
    CMP #$FF
    BNE ATARIDLOADLSKIP0
    DEC DCOM_FROM+1
ATARIDLOADLSKIP0:

    LDA DCOM_FROM
    ORA DCOM_FROM+1
    BNE ATARIDLOADLSKIP

ATARIDLOADL1:

    LDX #$10
    LDA #IOCB_GETCHR
    STA	ICCOM, X
    LDA DCOM_ADDRESS
    STA ICBADRL, X
    LDA DCOM_ADDRESS+1
    STA ICBADRH, X
    LDA #1
    STA ICBLENL, X
    LDA #0
    STA ICBLENH, X
    JSR CIOV

    CPY #1
    BNE ATARIDLOADEOF

    INC DCOM_ADDRESS
    BNE ATARIDLOADL11
    INC DCOM_ADDRESS+1
ATARIDLOADL11:

    DEC DCOM_SIZE
    CMP #$FF
    BNE ATARIDLOADL10
    DEC DCOM_SIZE+1
ATARIDLOADL10:

    LDA DCOM_SIZE
    ORA DCOM_SIZE+1
    BNE ATARIDLOADL1

ATARIDLOADEOF:
    LDX #$10
    LDA #IOCB_CLOSE
    STA	ICCOM, X
    JSR CIOV

ATARIDLOADDONE:
    RTS

ATARIDLOADERR:
    TYA
    SBC #127
    STY DLOADERROR
    RTS
