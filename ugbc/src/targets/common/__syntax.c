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

/* <usermanual>
@keyword FONT HEIGHT

@english
This function allows you to obtain the height of the current font, expressed in pixels. 
The height depends on the currently selected graphics mode, and it can change at runtime.

There is also a compile-level function for this keyword, which is called when the value 
is used to initialize a constant. In this case, the value is that taken from inspecting 
the instructions at the time of compilation.

@italian
Questa funzione permette di ottenere l'altezza del font corrente, 
espressa in pixels. L'altezza dipende dall'attuale modalità grafica 
selezionata, e può cambiare in sede di esecuzione.

Di questa parola chiave esiste anche una funzione a livello di compilazione, 
che viene richiamata quando il valore viene utilizzato per inizializzare una 
costante. In tal caso, il valore è quello desunto dall'ispezione delle 
istruzioni al momento della compilazione.

@syntax = FONT HEIGHT

@example fontSize = FONT HEIGHT

@target all
</usermanual> */

/* <usermanual>
@keyword hash (operator)

@english
In general, the hash operator (`#`) allows you to indicate the will to refer, 
explicitly, to a constant rather than to a value mediated by a variable. 
Without this operator, ugBASIC may decide to make a temporary copy of the 
value before using it. This can be inefficient. Therefore it is possible to 
indicate the will to actually refer to the equivalent value. 
For this reason, this operator works only if it is used with a constant value 
(eg: an integer) or with the name of a constant.

@italian
In generale, l'operatore hash (`#`) permette di indicare la volontà di fare riferimento, 
in modo esplicito, ad una costante piuttosto che ad un valore mediato da una variabile. 
Senza questo operatore, ugBASIC potrebbe decidere di fare una copia temporanea del valore
prima di usarlo. Questo può essere inefficiente. Pertanto è possibile indicare la volontà 
di riferirsi effettivamente al valore. Per questo motivo questo operatore funziona solo 
se utilizzato con un valore costante (es: un intero) o con il nome di una costante.

@syntax = # [constant]

@example fontSize = #constantSize
@example fontSize = #42

@target all
</usermanual> */
