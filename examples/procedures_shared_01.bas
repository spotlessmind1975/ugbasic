  PROCEDURE example
     SHARED a,b
     a = b - a
     b = b + 1
  END PROC

  a = 42
  b = 84
  
  example
  
  PRINT a;" ";
  PRINT b;" ";
  
  HALT
