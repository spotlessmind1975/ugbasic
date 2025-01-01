/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *----------------------------------------------------------------------------
 * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
 * (la "Licenza"); è proibito usare questo file se non in conformità alla
 * Licenza. Una copia della Licenza è disponibile all'indirizzo:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Se non richiesto dalla legislazione vigente o concordato per iscritto,
 * il software distribuito nei termini della Licenza è distribuito
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"
#include <math.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/* <usermanual>
@keyword EXP

@english

The ''EXP'' command is a mathematical function that calculates the natural 
exponential of a number. In other words, it raises Napier's number (e = 2.71828) 
to the specified power.

The ''EXP'' function has numerous applications in mathematics, science, 
and engineering. It is used to describe phenomena that grow at a rate 
proportional to the amount present, such as population growth or 
radioactive decay. The natural exponential is closely related to 
trigonometric functions and can be used to calculate them.

Many differential equations have solutions that involve the 
natural exponential, and it appears in many probability distributions, 
such as the exponential distribution and the normal distribution.

Noe that ''EXP'' function is defined only for ''FLOAT'' numbers.

@italian

Il comando ''EXP'' è una funzione matematica che calcola l'esponenziale 
naturale di un numero. In altre parole, eleva il numero di Napier 
(e = 2,71828) alla potenza specificata.

La funzione ''EXP'' ha numerose applicazioni in matematica, scienza e 
ingegneria. Viene utilizzata per descrivere fenomeni che crescono a 
una velocità proporzionale alla quantità presente, come la crescita 
della popolazione o il decadimento radioattivo. L'esponenziale 
naturale è strettamente correlato alle funzioni trigonometriche 
e può essere utilizzato per calcolarle.

Molte equazioni differenziali hanno soluzioni che coinvolgono 
l'esponenziale naturale e appare in molte distribuzioni di 
probabilità, come la distribuzione esponenziale e la 
distribuzione normale.

Noto che la funzione ''EXP'' è definita solo per numeri ''FLOAT''.

@syntax = EXP(number)

@example x = EXP(21)

</usermanual> */
Variable * fp_exp( Environment * _environment, char * _value ) {

    Variable * value = variable_retrieve_or_define( _environment, _value, VT_FLOAT, 0 );
    Variable * result = variable_temporary( _environment, VT_FLOAT, "(exp)");

    switch( result->precision ) {
        case FT_FAST:
            cpu_float_fast_exp( _environment, value->realName, result->realName );
            break;
        case FT_SINGLE:
            cpu_float_single_exp( _environment, value->realName, result->realName );
            break;
    }

    return result;

}
