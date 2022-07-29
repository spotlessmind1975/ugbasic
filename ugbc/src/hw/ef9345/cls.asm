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
;*                         CLEAR SCREEN ROUTINE FOR EF9345                     * 
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLS:

    LD D, REGISTER2
    LD E, 0
    CALL EF9345LIB  

    LD D, REGISTER3
    LD A, (_PEN)
    AND $07
    SLA A
    SLA A
    SLA A
    SLA A
    LD B, A
    LD A, (_PAPER)
    OR B
    LD E, A
    CALL EF9345LIB  

    LD B, $19
CLSL1:
    LD C, $28

    LD D, REGISTER7
    LD E, 0
    CALL EF9345LIB

    LD D, REGISTER6
    LD A, B
    DEC A
    CP 0
    JR Z, CLSL10Y
    ADD $07
CLSL10Y:
    LD E, A
    CALL EF9345LIB

CLSL2:

    LD D, REGISTER1
    LD A, (EMPTYTILE)
    LD E, A
    CALL EF9345LIB

    LD D, REGISTERE
    LD E, 1
    CALL EF9345LIB

    DEC     C
    JP      NZ, CLSL2
    DJNZ    CLSL1
    RET

