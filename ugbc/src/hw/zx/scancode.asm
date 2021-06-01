; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                      SCAN CODE ROUTINE FOR ZX SPECTRUM                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODE:
    LD HL,SCANCODEKM
    LD D,8
    LD C,$FE
SCANCODE0:
    LD B,(HL)
    INC HL
    IN A,(C)
    AND $1F
    LD E,5
SCANCODE1:
    SRL A
    JR NC,SCANCODE2
    INC HL
    DEC E
    JR NZ,SCANCODE1
    DEC D
    JR NZ,SCANCODE0
    AND A
    RET
SCANCODE2:
    LD A,(HL)
    RET
 
SCANCODEKM:
    DB $FE,$F1,"Z","X","C","V"
    DB $FD,"A","S","D","F","G"
    DB $FB,"Q","W","E","R","T"
    DB $F7,"1","2","3","4","5"
    DB $EF,"0","9","8","7","6"
    DB $DF,"P","O","I","U","Y"
    DB $BF,"#","L","K","J","H"
    DB $7F," ","#","M","N","B"