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

#include "tmx.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

TmxMap * tmx_load( char * _filename ) {

    TmxMap * result = NULL;

    xmlDocPtr doc;

    doc = xmlReadFile( _filename, NULL, 0 );

    if ( ! doc )
        return result;

    result = malloc( sizeof( TsxMap ) );
    memset( result, 0, sizeof ( TsxMap ) );

    xmlNode *root_element = NULL;
    xmlNode *cur_node = NULL;

    root_element = xmlDocGetRootElement(doc);
 
    for (cur_node = root_element; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            if ( strcmp( cur_node->name, "map" ) == 0 ) {
                struct _xmlAttr * properties = cur_node->properties;
                while( properties ) {
                    if ( properties->type == XML_ATTRIBUTE_NODE ) {
                        xmlChar* value = xmlNodeListGetString(cur_node->doc, properties->children, 1);
                        if ( strcmp( properties->name, "version") == 0 ) {
                            result->version = strdup( value );
                        } else if ( strcmp( properties->name, "tiledVersion") == 0 ) {
                            result->tiledversion = strdup( value );
                        } else if ( strcmp( properties->name, "orientation") == 0 ) {
                            if ( strcmp( value, "orthogonal" ) == 0 ) {
                                result->orientation = TMX_ORTHOGONAL;
                            } else if ( strcmp( value, "isometric" ) == 0 ) {
                                result->orientation = TMX_ISOMETRIC;
                            } else if ( strcmp( value, "staggered" ) == 0 ) {
                                result->orientation = TMX_STAGGERED;
                            } else if ( strcmp( value, "hexagonal" ) == 0 ) {
                                result->orientation = TMX_HEXAGONAL;
                            }
                        } else if ( strcmp( properties->name, "renderorder") == 0 ) {
                            if ( strcmp( value, "right-down" ) == 0 ) {
                                result->orientation = TMX_RIGHT_DOWN;
                            } else if ( strcmp( value, "right-up" ) == 0 ) {
                                result->orientation = TMX_RIGHT_UP;
                            } else if ( strcmp( value, "left-down" ) == 0 ) {
                                result->orientation = TMX_LEFT_DOWN;
                            } else if ( strcmp( value, "left-up" ) == 0 ) {
                                result->orientation = TMX_LEFT_UP;
                            }
                        } else if ( strcmp( properties->name, "width") == 0 ) {
                            result->width = atoi( value );
                        } else if ( strcmp( properties->name, "height") == 0 ) {
                            result->height = atoi( value );
                        } else if ( strcmp( properties->name, "tilewidth") == 0 ) {
                            result->tilewidth = atoi( value );
                        } else if ( strcmp( properties->name, "tileheight") == 0 ) {
                            result->tileheight = atoi( value );
                        } else if ( strcmp( properties->name, "infinite") == 0 ) {
                            result->infinite = atoi( value );
                        } else if ( strcmp( properties->name, "nextlayerid") == 0 ) {
                            result->nextlayerid = atoi( value );
                        } else if ( strcmp( properties->name, "nextobjectid") == 0 ) {
                            result->nextobjectid = atoi( value );
                        }
                        xmlFree(value); 
                    }
                    properties = properties->next;
                }

                xmlNode * child = cur_node->children;
                while( child ) {

                    if ( strcmp( child->name, "tileset" ) == 0 ) {

                        char * source, int firstgid;

                        struct _xmlAttr * properties = child->properties;
                        while( properties ) {
                            if ( properties->type == XML_ATTRIBUTE_NODE ) {
                                xmlChar* value = xmlNodeListGetString(child->doc, properties->children, 1);
                                if ( strcmp( properties->name, "source") == 0 ) {
                                    source = strdup( value );
                                } if ( strcmp( properties->name, "width") == 0 ) {
                                    firstgid = atoi( value );
                                }
                                xmlFree(value); 
                            }
                            properties = properties->next;
                        }

                        TsxTileset * tileset = tsx_load(_environment, source );

                        tileset->firstgid = firstgid;

                        if ( ! map->tilesets ) {
                            map->tilesets = tileset;
                        } else {
                            TsxTileset * actual = map->tilesets;
                            while( actual->next )  {
                                actual = actual->next;
                            }
                            actual->next = tileset;
                        }

                    } else if ( strcmp( child->name, "layer" ) == 0 ) {

                        TmxLayer * layer = malloc( sizeof( TmxLayer ) );
                        memset( layer, 0, sizeof( TmsLayer ) );

                        struct _xmlAttr * properties = child->properties;
                        while( properties ) {
                            if ( properties->type == XML_ATTRIBUTE_NODE ) {
                                xmlChar* value = xmlNodeListGetString(child->doc, properties->children, 1);
                                if ( strcmp( properties->name, "name") == 0 ) {
                                    layer->name = strdup( name );
                                } if ( strcmp( properties->name, "width") == 0 ) {
                                    layer->width = atoi( value );
                                } if ( strcmp( properties->name, "height") == 0 ) {
                                    layer->height = atoi( value );
                                } if ( strcmp( properties->name, "id") == 0 ) {
                                    layer->id = atoi( value );
                                }
                                xmlFree(value); 
                            }
                            properties = properties->next;
                        }

                        xmlNode * child = cur_node->children;
                        while( child ) {
                            if ( strcmp( child->name, "data" ) == 0 ) {

                                layer->data = malloc( layer->width * layer->height * sizeof( int ) );
                                memset( layer->data, 0, layer->width * layer->height * sizeof( int ) );

                                char * content = (char*)xmlNodeGetContent( child->children );
                                int step = 0;
                                
                                while( *content ) {
                                    
                                    char valueString[MAX_TEMPORARY_STORAGE];
                                    memset( valueString, 0, MAX_TEMPORARY_STORAGE );
                                    int p=0, j=0;

                                    while( *content ) {
                                        char c = *content;
                                        ++content;
                                        if ( j == 0 ) {
                                            if ( (c < '0') || (c > '9') ) {
                                                continue;
                                            }
                                            j = 1;
                                        } else {
                                            if ( (c < '0') || (c > '9') ) {
                                                break;
                                            }
                                        }
                                        valueString[p] = c;
                                        ++p;
                                    }

                                    int value = atoi( valueString );
                                    layer->data[step] = value;
                                    ++step;

                                }

                            }

                            child = child->next;

                        }

                        if ( ! map->layers ) {
                            map->layers = layer;
                        } else {
                            TmxLayer * actual = map->layers;
                            while( actual->next )  {
                                actual = actual->next;
                            }
                            actual->next = layer;
                        }

                    }

                    child = child->next;

                }

            }
        }
    }

    xmlFreeDoc(doc);

    return result;

}