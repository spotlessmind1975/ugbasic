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
The ''PRINT'' instruction can be used to print on the screen, starting from 
the current cursor position, and they may include the characters in 
any group of variables or constants. ''PRINT'' statements can occupy 
their own lines, but if more than one element to be printed is written 
as a single line of your program, each element must be separated from the
next by either a semi-colon character ('';'') or a comma (''.''). 

An element to be printed can be a string, a variable or a constant, 
and is placed inside a pair of quotation marks (''"''). A semi-colon 
('';'') is used to print elements immediately after one another while
a comma ('','') moves the cursor to the next "tab" position on the screen.

A tab is an automatic marker that sets up a location for printing, 
and is often used to lay out columns of figures, or to make indentations 
in text. Normally, the cursor is advanced downwards by one line after every
''PRINT'' command, but by using the semi-colon or comma, the rule can be changed.

@italian
L'istruzione ''PRINT'' può essere utilizzata per stampare sullo schermo, 
a partire dalla posizione corrente del cursore, e si possono includere caratteri 
in qualsiasi gruppo di variabili o costanti. Le istruzioni ''PRINT'' possono occupare
righe separate, ma se si vuore che più di un elemento da stampare sia stampato
come una singola riga, ogni elemento dovrà essere separato dal successivo da un 
punto e virgola (''; '') oppure da una virgola (' '.' ').

Un elemento da stampare può essere una stringa, una variabile o una costante e 
viene inserito tra virgolette (''"''). Il punto e virgola ('';'') viene utilizzato
per stampare elementi immediatamente uno dopo l'altro mentre una virgola ('','') 
sposta il cursore alla posizione di "tabulazione" successiva sullo schermo.

Una tabulazione è un indicatore automatico che imposta una posizione per la stampa
e viene spesso utilizzato per disporre colonne di cifre o per creare rientri nel 
testo. Normalmente, il cursore viene fatto avanzare verso il basso di una riga 
dopo ogni comando ''PRINT'', ma utilizzando il punto e virgola o la virgola,
la regola può essere modificata.

@syntax PRINT [expression]{;|,[expression]|;[expression]} ...

@example PRINT "HELLO WORLD!"
@example PRINT (A + B);" IS A SUM!";

@usedInExample texts_print_01.bas
@usedInExample texts_print_02.bas

@target all
</usermanual> */
void print( Environment * _environment, char * _value, int _new_line ) {

    MAKE_LABEL

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
            case 0:
                switch( value->type ) {
                    case VT_IMAGE: {
                        char bufferName[MAX_TEMPORARY_STORAGE];
                        sprintf(bufferName, "@image(%s)", value->name);
                        Variable * tmp = variable_temporary( _environment, VT_DSTRING, "(temporary for PRINT)");
                        variable_store_string( _environment, tmp->name, bufferName );

                        value = tmp;

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
                    case VT_MOB: {
                        char bufferName[MAX_TEMPORARY_STORAGE];
                        sprintf(bufferName, "@mob(%s)", value->name);
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
        text_text( _environment, value->name );
        cpu_dsfree( _environment, value->realName );
    } else {
        text_text( _environment, value->name );
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

