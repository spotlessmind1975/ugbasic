/* <usermanual>
@keyword IF

@english

The ''IF'' function allows you to evaluate whether a certain expression is ''TRUE'' (not 0) or ''FALSE''. 
(0). Depending on that check, the function will return the second (if ''TRUE'') or third (if ''FALSE'') 
argument. 

This function evaluates the expression at compile time: it follows that the return 
value does not change at runtime. There are three versions of this function, one for each 
type of value that can be returned. There is a version that returns integers, one for 
floating point numbers, and one for strings.

This function is particularly useful for carrying out a conditional evaluation of constants which, 
otherwise, would require evaluation at runtime, wasting time and occupying useless space.

@italian
La funzione IF consente di valutare se una certa espressione è vera o falsa. A seconda di 
tale controllo, la funzione restituirà il secondo argomento (se vero) o il terzo (se falso). 

Questa funzione valuta l'espressione la momento della compilazione: ne consegue che il valore
restituito non cambia in fase di runtime. Esistono tre versioni di questa funzione, una per 
ogni tipo di valore che può essere restituito. Esiste la versione che restituisce numeri interi, 
una per i numeri in virgola mobile e una per le stringhe.

Questa funzione è particolarmente utile per effettuare una valorizzazione condizionata di costanti 
che, altrimenti, richiederebbero una valutazione a runtime, con perdita di tempo e occupazione 
di spazio inutile.

@syntax = IF (exp, valueTrue, valueFalse )


@example pictureToUse = IF(SCREEN WIDTH > 160, "large.png", "small.png" )
@target all
@version
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
@keyword hash operator

@english
In general, the hash operator (''#'') allows you to indicate the will to refer, 
explicitly, to a constant rather than to a value mediated by a variable. 
Without this operator, ugBASIC may decide to make a temporary copy of the 
value before using it. This can be inefficient. Therefore it is possible to 
indicate the will to actually refer to the equivalent value. 
For this reason, this operator works only if it is used with a constant value 
(eg: an integer) or with the name of a constant.

@italian
In generale, l'operatore hash (''#'') permette di indicare la volontà di fare riferimento, 
in modo esplicito, ad una costante piuttosto che ad un valore mediato da una variabile. 
Senza questo operatore, ugBASIC potrebbe decidere di fare una copia temporanea del valore
prima di usarlo. Questo può essere inefficiente. Pertanto è possibile indicare la volontà 
di riferirsi effettivamente al valore. Per questo motivo questo operatore funziona solo 
se utilizzato con un valore costante (es: un intero) o con il nome di una costante.

@syntax = #constant

@example fontSize = #constantSize
@example fontSize = #42

@target all
</usermanual> */

/* <usermanual>
@keyword BLACK

@english
This keyword represents the color black. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space, usually ''(0,0,0)''. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore nero. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB, di solito ''(0,0,0)''. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = BLACK

@example PEN BLACK

@usedInExample control_loops_01.bas
@usedInExample graphics_clip_01.bas
@usedInExample graphics_plot_01.bas
@usedInExample graphics_plot_02.bas

@target all
</usermanual> */

/* <usermanual>
@keyword WHITE

@english
This keyword represents the color white. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space, usually ''(255,255,255)''. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore bianco. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB, di solito ''(255,255,255)''. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

Qui di seguito si forniscono le componenti cromatiche per ogni target e chipset:

@syntax = WHITE

@example PEN WHITE

@usedInExample control_loops_01.bas
@usedInExample graphics_clip_01.bas
@usedInExample graphics_plot_01.bas
@usedInExample graphics_plot_02.bas

@target all
</usermanual> */

/* <usermanual>
@keyword RED

@english
This keyword represents the color red. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space, usually ''(255,0,0)''. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore rosso. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB, di solito ''(255,0,0)''. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = RED

@example PEN RED

@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas
@usedInExample graphics_color_01.bas
@usedInExample graphics_plot_03.bas

@target all
</usermanual> */

/* <usermanual>
@keyword CYAN

@english
This keyword represents the color cyan. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space, usually ''(170,255,230)''. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore ciano. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB, di solito ''(170,255,230)''. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = CYAN

@example PEN CYAN

@target all
</usermanual> */

/* <usermanual>
@keyword VIOLET

@english
This keyword represents the color violet. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space, usually ''(204,68,204)''. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore viola. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB, di solito ''(204,68,204)''. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = VIOLET

@example PEN VIOLET

@target all
</usermanual> */

/* <usermanual>
@keyword GREEN

@english
This keyword represents the color green. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space, usually ''(0,204,85)''. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore verde. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB, di solito ''(0,204,85)''. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = GREEN

@example PEN GREEN

@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas
@usedInExample screens_cls_03.bas

@target all
</usermanual> */

/* <usermanual>
@keyword BLUE

@english
This keyword represents the color blue. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space, usually ''(0,0,170)''. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore blue. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB, di solito ''(0,0,170)''. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = BLUE

@example PEN BLUE

@usedInExample screens_cls_03.bas
@usedInExample texts_options_06.bas

@target all
</usermanual> */

/* <usermanual>
@keyword YELLOW

@english
This keyword represents the color yellow. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space, usually ''(238,238,119)''. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore giallo. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB, di solito ''(238,238,119)''. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = YELLOW

@example PEN YELLOW

@usedInExample control_loops_01.bas
@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas
@usedInExample graphics_color_01.bas

@target all
</usermanual> */

/* <usermanual>
@keyword ORANGE

@english
This keyword represents the color orange. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space, usually ''(161, 104, 60)''. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore arancio. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB, di solito ''(161, 104, 60)''. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = ORANGE

@example PEN ORANGE

@usedInExample control_loops_01.bas
@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas
@usedInExample graphics_color_01.bas

@target all
</usermanual> */

/* <usermanual>
@keyword BROWN

@english
This keyword represents the color brown. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space, usually ''(221, 136, 101)''. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore marrone. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB, di solito ''(221, 136, 101)''. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = BROWN

@example PEN BROWN

@target all
</usermanual> */

/* <usermanual>
@keyword LIGHT RED

@english
This keyword represents the color light red. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore rosso chiaro. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = LIGHT RED

@example PEN LIGHT RED

@target all
</usermanual> */

/* <usermanual>
@keyword DARK GREY

@english
This keyword represents the color dark grey. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore grigio scuro. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = DARK GREY

@example PEN DARK GREY

@target all
</usermanual> */

/* <usermanual>
@keyword GREY

@english
This keyword represents the color grey. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore grigio. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = GREY

@example PEN GREY

@target all
</usermanual> */

/* <usermanual>
@keyword LIGHT GREEN

@english
This keyword represents the color light green. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore verde chiaro. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = LIGHT GREEN

@example PEN LIGHT GREEN

@target all
</usermanual> */

/* <usermanual>
@keyword LIGHT BLUE

@english
This keyword represents the color light blue. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore blu chiaro. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = LIGHT BLUE

@example PEN LIGHT BLUE

@target all
</usermanual> */

/* <usermanual>
@keyword LIGHT GREY

@english
This keyword represents the color light grey. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore grigio chiaro. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = LIGHT GREY

@example PEN LIGHT GREY

@target all
</usermanual> */

/* <usermanual>
@keyword DARK BLUE

@english
This keyword represents the color dark blue. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore blu scuro. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = DARK BLUE

@example PEN DARK BLUE

@target all
</usermanual> */

/* <usermanual>
@keyword MAGENTA

@english
This keyword represents the color magenta. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore magenta. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = MAGENTA

@example PEN MAGENTA

@target all
</usermanual> */

/* <usermanual>
@keyword PURPLE

@english
This keyword represents the color purple. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore viola. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = PURPLE

@example PEN PURPLE

@target all
</usermanual> */

/* <usermanual>
@keyword LAVENDER

@english
This keyword represents the color lavender. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore lavanda. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = LAVENDER

@example PEN LAVENDER

@target all
</usermanual> */

/* <usermanual>
@keyword GOLD

@english
This keyword represents the color gold. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore oro. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = GOLD

@example PEN GOLD

@target all
</usermanual> */

/* <usermanual>
@keyword TURQUOISE

@english
This keyword represents the color turquoise. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore turchese. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = TURQUOISE

@example PEN TURQUOISE

@target all
</usermanual> */

/* <usermanual>
@keyword TAN

@english
This keyword represents the color tan. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore tanno. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = TAN

@example PEN TAN

@target all
</usermanual> */

/* <usermanual>
@keyword YELLOW GREEN

@english
This keyword represents the color yellow green. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore giallo verde. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = YELLOW GREEN

@example PEN YELLOW GREEN

@target all
</usermanual> */

/* <usermanual>
@keyword OLIVE GREEN

@english
This keyword represents the color olive green. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore verde olive. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = OLIVE GREEN

@example PEN OLIVE GREEN

@target all
</usermanual> */

/* <usermanual>
@keyword PINK

@english
This keyword represents the color pink. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore rosa. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = PINK

@example PEN PINK

@target all
</usermanual> */

/* <usermanual>
@keyword PEACH

@english
This keyword represents the color peach. Depending on the methodology and technique, 
as well as the available hardware, it can correspond to a specific color in the RGB 
space. However, not all computers have this color. In which case, 
it is approximated by the closest color available, which is usually also used in 
decoding images to identify the color to use.

@italian
Con questa parola chiave si rappresenta il colore pesca. A seconda della metodologia 
e della tecnica, nonché dell'hardware disponibile, può corrispondere a uno specifico 
colore nello spazio RGB. Tuttavia, non tutti i computer 
dispongono di un colore di questo tipo. Nel qual caso, viene approssimato dal 
colore più vicino, che di solito viene utilizzato anche nella decodifica delle 
immagini per individuare il colore da utilizzare.

@syntax = PEACH

@example PEN PEACH

@target all
</usermanual> */

/* <usermanual>
@keyword array operator

@english
In ugBASIC, arrays are accessed using the parenthesis operator (''('' and '')'') next to the name 
of the variable that contains the array. The indices must be inserted inside the brackets to 
access the individual elements of the array. 

There is no limit to the number of dimensions: 
however, the cardinality of indices must be the same as the one used when defining the
array itself. There is, also, a limit related to memory availability. Furthermore, 
access to locations is not controlled and therefore particular care must be taken not to exceed
the boundaries of the area intended to hold the information on the array.

When an array is accessed, it can be done in two ways: to retrieve a value (read access) 
or to set a value (write access). Read access occurs any time the array is used in an 
expression. Conversely, for write access, the indexed array must be used as the target variable.

In accessing the array, as in any other variable, the dollar sign (''$'') can be juxtaposed 
to indicate that you want to access a variable of type string. In this case, a further 
type check will be carried out during the compilation, to avoid referring to a variable
of numerical type.

@italian
In ugBASIC, si accede agli array utilizzando l'operatore parentesi (''('' e '')''), aggiunto
accanto al nome della variabile che contiene l'array. Gli indici devono essere inseriti 
all'interno delle parentesi per accedere ai singoli elementi dell'array. 

Non c'è limite al numero di dimensioni: tuttavia, la cardinalità degli indici deve essere la stessa 
di quella utilizzata nella definizione della matrice stessa. Esiste, inoltre, un limite 
relativo alla disponibilità di memoria. Per di più, l'accesso agli elementi non è controllato 
e pertanto si deve prestare particolare attenzione a non eccedere i confini dell'area 
destinata a contenere le informazioni sull'array.

Quando si accede a un array lo si può fare in due modi: per recuperare un valore 
(accesso in lettura) o per impostare un valore (accesso in scrittura). 
L'accesso in lettura avviene in qualsiasi momento l'array sia utilizzato in una 
espressione. Al contrario, per accedere in scrittura bisogna utilizzare l'array 
indicizzato come variabile di destinazione.

Nell'accesso all'array, come in qualsiasi altra variabile, può essere giustapposto il 
simbolo del dollaro (''$''), per indicare che si vuole accedere a una variabile di 
tipo stringa. In tal caso, un ulteriore controllo di tipo sarà svolto in sede di 
compilazione, per evitare di far riferimento a una variabile di tipo numerico.

@syntax ... = var( o1 [, i2 [, ...] ] )
@syntax var( o1 [, i2 [, ...] ] ) = expr
@syntax ... = var$( o1 [, i2 [, ...] ] )
@syntax var$( o1 [, i2 [, ...] ] ) = expr$

@example readElement = a(42,3)
@example b(1,1) = 42
@example word = words$(42)
@example words$(1) = "ok!"

@target all
</usermanual> */

