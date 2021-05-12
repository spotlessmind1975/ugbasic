  PROCEDURE hello [name$]
     DEBUG "HELLO " + name$
  END PROC
  
  REM Load n$ into name$ and enter procedure
  hello ["WORLD"]
  
  REM Load string into name$ and call hello
  hello ["NICE TO MEET YOU!"]

  HALT