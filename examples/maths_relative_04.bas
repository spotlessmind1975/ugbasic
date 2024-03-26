REM @english
REM MATHEMATIC ROUTINES CHECKING SIGN / UNSIGN CONVERSION
REM
REM This example allows you to verify that the assignment between signed 
REM and unsigned integer types works correctly.
REM
REM @italian
REM ROUTINE DI MATEMATICA VERIFICA LA CONVERSIONE CON SEGNO
REM
REM Questo esempio permette di verificare che l'assegnazione tra tipi
REM interi, con e senza segno, funzioni correttamente.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,zx

CLS

DIM sb AS SIGNED BYTE, ub AS BYTE
DIM sw AS SIGNED WORD, uw AS WORD
DIM sd AS SIGNED DWORD, ud AS DWORD

PRINT " 8>16) ";
sb = -42: sw = sb: IF sw <> -42 THEN: PRINT "(1)";: ENDIF
sb = -42: uw = sb: IF uw <> $FFD6 THEN: PRINT "(2)";: ENDIF
ub = 192: sw = ub: IF sw <> 192 THEN: PRINT "(3)";: ENDIF
ub = 192: uw = ub: IF uw <> 192 THEN: PRINT "(4)";: ENDIF
PRINT

PRINT " 8>32) ";
sb = -42: sd = sb: IF sd <> -42 THEN: PRINT "(1)";: ENDIF
sb = -42: ud = sb: IF ud <> $FFFFFFD6 THEN: PRINT "(2)";:ENDIF
ub = 42: sd = ub: IF sd <> 42 THEN: PRINT "(3)";: ENDIF
ub = 42: ud = ub: IF ud <> 42 THEN: PRINT "(4)";: ENDIF
PRINT

PRINT "16> 8) ";
sw = -42: sb = sw: IF sb <> -42 THEN: PRINT "(1)";: ENDIF
sw = -42: ub = sw: IF ub <> $D6 THEN: PRINT "(2)";: ENDIF
uw = 42: sb = uw: IF sb <> 42 THEN: PRINT "(3)";: ENDIF
uw = 42: ub = uw: IF ub <> 42 THEN: PRINT "(4)";: ENDIF
PRINT

PRINT "16>32) ";
sw = -42: sd = sw: IF sd <> -42 THEN: PRINT "(1)";: ENDIF
sw = -42: ud = sw: IF ud <> $FFFFFFD6 THEN: PRINT "(2)";: ENDIF
uw = 42: sd = uw: IF sd <> 42 THEN: PRINT "(3)";: ENDIF
uw = 42: ud = uw: IF ud <> 42 THEN: PRINT "(4)";: ENDIF
PRINT

PRINT "32> 8) ";
sd = -42: sb = sd: IF sb <> -42 THEN: PRINT "(1)";: ENDIF
sd = -42: ub = sd: IF ub <> $D6 THEN: PRINT "(2)";: ENDIF
ud = 42: sb = ud: IF sb <> 42 THEN: PRINT "(3)";: ENDIF
ud = 42: ub = ud: IF ub <> 42 THEN: PRINT "(4)";: ENDIF
PRINT

PRINT "32>16) ";
sd = -42: sw = sd: IF sw <> -42 THEN: PRINT "(1)";: ENDIF
sd = -42: uw = sd: IF uw <> $FFD6 THEN: PRINT "(2) = ";uw: ENDIF
ud = 42: sw = ud: IF sw <> 42 THEN: PRINT "(3)";: ENDIF
ud = 42: uw = ud: IF uw <> 42 THEN: PRINT "(4)";: ENDIF
PRINT

