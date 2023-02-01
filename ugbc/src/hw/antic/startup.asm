; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                          STARTUP ROUTINE FOR ANTIC                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

ANTICVBL:   .BYTE       0

IRQLISTENER:
    LDA #1
    STA ANTICVBL
    RTI

ANTICSTARTUP:
    ; LDA $0230
    ; STA TMPPTR
    ; LDA $0231
    ; STA TMPPTR+1

    ; CLC
    ; LDA TMPPTR
    ; ADC #4
    ; STA TMPPTR
    ; LDA TMPPTR+1
    ; ADC #0
    ; STA TMPPTR+1

    ; LDY #0
    ; LDA (TMPPTR),Y
    ; STA TEXTADDRESS
    ; INY
    ; LDA (TMPPTR),Y
    ; STA TEXTADDRESS+1

    ; CLC
    ; LDA TMPPTR
    ; ADC #23
    ; STA TMPPTR
    ; LDA TMPPTR+1
    ; ADC #0
    ; STA TMPPTR+1

    SEI
    LDA #<IRQLISTENER
    STA $0200
    LDA #>IRQLISTENER
    STA $0201
    CLI

    ; LDY #0
    ; LDA (TMPPTR),Y
    ; ORA #$80
    ; STA (TMPPTR),Y

    RTS