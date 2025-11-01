REM @english
REM MATHEMATIC ROUTINES MINIMUM VALUE (USING MIN)
REM
REM This example will show the behaviour of ''MIN'' operator in a couple of situations: when
REM integers are compared and when strings are.
REM
REM @italian
REM ROUTINE DI MATEMATICA CON L'USO DI MIN
REM
REM Questo esempio mostrerà il comportamento dell'operatore ''MIN'' in un paio di situazioni:
REM quando gli interi sono confrontati e quando lo sono le stringhe.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

 CLS

 PRINT "MIN(99,1) = ";MIN(99,1)
 PRINT "MIN(UGBASIC,AAAA) = ";MIN("UGBASIC","AAAA")
 