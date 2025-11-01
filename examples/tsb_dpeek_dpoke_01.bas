REM TSB PROJECT USING D!PEEK AND D!POKE
REM
REM This example shows how D!POKE and D!PEEK work.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) COME USARE D!PEEK E D!POKE
REM
REM Questo esempio mostra come funzionano D!POKE e D!PEEK.
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

D!POKE &Hc000, 42
PRINT D!PEEK(&Hc000)

