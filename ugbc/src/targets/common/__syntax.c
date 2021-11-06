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

@syntax = # [constant]

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
