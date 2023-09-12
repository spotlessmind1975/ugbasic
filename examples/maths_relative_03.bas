REM @english
REM MATHEMATIC ROUTINES LIMITS OF NUMERIC TYPES
REM
REM This example attempts to show the behavior of the system when dealing 
REM with conversion between types, signed or unsigned. The rule that ugBASIC 
REM uses is the minimum error rule: in general, if the destination type has 
REM a sufficient number of bits, it is possible to represent the information 
REM without losses. If the destination type has fewer bits, the number is 
REM guaranteed to be represented correctly if the number of destination bits 
REM are sufficient. In case of signed types, if the source number is 
REM negative but the destination type is unsigned, the value will be set 
REM to the absolute value without sign.
REM
REM @italian
REM ROUTINE DI MATEMATICA CON L'USO DI MIN
REM
REM Questo esempio cerca di mostrare il comportamento del sistema quando 
REM ha a che fare con la conversione tra tipi, con o senza segno. La regola 
REM che ugBASIC utilizza è quella dell'errore minimo: in generale, se il 
REM tipo di destinazione ha un numero sufficiente di bit, è possibile 
REM rappresentare l'informazione senza perdite. Se il tipo di destinazione 
REM ha un numero inferiore di bit, si garantisce che il numero sia 
REM rappresentato correttamente se il numero di bit di destinazione sono 
REM sufficienti. In caso di tipi con segno, se il numero di sorgente è 
REM negativo ma il tipo di destinazione è privo di segno, il valore sarà 
REM posto al valor assoluto.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

    CLS

    ' ******************************************************************
    ' ******** destination: signed byte ********************************
    ' ******************************************************************

    DIM sb AS SIGNED BYTE

    ' source underflow -> destination underflow
    '
    ' -42 = 11010110 -> 11010110 -> -42
    sb = -42
    PRINT "signed byte(-42) = "; sb; " (exp ";"-42";" )"

    ' source overflow [with unsigned byte] -> destination approximation
    '
    ' 200 = 11001000 -> 01001000 -> +72
    sb = 200
    PRINT "signed byte(200) = "; sb; " (exp ";"72";" )"

    ' source overflow [with signed word] -> destination approximation
    '
    ' -500 = 1111111000001100 -> 000111110100 -> 11110100 -> -116
    sb = -500
    PRINT "signed byte(-500) = "; sb; " (exp ";"-116";" )"

    ' source overflow [with unsigned word] -> destination approximation
    '
    ' 20000 = 0100111000100000 -> 00100000 -> +32
    sb = 20000
    PRINT "signed byte(20000) = "; sb; " (exp ";"32";" )"

    ' source overflow [with signed dword] -> destination approximation
    '
    ' -100500 = 11111111111111100111011101101100 -> 00011000100010010100 -> 10010100
    sb = -100500
    PRINT "signed byte(-100500) = "; sb; " (exp ";"-20";" )"

    ' source overflow [with unsigned dword] -> destination approximation

    sb = 10020000
    PRINT "signed byte(10020000) = "; sb; " (exp ";"32";" )"

    ' ******************************************************************
    ' ******************************************************************
    ' ******************************************************************

    WAIT KEY RELEASE : PRINT

    ' ******************************************************************
    ' ******** destination: unsigned byte ******************************
    ' ******************************************************************

    DIM b AS BYTE

    ' source underflow -> destination underflow
    '
    ' 42 = 11010110 -> 11010110 -> 42
    b = 42
    PRINT "byte(42) = "; b; " (exp ";"42";" )"

    ' source overflow [with unsigned byte] -> destination unsigned
    '
    ' -42 = 11010110 -> 01001000 -> +42
    b = -42
    PRINT "byte(-42) = "; b; " (exp ";"42";" )"

    ' source overflow [with signed word] -> destination approximation
    '
    ' -500 = 1111111000001100 -> 000111110100 -> 11110100 -> -116
    b = -500
    PRINT "byte(-500) = "; b; " (exp ";"12";" )"

    ' source overflow [with unsigned word] -> destination approximation
    '
    ' 20000 = 0100111000100000 -> 00100000 -> +32
    b = 20000
    PRINT "byte(20000) = "; b; " (exp ";"32";" )"

    ' source overflow [with signed dword] -> destination approximation
    '
    ' -100500 = 11111111111111100111011101101100 -> 00011000100010010100 -> 10010100
    b = -100500
    PRINT "byte(-100500) = "; b; " (exp ";"148";" )"

    ' source overflow [with unsigned dword] -> destination approximation

    b = 10020000
    PRINT "byte(10020000) = "; b; " (exp ";"160";" )"

    ' ******************************************************************
    ' ******************************************************************
    ' ******************************************************************

    WAIT KEY RELEASE : PRINT

    ' ****************************************************************
    ' ******** destination: signed word ******************************
    ' ****************************************************************

    DIM sw AS SIGNED WORD

    ' source underflow -> destination underflow
    '
    ' 42 = 11010110 -> 11010110 -> 42
    sw = 42
    PRINT "signed word(42) = "; sw; " (exp ";"42";" )"

    ' source underflow [with unsigned byte] -> destination underflow
    '
    ' -42 = 11010110 -> -42
    sw = -42
    PRINT "signed word(-42) = "; sw; " (exp ";"-42";" )"

    ' source underfow [with signed word] -> destination underflow
    '
    ' -500 = 1111111000001100 -> -500
    sw = -500
    PRINT "signed word(-500) = "; sw; " (exp ";"-500";" )"

    ' source overflow [with unsigned word] -> destination approximation
    '
    ' 40000 = 0100111000100000 -> 00100000 -> 7232
    sw = 40000
    PRINT "signed word(40000) = "; sw; " (exp ";"7232";" )"

    ' source overflow [with signed dword] -> destination approximation
    '
    ' -100500 = 11111111111111100111011101101100 -> 00011000100010010100 -> 10010100
    sw = -100500
    PRINT "signed word(-100500) = "; sw; " (exp ";"-2196";" )"

    ' source overflow [with unsigned dword] -> destination approximation

    sw = 10020000
    PRINT "signed word(10020000) = "; sw; " (exp ";"25760";" )"

    ' ******************************************************************
    ' ******************************************************************
    ' ******************************************************************

    WAIT KEY RELEASE : PRINT

    ' ******************************************************************
    ' ******** destination: unsigned word ******************************
    ' ******************************************************************

    DIM w AS WORD

    ' source underflow -> destination underflow
    '
    ' 42 = 11010110 -> 11010110 -> 42
    w = 42
    PRINT "word(42) = "; w; " (exp ";"42";" )"

    ' source underflow [with unsigned byte] -> destination underflow
    '
    ' -42 = 11010110 -> -42
    w = -42
    PRINT "word(-42) = "; w; " (exp ";"42";" )"

    ' source underfow [with signed word] -> destination underflow
    '
    ' -500 = 1111111000001100 -> -500
    w = -500
    PRINT "word(-500) = "; w; " (exp ";"500";" )"

    ' source overflow [with unsigned word] -> destination underflow
    '
    ' 40000 = 0100111000100000 -> 00100000 -> 7232
    w = 40000
    PRINT "word(40000) = "; w; " (exp ";"40000";" )"

    ' source overflow [with signed dword] -> destination approximation
    '
    ' -100500 = 11111111111111100111011101101100 -> 00011000100010010100 -> 10010100
    w = -100500
    PRINT "word(-100500) = "; w; " (exp ";"30752";" )"

    ' source overflow [with unsigned dword] -> destination approximation

    w = 10020000
    PRINT "word(10020000) = "; w; " (exp ";"58528";" )"

    ' ******************************************************************
    ' ******************************************************************
    ' ******************************************************************

    WAIT KEY RELEASE : PRINT

    ' *****************************************************************
    ' ******** destination: signed dword ******************************
    ' *****************************************************************

    DIM dw AS SIGNED DWORD

    ' source underflow -> destination underflow
    '
    ' 42 = 11010110 -> 11010110 -> 42
    dw = 42
    PRINT "signed dword(42) = "; dw; " (exp ";"42";" )"

    ' source underflow [with unsigned byte] -> destination underflow
    '
    ' -42 = 11010110 -> -42
    dw = -42
    PRINT "signed dword(-42) = "; dw; " (exp ";"-42";" )"

    ' source underfow [with signed word] -> destination underflow
    '
    ' -500 = 1111111000001100 -> -500
    dw = -500
    PRINT "signed dword(-500) = "; dw; " (exp ";"-500";" )"

    ' source underflow [with unsigned word] -> destination underflow
    '
    ' 40000 = 0100111000100000 -> 00100000 -> 7232
    dw = 40000
    PRINT "signed dword(40000) = "; dw; " (exp ";"40000";" )"

    ' source underflow [with signed dword] -> destination underflow
    '
    ' -100500 = 11111111111111100111011101101100 -> 00011000100010010100 -> 10010100
    dw = -100500
    PRINT "signed dword(-100500) = "; dw; " (exp ";"-100500";" )"

    ' source underflow [with unsigned dword] -> destination approximation

    dw = 10020000
    PRINT "signed dword(10020000) = "; sw; " (exp ";"25760";" )"

    ' ******************************************************************
    ' ******************************************************************
    ' ******************************************************************

    WAIT KEY RELEASE : PRINT

    ' ******************************************************************
    ' ******** destination: unsigned word ******************************
    ' ******************************************************************

    DIM udw AS DWORD

    ' source underflow -> destination underflow
    '
    ' 42 = 11010110 -> 11010110 -> 42
    udw = 42
    PRINT "unsigned dword(42) = "; udw; " (exp ";"42";" )"

    ' source underflow [with unsigned byte] -> destination underflow
    '
    ' -42 = 11010110 -> -42
    udw = -42
    PRINT "unsigned dword(-42) = "; udw; " (exp ";"42";" )"

    ' source underfow [with signed word] -> destination underflow
    '
    ' -500 = 1111111000001100 -> -500
    udw = -500
    PRINT "unsigned dword(-500) = "; udw; " (exp ";"500";" )"

    ' source underflow [with unsigned word] -> destination underflow
    '
    ' 40000 = 0100111000100000 -> 00100000 -> 7232
    udw = 40000
    PRINT "unsigned dword(40000) = "; udw; " (exp ";"40000";" )"

    ' source underflow [with signed dword] -> destination underflow
    '
    ' -100500 = 11111111111111100111011101101100 -> 00011000100010010100 -> 10010100
    udw = -100500
    PRINT "unsigned dword(-100500) = "; udw; " (exp ";"-100500";" )"

    ' source underflow [with unsigned dword] -> destination underflow

    udw = 10020000
    PRINT "unsigned dword(10020000) = "; udw; " (exp ";"10020000";" )"
