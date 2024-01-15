; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;*                         COMMON DISK ROUTINE ON MSX1                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

MSXFCB:
MSXFCBDRIVE:    DEFB        $0
MSXFCBFNAME:    DEFS        8
MSXFCBFEXT:     DEFS        3
MSXFCBEX:       DEFB        0
MSXFCBS1:       DEFB        0
MSXFCBS2:       DEFB        0
MSXFCBRC:       DEFB        0
MSXFCBFILSIZ:   DEFW        0, 0
MSXFCBDATE:     DEFW        0
MSXFCBTIME:     DEFW        0
MSXFCBDEVID:    DEFB        0
MSXFCBDIRLOC:   DEFB        0
MSXFCBSTRCLS:   DEFW        0
MSXFCBCLRCLS:   DEFW        0
MSXFCBCLSOFF:   DEFW        0
MSXFCBCR:       DEFB        0
MSXFCBRN:       DEFW        0, 0
MSXFCBE:

MSXFILSIZ:      DEFW        0

_FOPEN          =           $0F
_FCLOSE         =           $10
_FCREAT         =           $16
_RDSEQ          =           $14
_WRSEQ          =           $15

MSXCLEARFCB:
    PUSH AF
    PUSH BC
    PUSH DE
    LD A, 0
    LD DE, MSXFCB
    LD C, MSXFCBE-MSXFCB
MSXCLEARFCBL1:
    LD (DE), A
    INC DE
    DEC C
    JR NZ, MSXCLEARFCBL1
    LD A, $20
    LD DE, MSXFCBFNAME
    LD C, 11
MSXCLEARFCBL1FN:
    LD (DE), A
    INC DE
    DEC C
    JR NZ, MSXCLEARFCBL1FN
    POP DE
    POP BC
    POP AF
    RET

MSXSETNAMEFCB:
    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    LD A, B
    LD C, B
    LD B, 8
    LD DE, MSXFCBFNAME
MSXSETNAMEFCBL1:
    LD A, (HL)
    CP '.'
    JR Z, MSXSETNAMEFCBL1E
    LD (DE), A
    INC DE
    INC HL
    DEC C
    JR Z, MSXSETNAMEFCBDONE
    DEC B
    JR Z, MSXSETNAMEFCBDONE
    JP MSXSETNAMEFCBL1
MSXSETNAMEFCBL1E:
    DEC C
    INC HL
    LD B, 3
    LD DE, MSXFCBFEXT
MSXSETNAMEFCBL2:
    LD A, (HL)
    LD (DE), A
    INC DE
    INC HL
    DEC C
    JR Z, MSXSETNAMEFCBDONE
    DEC B
    JR Z, MSXSETNAMEFCBDONE
    JP MSXSETNAMEFCBL2
MSXSETNAMEFCBDONE:
    POP HL
    POP DE
    POP BC
    POP AF
    RET

MSXCOPYFROMDTA:
    LD HL, ($f23d)
    LD C, 128
MSXCOPYFROMDTAL1:
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    PUSH BC
    LD BC, (MSXFILSIZ)
    DEC BC
    LD (MSXFILSIZ), BC
    LD A, B
    OR C
    POP BC
    CP 0
    JR Z, MSXCOPYFROMDTAL1DONE
    DEC C
    JR NZ, MSXCOPYFROMDTAL1
MSXCOPYFROMDTAL1DONE:
    RET

MSXCOPYTODTA:
    LD HL, ($f23d)
    LD C, 128
MSXCOPYTODTAL1:
    LD A, (DE)
    LD (HL), A
    INC HL
    INC DE
    PUSH BC
    LD BC, (MSXFILSIZ)
    DEC BC
    LD (MSXFILSIZ), BC
    LD A, B
    OR C
    POP BC
    CP 0
    JR Z, MSXCOPYTODTAL1DONE
    DEC C
    JR NZ, MSXCOPYTODTAL1
MSXCOPYTODTAL1DONE:
    RET
