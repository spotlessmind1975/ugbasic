  a$ = "ugBASIC ********"
  RIGHT$( a$, 8 ) = "COMPILER"
  PRINT a$;" ";: REM It print out "ugBASIC COMPILER"
  b$ = RIGHT$( a$, 8 )
  PRINT b$;" ";: REM It print out "COMPILER"
  HALT