/* <usermanual>
@keyword local task variable operator

@english
To guarantee the use of local variables within parallel procedures, since the procedure does 
not have a stack, it is necessary to prepare an array to contain this type of information. 
Therefore, using the array access operator, it is then possible to access the individual 
variables, using the task identifier as an index.

ugBASIC provides a compact form to indicate this type of access. Instead of writing ''v(THREAD)''
you can write ''[v]''. This operator, called the "local task variable operator", can be used 
anywhere, and in any expression, and can be used as the target of the variable.

In accessing the array, as in any other variable, the dollar sign (''$'') can be juxtaposed 
to indicate that you want to access a variable of type string. In this case, a further 
type check will be carried out during the compilation, to avoid referring to a variable
of numerical type.

@italian
Per garantire l'utilizzo di variabili locali all'interno di procedure parallele, essendo 
la procedura priva di uno stack, è necessario predisporre un array per contenere questo 
tipo di informazione. Utilizzando, quindi, l'operatore di accesso agli array, è quindi 
possibile accedere alle singole variabili, utilizzando come indice l'identificativo del task.

ugBASIC fornisce una forma compatta per indicare questo tipo di accesso. Invece di scrivere 
''v(THREAD)'' si può scrivere ''[v]''. Questo operatore, chiamato "local task variable operator", 
può essere utilizzato dovunque, e in qualsiasi espressione, e può essere utilizzato come 
destinazione della variabile.

Nell'accesso all'array, come in qualsiasi altra variabile, può essere giustapposto il 
simbolo del dollaro (''$''), per indicare che si vuole accedere a una variabile di 
tipo stringa. In tal caso, un ulteriore controllo di tipo sarà svolto in sede di 
compilazione, per evitare di far riferimento a una variabile di tipo numerico.

@syntax = [variable]
@syntax [variable] = expression
@syntax = [variable$]
@syntax [variable$] = expression

@example PUT IMAGE token AT [x],[y]
@example [x] = [x] + 1
@example PRINT [word$]
@example [word$] = "ok!"

@usedInExample multitasking_example_06.bas

@target all
</usermanual> */

/* <usermanual>
@keyword casting operator

@english
ugBASIC is a loosely typed language. However, there are occasions when the use of certain
types is not permitted without the explicit consent of the programmer. For this purpose, 
a "type casting" mechanism has been integrated very similar to that available in other 
programming languages, such as C. 

In a nutshell, it is possible to add an expression in brackets as a prefix an expression 
(enclosed by brackets) or an integer, which represents the type conversion you want to make. 
Conversion from one type to another always generates a temporary variable, which 
is why it is not possible to change the original value directly. This mechanism, 
therefore, has the sole purpose of ensuring that conversions always 
take place correctly.

@italian
ugBASIC è un linguaggio lascamente tipizzato. Tuttavia, vi sono delle occasioni in cui 
l'utilizzo di determinati tipi non è permesso senza l'esplicito consenso da parte 
del programmatore. A tale scopo è stato integrato un meccanismo di "type casting" 
molto simile a quello disponibile in altri linguaggi di programmazione, come il C. 

In estrema sintesi, è possibile aggiungere, come prefisso ad una espressione (racchiusa
tra parentesi) oppure a un intero, una espressione tra parentesi che rappresenta 
la conversione di tipo che si desidera effettuare. La conversione da un tipo ad un 
altro genera sempre una variabile temporanea, ragion per cui non è possibile modificare 
direttamente il valore originale. Questo meccanismo, quindi, ha il solo scopo di garantire 
che le conversioni avvengano sempre correttamente.

@syntax ... = ( type ) #value
@syntax ... = ( type ) (expression)

@example y = (POSITION) 42
@example x = 42: y = (POSITION) ( x )

@usedInExample multitasking_example_06.bas

@target all
</usermanual> */

/* <usermanual>
@keyword buffer definition

@english
ugBASIC is able to define a byte buffer "in line", ie directly in the code. 
This can be useful in those occasions where it is necessary to include 
binary data, not being able to access an external file. 

The definition of a buffer occurs with the sequence of the hash operator (''#'') 
followed by the opening square bracket (''[''), by the hexadecimal couples and, 
optionally, terminated by the closing square bracket.

@italian
ugBASIC è in grado di definire un buffer di byte "in linea", cioè direttamente nel codice. 
Questo può essere utile in quelle occasioni dove sia necessario includere un dato binario, 
non potendo accedere a un file esterno. 

La definizione di un buffer avviene con la sequenza dell'operatore hash (''#'') seguita 
dalla parentesi quadra aperta (''[''), dalle coppie esadecimali e, opzionalmente, 
terminata dalla parentesi quadra chiusa.

@syntax ... = #[xx...
@syntax ... = #[xx...]

@example y = #[424280
@example x = #[424280]

@usedInExample buffers_definition_01.bas

@target all
</usermanual> */

/* <usermanual>
@keyword SIZE

@english
To get the (static) size of a buffer you can use the ''SIZE'' command. This command 
will restore, in bytes, the size of the given buffer. It is possible to apply this 
command to any type of static data, such as ''BUFFER'', ''IMAGE'', ''IMAGES'' and 
constant strings.

@italian
Per ottenere la dimensione (statica) di un buffer è possibile utilizzare il comando ''SIZE''. 
Tale comando ripristinare, in bytes, la dimensione del buffer dato. E' possibile applicare 
questo comando a qualsiasi tipo di dato statico, quali ''BUFFER'', ''IMAGE'', ''IMAGES'' e
stringe costanti.

@syntax ... = SIZE([resource])

@example PRINT SIZE(image)

@usedInExample buffers_definition_02.bas
@usedInExample buffers_definition_03.bas

@target all
</usermanual> */

/* <usermanual>
@keyword FREE

@english
Retrieves the free space still available for strings, in terms of bytes. 
This is how many characters are still available to be stored. The maximum 
value when calling this function is that indicated by the 
''DEFINE STRING SPACE'' statement. The default value for string 
storage is 1024 bytes.

@italian
Recupera lo spazio libero ancora disponibile per le stringhe, in termini di bytes. 
Equivale a quanti caratteri sono ancora disponibili per essere memorizzati. Il 
valore massimo, nel richiamare questa funzione, è quello indicato 
dall'istruzione ''DEFINE STRING SPACE'', ed è pari a 1024 bytes se non viene
impostato diversamente.

@syntax ... = FREE

@example PRINT FREE

@seeAlso DEFINE STRING SPACE

@target all
</usermanual> */

/* <usermanual>
@keyword SCREEN

@english
Retrieves a bitmask with screen characteristics, such as whether or 
not TILE or BITMAP mode is available.

^ BIT POSITION ^ SYMBOL  ^ MEANING            ^
| 0            | TILEMAP | Is tilemap native? |
| 1            | BITMAP  | Is bitmap native?  |

This can be verified with a simple bitwise comparison.

@italian
Recupera una maschera di bit con le caratteristiche dello schermo, quali la 
disponibilità o meno della modalità TILE o BITMAP.

^ POSIZIONE BIT ^ SIMBOLO  ^ SIGNIFICATO                 ^
| 0             | TILEMAP  | Supporto al tilemap nativo? |
| 1             | BITMAP   | Supporto al bitmap nativo?  |

Si può verificare con un semplice confronto bit a bit.

@syntax ... = SCREEN

@example IF SCREEN IS TILEMAP THEN: PRINT "tilemap is native!": ENDIF

@usedInExample screens_bitmap_01.bas

@target all
</usermanual> */

/* <usermanual>
@keyword TILEMAP

@english
This is the bitmask used to select the TILE mode.

@italian
Questa è la maschera di bit per indicare la modalità TILE.

@syntax ... = TILEMAP

@example IF SCREEN IS TILEMAP THEN: PRINT "tilemap is native!": ENDIF

@usedInExample screens_bitmap_01.bas

@target all
</usermanual> */

/* <usermanual>
@keyword BITMAP

@english
This is the bitmask used to select the BITMAP mode.

@italian
Questa è la maschera di bit per indicare la modalità BITMAP.

@syntax ... = BITMAP

@example IF SCREEN IS BITMAP THEN: PRINT "bitmap is native!": ENDIF

@usedInExample screens_bitmap_01.bas

@target all
</usermanual> */

/* <usermanual>
@keyword CONST

@english
Using the ''CONST'' command allows you to define one or more constants, which will be used later 
in the program. Constants have the advantage of being calculated once and for 
all, at compile time, directly by the compiler and can be used to initialize 
variables. Furthermore, the constants are global, that is, they are always visible 
everywhere, both in the main program and within the procedures. Finally, constants 
do not take up memory space.

In the definition of the constants itself it is possible to indicate whether it must 
be positive or not, with the keyword ''POSITIVE''. This check is carried out at  
compilation time and, in the event of a negative result, it will result in a 
compilation error. This condition is useful to ensure that the preconditions related to
the hardware are respected (as happens, for example, when calculating the margins 
in the case of a screen smaller than the expected minimum).

It is also possible to define a validity range of the values that will be represented
in the constant. This interval is defined in a similar way to intervals in mathematics: 
using the square bracket means that the extremes (minimum, maximum) are included, 
while a round bracket means that the extremes are excluded.

@italian
L'uso del comando ''CONST'' permette di definire una costante, che sarà utilizzata 
successivamente nel programma. Le costanti hanno il vantaggio di essere calcolate 
una volta per tutte, al momento della compilazione, direttamente dal compilatore e 
possono essere usate per inizializzare le variabili. Inoltre, le costanti sono globali, 
cioè sono sempre visibili dovunque, sia nel programma principale che all'interno 
delle procedure. Infine, le costanti non occupano spazio in memoria.

Nella definizione stessa delle costanti è possibile indicare se la stessa deve 
essere o meno positiva (con la parola chiave ''POSITIVE''). Tale controllo viene 
svolto al momento della compilazione, e in caso dia esito negativo, darà luogo a 
un errore di compilazione. Tale condizione è utile per garantire che le precondizioni 
legate all'hardware siano rispettate (come avviene, ad esempio, calcolando i margini 
in caso di uno schermo più piccolo del minimo atteso).

E' anche possibile definire un intervallo di validità dei valori che saranno rappresentati 
nella costante. Tale intervallo viene definito con una modalità analoga agli intervalli 
in matematica: usando la parentesi quadra si intende che gli estremi (minimo, massimo) 
sono inclusi, mentre una parentesi tonda si intende che gli estremi sono esclusi.

@syntax [POSITIVE] CONST identifier = value
@syntax CONST identifier IN (min,max) = value
@syntax CONST identifier IN [min,max) = value
@syntax CONST identifier IN (min,max] = value
@syntax CONST identifier IN [min,max] = value

@example CONST x = 42
@example POSITIVE CONST y = -42: ' this raises an error!
@example CONST width IN (0,320] = 128

@usedInExample contrib_sierpinski.bas
@usedInExample contrib_sierpinski2.bas
@usedInExample contrib_sierpinski3.bas

@target all
</usermanual> */

