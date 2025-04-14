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
;*                        DISK COMMON ROUTINE ON ATARI                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DCOM_FNAME         = $80    ; $81
DCOM_FNAME_SIZE    = $84
DCOM_SIZE          = $88; $89
DCOM_ADDRESS       = $82    ; $83
DCOM_FROM          = $8A; $8B
DCOM_TEMP          = $86; $87

ATARIFILENAME:      .BYTE 'D', ':'
ATARIFILENAME0:     .RES 13,0

ATARIPREPAREFILENAME:
    LDA #<ATARIFILENAME0
    STA DCOM_TEMP
    LDA #>ATARIFILENAME0
    STA DCOM_TEMP+1

    LDY #0
ATARIPREPAREFILENAMEL1:
    LDA (DCOM_FNAME), Y
    STA (DCOM_TEMP), Y
    INY
    CPY DCOM_FNAME_SIZE
    BNE ATARIPREPAREFILENAMEL1
    LDA #$9B
    STA (DCOM_TEMP), Y
    RTS
