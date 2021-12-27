#ifndef __UGBASICTESTER__
#define __UGBASICTESTER__

/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#include "../src/ugbc.h"

/****************************************************************************
 * DECLARATIONS AND DEFINITIONS SECTION 
 ****************************************************************************/

void test_cpu( );
void test_variables( );
void test_conditionals( );
void test_loops( );
void test_ons( );
void test_controls( );
void test_examples( );
void test_print( );

#if defined( __c64__ )
    #include "tester_c64.h"
#elif defined( __plus4__ )
    #include "tester_plus4.h"
#elif defined( __atari__ )
    #include "tester_atari.h"
#elif defined( __atarixl__ )
    #include "tester_atarixl.h"
#elif defined( __zx__ )
    #include "tester_zx.h"
#elif defined( __d32__ )
    #include "tester_d32.h"
#elif defined( __d64__ )
    #include "tester_d64.h"
#elif defined( __pc128op__ )
    #include "tester_pc128op.h"
#elif defined( __mo5__ )
    #include "tester_mo5.h"
#elif defined( __vic20__ )
    #include "tester_vic20.h"
#elif defined( __msx1__ )
    #include "tester_msx1.h"
#endif

#endif