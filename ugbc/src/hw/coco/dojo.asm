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
;*                     DOJO PROTOCOL ON TRS-80 COLOR COMPUTER                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DOJO_CMD_PING           EQU $00         ; PING
DOJO_CMD_LOGIN          EQU $01         ; LOGIN username password
DOJO_CMD_CREATE_PORT    EQU $02         ; CREATE PORT application sessionId
DOJO_CMD_DESTROY_PORT   EQU $03         ; DESTROY PORT portId
DOJO_CMD_FIND_PORT      EQU $04         ; FIND PORT username application sessionId
DOJO_CMD_PUT_MESSAGE    EQU $05         ; PUT MESSAGE message portId
DOJO_CMD_PEEK_MESSAGE   EQU $06         ; PEEK MESSAGE portId
DOJO_CMD_GET_MESSAGE    EQU $07         ; GET MESSAGE portId

    ALIGN 2
DOJOCURRENTID           FCB $0          ; Current packet ID

DOJOHELLOSTRING         FCB "****9910"

; ============================================================================
; DOJO PRIMITIVES
; ============================================================================

; ----------------------------------------------------------------------------
; DOJO READY
; ----------------------------------------------------------------------------
; We call this routine to check if any data is available from DOJO server.
;
; Output:
;           Z  = data is available
;           NZ = data is unavailable
;
DOJOISREADY
    LDA $FF41
    ANDA #$2
    CMPA #$2
    RTS

; ----------------------------------------------------------------------------
; DOJO READ BYTE
; ----------------------------------------------------------------------------
; We call this routine to read the next byte from DOJO server. If the byte
; is not available, the routine will wait for the available data.
;
; Output:
;           A = data received from DOJO server
;
DOJOREADBYTE
    JSR DOJOISREADY
    BNE DOJOREADBYTE
    LDA $FF42
    RTS

; ----------------------------------------------------------------------------
; DOJO WRITE BYTE
; ----------------------------------------------------------------------------
; We call this routine to write a byte to DOJO server.
;
; Input:
;           A = data to write to DOJO server
;
DOJOWRITEBYTE
    STA $FF42
    RTS

; ============================================================================
; DOJO PROTOCOL
; ============================================================================

; ----------------------------------------------------------------------------
; DOJO WAIT PACKET
; ----------------------------------------------------------------------------
; We call this routine to wait for a packet with the current ID.

DOJOWAITPACKET

    ; Read the ID of the packet

    JSR DOJOREADBYTE

    ; If the ID is equal to the one awaited for, go ahead.

    CMPA DOJOCURRENTID
    BEQ DOJOWAITPACKET0
    JSR DOJOSKIPPACKET

    ; Wait for the next packet.

    BRA DOJOWAITPACKET

DOJOWAITPACKET0
    RTS

; ----------------------------------------------------------------------------
; DOJO SKIP PACKET
; ----------------------------------------------------------------------------
; We call this routine to skip a packet that has a different ID from the
; one we are waiting for. Note that this routine must be called just after
; read the (wrong) ID.

DOJOSKIPPACKET

    ; Read the size of the packet to skip.

    JSR DOJOREADBYTE

    ; If size = 0 we can finish the execution.

    CMPA #0
    BEQ DOJOSKIPPACKET0

    ; Use the size as a counter.

    TFR A, B

    ; Read "size" bytes from the stream.

DOJOSKIPPACKETL1
    JSR DOJOREADBYTE
    DECB
    BNE DOJOSKIPPACKETL1

DOJOSKIPPACKET0
    RTS

; ============================================================================
; ============================================================================
; ============================================================================
; DOJO GAME PROTOCOL
; ============================================================================
; ============================================================================
; ============================================================================

; ----------------------------------------------------------------------------
; DOJO PING
; ----------------------------------------------------------------------------
; We call this routine to check if the server is alive.
;
; Input:
;
; Output:
;           C = server is alive
;          NC = server is gone
;

DOJOPING
    
    LDX #DOJOHELLOSTRING

    LDB #8

DOJOPINGL3
    LDA ,X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOPINGL3

DOJOPINGL3A
    JSR DOJOREADBYTE
    CMPA #$18
    BNE DOJOPINGL3A

    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_PING
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA #0
    JSR DOJOWRITEBYTE

    ; Wait response packet

    JSR DOJOWAITPACKET

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TFR A, B

    ; If the packet has size = 0, we finish

    CMPB #0
    BEQ DOJOPINGN1DE

    ; Read (and skip) any data

DOJOPINGL1
    JSR DOJOREADBYTE
    DECB
    BNE DOJOPINGL1
    ORCC #$01
    RTS

DOJOPINGN1DE
    ORCC #$01
    RTS

; ----------------------------------------------------------------------------
; DOJO LOGIN
; ----------------------------------------------------------------------------
; We call this routine to identify the user. This call will allow to 
; "read"/"write" anything on the shared space of this user.
;
; Input:
;           X = username
;           B = size of unique id name
;           Y = password
;           A = size of password
;
; Output:
;           U = address where to put the unique key access (8 bytes)
;

