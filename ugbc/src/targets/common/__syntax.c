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

@syntax ... = [variable]([index1]{, [index2] {, ...}})
@syntax [variable]([index1]{, [index2] {, ...}}) = ...
@syntax ... = [variable]$([index1]{, [index2] {, ...}})
@syntax [variable]$([index1]{, [index2] {, ...}}) = ...

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

@syntax ... = [ [variable] ]
@syntax [ [variable] ] = ...
@syntax ... = [ [variable]$ ]
@syntax [ [variable]$ ] = ...

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

@syntax ... = ( [type] ) [number]
@syntax ... = ( [type] ) ( ... )

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

@syntax CONST [identifier] = [constant value]
@syntax CONST POSITIVE [identifier] = [constant value]
@syntax CONST [identifier] IN ([min],[max]) = [constant value]
@syntax CONST [identifier] IN [[min],[max]) = [constant value]
@syntax CONST [identifier] IN ([min],[max]] = [constant value]
@syntax CONST [identifier] IN [[min],[max]] = [constant value]

@example CONST x = 42
@example CONST POSITIVE y = -42: ' this raises an error!
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
and to initialize this array with the values ​​we prefer.

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

@syntax DIM [identifier] {AS [datatype]} ( [dimension1] {, [dimension2], ... } )
@syntax DIM [identifier] {AS [datatype]} ( [dimension1] {, [dimension2], ... } ) = # [...bytes...]
@syntax DIM [identifier] {AS [datatype]} ( [dimension1] {, [dimension2], ... } ) = # { { value1, value2, ... }, ... }
@syntax DIM [identifier] {AS [datatype]} WITH [value] ( [dimension1] {, [dimension2], ... } )

@example DIM x(42)
@example DIM values AS DWORD(20,20)
@example DIM y AS BYTE(8) = #[ff80ff80ff80ff80]
@example DIM z AS BYTE(8) = #{ 255, 128, 255, 128, 255, 128, 255, 128 }
@example DIM scores WITH 0 (2)

@usedInExample contrib_sierpinski.bas
@usedInExample contrib_sierpinski2.bas
@usedInExample contrib_sierpinski3.bas

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

@syntax WAIT FIRE { ( [port] ) } { RELEASE }

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

@syntax WAIT KEY { RELEASE }

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

@syntax WAIT KEY OR FIRE { ( [port] ) } { RELEASE }

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

@syntax OPTION EXPLICT {[ON|OFF]}

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

@syntax ORIGIN [x], [y] {UP|DOWN}

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

@syntax RESOLUTION [x], [y]

@example RESOLUTION 100, 100

@target all
</usermanual> */
