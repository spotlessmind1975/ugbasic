REM @english
REM EXPANSION MANAGEMENT LOAD IMAGE ON BANK
REM
REM This example shows how to load an image on an expansion.
REM
REM @italian
REM ESPANSIONE DI MEMORIA CARICARE UNA IMMAGINE NELL'ESPANSIONE
REM
REM Questo esempio mostra come caricare una immagine su una espansione.
REM
REM @include coco3,c64reu

PROCEDURE example ON COCO3, C64REU

    IF BANK COUNT = 0 THEN
        PRINT "Sorry, this target "
        PRINT "  does not have any memory bank"
    ELSE

        BITMAP ENABLE

        CLS

        checkers := LOAD IMAGE("checkers2.png" ) BANKED

        PUT IMAGE checkers AT 0, 0

    ENDIF

END PROCEDURE

    example[] ON COCO3, C64REU