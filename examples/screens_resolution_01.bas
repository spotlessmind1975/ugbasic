  BITMAP ENABLE (320,200,16): REM at least 320x200 pixels, with 16 colors
  BITMAP ENABLE (320,,4): REM at least 320 pixels of width, with 4 colors
  BITMAP ENABLE (,256,2): REM at least 256 pixels of height, with 2 colors
  BITMAP ENABLE (320,200): REM at least 320x200 pixels, with any number of colors
  BITMAP ENABLE (320,): REM at least 320 pixels of width, with any number of colors
  BITMAP ENABLE (): REM it is equivalent to BITMAP ENABLE
  BITMAP ENABLE (,): REM it is equivalent to BITMAP ENABLE
  BITMAP ENABLE (,,): REM it is equivalent to BITMAP ENABLE
  
  TILEMAP ENABLE (40,25,16)
  TILEMAP ENABLE (32,,2)