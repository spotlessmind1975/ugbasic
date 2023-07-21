REM @english
REM AUDIO GENERATION VOLUME CONTROL
REM
REM This small example will show how to manage the volume.
REM 
REM @italian
REM AUDIO E MUSICA CONTROLLO DEL VOLUME
REM
REM Questo piccolo esempio vi mostrerà come gestire il volume.
REM

	CLS

	FOR level=VOLUME MIN TO VOLUME MAX
    	VOLUME level
      	BELL NOTE C4
      	WAIT 500 MS
  	NEXT
