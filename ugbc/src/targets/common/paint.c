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
 * @brief Emit ASM code for <b>PAIN</b>
 * 
 * @param _environment Current calling environment
 * @param _address Expression with the location to write to.
 * @param _value Expression to write.
 */
/* <usermanual>
@keyword PAINT

@english

The ''PAINT'' command is used in high resolution graphics modes, to fill a 
shape with a specified colour.

The ''x,y'' are the coordinates of the point where the painting is to start.
''c'' is the colour code of the colours to be used to paint. It must be 
between ''0'' and ''COLOR COUNT'' and be one of the available colour set 
for the working mode. If omitted, the current foreground colour is used.

The ''b'' parameter is the colour code of the border at which painting 
is to stop. It must also be between 0 and 8, the painting will continue 
over a border of any other colour. If omitted, the current foreground 
colour is used.

There is also an alternative syntax for ''PAINT'', that is  used to fill 
enclosed areas in the color of the specified color source '<fq>' (see ''HIRES''), 
starting from the starting point ''x'', ''y''. ''PAINT'' does nothing if the 
selected starting point already has the desired color. 

@italian

Il comando ''PAINT'' viene utilizzato nelle modalità grafiche ad alta 
risoluzione, per riempire una forma con un colore specificato.

Le ''x,y'' sono le coordinate del punto in cui deve iniziare il 
dipinto. ''c'' è il codice colore dei colori da utilizzare per
dipingere. Deve essere compreso tra ''0'' e ''COLOR COUNT'' ed essere 
uno dei set di colori disponibili per la modalità di lavoro. 
Se omesso, viene utilizzato il colore corrente. 

Il parametro ''b'' è il codice colore del bordo in cui deve terminare 
il painting. Inoltre deve essere compreso tra ''0'' e ''COLOR COUNT'', il riempimento 
proseguirà su un bordo di qualsiasi altro colore. Se omesso, 
viene utilizzato il colore di primo piano corrente.

Esiste anche una sintassi alternativa per ''PAINT'', che viene utilizzata per 
riempire le aree chiuse con il colore della sorgente di colore specificata 
''fq'' (vedi ''HIRES''), a partire dal punto iniziale ''x '', ''y''. 
''PAINT'' non fa nulla se il punto iniziale selezionato ha già il colore desiderato.

@syntax PAINT (x,y)[, c[, b]]
@syntax PAINT x, y, fq

@example PAINT(100,100),RED
@example PAINT 0,0,1

</usermanual> */
void paint_vars( Environment * _environment, char * _x, char * _y, char * _c, char * _b ) {

    MAKE_LABEL

    char beginPaintLabel[MAX_TEMPORARY_STORAGE]; sprintf( beginPaintLabel, "%sbegin", label );
    char isValidLabel[MAX_TEMPORARY_STORAGE]; sprintf( isValidLabel, "%sisvalid", label );
    char pushQueue[MAX_TEMPORARY_STORAGE]; sprintf( pushQueue, "%spush", label );
    char pushQueueDone[MAX_TEMPORARY_STORAGE]; sprintf( pushQueueDone, "%spushd", label );
    char popQueue[MAX_TEMPORARY_STORAGE]; sprintf( popQueue, "%spop", label );
    char popQueueDone[MAX_TEMPORARY_STORAGE]; sprintf( popQueueDone, "%spopd", label );
    char resultFalseLabel[MAX_TEMPORARY_STORAGE]; sprintf( resultFalseLabel, "%sresultfalse", label );
    char resultTrueLabel[MAX_TEMPORARY_STORAGE]; sprintf( resultTrueLabel, "%sresulttrue", label );
    char loopPaintLabel[MAX_TEMPORARY_STORAGE]; sprintf( loopPaintLabel, "%sloop", label );
    char endPaintLabel[MAX_TEMPORARY_STORAGE]; sprintf( endPaintLabel, "%send", label );
    char forceDequePaintLabel[MAX_TEMPORARY_STORAGE]; sprintf( forceDequePaintLabel, "%sdeque", label );
    char skip1PaintLabel[MAX_TEMPORARY_STORAGE]; sprintf( skip1PaintLabel, "%sskip1", label );
    char skip2PaintLabel[MAX_TEMPORARY_STORAGE]; sprintf( skip2PaintLabel, "%sskip2", label );
    char skip3PaintLabel[MAX_TEMPORARY_STORAGE]; sprintf( skip3PaintLabel, "%sskip3", label );
    char skip4PaintLabel[MAX_TEMPORARY_STORAGE]; sprintf( skip4PaintLabel, "%sskip4", label );

    deploy_begin( paint )

        cpu_jump( _environment, beginPaintLabel );

        Variable * pointValue = variable_define( _environment, "point__v", VT_COLOR, 0 );
        Variable * paintX = variable_define( _environment, "paint__x", VT_POSITION, 0 );
        Variable * paintY = variable_define( _environment, "paint__y", VT_POSITION, 0 );
        Variable * paintC = variable_define( _environment, "paint__c", VT_COLOR, 0 );
        Variable * paintB = variable_define( _environment, "paint__b", VT_COLOR, 0 );

        Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
        Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
        Variable * previousColor = variable_temporary( _environment, VT_COLOR, "(previousColor)" );
        Variable * posX = variable_temporary( _environment, VT_POSITION, "(x)" );
        Variable * posY = variable_temporary( _environment, VT_POSITION, "(y)" );

        Variable * queue = variable_define( _environment, "PAINTQUEUE", VT_BUFFER, 0 );
        variable_resize_buffer( _environment, queue->name, ( _environment->paintBucketSize == 0 ) ? DEFAULT_PAINT_BUCKET_SIZE : _environment->paintBucketSize );
        Variable * queuePtrFront = variable_define( _environment, "PAINTQUEUEPTRFRONT", VT_ADDRESS, 0 );
        Variable * queuePtrRear = variable_define( _environment, "PAINTQUEUEPTRREAR", VT_ADDRESS, 0 );
        Variable * queuePtrEnd = variable_define( _environment, "PAINTQUEUEPTREND", VT_ADDRESS, 0 );

        cpu_label( _environment, pushQueue );

            cpu_move_16bit_indirect( _environment, x->realName, queuePtrRear->realName );
            cpu_inc_16bit( _environment, queuePtrRear->realName );
            cpu_inc_16bit( _environment, queuePtrRear->realName );
            cpu_move_16bit_indirect( _environment, y->realName, queuePtrRear->realName );
            cpu_inc_16bit( _environment, queuePtrRear->realName );
            cpu_inc_16bit( _environment, queuePtrRear->realName );
            cpu_compare_and_branch_16bit( _environment, queuePtrRear->realName, queuePtrEnd->realName, pushQueueDone, 0 );
            cpu_addressof_16bit( _environment, queue->realName, queuePtrRear->realName );
            cpu_label( _environment, pushQueueDone );
            cpu_return( _environment );

        cpu_label( _environment, popQueue );

            cpu_move_16bit_indirect2( _environment, queuePtrFront->realName, posX->realName );
            cpu_inc_16bit( _environment, queuePtrFront->realName );
            cpu_inc_16bit( _environment, queuePtrFront->realName );
            cpu_move_16bit_indirect2( _environment, queuePtrFront->realName, posY->realName );
            cpu_inc_16bit( _environment, queuePtrFront->realName );
            cpu_inc_16bit( _environment, queuePtrFront->realName );
            cpu_compare_and_branch_16bit( _environment, queuePtrFront->realName, queuePtrEnd->realName, popQueueDone, 0 );
            cpu_addressof_16bit( _environment, queue->realName, queuePtrFront->realName );
            cpu_label( _environment, popQueueDone );
            cpu_return( _environment );

        cpu_label( _environment, isValidLabel );

            Variable * isValid = variable_temporary( _environment, VT_SBYTE, "(isValid)" );

            // // Function that returns true if
            // // the given pixel is valid
            // bool isValid(int screen[][8], int m, int n, int x, int y,
            //             int prevC, int newC)
            // {
            //     if (x < 0

            variable_move( _environment, 
                        variable_less_than_const( _environment, x->name, 0, 0 )->name, 
                        isValid->name );
            variable_compare_and_branch_const( _environment, isValid->name, 0xff, resultFalseLabel, 1 );

            //      || x >= m

            variable_move( _environment, 
                            variable_greater_than( _environment, 
                                x->name, 
                                screen_get_width( _environment )->name, 
                            1 )->name,
                            isValid->name );
            variable_compare_and_branch_const( _environment, isValid->name, 0xff, resultFalseLabel, 1 );

            //      || y < 0

            variable_move( _environment, 
                            variable_less_than_const( _environment, y->name, 0, 0 )->name, 
                            isValid->name );
            variable_compare_and_branch_const( _environment, isValid->name, 0xff, resultFalseLabel, 1 );

            //      || y >= n

            variable_move( _environment, 
                            variable_greater_than( _environment, 
                                y->name, 
                                screen_get_height( _environment )->name, 
                            1 )->name, 
                            isValid->name );
            variable_compare_and_branch_const( _environment, isValid->name, 0xff, resultFalseLabel, 1 );

            //      || screen[x][y] != prevC

            variable_move( _environment, point( _environment, x->name, y->name )->name, pointValue->name );

            variable_move( _environment, 
                            variable_compare_not( _environment, 
                                pointValue->name, 
                                previousColor->name
                            )->name,
                            isValid->name );
            variable_compare_and_branch_const( _environment, isValid->name, 0xff, resultFalseLabel, 1 );

            //      || screen[x][y] == newC

            variable_move( _environment, 
                            variable_compare( _environment, 
                                pointValue->name, 
                                paintC->name
                            )->name,
                            isValid->name );
            variable_compare_and_branch_const( _environment, isValid->name, 0xff, resultFalseLabel, 1 );

            //      || (newB > 0 ? screen[x][y] == newB ) )

            variable_compare_and_branch_const( _environment, paintB->name, 0x0, resultTrueLabel, 1 );

            variable_move( _environment, 
                            variable_compare( _environment, 
                                pointValue->name, 
                                paintB->name
                            )->name,
                            isValid->name );
            variable_compare_and_branch_const( _environment, isValid->name, 0xff, resultFalseLabel, 1 );

            //         return false;

            cpu_label( _environment, resultTrueLabel );
            cpu_store_8bit( _environment, isValid->realName, 0xff );
            cpu_return( _environment );

            //     return true;
            // }

            cpu_label( _environment, resultFalseLabel );

            cpu_store_8bit( _environment, isValid->realName, 0 );
            cpu_return( _environment );

            //////////////////////

        cpu_label( _environment, beginPaintLabel );

            variable_move( _environment, paintX->name, x->name );
            variable_move( _environment, paintY->name, y->name );

            variable_move( _environment, 
                                point( _environment, x->name, y->name )->name, 
                                previousColor->name);

            cpu_addressof_16bit( _environment, queue->realName, queuePtrFront->realName );
            cpu_addressof_16bit( _environment, queue->realName, queuePtrRear->realName );
            cpu_addressof_16bit( _environment, queue->realName, queuePtrEnd->realName );
            cpu_math_add_16bit_const( _environment, queuePtrEnd->realName, ( _environment->paintBucketSize == 0 ) ? DEFAULT_PAINT_BUCKET_SIZE : _environment->paintBucketSize, queuePtrEnd->realName );

            // Append the position of starting
            // pixel of the component
            // cpu_move_16bit_indirect( _environment, x->realName, queuePtrRear->realName );
            // cpu_inc_16bit( _environment, queuePtrRear->realName );
            // cpu_inc_16bit( _environment, queuePtrRear->realName );
            // cpu_move_16bit_indirect( _environment, y->realName, queuePtrRear->realName );
            // cpu_inc_16bit( _environment, queuePtrRear->realName );
            // cpu_inc_16bit( _environment, queuePtrRear->realName );
            cpu_call( _environment, pushQueue );

            // Color the pixel with the new color
            plot( _environment, x->name, y->name, paintC->name, 0 );

            // ------------------------------[ BEGIN FLOOD FILL LOOP ]
            cpu_label( _environment, loopPaintLabel );

                // cpu_label( _environment, forceDequePaintLabel );

                // While the queue is not empty i.e. the
                // whole component having prevC color
                // is not colored with newC color
                cpu_compare_and_branch_16bit( _environment, queuePtrFront->realName, queuePtrRear->realName, endPaintLabel, 1 );

                // Dequeue the front node
                // cpu_dec_16bit( _environment, queuePtr->realName );
                // cpu_dec_16bit( _environment, queuePtr->realName );
                // cpu_move_16bit_indirect2( _environment, queuePtr->realName, posY->realName );
                // cpu_dec_16bit( _environment, queuePtr->realName );
                // cpu_dec_16bit( _environment, queuePtr->realName );
                // cpu_move_16bit_indirect2( _environment, queuePtr->realName, posX->realName );
                cpu_call( _environment, popQueue );

                // int posX = currPixel.first;
                // int posY = currPixel.second;

                // Check if the adjacent
                // pixels are valid
                // if (isValid(screen, m, n, posX + 1, posY, prevC, newC)) {
                variable_move( _environment, posX->name, x->name );
                cpu_inc_16bit( _environment, x->realName );
                variable_move( _environment, posY->name, y->name );
                cpu_call( _environment, isValidLabel );
                cpu_compare_and_branch_8bit_const( _environment, isValid->realName, 0x00, skip1PaintLabel, 1 );
                // Color with newC
                // if valid and enqueue
                plot( _environment, x->name, y->name, paintC->name, 0 );
                // variable_move( _environment, 
                //     variable_compare( _environment, queuePtr->name, queuePtrEnd->name )->name,
                //     isValid->name );
                // cpu_compare_and_branch_8bit_const( _environment, isValid->realName, 0xff, forceDequePaintLabel, 1 );
                // // p.first = posX + 1;
                // cpu_move_16bit_indirect( _environment, x->realName, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // // p.second = posY;
                // cpu_move_16bit_indirect( _environment, y->realName, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // // queue.push(p);
                cpu_call( _environment, pushQueue );

                cpu_label( _environment, skip1PaintLabel );

                // Check if the adjacent
                // pixels are valid
                // if (isValid(screen, m, n, posX - 1, posY, prevC, newC)) {
                variable_move( _environment, posX->name, x->name );
                cpu_dec_16bit( _environment, x->realName );
                variable_move( _environment, posY->name, y->name );
                cpu_call( _environment, isValidLabel );
                cpu_compare_and_branch_8bit_const( _environment, isValid->realName, 0x00, skip2PaintLabel, 1 );
                // Color with newC
                // if valid and enqueue
                plot( _environment, x->name, y->name, paintC->name, 0 );
                // variable_move( _environment, 
                //     variable_compare( _environment, queuePtr->name, queuePtrEnd->name )->name,
                //     isValid->name );
                // cpu_compare_and_branch_8bit_const( _environment, isValid->realName, 0xff, forceDequePaintLabel, 1 );                
                // // p.first = posX + 1;
                // cpu_move_16bit_indirect( _environment, x->realName, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // // p.second = posY;
                // cpu_move_16bit_indirect( _environment, y->realName, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // // queue.push(p);
                cpu_call( _environment, pushQueue );
            
                cpu_label( _environment, skip2PaintLabel );

                // Check if the adjacent
                // pixels are valid
                // if (isValid(screen, m, n, posX, posY+1, prevC, newC)) {
                variable_move( _environment, posX->name, x->name );
                variable_move( _environment, posY->name, y->name );
                cpu_inc_16bit( _environment, y->realName );
                cpu_call( _environment, isValidLabel );
                cpu_compare_and_branch_8bit_const( _environment, isValid->realName, 0x00, skip3PaintLabel, 1 );
                // Color with newC
                // if valid and enqueue
                plot( _environment, x->name, y->name, paintC->name, 0 );
                // variable_move( _environment, 
                //     variable_compare( _environment, queuePtr->name, queuePtrEnd->name )->name,
                //     isValid->name );
                // cpu_compare_and_branch_8bit_const( _environment, isValid->realName, 0xff, forceDequePaintLabel, 1 );
                // // p.first = posX + 1;
                // cpu_move_16bit_indirect( _environment, x->realName, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // // p.second = posY;
                // cpu_move_16bit_indirect( _environment, y->realName, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // // queue.push(p);
                cpu_call( _environment, pushQueue );

                cpu_label( _environment, skip3PaintLabel );

                // Check if the adjacent
                // pixels are valid
                // if (isValid(screen, m, n, posX, posY-1, prevC, newC)) {
                variable_move( _environment, posX->name, x->name );
                variable_move( _environment, posY->name, y->name );
                cpu_dec_16bit( _environment, y->realName );
                cpu_call( _environment, isValidLabel );
                cpu_compare_and_branch_8bit_const( _environment, isValid->realName, 0x00, skip4PaintLabel, 1 );
                // Color with newC
                // if valid and enqueue
                plot( _environment, x->name, y->name, paintC->name, 0 );
                // variable_move( _environment, 
                //     variable_compare( _environment, queuePtr->name, queuePtrEnd->name )->name,
                //     isValid->name );
                // cpu_compare_and_branch_8bit_const( _environment, isValid->realName, 0xff, forceDequePaintLabel, 1 );
                // // p.first = posX + 1;
                // cpu_move_16bit_indirect( _environment, x->realName, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // // p.second = posY;
                // cpu_move_16bit_indirect( _environment, y->realName, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // cpu_inc_16bit( _environment, queuePtr->realName );
                // // queue.push(p);
                cpu_call( _environment, pushQueue );

                cpu_label( _environment, skip4PaintLabel );

            cpu_jump( _environment, loopPaintLabel );

        // ------------------------------[ END FLOOD FILL LOOP ]

        cpu_label( _environment, endPaintLabel );

        cpu_return( _environment );

    deploy_end( paint )

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * c = NULL;
    if ( _c ) {
        c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    } else {
        c = variable_retrieve( _environment, "PEN" );
    }

    Variable * px = variable_retrieve( _environment, "paint__x" );
    Variable * py = variable_retrieve( _environment, "paint__y" );
    Variable * pc = variable_retrieve( _environment, "paint__c" );
    Variable * pb = variable_retrieve( _environment, "paint__b" );

    variable_move( _environment, x->name, px->name );
    variable_move( _environment, y->name, py->name );
    variable_move( _environment, c->name, pc->name );
    if ( _b ) {
        Variable * b = variable_retrieve( _environment, _b );
        variable_move( _environment, b->name, pb->name );
    } else {
        variable_store( _environment, pb->name, 0 );
    }

    cpu_call( _environment, "lib_paint" );

}
