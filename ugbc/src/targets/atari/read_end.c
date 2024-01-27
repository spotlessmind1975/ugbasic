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

    deploy( read_data_unsafe, src_hw_6502_read_data_unsafe_asm );

    MAKE_LABEL

    Variable * readEnd = variable_temporary( _environment, VT_BYTE, "(flag)" );

    outline0("JSR READNUMERICEOD");
    outline1("BNE %s", label);
    outline0("LDA #$FF");
    outline1("JMP %sdone", label);
    outhead1("%s:", label);
    outline0("LDA #$00");
    outhead1("%sdone:", label);
    outline1("STA %s", readEnd->realName);

    return readEnd;

}

