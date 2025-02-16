/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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

 #include "../../../ugbc.h"

 /****************************************************************************
  * CODE SECTION 
  ****************************************************************************/

void fujinet_define( Environment * _environment, FujiNetDefine _mode ) {

    switch( _mode ) {
        
#if defined(__coco__)
        case FN_HDBDOS:
            deploy( serial, src_hw_coco_serial_asm);
            cpu_call( _environment, "SERIALDEFINEHDBDOS" );
            break;
        case FN_BECKER:
            deploy( serial, src_hw_coco_serial_asm);
            cpu_call( _environment, "SERIALDEFINEBECKERPORT" );
            break;
#endif

#if defined(__atari__) || defined(__atarixl__)
        case FN_SERIAL:
            deploy( serial, src_hw_atari_serial_asm);
            deploy( fujinet, src_hw_atari_fujinet_asm);
            cpu_call( _environment, "FUJINETDEFINESERIAL" );
            break;
        case FN_SIO:
            deploy( fujinet, src_hw_atari_fujinet_asm);
            cpu_call( _environment, "FUJINETDEFINESIO" );
            break;
#endif
    
    }
            
}
