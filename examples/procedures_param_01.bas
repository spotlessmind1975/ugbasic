    PROCEDURE joinString[a$,b$,c$]
        DEBUG a$
        DEBUG b$
        DEBUG c$   
    END PROC[a$+b$+c$]
    
    joinString["ONE","TWO","THREE"]
    DEBUG PARAM$(joinString)
    
    HALT