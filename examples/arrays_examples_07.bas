REM ARRAY MANAGEMENT INIZIALIZATION
REM
REM This small example will show how to define arrays
REM with different data types, and initialize them.
REM
REM @italian
REM GESTIONE DEGLI ARRAY INIZIALIZZAZIONE
REM
REM Questo piccolo esempio mostra come definire array
REM con differenti tipi di dato, e come inizializzarli.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc,vic20,zx

DIM integers(4) WITH 42
PRINT "integers(1) should be 42: ";integers(1)

DIM integers2(3,2) = #{ 10, 20, 30, 40, 50, 60 }
PRINT "integers2(1,0) should be 30: ";integers2(1,0)

DIM integers3(3,2) = #[0010002000030004000500060]
PRINT "integers3(1,0) should be 48: ";integers3(1,0)

