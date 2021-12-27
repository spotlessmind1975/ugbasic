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
;*                      CLEAR LINE ROUTINE FOR TMS9918                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINE:
    LD HL,(TEXTADDRESS)
    LD (COPYOFTEXTADDRESS),HL
    LD HL,(COLORMAPADDRESS)
    LD (COPYOFCOLORMAPADDRESS),HL

    LD A, (CLINEY)
    CP 0
    JR Z,CLINESKIP
    LD B, A
    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0
CLINEL1:
    LD HL,(COPYOFTEXTADDRESS)
    ADD HL, DE
    LD (COPYOFTEXTADDRESS),HL

    DEC B
    JR NZ,CLINEL1

    LD A, (CLINEY)
    LD B, A
    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0
CLINELC1:
    LD HL,(COPYOFTEXTADDRESS)
    ADD HL, DE
    LD (COPYOFTEXTADDRESS),HL

    DEC B
    JR NZ,CLINELC1

CLINESKIP:
    LD A, (CHARACTERS)
    JR Z,CLINEENTIRE

    LD E, (CLINEX)
    LD D, 0

    LD HL,(COPYOFTEXTADDRESS)
    ADD HL, DE
    LD (COPYOFTEXTADDRESS),HL

    LD HL,(COPYOFCOLORMAPADDRESS)
    ADD HL, DE
    LD (COPYOFCOLORMAPADDRESS),HL

CLINEINCX:
    LD HL, (COPYOFTEXTADDRESS)
    LD A, (EMPTYTILE)
    LD (HL),A
    INC HL
    LD (COPYOFTEXTADDRESS), HL

    LD A, (CURRENTTILESWIDTH)
    LD B, A
    LD A, (CLINEX)
    INC A
    LD (CLINEX), A
    CMP B
    JR NZ, CLINENEXT

    LD A, 0
    LD (CLINEX), 0

    LD A, (CURRENTTILESHEIGHT)
    LD B, A
    LD A, (CLINEY)
    INC A
    LD (CLINEY), A

    CMP B
    JR NZ, CLINENEXT

    CALL VSCROLLTUP

    LD A, (CLINEY)
    DEC A
    LD (CLINEY), A

    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0

    LD HL,(COPYOFTEXTADDRESS)
    SUB HL, DE
    LD (COPYOFTEXTADDRESS),HL

    LD HL,(COPYOFCOLORMAPADDRESS)
    SUB HL, DE
    LD (COPYOFCOLORMAPADDRESS),HL

CLINENEXT:

    LD A, (CHARACTERS)
    DEC A
    LD (CHARACTERS), A

    JR NZ, CLINEINCX

    RET

CLINEENTIRE:
    LDY #0

CLINEINC2X:
    LD HL, (COPYOFTEXTADDRESS)
    LD A, (EMPTYTILE)
    LD (HL),A
    INC HL
    LD (COPYOFTEXTADDRESS), HL
        
    LD A, (CURRENTTILESWIDTH)
    LD B, A
    LD A, (CLINEX)
    INC A
    LD (CLINEX), A
    CMP B
    JR NZ, CLINEINC2X
    RET
