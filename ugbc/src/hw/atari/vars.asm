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
;*                      INTERNAL VARIABLES FOR ATARI TARGET                    *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTADDRESS:        .WORD   $A000
BITMAPADDRESS:      .WORD   $A000
COLORMAPADDRESS:       .BYTE   0, $0
MOBADDRESS:         .WORD   $8000
EVERYSTATUS:         .BYTE   $00

TABCOUNT:   .BYTE    4
XCURS:      .BYTE    0
YCURS:      .BYTE    0
EMPTYTILE:  .BYTE   0
CURRENTMODE:    .BYTE   2
LASTCOLOR:      .BYTE   0

TMPPTR = $80    ; $81
TMPPTR2 = $82    ; $83

MATHPTR0 = $8B
MATHPTR1 = $84
MATHPTR2 = $85
MATHPTR3 = $86
MATHPTR4 = $87
MATHPTR5 = $88
MATHPTR6 = $89
MATHPTR7 = $8A

DSSTATUS = $8C
DSSIZE = $8D
DSADDRLO = $8E
DSADDRHI = $8F
DSBANKLO = $90
DSBANKHI = $91

COPYOFTEXTADDRESS = $a1
COPYOFBITMAPADDRESS = $a2
COPYOFCOLORMAPADDRESS = $a3
COPYOFTEXTADDRESS2 = $a4
COPYOFCOLORMAPADDRESS2 = $a5

DIRECTION = $92
CHARACTERS = $93
PATTERN = $92
CLINEX = $97
CLINEY = $98
BITSTOCONVERT = $94

XCURSYS = $A7
YCURSYS = $A8 ; $B2 for graphical modes!

KEYCODE2ATASCII: .BYTE 108,        106,        59,          0,          0,          107,        43,         42
                 .BYTE 111,         0,        112,        117,        155,        105,        45,         61
                 .BYTE 118,         0,          99,         0, 0, 98,         120,        122,        52
                 .BYTE 0,           51,         54,         27,         53,         50,         49,         44
                 .BYTE 32,          46,         110,        0, 109,        47,         0,          114,       0,  101
                 .BYTE 121,        127,        116,        119,        113,        57,    0
                 .BYTE 48,         55,         126,        56,         60,         62,         102,        104
                 .BYTE 100,        0,          0,          103,        115,        97,         76,         74
                 .BYTE 58,         75,         92,         94,         79,         80,         85,         155
                 .BYTE 73,         95,         124,        86,         67,         66,         88,         90
                 .BYTE 36,         35,         38,         27,         37,         34,         33,         91
                 .BYTE 32,         43,         78,         77,         63,         0,          82,         69
                 .BYTE 89,         159,        84,         87,         81,         40,         41,         39
                 .BYTE 156,        64,         125,        157,        70,         72,         68,         0
                 .BYTE 71,         83,         65
