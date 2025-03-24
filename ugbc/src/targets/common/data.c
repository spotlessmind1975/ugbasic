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
#include <math.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>DATA</strong> instruction (numeric values)
 * 
 * @param _environment Current calling environment
 * @param _value Numeric value to store
 */
 /* <usermanual>
@keyword DATA

@english

The ''DATA'' command is used to create a list of data that will be used 
in other parts of the program. It is like a container where values are 
stored that will then be "read" and used by other commands.

The ''DATA'' command is usually placed at the beginning of the program or in
a section dedicated to the definitions of data, but it is not mandatory.
The ''data1'', ''data2'', ... so on should be replaced witht he data you want to 
store inside the program. These can be numbers or text strings. To read the 
data contained in a ''DATA'' statement, you use the ''READ'' command. 
This command assigns the values contained in ''DATA'' to variables.

You can use multiple ''DATA'' statements to fill an array with a set of values.
Another usage is to create small tables of data, for example to represent 
menus or product lists. You can also store constants that are used frequently 
in the program.

The ''DATA'' values will be read from left to right, beginning with the first 
line containing a ''DATA'' statement. Each time a ''READ'' instruction is 
executed the saved ''DATA'' position of the last ''READ'' is advanced to the 
next value. Strings must be written in quotes, so characters 
like comma, space, colon, graphical ones or control characters has to be 
written inside double quotes like string constants. The ''RESTORE'' resets
the pointer of the current ''DATA'' position the program start so that 
next ''READ'' will read from the first ''DATA'' found from the beginning 
of the program.

The instruction ''DATA'' stores numeric data in an optimized way: so, if you enter a numeric
constant that can be represented by a single byte, it will be stored in the program
as a single byte. Floating point numbers are stored with default precision. 
Finally, strings are stored "as is". As a result, when you use the ''READ'' command, 
ugBASIC will implicitly perform the conversion if the same data type is not used,
and if it is posssible. It is possible to avoid this behavious by using the ''AS'' 
keyword, followed by the data type.

Separates the definition of data from its use, makes the code more readable 
and maintainable. You can change the data without having to change the 
logic of the program. Finally, the same data can be read multiple times 
in different parts of the program.

There is also a version of the syntax that allows you to load values from 
an external file. This syntax is currently limited to numeric data that must be
separated by a non-numeric separator.

@italian

Il comando ''DATA'' serve per creare un elenco di dati che saranno 
utilizzati in altre parti del programma. È come un contenitore in 
cui vengono memorizzati valori che saranno poi "letti" e utilizzati 
da altri comandi.

Il comando ''DATA'' è solitamente posizionato all'inizio del programma 
o in una sezione dedicata alle definizioni dei dati, ma non è obbligatorio.
''data1'', ''data2'', ... e così via devono essere sostituiti con i dati che si 
desidera memorizzare all'interno del programma. Possono essere numeri o 
stringhe di testo. Per leggere i dati contenuti in un'istruzione ''DATA'', 
si utilizza il comando ''READ''. Questo comando assegna i valori contenuti 
in ''DATA'' alle variabili.

È possibile utilizzare più istruzioni ''DATA'' per riempire un array con
un set di valori. Un altro utilizzo è quello di creare piccole tabelle di 
dati, ad esempio per rappresentare menu o elenchi di prodotti. È inoltre 
possibile memorizzare costanti che vengono utilizzate frequentemente nel 
programma.

I valori ''DATA'' verranno letti da sinistra a destra, iniziando dalla 
prima riga contenente un'istruzione ''DATA''. Ogni volta che viene eseguita 
un'istruzione ''READ'', la posizione ''DATA'' salvata dell'ultimo ''READ'' 
viene avanzata al valore successivo. Le stringhe devono essere scritte 
tra virgolette, quindi caratteri come virgola, spazio, due punti, 
caratteri grafici o caratteri di controllo devono essere scritti tra 
virgolette doppie come le costanti stringa. ''RESTORE'' reimposta il 
puntatore della posizione ''DATA'' corrente all'avvio del programma 
in modo che il successivo ''READ'' legga dal primo ''DATA'' trovato 
dall'inizio del programma.

L'istruzione ''DATA'' memorizza i dati numerici in modo ottimizzato: 
quindi, se si immette una costante numerica che può essere rappresentata 
da un singolo byte, verrà memorizzata nel programma come un singolo byte. 
I numeri in virgola mobile vengono memorizzati con precisione predefinita.
Infine, le stringhe vengono memorizzate "così come sono". Di conseguenza, 
quando si usa il comando ''READ'', ugBASIC eseguirà implicitamente la 
conversione se non viene usato lo stesso tipo di dati e se è possibile. 
È possibile evitare questo comportamento usando la parola chiave ''AS'', 
seguita dal tipo di dati.

Separa la definizione dei dati dal loro utilizzo, rende il codice più 
leggibile e gestibile. È possibile modificare i dati senza dover cambiare 
la logica del programma. Infine, gli stessi dati possono essere letti 
più volte in diverse parti del programma. 

E' disponibile anche una versione della sintassi che permette di caricare
i valori presenti in un file esterno. Questa sintassi, al momento, è 
limitata ai dati di tipo numerico che devono essere separati da un 
separatore non numerico.

@syntax DATA data1 [, data2 [, data3 ... ] ]
@syntaxDATA [AS data type] data1 [, data2 [, data3 ... ] ]
@syntaxDATA LOAD "filename" AS TEXT

@example DATA 10, 20, "test"
@example DATA AS INTEGER 10, 20, 30
@example DATA LOAD "datas.txt" AS TEXT

@usedInExample data_example_01.bas
@usedInExample data_example_02.bas
@usedInExample data_example_03.bas
@usedInExample data_example_05.bas

</usermanual> */
void data_numeric( Environment * _environment, int _value ) {

    VariableType type;

    if ( _environment->dataDataType ) {
        type = _environment->dataDataType;
    } else {
        type = variable_type_from_numeric_value( _environment, _value );
    }

    int bytes = VT_BITWIDTH( type ) >> 3;

    DataSegment * data;

    if ( _environment->lastDefinedLabel ) {
        if ( _environment->lastDefinedLabelIsNumeric ) {
            data = data_segment_define_or_retrieve_numeric( _environment, _environment->lastDefinedLabelNumeric );
        } else {
            data = data_segment_define_or_retrieve( _environment, _environment->lastDefinedLabel );
        }
    } else {
        data = data_segment_define_or_retrieve( _environment, "DATA" );
    }

    DataDataSegment * dataDataSegment = malloc( sizeof( DataDataSegment ) );
    memset( dataDataSegment, 0, sizeof( DataDataSegment ) );
    dataDataSegment->size = bytes;
    dataDataSegment->data = malloc( bytes );
    dataDataSegment->type = type;
#if defined(CPU_BIG_ENDIAN)
    char * value = (char *)&_value;
    for( int i=0; i<bytes; ++i ) {
        dataDataSegment->data[bytes-i-1] = value[i];
    }
#else
    memcpy( dataDataSegment->data, &_value, bytes );
#endif

    DataDataSegment * final = data->data;

    if ( final ) {
        while( final->next ) {
            final = final->next;
        }
        final->next = dataDataSegment;
    } else {
        data->data = dataDataSegment;
    }
    
    if (  _environment->dataDataType ) {
        data->type = _environment->dataDataType;
    }

}

