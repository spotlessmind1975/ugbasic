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
@keyword RESTORE

@english

The ''RESTORE'' command is used to reset the data read pointer to the beginning 
of a list of ''DATA''. Imagine having a cassette tape with numbers on it, and 
you want to read those numbers one at a time. When you use ''RESTORE'', it's as 
if you're rewinding the tape to the beginning, ready to read all the numbers again.

When the program encounters this command, the data read pointer is automatically 
reset to the beginning of the first data list you defined. If you give a ''parameter'',
you can set the pointer to the label given.

The ''RESTORE'' command is especially useful when you want to reuse a list of data.
If you need to read the same data multiple times in your program, you can use 
''RESTORE'' to reset the pointer to the beginning of the list without having to
retype it. If you want to read only part of the data, you can use ''RESTORE'' to 
skip parts of the list and start reading from a specific point. If you want to 
create loops that read the data, by combining ''RESTORE'' with other commands 
such as ''READ'' and ''DATA'', you can create loops that repeatedly read 
the same data.

@italian

Il comando ''RESTORE'' viene utilizzato per reimpostare il puntatore di lettura 
dei dati all'inizio di un elenco di ''DATA''. Immagina di avere una cassetta con dei 
numeri e di voler leggere quei numeri uno alla volta. Quando utilizzi ''RESTORE'', 
è come se stessi riavvolgendo il nastro all'inizio, pronto per leggere di nuovo 
tutti i numeri.

Quando il programma incontra questo comando, il puntatore di lettura dei dati viene 
automaticamente reimpostato all'inizio del primo elenco di dati che hai definito. 
Se fornisci un ''label'', puoi impostare il puntatore all'etichetta specificata.

Il comando ''RESTORE'' è particolarmente utile quando vuoi riutilizzare un 
elenco di dati. Se hai bisogno di leggere gli stessi dati più volte nel tuo 
programma, puoi utilizzare ''RESTORE'' per reimpostare il puntatore all'inizio 
dell'elenco senza doverlo digitare di nuovo. Se vuoi leggere solo una parte dei dati, 
puoi utilizzare ''RESTORE'' per saltare parti dell'elenco e iniziare la lettura da un
punto specifico. Se vuoi creare loop che leggono i dati, combinando ''RESTORE'' con altri 
comandi come ''READ'' e ''DATA'', puoi creare loop che leggono ripetutamente gli stessi dati.

@syntax RESTORE label

@example RESTORE inizio

@usedInExample data_example_03.bas

@seeAlso READ
@seeAlso DATA

</usermanual> */

void restore_label( Environment * _environment, char * _label ) {

    if ( !_label || label_exists_named( _environment, _label ) ) {

        DataSegment * data;

        if ( _label ) {
            data = data_segment_define_or_retrieve( _environment, _label );
        } else {
            data = data_segment_define_or_retrieve( _environment, "DATA" );
        }

        if ( !data ) {
            CRITICAL_RESTORE_WITHOUT_DATA( _label );
        }

        Variable * dataptr = variable_retrieve( _environment, "DATAPTR" );

        cpu_addressof_16bit( _environment, data->realName, dataptr->realName );

        restore_label_unsafe( _environment, _label );

    } else {

        MAKE_LABEL

        char searchDataSegmentLabel[MAX_TEMPORARY_STORAGE]; sprintf( searchDataSegmentLabel, "%ssearch", label );
        char doneDataSegmentLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneDataSegmentLabel, "%sdone", label );

        _environment->restoreDynamic = 1;

        Variable * variable = variable_retrieve_or_define( _environment, _label, VT_WORD, 0 );
        Variable * dataptr = variable_retrieve( _environment, "DATAPTR" );
        Variable * lineNumber = variable_temporary( _environment, VT_WORD, "(line number)");
        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)");

        if ( VT_BITWIDTH( variable->type ) > 1 ) {

            cpu_addressof_16bit( _environment, "DATASEGMENTNUMERIC", dataptr->realName );

            cpu_label( _environment, searchDataSegmentLabel );

                cpu_move_16bit_indirect2( _environment, dataptr->realName, lineNumber->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_move_16bit_indirect2( _environment, dataptr->realName, address->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_compare_and_branch_16bit( _environment, lineNumber->realName, variable->realName, doneDataSegmentLabel, 1 );
                cpu_compare_and_branch_16bit_const( _environment, lineNumber->realName, 0xffff, doneDataSegmentLabel, 1 );

            cpu_jump( _environment, searchDataSegmentLabel );

            cpu_label( _environment, doneDataSegmentLabel );
            
            variable_move( _environment, address->name, dataptr->name );

        } else {
            CRITICAL_RESTORE_WITH_UNSUPPORTED_DATA_TYPE( _label );
        }
        
        restore_label_unsafe( _environment, NULL );

    }
    
}


