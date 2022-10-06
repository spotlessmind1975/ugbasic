; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                      AUDIO ROUTINES ON THOMSON MO6                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

AUDIOBUFFER
    FCB $10,$10,$11,$12,$13,$13,$14,$15,
    FCB $15,$16,$17,$17,$18,$19,$19,$1a,
    FCB $1a,$1b,$1b,$1c,$1c,$1d,$1d,$1e,
    FCB $1e,$1e,$1e,$1f,$1f,$1f,$1f,$1f,
    FCB $1f,$1f,$1f,$1f,$1f,$1f,$1e,$1e,
    FCB $1e,$1e,$1d,$1d,$1c,$1c,$1b,$1b,
    FCB $1a,$1a,$19,$19,$18,$17,$17,$16,
    FCB $15,$15,$14,$13,$13,$12,$11,$10,
    FCB $10,$f,$e,$d,$c,$c,$b,$a,
    FCB $a,$9,$8,$8,$7,$6,$6,$5,
    FCB $5,$4,$4,$3,$3,$2,$2,$1,
    FCB $1,$1,$1,$0,$0,$0,$0,$0,
    FCB $0,$0,$0,$0,$0,$0,$1,$1,
    FCB $1,$1,$2,$2,$3,$3,$4,$4,
    FCB $5,$5,$6,$6,$7,$8,$8,$9,
    FCB $a,$a,$b,$c,$c,$d,$e,$f

PC128OPAUDIOSTARTUP
    LDA   $A7CF
    ANDA  #$FB
    STA   $A7CF
    LDB   #$3F
    STB   $A7CD
    ORA   #$04
    STA   $A7CF
    RTS

PC128AUDIOBITBANGSINGLE
    PSHS D
    LDB #$2
    LDA $A7C1
    ORA #$1
    STA $A7C1
PC128AUDIOBITBANGSINGLEL1
    DECB
    BNE PC128AUDIOBITBANGSINGLEL1
    LDA $A7C1
    ANDA #$FE
    STA $A7C1
    PULS D
    RTS

PC128AUDIOBITBANG
    JSR PC128AUDIOBITBANGSINGLE
    PSHS D
PC128AUDIOBITBANGL1
    DECA
    BNE PC128AUDIOBITBANGL1
    PULS D
    DECB
    BNE PC128AUDIOBITBANG
    RTS

PC128AUDIOBITSILENCE
    PSHS D
PC128AUDIOBITSILENCEL1
    DECA
    BNE PC128AUDIOBITSILENCEL1
    PULS D
    DECB
    BNE PC128AUDIOBITSILENCE
    RTS

PC128AUDIODACSINGLE
    PSHS D
    LDA $A7CD
    ANDA #$C0
    STB <TMPPTR
    ORA <TMPPTR
    STA $A7CD
    PULS D
    RTS

PC128AUDIODACSOUND
    JSR PC128AUDIODACSINGLE
PC128AUDIODACSOUNDL1
    DECA
    BNE PC128AUDIODACSOUNDL1
    RTS

PC128AUDIODACSILENCE
PC128AUDIODACSILENCEL1
    DECA
    BNE PC128AUDIODACSILENCEL1
    RTS

PC128AUDIOBELL
    LDX #AUDIOBUFFER
    LDU #128
PC128AUDIOBELLL1    
    LDA #1    
    LDB , X+
    JSR PC128AUDIODACSOUND
    LEAU -1, U
    CMPU #0
    BNE PC128AUDIOBELLL1
    LEAY -1, Y
    CMPY #0
    BNE PC128AUDIOBELL
    RTS

PC128AUDIOBOOM
    orcc #$50
    LDB PC128TIMER+1
    EORB PC128TIMER
    BNE PC128AUDIOBOOML1
    LDB #$AA
PC128AUDIOBOOML1
    RORB
    COMB
    EORB PC128TIMER
    RORB
    BCC PC128AUDIOBOOMSKIP
    PSHS D
    LDA #$10
    JSR PC128AUDIOBITBANG
    PULS D
    JMP PC128AUDIOBOOMDONE
PC128AUDIOBOOMSKIP
    PSHS D
    LDA #$5
    JSR PC128AUDIOBITSILENCE
    PULS D
PC128AUDIOBOOMDONE
    LEAU -1,U
    CMPU #0
    BNE PC128AUDIOBOOML1
    andcc #$af
    RTS
    