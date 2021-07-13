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
;*                      INTERNAL VARIABLES FOR TED HARDWARE                    *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
PLOTDEST = $28 ; $29
PLOTCDEST= $26 ; $27
PLOTLDEST= $30 ; $31

PLOTVBASELO:
    .byte <($6000+(0*320)),<($6000+(1*320)),<($6000+(2*320)),<($6000+(3*320))
    .byte <($6000+(4*320)),<($6000+(5*320)),<($6000+(6*320)),<($6000+(7*320))
    .byte <($6000+(8*320)),<($6000+(9*320)),<($6000+(10*320)),<($6000+(11*320))
    .byte <($6000+(12*320)),<($6000+(13*320)),<($6000+(14*320)),<($6000+(15*320))
    .byte <($6000+(16*320)),<($6000+(17*320)),<($6000+(18*320)),<($6000+(19*320))
    .byte <($6000+(20*320)),<($6000+(21*320)),<($6000+(22*320)),<($6000+(23*320))
    .byte <($6000+(24*320))

PLOTVBASEHI:
    .byte >($6000+(0*320)),>($6000+(1*320)),>($6000+(2*320)),>($6000+(3*320))
    .byte >($6000+(4*320)),>($6000+(5*320)),>($6000+(6*320)),>($6000+(7*320))
    .byte >($6000+(8*320)),>($6000+(9*320)),>($6000+(10*320)),>($6000+(11*320))
    .byte >($6000+(12*320)),>($6000+(13*320)),>($6000+(14*320)),>($6000+(15*320))
    .byte >($6000+(16*320)),>($6000+(17*320)),>($6000+(18*320)),>($6000+(19*320))
    .byte >($6000+(20*320)),>($6000+(21*320)),>($6000+(22*320)),>($6000+(23*320))
    .byte >($6000+(24*320))

PLOT8LO:
    .byte <(0*8),<(1*8),<(2*8),<(3*8),<(4*8),<(5*8),<(6*8),<(7*8),<(8*8),<(9*8)
    .byte <(10*8),<(11*8),<(12*8),<(13*8),<(14*8),<(15*8),<(16*8),<(17*8),<(18*8),<(19*8)
    .byte <(20*8),<(21*8),<(22*8),<(23*8),<(24*8),<(25*8),<(26*8),<(27*8),<(28*8),<(29*8)
    .byte <(30*8),<(31*8),<(32*8),<(33*8),<(34*8),<(35*8),<(36*8),<(37*8),<(38*8),<(39*8)

PLOT8HI:
    .byte >(0*8),>(1*8),>(2*8),>(3*8),>(4*8),>(5*8),>(6*8),>(7*8),>(8*8),>(9*8)
    .byte >(10*8),>(11*8),>(12*8),>(13*8),>(14*8),>(15*8),>(16*8),>(17*8),>(18*8),>(19*8)
    .byte >(20*8),>(21*8),>(22*8),>(23*8),>(24*8),>(25*8),>(26*8),>(27*8),>(28*8),>(29*8)
    .byte >(30*8),>(31*8),>(32*8),>(33*8),>(34*8),>(35*8),>(36*8),>(37*8),>(38*8),>(39*8)

PLOTCVBASELO:
    .byte <($5C00+(0*40)),<($5C00+(1*40)),<($5C00+(2*40)),<($5C00+(3*40))
    .byte <($5C00+(4*40)),<($5C00+(5*40)),<($5C00+(6*40)),<($5C00+(7*40))
    .byte <($5C00+(8*40)),<($5C00+(9*40)),<($5C00+(10*40)),<($5C00+(11*40))
    .byte <($5C00+(12*40)),<($5C00+(13*40)),<($5C00+(14*40)),<($5C00+(15*40))
    .byte <($5C00+(16*40)),<($5C00+(17*40)),<($5C00+(18*40)),<($5C00+(19*40))
    .byte <($5C00+(20*40)),<($5C00+(21*40)),<($5C00+(22*40)),<($5C00+(23*40))
    .byte <($5C00+(24*40))

PLOTCVBASEHI:
    .byte >($5C00+(0*40)),>($5C00+(1*40)),>($5C00+(2*40)),>($5C00+(3*40))
    .byte >($5C00+(4*40)),>($5C00+(5*40)),>($5C00+(6*40)),>($5C00+(7*40))
    .byte >($5C00+(8*40)),>($5C00+(9*40)),>($5C00+(10*40)),>($5C00+(11*40))
    .byte >($5C00+(12*40)),>($5C00+(13*40)),>($5C00+(14*40)),>($5C00+(15*40))
    .byte >($5C00+(16*40)),>($5C00+(17*40)),>($5C00+(18*40)),>($5C00+(19*40))
    .byte >($5C00+(20*40)),>($5C00+(21*40)),>($5C00+(22*40)),>($5C00+(23*40))
    .byte >($5C00+(24*40))

XGR:    .word 0
YGR:    .word 0
LINE:   .byte $ff, $ff

CLIPX1:    .word 0
CLIPY1:    .word 0
CLIPX2:    .word 319
CLIPY2:    .word 199
