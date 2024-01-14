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

    