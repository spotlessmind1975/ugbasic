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
;*                          VERTICAL SCROLL ON ZX SPECTRUM                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLL:
    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    PUSH IY
    PUSH IX
    CP $80
    JP C, VSCROLLDOWN

; ------------------------------------------------------------
; | SCROLL UP
; ------------------------------------------------------------

VSCROLLUP:
    
    ; Calculate offset for scrolling (B 2 complemented)
    XOR $FF
    ADD A, 1
    LD B, A

VSCROLLUPL:

    ; Get the height of the window scrolling (in bytes).

    LD A, (CONSOLEH)
    SLA A
    SLA A
    SLA A
    LD C, A

    ; We have to scroll just the height minus 
    ; the number of rows to scroll.

    LD A, C
    SUB A, B
    LD C, A

    ; Lookup table will do the magic.

    LD IX, ROWSADDRESS

    ; Lookup for first row (CONSOLEY1)

    PUSH BC
    LD A, (CONSOLEY1)
    CP 0
    JR Z, ROWSELECTUP
    SLA A
    SLA A
    SLA A
    LD C, A
ROWSELECTUPC:
    INC IX
    INC IX
    DEC C
    JR NZ, ROWSELECTUPC
ROWSELECTUP:
    POP BC


    PUSH IX
ROWSELECTREPEAT:
    POP IX
    PUSH IX

    ; Retrieve the address of the first (n-th) row in DE.

    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX

    ; Now we move ahead, to take address of the "second" row.

    PUSH B
    DEC B
    JR Z, ROWSELECTUP1
ROWSELECTUP0:
    INC IX
    INC IX
    DEC B
    JR NZ, ROWSELECTUP0
ROWSELECTUP1:
    POP B

    ; Retrieve the address of the "second" (nth+1) row in HL.

    LD A, (IX)
    LD L, A
    INC IX
    LD A, (IX)
    LD H, A
    INC IX

    ; Now we can copy the row (HL -> DE)

    CALL ROWCOPY

    ; Move to the next row.
    
    POP IX
    INC IX
    INC IX
    PUSH IX

    ; Decrement the number of rows to copy. 
    ; If not finished, continue with the next row.

    DEC C
    JR NZ, ROWSELECTREPEAT

    ; The last line will be cleared.

    PUSH HL
    POP DE

;     ; Clear all lines scrolled.

    LD IYL, 0
    PUSH B
    DEC B
    JR Z, ROWSELECTUP5
ROWSELECTUP4:
    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX
    CALL ROWCLEAR
    DEC B
    JR NZ, ROWSELECTUP4
ROWSELECTUP5:
    POP B

    POP IX

    ;
    ; ---------------------------------------------

VSCROLLUPLC:

    ; Get the height of the window scrolling (in bytes).

    LD A, (CONSOLEH)
    LD C, A
    DEC C

    ; Lookup table will do the magic.

    LD IX, COLRADDRESS

    LD A, B
    SRL A
    SRL A
    SRL A
    LD B, A

    ; Lookup for first row (CONSOLEY1)

    PUSH BC
    LD A, (CONSOLEY1)
    CP 0
    JR Z, ROWSELECTUPC20
    LD C, A
ROWSELECTUPC2:
    INC IX
    INC IX
    DEC C
    JR NZ, ROWSELECTUPC2
ROWSELECTUPC20:
    POP BC

    ; Retrieve the address of the first row in DE.

ROWCSELECTUPC:

    PUSH IX
ROWSELECTREPEATC:
    POP IX
    PUSH IX

    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX

    ; Now we move ahead, to take address of the "second" row.

    PUSH B
    LD A, B
    CP 1
    JR Z, ROWCSELECTUP1C
ROWCSELECTUP0C:
    INC IX
    INC IX
    DEC B
    JR NZ, ROWCSELECTUP0C
ROWCSELECTUP1C:
    POP B

    ; Retrieve the address of the "second" row in HL.

    LD A, (IX)
    LD L, A
    INC IX
    LD A, (IX)
    LD H, A
    INC IX

    ; Now we can copy the row (HL -> DE)

    CALL ROWCOPY

    POP IX
    INC IX
    INC IX
    PUSH IX

    ; Decrement the number of rows to copy. 
    ; If not finished, continue with the next row.

    DEC C
    JR NZ, ROWSELECTREPEATC

    ; The last line will be cleared.

    LD A, (_PAPER)
    AND $7
    SLA A
    SLA A
    SLA A    
    LD IYL, A
    LD A, (CONSOLEH)
    CP 0
    JR Z, ROWCSELECTUPC5
    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX
    CALL ROWCLEAR
