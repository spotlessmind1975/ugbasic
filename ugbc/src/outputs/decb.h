#ifndef __UGBASIC_DECB__
#define __UGBASIC_DECB__

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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

/****************************************************************************
 * DATA TYPES AND STRUCTURES
 ****************************************************************************/

#define     DECB_MARK_DATA          0
#define     DECB_MARK_EOF           255
#define     DECB_BLOCK_SIZE         8192

struct _DECBEntry;

typedef struct _DECBHandle {

    struct _DECBEntry        * first;
    
} DECBHandle;

/****************************************************************************
 * FUNCTION DECLARATION
 ****************************************************************************/

DECBHandle *        decb_create( );
void                decb_add_raw( DECBHandle * _handle, int _mark, int _size, int _address, char * _data );
void                decb_add( DECBHandle * _handle, int _size, int _address, char * _data );
void                decb_eof( DECBHandle * _handle, int _address );
void                decb_output( DECBHandle * _handle, unsigned char * _filename );
void                decb_free( DECBHandle * _handle );

#endif