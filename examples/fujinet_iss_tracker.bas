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

INK BLUE
CENTER "ISS TRACKER"
PRINT
INK YELLOW
PRINT "1) BECKER PORT"
PRINT "2) HDBDOS"
PRINT
INK RED
PRINT "IF YOU ARE USING AN EMULATOR"
PRINT "CONFIGURED TO USE ONLINE FUJINET"
PRINT "CHOOSE 1. OTHERWISE, CONNECT "
PRINT "A FUJINET DEVICE AND CHOOSE 2."

DO
	port = VAL(INKEY$)
	IF port = 1 THEN
		DEFINE SERIAL BECKER PORT
		EXIT
	ELSE IF port = 2 THEN
		DEFINE SERIAL HDBDOS
		EXIT
	ENDIF
LOOP

BITMAP ENABLE(16)

CLS

map := LOAD IMAGE("worldmap.png")
iss := LOAD IMAGE("iss.png")

PROCEDURE fetch

	SHARED latitude, longitude
	SHARED latitudeAsString, longitudeAsString
	SHARED timestampString
	
	FUJINET DEVICE 0
	err = FUJINET OPEN(apiEndpoint, httpGet, noTranslation)
	IF err <> success THEN
		LOCATE , ROWS/2
		CENTER "--- OPEN ERROR ---"
		RETURN
	ENDIF
	
	FUJINET SET CHANNEL MODE json
	
	err = FUJINET PARSE JSON
	
	IF err <> success THEN
		LOCATE , ROWS/2
		CENTER "--- JSON PARSE ERROR ---"
		RETURN
	ENDIF
	
	FUJINET SET JSON QUERY queryLongitude
	FUJINET STATUS
	longitudeAsString = FUJINET READ(FUJINET BYTES)
	
	longitude = ( SCREEN WIDTH / 2 ) + ( ( VAL(longitudeAsString) * ( SCREEN WIDTH / 2 ) ) / 360 )
	
	FUJINET SET JSON QUERY queryLatitude
	FUJINET STATUS
	latitudeAsString = FUJINET READ(FUJINET BYTES)
	
	latitude = ( SCREEN HEIGHT / 2 ) + ( VAL(latitudeAsString) * ( SCREEN HEIGHT / 2 ) ) / 180
	
	FUJINET SET JSON QUERY queryTimeStamp
	FUJINET STATUS
	timestampString = FUJINET READ(FUJINET BYTES)
	
	FUJINET CLOSE
	
END PROC

firstTime = TRUE

background := NEW IMAGE(16,11)

PUT IMAGE map AT 0, 0

DO

	previousLongitude = longitude
	previousLatitude = latitude
	
	fetch[]	

	IF NOT firstTime THEN
		PUT IMAGE background AT previousLongitude, previousLatitude
		firstTime = FALSE
	ENDIF
	GET IMAGE background FROM longitude, latitude
	PUT IMAGE iss AT longitude, latitude WITH TRANSPARENCY
	
	HOME
	PRINT longitudeAsString;",";latitudeAsString
	
	SLEEP 2
	
LOOP
