REM @english
REM COMPILATION PRAGMA DEFINE VIDEO OUTPUT (AUTO)
REM
REM This example allows you to define the television standard to
REM be used for programs, as well as the associated timing parameters.
REM 
REM @italian
REM PRAGMA DI COMPILAZIONE DEFINIZIONE DELLO STANDARD TELEVISIVO (AUTO)
REM
REM Questo esempio consente di definire lo standard televisivo da 
REM utilizzare per i programmi, e le relative temporizzazioni.
REM
REM @include atari atarixl c128 c128z c16 c64 c64reu coco cocob coco3 coco3b coleco cpc d32 d32b d64 d64b gb mo5 msx1 pc128op pc1403 pccga plus4 sc3000 sg1000 to8 vic20 zx

DEFINE VIDEO OUTPUT AUTO

CLS
PRINT "VIDEO STANDARD"
PRINT "--------------"
PRINT
PRINT "TICKS PER SECONDS = "; TICKS PER SECOND

