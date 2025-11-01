REM @english
REM ACCESSING MEMORY READING A BYTE
REM
REM This example shows how to read a byte from the memory.
REM
REM @italian
REM ACCEDERE ALLA MEMORIA LEGGERE UN BYTE
REM
REM Questo esempio mostra come leggere un byte dalla memoria.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,to8,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

    DIM memory AS BYTE
    DIM address AS ADDRESS
    DIM value AS BYTE

    address = VARPTR(memory)

    POKE address, 42
    value = PEEK( address )

    IF value = 42 THEN
        PRINT "ok!"
    ELSE
        PRINT "failed!"
    ENDIF

    