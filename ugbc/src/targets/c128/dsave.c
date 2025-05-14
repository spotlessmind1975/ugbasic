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
#include "../../libs/msc1.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>DLOAD(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 */
 /* <usermanual>
@keyword DSAVE

@english
Dynamically (at run-time) save a file to a mass storage. The DSAVE command 
allows you to (dynamically) save a file to a mass device. The syntax allows 
you to save a specific file (''filename'') starting from a specific ''offset'' 
within the file, from a specific ''address'' in memory for a certain 
number of ''bytes''. Note that the behavior of this instruction strictly 
depends on the target where it is executed. It follows that not all options 
are necessarily available on every target.

@italian
Il comando DLOAD permette di salvare (dinamicamente) un file verso una periferica
di massa. La sintassi permette di salvare un file specifico (''filename'') a 
partire da uno specifico ''offset'' all'interno del file, da uno specifico 
indirizzo (''address'') in memoria per un certo numero di ''bytes''.
Da notare che il comportamento di questa istruzione dipende strettamente 
dal target dove viene eseguito. Ne consegue che non è detto che tutte 
le opzioni siano disponibili.

@syntax DSAVE filename [TO offset] [FROM address] [SIZE size]

@example DSAVE "test" FROM finalAddress SIZE 16

@target c128

@seeAlso DSAVE ERROR

</usermanual> */
/* <usermanual>
@keyword DSAVE ERROR

@english

The ''DSAVE ERROR'' function lets you know whether the last 
''DSAVE'' instruction returned an error or not.

@italian

La funzione ''DSAVE ERROR'' consente di sapere se l'ultima istruzione 
''DSAVE'' ha dato errore o meno.

@syntax = DSAVE ERROR

@target c128

@seeAlso DSAVE

</usermanual> */
void dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    if ( _environment->emptyProcedure ) {
        return;
    }
    
    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "DLOAD");
    }

    if ( _environment->sandbox ) {
        CRITICAL_SANDBOX_ENFORCED( "DLOAD");
    }

    if ( ! _address ) {
        CRITICAL_DSAVE_MISSING_ADDRESS( _filename );
    }

    if ( ! _size ) {
        CRITICAL_DSAVE_MISSING_SIZE( _filename );
    }

    c128_dsave( _environment, _filename, _offset, _address, _size );

}
