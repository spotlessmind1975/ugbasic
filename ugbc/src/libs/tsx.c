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

#include "tsx.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

TsxTileset * tsx_load( char * _filename ) {

    TsxTileset * result = NULL;

    xmlDocPtr doc;

    doc = xmlReadFile( _filename, NULL, 0 );

    if ( ! doc )
        return result;

    result = malloc( sizeof( TsxTileset ) );
    memset( result, 0, sizeof ( TsxTileset ) );

    xmlNode *root_element = NULL;
    xmlNode *cur_node = NULL;

    root_element = xmlDocGetRootElement(doc);
 
    for (cur_node = root_element; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            if ( strcmp( cur_node->name, "tileset" ) == 0 ) {
                
                struct _xmlAttr * properties = cur_node->properties;
                while( properties ) {
                    if ( properties->type == XML_ATTRIBUTE_NODE ) {
                        xmlChar* value = xmlNodeListGetString(cur_node->doc, properties->children, 1);
                        if ( strcmp( properties->name, "version") == 0 ) {
                            result->version = strdup( value );
                        } else if ( strcmp( properties->name, "tiledVersion") == 0 ) {
                            result->tiledversion = strdup( value );
                        } else if ( strcmp( properties->name, "name") == 0 ) {
                            result->name = strdup( value );
                        } else if ( strcmp( properties->name, "tilewidth") == 0 ) {
                            result->tilewidth = atoi( value );
                        } else if ( strcmp( properties->name, "tileheight") == 0 ) {
                            result->tileheight = atoi( value );
                        } else if ( strcmp( properties->name, "tilecount") == 0 ) {
                            result->tilecount = atoi( value );
                        } else if ( strcmp( properties->name, "columns") == 0 ) {
                            result->columns = atoi( value );
                        } else if ( strcmp( properties->name, "columns") == 0 ) {
                            result->columns = atoi( value );
                        } else if ( strcmp( properties->name, "objectalignment") == 0 ) {
                            
                            // Object Alignment
                            // The alignment to use for tile objects referring to tiles from this tileset. 
                            // This affects the placement of the tile relative to the position of the object 
                            // (the origin) and is also the location around which the rotation is applied.
                            // Possible values are: Unspecified (the default), Top Left, Top, Top Right, 
                            // Left, Center, Right, Bottom Left, Bottom and Bottom Right. When unspecified, 
                            // tile object alignment is generally Bottom Left, except for Isometric maps 
                            // where it is Bottom.
                            
                            // currently unsupported

                        } else if ( strcmp( properties->name, "tilerendersize") == 0 ) {
                            
                            // currently unsupported

                        } else if ( strcmp( properties->name, "backgroundcolor") == 0 ) {
                            
                            // currently unsupported

                        } else if ( strcmp( properties->name, "fillmode") == 0 ) {
                            
                            // currently unsupported

                        }
                        xmlFree(value); 
                    }
                    properties = properties->next;
                }

                xmlNode * child = cur_node->children;
                while( child ) {
                    if ( strcmp( child->name, "image" ) == 0 ) {

                        TsxImage * image = malloc( sizeof( TsxImage ) );
                        memset( image, 0, sizeof ( TsxImage ) );

                        struct _xmlAttr * properties = child->properties;
                        while( properties ) {
                            if ( properties->type == XML_ATTRIBUTE_NODE ) {
                                xmlChar* value = xmlNodeListGetString(child->doc, properties->children, 1);
                                if ( strcmp( properties->name, "source") == 0 ) {
                                    image->source = strdup( value );
                                } if ( strcmp( properties->name, "width") == 0 ) {
                                    image->width = atoi( value );
                                } if ( strcmp( properties->name, "height") == 0 ) {
                                    image->height = atoi( value );
                                }
                                xmlFree(value); 
                            }
                            properties = properties->next;
                        }

                        result->image = image;

                    } else if ( strcmp( child->name, "tileoffset" ) == 0 ) {
                        
                        // Drawing Offset
                        // A drawing offset in pixels, applied when rendering any tile from the 
                        // tileset (as part of tile layers or as tile objects). This is can be 
                        // useful to make your tiles align to the grid.

                        // currently unsupported

                    } else if ( strcmp( child->name, "grid" ) == 0 ) {
                        
                        // Orientation
                        // When the tileset contains isometric tiles, you can set this to Isometric. 
                        // This value, along with the Grid Width and Grid Height properties, is 
                        // taken into account by overlays rendered on top of the tiles. This helps 
                        // for example when specifying Terrain Information. It also affects the 
                        // orientation used by the Tile Collision Editor.

                        // currently unsupported

                    } else if ( strcmp( child->name, "transformations" ) == 0 ) {
                        
                        // Tiled supports flipping and rotating tiles. When using terrains, tiles 
                        // can be automatically flipped and/or rotated to create variations that 
                        // would otherwise not be available in a tileset. This can be enabled in 
                        // the Tileset Properties.

                        // The following transformation-related options are available:

                        // Flip Horizontally
                        // Allow tiles to be flipped horizontally.

                        // Flip Vertically
                        // Allow tiles to be flipped vertically. This would be left disabled 
                        // when the graphics contain shadows in vertical direction, for example.

                        // Rotate
                        // Allow tiles to be rotated (by 90, 180 or 270-degrees).

                        // Prefer Untransformed Tiles
                        // When transformations are enabled, it could happen that a certain pattern 
                        // can be filled by either a regular tile or a transformed tile. With this 
                        // option enabled, the untransformed tiles will always take precedence. 
                        // Leaving this option disabled allows transformations to be used to create 
                        // more variation.

                        // currently unsupported

                    } else if ( strcmp( child->name, "tile" ) == 0 ) {

                        TsxTile * tile = malloc( sizeof( TsxTile ) );
                        memset( tile, 0, sizeof ( TsxTile ) );

                        tile->probability = 1.0f;

                        struct _xmlAttr * properties = child->properties;
                        while( properties ) {
                            if ( properties->type == XML_ATTRIBUTE_NODE ) {
                                xmlChar* value = xmlNodeListGetString(child->doc, properties->children, 1);
                                if ( strcmp( properties->name, "id") == 0 ) {
                                    tile->id = atoi( value );
                                } if ( strcmp( properties->name, "type") == 0 ) {
                                    tile->type = strdup( value );
                                } if ( strcmp( properties->name, "probability") == 0 ) {
                                    tile->probability = atof( value );
                                }
                                xmlFree(value); 
                            }
                            properties = properties->next;
                        }

                        if ( result->tiles ) {
                            tile->next = result->tiles;
                            result->tiles = tile;
                        } else {
                            result->tiles = tile;
                        }

                    }

                    child = child->next;
                }

                break;

            }
        }
    }

    xmlFreeDoc(doc);

    return result;

}