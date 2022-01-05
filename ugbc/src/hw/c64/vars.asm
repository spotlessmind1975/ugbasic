; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                      INTERNAL VARIABLES FOR C64 TARGET                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTADDRESS:        .BYTE   0, $84
BITMAPADDRESS:      .WORD   $A000
COLORMAPADDRESS:       .BYTE   0, $D8
MOBADDRESS:         .WORD   $8C00
CURRENTMODE:    .BYTE   0
EVERYSTATUS:    .BYTE   0

TABCOUNT:   .BYTE    4
XCURS:      .BYTE    0
YCURS:      .BYTE    0
EMPTYTILE:  .BYTE   32

TMPPTR = $22    ; $23
TMPPTR2 = $24    ; $25

MATHPTR0 = $F7
MATHPTR1 = $F8
MATHPTR2 = $F9
MATHPTR3 = $FA
MATHPTR4 = $FB
MATHPTR5 = $FC
MATHPTR6 = $FD
MATHPTR7 = $FE
MATHPTR8 = $FF

DSSTATUS = $32
DSSIZE = $21
DSADDRLO = $22
DSADDRHI = $23
DSBANKLO = $30
DSBANKHI = $31

COPYOFTEXTADDRESS = $25
COPYOFBITMAPADDRESS = $25
COPYOFCOLORMAPADDRESS = $2F
COPYOFTEXTADDRESS2 = $2D
COPYOFCOLORMAPADDRESS2 = $2B

DIRECTION = $32
PATTERN = $32
CHARACTERS = $25
CLINEX = $32
CLINEY = $33

BITSTOCONVERT = $25

XCURSYS = $D3
YCURSYS = $D6
