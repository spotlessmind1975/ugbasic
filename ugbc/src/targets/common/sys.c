/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

/**
 * @brief Emit code for <strong>SYS / EXEC ...</strong> command
 * 
 * @param _environment Current calling environment
 * @param _color Color to use for the pen
 */
/* <usermanual>
@keyword SYS

@english
This command allows you to start the execution of a subroutine, written directly 
in machine language, starting from the indicated address. It must be noted that 
this jump is intended as a return: any assembly instruction that returns from 
execution will continue the execution of the program from the next ugBASIC line.

@italian
Questo comando permette di iniziare l'esecuzione di una subroutine, scritta 
direttamente in linguaggio macchina, a partire dall'indirizzo indicato. Bisogna 
fare attenzione che tale salto si intende con ritorno: una eventuale istruzione 
assembly che fa ritornare dall'esecuzione farà continuare l'esecuzione del 
programma dalla riga ugBASIC successiva.

@syntax SYS [address]

@example SYS #49142
@example SYS indirizzo

@usedInExample extern_example_01.bas

@seeAlso EXEC

@target all
</usermanual> */
/* <usermanual>
@keyword EXEC

@english
Alias for SYS.

@italian
Alias per SYS.

@usedInExample extern_example_01.bas

@seeAlso SYS

@target all
</usermanual> */
void sys( Environment * _environment, int _address ) {

    char address[MAX_TEMPORARY_STORAGE]; sprintf( address, "$%4.4x", _address );

    if ( _environment->parameters ) {
        for( int i=0; i<_environment->parameters; ++i ) {
            if ( _environment->parametersEach[i] ) {
                Variable * var = variable_retrieve( _environment, _environment->parametersEach[i] );
                cpu_set_asmio_indirect( _environment, _environment->parametersAsmioEach[i], var->realName );
            } else {
                cpu_set_asmio( _environment, _environment->parametersAsmioEach[i], _environment->parametersValueEach[i] );
            }
        }
    }

    cpu_call( _environment, address );

    if ( _environment->returns ) {
        for( int i=0; i<_environment->returns; ++i ) {
            if ( _environment->returnsEach[i] ) {
                Variable * var = variable_retrieve( _environment, _environment->returnsEach[i] );
                cpu_get_asmio_indirect( _environment, _environment->returnsAsmioEach[i], var->realName );
            }
        }
    }

}

void sys_var( Environment * _environment, char * _address ) {

    Variable  * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );

    if ( _environment->parameters ) {
        for( int i=0; i<_environment->parameters; ++i ) {
            if ( _environment->parametersEach[i] ) {
                Variable * var = variable_retrieve( _environment, _environment->parametersEach[i] );
                cpu_set_asmio_indirect( _environment, _environment->parametersAsmioEach[i], var->realName );
            } else {
                cpu_set_asmio( _environment, _environment->parametersAsmioEach[i], _environment->parametersValueEach[i] );
            }
        }
    }

    cpu_call_indirect( _environment, address->realName );

    if ( _environment->returns ) {
        for( int i=0; i<_environment->returns; ++i ) {
            if ( _environment->returnsEach[i] ) {
                Variable * var = variable_retrieve( _environment, _environment->returnsEach[i] );
                cpu_get_asmio_indirect( _environment, _environment->returnsAsmioEach[i], var->realName );
            }
        }
    }

}