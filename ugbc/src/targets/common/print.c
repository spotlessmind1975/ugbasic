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
@keyword PRINT

@english

The ''PRINT'' instruction displays information on the screen, starting from the current
cursor position. An item or a list of items can follow the command. If any item is omitted, 
a blank line is printed. The list of items can consist of any group of strings, variables or constants.
Each element in the list must be separated by either a semi-colon '';'' or a comma '',''.
A semi-colon prints the data immediately after the previous value, whereas a comma first
moves the cursor to the next ''TAB'' position on the screen.

Normally the cursor will be advanced downwards by a single line after each ''PRINT''
instruction. This can be suppressed by adding a separator after the print. As before, a semicolon
will preserve the cursor position after the operation, and a comma will place the
cursor to the next ''TAB'' stop before proceeding.

All data printed to the screen is formatted by using the specific formatter for numbers,
and "as is" for strings, while complex data will be printed out with an unique self descriptive string.
 For the numeric data, the numbers are always translated into decimal system. Nothing is written 
 if parameter is omitted. 

Because the ''PRINT'' instruction prints with mono-spaced characters, there is a  correlation between
the number of characters printed and the number of columns those characters occupy. This ensures 
that each character uses only one column. You can use the ''SPC'' keyword to print after
a specific number of spaces.

It is also possible to put the output to a specific location. The ''PRINT @'' command is used 
to place output at a specified place on the screen. For this purpose the screen is divided 
into a ''SCREEN COLUMNS'' x ''SCREEN ROWS'' grid, giving a certain amount of positions. 
The expression after the ''@'' can be a number, a variable or an arithmetic expression, as
long as the value is between ''0'' and ''((SCREEN COLUMNS*SCREEN ROWS)-1)''.

Finally, note that the supplied string to print may contain control characters (clear 
screen, move cursor, and so on), which will be interpreted by the ''PRINT'' command. 
Since some targets give meaning to these characters, it is possible to omit 
this behavior by using the RAW keyword. This keyword will turn off interpretation for the 
expression that follows it, and turn it back on for the next one.

@italian

L'istruzione ''PRINT'' visualizza le informazioni sullo schermo, a partire dalla posizione attuale del 
cursore. Un elemento o un elenco di elementi può seguire il comando. Se un elemento viene omesso, viene 
stampata una riga vuota. L'elenco di elementi può essere costituito da qualsiasi gruppo di stringhe, 
variabili o costanti. Ogni elemento dell'elenco deve essere separato da un punto e virgola '';'' o da una 
virgola '',''. Un punto e virgola stampa i dati immediatamente dopo il valore precedente, mentre una virgola 
sposta prima il cursore alla posizione ''TAB'' successiva sullo schermo.

Normalmente il cursore sarà portato verso il basso di una singola riga dopo ciascuna istruzione ''PRINT''. 
Questo può essere evitato aggiungendo un separatore dopo la stampa. Come prima, un punto e virgola manterrà 
la posizione del cursore dopo l'operazione e una virgola posizionerà il cursore al punto ''TAB'' successivo 
prima di procedere.

Tutti i dati stampati sullo schermo vengono formattati utilizzando il formattatore specifico per i numeri 
e "così come sono" per le stringhe, mentre i dati complessi verranno stampati con una stringa di descrizione 
univoca e autoeplicativa. Per i dati numerici, i numeri sono sempre tradotti nel sistema decimale. Non viene scritto nulla 
se il parametro viene omesso.

Poiché l'istruzione ''PRINT'' stampa con caratteri a spaziatura fissa, esiste una correlazione tra il 
numero di caratteri stampati e il numero di colonne occupate da tali caratteri. Ciò garantisce che ogni 
carattere utilizzi solo una colonna.

È anche possibile collocare l'output in una posizione specifica. Il comando ''PRINT @'' viene utilizzato 
per posizionare l'output in un punto specificato sullo schermo. A questo scopo lo schermo è diviso 
in una griglia ''SCREEN COLUMNS'' x ''SCREEN ROWS'', fornendo un certo numero di posizioni. 
L'espressione dopo ''@'' può essere un numero, una variabile o un'espressione aritmetica, purché il 
valore sia compreso tra ''0'' e ''((SCREEN COLUMNS*SCREEN ROWS)-1)''.

