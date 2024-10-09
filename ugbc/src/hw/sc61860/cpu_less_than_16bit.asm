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
;*                           LESS THAN (16 BIT) SC61860                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; I:J <= A:B ?
CPULTE16U:
	LP	1
	CPMA
	JRZP	CPULTE16U2
	JRNCP	CPULTE16UL1
	LIA 255
	RTN
CPULTE16U2:
	LP	0
	EXAB
	CPMA
	JRNCP	CPULTE16UL1
	LIA 255
	RTN
CPULTE16UL1:
    LIA 0
    RTN

; I:J < A:B ?
CPULT16U:
	LP	1
	CPMA
	JRZP	CPULT16U2
	JRNCP	CPULT16UL1
	LIA 255
	RTN
CPULT16U2:
	LP	0
	EXAB
	CPMA
	JRNCP	CPULT16UL1
	JRZP	CPULT16UL1
	LIA 255
	RTN
CPULT16UL1:
    LIA 0
    RTN
