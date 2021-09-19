CONST rows = 6
CONST columns = 7
CONST tokens = ( rows*columns ) / 2
CONST freeCell = $ff
CONST unusedToken = $ff

DIM playfield AS BYTE WITH freeCell (columns,rows)
DIM tokenX AS BYTE WITH unusedToken (tokens)
DIM tokenY AS BYTE (tokens)

PROCEDURE isCellOccupied[x,y]
    SHARED playfield
    RETURN playfield(x,y) <> freeCell
END PROC

PROCEDURE isCellOccupiedUnderToken[t]
    SHARED tokenX, tokenY
    RETURN isCellOccupied[tokenX(t),tokenY(t)+1]
END PROC

PROCEDURE isTokenUsed[t]
    SHARED tokenX
    RETURN tokenX(t) <> unusedToken
END PROC

PROCEDURE isTokenAtBottom[t]
    SHARED tokenY
    RETURN tokenY(t) == (rows-1)
END PROC

PROCEDURE moveTokenDown[t]
    SHARED playfield, tokenX, tokenY
    playfield(tokenX(t),tokenY(t)) = freeCell
    tokenY(t) = tokenY(t) + 1
    playfield(tokenX(t),tokenY(t)) = t
END PROC

PROCEDURE moveToken[t]
    
    SHARED playfield, tokenX, tokenY

    LOCATE 4,21: PRINT "moveToken : "; t; " used: ";isTokenUsed[t];" bottom: ";isTokenAtBottom[t];" occupied: "; isCellOccupiedUnderToken[t]

    EXIT PROC IF NOT isTokenUsed[t]
    EXIT PROC IF isTokenAtBottom[t]

    IF NOT isCellOccupiedUnderToken[t] THEN
        CALL moveTokenDown[t]
    ENDIF 

END PROC

PROCEDURE moveTokens

    FOR i = 0 TO tokens-1
        IF isTokenUsed[i] THEN
            LOCATE 2,20: PRINT i;" <- used"
            moveToken[i]
        ENDIF
    NEXT

END PROC

PROCEDURE takeNextUnusedToken

    LOCATE 10,16: PRINT "i = 0 TO ";(tokens-1)

    j = unusedToken

    FOR i = 0 TO tokens-1
        LOCATE 10,17: PRINT "LOOK FOR = ";i
        IF NOT isTokenUsed[i] THEN
            j = i
            EXIT
        ENDIF
    NEXT

    LOCATE 10,18: PRINT "FOUND = ";j
    RETURN j

END PROC

PROCEDURE putTokenAt[x]
    
    SHARED tokenX, tokenY

    t = takeNextUnusedToken[]

    LOCATE 10,19: PRINT "                   "

    EXIT PROC IF t == unusedToken

    LOCATE 10,19: PRINT " t = "; t
    tokenX(t) = x

END PROC

PROCEDURE drawPlayfield

    SHARED playfield

    FOR y = 0 TO rows-1
        FOR x = 0 TO columns-1
            LOCATE x+1,y+1
            IF playfield(x,y) == -1 THEN
                PRINT "#"
            ELSE
                PRINT playfield(x,y)
            ENDIF
        NEXT
        PRINT
    NEXT    

END PROC

PROCEDURE pollKeyboardForColumn
    
    k = INKEY$

    c = VAL(k)

    IF ( c > 0 ) AND ( c <= columns ) THEN
        CALL putTokenAt[c]
    ENDIF

END PROC

DO

    CALL drawPlayfield
    CALL pollKeyboardForColumn
    CALL moveTokens

LOOP
