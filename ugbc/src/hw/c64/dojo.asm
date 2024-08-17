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
;*                        DOJO PROTOCOL ON COMMODORE 64                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DOJO_CMD_PING           = $00         ; PING
DOJO_CMD_LOGIN          = $01         ; LOGIN username password
DOJO_CMD_CREATE_PORT    = $02         ; CREATE PORT application sessionId
DOJO_CMD_DESTROY_PORT   = $03         ; DESTROY PORT portId
DOJO_CMD_FIND_PORT      = $04         ; FIND PORT username application sessionId
DOJO_CMD_PUT_MESSAGE    = $05         ; PUT MESSAGE message portId
DOJO_CMD_PEEK_MESSAGE   = $06         ; PEEK MESSAGE portId
DOJO_CMD_GET_MESSAGE    = $07         ; GET MESSAGE portId

DOJOCURRENTID:          .BYTE $0          ; Current packet ID

DOJOHELLOSTRING:        .BYTE "**DP**10"

DOJOINITARGS:           .BYTE 08, 00

DOJOCHARACTER:          .BYTE $FF

DOJOCURRENTKAPTR:       .BYTE $0, $0
DOJOCURRENTKAPTR2:      .BYTE $0, $0

; ============================================================================
; DOJO PRIMITIVES
; ============================================================================


DOJOREADCHAR:

    PHA
    TXA
    PHA
    TYA
    PHA

    PHA
    LDA #$BD
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    LDA #2
    LDX #<DOJOINITARGS
    LDY #>DOJOINITARGS
    JSR SYSCALL

    LDA #$02
    LDX #$02
    LDY #$00
    PHA
    LDA #$BA
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    PHA
    LDA #$C0
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    LDX #$02
    PHA
    LDA #$C6
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

DOJOREADLOOP:
    PHA
    LDA #$CF
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    CMP #00
DOJOREADLOOPD:
    BEQ DOJOREADLOOP

    STA DOJOCHARACTER

    LDA #$02
    PHA
    LDA #$C3
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    PHA
    LDA #$CC
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    PLA
    TAY
    PLA
    TAX
    PLA

    RTS

DOJOWRITECHAR:

    PHA
    TXA
    PHA
    TYA
    PHA

    PHA
    LDA #$BD
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    LDA #2
    LDX #<DOJOINITARGS
    LDY #>DOJOINITARGS
    JSR SYSCALL

    LDA #$02
    LDX #$02
    LDY #$00
    PHA
    LDA #$BA
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    PHA
    LDA #$C0
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    LDX #$02
    PHA
    LDA #$C9
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

DOJOWRITELOOP:
    LDA DOJOCHARACTER
    PHA
    LDA #$D2
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    LDA #$02
    PHA
    LDA #$C3
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    PHA
    LDA #$CC
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    PLA
    TAY
    PLA
    TAX
    PLA

    RTS

; ----------------------------------------------------------------------------
; DOJO READY
; ----------------------------------------------------------------------------
; We call this routine to check if any data is available from DOJO server.
;
; Output:
;           Z  = data is available
;           NZ = data is unavailable
;
DOJOISREADY:
    LDA #$EA
    STA DOJOREADLOOPD
    STA DOJOREADLOOPD+1
    JSR DOJOREADCHAR
    CMP #0
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
DOJOREADBYTE:
    LDA #$F0
    STA DOJOREADLOOPD
    LDA #$ED
    STA DOJOREADLOOPD+1
    JSR DOJOREADCHAR
    LDA DOJOCHARACTER
    RTS

; ----------------------------------------------------------------------------
; DOJO WRITE BYTE
; ----------------------------------------------------------------------------
; We call this routine to write a byte to DOJO server.
;
; Input:
;           A = data to write to DOJO server
;
DOJOWRITEBYTE:
    STA DOJOCHARACTER
    JSR DOJOWRITECHAR
    RTS

; ============================================================================
; DOJO PROTOCOL
; ============================================================================

