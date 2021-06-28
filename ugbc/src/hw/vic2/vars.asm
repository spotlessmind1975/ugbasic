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
;*                      INTERNAL VARIABLES FOR VIC-II HARDWARE                 *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
PLOTDEST = $28 ; $29
PLOTCDEST= $26 ; $27

PLOTVBASELO:
    .byte <($A000+(0*320)),<($A000+(1*320)),<($A000+(2*320)),<($A000+(3*320))
    .byte <($A000+(4*320)),<($A000+(5*320)),<($A000+(6*320)),<($A000+(7*320))
    .byte <($A000+(8*320)),<($A000+(9*320)),<($A000+(10*320)),<($A000+(11*320))
    .byte <($A000+(12*320)),<($A000+(13*320)),<($A000+(14*320)),<($A000+(15*320))
    .byte <($A000+(16*320)),<($A000+(17*320)),<($A000+(18*320)),<($A000+(19*320))
    .byte <($A000+(20*320)),<($A000+(21*320)),<($A000+(22*320)),<($A000+(23*320))
    .byte <($A000+(24*320))

PLOTVBASEHI:
    .byte >($A000+(0*320)),>($A000+(1*320)),>($A000+(2*320)),>($A000+(3*320))
    .byte >($A000+(4*320)),>($A000+(5*320)),>($A000+(6*320)),>($A000+(7*320))
    .byte >($A000+(8*320)),>($A000+(9*320)),>($A000+(10*320)),>($A000+(11*320))
    .byte >($A000+(12*320)),>($A000+(13*320)),>($A000+(14*320)),>($A000+(15*320))
    .byte >($A000+(16*320)),>($A000+(17*320)),>($A000+(18*320)),>($A000+(19*320))
    .byte >($A000+(20*320)),>($A000+(21*320)),>($A000+(22*320)),>($A000+(23*320))
    .byte >($A000+(24*320))

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
    .byte <($8400+(0*40)),<($8400+(1*40)),<($8400+(2*40)),<($8400+(3*40))
    .byte <($8400+(4*40)),<($8400+(5*40)),<($8400+(6*40)),<($8400+(7*40))
    .byte <($8400+(8*40)),<($8400+(9*40)),<($8400+(10*40)),<($8400+(11*40))
    .byte <($8400+(12*40)),<($8400+(13*40)),<($8400+(14*40)),<($8400+(15*40))
    .byte <($8400+(16*40)),<($8400+(17*40)),<($8400+(18*40)),<($8400+(19*40))
    .byte <($8400+(20*40)),<($8400+(21*40)),<($8400+(22*40)),<($8400+(23*40))
    .byte <($8400+(24*40))

PLOTCVBASEHI:
    .byte >($8400+(0*40)),>($8400+(1*40)),>($8400+(2*40)),>($8400+(3*40))
    .byte >($8400+(4*40)),>($8400+(5*40)),>($8400+(6*40)),>($8400+(7*40))
    .byte >($8400+(8*40)),>($8400+(9*40)),>($8400+(10*40)),>($8400+(11*40))
    .byte >($8400+(12*40)),>($8400+(13*40)),>($8400+(14*40)),>($8400+(15*40))
    .byte >($8400+(16*40)),>($8400+(17*40)),>($8400+(18*40)),>($8400+(19*40))
    .byte >($8400+(20*40)),>($8400+(21*40)),>($8400+(22*40)),>($8400+(23*40))
    .byte >($8400+(24*40))

XGR:    .word 0
YGR:    .word 0
LINE:   .byte $ff, $ff
