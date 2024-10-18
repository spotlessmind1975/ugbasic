REM @english
REM STORAGE MANAGEMENT LOADING IMAGES
REM
REM This example shows how to load images at runtime.
REM
REM @italian
REM MEMORIE DI MASSA CARICARE IMMAGINI
REM
REM Questo esempio mostra come caricare delle immagini a runtime.
REM 
REM @include atari,atarixl,c128,c64,coco,coco3,vic20,cpc

    BITMAP ENABLE(16)

STORAGE "disco" AS "disk1"
	IMAGES "bat.png" AS "bat" FRAME SIZE(32, 32)
ENDSTORAGE

    CLS

    batImages := NEW IMAGES(10, 32, 32)

    DLOAD "bat" TO VARPTR(batImages)

    DO   
        PUT IMAGE batImages FRAME frame AT 0, 0
        ADD frame, 1, 0 TO FRAMES(batImages)-1
    LOOP
