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

/**
 * @brief Emit code for <strong>PEN ...</strong> command
 * 
 * @param _environment Current calling environment
 * @param _color Color to use for the pen
 */
/* <usermanual>
@keyword PEN

@target plus4
</usermanual> */
void pen( Environment * _environment, char * _color ) {

    Variable * pen = variable_retrieve( _environment, "PEN" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    MAKE_LABEL

    outline0("LDA $D011");
    outline0("AND #%00100000");
    outline1("BEQ %stxt", label );
    outline1("LDA %s", color->realName);
    outline0("CLC" );
    outline0("ASL A" );
    outline0("CLC" );
    outline0("ASL A" );
    outline0("CLC" );
    outline0("ASL A" );
    outline0("CLC" );
    outline0("ASL A" );
    outline0("STA _PEN");
    outline1("JMP %sdone", label);
    outhead1("%stxt:", label );
    outline1("LDA %s", color->realName);
    outline0("STA _PEN");
    outline1("JMP %sdone", label);
    outhead1("%sdone:", label );
    
}