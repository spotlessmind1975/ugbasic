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
;  * Unless r=ired by applicable law or agreed to in writing, software
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
;*                          FUJINET SUPPORT ON ATARI                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

fujiOpNet               =     $E3

fujiCmdReady            =     $00
fujiCmdResponse         =     $01
fujiCmdError            =     $2
fujiCmdOpen             =     'O'
fujiCmdClose            =     'C'
fujiCmdParseJson        =     'P'
fujiCmdQueryJson        =     'Q'
fujiCmdRead             =     'R'
fujiCmdStatus           =     'S'
fujiCmdWrite            =     'W'
fujiCmdSetChannelMode   =     $fc
fujiCmdSetLogin         =     $fd
fujiCmdSetPassword      =     $fe

; FUJINET PACKET STAGE AREA
; -------------------------
FUJINETPACKET:
    .BYTE fujiOpNet, $00, $00, $00, $00
FUJINETPACKET_DID       =     (FUJINETPACKET+1)
FUJINETPACKET_CMD       =     (FUJINETPACKET+2)
FUJINETPACKET_DAT       =     (FUJINETPACKET+3)

FUJINETDEVICEID:
    .BYTE $00
FUJINETBYTESWAITING:
    .WORD $0000
FUJINETCONNECTED:
    .BYTE $00
FUJINETERRORCODE:
    .BYTE $00

; -------------------------------------------------------
; WRITE A FUJINET PACKET ON SERIAL
; -------------------------------------------------------

FUJINETPACKETWRITE:
    LDA #<FUJINETPACKET
    STA TMPPTR
    LDA #>FUJINETPACKET
    STA TMPPTR+1
    LDA #5
    STA MATHPTR0
    JSR SERIALWRITE
    RTS    

; -------------------------------------------------------
; MAKE SURE THAT FUJINET NETWORK IS READY
; -------------------------------------------------------
; Input:    
; Output:   A = status

FUJINETREADY:
    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdReady
    STA FUJINETPACKET_CMD
    LDA #0
    STA FUJINETPACKET_DAT
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE
    JSR SERIALREADBYTE
    RTS

; -------------------------------------------------------
; READ THE LAST ERROR FROM FUJINET
; -------------------------------------------------------
; Input:    
; Output:   A = error code

FUJINETERROR:
    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdError
    STA FUJINETPACKET_CMD
    LDA #0
    STA FUJINETPACKET_DAT
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE
    JSR SERIALREADBYTE
    RTS

; -------------------------------------------------------
; READ A RESPONSE FROM FUJINET
; -------------------------------------------------------
; Input:    
;           MATHPTR2 = number of bytes to read
;           TMPPTR2 = destination address
; Output:

FUJINETGETRESPONSE:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdResponse
    STA FUJINETPACKET_CMD
    LDA MATHPTR2
    STA FUJINETPACKET_DAT
    LDA #0
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDA MATHPTR2
    STA MATHPTR0
    LDA TMPPTR2
    STA TMPPTR
    LDA TMPPTR2+1
    STA TMPPTR+1
    JSR SERIALREAD

    RTS

; -------------------------------------------------------
; OPEN A RESOURCE ON FUJINET
; -------------------------------------------------------
; Input:    
;           MATHPTR2 = number of bytes of url
;           TMPPTR2 = url
;           MATHPTR3 = mode (high) 
;           MATHPTR4 = trans (low)
; Output:

FUJINETOPEN:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdOpen
    STA FUJINETPACKET_CMD
    LDA MATHPTR3
    STA FUJINETPACKET_DAT
    LDA MATHPTR4
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDA MATHPTR2
    STA MATHPTR0
    LDA TMPPTR2
    STA TMPPTR
    LDA TMPPTR2+1
    STA TMPPTR+1
    JSR SERIALWRITE

    SEC
    LDA #00
    SBC MATHPTR2
    STA MATHPTR0
    LDA #0
    JSR SERIALWRITECONST

    JSR FUJINETREADY

    JSR FUJINETERROR

    RTS

; -------------------------------------------------------
; CLOSE A RESOURCE ON FUJINET
; -------------------------------------------------------
; Input:    
; Output:

FUJINETCLOSE:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdClose
    STA FUJINETPACKET_CMD
    LDA #0
    STA FUJINETPACKET_DAT
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE
    RTS
    
; -------------------------------------------------------
; GET STATUS FROM FUJINET 
; -------------------------------------------------------
; Input:    
; Output:

