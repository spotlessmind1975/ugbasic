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
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CPUCONVERTSTRINGINTO16BIT_VALUE         =   MATHPTR0; MATHPTR1

CPUCONVERTSTRINGINTO16BIT:
    LDA #$0
    STA CPUCONVERTSTRINGINTO16BIT_VALUE
    STA CPUCONVERTSTRINGINTO16BIT_VALUE+1

    LDY #$0

CPUCONVERTSTRINGINTO16BIT2:
    LDA (TMPPTR),Y
    CMP #$39
    BCS CPUCONVERTSTRINGINTO16BIT3
    CMP #$30
    BCC CPUCONVERTSTRINGINTO16BIT3
    SBC #$30
    
    CLC
    ADC CPUCONVERTSTRINGINTO16BIT_VALUE
    STA CPUCONVERTSTRINGINTO16BIT_VALUE
    LDA #$0
    ADC CPUCONVERTSTRINGINTO16BIT_VALUE+1
    STA CPUCONVERTSTRINGINTO16BIT_VALUE+1

    LDA CPUCONVERTSTRINGINTO16BIT_VALUE+1
    STA TMPPTR2+1
    LDA CPUCONVERTSTRINGINTO16BIT_VALUE
    STA TMPPTR2
    
    INY
    DEX
    BEQ CPUCONVERTSTRINGINTO16BIT3
    
    LDA TMPPTR2
    STA CPUCONVERTSTRINGINTO16BIT_VALUE
    LDA TMPPTR2+1
    STA CPUCONVERTSTRINGINTO16BIT_VALUE+1
    ASL CPUCONVERTSTRINGINTO16BIT_VALUE
    ROL CPUCONVERTSTRINGINTO16BIT_VALUE+1
    ASL CPUCONVERTSTRINGINTO16BIT_VALUE
    ROL CPUCONVERTSTRINGINTO16BIT_VALUE+1
    CLC
    LDA TMPPTR2
    ADC CPUCONVERTSTRINGINTO16BIT_VALUE
    STA CPUCONVERTSTRINGINTO16BIT_VALUE
    LDA TMPPTR2+1
    ADC CPUCONVERTSTRINGINTO16BIT_VALUE+1
    STA CPUCONVERTSTRINGINTO16BIT_VALUE+1
    ASL CPUCONVERTSTRINGINTO16BIT_VALUE
    ROL CPUCONVERTSTRINGINTO16BIT_VALUE+1
    
    JMP CPUCONVERTSTRINGINTO16BIT2
    
CPUCONVERTSTRINGINTO16BIT3:
    RTS