#ifndef __SIDRELOC__
#define __SIDRELOC__

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

int sidreloc_set_page( int _page );
int sidreloc_set_page0( int _first, int _last );
int sidreloc_set_nopage0( );
int sidreloc_set_reloc( int _start, int _end );
int sidreloc_set_tolerance( int _tolerance );
int sidreloc_set_strict( );
int sidreloc_set_force( );
int sidreloc_set_verbosity( int _verbose );
int sidreloc_set_frames( int _frames );
int sidreloc_set_init_cycles( int _cycles );
int sidreloc_set_play_cycles( int _cycles );
int sidreloc_set_nmi_cycles( int _cycles );
int sidreloc_set_nmi_calls( int _cycles );
int sidreloc_set_input_data( unsigned char * _data, int _size );
int sidreloc_set_output_data( unsigned char * _data );

char * sidreloc_get_lasterror_string( );

int sidreloc_main();

 #endif