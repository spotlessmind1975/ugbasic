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
;*                          VERTICAL SCROLL ON VDC                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLLTUP:

    LD A, 24
    LD IXH, A
    CALL VDCZREAD
    OR $80
    LD IXL, A
    CALL VDCZWRITE

    LD A, 32
    LD IXH, A
    LD A, (TEXTADDRESS+1)
    LD IXL, A
    CALL VDCZWRITE
    LD A, 33
    LD IXH, A
    LD A, (TEXTADDRESS)
    LD E, A
    LD A, 0
    LD D, A
    ADD DE, 80
    LD A, E
    LD IXL, A
    CALL VDCZWRITE

    LD A, 18
    LD IXH, A
    LD A, (TEXTADDRESS+1)
    LD IXL, A
    CALL VDCZWRITE
    LD A, 19
    LD IXH, A
    LD A, (TEXTADDRESS)
    LD IXL, A
    CALL VDCZWRITE

    LD B, 24

VSCROLLTUPL1:
    LD A, 30
    LD IXH, A
    LD A, 80
    LD IXL, A
    CALL VDCZWRITE

    DEC B
    JR NZ, VSCROLLTUPL1

    LD A, 24
    LD IXH, A
    CALL VDCZREAD
    AND $7F
    LD IXL, A
    CALL VDCZWRITE

    LD A, 31
    LD IXH, A
    LD A, (EMPTYTILE)
    LD IXL, A
    CALL VDCZWRITE

    LD A, 30
    LD IXH, A
    LD A, 80
    LD IXL, A
    CALL VDCZWRITE

    LD A, 24
    LD IXH, A
    CALL VDCZREAD
    OR $80
    LD IXL, A
    CALL VDCZWRITE

    LD A, 32
    LD IXH, A
    LD A, (COLORMAPADDRESS+1)
    LD IXL, A
    CALL VDCZWRITE
    LD A, 33
    LD IXH, A
    LD A, (COLORMAPADDRESS)
    LD E, A
    LD A, 0
    LD D, A
    ADD DE, 80
    LD A, E
    LD IXL, A
    CALL VDCZWRITE

    LD A, 18
    LD IXH, A
    LD A, (COLORMAPADDRESS+1)
    LD IXL, A
    CALL VDCZWRITE
    LD A, 19
    LD IXH, A
    LD A, (COLORMAPADDRESS)
    LD IXL, A
    CALL VDCZWRITE

    LD B, 24

VSCROLLTUPL2:
    LD A, 30
    LD IXH, A
    LD A, 80
    LD IXL, A
    CALL VDCZWRITE

    DEC B
    JR NZ, VSCROLLTUPL2

    LD A, 24
    LD IXH, A
    CALL VDCZREAD
    AND $7F
    LD IXL, A
    CALL VDCZWRITE

    LD A, 31
    LD IXH, A
    LD A, (_PEN)
    OR $80
    LD IXL, A
    CALL VDCZWRITE

    LD A, 30
    LD IXH, A
    LD A, 80
    LD IXL, A
    CALL VDCZWRITE
    
    RET
