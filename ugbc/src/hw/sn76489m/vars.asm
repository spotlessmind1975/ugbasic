; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                      INTERNAL VARIABLES FOR SN-76489 HARfdbARE               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SN76489FREQTABLE
    fdb 255,		255,		255,		255,		255,		255,		255,		255,		255,		255
    fdb 255,		255,		255,		255,		255,		255,		255,		255,		255,		255
    fdb 255,		255,		255,        255,        255,        255,        255,        255,        255,        255
    fdb 255,        240,        227,        214,        202,        191,        180,        170,        160,        151
    fdb 143,        135,        127,        120,        113,        107,        101,        95,         90,         85
    fdb 80,         75,         71,         67,         63,         60,         56,         53,         50,         47
    fdb 45,         42,         40,         37,         35,         33,         31,         30,         28,         26
    fdb 25,         23,         22,         21,         20,         18,         17,         16,         15,         15
    fdb 14,         13,         12,         11,         11,         10,         10,         9,          8,          8
    fdb 7,          7,          7,          6,          6,          5,          5,          5,          5,          4
    fdb 4,          4,          3,          3,          3,          3,          3,          2,          2,          2
    fdb 2,          2,          2,          2,          1,          1,          1,          1,          1           
    
SN76489MUSICTYPE        fcb $0
SN76489MUSICREADY       fcb $0
SN76489BLOCKS           fdb $0
SN76489LASTBLOCK        fcb $0
SN76489MUSICLOOP        fcb $0

SN76489TMPPTR2          fdb $0
SN76489TMPPTR           fdb $0
SN76489TMPOFS           fdb $0
SN76489TMPLEN           fdb $0
SN76489JIFFIES          fdb $0

SN76489TMPPTR_BACKUP    fdb $0
SN76489LASTBLOCK_BACKUP fdb $0
SN76489BLOCKS_BACKUP    fdb $0
