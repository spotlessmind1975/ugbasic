REM @english
REM TEXTS OUTPUT DISPLAY ALL PAPER COLORS (USING PAPER)
REM
REM This example shows the entire collection of colors that can be used as paper
REM to color backgrounds. Thanks to the variable ''PAPER COLORS'', it is possible to iterate
REM between the first color (0) to the last one and to draw a text over a specific color
REM index, by using the command ''PAPER''.
REM
REM @italian
REM STAMPA DI TESTI CON COLORI DI SFONDO (1)
REM
REM Questo esempio mostra l'intera collezione di colori che può essere utilizzata come "sfondo"
REM per colorare i testi. Grazie alla variabile ''PAPER COLORS'' è possibile iterare dal primo 
REM colore (0) all'ultimo e disegnare un testo sopra uno specifico indice di colore, utilizzando 
REM il comando ''PAPER''.

   CLS

   PEN DEFAULT PEN
   
   FOR index = 0 TO PAPER COLORS-1
      PAPER index
      PRINT "PAPER NUMBER ";index;SPACE(23)
   NEXT
