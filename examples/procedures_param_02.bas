 PROCEDURE joinString[a$,b$,c$]
    DEBUG a$
    DEBUG b$
    DEBUG c$   
    RETURN a$+b$+c$
 END PROC
 
 joinString["ONE","TWO","THREE"]
 DEBUG PARAM$(joinString)
 
 HALT