DOJOLOGIN
    
    PSHS Y
    PSHS D

    STA MATHPTR0
    ADDB MATHPTR0
    INCB
    STB MATHPTR0

    PULS D
    PSHS D
    
    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_LOGIN
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA MATHPTR0
    JSR DOJOWRITEBYTE

    ; Send username, letter by letter

DOJOLOGINL1
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOLOGINL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    PULS D
    PULS Y

    TFR Y, X
    TFR A, B

    ; Send password, letter by letter

DOJOLOGINL2
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOLOGINL2

    ; Retrieve the response.

DOJOLOGINL3

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOLOGINN1

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TFR A, B

    ; If the packet has size = 0, we finish with an error.

    CMPB #0
    BEQ DOJOLOGINN1DE

    ; Read the session ID (8 bytes)

    LDB #8

DOJOLOGINN1L1
    JSR DOJOREADBYTE
    STA ,U+
    DECB
    BNE DOJOLOGINN1L1

    RTS

DOJOLOGINN1DE
    LDY #0
    RTS

; ----------------------------------------------------------------------------
; DOJO SUCCESS
; ----------------------------------------------------------------------------
; We call this routine to check if the session id / port id is valid.
;
; Input:
;           X = session id / port id
;
; Output:
;           C = is valid
;          NC = is not valid
;

DOJOSUCCESS

    LDB #8

    ; Send username, letter by letter

DOJOSUCCESSL1
    
    LDA , X+
    BNE DOJOSUCCESSL1Y
    DECB
    BNE DOJOSUCCESSL1

    ANDCC #$FE
    RTS

DOJOSUCCESSL1Y
    
    ORCC #$01
    RTS

; ----------------------------------------------------------------------------
; DOJO CREATE PORT
; ----------------------------------------------------------------------------
; We call this routine to create a port for receiving messages from other
; applications.
;
; Input:
;           X = application name
;           B = size of application name
;           Y = session id (8 bytes)
;
; Output:
;           U = address where to put the port id (8 bytes)
;

DOJOCREATEPORT
    
    PSHS Y
    PSHS D

    ADDB #9
    STB MATHPTR0

    PULS D
    PSHS D
    
    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_CREATE_PORT
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA MATHPTR0
    JSR DOJOWRITEBYTE

    ; Send application name, letter by letter

DOJOCREATEPORTL1
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOCREATEPORTL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    PULS D
    PULS Y

    TFR Y, X
    LDB #8

    ; Send session id, letter by letter

DOJOCREATEPORTL2
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOCREATEPORTL2

    ; Retrieve the response.

DOJOCREATEPORTL3

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOCREATEPORTN1

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TFR A, B

    ; If the packet has size = 0, we finish with an error.

    CMPB #0
    BEQ DOJOCREATEPORTN1DE

    ; Read the port ID (8 bytes)

    LDB #8

DOJOCREATEPORTN1L1
    JSR DOJOREADBYTE
    STA ,U+
    DECB
    BNE DOJOCREATEPORTN1L1

    RTS

DOJOCREATEPORTN1DE
    LDY #0
    RTS

; ----------------------------------------------------------------------------
; DOJO DESTROY PORT
; ----------------------------------------------------------------------------
; We call this routine to destroy an existent port.
;
; Input:
;           X = port id
;
; Output:
;           C = port destroyed
;           NC = unexistent port
;

DOJODESTROYPORT
    
    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_DESTROY_PORT
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA #8
    JSR DOJOWRITEBYTE

    ; Send sessionId, letter by letter

    LDB #8

DOJODESTROYPORTL1
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJODESTROYPORTL1

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJODESTROYPORTN1

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TFR A, B

    ; If the packet has size = 0, we finish with an error.

    CMPB #0
    BEQ DOJODESTROYPORTN1DE

    ; Read the returned byte.

    JSR DOJOREADBYTE
    CMPB #0
    BEQ DOJODESTROYPORTN1DE

DOJODESTROYPORTN1L1
    ORCC #$01
    RTS

DOJODESTROYPORTN1DE
    ANDCC #$FE
    RTS

; ----------------------------------------------------------------------------
; DOJO FIND PORT
; ----------------------------------------------------------------------------
; We call this routine to find out a port for sending messages to other
; applications.
;
; Input:
;           X = address to username
;           B = size of username
;           Y = address to application
;           A = size of application
;           U = address of session id (8 bytes)
;
; Output:
;           -2,S = address of (public) port id (8 bytes)
;

DOJOFINDPORT
    
    PSHS D ; S = 4 (D, U)

    STA MATHPTR0
    ADDB MATHPTR0
    INCB
    INCB
    ADDB #8
    STB MATHPTR0

    ANDCC #$FE

    PULS D ; S = 2 (U)
    PSHS D ; S = 4 (D, U)
    
    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_FIND_PORT
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA MATHPTR0
    JSR DOJOWRITEBYTE

    ; Send username name, letter by letter

DOJOFINDPORTL1
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOFINDPORTL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    PULS D ; S = 2 (D, U)

    TFR Y, X
    TFR A, B

    ; Send application name, letter by letter

DOJOFINDPORTL2
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOFINDPORTL2

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    TFR U, X
    LDB #8

    ; Send session id, letter by letter

