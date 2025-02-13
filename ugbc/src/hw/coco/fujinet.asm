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
;*                   FUJINET SUPPORT ON TRS-80 COLOR COMPUTER                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

fujiOpNet               equ     $E3

fujiCmdReady            equ     $00
fujiCmdResponse         equ     $01
fujiCmdError            equ     $2
fujiCmdOpen             equ     'O'
fujiCmdClose            equ     'C'
fujiCmdParseJson        equ     'P'
fujiCmdQueryJson        equ     'Q'
fujiCmdRead             equ     'R'
fujiCmdStatus           equ     'S'
fujiCmdWrite            equ     'W'
fujiCmdSetChannelMode   equ     $fc
fujiCmdSetLogin         equ     $fd
fujiCmdSetPassword      equ     $fe

; FUJINET PACKET STAGE AREA
; -------------------------
FUJINETPACKET
    fcb fujiOpNet, $00, $00, $00, $00
FUJINETPACKET_DID       equ     (FUJINETPACKET+1)
FUJINETPACKET_CMD       equ     (FUJINETPACKET+2)
FUJINETPACKET_DAT       equ     (FUJINETPACKET+3)

FUJINETDEVICEID
    fcb $00
FUJINETBYTESWAITING
    fdb $0000
FUJINETCONNECTED
    fcb $00
FUJINETERRORCODE
    fcb $00

; -------------------------------------------------------
; WRITE A FUJINET PACKET ON SERIAL
; -------------------------------------------------------

FUJINETPACKETWRITE
    LDX #FUJINETPACKET
    LDB #5
    JSR SERIALWRITE
    RTS    

; -------------------------------------------------------
; MAKE SURE THAT FUJINET NETWORK IS READY
; -------------------------------------------------------
; Input:    
; Output:   A = status

FUJINETREADY
    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdReady
    STA FUJINETPACKET_CMD
    CLR FUJINETPACKET_DAT
    CLR FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE
    JSR SERIALREADBYTE
    RTS

; -------------------------------------------------------
; READ THE LAST ERROR FROM FUJINET
; -------------------------------------------------------
; Input:    
; Output:   A = error code

FUJINETERROR
    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdError
    STA FUJINETPACKET_CMD
    CLR FUJINETPACKET_DAT
    CLR FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE
    JSR SERIALREADBYTE
    RTS

; -------------------------------------------------------
; READ A RESPONSE FROM FUJINET
; -------------------------------------------------------
; Input:    
;           B = number of bytes to read
;           Y = destination address
; Output:

FUJINETGETRESPONSE
    STB MATHPTR0
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdResponse
    LDB MATHPTR0
    STA FUJINETPACKET_CMD
    STB FUJINETPACKET_DAT
    CLRA
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDB MATHPTR0
    TFR Y, X
    JSR SERIALREAD

    RTS

; -------------------------------------------------------
; OPEN A RESOURCE ON FUJINET
; -------------------------------------------------------
; Input:    
;           B = number of bytes of url
;           Y = url
;           U = mode (high) trans (low)
; Output:

FUJINETOPEN
    STB MATHPTR0
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdOpen
    STA FUJINETPACKET_CMD
    STU FUJINETPACKET_DAT
    JSR FUJINETPACKETWRITE

    LDB MATHPTR0
    TFR Y, X
    JSR SERIALWRITE

    CLRA
    LDB #256
    SUBB MATHPTR0
    JSR SERIALWRITECONST

    JSR FUJINETREADY

    JSR FUJINETERROR

    RTS

; -------------------------------------------------------
; CLOSE A RESOURCE ON FUJINET
; -------------------------------------------------------
; Input:    
; Output:

FUJINETCLOSE
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdClose
    STA FUJINETPACKET_CMD
    CLR FUJINETPACKET_DAT
    CLR FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE
    RTS
    
; -------------------------------------------------------
; GET STATUS FROM FUJINET 
; -------------------------------------------------------
; Input:    A = device id
; Output:

FUJINETGETSTATUS
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdStatus
    STA FUJINETPACKET_CMD
    CLR FUJINETPACKET_DAT
    CLR FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE
 
    LDB #4
    LDY #FUJINETBYTESWAITING
    JSR FUJINETGETRESPONSE

    JSR FUJINETERROR

    RTS

; -------------------------------------------------------
; READ DATA FROM FUJINET CONNECTION
; -------------------------------------------------------
; Input:    B = bytes to read
;           Y = address to read to
; Output:

FUJINETREAD
    STB MATHPTR0
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdRead
    STA FUJINETPACKET_CMD
    CLR FUJINETPACKET_DAT
    CLR FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDB MATHPTR0
    JSR FUJINETGETRESPONSE

    RTS

; -------------------------------------------------------
; WRITE DATA TO FUJINET CONNECTION
; -------------------------------------------------------
; Input:    B = bytes to write
;           Y = address to write from
; Output:

FUJINETWRITE
    STB MATHPTR0
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdWrite
    STA FUJINETPACKET_CMD
    LDB MATHPTR0
    STB FUJINETPACKET_DAT
    CLRA
    STa FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDB MATHPTR0
    TFR Y, X
    JSR SERIALWRITE

	RTS

; -------------------------------------------------------
; SET CHANNEL MODE ON FUJINET
; -------------------------------------------------------
; Input:    B = mode
; Output:

FUJINETSETCHANNELMODE
    STB MATHPTR0
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdSetChannelMode
    STA FUJINETPACKET_CMD
    LDB MATHPTR0
    STB FUJINETPACKET_DAT
    CLRA
    STa FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE
    RTS

; -------------------------------------------------------
; PARSE JSON ON FUJINET
; -------------------------------------------------------
; Input:    
; Output:

FUJINETPARSEJSON
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdParseJson
    STA FUJINETPACKET_CMD
    CLR FUJINETPACKET_DAT
    CLR FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    JSR FUJINETERROR

    RTS

; -------------------------------------------------------
; SET JSON QUERY ON FUJINET
; -------------------------------------------------------
; Input:    B = bytes to write
;           Y = address to write from
; Output:

FUJINETSETJSONQUERY
    STB MATHPTR0
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdQueryJson
    STA FUJINETPACKET_CMD
    CLR FUJINETPACKET_DAT
    CLR FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDB MATHPTR0
    TFR Y, X
    JSR SERIALWRITE

    CLRA
    LDB #256
    SUBB MATHPTR0
    JSR SERIALWRITECONST

    JSR FUJINETERROR

    RTS

; -------------------------------------------------------
; SEND LOGIN ON FUJINET
; -------------------------------------------------------
; Input:    B = bytes to write
;           Y = address to write from
; Output:

FUJINETLOGIN
    STB MATHPTR0
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdSetLogin
    STA FUJINETPACKET_CMD
    CLR FUJINETPACKET_DAT
    CLR FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDB MATHPTR0
    TFR Y, X
    JSR SERIALWRITE

    CLRA
    LDB #256
    SUBB MATHPTR0
    JSR SERIALWRITECONST

    RTS

; -------------------------------------------------------
; SEND PASSWORD ON FUJINET
; -------------------------------------------------------
; Input:    B = bytes to write
;           Y = address to write from
; Output:

FUJINETPASSWORD
    STB MATHPTR0
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdSetLogin
    STA FUJINETPACKET_CMD
    CLR FUJINETPACKET_DAT
    CLR FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDB MATHPTR0
    TFR Y, X
    JSR SERIALWRITE

    CLRA
    LDB #256
    SUBB MATHPTR0
    JSR SERIALWRITECONST

    RTS