/* <usermanual>
@keyword DIM

@english
The ''DIM'' command allows you to define a vector or a multidimensional array of values, 
and to initialize this array with the preferred values.

The simplest syntax is that which defines a vector of a single dimension: in this case, 
it is sufficient to indicate the number of elements in parentheses. With the keyword 
''AS'' you can indicate the data type of each single element. You can, of course, 
define a matrix (i.e. a vector with two or more dimensions). In this case it is 
sufficient to indicate the number of elements for each dimension, separating them 
with a comma.

By definition, the array will be initialized with a value of zero for each element. 
You can change this behavior by specifying an initialization by assignment. The 
initialization can be done by indicating each single value of each single element, 
with the same type of data with which the matrix was created (with the ''# {...}''
syntax ), or by describing the memory area that will occupy the array, byte by byte 
(with the ''# [...]'' syntax ).

@italian
Il comando ''DIM'' permette di definire un vettore o una matrice multidimensionale
di valori, e di inizializzare tale array con i valori che preferiamo.

La sintassi più semplice è quella che definisce un vettore di una singola dimensione:
in tal caso, è sufficiente indicare il numero di elementi tra parentesi.
Con la parola chiave ''AS'' si può indicare il tipo di dato di ogni singolo elemento.
Si può, ovviamente, definire una matrice (cioè un vettore con due o più dimensioni). 
In tal caso è sufficiente indicare il numero di elementi per ogni dimensione, 
separandoli con una virgola.

Per definizione, l'array sarà inizializzato con un valore pari a zero per ogni elemento. 
Si può cambiare tale comportamento indicando una inizializzazione per assegnazione.

L'inizializzazione può essere fatta indicando ogni singolo valore di ogni singolo 
elemento, con lo stesso tipo di dato con cui è stata creata la matrice 
(con la sintassi ''# { ... }''), oppure descrivendo l'area di memoria che 
occuperà la matrice, byte per byte (con la sintassi ''#[...]'').

@syntax DIM variable [AS datatype] [, variable [AS datatype] [ , variable [AS datatype] ] ]
@syntax DIM variable [AS datatype] = constant
@syntax DIM id [AS type] ( d1 [, d2 [ , ... ] ] )
@syntax DIM id [AS type] ( d1 [, d2 [ , ... ] ] ) = #[hex]
@syntax DIM id [AS type] ( d1 [, d2 [ , ... ] ] ) = #{v1, v2, ... }
@syntax DIM id [AS type] WITH v ( d1 [, d2 [ , ... ] ] )

@example DIM x(42)
@example DIM values AS DWORD(20,20)
@example DIM y AS BYTE(8) = #[ff80ff80ff80ff80]
@example DIM z AS BYTE(8) = _
@example              #{ 255, 128, 255, 128, 255, 128, 255, 128 }
@example DIM scores WITH 0 (2)

@usedInExample arrays_examples_01.bas
@usedInExample arrays_examples_02.bas
@usedInExample arrays_examples_03.bas
@usedInExample arrays_examples_04.bas
@usedInExample arrays_examples_05.bas
@usedInExample contrib_sierpinski.bas
@usedInExample contrib_sierpinski2.bas
@usedInExample contrib_sierpinski3.bas

@seeAlso VAR

@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE MAX X

@english
This constant allows us to know which is the largest abscissa 
(x) that can assume the horizontal position of a sprite. It 
may or may not coincide with the horizontal resolution of the 
screen, in the sense that some graphics chipsets can move 
sprites far beyond what is representable (example: border 
management on the VIC-II).

@italian
Questa costante permette di sapere qual è l'ascissa (x) più 
grande che può assumere la posizione orizzontale di uno sprite.
Può o meno coincidere con la risoluzione orizzontale dello 
schermo, nel senso che  alcuni chipset grafici possono muovere 
sprite ben oltre quello che è rappresentabile (esempio: 
la gestione dei bordi sul VIC-II).

@syntax = SPRITE MAX X

@example maxX = SPRITE MAX X

@target c64
</usermanual> */

/* <usermanual>
@keyword SPRITE MIN X

@english
This constant allows us to know which is the smallest abscissa 
(x) that can assume the horizontal position of a sprite. It 
may or may not coincide with zero of the 
screen, in the sense that some graphics chipsets can move 
sprites far beyond what is representable (example: border 
management on the VIC-II).

@italian
Questa costante permette di sapere qual è l'ascissa (x) più 
piccola che può assumere la posizione orizzontale di uno sprite.
Può o meno coincidere con la risoluzione orizzontale dello 
schermo, nel senso che  alcuni chipset grafici possono muovere 
sprite ben oltre quello che è rappresentabile (esempio: 
la gestione dei bordi sul VIC-II).

@syntax = SPRITE MIN X

@example minX = SPRITE MIN X

@target c64
</usermanual> */

/* <usermanual>
@keyword SPRITE MAX Y

@english
This constant allows us to know which is the largest ordinate
(y) that can assume the vertical position of a sprite. It 
may or may not coincide with the horizontal resolution of the 
screen, in the sense that some graphics chipsets can move 
sprites far beyond what is representable (example: border 
management on the VIC-II).

@italian
Questa costante permette di sapere qual è l'ordinata (y) più 
grande che può assumere la posizione verticale di uno sprite.
Può o meno coincidere con la risoluzione verticale dello 
schermo, nel senso che  alcuni chipset grafici possono muovere 
sprite ben oltre quello che è rappresentabile (esempio: 
la gestione dei bordi sul VIC-II).

@syntax = SPRITE MAX Y

@example maxY = SPRITE MAX Y

@target c64
</usermanual> */

/* <usermanual>
@keyword SPRITE MIN Y

@english
This constant allows us to know which is the smallest ordinate 
(y) that can assume the vertical position of a sprite. It 
may or may not coincide with zero of the 
screen, in the sense that some graphics chipsets can move 
sprites far beyond what is representable (example: border 
management on the VIC-II).

@italian
Questa costante permette di sapere qual è l'ordinata (y) più 
piccola che può assumere la posizione verticale di uno sprite.
Può o meno coincidere con lo zero dello 
schermo, nel senso che  alcuni chipset grafici possono muovere 
sprite ben oltre quello che è rappresentabile (esempio: 
la gestione dei bordi sul VIC-II).

@syntax = SPRITE MIN Y

@example minX = SPRITE MIN Y

@target c64
</usermanual> */

/* <usermanual>
@keyword WAIT FIRE

@english
This instruction allows you to wait for the pressure of the FIRE key on the 
joystick. If the port number is not indicated, it means the first available 
(the one with index 0). If the keyword ''RELEASE'' is appended,
the instruction will wait for the release of the key, as well.

@italian
Questa istruzione consente di attendere la pressione del tasto FIRE del
joystick. Se non viene indicato il numero della porta, si intende il
primo disponibile (quello con indice 0). Se viene aggiunta la parola chiave
''RELEASE'', l'istruzione attenderà anche il rilascio del tasto.

@syntax WAIT FIRE [(port)] [RELEASE]

@example WAIT FIRE

@target all
</usermanual> */

/* <usermanual>
@keyword WAIT KEY

@english
This instruction allows you to wait for any key to be pressed
key on the keyboard. If the keyword ''RELEASE'' is appended,
the instruction will wait for the release of the key, as well.

@italian
Questa istruzione consente di attendere la pressione di un qualsiasi
tasto sulla tastiera. Se viene aggiunta la parola chiave
''RELEASE'', l'istruzione attenderà anche il rilascio del tasto.

@syntax WAIT KEY [RELEASE]

@example WAIT KEY

@target all
</usermanual> */

/* <usermanual>
@keyword WAIT KEY OR FIRE

@english
This instruction allows you to wait for the pressure of the FIRE key on the 
joystick or any key from keyboard. If the port number is not indicated, it means the first available 
(the one with index 0). If the keyword ''RELEASE'' is appended,
the instruction will wait for the release of the key / fire button, as well.

@italian
Questa istruzione consente di attendere la pressione del tasto FIRE del
joystick, oppure di un tasto sulla tastiera. Se non viene indicato il numero della porta, si intende il
primo disponibile (quello con indice 0). Se viene aggiunta la parola chiave
''RELEASE'', l'istruzione attenderà anche il rilascio di entrambi i tasti.

@syntax WAIT KEY OR FIRE [([port])] [RELEASE]

@example WAIT KEY OR FIRE

@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE MIN Y

@english
This constant allows us to know which is the smallest ordinate 
(y) that can assume the vertical position of a sprite. It 
may or may not coincide with zero of the 
screen, in the sense that some graphics chipsets can move 
sprites far beyond what is representable (example: border 
management on the VIC-II).

@italian
Questa costante permette di sapere qual è l'ordinata (y) più 
piccola che può assumere la posizione verticale di uno sprite.
Può o meno coincidere con lo zero dello 
schermo, nel senso che  alcuni chipset grafici possono muovere 
sprite ben oltre quello che è rappresentabile (esempio: 
la gestione dei bordi sul VIC-II).

@syntax = SPRITE MIN Y

@example minX = SPRITE MIN Y

@target c64
</usermanual> */

/* <usermanual>
@keyword OPTION EXPLICIT

@english
When ''OPTION EXPLICT'' or ''OPTION EXPLICIT ON'' appears in a source file,
the programmer must explicitly declare all variables by using the ''VAR'' or
''DIM'' statements. 

If the programmer tries to use an undeclared variable 
name, an error occurs at compile time. The ''OPTION EXPLICT OFF'' statement 
allows implicit declaration of variables. If used, the ''OPTION EXPLICT'' 
statement can appear everywhere in a source file, before any other source 
code statements to check.

Setting ''OPTION EXPLICT OFF'' is generally not a good practice. The programmer
could misspell a variable name in one or more locations, which would cause 
unexpected results when the program is run.

@italian
Quando ''OPTION EXPLICT'' o ''OPTION EXPLICIT ON'' appare in un file sorgente, 
il programmatore deve dichiarare esplicitamente tutte le variabili usando le 
istruzioni ''VAR'' o ''DIM''.

Se il programmatore tenta di utilizzare un nome di variabile non dichiarato, 
si verifica un errore in fase di compilazione. L'istruzione ''OPTION EXPLICT OFF'' 
consente la dichiarazione implicita di variabili. Se utilizzata, l'istruzione 
''OPTION EXPLICT'' può apparire ovunque in un file sorgente, prima di qualsiasi 
altra istruzione del codice sorgente da controllare.

L'impostazione di ''OPTION EXPLICT OFF'' generalmente non è una buona pratica. 
Il programmatore potrebbe digitare in modo errato un nome di variabile in una 
o più posizioni, il che causerebbe risultati imprevisti durante l'esecuzione 
del programma.

@syntax OPTION EXPLICT [ON]
@syntax OPTION EXPLICT OFF

@example OPTION EXPLICIT ON

@target all
</usermanual> */

