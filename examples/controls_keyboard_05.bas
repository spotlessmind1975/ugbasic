REM @english
REM I/O CONTROL KEYBOARD READ (BIT DECODING SCANSHIFT)
REM
REM This example will show the various way that are allowed in order to
REM check if a specific (shift) bit is on or off. The first is by using
REM the ''BIT'' function, that check for a specific bit. The second is
REM using the keywords ''BIT...OF'', that is a synonym of the previous
REM function. Finally, we show the use of conditions ''HAS BIT'' and ''IS'',
REM that checks for specific bitmask.
REM
REM @italian
REM CONTROLLI DI I/O LETTURA TASTIERA (DECODIFICA BIT DI SCANSHIFT)
REM
REM Questo esempio mostra i vari modi consentiti per controllare se uno specifico
REM bit (di shifting) è acceso o meno. Il primo impiega la funzione ''BIT'',
REM che controlla per l'accensione di uno specifico bit. Il secondo
REM usa le istruzioni ''BIT...OF'', che è un sinonimo della funzione precedente.
REM infine, si mostra l'utilizzo delle condizioni ''HAS BIT'' e ''IS'',
REM che controllano per un bitmask specifico.

    CLS

    DO

        HOME

        PRINT SCANSHIFT
        
        left = BIT( SCANSHIFT, LEFT SHIFT )
        PRINT "LEFT IS: ";left
        
        left = BIT LEFT SHIFT OF SCANSHIFT
        PRINT "LEFT IS: ";left
        
        IF SCANSHIFT HAS BIT LEFT SHIFT THEN : PRINT "LEFT" : ENDIF
        IF SCANSHIFT IS LEFT SHIFT THEN : PRINT "LEFT" : ENDIF
        
        IF SCANSHIFT HAS NOT BIT LEFT SHIFT THEN : PRINT "NOT LEFT" : ENDIF
        IF SCANSHIFT IS NOT LEFT SHIFT THEN : PRINT "NOT LEFT" : ENDIF

    LOOP
