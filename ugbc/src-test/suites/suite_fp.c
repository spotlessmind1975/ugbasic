#include "../tester.h"

int suite_fp( Environment * _environment ) {

    printf( "==== FLOATING POINT SUPPORT (COMPILE TIME) ====\n" );

    printf( "--- FLOAT <-> BYTES conversion\n" );

    int expectedm1p1[][4] = {
        { // -1.0
            0xbf, 0x80, 0x00, 0x00
        },
        { // -0.9
            0xbf, 0x66, 0x66, 0x66
        },
        { // -0.8
            0xbf, 0x4c, 0xcc, 0xcd
        },
        { // -0.7
            0xbf, 0x33, 0x33, 0x33
        },
        { // -0.6
            0xbf, 0x19, 0x99, 0x9a
        },
        { // -0.5
            0xbf, 0x00, 0x00, 0x00
        },
        { // -0.4
            0xbe, 0xcc, 0xcc, 0xcd
        },
        { // -0.3
            0xbe, 0x99, 0x99, 0x9a
        },
        { // -0.2
            0xbe, 0x4c, 0xcc, 0xcd
        },
        { // -0.1
            0xbd, 0xcc, 0xcc, 0xcd
        },
        { // 0
            0x00, 0x00, 0x00, 0x00
        },
        { // 0.1
            0x3d, 0xcc, 0xcc, 0xcd
        },
        { // 0.2
            0x3e, 0x4c, 0xcc, 0xcd
        },
        { // 0.3
            0x3e, 0x99, 0x99, 0x9a
        },
        { // 0.4
            0x3e, 0xcc, 0xcc, 0xcd
        },
        { // 0.5
            0x3f, 0x00, 0x00, 0x00
        },
        { // 0.6
            0x3f, 0x19, 0x99, 0x9a
        },
        { // 0.7
            0x3f, 0x33, 0x33, 0x33
        },
        { // 0.8
            0x3f, 0x4c, 0xcc, 0xcd
        },
        { // 0.9
            0x3f, 0x66, 0x66, 0x66
        },
    };

    for( int i=-10; i<10; ++i ) {
        double val = (double) i / 10.0;
        test_fp_conversion_to_bytes( _environment, val, &expectedm1p1[10+i][0] );
        test_fp_conversion_to_double( _environment, &expectedm1p1[10+i][0], val  );
    }

    int expectedm1010p1010[][4] = {
        { // -11
            0xc1, 0x30, 0x00, 0x00
        },
        { // -9.9
            0xc1, 0x1e, 0x66, 0x66
        },
        { // -8.8
            0xc1, 0x0c, 0xcc, 0xcd
        },
        { // -7.7
            0xc0, 0xf6, 0x66, 0x66
        },
        { // -6.6
            0xc0, 0xd3, 0x33, 0x33
        },
        { // -5.5
            0xc0, 0xb0, 0x00, 0x00
        },
        { // -4.4
            0xc0, 0x8c, 0xcc, 0xcd
        },
        { // -3.3
            0xc0, 0x53, 0x33, 0x33
        },
        { // -2.2
            0xc0, 0x0c, 0xcc, 0xcd
        },
        { // -1.1
            0xbf, 0x8c, 0xcc, 0xcd
        },
        { // 0
            0x00, 0x00, 0x00, 0x00
        },
        { // 1.1
            0x3f, 0x8c, 0xcc, 0xcd
        },
        { // 2.2
            0x40, 0x0c, 0xcc, 0xcd
        },
        { // 3.3
            0x40, 0x53, 0x33, 0x33
        },
        { // 4.4
            0x40, 0x8c, 0xcc, 0xcd
        },
        { // 5.5
            0x40, 0xb0, 0x00, 0x00
        },
        { // 6.6
            0x40, 0xd3, 0x33, 0x33
        },
        { // 7.7
            0x40, 0xf6, 0x66, 0x66
        },
        { // 8.8
            0x41, 0x0c, 0xcc, 0xcd
        },
        { // 9.9
            0x41, 0x1e, 0x66, 0x66
        },
    };

    for( int i=-10; i<10; ++i ) {
        double val = (double) ( i / 10.0 ) + (double) (i);
        test_fp_conversion_to_bytes( _environment, val, &expectedm1010p1010[10+i][0] );
        test_fp_conversion_to_double( _environment, &expectedm1010p1010[10+i][0], val );
    }

    printf( "\n" );

}
