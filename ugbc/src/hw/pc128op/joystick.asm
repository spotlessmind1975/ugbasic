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
;*                    JOYSTICK MOVEMENT DETECTION ON DRAGON 32/64              *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PORT        EQU     DIRECTION

IO		equ		$ff00		; IO page on Dragon

DPPIA0DA	EQU		$00		; Side A Data/DDR
DPPIA0CRA	EQU		$01		; Side A Control.
DPPIA0DB	EQU		$02		; Side B Data/DDR
DPPIA0CRB	EQU		$03		; Side B Control.

PIA0DA		EQU		DPPIA0DA+IO	; Side A Data/DDR
PIA0CRA		EQU		DPPIA0CRA+IO	; Side A Control.
PIA0DB		EQU		DPPIA0DB+IO	; Side A Data/DDR
PIA0CRB		EQU		DPPIA0CRB+IO	; Side A Control.

DPPIA1DA	EQU		$20		; Side A Data/DDR
DPPIA1CRA	EQU		$21		; Side A Control.
DPPIA1DB	EQU		$22		; Side B Data/DDR
DPPIA1CRB	EQU		$23		; Side B Control.

PIA1DA		EQU		DPPIA1DA+IO	; Side A Data/DDR
PIA1CRA		EQU		DPPIA1CRA+IO	; Side A Control.
PIA1DB		EQU		DPPIA1DB+IO	; Side A Data/DDR
PIA1CRB		EQU		DPPIA1CRB+IO	; Side A Control.

JOYSTICK
    RTS
