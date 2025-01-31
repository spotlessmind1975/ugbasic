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

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Emit code for <strong>PRINT...</strong> instruction
 * 
 * @param _environment Current calling environment
 * @param _value Value to print
 * @param _new_line 1 if a new line must be added at the end
 */
/* <usermanual>
@keyword PRINT BUFFER

@english

This is a specific variant of ''PRINT'' that can be used to print large amount of text.
The ''PRINT BUFFER'' instruction does not have the limits of ''PRINT'' strings,
and is able to print any file that have been loaded. An item or a list of items 
can follow the command. The list of items can consist of any group of buffers.
Each element in the list must be separated by either a semi-colon '';'' or a comma '',''.
A semi-colon prints the data immediately after the previous value, whereas a comma first
moves the cursor to the next ''TAB'' position on the screen.

Normally the cursor will be advanced downwards by a single line after each ''PRINT BUFFER''
instruction. This can be suppressed by adding a separator after the print. As before, a semicolon
will preserve the cursor position after the operation, and a comma will place the
cursor to the next ''TAB'' stop before proceeding.

Finally, it is possible to omit the native conversion of the buffer storage system, if you want 
to print "as is". In that case you need to use the ''RAW'' keyword.

@italian

Questa è una variante specifica di ''PRINT'' che può essere utilizzata per stampare grandi 
quantità di testo. L'istruzione ''PRINT BUFFER'' non ha i limiti delle stringhe ''PRINT'', 
ed è in grado di stampare qualsiasi file che sono stati caricati. Un elemento o un elenco di 
elementi può seguire il comando. L'elenco di elementi può essere costituito da qualsiasi 
gruppo di buffer. Ogni elemento nell'elenco deve essere separato da un punto e virgola '';''
o da una virgola '',''. Un punto e virgola stampa i dati immediatamente dopo il valore 
precedente, mentre una virgola sposta prima il cursore alla posizione ''TAB'' successiva 
sullo schermo.

Normalmente il cursore verrà avanzato verso il basso di una singola riga dopo ciascuna 
istruzione ''PRINT BUFFER''. Questo può essere eliminato aggiungendo un separatore dopo 
la stampa. Come prima, un punto e virgola manterrà la posizione del cursore dopo l'operazione 
e una virgola posizionerà il cursore al successivo punto "TAB" prima di procedere.

Infine, è possibile omettere la conversione nativa del sistema di stoccaggio del buffer, 
laddove si voglia stampare "as is". In tal caso è necessario utilizzare la parola chiave ''RAW''.

@syntax PRINT BUFFER buf1 [; [buf2] [; ...] ... ]
@syntax PRINT BUFFER RAW buf1 [; [buf2] [; ...] ... ]

@example PRINT BUFFER description
@example PRINT BUFFER RAW descriptionRaw

@usedInExample buffers_print_01.bas
@usedInExample contrib_ascii.bas
@usedInExample contrib_ascii2.bas

@target all
@verified

@keyword PRINT BUFFER

@english


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
void print_buffer( Environment * _environment, char * _value, int _new_line, int _printable ) {

    MAKE_LABEL

    const int bufferSizeSegment = 32;

    Variable * value = variable_retrieve( _environment, _value );
    Variable * dstring = variable_temporary( _environment, VT_DSTRING, "(temporary buffer)" );
    Variable * targetAddress = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );
    Variable * sourceAddress = variable_temporary( _environment, VT_ADDRESS, "(address)" );
   
    char printBufferLabel[MAX_TEMPORARY_STORAGE]; sprintf( printBufferLabel, "%sloop", label );
    char printBufferRestLabel[MAX_TEMPORARY_STORAGE]; sprintf( printBufferRestLabel, "%srest", label );

    if ( value->type != VT_BUFFER ) {
        CRITICAL_PRINT_BUFFER_ON_A_NOT_BUFFER( _value );
    }

    value->printable = _printable;

    // char * string = malloc( value->size + 1 );
    // memset( string, 0, value->size );
    // memcpy( string, value->valueBuffer, value->size );
    
    Variable * bufferSize = variable_temporary( _environment, VT_WORD, "(bufferSize)" );
    Variable * restSize = variable_temporary( _environment, VT_BYTE, "(bufferSize)" );

    if ( value->residentAssigned ) {

        char alreadyLoadedLabel[MAX_TEMPORARY_STORAGE];
        sprintf(alreadyLoadedLabel, "%salready", label );

        char bankWindowId[MAX_TEMPORARY_STORAGE];
        sprintf( bankWindowId, "BANKWINDOWID%2.2x", value->residentAssigned );

        char bankWindowName[MAX_TEMPORARY_STORAGE];
        sprintf( bankWindowName, "BANKWINDOW%2.2x", value->residentAssigned );

        cpu_compare_and_branch_16bit_const( _environment, bankWindowId, value->variableUniqueId, alreadyLoadedLabel, 1 );
        if ( value->uncompressedSize ) {
            bank_uncompress_semi_var( _environment, value->bankAssigned, value->absoluteAddress, bankWindowName );
            variable_store( _environment, bufferSize->name, value->uncompressedSize );
        } else {
            bank_read_semi_var( _environment, value->bankAssigned, value->absoluteAddress, bankWindowName, value->size );
            variable_store( _environment, bufferSize->name, value->size );
        }
        cpu_store_16bit(_environment, bankWindowId, value->variableUniqueId );
        cpu_label( _environment, alreadyLoadedLabel );
        cpu_addressof_16bit( _environment, bankWindowName, sourceAddress->realName );
    } else {
        cpu_addressof_16bit( _environment, value->realName, sourceAddress->realName );
        variable_store( _environment, bufferSize->name, value->size );
    }

    int offset = 0;

    cpu_dsalloc_size( _environment, bufferSizeSegment, dstring->realName );
    cpu_dsdescriptor( _environment, dstring->realName, targetAddress->realName, size->realName );

    cpu_label( _environment, printBufferLabel );

    Variable * compare = variable_greater_than_const( _environment, bufferSize->name, bufferSizeSegment, 1 );
    cpu_compare_and_branch_8bit_const( _environment, compare->realName, 0, printBufferRestLabel, 1 );

    cpu_mem_move_size( _environment, sourceAddress->realName, targetAddress->realName, bufferSizeSegment );
    cpu_math_add_16bit_const( _environment, sourceAddress->realName, bufferSizeSegment, sourceAddress->realName );
    cpu_math_add_16bit_const( _environment, bufferSize->realName, -bufferSizeSegment, bufferSize->realName );
    text_text( _environment, dstring->name, 0 );

    cpu_jump( _environment, printBufferLabel );

    cpu_label( _environment, printBufferRestLabel );

    variable_move( _environment, bufferSize->name, restSize->name );

    cpu_dsfree( _environment, dstring->realName );
    cpu_dsalloc( _environment, restSize->realName, dstring->realName );
    cpu_dsdescriptor( _environment, dstring->realName, targetAddress->realName, size->realName );
    cpu_mem_move( _environment, sourceAddress->realName, targetAddress->realName, restSize->realName );
    text_text( _environment, dstring->name, 0 );
    cpu_dsfree( _environment, dstring->realName );

    if ( _new_line ) {
        text_newline( _environment );
    }

}
