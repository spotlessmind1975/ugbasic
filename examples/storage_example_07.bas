REM @english
REM STORAGE MANAGEMENT LOADING ON VARIABLES
REM
REM This example shows how to make ugBASIC understand the
REM memory needed for the various elements in the storage,
REM without defining them.
REM
REM @italian
REM MEMORIE DI MASSA CARICARE MUSICA
REM
REM Questo esempio mostra come far sì che ugBASIC comprenda
REM le necessità di memoria dei vari elementi stoccati nelle
REM memorie di massa, senza aver necessità di definirli 
REM esplicitamente.
REM 
REM @include atari,atarixl,c128,c64,coco,coco3,vic20,cpc

GLOBAL track

STORAGE "disco" AS "disk1"
	MUSIC "example.mid" AS "track1" TO track
    MUSIC "what_a_wonderful_world.mid" AS "track2" TO track
ENDSTORAGE

PROCEDURE example ON ALL BUT COCO, COCO3

    DIM song AS STRING
    DIM songName AS STRING

    DO
        CLS

        PRINT "SELECT A SONG"
        PRINT
        PRINT "1. Example of song"
        PRINT "2. What a wonderful world"

        INPUT song

        SELECT CASE song
            CASE "1"
                songName = "track1"
            CASE "2"
                songName = "track2"
            CASE ELSE
                songName = ""
        ENDSELECT

        IF songName <> "" THEN
            DLOAD songName TO VARPTR(track)
            MUSIC LOOP track
            PRINT "... press any key to stop ..."
            WAIT KEY
        ENDIF

    LOOP        

END PROC

    example[] ON ALL BUT COCO, COCO3
