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
;*                            WAIT KEY OR FIRE ON C=128                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; WAITKEYFIRE
; ----------------------------------------------------------------------------
; This routine will wait for a key press OR a fire press. 

@IF keyboardConfig.sync

    WAITKEYFIREX:
        LDA $D010,X
        AND #$01
        EOR #$01
        STA MATHPTR0
        LDA $2FC
        EOR #$FF
        ORA MATHPTR0
        BEQ WAITKEYFIRE
        LDA #$FF
        STA $2FC
        RTS

    WAITKEYFIRE:
        LDA $D010
        AND #$01
        EOR #$01
        STA MATHPTR0
        LDA $D011
        AND #$01
        EOR #$01
        ORA MATHPTR0
        STA MATHPTR0
        LDA $D012
        AND #$01
        EOR #$01
        ORA MATHPTR0
        STA MATHPTR0
        LDA $D013
        AND #$01
        EOR #$01
        ORA MATHPTR0
        LDA $2FC
        EOR #$FF
        ORA MATHPTR0
        BEQ WAITKEYFIRE
        LDA #$FF
        STA $2FC
        RTS

@ELSE

    WAITKEYFIREX:
        LDA KEYBOARDASFSTATE
        BEQ WAITKEYFIRE1X
    WAITKEYFIRE0X:
        LDA KEYBOARDASFSTATE
        BNE WAITKEYFIRE0X
    WAITKEYFIRE1X:
        LDA $D010, X
        AND #$01
        EOR #$01
        STA MATHPTR0
        LDA KEYBOARDASFSTATE
        ORA MATHPTR0
        BEQ WAITKEYFIRE1X
        RTS

    WAITKEYFIRE:
        LDA KEYBOARDASFSTATE
        BEQ WAITKEYFIRE1
    WAITKEYFIRE0:
        LDA KEYBOARDASFSTATE
        BNE WAITKEYFIRE0
    WAITKEYFIRE1:
        LDA $D010
        AND #$01
        EOR #$01
        STA MATHPTR0
        LDA $D011
        AND #$01
        EOR #$01
        ORA MATHPTR0
        STA MATHPTR0
        LDA $D012
        AND #$01
        EOR #$01
        ORA MATHPTR0
        STA MATHPTR0
        LDA $D013
        AND #$01
        EOR #$01
        ORA MATHPTR0
        LDA KEYBOARDASFSTATE
        ORA MATHPTR0
        BEQ WAITKEYFIRE1
        RTS

@ENDIF
