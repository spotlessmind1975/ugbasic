REM @english
REM ARRAY MANAGEMENT INITIALIZING (3)
REM
REM This small example will show how to initialize each element of an
REM array, at compile time. This will reduce the footprint in terms of
REM time and space.
REM 
REM @italian
REM GESTIONE DEGLI ARRAY INIZIALIZZAZIONE (3)
REM
REM Questo piccolo esempio mostra come inizializzare ogni elemento di
REM un array, al momento della compilazione. Questo riduce l'ingombro
REM in termini di tempo e spazio.
REM


DIM a AS BYTE(2,2) = #{ $42, $84, _
$10, $20 }

PRINT "a(0,0) = ";a(0,0);" (expected 66)"
PRINT "a(1,0) = ";a(1,0);" (expected 132)"
PRINT "a(0,1) = ";a(0,1);" (expected 16)"
PRINT "a(1,1) = ";a(1,1);" (expected 32)"

ARRAY a = #{ $20, $21, $22, $23 }

PRINT "a(0,0) = ";a(0,0);" (expected 32)"
PRINT "a(1,0) = ";a(1,0);" (expected 33)"
PRINT "a(0,1) = ";a(0,1);" (expected 34)"
PRINT "a(1,1) = ";a(1,1);" (expected 35)"
