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

/**
 * @brief Emit code for <strong>READ END</strong> function
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword READ END

@english

The ''READ END'' function allows you to know if you have reached the last value
to read with the ''READ'' command. If the function returns true, this means that 
the next ''READ'' command will ignore the read.

@italian

La funzione ''READ END'' permette di sapere se se è arrivato all'ultimo valore da 
leggere con il comando ''READ''. Se la funzione restituisce true, questo vuol dire 
che il prossimo comando ''READ'' ignorerà la lettura.

@syntax = READ END

@example IF READ END THEN
@example    RESTORE
@example ENDIF

@usedInExample data_example_04.bas
@usedInExample data_example_05.bas

@target all
@verified
</usermanual> */
Variable * read_end( Environment * _environment ) {

    MAKE_LABEL

    Variable * dataptr = variable_retrieve( _environment, "DATAPTR" );
    Variable * dataptre = variable_temporary( _environment, VT_ADDRESS, "(dataptre)" );
    Variable * readEnd = variable_temporary( _environment, VT_BYTE, "(type)" );

    cpu_compare_and_branch_16bit_const( _environment, dataptr->realName, 0, label, 0 );

    if ( !_environment->dataSegment ) {
        CRITICAL_READ_END_WITHOUT_DATA( );
    }

    cpu_addressof_16bit( _environment, _environment->dataSegment->realName, dataptr->realName );

    cpu_label( _environment, label );

    cpu_addressof_16bit( _environment, "DATAPTRE", dataptre->realName );
    cpu_compare_16bit( _environment, dataptr->realName, dataptre->realName, readEnd->realName, 1 );

    return readEnd;

}

