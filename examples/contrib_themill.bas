REM @english
REM OTHER CONTRIBUTIONS THE MILL
REM
REM This example shows a simple way to load an entire bitmap screen
REM and to show it on the screen. The image of [[https://www.deviantart.com/oliverlindau/art/The-Mill-670453724|"The Mill"]] is
REM (c) [[https://www.deviantart.com/oliverlindau|oliverlindau]] on Deviant Art.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI IL MULINO
REM
REM Questo piccolo esempio mostra come sia semplice caricare una intera
REM bitmap e mostrarla sullo schermo. L'immagine del [[https://www.deviantart.com/oliverlindau/art/The-Mill-670453724|"Mulino"]] è
REM (c) [[https://www.deviantart.com/oliverlindau|oliverlindau]] su Deviant Art.
REM

BITMAP ENABLE(16)
themill := LOAD IMAGE("themill.png")
PUT IMAGE themill AT 0, 0





