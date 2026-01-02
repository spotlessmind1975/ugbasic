; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;*                            CHAIN ROUTINE ON C128                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CHAINIRQ    =   $47

CHAIN:
    LDA #$ff
    STA DCOMMONP2
    LDA #$1b
    STA DCOMMONP2+1
    LDA #0
    STA DCOMMON1

    LDA NMISVC_SYSTEM
    STA CHAINIRQ
    LDA NMISVC_SYSTEM+1
    STA CHAINIRQ+1

    LDA IRQSVC_SYSTEM
    STA CHAINIRQ+2
    LDA IRQSVC_SYSTEM+1
    STA CHAINIRQ+3

    LDA IRQSVC2_SYSTEM
    STA CHAINIRQ+4
    LDA IRQSVC2_SYSTEM+1
    STA CHAINIRQ+5

    JSR C128DLOAD

    SEI
    LDA CHAINIRQ
    STA $FFFA
    LDA CHAINIRQ+1
    STA $FFFB

    LDA CHAINIRQ+2
    STA $FFFE
    LDA CHAINIRQ+3
    STA $FFFF

    LDA CHAINIRQ+4
    STA $0314
    LDA CHAINIRQ+5
    STA $0315
    CLI    

    JMP CHAINEDSTART
