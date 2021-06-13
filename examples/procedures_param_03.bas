 PROCEDURE joinString[a$,b$,c$]
    PRINT a$;" ";
    PRINT b$;" ";
    PRINT c$   ;" ";
    RETURN a$+b$+c$
 END PROC
 
 PRINT joinString["ONE","TWO","THREE"];" ";
 HALT
 