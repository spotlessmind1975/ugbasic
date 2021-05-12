 PROCEDURE joinString[a$,b$,c$]
    DEBUG a$
    DEBUG b$
    DEBUG c$   
    RETURN a$+b$+c$
 END PROC
 
 DEBUG joinString["ONE","TWO","THREE"]
 HALT
 