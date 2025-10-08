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

/**
 * @brief Emit code for <strong>NEW SEQUENCE(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _width Width of the image, in pixel
 * @param _height Heigth of the image, in pixel
 * @param _mode Mode to use
 */
Variable * new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    Variable * result = gime_new_sequence( _environment, _sequences, _frames, _width, _height, _mode );

    result->offsettingFrames = offsetting_size_count( _environment, result->frameSize, _frames );
    offsetting_add_variable_reference( _environment, result->offsettingFrames, result, 0 );

    result->offsettingSequences = offsetting_size_count( _environment, _frames*result->frameSize, _sequences );
    offsetting_add_variable_reference( _environment, result->offsettingSequences, result, 1 );

    return result;

}
