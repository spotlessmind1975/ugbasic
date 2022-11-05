05 HOME
10 max = 5000
20 x = 1 : y = 1
30 IF (x > max) THEN 100
40 PRINT x
50 x = x + y
60 IF (y > max) THEN 100
70 PRINT y
80 y = x + y
90 GOTO 30
100 END
