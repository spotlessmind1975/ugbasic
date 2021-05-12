    GLOBAL "*"

    PROCEDURE test
    a = a + 1
    END PROC

    a = 42
    test
    DEBUG a
    
    HALT
