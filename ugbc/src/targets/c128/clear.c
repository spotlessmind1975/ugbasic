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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/* <usermanual>
@keyword CLEAR

@english

The ''CLEAR'' command serves two purposes: when ''CLEAR'' is executed, all numeric 
variables are initialized to zero and all strings are set to the empty string (""). 
This is especially useful at the beginning of a program to ensure that there are 
no residual values from previous executions. It can be used to resize (statically)
allocated memory for dynamic strings. This may be necessary to avoid "out of memory" 
errors when working with strings.

@italian

Il comando ''CLEAR'' ha due scopi: quando ''CLEAR'' viene eseguito, tutte le 
variabili numeriche vengono inizializzate a zero e tutte le stringhe vengono 
impostate sulla stringa vuota (""). Ciò è particolarmente utile all'inizio 
di un programma per garantire che non vi siano valori residui dalle esecuzioni 
precedenti. Può essere utilizzato per ridimensionare (staticamente) la memoria 
allocata per le stringhe dinamiche. Ciò potrebbe essere necessario per evitare errori 
di "memoria insufficiente" quando si lavora con le stringhe.

@syntax CLEAR size

@example CLEAR 2048

@alias CLR
</usermanual> */

/* <usermanual>
@keyword CLR

@syntax CLR size

@example CLR 2048

@alias CLEAR
</usermanual> */
void clear( Environment * _environment ) {

    cpu_call( _environment, "VARINITCLEAR" );

}
