REM @english
REM MATHEMATIC ROUTINES FAST OPERATIONS (USING DIV)
REM
REM This example will show the use of fast integer operators, with the use of ''DIV'' instruction. 
REM Those instructions will operate without the use of intermediate results, in order
REM to give the maximum throughtput in division and modulo values.
REM
REM @italian
REM ROUTINE DI MATEMATICA CON PRIORITA' ASSOCIATIVA (3)
REM
REM Questo esempio mostrerà l'uso di operatori interi veloci, con l'uso dell'istruzione ''MUL''. 
REM Tali istruzioni funzioneranno senza l'uso di risultati intermedi, al fine di fornire il massimo 
REM rendimento nel prodotto di valori. 
REM
REM @include atari,atarixl,c128,c64,coco

   CLS
   
   a% = 42
   b% = 10
   DIV a%, b%
   PRINT "42 / 10 = "; a%

   a% = 42
   DIV a%, b%, c%
   PRINT "42 / 10 = "; a%; " mod "; c%
   