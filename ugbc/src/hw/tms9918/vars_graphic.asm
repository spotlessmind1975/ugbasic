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
;*                          INTERNAL VARIABLES FOR TMS9918                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ------------------------------------------------------------------------------
; BITMAP_MODE_GRAPHIC2
; ------------------------------------------------------------------------------

PLOTVBASE:
    DW ($0000+(0*256)),($0000+(1*256)),($0000+(2*256)),($0000+(3*256))
    DW ($0000+(4*256)),($0000+(5*256)),($0000+(6*256)),($0000+(7*256))
    DW ($0000+(8*256)),($0000+(9*256)),($0000+(10*256)),($0000+(11*256))
    DW ($0000+(12*256)),($0000+(13*256)),($0000+(14*256)),($0000+(15*256))
    DW ($0000+(16*256)),($0000+(17*256)),($0000+(18*256)),($0000+(19*256))
    DW ($0000+(20*256)),($0000+(21*256)),($0000+(22*256)),($0000+(23*256))

PLOT8:
    DW (0*8),(1*8),(2*8),(3*8),(4*8),(5*8),(6*8),(7*8),(8*8),(9*8)
    DW (10*8),(11*8),(12*8),(13*8),(14*8),(15*8),(16*8),(17*8),(18*8),(19*8)
    DW (20*8),(21*8),(22*8),(23*8),(24*8),(25*8),(26*8),(27*8),(28*8),(29*8)
    DW (30*8),(31*8)

PLOTCVBASE:
    DW ($2000+(0*256)),($2000+(1*256)),($2000+(2*256)),($2000+(3*256))
    DW ($2000+(4*256)),($2000+(5*256)),($2000+(6*256)),($2000+(7*256))
    DW ($2000+(8*256)),($2000+(9*256)),($2000+(10*256)),($2000+(11*256))
    DW ($2000+(12*256)),($2000+(13*256)),($2000+(14*256)),($2000+(15*256))
    DW ($2000+(16*256)),($2000+(17*256)),($2000+(18*256)),($2000+(19*256))
    DW ($2000+(20*256)),($2000+(21*256)),($2000+(22*256)),($2000+(23*256))

