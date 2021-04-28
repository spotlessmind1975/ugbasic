 DO
    COLOR BORDER YELLOW
    WAIT 500 MS
    COLOR BORDER BLACK
    WAIT 500 MS
    DO
       COLOR BORDER RED
       WAIT 1000 MS
       COLOR BORDER GREEN
       WAIT 1000 MS
       DO
          COLOR BORDER RED
          WAIT 1000 MS
          EXIT 2 : REM EXIT 2 = skip 1 more loop, because "EXIT" == "EXIT 1"!
          REM The border will never be green,
          REM and the secondo loop will be skiped
          COLOR BORDER GREEN
          WAIT 1000 MS
       LOOP
    LOOP
 LOOP