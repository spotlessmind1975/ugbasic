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

FPSINGLE_POWN10_LUT:
DEFB $CD,$CC,$CC,$3D  ;1E-1
DEFB $0A,$D7,$23,$3C  ;1E-2
DEFB $17,$B7,$D1,$38  ;1E-4
DEFB $77,$CC,$2B,$32  ;1E-8
DEFB $95,$95,$E6,$24  ;1E-16
DEFB $1F,$B1,$4F,$0A  ;1E-32

FPSINGLE_POW10_LUT:
DEFB $00,$00,$20,$41  ;1E1
DEFB $00,$00,$C8,$42  ;1E2
DEFB $00,$40,$1C,$46  ;1E4
DEFB $20,$BC,$BE,$4C  ;1E8
DEFB $CA,$1B,$0E,$5A  ;1E16
DEFB $AE,$C5,$9D,$74  ;1E32
