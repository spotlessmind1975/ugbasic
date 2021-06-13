    PROCEDURE joinString[a$,b$,c$]
        PRINT a$;" ";
        PRINT b$;" ";
        PRINT c$   ;" ";
    END PROC[a$+b$+c$]
    
    joinString["ONE","TWO","THREE"]
    PRINT PARAM$(joinString);" ";
    
    HALT