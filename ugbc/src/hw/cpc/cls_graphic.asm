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
;*                      CLEAR SCREEN ROUTINE FOR TMS9918 (graphic mode)        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLSG:
    LD A, (CURRENTMODE)
    CP 0
    JR Z, CLSG0
    CP 1
    JR Z, CLSG1
    CP 2
    JR Z, CLSG2
    CP 3
    JR Z, CLSG3    
    RET

CLSG0:
    LD A, (_PAPER)
    SRL A
    SRL A
    SRL A
    SRL A
    LD B, A
    LD A, (_PAPER)
    OR B
    JP CLSX

CLSG1:
CLSG3:
    LD A, (_PAPER)
    SRL A
    SRL A
    LD B, A
    LD A, (_PAPER)
    OR B
    SRL A
    SRL A
    LD B, A
    LD A, (_PAPER)
    OR B
    SRL A
    SRL A
    LD B, A
    LD A, (_PAPER)
    OR B
    SRL A
    SRL A
    JP CLSX

CLSG2:
    LD A, (_PAPER)
    SRL A
    LD B, A
    LD A, (_PAPER)
    OR B
    SRL A
    LD B, A
    LD A, (_PAPER)
    OR B
    SRL A
    LD B, A
    LD A, (_PAPER)
    OR B
    SRL A
    JP CLSX

CLSX:
    LD HL, $C000
    LD (HL), A
    LD E, L
    LD D, H
    INC DE
    LD BC, $3FFF
    LDIR
    RET