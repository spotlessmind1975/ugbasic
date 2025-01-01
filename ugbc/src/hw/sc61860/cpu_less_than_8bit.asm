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
;*                           LESS THAN (8 BIT) SC61860                         *
;*                                                                             *
;*                             by F Fumi                                       *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; I <= A ?
CPULTE8U:
	LP	0
	EXAB
	CPMA
	JRNCP	CPULTE8UL1
	LIA 255
	RTN
CPULTE8UL1:
    LIA 0
    RTN

; I < A ?
CPULT8U:
	LP	0
	EXAB
	CPMA
	JRNCP	CPULT8UL1
	JRZP	CPULT8UL1
	LIA 255
	RTN
CPULT8UL1:
    LIA 0
    RTN
	
; (signed) I <= A ? 
CPULTE8S:
	PUSH
	CPIA 0x80
	JRNCP CPULTE8SN
	LP 0
	EXAM
	CPIA 0x80
	JRCP CPULTE8SN
	POP
	CALL CPULTE8U
	RTN
CPULTE8SN:
	POP
	CALL CPULTE8U
	CPIA 0
	JRZP CPULTE8SD
	LIA 0
	RTN
CPULTE8SD:
	LIA 0xff
	RTN

; (signed) I < A ? 
CPULT8S:
	PUSH
	CPIA 0x80
	JRNCP CPULT8SN
	LP 0
	EXAM
	CPIA 0x80
	JRCP CPULT8SN
	POP
	CALL CPULT8U
	RTN
CPULT8SN:
	POP
	CALL CPULT8U
	CPIA 0
	JRZP CPULT8SD
	LIA 0
	RTN
CPULT8SD:
	LIA 0xff
	RTN
