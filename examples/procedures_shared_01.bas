  PROCEDURE example
     SHARED a,b
     a = b - a
     b = b + 1
  END PROC

  a = 42
  b = 84
  
  example
  
  DEBUG a
  DEBUG b
  
  HALT
