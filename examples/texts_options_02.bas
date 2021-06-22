REM @english
REM TEXTS OUTPUT WITH PEN COLORS (2)
REM
REM This example shows how to use pen colors inside strings. In other words,
REM it is possible to embed an arbitrary number of ''PEN'' commands inside
REM a string. When the string is printed, the color of the pen will be
REM changed accordingly.
REM
REM @italian
REM STAMPA DI TESTI CON COLORI DI PENNA (2)
REM
REM Questo esempio mostra come utilizzare i colori della penna all'interno 
REM delle stringhe. In altre parole, è possibile incorporare un numero 
REM arbitrario di comandi ''PEN'' all'interno di una stringa. Quando 
REM la stringa viene stampata, il colore della penna verrà modificato di conseguenza.

    p$ = PEN$(WHITE)+"WELL ALL WHITE, "+PEN$(YELLOW)+" I STILL GOT THE YELLOW"

    PRINT p$    

    PEN RED
    PRINT "IN THE RED"

    HALT