Infine, è da notare che la stringa fornita da stampare potrebbe presentare caratteri di controllo 
(di cancellazione schermo, di spostamento del cursore, e così via), che saranno interpretati 
dal comando ''PRINT''. Poiché alcuni target danno significato a questi caratteri, è 
possibile omettere questo comportamento usanto la parola chiave ''RAW''. Tale parola chiave 
disattiverà l'interpretazione per l'espressione che la segua, e la riattiverà alla 
successiva.

@syntax PRINT [[RAW] expr] [; [[RAW]expr] [; ...] ... ]
@syntax PRINT [[RAW] expr] [, [[RAW]expr] [, ...] ... ]
@syntax PRINT @expr, [, [[RAW]expr] [, ...] ... ]

@example PRINT "HELLO WORLD!"
@example PRINT RAW "RAW";"NOT RAW";RAW "RAW"
@example PRINT (a + b);" IS A SUM!";
@example PRINT @100, "HELLO WORLD!"

@usedInExample texts_print_01.bas
@usedInExample texts_print_02.bas
@usedInExample texts_print_04.bas

@target all
@verified
</usermanual> */
void print( Environment * _environment, char * _value, int _new_line, int _raw ) {

    MAKE_LABEL

    if ( _value ) {

        Variable * value = variable_retrieve_or_define( _environment, _value, VT_DSTRING, 0 );

        if ( value->type != VT_DSTRING && value->type != VT_STRING && value->type != VT_CHAR ) {
            switch( VT_BITWIDTH( value->type ) ) {
                case 32:
                case 16:
                case 8: {
                    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary for PRINT)");
                    Variable * size = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");
                    Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                    variable_store_string( _environment, tmp->name, "          " );

                    cpu_dswrite( _environment, tmp->realName );

                    cpu_dsdescriptor( _environment, tmp->realName, address->realName, size->realName );

                    cpu_number_to_string( _environment, value->realName, address->realName, size->realName, VT_BITWIDTH( value->type ), VT_SIGNED( value->type ) );

                    cpu_dsresize( _environment, tmp->realName, size->realName );

                    value = tmp;
                    
                    break;
                }
                case 1: {
                    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary for PRINT)");
                    Variable * size = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");
                    Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                    Variable * bcheck = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");
                    Variable * zero = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");
                    Variable * one = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");

                    cpu_store_8bit( _environment, zero->realName, '0' );
                    cpu_store_8bit( _environment, one->realName, '1' );

                    variable_store_string( _environment, tmp->name, " " );
                    cpu_dswrite( _environment, tmp->realName );
                    cpu_dsdescriptor( _environment, tmp->realName, address->realName, size->realName );

                    MAKE_LABEL

                    char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneLabel, "%sdone", label );

                    outline0(" ; printing bit..." );
                    cpu_bit_check( _environment, value->realName, value->bitPosition, bcheck->realName, 8 );
                    cpu_compare_and_branch_8bit_const( _environment, bcheck->realName, 0, label, 1 );
                    cpu_move_8bit_indirect( _environment, one->realName, address->realName );
                    cpu_jump( _environment, doneLabel );
                    cpu_label( _environment, label );
                    cpu_move_8bit_indirect( _environment, zero->realName, address->realName );
                    cpu_label( _environment, doneLabel );

                    value = tmp;
                    
                    break;
                }
                case 0:
                    switch( value->type ) {
                        case VT_FLOAT: {
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(temporary for PRINT)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(temporary for PRINT)");
                            Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");

                            variable_store_string( _environment, tmp->name, "                              " );

                            cpu_dswrite( _environment, tmp->realName );

                            cpu_dsdescriptor( _environment, tmp->realName, address->realName, size->realName );

                            switch( value->precision ) {
                                case FT_FAST:
                                    cpu_float_fast_to_string( _environment, value->realName, address->realName, size->realName );
                                    break;
                                case FT_SINGLE:
                                    cpu_float_single_to_string( _environment, value->realName, address->realName, size->realName );
                                    break;
                            }

                            cpu_dsresize( _environment, tmp->realName, size->realName );

                            value = tmp;

                            break;
                        }
                        case VT_IMAGE: {
                            char bufferName[MAX_TEMPORARY_STORAGE];
                            sprintf(bufferName, "@image(%s)", value->name);
                            Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                            variable_store_string( _environment, tmp->name, bufferName );

                            value->usedImage = 1;
                            
                            value = tmp;

                            break;
                        }
                        case VT_IMAGES: {
                            char bufferName[MAX_TEMPORARY_STORAGE];
                            sprintf(bufferName, "@images(%s)", value->name);
                            Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                            variable_store_string( _environment, tmp->name, bufferName );

                            value->usedImage = 1;

                            value = tmp;

                            break;
                        }
                        case VT_DOJOKA: {
                            Variable * dojokaHandle = variable_temporary( _environment, VT_DWORD, "(dojoka)");
                            cpu_mem_move_direct_size( _environment, value->realName, dojokaHandle->realName, 4 );
                            print( _environment, variable_hex( _environment, dojokaHandle->name )->name, 0, _raw );
                            value = NULL;

                            break;
                        }
                        case VT_BUFFER: {
                            char bufferName[MAX_TEMPORARY_STORAGE];
                            sprintf(bufferName, "@buffer(%s)", value->name);
                            Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                            variable_store_string( _environment, tmp->name, bufferName );

                            value = tmp;

                            break;
                        }
                        case VT_SPRITE: {
                            char bufferName[MAX_TEMPORARY_STORAGE];
                            sprintf(bufferName, "@sprite(%s)", value->name);
                            Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                            variable_store_string( _environment, tmp->name, bufferName );

                            value = tmp;

                            break;
                        }
                        case VT_MSPRITE: {
                            char bufferName[MAX_TEMPORARY_STORAGE];
                            sprintf(bufferName, "@msprite(%s)", value->name);
                            Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                            variable_store_string( _environment, tmp->name, bufferName );

                            value = tmp;

                            break;
                        }
                        case VT_TILE: {
                            char bufferName[MAX_TEMPORARY_STORAGE];
                            sprintf(bufferName, "@tile(%s)", value->name);
                            Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                            variable_store_string( _environment, tmp->name, bufferName );

                            value = tmp;

                            break;
                        }
                        case VT_TILESET: {
                            char bufferName[MAX_TEMPORARY_STORAGE];
                            sprintf(bufferName, "@tileset(%s)", value->name);
                            Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                            variable_store_string( _environment, tmp->name, bufferName );

                            value->usedImage = 1;

                            value = tmp;

                            break;
                        }
                        case VT_TILEMAP: {
                            char bufferName[MAX_TEMPORARY_STORAGE];
                            sprintf(bufferName, "@tilemap(%s)", value->name);
                            Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                            variable_store_string( _environment, tmp->name, bufferName );

                            value->usedImage = 1;

                            value = tmp;

                            break;
                        }
                        case VT_TILES: {
                            char bufferName[MAX_TEMPORARY_STORAGE];
                            sprintf(bufferName, "@tiles(%s)", value->name);
                            Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                            variable_store_string( _environment, tmp->name, bufferName );

                            value = tmp;

                            break;
                        }
                        default:
                            CRITICAL_PRINT_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type]);
                    }
            }
            if ( value ) {
                text_text( _environment, value->name, _raw );
                cpu_dsfree( _environment, value->realName );
                cpu_store_8bit( _environment, value->realName, 0 );
            }
        } else {
            text_text( _environment, value->name, _raw );
        }

    }

    if ( _new_line ) {
        text_newline( _environment );
    }

}

/**
 * @brief Emit code for print a single TAB
 * 
 * @param _environment Current calling environment
 * @param _new_line 1 if a new line must be added at the end
 */
void print_tab( Environment * _environment, int _new_line ) {

    text_tab( _environment );

    if ( _new_line ) {
        text_newline( _environment );
    }

}

/**
 * @brief Emit code for print a single question mark
 * 
 * @param _environment Current calling environment
 */
void print_question_mark( Environment * _environment ) {
    text_question_mark( _environment );
}

/**
 * @brief Emit code for print a single newline
 * 
 * @param _environment Current calling environment
 */
void print_newline( Environment * _environment ) {
    text_newline( _environment );
}

