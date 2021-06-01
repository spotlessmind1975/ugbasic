#ifndef __UGBASICTESTER_ZX__
#define __UGBASICTESTER_ZX__

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

#include "../src/ugbc.h"

/****************************************************************************
 * DECLARATIONS AND DEFINITIONS SECTION 
 ****************************************************************************/

typedef struct _InternalMachineState {

    unsigned int a;
    
    unsigned int b;
    
    unsigned int c;
    
    unsigned int d;
    
    unsigned int e;
    
    unsigned int f;

    unsigned int h;

    unsigned int l;

    unsigned int working[1024];

    unsigned int temporary[1024];

    struct {
        unsigned int size;

        unsigned int low;

        unsigned int high;

        unsigned int status;

    } descriptors[255];

    unsigned int xusing;

    unsigned int working_base_address;
    
    unsigned int temporary_base_address;

} InternalMachineState;

typedef struct _DebugInspection {

    char *      name;
    int         address;
    int         size;
    char *      memory;
} DebugInspection;

typedef struct _Debug {
    int                 inspections_count;
    DebugInspection     inspections[1024];
} Debug;

typedef struct _TestEnvironment {
    Environment                 environment;
    InternalMachineState        state;
    Variable                *   trackedVariables[128];
    Debug                       debug;
} TestEnvironment;

void create_test( char *_name, void (*_payload)(TestEnvironment *), int (*_tester)(TestEnvironment *) );
void stop_test( Environment * _environment );

#endif