/* <usermanual>
@keyword ORIGIN

@english
The ''ORIGIN'' command can be used to set the origin of the cartesian axes with 
respect to which drawing instructions will operate. The command accepts the 
coordinates ''x, y'' of the origin, and the indication whether the Y axis is 
oriented upwards (''UP'') or downwards (''DOWN''). If not used, the reference 
system by default is placed at the top left with the Y axis downwards.

@italian
Il comando ''ORIGIN'' può essere utilizzato per impostare l'origine degli assi 
cartesiani rispetto ai quali opereranno le istruzioni di disegno. Il comando 
accetta le coordinate ''x, y'' dell'origine, e l'indicazione se l'asse delle 
Y è orientato verso l'alto (''UP'') oppure verso il basso (''DOWN''). 
Se non utilizzato, il sistema di riferimento per default viene posto in alto a 
sinistra con l'asse delle Y verso il basso. 

@syntax ORIGIN x, y UP
@syntax ORIGIN x, y [DOWN]

@example ORIGIN 100, 100 UP

@target all
</usermanual> */

/* <usermanual>
@keyword RESOLUTION

@english
This keyword allows to have a "virtual" resolution. Even when you select a graphical mode with only 
160 pixel x 200 pixel, the graphical instructions execute the same thing, the only difference is that 
the pixels will be proportional to virtual resolution. The choice to add this instruction is guided 
by mathematical ratio, since 640x400 pixels gives 1,6 where 640x200 gives 3,2. 1.6 isn't a perfect 
4/3 ratio but at least it's closer. By default, the virtual resolution will be set equal to the 
resolution given by ''BITMAP ENABLE''. Then, after ''RESOLUTION'', the graphical instructions 
will use this virtual resolution.

@italian
Questa parola chiave permette di avere una risoluzione "virtuale". Anche quando si seleziona una 
modalità grafica con soli 160 pixel x 200 pixel, le istruzioni grafiche funzioneranno con le
stesse identiche dimensioni. L'unica differenza è che i pixel saranno proporzionali alla 
risoluzione virtuale. La scelta di aggiungere questa istruzione è guidata dal rapporto matematico, 
poiché 640x400 pixel dà 1,6 dove 640x200 dà 3,2. 1.6 non è un perfetto rapporto 4/3 ma almeno è più 
vicino. Di default, la risoluzione virtuale sarà impostata uguale alla risoluzione data da 
''BITMAP ENABLE''. Quindi, dopo ''RESOLUTION'', le istruzioni grafiche utilizzeranno 
questa risoluzione virtuale.

@syntax RESOLUTION width, height

@example RESOLUTION 100, 100

@target all
</usermanual> */

/* <usermanual>
@keyword FONT LOAD

@english
The ''FONT LOAD'' command allows you to load an image and to convert it into
a font.

The command support a set of modern image format, like:

  * JPEG baseline & progressive

  * PNG 1/2/4/8/16-bit-per-channel

  * TGA

  * BMP (non-1bpp, non-RLE)

  * PSD (composited view only, no extra channels, 8/16 bit-per-channel)

  * GIF

  * HDR (radiance rgbE format)

  * PIC (Softimage PIC)

  * PNM (PPM and PGM binary only)

The image will be converted into a way that can be efficiently drawn
on the screen using the default characters.

It is also possible to indicate the index from which to start loading the various characters. 
The index is not the ASCII code but the screen code.

@italian
Il comando ''FONT LOAD'' permette di caricare un file immagine, e di convertirlo
in una serie di caratteri (font). 

Il comando supporta una serie di formati moderni:

  * JPEG baseline & progressive

  * PNG 1/2/4/8/16-bit-per-canale

  * TGA

  * BMP (non-1bpp, non-RLE)

  * PSD (vista composita, nessun canale extra, 8/16 bit-per-canale)

  * GIF

  * HDR (formato radiance rgbE)

  * PIC (Softimage PIC)

  * PNM (solo formato binario PPM e PGM)
  
L'immagine verrà convertita in un modo che possa essere disegnata in modo efficiente
sullo schermo. Potrebbe essere convertita in una tavolozza indicizzata, e potrebbe essere
anche ridimensionata.

E' inoltre possibile indicare l'indice da cui iniziare a caricare i vari caratteri. 
L'indice non è il codice ASCII ma lo screen code.

@syntax FONT LOAD filename [TO index]

@example FONT LOAD "digit0.png" TO 48

@target all
</usermanual> */
/* <usermanual>
@keyword DEFINE KEYBOARD RATE

@english
This command allows you to define the speed with which the characters will be 
received by the input system on repetition, with the INPUT or INKEY command. The speed depends
on the target, with a minimum value of 0 (maximum speed) to a maximum value of 
254 (minimum speed).

@italian
Questo comando permette di definire la velocità con la quale i caratteri saranno 
recepiti dal sistema di input in ripetizione, con il comando INPUT oppure INKEY. La velocità 
dipende dal target, con un valore minimo di 0 (massima velocità) a un valore 
massimo di 254 (minima velocità).

@syntax DEFINE KEYBOARD RATE value

@example DEFINE KEYBOARD RATE 123

@target atari
@target atarixl
@target c128
@target c128z
@target coco
@target coco3
@target cpc
@target d32
@target d64
@target mo5
@target msx1
@target pc128op
</usermanual> */
/* <usermanual>
@keyword DEFINE KEYBOARD DELAY

@english
This command allows you to define the delay to wait before the characters will be 
repeated by the input system, with the INPUT or INKEY command. The delay depends
on the target, with a minimum value of 1 (no delay) to a maximum value of 
255 (maximum delay).

@italian
Questo comando permette di definire il ritardo che il sistema attenderà
prima di iniziare la ripetizione dei caratteri  dal sistema di input, con il 
comando INPUT oppure INKEY. Il ritardo dipende dal target, con un valore minimo 
di 0 (nessun ritardo) a un valore massimo di 255 (massimo ritardo).

@syntax DEFINE KEYBOARD DELAY value

@example DEFINE KEYBOARD DELAY 50

@target atari
@target atarixl
@target c128
@target c128z
@target cpc
@target msx1
</usermanual> */

/* <usermanual>
@keyword REM

@english
The ''REM'' keyword is used to include explanatory remarks in the source code of a program.
In the text of any comment you want to include, that is optional, a space is required 
between the ''REM'' keyword and comment.

You can put a ''REM'' statement alone on a line, or you can put it on a line following 
another statement . The ''REM'' statement must be the last statement on the line. If it follows 
another statement, the ''REM'' must be separated from that statement by a colon ('':'').

You can use a single quotation mark (') instead of ''REM''. This is true whether your comment follows
another statement on the same line or sits alone on a line. However, you cannot continue a 
''REM'' statement by using a line-continuation sequence (''_''). This means that, for a multiple-line 
comment, you need to use as many ''REM''s statements as the lines you comment.

@italian
La parola chiave ''REM'' viene utilizzata per includere commenti esplicativi nel codice sorgente di 
un programma. Nel testo di qualsiasi commento che si desidera includere, e che è facoltativo, è 
richiesto uno spazio tra la parola chiave ''REM'' e il commento.

E' possibile introdurree un'istruzione ''REM'' da sola su una riga, oppure su una riga dopo un'altra 
istruzione. L'istruzione ''REM'' deve essere l'ultima istruzione sulla riga. Se segue un'altra istruzione, 
il ''REM'' deve essere separato da quell'istruzione con i due punti ('':'').

È possibile utilizzare un'apice (') invece di ''REM''. Questo è vero sia che il commento segua un'altra 
istruzione sulla stessa riga o che si trovi da solo su una riga. Tuttavia, non è possibile continuare 
un'istruzione ''REM'' utilizzando la sequenza di continuazione della riga (''_''). Ciò significa che, 
per un commento su più righe, è necessario utilizzare tante istruzioni ''REM' quante sono le righe 
da commentare.

@syntax REM [comment]
@syntax ' [comment]

@example REM this is a comment
@example ' and this is a comment
@example PRINT "ok": REM I am printing ok

@target all
@verified
</usermanual> */

/* <usermanual>
@keyword defining labels

@english

In ugBASIC it is possible to indicate the position within a program with the use of 
so-called "labels". The labels can be represented in the BASIC standard, i.e. with numeric 
labels, or with alphanumeric labels, and are used to jump within specific positions of the program.

@italian

In ugBASIC è possibile indicare la posizione all'interno di un programma con l'utilizzo delle cosiddette
"etichette". Le etichette possono essere rappresentate nello standard BASIC, ovvero con etichette numeriche,
oppure con etichetta alfanumeriche, e servono per saltare all'interno di specifiche posizioni del programma.

@syntax number instruction
@syntax label: instruction
@syntax [label:] instruction

@example 100 PRINT "oK!": GOTO 100
@example begin: PRINT "OK!" : GOTO begin
@example [begin:] PRINT "OK!" : GOTO begin

@usedInExample contrib_cube_10lines.bas

@target all
@verified
</usermanual> */

/* <usermanual>
@keyword separating instructions

@english

In ugBASIC, the instructions are separated using a colon character ('':''). Since this character
is used also as a suffix for a label, you have to use the ''[label:]'' variant, to avoid to
consider ''label'' as a instruction.

@italian

In ugBASIC, le istruzioni sono separate utilizzando i due punti ('':''). Poiché questo carattere 
viene utilizzato anche come suffisso per un'etichetta, è necessario utilizzare la variante ''[label:]'',
per evitare di considerare ''label'' come una istruzione.

@syntax instruction1 : instruction2 : ...

@example PRINT : CLS : PRINT

@target all
@verified
</usermanual> */

/* <usermanual>
@keyword RGB

@english

The ''RGB'' function allows you to obtain the equivalent value of a color, given its red, green and blue 
components. The value of this function, where it is supported by the target, can be used in place of a 
nominal color. Where it is not defined, it always returns a value of zero, which may (or may not) correspond 
to a valid color.

@italian

La funzione ''RGB'' consente di ottenere il valore equivalente di un colore, date le sue componenti secondo
rosso, verde e blu. Il valore di questa funzione, laddove è supportata dal target, può essere utilizzata al
posto di un colore nominale. Laddove non è definita, restituisce sempre un valore di zero, che può (o meno)
corrispondere a un colore valido.

@syntax = RGB( red, green, blue )

@example red = RGB( 255, 0, 0 )

@usedInExample graphics_color_04.bas
@usedInExample graphics_palette_01.bas
@usedInExample images_get_03.bas

@seeAlso COLOR
@seeAlso SHADES (constant)
@target all
</usermanual> */

/* <usermanual>
@keyword DEFINE STRING SPACE

@english

With the ''DEFINE STRING SPACE'' instruction it is possible to define the space 
dedicated to dynamic strings.

@italian
Con l'istruzione DEFINE STRING SPACE è possibile definire lo spazio dedicato 
alle stringe dinamiche.

@syntax DEFINE STRING SPACE bytes

@example DEFINE STRING SPACE 512

@target all
</usermanual> */
/* <usermanual>
@keyword DEFINE STRING COUNT

@english

With the ''DEFINE STRING COUNT'' instruction it is possible to define the number 
of concurrent dynamic strings allowed.

@italian
Con l'istruzione DEFINE STRING COUNT è possibile definire il massimo numero
di stringe dinamiche concorrenti consentite.

@syntax DEFINE STRING COUNT strings

@example DEFINE STRING COUNT 64

@target all
</usermanual> */

