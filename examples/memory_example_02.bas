REM @english
REM ACCESSING MEMORY READING A WORD
REM
REM This example shows how to read a word from the memory.
REM
REM @italian
REM ACCEDERE ALLA MEMORIA LEGGERE UNA WORD
REM
REM Questo esempio mostra come leggere una word dalla memoria.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,to8,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

    DIM memory AS WORD
    DIM address AS ADDRESS
    DIM value AS WORD

    address = VARPTR(memory)

    POKEW address, 4242
    value = PEEKW( address )

    IF value = 4242 THEN
        PRINT "ok!"
    ELSE
        PRINT "failed!"
    ENDIF

    