#include "../tester.h"

int suite_fp_6502( Environment * _environment ) {

    printf( "==== FLOATING POINT SUPPORT (MOS 6502) ====\n" );

    printf( "--- ADD operation\n" );

    for( int i=-10; i<10; ++i ) {
        for( int j=-10; j<10; ++j ) {
            double a = (float)(i) / 10.00;
            double b = (float)(j) / 10.00;
            printf( "a = %f, b = %f\n", a, b );
            test_fp_6502_add( _environment, a, b, a+b );
        }
    }

    // test_fp_6502_add( _environment, 0.0, 0.0, 0.0 );
    // test_fp_6502_add( _environment, 1.0, 1.0, 2.0 );
    // test_fp_6502_add( _environment, 0.0, 0.0, 0.0 );

    printf( "\n" );
    
}