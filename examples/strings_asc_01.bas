REM @english
REM STRING MANIPULATION ASCII VALUE (USING ASC())
REM
REM This example shows how ''ASC'' function works. It converts the given
REM parameter (''"0"'') into ASCII code, and print it on the screen.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE CON L'USO DI ASC (1)
REM
REM Questo esempio mostra come funziona ''ASC''. Questa funzione converte
REM il parametro dato (la stringa ''"0"'') nel valore ASCII corrispondente,
REM e lo stampa sullo schermo.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,pc128op,to8,cpc

  CLS

  PRINT "0 = ";ASC("0");" ASCII CODE"
