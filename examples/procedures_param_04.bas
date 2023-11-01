REM @english
REM USER-DEFINED PROCEDURES RETURN VALUE (USING RETURN) (3)
REM
REM This example will demonstrate how to return a value.
REM
REM @italian
REM USARE LE PROCEDURE CON PARAMETRI (3)
REM
REM Questo esempio dimostrerà come definire procedure per restituire valori.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

     CLS
   
     PROCEDURE test[x]
          IF x > 0 THEN
               RETURN TRUE
          ELSE
               RETURN FALSE
          ENDIF
     END PROC

     IF test[42] THEN
          PRINT "42 > 0!"
     ELSE
          PRINT "42 <= 0!"
     ENDIF

  
