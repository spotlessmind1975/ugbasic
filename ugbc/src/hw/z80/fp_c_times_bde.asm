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

FP_C_TIMES_BDE:
  LD A, B
  LD H, D
  LD L, E
  SLA C
  JR C, FPMUL_24_1
  SLA C
  JR C, FPMUL_24_2
  SLA C
  JR C, FPMUL_24_3
  SLA C
  JR C, FPMUL_24_4
  SLA C
  JR C, FPMUL_24_5
  SLA C
  JR C, FPMUL_24_6
  SLA C
  JR C, FPMUL_24_7
  SLA C
  RET C

  LD A, C
  LD H, C
  LD L, C
  RET

FPMUL_24_1:
    ADD HL,HL
    RLA
    RL C 
    JR NC,$+7
    ADD HL, DE
    ADC A, B
    JR NC, $+3
    INC C
FPMUL_24_2:
    ADD HL, HL
    RLA
    RL C
    JR NC, $+7
    ADD HL, DE
    ADC A, B
    JR NC, $+3
    INC C
FPMUL_24_3:
    ADD HL,HL
    RLA
    RL C
    JR NC, $+7
    ADD HL, DE
    ADC A, B
    JR NC, $+3
    INC C
FPMUL_24_4:
    ADD HL,HL
    RLA
    RL C
    JR NC, $+7
    ADD HL, DE
    ADC A, B
    JR NC, $+3
    INC C
FPMUL_24_5:
    ADD HL, HL
    RLA
    RL C
    JR NC, $+7
    ADD HL, DE
    ADC A, B
    JR NC, $+3
    INC C
FPMUL_24_6:
    ADD HL, HL
    RLA
    RL C
    JR NC, $+7
    ADD HL ,DE
    ADC A, B
    JR NC,  $+3
    INC C
FPMUL_24_7:
    ADD HL, HL 
    RLA
    RL C
    RET NC
    ADD HL, DE
    ADC A, B
    RET NC
    INC C
    RET

