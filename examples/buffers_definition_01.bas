REM @english
REM BUFFERS MANAGEMENT LITERAL DEFINITION
REM
REM This small example will show the basic syntax to define a buffer.
REM A buffer is a memory area that is defined statically and used "as is".
REM 
REM @italian
REM GESTIONE DEI BUFFER DEFINIZIONE LETTERALE
REM
REM Questo piccolo esempio mostra la sintassi base per definire un buffer.
REM Un buffer è un'area di memoria definita staticamente e usata "così com'è".
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000

    CLS

    b = #[48454c4c4f]
    c = #[574f524c440a]

    PRINT "b = ";b
    PRINT "c = ";c
    PRINT (STRING)b;" ";(STRING)c
