REM @english
REM STORAGE MANAGEMENT LOADING AN IMAGE (1)
REM
REM This example shows how to load an image at runtime. This example
REM will show the first approach, that is "manual".
REM
REM @italian
REM MEMORIE DI MASSA CARICARE UNA IMMAGINE (1)
REM
REM Questo esempio mostra come caricare una immagine a runtime. Questo
REM esempio mostra il primo approccio, che è per così dire "manuale".
REM 
REM @include atari,atarixl,c128,c64,coco,coco3,vic20,cpc

    BITMAP ENABLE

STORAGE "disco" AS "disk1"
	IMAGE "token_red.png" AS "tokenred"
ENDSTORAGE

    CLS

    tokenImage := NEW IMAGE(16, 16)

    DLOAD "tokenred" TO VARPTR(tokenImage)

    PUT IMAGE tokenImage AT 32, 32
