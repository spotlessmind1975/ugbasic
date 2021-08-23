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

TEXTADDRESS         fdb     $0400
BITMAPADDRESS       fdb     $a000
COLORMAPADDRESS     fdb     $a000
MOBADDRESS          fdb     $a000
CURRENTMODE         fcb     $0

TABCOUNT            fcb     4
XCURS               fcb     0
YCURS               fcb     0
LOCALWW             fcb     3
EMPTYTILE           fcb     32

TMPPTR equ $22    ; $23
TMPPTR2 equ $24    ; $25

MATHPTR0 equ $F6
MATHPTR1 equ $F7
MATHPTR2 equ $F8
MATHPTR3 equ $F9
MATHPTR4 equ $FA
MATHPTR5 equ $FB
MATHPTR6 equ $FC
MATHPTR7 equ $FD
MATHPTR8 equ $FF

DSSTATUS equ $20
DSSIZE equ $21
DSADDRLO equ $22
DSADDRHI equ $23
DSBANKLO equ $30
DSBANKHI equ $31

COPYOFTEXTADDRESS equ $25
COPYOFBITMAPADDRESS equ $25
COPYOFCOLORMAPADDRESS equ $2F
COPYOFTEXTADDRESS2 equ $2D
COPYOFCOLORMAPADDRESS2 equ $2B

DIRECTION equ $20
PATTERN equ $20
CHARACTERS equ $25
CLINEX equ $32
CLINEY equ $33

BITSTOCONVERT equ $25

XCURSYS equ $D3
YCURSYS equ $D6