; ----------------------------------------------------------------------------
; DOJO WAIT PACKET
; ----------------------------------------------------------------------------
; We call this routine to wait for a packet with the current ID.

DOJOWAITPACKET:

    ; Read the ID of the packet

    JSR DOJOREADBYTE

    ; If the ID is equal to the one awaited for, go ahead.

    CMP DOJOCURRENTID
    BEQ DOJOWAITPACKET0
    JSR DOJOSKIPPACKET

    ; Wait for the next packet.

    JMP DOJOWAITPACKET

DOJOWAITPACKET0:
    RTS

; ----------------------------------------------------------------------------
; DOJO SKIP PACKET
; ----------------------------------------------------------------------------
; We call this routine to skip a packet that has a different ID from the
; one we are waiting for. Note that this routine must be called just after
; read the (wrong) ID.

DOJOSKIPPACKET:

    ; Read the size of the packet to skip.

    JSR DOJOREADBYTE

    ; If size = 0 we can finish the execution.

    CMP #0
    BEQ DOJOSKIPPACKET0

    ; Use the size as a counter.

    TAX

    ; Read "size" bytes from the stream.

DOJOSKIPPACKETL1:
    JSR DOJOREADBYTE
    DEX
    BNE DOJOSKIPPACKETL1

DOJOSKIPPACKET0:
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

DOJOPING:
    
    LDA #<DOJOHELLOSTRING
    STA TMPPTR
    LDA #>DOJOHELLOSTRING
    STA TMPPTR+1

    LDX #8
    LDY #0

DOJOPINGL3:
    LDA (TMPPTR),Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOPINGL3

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
    TAX

    ; If the packet has size = 0, we finish

    CPX #0
    BEQ DOJOPINGN1DE

    ; Read (and skip) any data

DOJOPINGL1:
    JSR DOJOREADBYTE
    DEX
    BNE DOJOPINGL1
    SEC
    RTS

DOJOPINGN1DE:
    SEC
    RTS

; ----------------------------------------------------------------------------
; DOJO LOGIN
; ----------------------------------------------------------------------------
; We call this routine to identify the user. This call will allow to 
; "read"/"write" anything on the shared space of this user.
;
; Input:
;           TMPPTR = username
;           X = size of username
;           TMPPTR2 = password
;           Y = size of password
;
; Output:
;           DOJOCURRENTKAPTR = the unique key access (8 bytes)
;

DOJOLOGIN:

    PHA

    STX MATHPTR0
    TYA
    CLC
    ADC MATHPTR0
    STA MATHPTR0
    INC MATHPTR0

    PLA

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

    TYA 
    PHA

    LDY #0

DOJOLOGINL1:
    
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOLOGINL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    ; Send password, letter by letter

    PLA
    TAX
    LDY #0

DOJOLOGINL2:
    
    LDA (TMPPTR2), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOLOGINL2

    ; Retrieve the response.

DOJOLOGINL3:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOLOGINN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJOLOGINN1DE

    ; Read the session ID (8 bytes)

    LDA DOJOCURRENTKAPTR
    STA TMPPTR
    LDA DOJOCURRENTKAPTR+1
    STA TMPPTR+1

    LDY #0

DOJOLOGINN1L1:
    JSR DOJOREADBYTE
    STA (TMPPTR), Y
    INY
    DEX
    BNE DOJOLOGINN1L1

    RTS

DOJOLOGINN1DE:
    RTS

; ----------------------------------------------------------------------------
; DOJO SUCCESS
; ----------------------------------------------------------------------------
; We call this routine to check if the session id / port id is valid.
;
; Input:
;           TMPPTR = session id / port id
;
; Output:
;           C = is valid
;          NC = is not valid
;

DOJOSUCCESS:

    LDX #8
    LDY #0

    ; Send username, letter by letter

DOJOSUCCESSL1:
    
    LDA (TMPPTR), Y
    BNE DOJOSUCCESSL1Y
    INY
    DEX
    BNE DOJOSUCCESSL1
    CLC
    RTS

