 DO
    COLOR BORDER YELLOW
    WAIT 500 MS
    COLOR BORDER BLACK
    WAIT 500 MS
    DO
       COLOR BORDER RED
       WAIT 1000 MS
       EXIT
       REM The border will never be green!
       COLOR BORDER GREEN
       WAIT 1000 MS
    LOOP
 LOOP