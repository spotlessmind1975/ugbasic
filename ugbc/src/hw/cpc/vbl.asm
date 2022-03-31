WAITVBL:
    LD B, $f5
WAITVBLL1:    
    IN A, (C)
    RRA
    JP NC, WAITVBLL1
    RET