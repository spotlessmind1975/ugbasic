REM @english
REM MATHEMATIC ROUTINES FAST OPERATIONS (USING INC/DEC)
REM
REM This example will show the use of fast integer operators, with the use of ''INC'' and ''DEC''
REM instructions. Those instructions will operate without the use of intermediate results, in order
REM to give the maximum throughtput in increasing and decreasing values. The result will print
REM on the screen.
REM
REM @italian
REM ROUTINE DI MATEMATICA CON PRIORITA' ASSOCIATIVA (2)
REM
REM Questo esempio mostrerà l'uso di operatori interi veloci, con l'uso delle istruzioni ''INC''
REM e ''DEC''. Tali istruzioni funzioneranno senza l'uso di risultati intermedi, al fine di fornire 
REM il massimo rendimento nell'incremento o decremento di valori. Il risultato sarà stampato sullo schermo.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

   CLS
   
   v=41
   PRINT "INC ";v;" = ";
   INC v
   PRINT v

   v=43
   PRINT "DEC ";v;" = ";
   DEC v
   PRINT v
