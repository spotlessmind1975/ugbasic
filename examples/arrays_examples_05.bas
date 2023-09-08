REM @english
REM ARRAY MANAGEMENT INITIALIZING
REM
REM This small example will show how to initialize each element of an
REM array, at compile time. This will reduce the footprint in terms of
REM time and space.
REM 
REM @italian
REM GESTIONE DEGLI ARRAY INIZIALIZZAZIONE
REM
REM Questo piccolo esempio mostra come inizializzare ogni elemento di
REM un array, al momento della compilazione. Questo riduce l'ingombro
REM in termini di tempo e spazio.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

    CLS

    DIM a AS BYTE(2,2) = #[42841020]
    DIM b AS BYTE(2,2) = #{ $42, $84, $10, $20 }
    DIM c AS BYTE(2,2) = #{ $42, $84, _
    $10, $20 }

    FOR y = 0 TO 1
        FOR x = 0 TO 1
            IF ( a(x,y) <> b(x,y) ) OR ( a(x,y) <> c(x,y) ) THEN
                PRINT "Check failed at ";x;",";y
                EXIT 2
            ENDIF
        NEXT
    NEXT

    PRINT "a(0,0) = ";a(0,0);" (expected 66)"
    PRINT "a(1,0) = ";a(1,0);" (expected 132)"
    PRINT "a(0,1) = ";a(0,1);" (expected 16)"
    PRINT "a(1,1) = ";a(1,1);" (expected 32)"

