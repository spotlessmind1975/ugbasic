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
; We call this routine to check if any data is available on DriveWire port.
;
; Output:
;           Z  = data is available
;           NZ = data is unavailable
;
SERIALISREADY
    LDA $FF41
    ANDA #$2
    CMPA #$2
    RTS

; ----------------------------------------------------------------------------
; SERIAL READ BYTE
; ----------------------------------------------------------------------------
; We call this routine to read the next byte from serial port. If the byte
; is not available, the routine will wait for the available data.
;
; Output:
;           A = data received from SERIAL port
;
SERIALREADBYTE
    JSR SERIALISREADY
    BNE SERIALREADBYTE
    LDA $FF42
    RTS

; ----------------------------------------------------------------------------
; SERIAL WRITE BYTE
; ----------------------------------------------------------------------------
; We call this routine to write a byte to serial port.
;
; Input:
;           A = data to write to SERIAL server
;
SERIALWRITEBYTE
    STA $FF42
    RTS

; ----------------------------------------------------------------------------
; SERIAL WRITE
; ----------------------------------------------------------------------------
;
; Input:
;           X = address of data to send
;           B = size of the data to send
; Output:
;           B = 0 is success, 0xff is failed
;

SERIALWRITE
    LDA ,X+
    JSR SERIALWRITEBYTE
    DECB
    BNE SERIALWRITE
    LDB #0
    RTS

; ----------------------------------------------------------------------------
; SERIAL WRITE CONST
; ----------------------------------------------------------------------------
;
; Input:
;           A = value to write
;           B = size of the data to send
; Output:
;           B = 0 is success, 0xff is failed
;

SERIALWRITECONST
    JSR SERIALWRITEBYTE
    DECB
    BNE SERIALWRITECONST
    RTS

; ----------------------------------------------------------------------------
; SERIAL READ
; ----------------------------------------------------------------------------
;
; Input:
;           X = address of data to read to
;           B = size of the data to read

SERIALREAD
    JSR SERIALREADBYTE
    STA ,X+
    DECB
    BNE SERIALREAD
    RTS

