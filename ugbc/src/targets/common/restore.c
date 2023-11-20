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

        Variable * variable = variable_retrieve( _environment, _label );
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


