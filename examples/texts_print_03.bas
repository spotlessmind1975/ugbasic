REM @english
REM TEXTS OUTPUT ON MULTICOLOR BITMAP (1)
REM
REM This example will show the effect of printing on monocolor bitmap and multicolor bitmap.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI PLOT (4)
REM
REM Questo esempio mostrerà gli effetti di stampare sulle bitmap monocromatiche e su quelle multicolor.

  BITMAP ENABLE (1)
  CLS BLACK
  INK WHITE
  PRINT "hires printing"

  WAIT KEY

  BITMAP ENABLE (4)
  CLS BLACK
  INK RED
  PRINT "lores printing"

  HALT