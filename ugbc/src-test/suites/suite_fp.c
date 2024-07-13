#include "../tester.h"

int suite_fp( Environment * _environment ) {

    printf( "==== FLOATING POINT SUPPORT (COMPILE TIME) ====\n" );

    printf( "--- FLOAT <-> BYTES conversion\n" );

    double values[] = { 10.0, 1.0, 0.1, 0.0, /*-0.1,*/ -1.0 -10.0 };

    int expected[][4] = {
        // 10.0
        {
            0x83, 0x50, 0x00, 0x00
        },
        // 1.0
        {
            0x80, 0x40, 0x00, 0x00
        },
        // 0.1
        {
            0x7C, 0x66, 0x66, 0x66
        },
        // 0.0
        {
            0x00, 0x00, 0x00, 0x00
        },
        // // -0.1
        // {
        //     0xFC, 0x99, 0x99, 0x9A
        // },
        // -1.0
        {
            0x7F, 0x80, 0x00, 0x00     
        },
        // -10.0
        {
            0x83, 0xB0, 0x00, 0x00
        }
    };
     
    for( int i=0; i<( sizeof( values ) / sizeof( double ) )-1; ++i ) {
        test_fp_conversion_to_bytes( _environment, values[i], &expected[i][0] );
        test_fp_conversion_to_double( _environment, &expected[i][0], values[i] );
    }

    printf( "\n" );

}
