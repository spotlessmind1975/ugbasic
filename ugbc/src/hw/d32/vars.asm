; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                      INTERNAL VARIABLES FOR DRAGON 32/64 TARGET             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTADDRESS         fdb     $0400
BITMAPADDRESS       fdb     $0c00
COLORMAPADDRESS     fdb     $a000
CURRENTMODE         fcb     $2
CURRENTTILEMODE     fcb     1
EVERYSTATUS        fcb     0

TABCOUNT            fcb     4
XCURS               fcb     0
YCURS               fcb     0
EMPTYTILE           fcb     $60
KBDRATE             fcb     16

DRGTIMER            fdb     $0
DRGTIMER2           fdb     $0
TICKSPERSECOND      fcb     $0

TMPPTR equ $10    ; $23
TMPPTR2 equ $12    ; $25

MATHPTR0 equ $14
MATHPTR1 equ $15
MATHPTR2 equ $16
MATHPTR3 equ $17
MATHPTR4 equ $18
MATHPTR5 equ $19
MATHPTR6 equ $20
MATHPTR7 equ $21
MATHPTR8 equ $22
MATHPTRB0 equ $23
MATHPTRB1 equ $24
MATHPTRB2 equ $25
MATHPTRB3 equ $26
MATHPTRB4 equ $27
MATHPTRB5 equ $28
MATHPTRB6 equ $29
MATHPTRB7 equ $2a
MATHPTRB8 equ $2b

DSSTATUS equ $3b
DSSIZE equ $3c
DSADDRLO equ $3d
DSADDRHI equ $3e
DSBANKLO equ $3f
DSBANKHI equ $40

COPYOFTEXTADDRESS equ $41
COPYOFBITMAPADDRESS equ $43
COPYOFCOLORMAPADDRESS equ $45
COPYOFTEXTADDRESS2 equ $47
COPYOFCOLORMAPADDRESS2 equ $49

DIRECTION equ $4a
PATTERN equ $4a
CHARACTERS equ $4a
CLINEX equ $4b
CLINEY equ $4c

BITSTOCONVERT equ $4a

XCURSYS equ $D3
YCURSYS equ $D6

BANKSHADOW fcb  0
