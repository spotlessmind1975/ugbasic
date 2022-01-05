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

void target_install( Environment * _environment ) {

    char answer;

    printf("\nYou have requested to install the chaintool for the Dragon 32 target.\n"); 

    #ifdef _WIN32
        printf("This implies that \"asm6809 assembler\"\n");
        printf("will be downloaded from the ugBASIC site, and it will be run automatically.\n");
        printf("The size of the self-extracting executable is of about 155 KB.n\n\n");

        printf("Do you want to continue [y/N] ?");

        (void)!scanf(" %c", &answer);

        printf("\n\n");

        if (answer == 'Y' || answer == 'y'){

            mkdir("asm6809");
            mkdir("asm6809\\bin");

            printf("Downloading: asm6809 assembler\n\n");
            (void)!system_call( _environment,  "curl https://ugbasic.iwashere.eu/download/asm6809.exe --output asm6809\\bin\\asm6809.exe" );

            printf("\n\nInstalling: asm6809 assembler\n\n");

            remove( "cc65-win32.exe" );

    }

    #else
        printf("This implies that \"asm6809 assembler\"\n");
        printf("must be installed from the standard GitHub repository:\n\n");
        printf("https://www.6809.org.uk/git/asm6809.git/\n\n");
    #endif

}