ROWCSELECTUPC5:

    POP IX

    JP VSCROLLE

; ------------------------------------------------------------
; | SCROLL DOWN
; ------------------------------------------------------------

VSCROLLDOWN:
    LD B, A
VSCROLLDOWNL:
    LD C, 192

    LD A, C
    SUB A, B
    LD C, A

    LD IX, ROWSADDRESSL
ROWSELECTDOWN:

    DEC IX
    DEC IX

    PUSH B
    DEC B
    JR NZ, ROWSELECTDOWN1
ROWSELECTDOWN0:
    DEC IX
    DEC IX
    DEC B
    JR NZ, ROWSELECTDOWN0
ROWSELECTDOWN1:
    POP B

    LD A, (IX)
    LD L, A
    INC IX
    LD A, (IX)
    LD H, A
    INC IX

    PUSH B
    DEC B
    JR Z, ROWSELECTDOWN2
ROWSELECTDOWN3:
    INC IX
    INC IX
    JR NZ, ROWSELECTDOWN3
ROWSELECTDOWN2:
    POP B

    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX

    DEC IX
    DEC IX
    DEC IX
    DEC IX

    PUSH B
    DEC B
    JR Z, ROWSELECTDOWN5
ROWSELECTDOWN4:
    DEC IX
    DEC IX
    DEC B
    JR NZ, ROWSELECTDOWN4
ROWSELECTDOWN5:
    POP B

    CALL ROWCOPY
    DEC C
    JR NZ, ROWSELECTDOWN

    PUSH B
    DEC B
    JR Z, ROWSELECTDOWN7
ROWSELECTDOWN6:
    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX
    CALL ROWCLEAR    
    DEC B
    JR NZ, ROWSELECTDOWN6
ROWSELECTDOWN7:
    POP B

    LD IX, COLRADDRESSL

    LD A, (IX)
    LD L, A
    INC IX
    LD A, (IX)
    LD H, A
    INC IX

    DEC IX
    DEC IX

    PUSH B
    DEC B
    JR Z, ROWCSELECTDOWNL2 
ROWCSELECTDOWNL:
    DEC IX
    DEC IX
    DEC B
    JR NZ, ROWCSELECTDOWNL
ROWCSELECTDOWNL2:
    POP B

    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A

    LD A, B

    SRA A
    SRA A
    SRA A
    SRA A
    SRA A

    JR NZ, ROWCSELECTDOWNL3A

    LD A, 1

ROWCSELECTDOWNL3A:

    PUSH HL
    PUSH DE
    LD HL, $280
    LD DE, $20
    DEC A
    JR Z, ROWCSELECTDOWNL4
ROWCSELECTDOWNL3:
    SBC HL, DE
    DEC A
    JR NZ, ROWCSELECTDOWNL3
ROWCSELECTDOWNL4:
    LD BC, HL
    POP DE
    POP HL
    LDIR

    JP VSCROLLE

;;;;;;;;;;;;;;;;;;;

ROWCOPY:
    PUSH HL
    PUSH BC
    PUSH DE
    LD A, (CONSOLEX1)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD BC, DE
    POP DE
    PUSH HL
    LD HL, DE
    LD DE, BC
    ADD HL, DE
    LD DE, HL
    POP HL
    LD A, (CONSOLEW)
    LD B, A
ROWCOPYL:
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC B
    JR NZ, ROWCOPYL
    POP BC
    POP HL
    RET

ROWCLEAR:
    PUSH BC
    LD HL, DE
    LD A, (CONSOLEX1)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD DE, HL
    LD A, (CONSOLEW)
    LD B, A
    LD A, IYL
ROWCLEARL:
    LD (DE), A
    INC DE
    DEC B
    JR NZ, ROWCLEARL
    POP BC
    RET

VSCROLLE:
    POP IX
    POP IY
    POP HL
    POP DE
    POP BC
    POP AF
    RET