DOJOSUCCESSL1Y:
    SEC
    RTS

; ----------------------------------------------------------------------------
; DOJO CREATE PORT
; ----------------------------------------------------------------------------
; We call this routine to create a port for receiving messages from other
; applications.
;
; Input:
;           TMPPTR = application name
;           X = size of application name
;           TMPPTR2 = session id (8 bytes)
;
; Output:
;           DOJOCURRENTKAPTR = address where to put the port id (8 bytes)
;

DOJOCREATEPORT:

    STX MATHPTR0
    LDA MATHPTR0
    CLC
    ADC #9
    STA MATHPTR0

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

    LDY #0    

DOJOCREATEPORTL1:
    
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOCREATEPORTL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    LDA DOJOCURRENTKAPTR
    STA TMPPTR
    LDA DOJOCURRENTKAPTR+1
    STA TMPPTR+1

    LDX #8

    ; Send session id, letter by letter

    LDY #0

DOJOCREATEPORTL2:
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOCREATEPORTL2

    ; Retrieve the response.

DOJOCREATEPORTL3:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOCREATEPORTN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJOCREATEPORTN1DE

    ; Read the port ID (8 bytes)

    LDY #0

DOJOCREATEPORTN1L1:
    JSR DOJOREADBYTE
    STA (TMPPTR), Y
    INY
    DEX
    BNE DOJOCREATEPORTN1L1

    RTS

DOJOCREATEPORTN1DE:
    RTS

; ----------------------------------------------------------------------------
; DOJO DESTROY PORT
; ----------------------------------------------------------------------------
; We call this routine to destroy an existent port.
;
; Input:
;           TMPPTR = port id
;
; Output:
;           C = port destroyed
;           NC = unexistent port
;

DOJODESTROYPORT:
    
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

    LDX #8
    LDY #0

DOJODESTROYPORTL1:
    
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJODESTROYPORTL1

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJODESTROYPORTN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJODESTROYPORTN1DE

    ; Read the returned byte.

    JSR DOJOREADBYTE
    CMP #0
    BEQ DOJODESTROYPORTN1DE

DOJODESTROYPORTN1L1:
    SEC
    RTS

DOJODESTROYPORTN1DE:
    CLC
    RTS

; ----------------------------------------------------------------------------
; DOJO FIND PORT
; ----------------------------------------------------------------------------
; We call this routine to find out a port for sending messages to other
; applications.
;
; Input:
;           TMPPTR = address to username
;           X = size of username
;           TMPPTR2 = address to application
;           Y = size of application
;           DOJOCURRENTPTR = address of session id (8 bytes)
;
; Output:
;           DOJOCURRENTPTR2 = address of (public) port id (8 bytes)
;

DOJOFINDPORT:

    STX MATHPTR0
    TYA
    CLC
    ADC MATHPTR0
    STA MATHPTR0
    LDA #10
    ADC MATHPTR0
    STA MATHPTR0

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

    TYA
    PHA

    LDY #0
DOJOFINDPORTL1:
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOFINDPORTL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    PLA
    TAX

    ; Send application name, letter by letter

    LDY #0
DOJOFINDPORTL2:
    LDA (TMPPTR2), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOFINDPORTL2

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    LDA DOJOCURRENTKAPTR
    STA TMPPTR
    LDA DOJOCURRENTKAPTR+1
    STA TMPPTR+1

    LDX #8

    ; Send session id, letter by letter
    LDY #0
DOJOFINDPORTL3:
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOFINDPORTL3

    ; Retrieve the response.

DOJOFINDPORTL4:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOFINDPORTN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJOFINDPORTN1DE

    LDA DOJOCURRENTKAPTR2
    STA TMPPTR
    LDA DOJOCURRENTKAPTR2+1
    STA TMPPTR+1
    
    ; Read the (public) port ID (8 bytes)

    LDX #8
    LDY #0

DOJOFINDPORTN1L1:
    JSR DOJOREADBYTE
    STA (TMPPTR), Y
    INY
    DEX
    BNE DOJOFINDPORTN1L1

    RTS

