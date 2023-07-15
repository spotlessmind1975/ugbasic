REM @english
REM EXPANSION MANAGEMENT LOAD IMAGE ON BANK
REM
REM This example shows how to load an image on an expansion.
REM
REM @italian
REM ESPANSIONE DI MEMORIA CARICARE UNA IMMAGINE NELL'ESPANSIONE
REM
REM Questo esempio mostra come caricare una immagine su una espansione.

BITMAP ENABLE

CLS

checkers := LOAD IMAGE("checkers2.png" ) BANKED

PUT IMAGE checkers AT 0, 0

HALT