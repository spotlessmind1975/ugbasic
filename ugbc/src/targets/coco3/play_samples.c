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
@target coco3
</usermanual> */
void play_samples_var( Environment * _environment, char * _expr ) {

    deploy( play_samples, src_hw_coco3_play_samples_asm);

    Variable * samples = variable_retrieve( _environment, _expr );

    if ( samples->type != VT_SAMPLES ) {
        CRITICAL_CANNOT_PLAY_SAMPLES_NOT_SAMPLES( _expr );
    }

    int frequency_to_delay[256] = {
            27969,  24189,  21309,  19042,  17211,  15702,  14435,  13358,
            12430,  11623,  10914,  10287,  9728,   9226,   8774,   8364,
            7991,   7649,   7336,   7047,   6780,   6532,   6302,   6088,
            5888,   5700,   5524,   5359,   5203,   5056,   4917,   4786,
            4661,   4543,   4430,   4323,   4221,   4124,   4031,   3942,
            3857,   3776,   3698,   3623,   3551,   3482,   3416,   3352,
            3290,   3231,   3173,   3118,   3065,   3013,   2963,   2915,
            2868,   2823,   2779,   2737,   2695,   2655,   2617,   2579,
            2542,   2507,   2472,   2438,   2405,   2374,   2342,   2312,
            2283,   2254,   2226,   2199,   2172,   2146,   2120,   2096,
            2071,   2048,   2024,   2002,   1980,   1958,   1937,   1916,
            1896,   1876,   1856,   1837,   1819,   1800,   1782,   1765,
            1748,   1731,   1714,   1698,   1682,   1666,   1651,   1636,
            1621,   1606,   1592,   1578,   1564,   1551,   1537,   1524,
            1511,   1499,   1486,   1474,   1462,   1450,   1438,   1427,
            1416,   1405,   1394,   1383,   1372,   1362,   1351,   1341,
            1331,   1322,   1312,   1302,   1293,   1284,   1274,   1265,
            1257,   1248,   1239,   1231,   1222,   1214,   1206,   1198,
            1190,   1182,   1174,   1166,   1159,   1151,   1144,   1137,
            1130,   1122,   1115,   1109,   1102,   1095,   1088,   1082,
            1075,   1069,   1062,   1056,   1050,   1044,   1038,   1032,
            1026,   1020,   1014,   1009,   1003,   997,    992,    986,
            981,    976,    970,    965,    960,    955,    950,    945,
            940,    935,    930,    925,    920,    916,    911,    906,
            902,    897,    893,    888,    884,    880,    875,    871,
            867,    863,    858,    854,    850,    846,    842,    838,
            834,    831,    827,    823,    819,    815,    812,    808,
            804,    801,    797,    794,    790,    787,    783,    780,
            776,    773,    770,    766,    763,    760,    757,    754,
            750,    747,    744,    741,    738,    735,    732,    729,
            726,    723,    720,    717,    714,    712,    709,    706,
            703,    700,    698,    695,    692,    690,    687,    684,
    };

    int delay = 16; /* 8.000 Hz by default */

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
        outline1("LDA #$%2.2x", samples->bankAssigned );
        outline1("LDX #$%4.4x", samples->absoluteAddress );
        outline0("JSR PLAYSAMPLESEXP" );
    } else {
        outline1("LDA #$%2.2x", ( unsigned char) ( delay & 0xff ) );
        outline0("STA PLAYSAMPLESL2LR+1" );
        outline0("STA PLAYSAMPLESL2HR+1" );
        outline1("LDX #%s", samples->realName );
        outline0("JSR PLAYSAMPLES" );
    }

}
