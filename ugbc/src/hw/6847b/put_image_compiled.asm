
; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                       COMPILED IMAGES ROUTINE FOR 6847B                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 2) || (currentMode == 3) )

PUTCIMAGE2CALCPOS
PUTCIMAGE3CALCPOS

    LDX TEXTADDRESS
    LDB <(IMAGEY+1)

    LSLB
    LSLB
    ADDB <(IMAGEY+1)
    LSRB
    LSRB
    LSRB
    LSRB
    LSRB
    LSRB
    CLRA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 7) )

PUTCIMAGE7CALCPOS

    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D,X 
    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D,X 
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 8) )

PUTCIMAGE8CALCPOS
    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 9) )

PUTCIMAGE9CALCPOS
    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 10) )

PUTCIMAGE10CALCPOS
    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 11) )

PUTCIMAGE11CALCPOS
    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 12) )

PUTCIMAGE12CALCPOS
    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 13) )

PUTCIMAGE13CALCPOS
    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 14) )

PUTCIMAGE14CALCPOS
    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    RTS

@ENDIF
