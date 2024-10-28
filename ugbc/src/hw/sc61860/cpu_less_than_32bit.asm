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
;*                           LESS THAN (32 BIT) SC61860                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; 0 1 2 3 == 8 9 a b
; I:J:A:B <= K:L:M:N ?
CPULTE32U:

	LP 8
	EXAM
	LP 0
	CPMA
	JRZP	CPULTE32U2
	JRNCP	CPULTE32UL1
	LIA 255
	RTN

CPULTE32U2:

	LP 9
	EXAM
	LP 1
	CPMA
	JRZP	CPULTE32U3
	JRNCP	CPULTE32UL1
	LIA 255
	RTN

CPULTE32UL1:
    LIA 0
    RTN

CPULTE32U3:

	LP 10
	EXAM
	LP 2
	CPMA
	JRZP	CPULTE32U4
	JRNCP	CPULTE32UL1
	LIA 255
	RTN

CPULTE32U4:

	LP 11
	EXAM
	LP 3
	CPMA
	JRNCP	CPULTE32UL1
	LIA 255
	RTN

; 0 1 2 3 == 8 9 a b
; I:J:A:B < K:L:M:N ?
CPULT32U:

	LP 8
	EXAM
	LP 0
	CPMA
	JRZP	CPULT32U2
	JRNCP	CPULT32UL1
	LIA 255
	RTN

CPULT32U2:

	LP 9
	EXAM
	LP 1
	CPMA
	JRZP	CPULT32U3
	JRNCP	CPULT32UL1
	LIA 255
	RTN

CPULT32UL1:
    LIA 0
    RTN

CPULT32U3:

	LP 10
	EXAM
	LP 2
	CPMA
	JRZP	CPULT32U4
	JRNCP	CPULT32UL1
	LIA 255
	RTN

CPULT32U4:

	LP 11
	EXAM
	LP 3
	CPMA
	JRNCP	CPULT32UL1
	JRZP	CPULT32UL1
	LIA 255
	RTN
