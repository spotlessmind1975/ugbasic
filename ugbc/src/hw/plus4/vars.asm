; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                      INTERNAL VARIABLES FOR PLUS/4 TARGET                   *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTADDRESS:        .BYTE   0, $5c
BITMAPADDRESS:      .WORD   $6000
COLORMAPADDRESS:       .BYTE   0, $58
MOBADDRESS:         .WORD   $5C00

TABCOUNT:   .BYTE    4
XCURS:      .BYTE    0
YCURS:      .BYTE    0
LOCALWW:    .BYTE    3
EMPTYTILE:  .BYTE   32


TMPPTR = $22    ; $23
TMPPTR2 = $24    ; $25

MATHPTR0 = $D9
MATHPTR1 = $D0
MATHPTR2 = $D1
MATHPTR3 = $D2
MATHPTR4 = XCURSYS
MATHPTR5 = $D4
MATHPTR6 = $D5
MATHPTR7 = $D7
MATHPTR8 = $E0

DSSTATUS = $DA
DSSIZE = $DB
DSADDRLO = $DD
DSADDRHI = $DD
DSBANKLO = $DE
DSBANKHI = $DF

COPYOFTEXTADDRESS = $D9
COPYOFBITMAPADDRESS = $D9
COPYOFCOLORMAPADDRESS = $DB
COPYOFTEXTADDRESS2 = $DD
COPYOFCOLORMAPADDRESS2 = $DF

DIRECTION = $E0
CHARACTERS = $E0
PATTERN = $E0
CLINEX = $E1
CLINEY = $E2
BITSTOCONVERT = $E0

XCURSYS = $CA
YCURSYS = $CD
