REM @english
REM FLOW CONTROL POPPING FROM GOSUB
REM
REM This example will use the ''POP'' keyword, to demonstrate
REM the fact that the program can exit from a ''GOSUB'' call without
REM using a ''RETURN'' statement. The example will change the color of
REM the border in a deterministic way, by using the sum of two variables.
REM In order to increment the ''y'' variable in a different way when the ''x''
REM variable is greater than 7, the execution flow will call the ''POP''
REM instruction. The border color is changed using the ''COLOR BORDER'' 
REM instruction, using the sum of ''x'' and ''y''.
REM
REM @italian
REM CONTROLLO DI FLUSSO "SALTANDO FUORI"
REM
REM Questo esempio utilizzerà la parola chiave ''POP'', per dimostrare il fatto
REM che il programma può uscire da una chiamata ''GOSUB'' senza utilizzare 
REM un'istruzione ''RETURN''. L'esempio cambierà il colore del bordo in modo 
REM deterministico, utilizzando la somma di due variabili. Per incrementare la 
REM variabile ''y'' in modo diverso quando la variabile ''x'' è maggiore di 7, 
REM il flusso di esecuzione chiamerà l'istruzione ''POP''. Il colore del bordo 
REM viene modificato utilizzando l'istruzione ''COLOR BORDER'', utilizzando 
REM la somma delle variabili ''x'' e ''y''.
REM
REM @include atari,atarixl,c128,c64

   CLS

   x = 0
   y = 0
start:
   x = x + 1
   COLOR BORDER x + y
   HOME: PRINT x + y;"   "
   GOSUB incrementX
   GOTO start

nextCycle:
   y = y + 1
   IF y > 7 THEN : y = 0 : ENDIF
   GOTO start

incrementX:
   IF x > 7 THEN : POP : x = 0 : GOTO nextCycle : ENDIF
   RETURN
