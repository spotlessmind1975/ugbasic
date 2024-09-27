REM @english
REM OTHER CONTRIBUTIONS THE MILL
REM
REM This example shows a simple way to load an entire bitmap screen
REM and to show it on the screen. The image of "The Mill" is
REM (c) oliverlindau on Deviant Art.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI IL MULINO
REM
REM Questo piccolo esempio mostra come sia semplice caricare una intera
REM bitmap e mostrarla sullo schermo. L'immagine del "Mulino" è
REM (c) oliverlindau on Deviant Art.
REM
REM @url https://www.deviantart.com/oliverlindau/art/The-Mill-670453724
REM
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

    BITMAP ENABLE(16)

    CLS

    PROCEDURE example ON ALL BUT PC128OP

        themill := LOAD IMAGE("themill.png")

        PUT IMAGE themill AT 0, 0

    END PROC

    example[] ON ALL BUT PC128OP
    
    WAIT KEY
    
