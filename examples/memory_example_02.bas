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
REM @include 

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

    