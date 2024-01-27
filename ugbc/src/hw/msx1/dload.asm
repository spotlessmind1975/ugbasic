; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                             DLOAD ROUTINE ON MSX1                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; HL: filename, B: filename length
; DE: address
MSX1DLOAD:

    CALL MSXCLEARFCB
    CALL MSXSETNAMEFCB
    LD A, $80
    LD (MSXFCB+MSXFCBS2), A

    PUSH DE
    LD C, _FOPEN
    LD DE, MSXFCB
    CALL $f37d
    LD DE, (MSXFCBFILSIZ)
    LD (MSXFILSIZ), DE
    POP DE

    CP 0
    JR NZ, MSX1DLOADERROR

    LD A, $80
    LD (MSXFCB+MSXFCBS2), A

MSX1DLOADL1:

    PUSH DE
    LD C, _RDSEQ
    LD DE, MSXFCB
    CALL $f37d
    POP DE

    CP 0
    JR NZ, MSX1DLOADDONE

    CALL MSXCOPYFROMDTA

    JP MSX1DLOADL1

MSX1DLOADDONE:

    PUSH DE
    LD C, _FCLOSE
    LD DE, MSXFCB
    CALL $f37d
    POP DE

    RET

MSX1DLOADERROR:
    LD (DLOADERR), A

    PUSH DE
    LD C, _FCLOSE
    LD DE, MSXFCB
    CALL $f37d
    POP DE

    RET


