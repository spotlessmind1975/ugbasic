/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
@keyword LOG

@english

The ''LOG'' instruction calculate the natural logarithm of the given ''number'',
that must be ''FLOAT''. This is a mathematical function that is the inverse 
of the natural exponential 
(with base e). In other words, the natural logarithm of a number ''x'' is the 
exponent to which Napier's number (e = 2.71828) must be raised to obtain ''x''.

This function can be used to solve differential equations, calculate integrals 
and approximate functions, for normalizing data and it is used in many physical 
and biological models.

@italian

L'istruzione ''LOG'' calcola il logaritmo naturale del ''numero'' dato, che deve
essere ''FLOAT''. Questa è una funzione matematica che è l'inverso dell'esponenziale 
naturale (con base e). In altre parole, il logaritmo naturale di un numero ''x'' è 
l'esponente a cui deve essere elevato il numero di Nepier (e = 2,71828) per ottenere ''x''.

Questa funzione può essere utilizzata per risolvere equazioni differenziali, calcolare 
integrali e funzioni approssimate, per normalizzare i dati ed è utilizzata in molti 
modelli fisici e biologici.

@syntax = LOG(number)

@example x = LOG(21)

</usermanual> */
Variable * fp_log( Environment * _environment, char * _value ) {

    Variable * value = variable_retrieve_or_define( _environment, _value, VT_FLOAT, 0 );
    Variable * result = variable_temporary( _environment, VT_FLOAT, "(log)");

    switch( result->precision ) {
        case FT_FAST:
            cpu_float_fast_log( _environment, value->realName, result->realName );
            break;
        case FT_SINGLE:
            cpu_float_single_log( _environment, value->realName, result->realName );
            break;
    }

    return result;

}
