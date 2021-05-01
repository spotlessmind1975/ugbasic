  a$ = "ugBASIC ********"
  RIGHT$( a$, 8 ) = "COMPILER"
  DEBUG a$: REM It print out "ugBASIC COMPILER"
  b$ = RIGHT$( a$, 8 )
  DEBUG b$: REM It print out "COMPILER"
  HALT
