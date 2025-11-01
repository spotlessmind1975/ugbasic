REM @english
REM USER-DEFINED PROCEDURES RETURN VALUE (USING PARAM$())
REM
REM This example will demonstrate how to define procedures with
REM one or more parameters. Parameters are a way to give informations
REM to the procedure. Moreover, it shows one way to retrieve the returning value
REM of the procedure. There are several. Anyway, the parameters should
REM be considered like local variables that are feeded by the caller.
REM The returning value should be considered as a value than could
REM be used by the caller. The example will implement a procedure that
REM merges three strings all togheter. 
REM
REM @italian
REM USARE LE PROCEDURE CON PARAMETRI (1)
REM
REM Questo esempio dimostrerà come definire procedure con uno o più parametri. 
REM I parametri sono un modo per dare informazioni alla procedura. Inoltre, 
REM l'esempio mostra un modo per recuperare il valore restituito dalla procedura. 
REM Ce ne sono diversi. I parametri vanno comunque considerati come variabili 
REM locali che vengono alimentate dal chiamante. Il valore restituito deve essere
REM considerato come un valore che potrebbe essere utilizzato dal chiamante. 
REM L'esempio implementerà una procedura che unisce tre stringhe tutte insieme.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,pc128op,to8,cpc

    CLS
    
    PROCEDURE joinString[a$,b$,c$ ]
        PRINT "joinString called with:"
        PRINT " a$ = ";a$
        PRINT " b$ = ";b$
        PRINT " c$ = ";c$
    END PROC[a$+b$+c$]
    
    joinString["ONE","TWO","THREE"]

    PRINT "joinString[ONE,TWO,THREE] = ";PARAM$(joinString)
