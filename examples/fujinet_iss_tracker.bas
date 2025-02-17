REM FUJINET PROJECT ISS TRACKER
REM
REM This is an example for ISS tracking application.
REM
REM @italian
REM PROGETTO FUJINET (ESEMPI) ISS TRACKING
REM
REM Questo è un esempio di applicazione che traccia la ISS.
REM 
REM @include coco

CONST httpGet = 12
CONST noTranslation = 0
CONST json = 1
CONST success = 1

CONST apiEndpoint = "N:HTTP://api.open-notify.org/iss-now.json"
CONST queryLongitude = "/iss_position/longitude"
CONST queryLatitude = "/iss_position/latitude"
CONST queryTimeStamp = "/timestamp"

latitude = 0
longitude = 0
longitudeString = ""
latitudeString = ""
timestampString = ""

CLS

PROCEDURE selectFujiNet ON COCO

	CENTER "ISS TRACKER"
	PRINT
	PRINT "CHOOSE YOUR FUJINET:"
	PRINT 
	PRINT "1) emulated/virtualized (becker port)"
	PRINT "2) real hardware"
	PRINT
	
	DO
		port = VAL(INKEY$)
		IF port = 1 THEN
			DEFINE FUJINET BECKER PORT
			EXIT
		ELSE IF port = 2 THEN
			DEFINE FUJINET HDBDOS
			EXIT
		ENDIF
	LOOP

END PROC

PROCEDURE selectFujiNet ON ATARI

	CENTER "ISS TRACKER"
	PRINT
	PRINT "CHOOSE YOUR FUJINET:"
	PRINT 
	PRINT "1) emulated (via device R1:)"
	PRINT "2) virtualized/real hardware"
	PRINT
	
	DO
		port = VAL(INKEY$)
		IF port = 1 THEN
			DEFINE FUJINET SERIAL
			EXIT
		ELSE IF port = 2 THEN
			DEFINE FUJINET SIO
			EXIT
		ENDIF
	LOOP

END PROC

selectFujiNet[] ON COCO
selectFujiNet[] ON ATARI

BITMAP ENABLE(16)

CLS

map := LOAD IMAGE("worldmap.png") EXACT
iss := LOAD IMAGE("iss.png") EXACT

PROCEDURE fetch

	SHARED latitude, longitude
	SHARED latitudeAsString, longitudeAsString
	SHARED timestampString
	
	FUJINET DEVICE 0
	err = FUJINET OPEN(apiEndpoint, httpGet, noTranslation)
	
	IF err <> success THEN
		HOME
		CENTER "--- OPEN ERROR ---"
		RETURN
	ENDIF
	
	FUJINET SET CHANNEL MODE json
	
	err = FUJINET PARSE JSON
	
	IF err <> success THEN
		HOME
		CENTER "--- JSON PARSE ERROR ---"
		RETURN
	ENDIF
	
	FUJINET SET JSON QUERY queryLongitude
	FUJINET STATUS
	
	longitudeAsString = FUJINET READ(FUJINET BYTES AS STRING)
	
	longitude = ( SCREEN WIDTH / 2 ) + ( ( VAL(longitudeAsString) * ( SCREEN WIDTH / 2 ) ) / 360 )
	
	FUJINET SET JSON QUERY queryLatitude
	FUJINET STATUS
	latitudeAsString = FUJINET READ(FUJINET BYTES AS STRING)
	
	latitude = ( SCREEN HEIGHT / 2 ) + ( VAL(latitudeAsString) * ( SCREEN HEIGHT / 2 ) ) / 180
	
	FUJINET SET JSON QUERY queryTimeStamp
	FUJINET STATUS
	timestampString = FUJINET READ(FUJINET BYTES AS STRING)
	
	FUJINET CLOSE
	
	HOME
	PRINT longitudeAsString;",";latitudeAsString
	
END PROC

firstTime = TRUE

background := NEW IMAGE(16,11)

PUT IMAGE map AT 0, 0

DO

	previousLongitude = longitude
	previousLatitude = latitude

	fetch[]

	IF longitude <> 0 AND latitude <> 0 THEN
		IF NOT firstTime THEN
			PUT IMAGE background AT previousLongitude, previousLatitude
			firstTime = FALSE
		ENDIF
		GET IMAGE background FROM longitude, latitude
		PUT IMAGE iss AT longitude, latitude WITH TRANSPARENCY
	ENDIF
	
	SLEEP 10
	
LOOP
