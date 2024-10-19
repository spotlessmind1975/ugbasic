REM @english
REM STORAGE MANAGEMENT LOADING TILESET
REM
REM This example shows how to load tileset at runtime.
REM
REM @italian
REM MEMORIE DI MASSA CARICARE UN TILESET
REM
REM Questo esempio mostra come caricare un tileset a runtime.
REM 
REM @include atari,atarixl,c128,c64,coco,coco3,vic20,cpc

    BITMAP ENABLE(16)

STORAGE "disco" AS "disk1"
	TILESET "kenney-tiny-town.tsx" AS "ktt" TO tileset
ENDSTORAGE

    CLS

    DLOAD "ktt" TO VARPTR(tileset)

    PUT IMAGE tileset FRAME 0 AT 0,0