/* <usermanual>
@keyword AFTER...CALL

@english
Define the call of a procedure after a specific amout of time, without 
interfering with the main program. You must specifying the length of time 
to wait, measured in TICKS. The ugBASIC branches to the 
procedure after ''value''/''TICKS PER SECONDS'' seconds.

There are 8 delay timers from 0 to 7 which can be specified with ''timer''. 
If omitted ''timer'' defaults to 0. In the case of parallel task has 0 the 
highest and 8 the lowest priority.

With ''EVERY OFF'' and ''EVERY ON'' you can disable or enable the timed 
calls. It is important to know or realise that 
low-priority-procedures which occurs simultanously to higher-priority-procedures 
are not lost. Their task remains or handled again after finishing the higher-prio interrupt.

@italian
Introduce la chiamata di una procedura dopo un certo tempo, senza interferire 
con il programma principale. È necessario specificare l'intervallo di tempo da attendere, 
misurato in ''TICKS''. Il compilatore ugBASIC passa alla procedura 
dopo ''value''/''TICKS PER SECOND'' secondi.

Vi sono 8 timer di ritardo da 0 a 7 che possono essere specificati con ''timer''. 
Se omesso, il valore predefinito ''timer'' è 0. Nel caso di attività parallela, 
0 ha la priorità più alta e 8 la priorità più bassa.

Con ''EVERY OFF'' e ''EVERY ON'' è possibile disabilitare o abilitare le chiamate 
temporizzate. È importante sapere o realizzare che le procedure a bassa priorità che si 
verificano contemporaneamente alle procedure a priorità più alta non vanno perse. 
Il loro compito rimane o viene gestito nuovamente dopo aver terminato 
l'interruzione con priorità più alta.

@syntax AFTER value[,timer] TICKS CALL identifier

@example AFTER 50 TICKS CALL changeBorderColor
@example AFTER 50,2 TICKS CALL changeBorderColor

@usedInExample control_after_01.bas

@target all
</usermanual> */

/* <usermanual>
@keyword AFTER...GOSUB

@english
Define the call of a subroutine after a specific time, without 
interfering with the main program. You must specifying the length of time 
to wait, measured in TICKS. The ugBASIC branches to the 
subroutine after ''value''/''TICKS PER SECONDS'' seconds.

There are 8 delay timers from 0 to 7 which can be specified with ''timer''. 
If omitted ''timer'' defaults to 0. In the case of parallel task has 0 the 
highest and 8 the lowest priority.

With ''EVERY OFF'' and ''EVERY ON'' you can disable or enable the timed
calls. It is important to know or realise that 
low-priority-subroutines which occurs simultanously to higher-priority-subroutines 
are not lost. Their task remains or handled again after finishing the higher-prio interrupt.

@italian
Introduce la chiamata di una subroutine dopo un certo tempo, senza interferire 
con il programma principale. È necessario specificare il tempo da attendere, 
misurato in ''TICKS''. Il compilatore ugBASIC passa alla subroutine 
dopo ''value''/''TICKS PER SECOND'' secondi.

Vi sono 8 timer di ritardo da 0 a 7 che possono essere specificati con ''timer''. 
Se omesso, il valore predefinito ''timer'' è 0. Nel caso di attività parallela, 
0 ha la priorità più alta e 8 la priorità più bassa.

Con ''EVERY OFF'' e ''EVERY ON'' è possibile disabilitare o abilitare le chiamate 
temporizzate. 
È importante sapere o realizzare che le subroutine a bassa priorità che si 
verificano contemporaneamente alle subroutine a priorità più alta non vanno perse. 
Il loro compito rimane o viene gestito nuovamente dopo aver terminato 
l'interruzione con priorità più alta.

@syntax AFTER value[,timer] TICKS GOSUB label

@example AFTER 50 TICKS GOSUB 100
@example AFTER 50,2 TICKS GOSUB label

@usedInExample control_after_02.bas

@target all
</usermanual> */

/* <usermanual>
@keyword BORDER

@english
Change the color of the border of the screen.

@italian
Questa istruzione cambia il colore del bordo.

@syntax BORDER color

@example BORDER YELLOW

@target all
</usermanual> */

/* <usermanual>
@keyword UBOUND

@english
Retrieves the maximum value of the index of an array, given the dimension.

@italian
Recupera il valore massimo dell'indice di un array, data la dimensione.

@syntax = UBOUND( array [, dimension])

@example DIM a(10,20)
@example PRINT UBOUND(a,1) : REM it will print 20

@target all
</usermanual> */

/* <usermanual>
@keyword LBOUND

@english
Retrieves the minimum value of the index of an array, given the dimension.

@italian
Recupera il valore minimo dell'indice di un array, data la dimensione.

@syntax = LBOUND( array [, dimension])

@example DIM a(10,20)
@example PRINT LBOUND(a) : REM it will print 0

@target all
</usermanual> */

/* <usermanual>
@keyword BIG ENDIAN

@english
Returns not zero if the CPU has big endian byte order, zero otherwise.

@italian
Restituisce un valore diverso da zero se la CPU ha un ordinamento "big endian", zero altrimenti.

@syntax = BIG ENDIAN

@example IF BIG ENDIAN THEN : PRINT "BIG ENDIAN" : ENDIF

@target all
</usermanual> */

/* <usermanual>
@keyword LITTLE ENDIAN

@english
Returns not zero if the CPU has little endian byte order, zero otherwise.

@italian
Restituisce un valore diverso da zero se la CPU ha un ordinamento "little endian", zero altrimenti.

@syntax = LITTLE ENDIAN

@example IF LITTLE ENDIAN THEN : PRINT "LITTLE ENDIAN" : ENDIF

@target all
</usermanual> */

/* <usermanual>
@keyword VARBANK

@english
Returns the bank assigned for the given variable, -1 if the variable is on resident memory.

@italian
Restituisce il banco della memoria espansa assegnato per la data variabile, oppure -1
se la variabile è posta sulla memoria residente.

@syntax = VARBANK( variable )

@example DIM x as INTEGER: DIM largeArray( 100, 100 ) AS INTEGER BANKED
@example x = 42
@example BANK WRITE VARBANK( largeArray ) FROM VARPTR( x ) TO VARBANKPTR( largeArray ) SIZE 2

@target all
</usermanual> */

/* <usermanual>
@keyword VARBANKPTR

@english
Returns the address assigned for the given variable inside a bank of memory expansion.

@italian
Restituisce l'indirizzo di memoria assegnato all'interno del banco di memoria espansa.

@syntax = VARBANKPTR( variable )

@example DIM x as INTEGER: DIM largeArray( 100, 100 ) AS INTEGER BANKED
@example x = 42
@example BANK WRITE VARBANK( largeArray ) FROM VARPTR( x ) TO VARBANKPTR( largeArray ) SIZE 2

@target all
</usermanual> */

/* <usermanual>
@keyword ENABLE INTERRUPT

@english

This instruction enables CPU-level interrupts. If they were previously disabled, they will 
now be enabled; if they were already enabled, nothing will happen.

@italian

Questa istruzione abilita gli interrupt a livello di CPU. Se prima erano disabilitate, 
saranno quindi abilitate; se lo erano già, non accadrà nulla.

@syntax ENABLE INTERRUPT

@example ENABLE INTERRUPT

@target all
</usermanual> */

/* <usermanual>
@keyword DISABLE INTERRUPT

@english

This instruction disables CPU-level interrupts. If they were previously enabled, they will 
now be disabled; if they were already disabled, nothing will happen.

@italian

Questa istruzione disabilita gli interrupt a livello di CPU. Se prima erano abilitate, 
saranno quindi disabilitate; se lo erano già, non accadrà nulla.

@syntax DISABLE INTERRUPT

@example DISABLE INTERRUPT

@target all
</usermanual> */

/* <usermanual>
@keyword JOY

@english
Read the value from the joystick port. 

@italian
Leggi il valore della porta del joystick.

@syntax = JOY( port )

@example x = JOY(0)

@target all
</usermanual> */

/* <usermanual>
@keyword JUP

@english
Read the joystick port and check for "direction up" bit.

@italian
Leggi il valore della porta del joystick, e controlla il bit in "direzione su".

@syntax = JUP( port )

@example x = JUP(0)

@target all
</usermanual> */

/* <usermanual>
@keyword JDOWN

@english
Read the joystick port and check for "direction down" bit.

@italian
Leggi il valore della porta del joystick, e controlla il bit in "direzione giù".

@syntax = JDOWN( port )

@example x = JDOWN(0)

@target all
</usermanual> */

/* <usermanual>
@keyword JLEFT

@english
Read the joystick port and check for "direction left" bit.

@italian
Leggi il valore della porta del joystick, e controlla il bit in "direzione sinistra".

@syntax = JLEFT( port )

@example x = JLEFT(0)

@target all
</usermanual> */

/* <usermanual>
@keyword JRIGHT

@english
Read the joystick port and check for "direction right" bit.

@italian
Leggi il valore della porta del joystick, e controlla il bit in "direzione destra".

@syntax = JRIGHT( port )

@example x = JRIGHT(0)

@target all
</usermanual> */

/* <usermanual>
@keyword JFIRE

@english
Read the joystick port and check for "fire button" bit.

@italian
Leggi il valore della porta del joystick, e controlla il bit "fuoco".

@syntax = JFIRE( port )

@example x = JFIRE(0)

@target all
</usermanual> */

/* <usermanual>
@keyword FIRE

@english
Read the joystick port and check for "fire button" bit.

@italian
Leggi il valore della porta del joystick, e controlla il bit "fuoco".

@syntax = FIRE( port )

@example x = FIRE(0)

@target all
</usermanual> */

/* <usermanual>
@keyword JOY COUNT

@english
Read the number of joysticks installed into the system.

@italian
Recupera il numero di porte joystick installate nel sistema.

@syntax = JOY COUNT

@example x = JOY COUNT

@target all
</usermanual> */

/* <usermanual>
@keyword JOYCOUNT

@english
Read the number of joysticks installed into the system.

@italian
Recupera il numero di porte joystick installate nel sistema.

@syntax = JOYCOUNT

@example x = JOYCOUNT

@target all
</usermanual> */

/* <usermanual>
@keyword JOY X

@english
Read the horizontal axys of an analogical joystick, if it is present.
A negative value means "left" while a positive one means "right".
The value near 0 means "no direction".

@italian
Legge il valore dell'asse orizzontale di un joystick analogico, se presente.
Un valore negativo indica "sinistra" mentre un valore positivo indica "destra".
Un valore prossimo allo 0 significa "nessuna direzione".

@syntax = JOY X( port )

@example x = JOY X(0)

@target coco
@target coco3
@target d32
@target d64
</usermanual> */

/* <usermanual>
@keyword JOYX

@english
Alias per ''JOY X''.

@italian
Alias di ''JOY X''

@syntax = JOYX( port )

@example x = JOYX(0)

@alias JOY X

@target coco
@target coco3
@target d32
@target d64
</usermanual> */

