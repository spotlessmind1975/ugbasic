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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/


/* <usermanual>
@keyword CSET

@english

The ''CSET'' command switches with ''value'' between the two character sets 
of the VIC-II: uppercase graphics characters (0) and uppercase/lowercase 
(CSET 1). You can also use this to switch to graphics mode without clearing 
the graphics memory (see ''HIRES''), for this you use CSET 2. 

@italian

Il comando ''CSET'' commuta con ''value'' tra i due set di caratteri
del VIC-II: caratteri grafici maiuscoli (0) e maiuscolo/minuscolo
(CSET 1). È possibile utilizzarlo anche per passare alla modalità grafica 
senza cancellare la memoria grafica (vedere ''HIRES''), per questo si 
utilizza CSET 2.

@syntax CSET value

@example CSET 1

@target c64
@target c64reu
@target c128

</usermanual> */




void cset( Environment * _environment, char * _value ) {

    MAKE_LABEL

    Variable * value = variable_retrieve_or_define( _environment, _value, VT_BYTE, 0 );

    char l1Label[MAX_TEMPORARY_STORAGE]; sprintf( l1Label, "%sl1", label );
    char l2Label[MAX_TEMPORARY_STORAGE]; sprintf( l2Label, "%sl2", label );
    char l3Label[MAX_TEMPORARY_STORAGE]; sprintf( l3Label, "%sl3", label );

    cpu_compare_and_branch_8bit_const( _environment, value->realName, 1, l1Label, 1 );
    cpu_compare_and_branch_8bit_const( _environment, value->realName, 2, l2Label, 1 );
    cpu_compare_and_branch_8bit_const( _environment, value->realName, 3, l3Label, 1 );
    cpu_jump( _environment, label );

    cpu_label( _environment, l1Label );
    if ( _environment->fontConfig.schema || _environment->descriptors ) {
        charset_uppercase( _environment );
    } else {
        charset_lowercase( _environment );
    }
    cpu_jump( _environment, label );

    cpu_label( _environment, l2Label );
    if ( _environment->fontConfig.schema || _environment->descriptors ) {
        charset_lowercase( _environment );
    } else {
        charset_uppercase( _environment );
    }
    cpu_jump( _environment, label );

    cpu_label( _environment, l3Label );
    hires( _environment, NULL, NULL );
    cpu_jump( _environment, label );

    cpu_label( _environment, label );

}
