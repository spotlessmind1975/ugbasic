/* <usermanual>
@keyword IF

@english
The ''IF'' function allows you to evaluate whether a certain expression is ''TRUE'' or ''FALSE''. 
Depending on that check, the function will return the second (if ''TRUE'') or third (if ''FALSE'') 
argument. This function evaluates the expression at compile time: it follows that the return 
value does not change at runtime. This function is particularly useful for carrying out a
conditional evaluation of constants which, otherwise, would require evaluation at runtime, 
wasting time and occupying useless space.

@italian
La funzione IF consente di valutare se una certa espressione è vera o falsa. A seconda di 
tale controllo, la funzione restituirà il secondo argomento (se vero) o il terzo (se falso). 
Questa funzione valuta l'espressione la momento della compilazione: ne consegue che il valore
restituito non cambia in fase di runtime. Questa funzione è particolarmente utile per 
effettuare una valorizzazione condizionata di costanti che, altrimenti, richiederebbero una
valutazione a runtime, con perdita di tempo e occupazione di spazio inutile.

@syntax = IF ([condition], [expression], [expression] )

@example pictureToUse = IF(SCREEN WIDTH > 160, "large.png", "small.png" )

@target all
</usermanual> */

/* <usermanual>
@keyword FONT WIDTH

@english
This function allows you to obtain the width of the current font, expressed in pixels. 
The width depends on the currently selected graphics mode, and it can change at runtime.

There is also a compile-level function for this keyword, which is called when the value 
is used to initialize a constant. In this case, the value is that taken from inspecting 
the instructions at the time of compilation.

@italian
Questa funzione permette di ottenere la larghezza del font corrente, 
espressa in pixels. La larghezza dipende dall'attuale modalità grafica 
selezionata, e può cambiare in sede di esecuzione.

Di questa parola chiave esiste anche una funzione a livello di compilazione, 
che viene richiamata quando il valore viene utilizzato per inizializzare una 
costante. In tal caso, il valore è quello desunto dall'ispezione delle 
istruzioni al momento della compilazione.

@syntax = FONT WIDTH

@example fontSize = FONT WIDTH

@target all
</usermanual> */