/* <usermanual>
@keyword JOYY

@english
Read the vertical axys of an analogical joystick, if it is present.
A negative value means "up" while a positive one means "down".
The value near 0 means "no direction".

@italian
Legge il valore dell'asse verticale di un joystick analogico, se presente.
Un valore negativo indica "su" mentre un valore positivo indica "giù".
Un valore prossimo allo 0 significa "nessuna direzione".

@syntax = JOY Y( port )

@example y = JOY Y(0)

@target coco
@target coco3
@target d32
@target d64
</usermanual> */

/* <usermanual>
@keyword JOYY

@english
Alias per ''JOY Y''.

@italian
Alias di ''JOY Y''

@syntax = JOYY( port )

@example y = JOYY(0)

@alias JOY Y

@target coco
@target coco3
@target d32
@target d64
</usermanual> */

/* <usermanual>
@keyword DEFINE AUDIO

@english

This pragma allows you to indicate whether the sound should be played 
synchronously or asynchronously with the execution of subsequent instructions. 

Specifically, with ''DEFINE AUDIO SYNC'', effects and notes are played 
synchronously, so you do not have to wait for completion to execute the next 
command. On the contrary, with ''DEFINE AUDIO ASYNC'', effects and notes are
played asynchronously, so you must wait for completion otherwise subsequent 
commands will be executed during the sound effect/note.

Note that not all targets support both modes.

@italian

Questa pragma consente di indicare se il suono deve essere riprodotto in
modo sincrono o asincrono con l'esecuzione delle istruzioni successive.

In particolare, con ''DEFINE AUDIO SYNC'', effetti e note vengono riprodotti
in modo sincrono, quindi non è necessario attendere il completamento per eseguire 
il comando successivo. Al contrario, con ''DEFINE AUDIO ASYNC'', effetti e 
note vengono riprodotti in modo asincrono, quindi è necessario attendere il
completamento, altrimenti i comandi successivi verranno eseguiti durante 
l'effetto sonoro/nota.

Nota che non tutti i target supportano entrambe le modalità.

@syntax DEFINE AUDIO SYNC
@syntax DEFINE AUDIO ASYNC

@example DEFINE AUDIO SYNC

@target all
*/

/* <usermanual>
@keyword BLOCK

@english

''BLOCK'' draws a filled rectangle. The location of the top left corner is determined by the first 
two parameters ''x1'' and ''y1'', the coordinates of the bottom right corner of the rectangle 
are determined by parameters three and four (''x2'' and ''y2'', where ''x2=x1+width'' and 
''y2=y1+height'', important for ''REC''). The color of the rectangle is determined by the 
last parameter (''fq'', color source). Permissible values ​​are 0..''SCREEN WIDTH'' for ''x1''
and ''x2' . For ''y1'' and ''y2'', values ​​from 0 to ''SCREEN HEIGHT'' are permitted in both cases. 
The color also depends on the graphics mode and refers to the color specifications behind ''HIRES''
on the one hand and ''MULTI'' and ''LOW COL'' on the other. The point 0,0 is in the top left corner.

Note: Unfortunately, the parameter types of ''REC'' and ''BLOCK'' do not match, which makes 
programming a little more complicated (see program example). 

@italian

''BLOCK'' disegna un rettangolo pieno. La posizione dell'angolo in alto a sinistra è determinata
dai primi due parametri ''x1'' e ''y1'', le coordinate dell'angolo in basso a destra del rettangolo
sono determinate dai parametri tre e quattro (''x2'' e ''y2'', dove ''x2=x1+larghezza'' e 
''y2=y1+altezza'', importante per ''REC''). Il colore del rettangolo è determinato dall'ultimo 
parametro (''fq'', fonte colore). I valori consentiti sono 0..''SCREEN WIDTH'' per ''x1'' e ''x2'.
Per ''y1'' e ''y2'' sono ammessi in entrambi i casi i valori da 0 a ''SCREEN HEIGHT''. Il colore 
dipende anche dalla modalità grafica e si riferisce alle specifiche del colore dietro ''HIRES''
da un lato e ''MULTI'' e ''LOW COL'' dall'altro. Il punto 0,0 si trova nell'angolo in alto a sinistra.

Nota: Sfortunatamente i tipi di parametri di ''REC'' e ''BLOCK'' non corrispondono, il che rende 
la programmazione un po' più complicata (vedi esempio di programma).

@syntax BLOCK x1, y1, x2, y2, fq

@example BLOCK x, y, x+29, y+19, 0

@usedInExample tsb_block_rec_01.bas

@target c128
@project tsb
</usermanual> */

/* <usermanual>
@keyword REC

@english

''REC'' draws a rectangle. The location of the top left corner is determined by the first two 
parameters ''x'' and ''y'', the width and height of the rectangle by parameters three and four 
(''sa'' and ''sb''). The color of the edge lines is determined by the last parameter (''fq'', 
color source). The four corners of the rectangle are always drawn.

Permissible values ​​are 0..''SCREEN WIDTH'' for ''x'' and ''sa''. 
For ''y'' or ''sb'', values ​​from 0 to ''SCREEN HEIGHT'' are permitted in both cases. The color also depends on
the graphics mode and refers to the color specifications behind ''HIRES'' on the one hand and 
''MULTI'' and ''LOW COL'' on the other. The point 0,0 is in the top left corner.

Note: If the edge lengths of the rectangle exceed the screen limits, rectangle will be clipped.

@italian

''REC'' disegna un rettangolo. La posizione dell'angolo in alto a sinistra è determinata dai
primi due parametri ''x'' e ''y'', la larghezza e l'altezza del rettangolo dai parametri tre e 
quattro (''sa'' e ''sb'' ). Il colore delle linee del bordo è determinato dall'ultimo parametro 
(''fq'', sorgente colore). Vengono sempre disegnati i quattro angoli del rettangolo.

I valori consentiti sono 0..''SCREEN WIDTH'' per ''x'' e ''sa''. Per ''y'' o ''sb'' sono ammessi 
in entrambi i casi i valori da 0 a ''SCREEN HEIGHT''. Il colore dipende anche dalla modalità 
grafica e si riferisce alle specifiche del colore date al comando ''HIRES'' da un lato e 
''MULTI'' e ''LOW COL'' dall'altro. Il punto 0,0 si trova nell'angolo in alto a sinistra.

Nota: se la lunghezza dei bordi del rettangolo supera i limiti dello schermo, il rettangolo
sarà ritagliato

@syntax REC x, y, sa, sb, fq

@example REC x, y, 29, 19, 1

@usedInExample tsb_block_rec_01.bas

@target c128
@project tsb
</usermanual> */

/* <usermanual>
@keyword HIRES

@english

`HIRES` is used to switch from text to high-resolution graphics mode and to use the specified colors: 
''ink'' for the writing color and ''paper'' for the background color (both with values ​​from 0 to ''SCREEN COLORS'').
The graphics memory is deleted and preset with the specified colors. The color of the screen frame 
remains unaffected. The selected mode remains active until it is switched off or changed by a command 
(''MULTI'', ''CSET'' or ''NRM''). Important: the color specifications of almost all other graphics 
commands that use ''fg'' as color parameter refers to the colors specified here. If the color source ''0'' is specified in a graphics 
command, the color specified for ''paper'' is selected; if ''1'' is specified, the color for ''ink''
is selected; the color specification ''2'' inverts the controlled pixel (if in hires mode, 
otherwise see ''MULTI''). 

@italian

''HIRES'' serve per passare dalla modalità testo a quella grafica ad alta risoluzione e per
utilizzare i colori specificati: ''ink'' per il colore della scrittura e ''paper'' per il colore
dello sfondo (entrambi con valori da 0 a ''SCREEN COLORS''). La memoria grafica viene cancellata e
preimpostata con i colori specificati. Il colore della cornice dello schermo rimane inalterato. 
La modalità selezionata rimane attiva finché non viene spenta o modificata tramite un comando 
(''MULTI'', ''CSET'' o ''NRM''). Importante: le specifiche dei colori di quasi tutti gli altri
comandi grafici che usano ''fg'' come parametro del colore si riferiscono ai colori qui specificati. 
Se in un comando grafico viene specificata l'origine colore ''0'', viene selezionato il colore 
specificato per ''paper''; se viene specificato ''1'', viene selezionato il colore per 
''ink''; la specifica colore ''2'' inverte il pixel controllato (se in modalità ''HIRES'', altrimenti
vedi ''MULTI'').

@syntax HIRES ink, paper

@example HIRES 0, 1

@usedInExample tsb_block_rec_01.bas

@target c128
@project tsb
</usermanual> */

/* <usermanual>
@keyword DO NULL

@english

Wait for a keystroke. If a program comes to a ''DO NULL'' instruction, it waits until the user presses
a key. Differently from TSB, further commands can follow on the same BASIC line in the progra,
and it can be used in an ''IF'' line (after ''THEN'' or ''ELSE''). 

@italian

Aspetta la sequenza di tasti. Se un programma arriva a un'istruzione ''DO NULL'', attende finché l'utente
preme un tasto. A differenza di TSB, ulteriori comandi possono seguire sulla stessa riga BASIC nel programma,
e può essere utilizzata in una riga ''IF'' (dopo ''THEN'' o ''ELSE'').

@syntax DO NULL

@example DO NULL

@usedInExample tsb_block_rec_01.bas

@target c128
@project tsb
</usermanual> */

/* <usermanual>
@keyword NRM

@english

''NRM'' resets the chipset to its default values: the graphic mode is switched off,
uppercase and lowercase font is activated, the extended color mode is switched off.

@italian

''NRM'' ripristina il chipset ai suoi valori predefiniti: la modalità grafica è 
disattivata, i caratteri maiuscoli e minuscoli sono attivati, la modalità colore 
estesa è disattivata.

@syntax NRM

@example NRM

@usedInExample tsb_block_rec_01.bas

@target c128
@project tsb
</usermanual> */

/* <usermanual>
@keyword INSERT

@english

''INSERT'' inserts the character string ''<string>'' (first argument) into the character string 
''<altstring>'' (second argument) starting at the position ''<pos>'' (third argument), whereby 
the counting starts with ''1''. The resulting character string is as long as the sum of the two 
individual character strings.

@italian

''INSERT'' inserisce la stringa di caratteri ''<string>'' (primo argomento) nella stringa di 
caratteri ''<altstring>'' (secondo argomento) a partire dalla posizione ''<pos>'' (terzo argomento), 
per cui il conteggio inizia con ''1''. La stringa di caratteri risultante è lunga quanto la somma 
delle due stringhe di caratteri individuali.

@syntax = INSERT(<string>,<altstring>,<pos>) 

@example c$=INSERT(a$,b$,9)

@usedInExample tsb_insert_01.bas

@target c128
@project tsb
</usermanual> */

/* <usermanual>
@keyword DEFINE CENTER

@english

This pragma allows you to change the behavior of the ''CENTER'' command. 
By definition, the ''CENTER'' command behaves exactly like the ''PRINT'' 
command, with the difference that the text is centered.

So if the ''CENTER'' command is followed by the parameter only, subsequent 
writings will start from the next line; if, on the contrary, the semicolon 
character ('';'') is added, subsequent writings will continue from the
previous position.

This behavior can be changed with the ''WITHOUT NEWLINE'' option, which 
at this point will not move the cursor to the next line, in any case.

@italian

Questo pragma permette di cambiare il comportamento del comando ''CENTER''. 
Per definizione, il comando ''CENTER'' si comporta esattamente come il 
comando ''PRINT'', con la differenza che il testo viene centrato. 

Quindi se il comando ''CENTER'' viene seguito dal solo parametro, le 
successive scritture inizieranno dalla riga successiva; se, al contrario, 
viene aggiunto il carattere punto e virgola ('';''), le successive 
scritture continueranno dalla posizione precedente. 

Tale comportamento può essere modificato con l'opzione ''WITHOUT NEWLINE'', 
che a questo punto non farà spostare il cursore alla linea successiva, 
in alcun caso.

@syntax DEFINE CENTER WITHOUT NEWLINE
@syntax DEFINE CENTER WITH NEWLINE

@example DEFINE CENTER WITH NEWLINE

@target all
*/

