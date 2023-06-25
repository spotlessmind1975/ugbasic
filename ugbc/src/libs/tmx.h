#ifndef __TMX__
#define __TMX__

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

typedef enum _TmxOrientation {
 
    TMX_ORTHOGONAL = 1,
    TMX_ISOMETRIC = 2,
    TMX_STAGGERED = 3,
    TMS_HEXAGONAL = 4
 
} TmxOrientation;

typedef enum _TmxRenderOrder {
 
    TMX_RIGHT_DOWN = 1,
    TMX_RIGHT_UP = 2,
    TMX_LEFT_DOWN = 3,
    TMX_LEFT_UP = 4
 
} TmxRenderOrder;

typedef struct _TmxLayer {

    int                     id;
    char                *   name;
    int                     width;
    int                     height;

    int                 *   data;

    struct _TsmxLayer    *   next;

} TmxLayer;

typedef struct _TmxMap {

    TmxOrientation          orientation;
    TmxOrientation          renderorder;
    int                     width;
    int                     height;
    int                     tilewidth;
    int                     tileheight;
    int                     infinite;
    int                     nextlayerid;
    int                     nextobjectid;

    struct _TmxTileset  *   tilesets;

    struct _TmxLayer    *   layers;

} TmxMap;

TmxMap * tmx_load( char * _filename );

#endif