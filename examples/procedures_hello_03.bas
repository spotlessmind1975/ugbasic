   REM Demonstrate that a procedure is being called not simply a command
   PROC hello
   
   REM The same can be achieved without the PROC
   hello
   
   REM The same can be achieved with the CALL command
   CALL hello
   
   PROCEDURE hello
      DEBUG "HEY!"
   END PROC

   HALT