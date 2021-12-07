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

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Emit code for <strong>PRINT...</strong> instruction
 * 
 * @param _environment Current calling environment
 * @param _value Value to print
 * @param _new_line 1 if a new line must be added at the end
 */
/* <usermanual>
@keyword PRINT

@english
A specific variant of ''PRINT'' can be used to print large amount of text.
The ''PRINT BUFFER'' instruction does not have the limits of ''PRINT'' strings,
and is able to print any file that have been loaded.

@italian
Esiste anche una specifica variante di ''PRINT'' , che può essere utilizzata per
stampare un grande ammontare di testo. L'istruzione ''PRINT BUFFER'' non ha i limiti
delle stringhe con il ''PRINT'', e quindi è in grado di stampare qualsiasi file sia stato
caricato.

@syntax PRINT BUFFER [expression]{;|,[expression]|;[expression]} ...

@example file := load("example.txt") 
@example PRINT BUFFER file 

@usedInExample buffers_print_01.bas

@target all
</usermanual> */
void print_buffer( Environment * _environment, char * _value, int _new_line ) {

    MAKE_LABEL

    Variable * value = variable_retrieve( _environment, _value );
    Variable * dstring = variable_temporary( _environment, VT_DSTRING, "(temporary buffer)" );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );
    
    if ( value->type != VT_BUFFER ) {
        CRITICAL_PRINT_BUFFER_ON_A_NOT_BUFFER( _value );
    }

    value->printable = 1;

    char sourceAddress[MAX_TEMPORARY_STORAGE]; 

    char * string = malloc( value->size + 1 );
    memset( string, 0, value->size );
    memcpy( string, value->valueBuffer, value->size );
    
    int bufferSize = strlen( string );
    int offset = 0;

    if ( bufferSize > 127 ) {

        cpu_dsalloc_size( _environment, 127, dstring->realName );
        cpu_dsdescriptor( _environment, dstring->realName, address->realName, size->realName );

        while( bufferSize > 127 ) {

            sprintf( sourceAddress, "(%s+%d)", value->realName, offset );
            cpu_mem_move_direct_indirect_size( _environment, sourceAddress, address->realName, 127 );
            text_text( _environment, dstring->name );

            bufferSize -= 127;
            offset += 127;
        }

        cpu_dsfree( _environment, dstring->realName );

    }

    cpu_dsalloc_size( _environment, bufferSize, dstring->realName );
    cpu_dsdescriptor( _environment, dstring->realName, address->realName, size->realName );

    sprintf( sourceAddress, "(%s+%d)", value->realName, offset );
    cpu_mem_move_direct_indirect_size( _environment, sourceAddress, address->realName, bufferSize );

    text_text( _environment, dstring->name );

    if ( _new_line ) {
        text_newline( _environment );
    }

}
