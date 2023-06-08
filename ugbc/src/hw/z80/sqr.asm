; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

SQROOT:

    LD DE,05040H  ; 10
    LD A, H        ; 4
    SUB E         ; 4
    JR NC,SQROOT7     ;\
    ADD A, E       ; | BRANCH 1: 12CC
    LD D, 16       ; | BRANCH 2: 18CC
SQROOT7:            ;/

; ----------

  CP D          ; 4
  JR C, SQROOT6      ;\
  SUB D         ; | BRANCH 1: 12CC
  SET 5, D       ; | BRANCH 2: 19CC
SQROOT6:            ;/

; ----------
  RES 4, D       ; 8
  SRL D         ; 8
  SET 2, D       ; 8
  CP D          ; 4
  JR C, SQROOT5      ;\
  SUB D         ; | BRANCH 1: 12CC
  SET 3, D       ; | BRANCH 2: 19CC
SQROOT5:            ;/
  SRL D         ; 8

; ----------

  INC A         ; 4
  SUB D         ; 4
  JR NC, SQROOT4     ;\
  DEC D         ; | BRANCH 1: 12CC
  ADD A, D       ; | BRANCH 2: 19CC
  DEC D         ; | <-- THIS RESETS THE LOW BIT OF D, SO `SRL D` RESETS CARRY.
SQROOT4:            ;/
  SRL D         ; 8
  LD H,A        ; 4

; ----------

  LD A,E        ; 4
  SBC HL, DE     ; 15
  JR NC, SQROOT3     ;\
  ADD HL, DE     ; | 12CC OR 18CC
SQROOT3:            ;/
  CCF           ; 4
  RRA           ; 4
  SRL D         ; 8
  RRA           ; 4

; ----------

  LD E, A        ; 4
  SBC HL, DE     ; 15
  JR C,S QROOT2      ;\
  OR 20H        ; | BRANCH 1: 23CC
  DEFB 254        ; |   <-- START OF `CP *` WHICH IS 7CC TO SKIP THE NEXT BYTE.
SQROOT2:            ; | BRANCH 2: 21CC
  ADD HL, DE     ;/

  XOR 18H       ; 7
  SRL D         ; 8
  RRA           ; 4

; ----------

  LD E, A        ; 4
  SBC HL, DE     ; 15
  JR C, SQROOT1      ;\
  OR 8          ; | BRANCH 1: 23CC
  DEFB 254        ; |   <-- START OF `CP *` WHICH IS 7CC TO SKIP THE NEXT BYTE.
SQROOT1:            ; | BRANCH 2: 21CC
  ADD HL, DE     ;/

  XOR 6         ; 7
  SRL D         ; 8
  RRA           ; 4

; ----------

  LD E, A        ; 4
  SBC HL, DE     ; 15
  JR NC, SQROOT1L1      ;    \
  ADD HL, DE     ; 15  |
  SRL D         ; 8   |
  RRA           ; 4   | BRANCH 1: 38CC
  RET           ; 10  | BRANCH 2: 40CC
SQROOT1L1:              ;     |
  INC A         ; 4   |
  SRL D         ; 8   |
  RRA           ; 4   |
  RET           ; 10 /
 