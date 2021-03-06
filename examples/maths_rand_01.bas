REM @english
REM MATHEMATIC ROUTINES WITH RANDOM VALUES (1)
REM
REM This example will show the generation of random value. The function used is ''RND(...)'' that
REM generate a random number between 0 and the value gived as argument. This function will
REM be applied to the current screen width and height, in order to print a string on the
REM screen at random position.
REM
REM @italian
REM ROUTINE DI MATEMATICA CON VALORI CASUALI (1)
REM
REM Questo esempio mostrerà la generazione di un valore casuale. La funzione utilizzata è ''RND(...)'' 
REM che genera un numero casuale compreso tra 0 e il valore dato come argomento. Questa funzione 
REM verrà applicata alla larghezza e all'altezza dello schermo correnti, in modo da stampare una stringa
REM sullo schermo in una posizione casuale.

   DO 
      x = RND(SCREEN WIDTH - 1): REM you can use "RANDOM WIDTH" as an alternative
      y = RND(SCREEN HEIGHT - 1): REM you can use "RANDOM HEIGHT" as an alternative
      TEXT x, y, "UGBASIC AT RANDOM"
   LOOP
 