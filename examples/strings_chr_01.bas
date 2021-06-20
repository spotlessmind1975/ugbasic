REM @english
REM STRING MANIPULATION WITH CHR (1)
REM
REM This example print out a short list of printable characters.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE CON L'USO DI CHR (1)
REM
REM Questo esempio stampa un breve elenco di caratteri stampabili.

  FOR i = 32 TO 256
    PRINT CHR(i);" ";
  NEXT

  HALT