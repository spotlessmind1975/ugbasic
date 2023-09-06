REM @english
REM STATIC IMAGES SEQUENCE LOADING AND DISPLAY OF A FRAME
REM
REM This small example will show how to load sequence from a single image.
REM The basic syntax is to give a "frame size" of each frame inside the
REM original image. In this way, every frame will be taken to generate
REM a set of IMAGES datatype. Note that SEQUENCE can be used as IMAGES as well,
REM and it means to use the first frame.
REM
REM @italian
REM GESTIONE DELLE IMMAGINI CARICAMENTO SEQUENZA (1)
REM
REM Questo piccolo esempio mostrerà come caricare un insieme di set di immagini 
REM a partire da una immagine. La sintassi di base permette di dare una 
REM "dimensione del fotogramma" all'interno dell'immagine originale. 
REM In questo modo, l'insieme dei frame verrà preso per generare un tipo 
REM di dati SEQUENCE. Nota che questo tipo di dato può essere usato anche 
REM come IMAGE, il che significa usare il primo fotogramma.
REM
REM @include atari,atarixl,c128,c64,coco

    BITMAP ENABLE (16)
    CLS

    sequence := LOAD SEQUENCE("sequence.png" ) FRAME SIZE (16,16)

    PUT IMAGE sequence SEQUENCE 1 FRAME 0 AT 0,0

