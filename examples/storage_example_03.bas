REM @english
REM STORAGE MANAGEMENT LOADING AN IMAGE (2)
REM
REM This example shows how to load an image at runtime. This example
REM will show the first approach, that is "manual", with multiple
REM images.
REM
REM @italian
REM MEMORIE DI MASSA CARICARE UNA IMMAGINE (1)
REM
REM Questo esempio mostra come caricare una immagine a runtime. Questo
REM esempio mostra il primo approccio, che è per così dire "manuale",
REM ed applicato a immagini multiple.

    BITMAP ENABLE

STORAGE "disco" AS "disk1"
	IMAGE "token_red.png" AS "tokenred"
	IMAGE "token_yellow.png" AS "tokenye"
ENDSTORAGE

    CLS

    tokenImage := NEW IMAGE(16, 16)

    DLOAD "tokenred" TO VARPTR(tokenImage)

    PUT IMAGE tokenImage AT 0, 0

    WAIT KEY

    DLOAD "tokenye" TO VARPTR(tokenImage)

    PUT IMAGE tokenImage AT 0, 0    
