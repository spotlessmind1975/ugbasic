REM @english
REM TSB PROJECT BLOCK / REC COMMANDS
REM
REM This example shows some commands specific to Simons' BASIC, 
REM and how they work when recompiled with ugBASIC.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) COMANDI BLOCK / REC
REM
REM Questo esempio mostra alcuni comandi specifici del 
REM Simons' BASIC, e come funzionano se ricompilati con ugBASIC.
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

100 HIRES 0,1 
105 REPEAT: a$ = INKEY$
110 x=290.0*RND(1): y=180.0*RND(1) 
120 BLOCK x,y,x+29,y+19,0
130 REC x,y,29,19,1
140 UNTIL a$<>""
150 PAINT 0,0,1 
160 DO NULL
170 NRM
180 PRINT "Done!"
