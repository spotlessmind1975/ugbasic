; Square Root Calculator written by Zeda
;
; returns A as the sqrt, HL as the remainder, D = 0
; min: 352cc
; max: 391cc
; avg: 371.5cc
;
; Originally published on https://wikiti.brandonw.net/index.php?title=Z80_Routines:Math:Square_root 
; Adapted by Marco Spedaletti for ugBASIC   


;
SQROOT:

    LD DE,05040H  ; 10
    LD A,H        ; 4
    SUB E         ; 4
    JR NC,SQROOT7     ;\
    ADD A,E       ; | BRANCH 1: 12CC
    LD D,16       ; | BRANCH 2: 18CC
SQROOT7:            ;/

; ----------

  CP D          ; 4
  JR C,SQROOT6      ;\
  SUB D         ; | BRANCH 1: 12CC
  SET 5,D       ; | BRANCH 2: 19CC
SQROOT6:            ;/

; ----------
  RES 4,D       ; 8
  SRL D         ; 8
  SET 2,D       ; 8
  CP D          ; 4
  JR C,SQROOT5      ;\
  SUB D         ; | BRANCH 1: 12CC
  SET 3,D       ; | BRANCH 2: 19CC
SQROOT5:            ;/
  SRL D         ; 8

; ----------

  INC A         ; 4
  SUB D         ; 4
  JR NC,SQROOT4     ;\
  DEC D         ; | BRANCH 1: 12CC
  ADD A,D       ; | BRANCH 2: 19CC
  DEC D         ; | <-- THIS RESETS THE LOW BIT OF D, SO `SRL D` RESETS CARRY.
SQROOT4:            ;/
  SRL D         ; 8
  LD H,A        ; 4

; ----------

  LD A,E        ; 4
  SBC HL,DE     ; 15
  JR NC,SQROOT3     ;\
  ADD HL,DE     ; | 12CC OR 18CC
SQROOT3:            ;/
  CCF           ; 4
  RRA           ; 4
  SRL D         ; 8
  RRA           ; 4

; ----------

  LD E,A        ; 4
  SBC HL,DE     ; 15
  JR C,SQROOT2      ;\
  OR 20H        ; | BRANCH 1: 23CC
  DB 254        ; |   <-- START OF `CP *` WHICH IS 7CC TO SKIP THE NEXT BYTE.
SQROOT2:            ; | BRANCH 2: 21CC
  ADD HL,DE     ;/

  XOR 18H       ; 7
  SRL D         ; 8
  RRA           ; 4

; ----------

  LD E,A        ; 4
  SBC HL,DE     ; 15
  JR C,SQROOT1      ;\
  OR 8          ; | BRANCH 1: 23CC
  DB 254        ; |   <-- START OF `CP *` WHICH IS 7CC TO SKIP THE NEXT BYTE.
SQROOT1:            ; | BRANCH 2: 21CC
  ADD HL,DE     ;/

  XOR 6         ; 7
  SRL D         ; 8
  RRA           ; 4

; ----------

  LD E,A        ; 4
  SBC HL,DE     ; 15
  JR NC,+_      ;    \
  ADD HL,DE     ; 15  |
  SRL D         ; 8   |
  RRA           ; 4   | BRANCH 1: 38CC
  RET           ; 10  | BRANCH 2: 40CC
_:              ;     |
  INC A         ; 4   |
  SRL D         ; 8   |
  RRA           ; 4   |
  RET           ; 10 /
 