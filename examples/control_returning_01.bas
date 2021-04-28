 start:
     GOSUB yellowBorder
     WAIT 1000 MS
     GOSUB blackBorder
     WAIT 1000 MS
     GOTO start
      
 yellowBorder:
     COLOR BORDER YELLOW
     RETURN
 
 blackBorder:
     COLOR BORDER BLACK
     RETURN