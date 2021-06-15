  colorIndex = 0
  
  EVERY 50 TICKS GOSUB changeBorderColor
  
  EVERY ON

  HALT
  
  changeBorderColor:
     COLOR BORDER colorIndex
     colorIndex = colorIndex + 1
     IF colorIndex > 16 THEN
        colorIndex = 0
     ENDIF
     EVERY ON
     RETURN