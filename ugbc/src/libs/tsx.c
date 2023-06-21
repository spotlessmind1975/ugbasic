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

    xmlNode *root_element = NULL;
    xmlNode *cur_node = NULL;

    root_element = xmlDocGetRootElement(doc);
 
    for (cur_node = root_element; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            if ( strcmp( cur_node->name, "tileset" ) == 0 ) {
                
                result = malloc( sizeof( TsxTileset ) );
                memset( result, 0, sizeof ( TsxTileset ) );

                struct _xmlAttr * properties = cur_node->properties;
                while( properties ) {
                    if ( properties->type == XML_ATTRIBUTE_NODE ) {
                        xmlChar* value = xmlNodeListGetString(cur_node->doc, properties->children, 1);
                        if ( strcmp( properties->name, "version") == 0 ) {
                            result->version = strdup( value );
                        } if ( strcmp( properties->name, "tiledVersion") == 0 ) {
                            result->tiledversion = strdup( value );
                        } if ( strcmp( properties->name, "name") == 0 ) {
                            result->name = strdup( value );
                        } if ( strcmp( properties->name, "tilewidth") == 0 ) {
                            result->tilewidth = atoi( value );
                        } if ( strcmp( properties->name, "tileheight") == 0 ) {
                            result->tileheight = atoi( value );
                        } if ( strcmp( properties->name, "tilecount") == 0 ) {
                            result->tilecount = atoi( value );
                        } if ( strcmp( properties->name, "columns") == 0 ) {
                            result->columns = atoi( value );
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