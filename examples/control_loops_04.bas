REM @english
REM FLOW CONTROL MIXED DO..LOOP AND WHILE..WEND
REM
REM This small example will use the ''DO...LOOP'' keywords to implement
REM an endless loop, and the ''WHILE...WEND'' keywords to implement a
REM limited loop. The inner loop will run for 10 times, while ''x'' is
REM greater than zero. For each inner loop, the number will be printed.
REM So we expect to obtain the an endless flow of numbers from 10 to 1.
REM This example also shows how automatic scrolling works, when the end 
REM of the screen is reached with the use of the ''PRINT'' command.
REM Finally, the initial value will be represented by a single byte,
REM by using a syntax called "explicit cast" (''(8BIT)'').
REM 
REM @italian
REM CONTROLLO DI FLUSSO MESCOLANDO DO..LOOP E WHILE..WEND
REM
REM Questo piccolo esempio utilizzerà le parole chiave ''DO...LOOP'' per 
REM implementare un ciclo infinito e le parole chiave ''WHILE...WEND'' per 
REM implementare un ciclo. Il ciclo interno verrà eseguito per 10 volte, 
REM mentre ''x'' è maggiore di zero. Per ogni ciclo interno, verrà stampato 
REM il numero. Quindi ci aspettiamo di ottenere un flusso infinito di numeri 
REM da 10 a 1. Questo esempio mostra anche come funziona lo scorrimento 
REM automatico, quando si raggiunge la fine della schermata con l'uso del 
REM comando ''PRINT''. Infine, il valore iniziale sarà rappresentato da 
REM un singolo byte, utilizzando una sintassi chiamata "cast esplicito"
REM (''(8BIT)'').
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000,cpc

    CLS

    DO
        x = (8BIT) 10
        WHILE x > 0
            PRINT x;" ";
            x = x - 1
        WEND
    LOOP
