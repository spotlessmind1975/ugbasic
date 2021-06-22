REM @english
REM TEXTS OUTPUT WITH PAPER COLORS (2)
REM
REM This example shows how to use pen colors inside strings. In other words,
REM it is possible to embed an arbitrary number of ''PAPER'' commands inside
REM a string. When the string is printed, the color of the paper will be
REM changed accordingly.
REM
REM @italian
REM STAMPA DI TESTI CON COLORI DI SFONDO (2)
REM
REM Questo esempio mostra come utilizzare i colori dello sfondo all'interno 
REM delle stringhe. In altre parole, è possibile incorporare un numero 
REM arbitrario di comandi ''PAPER'' all'interno di una stringa. Quando 
REM la stringa viene stampata, il colore dello sfondo verrà modificato di conseguenza.

    PEN BLACK

    b$=PAPER$(RED)+"BLACK ON RED"+PAPER$(BLACK)+"BLACK ON BLACK"

    PRINT b$

    HALT