  v=0
  REPEAT
     ADD v,1,1 TO 42
     PRINT v;" ";
  UNTIL v == 43 : REM This loop is infinite because v < 43
  HALT