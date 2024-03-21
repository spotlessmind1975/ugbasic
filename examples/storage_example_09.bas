REM @english
REM STORAGE MANAGEMENT LOADING TILEMAP
REM
REM This example shows how to load tilemap at runtime.
REM
REM @italian
REM MEMORIE DI MASSA CARICARE UN TILEMAP
REM
REM Questo esempio mostra come caricare un tilemap a runtime.

    DEFINE STRING SPACE 128
    DEFINE STRING COUNT 16

    BITMAP ENABLE(16)

STORAGE "disco" AS "disk1"
	TILEMAP "kenney-line.tmx" AS "kenney" TO tilemap
ENDSTORAGE


PROCEDURE example09 ON ALL BUT C64REU

    SHARED tilemap

    CLS

    DLOAD "kenney" TO VARPTR(tilemap)

    PUT TILEMAP tilemap

END PROCEDURE

    example09[] ON ALL BUT C64REU