ROWSADDRESS: 
    DEFW 16384
    DEFW 16640
    DEFW 16896
    DEFW 17152
    DEFW 17408
    DEFW 17664
    DEFW 17920
    DEFW 18176
    DEFW 16416
    DEFW 16672
    DEFW 16928
    DEFW 17184
    DEFW 17440
    DEFW 17696
    DEFW 17952
    DEFW 18208
    DEFW 16448
    DEFW 16704
    DEFW 16960
    DEFW 17216
    DEFW 17472
    DEFW 17728
    DEFW 17984
    DEFW 18240
    DEFW 16480
    DEFW 16736
    DEFW 16992
    DEFW 17248
    DEFW 17504
    DEFW 17760
    DEFW 18016
    DEFW 18272
    DEFW 16512
    DEFW 16768
    DEFW 17024
    DEFW 17280
    DEFW 17536
    DEFW 17792
    DEFW 18048
    DEFW 18304
    DEFW 16544
    DEFW 16800
    DEFW 17056
    DEFW 17312
    DEFW 17568
    DEFW 17824
    DEFW 18080
    DEFW 18336
    DEFW 16576
    DEFW 16832
    DEFW 17088
    DEFW 17344
    DEFW 17600
    DEFW 17856
    DEFW 18112
    DEFW 18368
    DEFW 16608
    DEFW 16864
    DEFW 17120
    DEFW 17376
    DEFW 17632
    DEFW 17888
    DEFW 18144
    DEFW 18400
    DEFW 18432
    DEFW 18688
    DEFW 18944
    DEFW 19200
    DEFW 19456
    DEFW 19712
    DEFW 19968
    DEFW 20254
    DEFW 18464
    DEFW 18720
    DEFW 18976
    DEFW 19232
    DEFW 19488
    DEFW 19744
    DEFW 20000
    DEFW 20256
    DEFW 18496
    DEFW 18752
    DEFW 19008
    DEFW 19264
    DEFW 19520
    DEFW 19776
    DEFW 20032
    DEFW 20288
    DEFW 18528
    DEFW 18784
    DEFW 19040
    DEFW 19296
    DEFW 19552
    DEFW 19808
    DEFW 20064
    DEFW 20320
    DEFW 18560
    DEFW 18816
    DEFW 19072
    DEFW 19328
    DEFW 19584
    DEFW 19840
    DEFW 20096
    DEFW 20352
    DEFW 18592
    DEFW 18848
    DEFW 19104
    DEFW 19360
    DEFW 19616
    DEFW 19872
    DEFW 20128
    DEFW 20384
    DEFW 18624
    DEFW 18880
    DEFW 19136
    DEFW 19392
    DEFW 19648
    DEFW 19904
    DEFW 20160
    DEFW 20416
    DEFW 18656
    DEFW 18912
    DEFW 19168
    DEFW 19424
    DEFW 19680
    DEFW 19936
    DEFW 20192
    DEFW 20448
    DEFW 20480
    DEFW 20736
    DEFW 20992
    DEFW 21248
    DEFW 21504
    DEFW 21760
    DEFW 22016
    DEFW 22272
    DEFW 20512
    DEFW 20768
    DEFW 21024
    DEFW 21280
    DEFW 21536
    DEFW 21792
    DEFW 22048
    DEFW 22304
    DEFW 20544
    DEFW 20800
    DEFW 21056
    DEFW 21312
    DEFW 21568
    DEFW 21824
    DEFW 22080
    DEFW 22336
    DEFW 20576
    DEFW 20832
    DEFW 21088
    DEFW 21344
    DEFW 21600
    DEFW 21856
    DEFW 22112
    DEFW 22368
    DEFW 20608
    DEFW 20864
    DEFW 21120
    DEFW 21376
    DEFW 21632
    DEFW 21888
    DEFW 22144
    DEFW 22400
    DEFW 20640
    DEFW 20896
    DEFW 21152
    DEFW 21408
    DEFW 21664
    DEFW 21920
    DEFW 22176
    DEFW 22432
    DEFW 20672
    DEFW 20928
    DEFW 21184
    DEFW 21440
    DEFW 21696
    DEFW 21952
    DEFW 22208
    DEFW 22464
    DEFW 20704
    DEFW 20960
    DEFW 21216
    DEFW 21472
    DEFW 21728
    DEFW 21984
    DEFW 22240
ROWSADDRESSL:
    DEFW 22496

COLRADDRESS:
    DEFW 22528
    DEFW 22560
    DEFW 22592
    DEFW 22624
    DEFW 22656
    DEFW 22688
    DEFW 22720
    DEFW 22752
    DEFW 22784
    DEFW 22816
    DEFW 22848
    DEFW 22880
    DEFW 22912
    DEFW 22944
    DEFW 22976
    DEFW 23008
    DEFW 23040
    DEFW 23072
    DEFW 23104
    DEFW 23136
    DEFW 23168
    DEFW 23200
    DEFW 23232
    DEFW 23264
COLRADDRESSL:
    DEFW 23296
