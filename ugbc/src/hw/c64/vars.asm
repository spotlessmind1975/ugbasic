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
;*                      INTERNAL VARIABLES FOR C64 TARGET                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTADDRESS:        .BYTE   0, $84
BITMAPADDRESS:      .WORD   $A000
COLORMAPADDRESS:       .BYTE   0, $D8
TABCOUNT:   .BYTE    4
XCURS:      .BYTE    0
YCURS:      .BYTE    0
LOCALWW:    .BYTE    3
EMPTYTILE:  .BYTE   32

TMPPTR = $22    ; $23
TMPPTR2 = $24    ; $25

MATHPTR0 = $FE
MATHPTR1 = $F7
MATHPTR2 = $F8
MATHPTR3 = $F9
MATHPTR4 = $FA
MATHPTR5 = $FB
MATHPTR6 = $FC
MATHPTR7 = $FD
MATHPTR8 = $FF

DSSTATUS = $20
DSSIZE = $21
DSADDRLO = $22
DSADDRHI = $23
DSBANKLO = $30
DSBANKHI = $31

COPYOFTEXTADDRESS = $25
COPYOFBITMAPADDRESS = $25
COPYOFCOLORMAPADDRESS = $29
COPYOFTEXTADDRESS2 = $27
COPYOFCOLORMAPADDRESS2 = $2B

DIRECTION = $20
CLINEY = $21