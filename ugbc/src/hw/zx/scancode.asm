
SCANCODE:
    LD HL,SCANCODEKM
    LD D,8
    LD C,$FE
SCANCODE0:
    LD B,(HL)
    INC HL
    IN A,(C)
    AND $1F
    LD E,5
SCANCODE1:
    SRL A
    JR NC,SCANCODE2
    INC HL
    DEC E
    JR NZ,SCANCODE1
    DEC D
    JR NZ,SCANCODE0
    AND A
    RET
SCANCODE2:
    LD A,(HL)
    RET
 
SCANCODEKM:
    DB $FE,$F1,"Z","X","C","V"
    DB $FD,"A","S","D","F","G"
    DB $FB,"Q","W","E","R","T"
    DB $F7,"1","2","3","4","5"
    DB $EF,"0","9","8","7","6"
    DB $DF,"P","O","I","U","Y"
    DB $BF,"#","L","K","J","H"
    DB $7F," ","#","M","N","B"