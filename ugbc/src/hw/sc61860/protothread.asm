; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                               PROTOTHREADING                                *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PROTOTHREADVOID:
    RTN

; ------------------------------------------------------------------------------
; PROTOTHREADADDRESS
;       Input: I = thread number
;       Output: X = address for thread, Y = address for thread
;       Saves:
; ------------------------------------------------------------------------------

PROTOTHREADADDRESS:
    LIA PROTOTHREADLOOP
    LIP 4
    EXAM
    LIA >PROTOTHREADLOOP
    LIP 5
    EXAM
    LIA 0
    EXAB
    LIA 3
    ADB
    LIP 0
    LDM
    CPIA 0
    JRZP PROTOTHREADADDRESSL0
PROTOTHREADADDRESSL1:
    ADB
    DECI
    JRNZM PROTOTHREADADDRESSL1
PROTOTHREADADDRESSL0:
    LIP 4
    LDM
    LIP 6
    EXAM
    LIP 5
    LDM
    LIP 7
    EXAM
    RTN

; ------------------------------------------------------------------------------
; PROTOTHREADREGAT
;       Input: $0c-$0d = address of routine, I = thread number
;       Output:
;       Saves:
; ------------------------------------------------------------------------------

PROTOTHREADREGAT:
    CALL PROTOTHREADADDRESS
    DY

    LIP 0x0c
    EXAM
    IYS
    LIP 0x0d
    EXAM
    IYS

    RTN

; ------------------------------------------------------------------------------
; PROTOTHREADGETADDRESS
;       Input: I = thread number
;       Output: $0c-$0d = address of routine
;       Saves:
; ------------------------------------------------------------------------------

PROTOTHREADGETADDRESS:
    CALL PROTOTHREADADDRESS
    DX
    IXL
    LIP 0x0c
    EXAM
    IXL
    LIP 0x0d
    EXAM
    RTN

; ------------------------------------------------------------------------------
; PROTOTHREADREG
;       Input: $0c-$0d = address of routine
;       Output: I = thread number
;       Saves:
; ------------------------------------------------------------------------------

PROTOTHREADREG:
    LIDP PROTOTHREADCOUNT
    LDD
    LIP 0
    EXAM
    DECI
PROTOTHREADREGL1:
    CALL PROTOTHREADADDRESS
    DX
    IXL
    LIP 1
    EXAM
    LIA PROTOTHREADVOID
    CPMA
    JRNZP PROTOTHREADREGW
    IXL
    EXAM
    LIA >PROTOTHREADVOID
    CPMA
    JRNZP PROTOTHREADREGW
    LIP 0x0c
    EXAM
    IYS
    LIP 0x0d
    EXAM
    IYS
    RTN
PROTOTHREADREGW:
    DECI
    EXAM
    CPIA 0Xff
    JRNZM PROTOTHREADREGL1

; ------------------------------------------------------------------------------
; PROTOTHREADUNREG
;       Input: I = thread number
;       Output:
;       Saves:
; ------------------------------------------------------------------------------

PROTOTHREADUNREG:
    LIA PROTOTHREADVOID
    LIP 0x0c
    EXAM
    LIA >PROTOTHREADVOID
    LIP 0x0c
    EXAM
    CALL PROTOTHREADREGAT
    RTN

; ------------------------------------------------------------------------------
; PROTOTHREADSAVE
;       Input: I = thread number, J = step
;       Output:
;       Saves:
; ------------------------------------------------------------------------------

PROTOTHREADSAVE:
    LIA PROTOTHREADLC
    LIP 6
    EXAM
    LIA >PROTOTHREADLC
    LIP 7
    EXAM
    LIP 0
    EXAM
    LIB 0
    LIP 6
    ADB
    DY
    LIP 1
    EXAM
    IYS
    RTN

; ------------------------------------------------------------------------------
; PROTOTHREADRESTORE
;       Input: I = thread number
;       Output: J = step
;       Saves:
; ------------------------------------------------------------------------------

PROTOTHREADRESTORE:
    LIA PROTOTHREADLC
    LIP 4
    EXAM
    LIA >PROTOTHREADLC
    LIP 5
    EXAM
    CPIA 0
    EXAM
    LIB 0
    LIP 4
    ADB
    DX
    IXL
    LIP 1
    EXAM
    RTN

; ------------------------------------------------------------------------------
; PROTOTHREADSETSTATE
;       Input: I = thread number, J = state
;       Output: 
;       Saves:
; ------------------------------------------------------------------------------

PROTOTHREADSETSTATE:
    LIA PROTOTHREADST
    LIP 6
    EXAM
    LIA >PROTOTHREADST
    LIP 7
    EXAM
    LIP 0
    EXAM
    LIB 0
    LIP 6
    ADB
    DY
    LIP 1
    EXAM
    IYS
    RTN

; ------------------------------------------------------------------------------
; PROTOTHREADGETSTATE
;       Input: I = thread number
;       Output: J = status
;       Saves:
; ------------------------------------------------------------------------------

PROTOTHREADGETSTATE:
    LIA PROTOTHREADST
    LIP 4
    EXAM
    LIA >PROTOTHREADST
    LIP 5
    EXAM
    CPIA 0
    EXAM
    LIB 0
    LIP 4
    ADB
    DX
    IXL
    LIP 1
    EXAM
    RTN
