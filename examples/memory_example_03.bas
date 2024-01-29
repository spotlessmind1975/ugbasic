REM @english
REM ACCESSING MEMORY READING A BYTE
REM
REM This example shows how to read a byte from the memory.
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (1)
REM
REM Questo esempio mostra come leggere un byte dalla memoria.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

    DIM memory AS DWORD
    DIM address AS ADDRESS
    DIM value AS DWORD

    address = VARPTR(memory)

    POKED address, 42424242
    value = PEEKD( address )

    IF value = 42424242 THEN
        PRINT "ok!"
    ELSE
        PRINT "failed!"
    ENDIF

    