; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                     SERIAL SUPPORT ON R: DEVICE FOR ATARI                   *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SERIALFILENAME:
    .BYTE "R1:", 0

RECVBUF: .res  256

SERIALINIT:
    LDX #$10
    LDA #IOCB_OPEN
    STA	ICCOM, X
    LDA #13
    STA	ICAUX1, X
    LDA #$0
    STA	ICAUX2, X
    LDA #<SERIALFILENAME
    STA ICBADRL, X
    LDA #>SERIALFILENAME
    STA ICBADRH, X
    LDA #$3
    STA ICBLENL, X
    LDA #$0
    STA ICBLENH, X
    JSR CIOV

    CPY #127
    BCC SERIALINITNOERROR
    RTS
SERIALINITNOERROR:

    LDX #$10
    LDA #36
    STA	ICCOM, X
    LDA #14
    STA ICAUX1, X
    LDA #0
    STA ICAUX2, X
    LDA #<SERIALFILENAME
    STA ICBADRL, X
    LDA #>SERIALFILENAME
    STA ICBADRH, X
    LDA #$3
    STA ICBLENL, X
    LDA #$0
    STA ICBLENH, X
    JSR CIOV

    LDA #38
    STA ICCOM, X
    LDA #32
    STA ICAUX1, X
    LDA #0
    STA ICAUX2, X
    LDA #<RECVBUF
    STA ICBADRL, X
    LDA #>RECVBUF
    STA ICBADRH, X
    LDA #$FF
    STA ICBLENL, X
    LDA #$0
    STA ICBLENH, X
    JSR CIOV    

    LDA #40
    STA ICCOM, X
    LDA #$0D
    STA ICAUX1, X
    LDA #0
    STA ICAUX2, X
    LDA #<RECVBUF
    STA ICBADRL, X
    LDA #>RECVBUF
    STA ICBADRH, X
    LDA #$FF
    STA ICBLENL, X
    LDA #$0
    STA ICBLENH, X
    JSR CIOV

    RTS

; ----------------------------------------------------------------------------
; SERIAL READ BYTE
; ----------------------------------------------------------------------------
; We call this routine to read the next byte from R: device.
;
; Output:
;           A = data received from SERIAL port
;
SERIALREADBYTE:
    LDX #$10
    LDA #IOCB_GETCHR
    STA	ICCOM, X
    LDA #0
    STA ICBADRL, X
    STA ICBADRH, X
    STA ICBLENL, X
    STA ICBLENH, X
    JSR CIOV
    RTS

; ----------------------------------------------------------------------------
; SERIAL WRITE BYTE
; ----------------------------------------------------------------------------
; We call this routine to write a byte to DriveWire port using becker port 
; emulation under emulator.
;
; Input:
;           A = data to write to SERIAL server
;
SERIALWRITEBYTE:
    PHA
    LDX #$10
    LDA #IOCB_PUTCHR
    STA	ICCOM, X
    LDA #0
    STA ICBADRL, X
    STA ICBADRH, X
    STA ICBLENL, X
    STA ICBLENH, X
    PLA
    JSR CIOV
    RTS

; ----------------------------------------------------------------------------
; SERIAL WRITE
; ----------------------------------------------------------------------------
; We call this routine to write a string of bytes to DriveWire port using 
; becker port emulation under emulator.
;
; Input:
;           TMPPTR = address of data to send
;           MATHPTR0 = size of the data to send
; Output:
;           A = 0 is success, 0xff is failed
;

SERIALWRITE:
    LDX #$10
    LDA #IOCB_PUTCHR
    STA	ICCOM, X
    LDA TMPPTR
    STA ICBADRL, X
    LDA TMPPTR+1
    STA ICBADRH, X
    LDA MATHPTR0
    STA ICBLENL, X
    LDA #0
    STA ICBLENH, X
    JSR CIOV
    LDA #0
    RTS

; ----------------------------------------------------------------------------
; SERIAL WRITE CONST
; ----------------------------------------------------------------------------
; We call this routine to write a sequence of the same byte to DriveWire port 
; using becker port emulation under emulator.
;
; Input:
;           A = value to send
;           MATHPTR0 = size of the data to send
; Output:
;           A = 0 is success, 0xff is failed
;

SERIALWRITECONST:
    JSR SERIALWRITEBYTE
    DEC MATHPTR0
    BNE SERIALWRITECONST
    LDA #0
    RTS

; ----------------------------------------------------------------------------
; SERIAL READ
; ----------------------------------------------------------------------------
; We call this routine to read a sequence of bytes from DriveWire port 
; using becker port emulation under emulator.
;
; Input:
;           TMPPTR = address of data to receive
;           MATHPTR0 = size of the data to receive

SERIALREAD:
    LDX #$10
    LDA #IOCB_GETCHR
    STA	ICCOM, X
    LDA TMPPTR
    STA ICBADRL, X
    LDA TMPPTR+1
    STA ICBADRH, X
    LDA MATHPTR0
    STA ICBLENL, X
    LDA #0
    STA ICBLENH, X
    JSR CIOV
    LDA #0
    RTS

