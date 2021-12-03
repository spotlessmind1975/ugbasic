/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

void target_install( Environment * _environment ) {

    char answer;

    printf("\nYou have requested to install the chaintool for the ZX Spectrum target.\n"); 

    #ifdef _WIN32
        printf("This implies that \"Z88DK - The Development Kit for Z80 Computers\"\n");
        printf("will be downloaded from the ugBASIC site, and it will be run automatically.\n");
        printf("The size of the self-extracting executable is of about 22 MB.n\n\n");

        printf("Do you want to continue [y/N] ?");

        (void)!scanf(" %c", &answer);

        printf("\n\n");

        if (answer == 'Y' || answer == 'y'){

            printf("Downloading: Z88DK - The Development Kit for Z80 Computers\n\n");
            (void)!system( "curl https://ugbasic.iwashere.eu/download/z88dk-win32.exe --output z88dk-win32.exe" );

            printf("\n\nInstalling: Z88DK - The Development Kit for Z80 Computers\n\n");
            (void)!system( "z88dk-win32.exe" );

            remove( "z88dk-win32.exe" );

        }

    #else
        printf("This implies that \"Z88DK - The Development Kit for Z80 Computers\"\n");
        printf("must be installed from the standard GitHub repository:\n\n");
        printf("https://github.com/z88dk/z88dk.git\n\n");
    #endif


}
