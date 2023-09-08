REM @english
REM MATHEMATIC ROUTINES RANDOM VALUES (USING RANDOMIZE)
REM
REM This example will show the generation of random value. The function used is ''RND(...)'' that
REM generate a random number between 0 and the value gived as argument. This function will
REM be applied to a constant value, in order to show the variability of random output when
REM ''RANDOMIZE'' is called before.
REM
REM @italian
REM ROUTINE DI MATEMATICA CON VALORI CASUALI (2)
REM
REM Questo esempio mostrerà la generazione di un valore casuale. La funzione utilizzata è ''RND(...)'' 
REM che genera un numero casuale compreso tra 0 e il valore dato come argomento. Questa funzione 
REM verrà applicata a un numero costante, per mostrare la variabilità casuale dell'output quando viene
REM richiamata prima l'istruzione ''RANDOMIZE''.
REM
REM @include atari,atarixl,c128,c64,coleco,cpc

    CLS
    
    RANDOMIZE TIMER
    
    PRINT "random value = ";RND(42)
