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
 * @brief Emit ASM code for <b>PLAY SAMPLES</b>
 * 
 * This function emits a code capable of play samples
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play off
 */
/* <usermanual>
@keyword PLAY SAMPLES
@target pc128op
</usermanual> */
void play_samples_var( Environment * _environment, char * _expr ) {
    
    deploy_preferred( play_samples, src_hw_pc128op_play_samples_asm);

    int frequency_to_delay[256] = {
        37735,  31746,  27397,  24096,  21505,  19417,  17699,  16260,
        15037,  13986,  13071,  12269,  11560,  10928,  10362,  9852,
        9389,   8968,   8583,   8230,   7905,   7604,   7326,   7067,
        6825,   6600,   6389,   6191,   6006,   5830,   5665,   5509,
        5361,   5221,   5089,   4962,   4842,   4728,   4618,   4514,
        4415,   4319,   4228,   4140,   4056,   3976,   3898,   3824,
        3752,   3683,   3616,   3552,   3490,   3430,   3372,   3316,
        3262,   3210,   3159,   3110,   3062,   3016,   2971,   2928,
        2886,   2844,   2805,   2766,   2728,   2691,   2656,   2621,
        2587,   2554,   2522,   2490,   2460,   2430,   2400,   2372,
        2344,   2317,   2290,   2265,   2239,   2214,   2190,   2166,
        2143,   2120,   2098,   2076,   2055,   2034,   2014,   1994,
        1974,   1955,   1936,   1917,   1899,   1881,   1863,   1846,
        1829,   1813,   1796,   1780,   1765,   1749,   1734,   1719,
        1705,   1690,   1676,   1662,   1648,   1635,   1622,   1609,
        1596,   1583,   1571,   1558,   1546,   1534,   1523,   1511,
        1500,   1489,   1478,   1467,   1456,   1446,   1435,   1425,
        1415,   1405,   1395,   1386,   1376,   1367,   1357,   1348,
        1339,   1330,   1321,   1313,   1304,   1296,   1287,   1279,
        1271,   1263,   1255,   1247,   1239,   1232,   1224,   1217,
        1209,   1202,   1195,   1188,   1181,   1174,   1167,   1160,
        1154,   1147,   1140,   1134,   1128,   1121,   1115,   1109,
        1103,   1097,   1091,   1085,   1079,   1073,   1067,   1062,
        1056,   1050,   1045,   1040,   1034,   1029,   1024,   1018,
        1013,   1008,   1003,   998,    993,    988,    983,    978,
        974,    969,    964,    960,    955,    951,    946,    942,
        937,    933,    928,    924,    920,    916,    911,    907,
        903,    899,    895,    891,    887,    883,    879,    876,
        872,    868,    864,    860,    857,    853,    849,    846,
        842,    839,    835,    832,    828,    825,    822,    818,
        815,    812,    808,    805,    802,    799,    795,    792,
        789,    786,    783,    780,    777,    774,    771,    768,
    };

    Variable * samples = variable_retrieve( _environment, _expr );

    if ( samples->type != VT_SAMPLES ) {
        CRITICAL_CANNOT_PLAY_SAMPLES_NOT_SAMPLES( _expr );
    }

    int delay = 20; /* 8.000 Hz by default */

    for( int i=0; i<256; ++i ) {
        if ( frequency_to_delay[i] < samples->frequency ) {
            delay = i;
            break;
        }
    }

    if ( samples->bankAssigned != -1 ) {
        outline1("LDA #$%2.2x", ( unsigned char) ( delay & 0xff ) );
        outline0("STA PLAYSAMPLESEXPL2LR+1" );
        outline0("STA PLAYSAMPLESEXPL2HR+1" );
        outline1("LDX #$%4.4x", samples->absoluteAddress );
        outline1("LDB #$%2.2x", samples->bankAssigned );
        outline0("JSR PLAYSAMPLESEXP" );
    } else {
        outline1("LDA #$%2.2x", ( unsigned char) ( delay & 0xff ) );
        outline0("STA PLAYSAMPLESL2LR+1" );
        outline0("STA PLAYSAMPLESL2HR+1" );
        outline1("LDX #%s", samples->realName );
        outline0("JSR PLAYSAMPLES" );
    }

}
