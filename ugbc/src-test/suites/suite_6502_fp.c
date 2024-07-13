#include "../tester.h"

int suite_fp_6502( Environment * _environment ) {

    printf( "==== FLOATING POINT SUPPORT (MOS 6502) ====\n" );

    printf( "--- ADD operation\n" );

    for( int i=0; i<10; ++i ) {
        for( int j=0; j<10; ++j ) {
            double a = (float)(i) / 10.00;
            double b = (float)(j) / 10.00;
            test_fp_6502_add( _environment, a, b, a+b );
        }
    }

    printf( "\n" );

    printf( "--- SUB operation\n" );

    for( int i=0; i<10; ++i ) {
        for( int j=0; j<10; ++j ) {
            double a = (float)(i) / 10.00;
            double b = (float)(j) / 10.00;
            test_fp_6502_sub( _environment, a, b, a-b );
        }
    }

    printf( "\n" );
    
}