' /*****************************************************************************
'  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
'  *****************************************************************************
'  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
'  *
'  * Licensed under the Apache License, Version 2.0 (the "License");
'  * you may not use this file except in compliance with the License.
'  * You may obtain a copy of the License at
'  *
'  * http://www.apache.org/licenses/LICENSE-2.0
'  *
'  * Unless required by applicable law or agreed to in writing, software
'  * distributed under the License is distributed on an "AS IS" BASIS,
'  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
'  * See the License for the specific language governing permissions and
'  * limitations under the License.
'  *----------------------------------------------------------------------------
'  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
'  * (la "Licenza"); è proibito usare questo file se non in conformità alla
'  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
'  *
'  * http://www.apache.org/licenses/LICENSE-2.0
'  *
'  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
'  * il software distribuito nei termini della Licenza è distribuito
'  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
'  * implicite. Consultare la Licenza per il testo specifico che regola le
'  * autorizzazioni e le limitazioni previste dalla medesima.
'  ****************************************************************************/
'  ****************************************************************************
'  *** IMPORT DECLARES FOR TARGET atarixl (ATARI XL/XE)
'  ****************************************************************************
'  ** Informations from: https://atariwiki.org/wiki/Wiki.jsp?page=How%20to%20read%20a%20Key%20from%20Keyboard%20with%20ATARI%20ROM%20Routines
'  ****************************************************************************
'  * Tested with ugBASIC v1.14.1
'  ****************************************************************************

PROCEDURE getkey ON ATARIXL

    DIM key AS BYTE

    GOTO getkeydone

ON ATARIXL BEGIN ASM

GETKEY:
        LDA $E425
        PHA
        LDA $E424
        PHA
        RTS

END ASM

getkeydone:

ON ATARIXL BEGIN ASM

        JSR GETKEY
        STA _getkey_key

END ASM

        RETURN key

END PROC


