REM @english
REM MATHEMATIC ROUTINES FAST OPERATIONS (USING ADD)
REM
REM This example will show the use of fast integer operators, with the use of ''ADD'' instruction. 
REM Those instructions will operate without the use of intermediate results, in order
REM to give the maximum throughtput in adding values. In this particular example, the ''ADD'' will be
REM used in a form of "controlled loop". So a loop that should stop when a given variable reach
REM a particular valure will continue forever, since ''ADD'' will limit the value of the variable
REM between a range that is in the limit of the loop.
REM
REM @italian
REM ROUTINE DI MATEMATICA CON PRIORITA' ASSOCIATIVA (2)
REM
REM Questo esempio mostrerà l'uso di operatori interi veloci, con l'uso dell'istruzione ''ADD''. 
REM Tali istruzioni funzioneranno senza l'uso di risultati intermedi, al fine di fornire il massimo 
REM rendimento nell'aggiunta di valori. In questo particolare esempio, ''ADD'' verrà utilizzato in 
REM una forma di "loop controllato". Quindi un ciclo che dovrebbe interrompersi quando una data 
REM variabile raggiunge un particolare valore continuerà per sempre, poiché ''ADD'' limiterà il
REM valore della variabile tra un intervallo che è nel limite del ciclo.
REM
REM @include atari,atarixl,c128,c64,coco

   CLS
   
   v=0
   
   REPEAT
      ADD v,1,1 TO 42
      PRINT v;" ";
   UNTIL v == 43
