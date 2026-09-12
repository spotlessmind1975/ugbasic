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
@target coco
</usermanual> */
void play_samples_var( Environment * _environment, char * _expr ) {

    int frequency_to_delay[256] = {
                27969 /* Hz = 0 */, 24189 /* Hz = 1 */, 21309 /* Hz = 2 */, 19042 /* Hz = 3 */, 17211 /* Hz = 4 */, 15702 /* Hz = 5 */, 14435 /* Hz = 6 */, 13358 /* Hz = 7 */,
                12430 /* Hz = 8 */, 11623 /* Hz = 9 */, 10914 /* Hz = 10 */, 10287 /* Hz = 11 */, 9728 /* Hz = 12 */, 9226 /* Hz = 13 */, 8774 /* Hz = 14 */, 8364 /* Hz = 15 */,
                7991 /* Hz = 16 */, 7649 /* Hz = 17 */, 7336 /* Hz = 18 */, 7047 /* Hz = 19 */, 6780 /* Hz = 20 */, 6532 /* Hz = 21 */, 6302 /* Hz = 22 */, 6088 /* Hz = 23 */,
                5888 /* Hz = 24 */, 5700 /* Hz = 25 */, 5524 /* Hz = 26 */, 5359 /* Hz = 27 */, 5203 /* Hz = 28 */, 5056 /* Hz = 29 */, 4917 /* Hz = 30 */, 4786 /* Hz = 31 */,
                4661 /* Hz = 32 */, 4543 /* Hz = 33 */, 4430 /* Hz = 34 */, 4323 /* Hz = 35 */, 4221 /* Hz = 36 */, 4124 /* Hz = 37 */, 4031 /* Hz = 38 */, 3942 /* Hz = 39 */,
                3857 /* Hz = 40 */, 3776 /* Hz = 41 */, 3698 /* Hz = 42 */, 3623 /* Hz = 43 */, 3551 /* Hz = 44 */, 3482 /* Hz = 45 */, 3416 /* Hz = 46 */, 3352 /* Hz = 47 */,
                3290 /* Hz = 48 */, 3231 /* Hz = 49 */, 3173 /* Hz = 50 */, 3118 /* Hz = 51 */, 3065 /* Hz = 52 */, 3013 /* Hz = 53 */, 2963 /* Hz = 54 */, 2915 /* Hz = 55 */,
                2868 /* Hz = 56 */, 2823 /* Hz = 57 */, 2779 /* Hz = 58 */, 2737 /* Hz = 59 */, 2695 /* Hz = 60 */, 2655 /* Hz = 61 */, 2617 /* Hz = 62 */, 2579 /* Hz = 63 */,
                2542 /* Hz = 64 */, 2507 /* Hz = 65 */, 2472 /* Hz = 66 */, 2438 /* Hz = 67 */, 2405 /* Hz = 68 */, 2374 /* Hz = 69 */, 2342 /* Hz = 70 */, 2312 /* Hz = 71 */,
                2283 /* Hz = 72 */, 2254 /* Hz = 73 */, 2226 /* Hz = 74 */, 2199 /* Hz = 75 */, 2172 /* Hz = 76 */, 2146 /* Hz = 77 */, 2120 /* Hz = 78 */, 2096 /* Hz = 79 */,
                2071 /* Hz = 80 */, 2048 /* Hz = 81 */, 2024 /* Hz = 82 */, 2002 /* Hz = 83 */, 1980 /* Hz = 84 */, 1958 /* Hz = 85 */, 1937 /* Hz = 86 */, 1916 /* Hz = 87 */,
                1896 /* Hz = 88 */, 1876 /* Hz = 89 */, 1856 /* Hz = 90 */, 1837 /* Hz = 91 */, 1819 /* Hz = 92 */, 1800 /* Hz = 93 */, 1782 /* Hz = 94 */, 1765 /* Hz = 95 */,
                1748 /* Hz = 96 */, 1731 /* Hz = 97 */, 1714 /* Hz = 98 */, 1698 /* Hz = 99 */, 1682 /* Hz = 100 */, 1666 /* Hz = 101 */, 1651 /* Hz = 102 */, 1636 /* Hz = 103 */,
                1621 /* Hz = 104 */, 1606 /* Hz = 105 */, 1592 /* Hz = 106 */, 1578 /* Hz = 107 */, 1564 /* Hz = 108 */, 1551 /* Hz = 109 */, 1537 /* Hz = 110 */, 1524 /* Hz = 111 */,
                1511 /* Hz = 112 */, 1499 /* Hz = 113 */, 1486 /* Hz = 114 */, 1474 /* Hz = 115 */, 1462 /* Hz = 116 */, 1450 /* Hz = 117 */, 1438 /* Hz = 118 */, 1427 /* Hz = 119 */,
                1416 /* Hz = 120 */, 1405 /* Hz = 121 */, 1394 /* Hz = 122 */, 1383 /* Hz = 123 */, 1372 /* Hz = 124 */, 1362 /* Hz = 125 */, 1351 /* Hz = 126 */, 1341 /* Hz = 127 */,
                1331 /* Hz = 128 */, 1322 /* Hz = 129 */, 1312 /* Hz = 130 */, 1302 /* Hz = 131 */, 1293 /* Hz = 132 */, 1284 /* Hz = 133 */, 1274 /* Hz = 134 */, 1265 /* Hz = 135 */,
                1257 /* Hz = 136 */, 1248 /* Hz = 137 */, 1239 /* Hz = 138 */, 1231 /* Hz = 139 */, 1222 /* Hz = 140 */, 1214 /* Hz = 141 */, 1206 /* Hz = 142 */, 1198 /* Hz = 143 */,
                1190 /* Hz = 144 */, 1182 /* Hz = 145 */, 1174 /* Hz = 146 */, 1166 /* Hz = 147 */, 1159 /* Hz = 148 */, 1151 /* Hz = 149 */, 1144 /* Hz = 150 */, 1137 /* Hz = 151 */,
                1130 /* Hz = 152 */, 1122 /* Hz = 153 */, 1115 /* Hz = 154 */, 1109 /* Hz = 155 */, 1102 /* Hz = 156 */, 1095 /* Hz = 157 */, 1088 /* Hz = 158 */, 1082 /* Hz = 159 */,
                1075 /* Hz = 160 */, 1069 /* Hz = 161 */, 1062 /* Hz = 162 */, 1056 /* Hz = 163 */, 1050 /* Hz = 164 */, 1044 /* Hz = 165 */, 1038 /* Hz = 166 */, 1032 /* Hz = 167 */,
                1026 /* Hz = 168 */, 1020 /* Hz = 169 */, 1014 /* Hz = 170 */, 1009 /* Hz = 171 */, 1003 /* Hz = 172 */, 997 /* Hz = 173 */, 992 /* Hz = 174 */, 986 /* Hz = 175 */,
                981 /* Hz = 176 */, 976 /* Hz = 177 */, 970 /* Hz = 178 */, 965 /* Hz = 179 */, 960 /* Hz = 180 */, 955 /* Hz = 181 */, 950 /* Hz = 182 */, 945 /* Hz = 183 */,
                940 /* Hz = 184 */, 935 /* Hz = 185 */, 930 /* Hz = 186 */, 925 /* Hz = 187 */, 920 /* Hz = 188 */, 916 /* Hz = 189 */, 911 /* Hz = 190 */, 906 /* Hz = 191 */,
                902 /* Hz = 192 */, 897 /* Hz = 193 */, 893 /* Hz = 194 */, 888 /* Hz = 195 */, 884 /* Hz = 196 */, 880 /* Hz = 197 */, 875 /* Hz = 198 */, 871 /* Hz = 199 */,
                867 /* Hz = 200 */, 863 /* Hz = 201 */, 858 /* Hz = 202 */, 854 /* Hz = 203 */, 850 /* Hz = 204 */, 846 /* Hz = 205 */, 842 /* Hz = 206 */, 838 /* Hz = 207 */,
                834 /* Hz = 208 */, 831 /* Hz = 209 */, 827 /* Hz = 210 */, 823 /* Hz = 211 */, 819 /* Hz = 212 */, 815 /* Hz = 213 */, 812 /* Hz = 214 */, 808 /* Hz = 215 */,
                804 /* Hz = 216 */, 801 /* Hz = 217 */, 797 /* Hz = 218 */, 794 /* Hz = 219 */, 790 /* Hz = 220 */, 787 /* Hz = 221 */, 783 /* Hz = 222 */, 780 /* Hz = 223 */,
                776 /* Hz = 224 */, 773 /* Hz = 225 */, 770 /* Hz = 226 */, 766 /* Hz = 227 */, 763 /* Hz = 228 */, 760 /* Hz = 229 */, 757 /* Hz = 230 */, 754 /* Hz = 231 */,
                750 /* Hz = 232 */, 747 /* Hz = 233 */, 744 /* Hz = 234 */, 741 /* Hz = 235 */, 738 /* Hz = 236 */, 735 /* Hz = 237 */, 732 /* Hz = 238 */, 729 /* Hz = 239 */,
                726 /* Hz = 240 */, 723 /* Hz = 241 */, 720 /* Hz = 242 */, 717 /* Hz = 243 */, 714 /* Hz = 244 */, 712 /* Hz = 245 */, 709 /* Hz = 246 */, 706 /* Hz = 247 */,
                703 /* Hz = 248 */, 700 /* Hz = 249 */, 698 /* Hz = 250 */, 695 /* Hz = 251 */, 692 /* Hz = 252 */, 690 /* Hz = 253 */, 687 /* Hz = 254 */, 684 /* Hz = 255 */
    };

    deploy( play_samples, src_hw_coco_play_samples_asm);

    Variable * samples = variable_retrieve( _environment, _expr );

    if ( samples->type != VT_SAMPLES ) {
        CRITICAL_CANNOT_PLAY_SAMPLES_NOT_SAMPLES( _expr );
    }

    
    outline1("LDX #%s", samples->realName );
    outline1("LDA #%2.2x", ( unsigned char) ( delay & 0xff ) );
    outline0("STA PLAYSAMPLESL2LR+1" );
    outline0("STA PLAYSAMPLESL2HR+1" );
    outline0("JSR PLAYSAMPLES" );

}
