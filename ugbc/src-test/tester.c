#include "tester.h"

int yycolno;
int yyposno;

void show_usage_and_exit( int _argc, char *_argv[] ) {

    printf("ugBASIC Compiler TESTER v1.0\n");
    printf("----------------------------\n");
    printf("Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)\n\n");
    printf("Licensed under the Apache License, Version 2.0 (the \"License\");\n");
    printf("you may not use this program except in compliance with the License.\n\n");

    printf("usage: %s\n\n", _argv[0] );

    exit(EXIT_FAILURE);
}

void dump( char * _title, MemoryBlock * _memory, int _size ) {

    printf("--- %s (%d) ---\n", _title, _size );
    for( int i=0; i<_size; ++i ) {
        printf( "%2.2x ", _memory[i] );
        if ( ( (i+1) % 8  ) == 0 ) {
            printf("\n");
        }
    }
    printf("\n\n");

}

int test_fp_single( Environment * _environment, double _val, int _expected[4] ) {

    int result[4];

    cpu_float_single_from_double_to_int_array( _environment, _val, &result[0] );

    if ( memcmp( &_expected[0], &result[0], 4 ) == 0 ) {
        printf( "FP %f ... OK\n", _val );
    } else {
        printf( "FP %f ... BAD\n", _val );
        printf( "    expected: %2.2x %2.2x %2.2x %2.2x\n", (unsigned char) _expected[0], (unsigned char) _expected[1], (unsigned char) _expected[2], (unsigned char) _expected[3]);
        printf( "    got     : %2.2x %2.2x %2.2x %2.2x\n", (unsigned char) result[0], (unsigned char) result[1], (unsigned char) result[2], (unsigned char) result[3] );
    }

}

int test_fp( Environment * _environment ) {

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
        test_fp_single( _environment, val, &expectedm1p1[10+i][0] );
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
        test_fp_single( _environment, val, &expectedm1010p1010[10+i][0] );
    }

}

int test_fp_add( Environment * _environment ) {
    
    char executableName[MAX_TEMPORARY_STORAGE];
    BUILD_TOOLCHAIN_CC65_GET_EXECUTABLE( _environment, executableName );

}

int main( int _argc, char *_argv[] ) {

    Environment * environment = malloc( sizeof( Environment ) );
    memset( environment, 0, sizeof( Environment ) );

    test_fp( environment );

    test_fp_add( environment );

}