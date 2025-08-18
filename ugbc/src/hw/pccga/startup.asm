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
;*                      STARTUP ROUTINE FOR PC IBM WITH CGA                    *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PCCGASTARTUP:
    
@IF deployed.fp

    FINIT
    WAIT

@ENDIF

@IF deployed.keyboard && !keyboardConfig.sync

    CLI
    PUSH DS
    MOV DX, 0x0000
    MOV DS, DX
    MOV WORD [9*4], KEYBOARDMANAGER
    MOV DX, CS
    MOV WORD [9*4+2], DX
    POP DS
    STI

    ; The interrupt vector table (contains addresses of interrupt 
    ; handling routines) is in memory starting at 0000:0000 address.

    ; Every entry in the table consist of four bytes, so then offset
    ; for 21h is 21h*4 = 84h (not 84, but 84h == 132).

    ; Those four bytes of single entry are segment:offset address 
    ; of routine, the offset part is stored as first word, segment
    ; part is the second word (at 0:86h). Your original code does set 
    ; only offset part, but not segment, that's why it jumps to 
    ; F400h:1500h, you didn't change that old F400h of original DOS handler.

@ENDIF

    RET