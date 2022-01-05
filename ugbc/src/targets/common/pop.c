/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

/**
 * @brief Emit ASM code for <b>POP</b>
 * 
 * This function can be used to issue a code equivalent to removing
 * caller address for a GOSUB.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword POP

@english
Remove the caller address from ''GOSUB'' call. So you can do a ''GOTO''
instead of ''RETURN''.

@italian
Rimuove l'indirizzo chiamante stoccato da ''GOSUB''. Quindi sarà
possibile usare un ''GOTO'' invece di un ''RETURN''.

@syntax POP

@example POP
@usedInExample control_popping_01.bas

@target all

@seeAlso RETURN
@seeAlso GOSUB
</usermanual> */
void pop( Environment * _environment ) {

    cpu_pop( _environment );

}