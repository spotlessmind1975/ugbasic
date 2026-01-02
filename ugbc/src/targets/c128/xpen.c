/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>= XPEN()</b>
 * 
 * This function can be used to read the X (horizontal) position of the 
 * electronic pen connected to the hardware. The result is stored in a 
 * temporary variable.
 * 
 * @param _environment Current calling environment
 * @return Variable* Variable with the result of the reading
 */
/* <usermanual>
@keyword XPEN

@english

The ''XPEN'' command is used to query the hardware and get the horizontal 
position (X coordinate) of a light pen attached to the system, if the 
hardware supports such a device. When the ''XPEN' command is executed 
within a program, the underlying hardware attempts to read the X coordinate 
value detected by the light pen. This value represents the horizontal position 
of where the pen is currently pointing on the screen or a touch-sensitive surface.

It is important to note that the ''XPEN'' command will only work if the hardware 
on which the program is running actually has a pen interface, and if the pen is 
properly connected and working. If the hardware does not support a pen, the 
value returned by ''XPEN'' may be undefined (often 0 or some other default value), 
and will not represent a valid position.

On some systems, a pen calibration step may be necessary to ensure an accurate 
correspondence between the physical position of the pen and the coordinates on 
the screen. The language itself does not handle calibration directly, which is 
usually handled by the operating system or hardware-specific routines.

To track the movement of the pen, you will need to read the value of ''XPEN'' (and 
usually also ''YPEN'' for the vertical coordinate) in a continuous loop within 
the program.

The value returned by ''XPEN'' represents the horizontal coordinate. The range of 
these values will depend on the horizontal resolution of the screen or touch 
surface supported by the pen.

@italian

Il comando ''XPEN'' viene utilizzato per interrogare l'hardware e ottenere la 
posizione orizzontale (coordinata X) di una penna ottica collegata al sistema, 
se l'hardware la supporta. Quando il comando ''XPEN'' viene eseguito all'interno 
di un programma, l'hardware sottostante tenta di leggere il valore della coordinata 
X rilevato dalla penna ottica. Questo valore rappresenta la posizione orizzontale 
del punto in cui la penna sta attualmente puntando sullo schermo o su una 
superficie sensibile al tocco. 

È importante notare che il comando ''XPEN'' funziona 
solo se l'hardware su cui è in esecuzione il programma dispone effettivamente di 
un'interfaccia penna e se la penna è correttamente collegata e funzionante. 

Se l'hardware non supporta una penna, il valore restituito da ''XPEN'' potrebbe 
essere indefinito (spesso 0 o un altro valore predefinito) e non rappresenterà 
una posizione valida. 

Su alcuni sistemi, potrebbe essere necessaria una fase di 
calibrazione della penna per garantire una corrispondenza accurata tra la posizione 
fisica della penna e le coordinate sullo schermo. Il linguaggio stesso non gestisce 
direttamente la calibrazione, che solitamente viene gestita dal sistema operativo 
o da routine specifiche dell'hardware. 

Per tracciare il movimento della penna, è necessario leggere il valore di ''XPEN'' 
(e solitamente anche ''YPEN'' per la coordinata verticale) in un ciclo continuo 
all'interno del programma. Il valore restituito da ''XPEN'' rappresenta la 
coordinata orizzontale. L'intervallo di questi valori dipenderà dalla risoluzione 
orizzontale dello schermo o della superficie touch supportata dalla penna.

@syntax = XPEN( )

@example x = XPEN( )

@target c128
@target c128reu
@target c128

@alias X PEN
@seeAlso YPEN
</usermanual> */
/* <usermanual>
@keyword X PEN
@alias XPEN
@seeAlso Y PEN
</usermanual> */
Variable * xpen( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_POSITION, "(result)" );

    c128_xpen( _environment, result->realName );
    
    return result;

}
