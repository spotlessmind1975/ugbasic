; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                        DISK COMMON ROUTINE ON ATARI                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

IOCB_OPEN           = $03       ; open
IOCB_GETREC         = $05       ; get record
IOCB_GETCHR         = $07       ; get character(s)
IOCB_PUTREC         = $09       ; put record
IOCB_PUTCHR         = $0B       ; put character(s)
IOCB_CLOSE          = $0C       ; close
IOCB_STATIS         = $0D       ; status
IOCB_SPECIL         = $0E       ; special
IOCB_DRAWLN         = $11       ; draw line
IOCB_FILLIN         = $12       ; draw line with right fill
IOCB_RENAME         = $20       ; rename disk file
IOCB_DELETE         = $21       ; delete disk file
IOCB_LOCKFL         = $23       ; lock file (set to read-only)
IOCB_UNLOCK         = $24       ; unlock file
IOCB_POINT          = $25       ; point sector
IOCB_NOTE           = $26       ; note sector
IOCB_GETFL          = $27       ; get file length
IOCB_CHDIR_MYDOS    = $29       ; change directory (MyDOS)
IOCB_MKDIR          = $2A       ; make directory (MyDOS/SpartaDOS)
IOCB_RMDIR          = $2B       ; remove directory (SpartaDOS)
IOCB_CHDIR_SPDOS    = $2C       ; change directory (SpartaDOS)
IOCB_GETCWD         = $30       ; get current directory (MyDOS/SpartaDOS)
IOCB_FORMAT         = $FE       ; format


IOCB                = $0340

ICHID               = $0340     ; DEVICE HANDLER IS (SET BY OS)
ICDNO               = $0341     ; DEVICE NUMBER (SET BY OS)
ICCOM               = $0342     ; I/O COMMAND
ICSTA               = $0343     ; I/O STATUS
ICBADRL             = $0344     ; BUFFER ADDRESS (LOW)
ICBADRH             = $0345     ; BUFFER ADDRESS (HIGH)
ICPUT               = $0346     ; DH PUT ROUTINE (ADR-1)
ICBLENL             = $0348     ; BUFFER LENGTH (LOW)
ICBLENH             = $0349     ; BUFFER LENGTH (HIGH)
ICAUX1              = $034A     ; AUX 1
ICAUX2              = $034B     ; AUX 2
ICAUX3              = $034C     ; AUX 3
ICAUX4              = $034D     ; AUX 4
ICAUX5              = $034E     ; AUX 5
ICAUX6              = $034F     ; AUX 6

CIOV                = $E456     ; JSR vector for CIO. All CIO operations go through this address

ATARIFILENAME:      .BYTE 'D', ':'
ATARIFILENAME0:     .RES 13,0

ATARIPREPAREFILENAME:
    LDA #<ATARIFILENAME0
    STA MATHPTR2
    LDA #>ATARIFILENAME0
    STA MATHPTR2+1

    LDY #0
ATARIPREPAREFILENAMEL1:
    LDA (TMPPTR), Y
    STA (MATHPTR2), Y
    INY
    CPY MATHPTR0
    BNE ATARIPREPAREFILENAMEL1
    LDA #$9B
    STA (MATHPTR2), Y
    RTS
