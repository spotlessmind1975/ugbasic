REM @english
REM STORAGE MANAGEMENT LOADING IMAGES
REM
REM This example shows how to load images at runtime.
REM
REM @italian
REM MEMORIE DI MASSA CARICARE IMMAGINI
REM
REM Questo esempio mostra come caricare delle immagini a runtime.

    BITMAP ENABLE

STORAGE "disco" AS "disk1"
	SEQUENCE "sequence.png" AS "sequence" FRAME SIZE(16, 16)
ENDSTORAGE

    CLS

    sequence := NEW SEQUENCE(2, 10, 16, 16)
    ' sequence := LOAD SEQUENCE("sequence.png") FRAME SIZE(16, 16)

    DLOAD "sequence" TO VARPTR(sequence)

    DO   
        PUT IMAGE sequence SEQUENCE 0 FRAME frame AT 0, 0
        ' WAIT KEY
        ' WAIT 500 MS
        ADD frame, 1, 0 TO FRAMES(sequence)-1
    LOOP
