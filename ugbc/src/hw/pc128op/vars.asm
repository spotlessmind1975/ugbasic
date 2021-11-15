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
;*    INTERNAL VARIABLES FOR THOMSON MO6/OLIVETTI PRODEST PC128 TARGET         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTADDRESS         fdb     $0000
BITMAPADDRESS       fdb     $0000
COLORMAPADDRESS     fdb     $0000
MOBADDRESS          fdb     $a000
CURRENTMODE         fcb     $0
EVERYSTATUS        fcb     0

TABCOUNT            fcb     4
XCURS               fcb     0
YCURS               fcb     0
EMPTYTILE           fcb     $60

TMPPTR equ $10    ; $23
TMPPTR2 equ $12    ; $25

MATHPTR0 equ $14
MATHPTR1 equ $15
MATHPTR2 equ $16
MATHPTR3 equ $17
MATHPTR4 equ $18
MATHPTR5 equ $19
MATHPTR6 equ $1a
MATHPTR7 equ $1b
MATHPTR8 equ $1c
MATHPTRB0 equ $1d
MATHPTRB1 equ $1e
MATHPTRB2 equ $1f
MATHPTRB3 equ $20
MATHPTRB4 equ $21
MATHPTRB5 equ $22
MATHPTRB6 equ $23
MATHPTRB7 equ $24
MATHPTRB8 equ $25

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

XCURSYS fcb 0
YCURSYS fcb 0