DOJOFINDPORTL3
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOFINDPORTL3

    ; Retrieve the response.

DOJOFINDPORTL4

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOFINDPORTN1

    LDU 2,S
    
    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TFR A, B

    ; If the packet has size = 0, we finish with an error.

    CMPB #0
    BEQ DOJOFINDPORTN1DE

    ; Read the (public) port ID (8 bytes)

    LDB #8

DOJOFINDPORTN1L1
    JSR DOJOREADBYTE
    STA ,U+
    DECB
    BNE DOJOFINDPORTN1L1

    RTS

DOJOFINDPORTN1DE
    LDY #0
    RTS

; ----------------------------------------------------------------------------
; DOJO PUT MESSAGE
; ----------------------------------------------------------------------------
; We call this routine to put a message to a port.
;
; Input:
;           X = address of message
;           B = size of message
;           Y = address of port id (8 bytes)
;
; Output:
;           C = message send
;          NC = message not sent
;

DOJOPUTMESSAGE
    
    PSHS D

    ADDB #9
    STB MATHPTR0

    PULS D
    PSHS D
    
    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_PUT_MESSAGE
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA MATHPTR0
    JSR DOJOWRITEBYTE

    ; Send message, letter by letter

DOJOPUTMESSAGEL1
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOPUTMESSAGEL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    PULS D

    TFR Y, X

    ; Send port id, letter by letter

    LDB #8

DOJOPUTMESSAGEL2
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOPUTMESSAGEL2

    ; Retrieve the response.

DOJOPUTMESSAGEL4

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOPUTMESSAGEN1

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TFR A, B

    ; If the packet has size = 0, we finish with an error.

    CMPB #0
    BEQ DOJOPUTMESSAGEN1DE

    ; Read the status byte

    JSR DOJOREADBYTE
    CMPA #0
    BEQ DOJOPUTMESSAGEN1DE

DOJOPUTMESSAGEN1L1
    ORCC #$01
    RTS

DOJOPUTMESSAGEN1DE
    ANDCC #$FE
    RTS

; ----------------------------------------------------------------------------
; DOJO PEEK MESSAGE
; ----------------------------------------------------------------------------
; We call this routine to peek the presence (and size of) next message
; that can be took using DOJO GET MESSAGE.
;
; Input:
;           Y = address of port id (8 bytes)
;
; Output:
;           B = size of message (if C = 1)
;           C = message present
;          NC = message absent

DOJOPEEKMESSAGE
    
    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_PEEK_MESSAGE
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA #8
    JSR DOJOWRITEBYTE

    TFR Y, X

    LDB #8

    ; Send port id, letter by letter

DOJOPEEKMESSAGEL1
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOPEEKMESSAGEL1

    ; Retrieve the response.

DOJOPEEKMESSAGEL4

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOPEEKMESSAGEN1

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TFR A, B

    ; If the packet has size = 0, we finish with an error.

    CMPB #0
    BEQ DOJOPEEKMESSAGEN1DE

    ; Read the message size byte

    JSR DOJOREADBYTE
    TFR A, B
    CMPA #0
    BEQ DOJOPEEKMESSAGEN1DE

DOJOPEEKMESSAGEN1L1
    ORCC #$01
    RTS

DOJOPEEKMESSAGEN1DE
    ANDCC #$FE
    RTS

; ----------------------------------------------------------------------------
; DOJO GET MESSAGE
; ----------------------------------------------------------------------------
; We call this routine to get the next message. It imply call DOJO PEEK 
; MESSAGE. 
;
; Input:
;           Y = address of port id (8 bytes)
;
; Output:
;           B = dynamic string index
;           C = message present
;          NC = message absent

DOJOGETMESSAGE
    
    JSR DOJOPEEKMESSAGE
    BCC DOJOGETMESSAGEN1DE

    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_GET_MESSAGE
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA #8
    JSR DOJOWRITEBYTE

    ; Send message, letter by letter

    LDB #8
    TFR Y, X

DOJOGETMESSAGEL1
    
    LDA , X+
    JSR DOJOWRITEBYTE
    DECB
    BNE DOJOGETMESSAGEL1

    ; Retrieve the response.

DOJOGETMESSAGEL4

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOGETMESSAGEN1

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TFR A, B

    ; If the packet has size = 0, we finish with an error.

    CMPB #0
    BEQ DOJOGETMESSAGEN1DE

    ; Allocate a dynamic string big enough
    ; to store the incoming message.

    JSR DSALLOC

    PSHS D

    ; Retrieve the address of the dynamic
    ; string space and use it as final
    ; storage space.

    JSR DSDESCRIPTOR
    LDD 1, X
    TFR D, Y
    LDB , X
    TFR Y, X

    ; Read the message size byte

DOJOGETMESSAGEL2
    JSR DOJOREADBYTE
    STA , X+
    DECB
    BNE DOJOGETMESSAGEL2
DOJOGETMESSAGEN1L1

    PULS D

    ORCC #$01
    RTS

DOJOGETMESSAGEN1DE
    LDA #0
    JSR DSALLOC
    ANDCC #$FE
    RTS