FUJINETGETSTATUS:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdStatus
    STA FUJINETPACKET_CMD
    LDA #0
    STA FUJINETPACKET_DAT
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE
 
    LDA #4
    STA MATHPTR2
    LDA #<FUJINETBYTESWAITING
    STA TMPPTR2
    LDA #>FUJINETBYTESWAITING
    STA TMPPTR2+1
    JSR FUJINETGETRESPONSE

    JSR FUJINETERROR

    RTS

; -------------------------------------------------------
; READ DATA FROM FUJINET CONNECTION
; -------------------------------------------------------
; Input:    MATHPTR2 = bytes to read
;           TMPPTR2 = address to read to
; Output:

FUJINETREAD:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdRead
    STA FUJINETPACKET_CMD
    LDA #0
    STA FUJINETPACKET_DAT
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDA MATHPTR2
    STA MATHPTR0
    LDA TMPPTR2
    STA TMPPTR
    LDA TMPPTR2+1
    STA TMPPTR+1
    JSR FUJINETGETRESPONSE

    RTS

; -------------------------------------------------------
; WRITE DATA TO FUJINET CONNECTION
; -------------------------------------------------------
; Input:    MATHPTR2 = bytes to write
;           TMPPTR2 = address to write from
; Output:

FUJINETWRITE:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdWrite
    STA FUJINETPACKET_CMD
    LDA MATHPTR2
    STA FUJINETPACKET_DAT
    LDA #0
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDA MATHPTR2
    STA MATHPTR0
    LDA TMPPTR2
    STA TMPPTR
    LDA TMPPTR2+1
    STA TMPPTR+1
    JSR SERIALWRITE

	RTS

; -------------------------------------------------------
; SET CHANNEL MODE ON FUJINET
; -------------------------------------------------------
; Input:    MATHPTR2 = mode
; Output:

FUJINETSETCHANNELMODE:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdSetChannelMode
    STA FUJINETPACKET_CMD
    LDA MATHPTR2
    STA FUJINETPACKET_DAT
    LDA #0
    STa FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE
    RTS

; -------------------------------------------------------
; PARSE JSON ON FUJINET
; -------------------------------------------------------
; Input:    
; Output:

FUJINETPARSEJSON:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdParseJson
    STA FUJINETPACKET_CMD
    LDA #0
    STA FUJINETPACKET_DAT
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    JSR FUJINETERROR

    RTS

; -------------------------------------------------------
; SET JSON QUERY ON FUJINET
; -------------------------------------------------------
; Input:    MATHPTR2 = bytes to write
;           TMPPTR2 = address to write from
; Output:

FUJINETSETJSONQUERY:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdQueryJson
    STA FUJINETPACKET_CMD
    LDA #0
    STA FUJINETPACKET_DAT
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDA MATHPTR2
    STA MATHPTR0
    LDA TMPPTR2
    STA TMPPTR
    LDA TMPPTR2+1
    STA TMPPTR+1
    JSR SERIALWRITE

    SEC
    LDA #00
    SBC MATHPTR2
    STA MATHPTR0
    LDA #0
    JSR SERIALWRITECONST

    JSR FUJINETERROR

    RTS

; -------------------------------------------------------
; SEND LOGIN ON FUJINET
; -------------------------------------------------------
; Input:    MATHPTR2 = bytes to write
;           TMPPTR2 = address to write from
; Output:

FUJINETLOGIN:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdSetLogin
    STA FUJINETPACKET_CMD
    LDA #0
    STA FUJINETPACKET_DAT
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDA MATHPTR2
    STA MATHPTR0
    LDA TMPPTR2
    STA TMPPTR
    LDA TMPPTR2+1
    STA TMPPTR+1
    JSR SERIALWRITE

    SEC
    LDA #00
    SBC MATHPTR2
    SBC MATHPTR2
    STA MATHPTR0
    LDA #0
    JSR SERIALWRITECONST

    RTS

; -------------------------------------------------------
; SEND PASSWORD ON FUJINET
; -------------------------------------------------------
; Input:    B = bytes to write
;           Y = address to write from
; Output:

FUJINETPASSWORD:
    JSR FUJINETREADY

    LDA FUJINETDEVICEID
    STA FUJINETPACKET_DID
    LDA #fujiCmdSetLogin
    STA FUJINETPACKET_CMD
    LDA #0
    STA FUJINETPACKET_DAT
    STA FUJINETPACKET_DAT+1
    JSR FUJINETPACKETWRITE

    LDA MATHPTR2
    STA MATHPTR0
    LDA TMPPTR2
    STA TMPPTR
    LDA TMPPTR2+1
    STA TMPPTR+1
    JSR SERIALWRITE

    SEC
    LDA #00
    SBC MATHPTR2
    SBC MATHPTR2
    STA MATHPTR0
    LDA #0
    JSR SERIALWRITECONST

    RTS