/**
 * @brief Emit code for <strong>DATA</strong> instruction (float values)
 * 
 * @param _environment Current calling environment
 * @param _value Float value to store
 */
void data_floating( Environment * _environment, double _value ) {

    VariableType type = VT_FLOAT;

    int bytes = VT_FLOAT_BITWIDTH( _environment->floatType.precision ) >> 3;

    DataSegment * data;

    if ( _environment->lastDefinedLabel ) {
        if ( _environment->lastDefinedLabelIsNumeric ) {
            data = data_segment_define_or_retrieve_numeric( _environment, _environment->lastDefinedLabelNumeric );
        } else {
            data = data_segment_define_or_retrieve( _environment, _environment->lastDefinedLabel );
        }
    } else {
        data = data_segment_define_or_retrieve( _environment, "DATA" );
    }

    int result[32];
    cpu_float_single_from_double_to_int_array( _environment, _value, result );

    DataDataSegment * dataDataSegment = malloc( sizeof( DataDataSegment ) );
    memset( dataDataSegment, 0, sizeof( DataDataSegment ) );
    dataDataSegment->size = bytes;
    dataDataSegment->data = malloc( bytes );
    dataDataSegment->type = type;
    dataDataSegment->precision = _environment->floatType.precision;
    for( int i=0; i<bytes; ++i ) {
        dataDataSegment->data[i] = (char)(result[i] & 0xff );
    }

    DataDataSegment * final = data->data;

    if ( final ) {
        while( final->next ) {
            final = final->next;
        }
        final->next = dataDataSegment;
    } else {
        data->data = dataDataSegment;
    }
    
    if (  _environment->dataDataType ) {
        data->type = _environment->dataDataType;
    }

}