/* <usermanual>
@keyword COLORS (constant)

@english

This constant holds the maximum number of colors available for the target, for 
the current mode. Note that, although this is the number of colors available, 
it is not guaranteed that every single graphic or text element in the mode could 
assume this number independently. This depends on the specific characteristics 
of the video chipset available. Also, it is not guaranteed that the colors are 
changeable. This information is useful when you want to choose a random color 
from those available, or to perform loops on the actual availability of colors.

@italian

Questa costante mantiene il numero massimo di colori disponibili per il target, 
per la modalità corrente. Nota che, sebbene questo sia il numero di colori 
disponibili, non è detto che ogni singolo elemento grafico o testuale della 
modalità possa assumerlo in modo indipendente. Questo dipende dalle caratteristiche 
specifiche del chipset video a disposizione. Inoltre, non è detto che i colori 
siano modificabili. Questa informazione è utile laddove si voglia scegliere un 
colore a caso tra quelli disponibili, o effettuare cicli sulla effettiva 
disponibilità di colori.

@syntax = COLORS

@alias SCREEN COLORS (constant)
@alias COLORS COUNT (constant)
@alias COLOR COUNT (constant)
@target all
</usermanual> */

/* <usermanual>
@keyword SCREEN COLORS (constant)

@english

Alias for ''COLORS''.

@italian

Alias per ''COLORS''.

@syntax = SCREEN COLORS

@alias COLORS (constant)
@alias COLORS COUNT (constant)
@target all
</usermanual> */

/* <usermanual>
@keyword COLORS COUNT (constant)

@english

Alias for ''COLORS''.

@italian

Alias per ''COLORS''.

@syntax = COLORS COUNT

@alias COLORS (constant)
@alias SCREEN COLORS (constant)
@alias COLOR COUNT (constant)
@target all
</usermanual> */

/* <usermanual>
@keyword COLOR COUNT (constant)

@english

Alias for ''COLORS''.

@italian

Alias per ''COLORS''.

@syntax = COLOR COUNT

@alias COLORS (constant)
@alias SCREEN COLORS (constant)
@alias COLORS COUNT (constant)
@target all
</usermanual> */


/* <usermanual>
@keyword COLOURS (constant)

@english

Alias for ''COLORS''.

@italian

Alias per ''COLORS''

@syntax = COLOURS

@alias SCREEN COLOURS (constant)
@alias COLOURS COUNT (constant)
@target all
</usermanual> */

/* <usermanual>
@keyword SCREEN COLOURS (constant)

@english

Alias for ''COLORS''.

@italian

Alias per ''COLORS''.

@syntax = SCREEN COLORS

@alias COLOURS (constant)
@alias COLOURS COUNT (constant)
@target all
</usermanual> */

/* <usermanual>
@keyword COLOURS COUNT (constant)

@english

Alias for ''COLORS''.

@italian

Alias per ''COLORS''.

@syntax = COLOURS COUNT

@alias COLOURS (constant)
@alias SCREEN COLOURS (constant)
@target all
</usermanual> */

/* <usermanual>
@keyword PEN COLORS (constant)

@english

This constant gives the number of colors that can be used with the ''PEN'' command. 
It usually represents the maximum number of colors that can be managed in text mode,
and has little to do with the actual number of colors available in the mode in use. 
For that, it is advisable to use the ''COLORS'' constant.

@italian

Questa costante fornisce il numero di colori utilizzabili con il comando ''PEN''. 
Di solito rappresenta il numero massimo di colori gestibili nella modalità testuale, 
e non ha molta attinenza con l'effettivo numero di colori disponibili nella 
modalità in uso. Per quello è consigliabile usare la costante ''COLORS''.

@syntax = PEN COLORS

@seeAlso COLORS (constant)
@target all
</usermanual> */

/* <usermanual>
@keyword PAPER COLORS (constant)

@english

This constant gives the number of colors that can be used with the ''PAPER'' command. 
It usually represents the maximum number of colors that can be managed in text mode,
and has little to do with the actual number of colors available in the mode in use. 
For that, it is advisable to use the ''COLORS'' constant.

@italian

Questa costante fornisce il numero di colori utilizzabili con il comando ''PAPER''. 
Di solito rappresenta il numero massimo di colori gestibili nella modalità testuale, 
e non ha molta attinenza con l'effettivo numero di colori disponibili nella 
modalità in uso. Per quello è consigliabile usare la costante ''COLORS''.

@syntax = PAPER COLORS

@seeAlso COLORS (constant)
@target all
</usermanual> */

/* <usermanual>
@keyword COLOR (data type)

@english

The ''COLOR'' data type holds enough information to represent a color on the target's 
video chipset. This type of information allows one of several possible colors to be 
selected, either predefined or redefined, depending on the targets' capabilities.

@italian

Il tipo di dato ''COLOR'' mantiene l'informazione sufficiente a rappresentare un colore 
sul chipset video del target. Questo tipo di informazione permette di selezionare uno 
dei colori possibili, predefiniti o ridefiniti, a seconda delle possibilità dei target.

@syntax DIM c AS COLOR
@syntax x = (COLOR) 42

@target all
</usermanual> */

/* <usermanual>
@keyword SHADES (constant)

@english

This constant holds the maximum number of shades available for the target, for 
the current mode. Note that, although this is the number of shades available, 
it is not guaranteed that every single graphic or text element in the mode could 
assume this value, independently. This depends on the specific characteristics 
of the video chipset available. 

@italian

Questa costante mantiene il numero massimo di sfumature disponibili per il target, 
per la modalità corrente. Nota che, sebbene questo sia il numero di sfumature 
disponibili, non è detto che ogni singolo elemento grafico o testuale della 
modalità possa assumere tale vlaore in modo indipendente. Questo dipende dalle 
caratteristiche specifiche del chipset video a disposizione. 

@syntax = SHADES

@alias SCREEN SHADES (constant)
@seeAlso COLOR
@seeAlso RGB
@target all
</usermanual> */

/* <usermanual>
@keyword SCREEN SHADES (constant)

@english

Alias for ''SHADES''.

@italian

Alias per ''SHADES''.

@syntax = SCREEN SHADES

@alias SHADES (constant)
@seeAlso COLOR
@seeAlso RGB
@target all
</usermanual> */

/* <usermanual>
@keyword SCREEN BORDER X (constant)

@english

Returns the width of the border of the screen, in the reference frame used by sprites. If no sprites 
are available, or if the border is not present, it is equal to ''0''. This constant should be used as
a horizontal offset, to ensure that the sprite is visible beyond the left screen border.

@italian

Restituisce la larghezza del bordo dello schermo, nel sistema di riferimento utilizzato dagli sprites. Se 
gli sprite non sono disponibili, oppure se il bordo non è presente, vale ''0''. Questa costante 
deve essere utilizzata come offset orizzontale, per garantire che lo sprite sia visibile oltre
il bordo sinistro dello schermo.

@syntax = SCREEN BORDER X

@target all
</usermanual> */

/* <usermanual>
@keyword SCREEN BORDER Y (constant)

@english

Returns the height of the border of the screen, in the reference frame used by sprites. If no sprites 
are available, or if the border is not present, it is equal to ''0''. This constant should be used as
a vertical offset, to ensure that the sprite is visible beyond the top screen border.

@italian

Restituisce l'altezza del bordo dello schermo, nel sistema di riferimento utilizzato dagli sprites. Se 
gli sprite non sono disponibili, oppure se il bordo non è presente, vale ''0''. Questa costante 
deve essere utilizzata come offset verticale, per garantire che lo sprite sia visibile oltre
il bordo superiore dello schermo.

@syntax = SCREEN BORDER Y

@target all
</usermanual> */

/* <usermanual>
@keyword BORDER

@english

Alias for ''COLOR BORDER''.

@italian

Alias per ''COLOR BORDER''.

@syntax BORDER shade

@alias COLOR BORDER
@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE COUNT (constant)

@english

This constant allows you to know the number of hardware sprites available on the 
target considered. Note that this is the effective limit allowed by the video
chipset: however, ugBASIC can provide additional mechanisms to multiply the 
number of available sprites, such as the so-called "sprite multiplexing".

@italian

Questa costante permette di conoscere il numero di sprite hardware disponibili 
sul target considerato. Da notare che questo è l'effettivo limite concesso
dal chipset video: tuttavia, ugBASIC può dare meccanismi aggiuntivi per 
moltiplicare il numero di sprite disponibili, come il cosiddetto 
"sprite multiplexing".

@syntax = SPRITE COUNT

@target all
</usermanual> */

/* <usermanual>
@keyword SCREEN SPRITE RATIO X (constant)

@english

This constant allows you to know the ratio (percentile) between the screen 
reference system and the sprite reference system. In other words, given a
coordinate according to the screen reference system, you can calculate the 
one according to the sprite reference system with the following proportion:

'''( SCREEN WIDTH * SCREEN SPRITE RATIO X ) / 100'''

@italian

Questa costante permette di conoscere il rapporto (percentile) tra il 
sistema di riferimento dello schermo e quello degli sprite. In altri termini, 
data una coordinata secondo il sistema di riferimento dello schermo, si può 
calcolare quella secondo il sistema di riferimento degli sprite con la 
seguente proporzione:

'''( SCREEN WIDTH * SCREEN SPRITE RATIO X ) / 100'''

@syntax = SCREEN SPRITE RATIO X

@target all
</usermanual> */

