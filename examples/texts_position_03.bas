REM @english
REM TEXTS OUTPUT TEXT POSITIONING (USING CMOVE)
REM
REM This example shows the use of ''CMOVE'' command to set the next
REM output position by using a relative measure (offset from current position). 
REM If the coordinates' component is omitted this means that the offset along that component
REM is 0 (remain in the same position).
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (3)
REM
REM Questo esempio mostra l'uso del comando ''CMOVE'' per reimpostare la
REM posizione per il successivo output sullo schermo, con l'utilizzo di misure
REM relative (scostamenti rispetto alla posizione corrente). Se una delle componenti
REM delle coordinate è omessa, questo significa che l'offset corrispondente è pari a
REM zero, quindi rimane sulla medesima posizione.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

   CLS

   PRINT "ICELAND"

   CMOVE 5,5
   PRINT "SCOTLAND"

   CMOVE ,-3
   PRINT "NORWAY"

   CMOVE 10,14
   PRINT "FRANCE"