/**
 * @brief Emit code for <strong>DATA</strong> instruction (string values)
 * 
 * @param _environment Current calling environment
 * @param _value String value to store
 */
void data_string( Environment * _environment, char * _value ) {

    VariableType type = VT_STRING;

    int bytes;

    char * value = unescape_string( _environment, _value, 0, &bytes );

    DataSegment * data;

    if ( _environment->lastDefinedLabel ) {
        if ( _environment->lastDefinedLabelIsNumeric ) {
            data = data_segment_define_or_retrieve_numeric( _environment, _environment->lastDefinedLabelNumeric );
        } else {
            data = data_segment_define_or_retrieve( _environment, _environment->lastDefinedLabel );
        }
    } else {
        data = data_segment_define_or_retrieve( _environment, "DATA" );
    }

    DataDataSegment * dataDataSegment = malloc( sizeof( DataDataSegment ) );
    memset( dataDataSegment, 0, sizeof( DataDataSegment ) );
    dataDataSegment->size = bytes;
    dataDataSegment->data = malloc( bytes + 1 );
    memset( dataDataSegment->data, 0, bytes + 1 );
    dataDataSegment->type = type;
    memcpy( dataDataSegment->data, value, bytes );

    if (  _environment->dataDataType ) {
        data->type = _environment->dataDataType;
    }

    DataDataSegment * final = data->data;
    
    if ( final ) {
        while( final->next ) {
            final = final->next;
        }
        final->next = dataDataSegment;
    } else {
        data->data = dataDataSegment;
    }

}

void data_type( Environment * _environment ) {

    VariableType type;

    DataSegment * data;

    int os = VT_OPTIMAL_SHIFT( _environment->currentType->size );
    int bytes = 1 << os;

    if ( _environment->lastDefinedLabel ) {
        if ( _environment->lastDefinedLabelIsNumeric ) {
            data = data_segment_define_or_retrieve_numeric( _environment, _environment->lastDefinedLabelNumeric );
        } else {
            data = data_segment_define_or_retrieve( _environment, _environment->lastDefinedLabel );
        }
    } else {
        data = data_segment_define_or_retrieve( _environment, "DATA" );
    }

    DataDataSegment * dataDataSegment = malloc( sizeof( DataDataSegment ) );
    memset( dataDataSegment, 0, sizeof( DataDataSegment ) );
    dataDataSegment->size = bytes;
    dataDataSegment->data = malloc( bytes );
    memset( dataDataSegment->data, 0, bytes );
    dataDataSegment->type = VT_TYPE;
    Constant * current = _environment->currentFieldsValues;
    Field * currentField = _environment->currentType->first;
    int offset = 0;
    while( current ) {
        switch( VT_BITWIDTH( currentField->type ) ) {
            case 8:
                dataDataSegment->data[offset] = (unsigned char)current->value & 0xff;
                ++offset;
                break;
            case 16:
#if defined(CPU_BIG_ENDIAN)
                dataDataSegment->data[offset+1] = (unsigned char)current->value & 0xff;
                dataDataSegment->data[offset] = (unsigned char)((current->value>>8) & 0xff);
#else
                dataDataSegment->data[offset] = (unsigned char)current->value & 0xff;
                dataDataSegment->data[offset+1] = (unsigned char)((current->value>>8) & 0xff);
#endif
                offset+=2;
                break;
            case 32:
#if defined(CPU_BIG_ENDIAN)
                dataDataSegment->data[offset+3] = (unsigned char)current->value & 0xff;
                dataDataSegment->data[offset+2] = (unsigned char)((current->value>>8) & 0xff);
                dataDataSegment->data[offset+1] = (unsigned char)((current->value>>16) & 0xff);
                dataDataSegment->data[offset] = (unsigned char)((current->value>>24) & 0xff);
#else
                dataDataSegment->data[offset] = (unsigned char)current->value & 0xff;
                dataDataSegment->data[offset+1] = (unsigned char)((current->value>>8) & 0xff);
                dataDataSegment->data[offset+2] = (unsigned char)((current->value>>16) & 0xff);
                dataDataSegment->data[offset+3] = (unsigned char)((current->value>>24) & 0xff);
#endif
                offset+=4;
                break;
        }
        current = current->next;
        currentField = currentField->next;
    }

    DataDataSegment * final = data->data;

    if ( final ) {
        while( final->next ) {
            final = final->next;
        }
        final->next = dataDataSegment;
    } else {
        data->data = dataDataSegment;
    }
    
    data->type = VT_TYPE;

}
