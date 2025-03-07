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
;*           SERIAL SUPPORT ON DRIVEWIRE ON TRS-80 COLOR COMPUTER              *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; SERIAL READY
; ----------------------------------------------------------------------------
; We call this routine to check if any data is available on DriveWire port
; using becker port emulation under emulator.
;
; Output:
;           Z  = data is available
;           NZ = data is unavailable
;
SERIALBISREADY
    LDA $FF41
    ANDA #$2
    CMPA #$2
    RTS

; ----------------------------------------------------------------------------
; SERIAL READ BYTE
; ----------------------------------------------------------------------------
; We call this routine to read the next byte from DriveWire port using becker 
; port emulation under emulator. If the byte is not available, the routine 
; will wait for the available data.
;
; Output:
;           A = data received from SERIAL port
;
SERIALBREADBYTE
    JSR SERIALBISREADY
    BNE SERIALBREADBYTE
    LDA $FF42
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
SERIALBWRITEBYTE
    STA $FF42
    RTS

; ----------------------------------------------------------------------------
; SERIAL WRITE
; ----------------------------------------------------------------------------
; We call this routine to write a string of bytes to DriveWire port using 
; becker port emulation under emulator.
;
; Input:
;           X = address of data to send
;           B = size of the data to send
; Output:
;           B = 0 is success, 0xff is failed
;

SERIALBWRITE
    LDA ,X+
    JSR SERIALBWRITEBYTE
    DECB
    BNE SERIALBWRITE
    LDB #0
    RTS

; ----------------------------------------------------------------------------
; SERIAL WRITE CONST
; ----------------------------------------------------------------------------
; We call this routine to write a sequence of the same byte to DriveWire port 
; using becker port emulation under emulator.
;
; Input:
;           A = value to write
;           B = size of the data to send
; Output:
;           B = 0 is success, 0xff is failed
;

SERIALBWRITECONST
    JSR SERIALBWRITEBYTE
    DECB
    BNE SERIALBWRITECONST
    RTS

; ----------------------------------------------------------------------------
; SERIAL READ
; ----------------------------------------------------------------------------
; We call this routine to read a sequence of bytes from DriveWire port 
; using becker port emulation under emulator.
;
; Input:
;           X = address of data to read to
;           B = size of the data to read

SERIALBREAD
    JSR SERIALBREADBYTE
    STA ,X+
    DECB
    BNE SERIALBREAD
    RTS

; ----------------------------------------------------------------------------
; ----------------------------------------------------------------------------
; ----------------------------------------------------------------------------

; ----------------------------------------------------------------------------
; SERIAL WRITE
; ----------------------------------------------------------------------------
; We call this routine to write a string of bytes to DriveWire port using 
; HDB-DOS, as the regular FujiNet integration.
;
; Input:
;           X = address of data to send
;           B = size of the data to send
; Output:
;           B = 0 is success, 0xff is failed
;

SERIALHWRITE
    ORCC #$50
    LDA RAMENABLED
    PSHS D
    CLR RAMENABLED
    STA $FFDE
    PSHS X, Y
    LDA #0
    TFR D, Y
    JSR [0xD941]
    PULS X, Y
    PULS D
    STA RAMENABLED
    BEQ SERIALHWRITEDONE2
    STA $FFDF
SERIALHWRITEDONE2
    TFR CC, B
    LSRB
    LSRB
    ANDB #$01
    BEQ SERIALHWRITEDONE
    LDB #$FF
SERIALHWRITEDONE
    ANDCC #$AF
    RTS

; ----------------------------------------------------------------------------
; SERIAL WRITE CONST
; ----------------------------------------------------------------------------
; We call this routine to write a sequence of the same byte to DriveWire port 
; using HDB-DOS, as the regular FujiNet integration.
;
; Input:
;           A = value to write
;           B = size of the data to send
; Output:
;           B = 0 is success, 0xff is failed
;
SERIALHWRITECONSTDATA
    fcb $00
SERIALHWRITECONST
    PSHS D
    STA SERIALHWRITECONSTDATA
    LDX #SERIALHWRITECONSTDATA
    LDB #1
    JSR SERIALHWRITE
    PULS D
    DECB
    BNE SERIALHWRITECONST
    RTS

; ----------------------------------------------------------------------------
; SERIAL READ
; ----------------------------------------------------------------------------
; We call this routine to read a sequence of bytes from DriveWire port 
; using HDB-DOS, as the regular FujiNet integration.
;
; Input:
;           X = address of data to read to
;           B = size of the data to read

SERIALHREAD
    ORCC #$50
    LDA RAMENABLED
    PSHS D
    CLR RAMENABLED
    STA $FFDE
    PSHS X, Y
    LDA #0
    TFR D, Y
    JSR [0xD93F]
    PULS X, Y

    PULS D
    STA RAMENABLED
    BEQ SERIALHREADDONE2
    STA $FFDF
SERIALHREADDONE2

    TFR CC, B
    LSRB
    LSRB
    ANDB #$01
    BEQ SERIALHREADDONE
    LDB #$FF
SERIALHREADDONE
    ANDCC #$AF
    RTS

; ----------------------------------------------------------------------------
; SERIAL READ BYTE
; ----------------------------------------------------------------------------
; We call this routine to read a byte from DriveWire port using HBD-DOS, as 
; the regular FujiNet integration.

SERIALHREADBYTEDATA
    fcb $00
SERIALHREADBYTE
    LDX #SERIALHREADBYTEDATA
    LDB #1
    JSR SERIALHREAD
    LDA SERIALHREADBYTEDATA
    RTS

SERIALREAD
    JMP SERIALBREAD

SERIALREADBYTE
    JMP SERIALBREADBYTE

SERIALWRITE
    JMP SERIALBWRITE

SERIALWRITECONST
    JMP SERIALBWRITECONST

SERIALDEFINEBECKERPORT
    LDD #SERIALBREAD
    STD (SERIALREAD+1)
    LDD #SERIALBREADBYTE
    STD (SERIALREADBYTE+1)
    LDD #SERIALBWRITE
    STD (SERIALWRITE+1)
    LDD #SERIALBWRITECONST
    STD (SERIALWRITECONST+1)
    RTS

SERIALDEFINEHDBDOS
    LDD #SERIALHREAD
    STD (SERIALREAD+1)
    LDD #SERIALHREADBYTE
    STD (SERIALREADBYTE+1)
    LDD #SERIALHWRITE
    STD (SERIALWRITE+1)
    LDD #SERIALHWRITECONST
    STD (SERIALWRITECONST+1)
    RTS
