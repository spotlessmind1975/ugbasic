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
MOBADDRESS:         .WORD   $A000
CURRENTMODE:    .BYTE   0
EVERYSTATUS:        .BYTE   0

TABCOUNT:   .BYTE    4
XCURS:      .BYTE    0
YCURS:      .BYTE    0
EMPTYTILE:  .BYTE   32


TMPPTR = $71    ; $72
TMPPTR2 = $7E    ; $7F

MATHPTR0 = $68
MATHPTR1 = $69
MATHPTR2 = $6A
MATHPTR3 = $6B
MATHPTR4 = $6C
MATHPTR5 = $6D
MATHPTR6 = $6E
MATHPTR7 = $6F
MATHPTR8 = $70

DSSTATUS = $D0
DSSIZE = $D1
DSADDRLO = $D2
DSADDRHI = $D3
DSBANKLO = $D4
DSBANKHI = $D5

COPYOFTEXTADDRESS = $23
COPYOFBITMAPADDRESS = $25
COPYOFCOLORMAPADDRESS = $27
COPYOFTEXTADDRESS2 = $2A
COPYOFCOLORMAPADDRESS2 = $3B

DIRECTION = $52
CHARACTERS = $52
PATTERN = $52
CLINEX = $60
CLINEY = $62
BITSTOCONVERT = $52

XCURSYS = $64
YCURSYS = $66
