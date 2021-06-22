REM @english
REM TEXTS OUTPUT WITH PEN COLORS (1)
REM
REM This example shows the entire collection of colors that can be used as a pen
REM to color texts. Thanks to the variable ''PEN COLORS'', it is possible to iterate
REM between the first color (0) to the last one and to draw a text with a specific color
REM index, by using the command ''PEN''.
REM
REM @italian
REM STAMPA DI TESTI CON COLORI DI PENNA (1)
REM
REM Questo esempio mostra l'intera collezione di colori che può essere utilizzata come "penna"
REM per colorare i testi. Grazie alla variabile ''PEN COLORS'' è possibile iterare dal primo 
REM colore (0) all'ultimo e disegnare un testo con uno specifico indice di colore, utilizzando 
REM il comando ''PEN''.

   FOR index=0 TO PEN COLORS - 1
      PEN index
      PRINT "PEN NUMBER ";index
   NEXT 

   HALT