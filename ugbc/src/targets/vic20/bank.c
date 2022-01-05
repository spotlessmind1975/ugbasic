/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

extern char BANK_TYPE_AS_STRING[][16];

/**
 * @brief Emit source and configuration lines for banks
 * 
 * This function can be called to generate all the definitions (on the source
 * file, on the configuration file and on any support file) necessary to 
 * implement the memory banks.
 * 
 * @param _environment Current calling environment
 * @todo The data upload should be customized.
 */
void bank_cleanup( Environment * _environment ) {
    int i=0;
    for(i=0; i<BANK_TYPE_COUNT; ++i) {
        Bank * actual = _environment->banks[i];
        while( actual ) {
            if ( actual->type == BT_VARIABLES ) {

            } else if ( actual->type == BT_TEMPORARY ) {

            } else if ( actual->type == BT_STRINGS ) {

            } else {
                if ( actual->filename ) {
                    cfgline4("# BANK %s %s AT $%4.4x WITH \"%s\"", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address, actual->filename);
                } else {
                    cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                }
                cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
                if ( actual->filename ) {
                    int b = 0;
                    FILE * file = fopen(actual->filename, "rb" );
                    if ( !file ) {
                        fprintf(stderr, "Compiler error: unable to open file %s\n", actual->filename);
                        exit(EXIT_FAILURE);                        
                    }
                    if ( actual->filename ) {
                        outline4("; BANK %s %s AT $%4.4x WITH \"%s\" (duplicate)", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address, actual->filename);
                    } else {
                        outline3("; BANK %s %s AT $%4.4x (duplicate)", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                    }
                    // TODO: customize loading of data, based on data type and target
                    outhead1(".segment \"%s\"", actual->name);
                    while( !feof( file ) ) {
                        if ( ( b % 8 ) == 0 ) {
                            out0("\n");
                            out0("\t.byte ");
                        }
                        unsigned char data = fgetc(file);
                        out1("$%2.2x", ( data & 0xff ) );
                        if ( ( ( b % 8 ) != 7 ) ) {
                            out0(",");
                        }
                        ++b;
                    }
                    out0("\n");
                    fclose(file);                 
                }
            }
           actual = actual->next;
        }
    }
}