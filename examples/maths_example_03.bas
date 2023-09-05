REM @english
REM MATHEMATIC ROUTINES ASSOCIATIVE PRIORITY (SUMS AND PRODUCTS)
REM
REM This example will show the application of associative priority. Since multiplication (''*'') has
REM a greater priority in respect of sum (''+''), and since the parentesys (''(...)'') change the
REM priority of application, the result of the two expression is different.
REM
REM @italian
REM ROUTINE DI MATEMATICA CON PRIORITA' ASSOCIATIVA (1)
REM
REM Questo esempio mostrerà l'applicazione della priorità associativa. Poiché la moltiplicazione (''*'') 
REM ha una priorità maggiore rispetto alla somma (''+''), e poiché le parentesi (''(...)'') cambiano la 
REM priorità di applicazione, il risultato della due espressioni sarà diverso.
REM
REM @include atari,atarixl,c128,c64

    CLS
    
    PRINT "(2+2*2)   = ";(2+2*2)
    PRINT "((2+2)*2) = ";((2+2)*2)
    