DOJOFINDPORTN1DE:
    RTS

; ----------------------------------------------------------------------------
; DOJO PUT MESSAGE
; ----------------------------------------------------------------------------
; We call this routine to put a message to a port.
;
; Input:
;           TMPPTR = address of message
;           X = size of message
;           TMPPTR2 = address of port id (8 bytes)
;
; Output:
;           C = message send
;          NC = message not sent
;

DOJOPUTMESSAGE:

    STX MATHPTR0
    LDA #9
    CLC
    ADC MATHPTR0
    STA MATHPTR0

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

    LDY #0

DOJOPUTMESSAGEL1:
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOPUTMESSAGEL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    ; Send port id, letter by letter

    LDX #8
    LDY #0

DOJOPUTMESSAGEL2:
    LDA (TMPPTR2), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOPUTMESSAGEL2

    ; Retrieve the response.

DOJOPUTMESSAGEL4:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOPUTMESSAGEN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJOPUTMESSAGEN1DE

    ; Read the status byte

    JSR DOJOREADBYTE
    CMP #0
    BEQ DOJOPUTMESSAGEN1DE

DOJOPUTMESSAGEN1L1:
    SEC
    RTS

DOJOPUTMESSAGEN1DE:
    CLC
    RTS

; ----------------------------------------------------------------------------
; DOJO PEEK MESSAGE
; ----------------------------------------------------------------------------
; We call this routine to peek the presence (and size of) next message
; that can be took using DOJO GET MESSAGE.
;
; Input:
;           TMPPTR = address of port id (8 bytes)
;
; Output:
;           X = size of message (if C = 1)
;           C = message present
;          NC = message absent

DOJOPEEKMESSAGE:
    
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

    LDX #8

    ; Send port id, letter by letter

DOJOPEEKMESSAGEL1:
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOPEEKMESSAGEL1

    ; Retrieve the response.

DOJOPEEKMESSAGEL4:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOPEEKMESSAGEN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJOPEEKMESSAGEN1DE

    ; Read the message size byte

    JSR DOJOREADBYTE
    TAX
    CPX #0
    BEQ DOJOPEEKMESSAGEN1DE

DOJOPEEKMESSAGEN1L1:
    SEC
    RTS

DOJOPEEKMESSAGEN1DE:
    CLC
    RTS

; ----------------------------------------------------------------------------
; DOJO GET MESSAGE
; ----------------------------------------------------------------------------
; We call this routine to get the next message. It imply call DOJO PEEK 
; MESSAGE. 
;
; Input:
;           TMPPTR = address of port id (8 bytes)
;
; Output:
;           X = dynamic string index
;           C = message present
;          NC = message absent

DOJOGETMESSAGE:
    
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

    LDX #8
    LDY #0

DOJOGETMESSAGEL1:
    
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOGETMESSAGEL1

    ; Retrieve the response.

DOJOGETMESSAGEL4:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOGETMESSAGEN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE

    ; If the packet has size = 0, we finish with an error.

    CMP #0
    BEQ DOJOGETMESSAGEN1DE

    ; Allocate a dynamic string big enough
    ; to store the incoming message.

    STA DSSIZE
    JSR DSALLOC

    ; Retrieve the address of the dynamic
    ; string space and use it as final
    ; storage space.

    JSR DSDESCRIPTOR
    LDA DSADDRLO
    STA TMPPTR2
    LDA DSADDRHI
    STA TMPPTR2+1

    TXA
    PHA

    ; Read the message size byte

    LDX DSSIZE
    LDY #0

DOJOGETMESSAGEL2:
    JSR DOJOREADBYTE
    STA (TMPPTR), Y
    INY
    DEX
    BNE DOJOGETMESSAGEL2
DOJOGETMESSAGEN1L1:

    PLA
    TAX

    SEC
    RTS

DOJOGETMESSAGEN1DE:
    LDA #0
    STA DSSIZE
    JSR DSALLOC
    CLC
    RTS

