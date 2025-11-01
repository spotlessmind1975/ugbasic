REM @english
REM TEXTS OUTPUT CHANGE WRITING MODE (USING WRITING)
REM
REM This example shows the various combination allowed when using the ''WRITING'' command,
REM and its effects in terms on graphical effects. Note that the text output will be the
REM same for every call, while the output will differ in base of ''WROTR'
REM
REM @italian
REM STAMPA DI TESTI CON MODALITA' DI SCRITTURA (1)
REM
REM Questo esempio mostra le varie combinazioni permette quando si utilizza il comando ''WRITING''
REM e i loro effetti in termini di resa grafica. Da notare che il testo di output sarà lo stesso
REM per ogni chiamata, mentre la resa differirà in base al valore attuale di ''WRITING''.
REM
REM @include c128,coco3

    CLS

    t$ = PEN$(YELLOW)+"YELLOW ON "+PAPER$(BLUE)+" BLUE"

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING REPLACE, NORMAL
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING REPLACE, PAPER
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING REPLACE, PEN
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING OR, NORMAL
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING OR, PAPER
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING OR, PEN
    PRINT t$
    WAIT 500 MS
    
    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING XOR, NORMAL
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING XOR, PAPER
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING XOR, PEN
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING AND, NORMAL
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING AND, PAPER
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING AND, PEN
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING IGNORE, NORMAL
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING IGNORE, PAPER
    PRINT t$
    WAIT 500 MS

    PEN DEFAULT PEN
    PAPER DEFAULT PAPER
    WRITING IGNORE, PEN
    PRINT t$
    WAIT 500 MS
