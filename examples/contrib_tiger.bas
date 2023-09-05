REM @english
REM OTHER CONTRIBUTIONS A CARTOON FOREST
REM
REM This example shows how much the MSC1 algorithm can compress 
REM when dealing with an anime-style (cartoon) image.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI UNA FORESTA DI CARTONI
REM
REM Questo esempio mostra quanto riesce a comprimere l'algoritmo MSC1, 
REM quando si trova ad avere a che fare con una immagine in stile 
REM anime (cartoon).
REM
REM @include atari,atarixl,c128,c64

    BITMAP ENABLE(2)

    CLS

    tiger := LOAD IMAGE("tiger128x128x4.png") 

    PUT IMAGE tiger AT 0, 0
