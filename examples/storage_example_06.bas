﻿REM @english
REM STORAGE MANAGEMENT LOADING MUSIC
REM
REM This example shows how to load music at runtime.
REM
REM @italian
REM MEMORIE DI MASSA CARICARE MUSICA
REM
REM Questo esempio mostra come caricare della musica a runtime.
REM 
REM @include atari,atarixl,c128,c64,coco,coco3,vic20,cpc

STORAGE "disco" AS "disk1"
	MUSIC "example.mid" AS "example"
ENDSTORAGE

PROCEDURE example ON ALL BUT COCO, COCO3

    CLS

    track := NEW MUSIC(1024)

    DLOAD "example" TO VARPTR(track) SIZE FSIZE("example")

    MUSIC LOOP track 

END PROC

    example[] ON ALL BUT COCO, COCO3
