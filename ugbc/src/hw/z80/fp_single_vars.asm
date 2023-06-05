; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2023 Marco Spedaletti (asimov@mclink.it)
;  * Inspired from modules/z80float, copyright 2018 Zeda A.K. Thomas
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

FPSINGLE_CONST_PI:
	DEFB $DB,$0F,$49,$40	;3.14159265
FPSINGLE_CONST_2PI:
	DEFB $DB,$0F,$C9,$40	;6.28318530
FPSINGLE_CONST_PI_DIV_2:
	DEFB $DB,$0F,$C9,$3F	;6.28318530
FPSINGLE_CONST_0:
	DEFB $00,$00,$00,$00	;0
FPSINGLE_CONST_1:
	DEFB $00,$00,$80,$3F	;1
FPSINGLE_CONST_N1:
	DEFB $00,$00,$80,$BF	;-1
FPSINGLE_CONST_NAN:
	DEFB $FF,$FF,$FF,$7F	;NAN
FPSINGLE_CONST_INF:
	DEFB $00,$00,$80,$7F	;INF
FPSINGLE_CONST_NINF:
	DEFB $00,$00,$80,$FF	;-INF
FPSINGLE_CONST_LN2:
	DEFB $18,$72,$31,$3F	;.6931471806
FPSINGLE_CONST_LG_E:
	DEFB $3B,$AA,$B8,$3F	;1.442695041
FPSINGLE_CONST_LOG10_E:
	DEFB $D9,$5B,$DE,$3E	;0.4342944819
FPSINGLE_CONST_P5:
	DEFB $00,$00,$00,$3F	;.5
FPSINGLE_CONST_P25:
	DEFB $00,$00,$80,$3E	;.25
FPSINGLE_CONST_2PI_INV:
	DEFB $83,$F9,$22,$3E	;.1591549431
FPSINGLE_CONST_LG_10:
	DEFB $78,$9A,$54,$40	;3.321928095

