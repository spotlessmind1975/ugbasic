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

void option_dialect( Environment * _environment, Dialect _dialect ) {

    switch( _dialect ) {
        case DI_UGBASIC:
            _environment->optionExecAsGosub = 1;
            _environment->optionCallAsGoto = 0;
            _environment->colorImplicit = 0;
            _environment->centerWithoutNewLine = 0;
            _environment->vestigialConfig.clsImplicit = 0;
            _environment->joystickConfig.values = 0;
            break;
        case DI_TSB:
            _environment->optionExecAsGosub = 1;
            _environment->optionCallAsGoto = 1;
            _environment->colorImplicit = 1;
            _environment->centerWithoutNewLine = 1;
            _environment->vestigialConfig.clsImplicit = 1;
            _environment->joystickConfig.values = 1;
            break;
    }

    if ( !_environment->clsCalledOnce ) {
        _environment->clsCalledOnce = 1;
        cls( _environment, NULL );
    }

}

