REM @english
REM STRING MANIPULATION ITERATIVE MID
REM
REM This example shows the extraction of a substring from the very same string.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE MID ITERATIVI
REM
REM Questo esempio mostra come estrarre sottostringhe dalla stessa stringa.

    CLS

    text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    PRINT text

    text = MID$(text,2) 
    PRINT text
    text = MID$(text,2)
    PRINT text
    text = MID$(text,2)
    PRINT text
    text = MID$(text,2)
    PRINT text
    