/* <usermanual>
@keyword SCREEN SPRITE RATIO Y (constant)

@english

This constant allows you to know the ratio (percentile) between the screen 
reference system and the sprite reference system. In other words, given a
coordinate according to the screen reference system, you can calculate the 
one according to the sprite reference system with the following proportion:

'''( SCREEN HEIGHT * SCREEN SPRITE RATIO Y ) / 100'''

@italian

Questa costante permette di conoscere il rapporto (percentile) tra il 
sistema di riferimento dello schermo e quello degli sprite. In altri termini, 
data una coordinata secondo il sistema di riferimento dello schermo, si può 
calcolare quella secondo il sistema di riferimento degli sprite con la 
seguente proporzione:

'''( SCREEN HEIGHT * SCREEN SPRITE RATIO Y ) / 100'''

@syntax = SCREEN SPRITE RATIO Y

@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE HEIGHT (constant)

@english

This constant allows you to know the height of hardware sprites available on the 
target considered. Note that this is the effective limit allowed by the video
chipset: however, ugBASIC can provide additional mechanisms to increase the 
height of sprites, such as the so-called "sprite multiplexing".

@italian

Questa costante permette di conoscere l'altezza degli sprite hardware disponibili 
sul target considerato. Da notare che questo è l'effettivo limite concesso
dal chipset video: tuttavia, ugBASIC può dare meccanismi aggiuntivi per 
accrescere l'altezza degli sprite disponibili, come il cosiddetto 
"sprite multiplexing".

@syntax = SPRITE HEIGHT

@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE WIDTH (constant)

@english

This constant allows you to know the width of hardware sprites available on the 
target considered. Note that this is the effective limit allowed by the video
chipset: however, ugBASIC can provide additional mechanisms to increase the 
width of sprites, such as the so-called "sprite multiplexing".

@italian

Questa costante permette di conoscere la larghezza degli sprite hardware disponibili 
sul target considerato. Da notare che questo è l'effettivo limite concesso
dal chipset video: tuttavia, ugBASIC può dare meccanismi aggiuntivi per 
accrescere la larghezza degli sprite disponibili, come il cosiddetto 
"sprite multiplexing".

@syntax = SPRITE WIDTH

@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE X MIN (constant)

@english

This constant allows you to know the minimum value of horizontal position of hardware 
sprites available on the target considered. Note that this is the effective limit 
allowed by the video chipset.

@italian

Questa costante permette di conoscere il valor minimo della posizione X degli sprite 
hardware disponibili  sul target considerato.

@syntax = SPRITE X MIN
@syntax = SPRITE MIN X

@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE Y MIN (constant)

@english

This constant allows you to know the minimum value of vertical position of hardware 
sprites available on the target considered. Note that this is the effective limit 
allowed by the video chipset.

@italian

Questa costante permette di conoscere il valor minimo della posizione Y degli sprite 
hardware disponibili sul target considerato.

@syntax = SPRITE Y MIN
@syntax = SPRITE MIN Y

@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE X MAX (constant)

@english

This constant allows you to know the maximum value of horizontal position of hardware 
sprites available on the target considered. Note that this is the effective limit 
allowed by the video chipset.

@italian

Questa costante permette di conoscere il valor massimo della posizione X degli sprite 
hardware disponibili  sul target considerato.

@syntax = SPRITE X MAX
@syntax = SPRITE MAX X

@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE Y MAX (constant)

@english

This constant allows you to know the maximum value of vertical position of hardware 
sprites available on the target considered. Note that this is the effective limit 
allowed by the video chipset.

@italian

Questa costante permette di conoscere il valor massimo della posizione Y degli sprite 
hardware disponibili sul target considerato.

@syntax = SPRITE Y MAX
@syntax = SPRITE MAX Y

@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE (data type)

@english

This data type allows you to identify and use a hardware sprite resource. Its value is 
not directly usable by the programmer, who must consider the variable that contains 
it as a "placeholder" for the sprite. Furthermore, this data type is used by both 
native hardware sprites (''SPRITE'') and "composite" ones (''CSPRITE''), but it is 
not possible to mix their use.

@italian

Questo tipo di dato permette di individuare e utilizzare una risorsa di tipo 
sprite hardware. Il suo valore non è direttamente utilizzabile dal programmatore, 
che deve intendere la variabile che lo contiene come un "segnaposto" dello sprite.
Inoltre, questo tipo di dato è usato sia dagli sprite hardware nativi (''SPRITE'') 
che da quelli "compositi" (''CSPRITE''), ma non è possibile miscelarne l'uso.

@syntax DIM x AS SPRITE: x = SPRITE(xImage)

@target all
</usermanual> */

/* <usermanual>
@keyword SPRITE

@english

The ''SPRITE'' instructions can be used to prefix one or more commands on specific 
hardware sprites. Commands can be specified, one after the other, after specifying which 
sprite to refer to. If the sprite number is omitted, it is assumed that the 
operations will be performed on all hardware sprites.

@italian

L'istruzione ''SPRITE'' può essere utilizzata per premettere uno o più comandi su 
specifici sprite hardware. I comandi possono essere indicate, una dopo l'altra, 
dopo aver indicato a quale sprite si vuol far riferimento. Se viene omesso il 
numero dello sprite, si intende che le operazioni saranno svolte su tutti gli 
sprite hardware.

@syntax SPRITE index command1 [command2 [command3 ...]]
@syntax SPRITE command1 [command2 [command3 ...]]

@example SPRITE 1 ENABLE MULTICOLOR
@example SPRITE ON

@target c64
@target c64reu
@target c128
@target msx1
@target coleco
@target sc3000
@target sg1000
@seeAlso SPRITE (function)
@seeAlso SPRITE AT (command)
@seeAlso SPRITE COLOR (command)
@seeAlso SPRITE COMPRESS HORIZONTAL (command)
@seeAlso SPRITE COMPRESS VERTICAL (command)
@seeAlso SPRITE DISABLE (command)
@seeAlso SPRITE ENABLE (command)
@seeAlso SPRITE EXPAND HORIZONTAL (command)
@seeAlso SPRITE EXPAND VERTICAL (command)
@seeAlso SPRITE MONOCOLOR (command)
@seeAlso SPRITE MULTICOLOR (command)
</usermanual> */

/* <usermanual>
@keyword BITMAP (constant)

@english

The ''BITMAP'' constant represents the position (in terms of bits) that tracks 
whether the graphics chipset is capable of rendering graphics in "bitmap" mode, 
i.e. whether it is possible to address individual pixels on the screen. 

This constant can be used to query the ''SCREEN'' constant, in an attempt to 
understand whether the functionality is available or not.

@italian

La costante ''BITMAP'' rappresenta la posizione (in termini di bit) che traccia 
se il chipset grafico è in grado di rapprentare grafica nella modalità "bitmap", 
cioè se è possibile indirizzare singolarmente i singoli pixel sullo schermo. 

Questa costante può essere utilizzata per interrogare la costante ''SCREEN'', 
nel tentativo di comprendere se la funzionalità è disponibile o meno.

@syntax = BITMAP

@example IF BIT BITMAP OF SCREEN THEN: PRINT "bitmap is available!": ENDIF

@target all
@seeAlso SCREEN (constant)
</usermanual> */

/* <usermanual>
@keyword SCREEN (constant)

@english

The ''SCREEN'' constant represents the capabilities of video chipset.

@italian

La costante ''SCREEN'' rappresenta le capacità del chipset video.

@syntax = SCREEN

@example IF BIT BITMAP OF SCREEN THEN: PRINT "bitmap is available!": ENDIF

@target all
@seeAlso BITMAP (constant)
</usermanual> */

/* <usermanual>
@keyword SCREEN WIDTH (constant)

@english

The ''SCREEN WIDTH'' constant represents the actual width of the screen,
for the current video chipset and graphic / text mode, in terms of pixels.

@italian

La costante ''SCREEN WIDTH'' rappresenta la larghezza effettiva dello 
schermo, per l'attuale chipset video e la modalità grafica/testo, 
in termini di pixel.

@syntax = SCREEN WIDTH

@example IF SCREEN WIDTH > 128 THEN: PRINT "At least 128 pixels!!": ENDIF

@target all
@alias WIDTH (constant)
</usermanual> */

/* <usermanual>
@keyword WIDTH (constant)

@english

Alias for ''SCREEN WIDTH''.

@italian

Alias per ''SCREEN WIDTH''.

@syntax = WIDTH

@example IF WIDTH > 128 THEN: PRINT "At least 128 pixels!!": ENDIF

@target all
@alias SCREEN WIDTH (constant)
</usermanual> */

/* <usermanual>
@keyword SCREEN HEIGHT (constant)

@english

The ''SCREEN HEIGHT'' constant represents the actual height of the screen,
for the current video chipset and graphic / text mode, in terms of pixels.

@italian

La costante ''SCREEN HEIGHT'' rappresenta la larghezza effettiva dello 
schermo, per l'attuale chipset video e la modalità grafica/testo, 
in termini di pixel.

@syntax = SCREEN HEIGHT

@example IF SCREEN HEIGHT > 128 THEN: PRINT "At least 128 pixels!!": ENDIF

@target all
@alias HEIGHT (constant)
</usermanual> */

/* <usermanual>
@keyword HEIGHT (constant)

@english

Alias for ''SCREEN HEIGHT''.

@italian

Alias per ''SCREEN HEIGHT''.

@syntax = HEIGHT

@example IF HEIGHT > 128 THEN: PRINT "At least 128 pixels!!": ENDIF

@target all
@alias SCREEN HEIGHT (constant)
</usermanual> */

///////////////

/* <usermanual>
@keyword SCREEN TILES WIDTH (constant)

@english

The ''SCREEN TILES WIDTH'' constant represents the actual width of the screen,
for the current video chipset and graphic / text mode, in terms of tiles (characters).

@italian

La costante ''SCREEN TILES WIDTH'' rappresenta la larghezza effettiva dello 
schermo, per l'attuale chipset video e la modalità grafica/testo, 
in termini di tiles (caratteri).

@syntax = SCREEN TILES WIDTH

@example IF SCREEN TILES WIDTH > 40 THEN: PRINT "At least 40 columns!!": ENDIF

@target all
@alias TILES WIDTH (constant)
@alias SCREEN COLUMNS (constant)
</usermanual> */

/* <usermanual>
@keyword TILES WIDTH (constant)

@english

Alias for ''SCREEN TILES WIDTH''.

@italian

Alias per ''SCREEN TILES WIDTH''.

@syntax = TILES WIDTH

@example IF TILES WIDTH > 40 THEN: PRINT "At least 40 columns!!": ENDIF

@target all
@alias SCREEN TILES WIDTH (constant)
@alias SCREEN COLUMNS (constant)
</usermanual> */

/* <usermanual>
@keyword SCREEN COLUMNS (constant)

@english

Alias for ''SCREEN TILES WIDTH''.

@italian

Alias per ''SCREEN TILES WIDTH''.

@syntax = SCREEN COLUMNS

@example IF SCREEN COLUMNS > 40 THEN: PRINT "At least 40 columns!!": ENDIF

@target all
@alias SCREEN TILES WIDTH (constant)
@alias TILES WIDTH (constant)
</usermanual> */

//////////////

/* <usermanual>
@keyword SCREEN TILES HEIGHT (constant)

@english

The ''SCREEN TILES HEIGHT'' constant represents the actual width of the screen,
for the current video chipset and graphic / text mode, in terms of tiles (characters).

@italian

La costante ''SCREEN TILES HEIGHT'' rappresenta la larghezza effettiva dello 
schermo, per l'attuale chipset video e la modalità grafica/testo, 
in termini di tiles (caratteri).

@syntax = SCREEN TILES HEIGHT

@example IF SCREEN TILES HEIGHT > 10 THEN: PRINT "At least 10 rows!!": ENDIF

@target all
@alias TILES HEIGHT (constant)
@alias SCREEN COLUMNS (constant)
</usermanual> */

/* <usermanual>
@keyword TILES HEIGHT (constant)

@english

Alias for ''SCREEN TILES HEIGHT''.

@italian

Alias per ''SCREEN TILES HEIGHT''.

@syntax = TILES HEIGHT

@example IF TILES HEIGHT > 10 THEN: PRINT "At least 10 rows!!": ENDIF

@target all
@alias SCREEN TILES HEIGHT (constant)
@alias SCREEN COLUMNS (constant)
</usermanual> */

/* <usermanual>
@keyword SCREEN ROWS (constant)

@english

Alias for ''SCREEN TILES HEIGHT''.

@italian

Alias per ''SCREEN TILES HEIGHT''.

@syntax = SCREEN ROWS

@example IF SCREEN ROWS > 10 THEN: PRINT "At least 10 rows!!": ENDIF

@target all
@alias SCREEN TILES HEIGHT (constant)
@alias TILES HEIGHT (constant)
</usermanual> */

