 PROCEDURE joinString[a$,b$,c$]
    PRINT a$;" ";
    PRINT b$;" ";
    PRINT c$   ;" ";
    RETURN a$+b$+c$
 END PROC
 
 joinString["ONE","TWO","THREE"]
 PRINT PARAM$(joinString);" ";
 
 HALT