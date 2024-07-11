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

void execute6502( Environment * _environment, char * _asm_filename, Variable * _variable ) {

    char * binaryFileNameRoot = get_temporary_filename( _environment );
    char * mapFileNameRoot = get_temporary_filename( _environment );

    char binaryFileName[MAX_TEMPORARY_STORAGE];
    sprintf( binaryFileName, "%s.bin", binaryFileNameRoot );
    char mapFileName[MAX_TEMPORARY_STORAGE];
    sprintf( mapFileName, "%s.lbl", mapFileNameRoot );

    char commandLine[MAX_TEMPORARY_STORAGE];
    sprintf( commandLine, "cl65 -g -Ln %s --start-addr 32768 -t none -o %s %s", mapFileName, binaryFileName, _asm_filename );
    printf( "%s\n", commandLine );
    system( commandLine );
    sprintf( commandLine, "run6502 -l 8000 %s -R 8000 -X 0000 -D", binaryFileName );
    printf( "%s\n", commandLine );
    system( commandLine );

    unsigned char memory[0xffff];
    memset( memory, 0, 0xffff );

    FILE * dumpFile = fopen( "run6502.dump", "rb" );
    if ( dumpFile ) {
        fread( &memory[0], 1, 0xffff, dumpFile );
        fclose( dumpFile );
    }

    FILE * mapFile = fopen( mapFileName, "r" );
    if ( mapFile ) {
        while( ! feof( mapFile ) ) {
            char type[32];
            unsigned int address;
            char name[256];

            fscanf( mapFile, "%s %x .%s", type, &address, name );

            Variable * v = _variable;
            while ( v->next ) {
                if ( strcmp( v->name, name ) ) {
                    switch( VT_BITWIDTH( v->type ) ) {
                        case 0: {
                            switch( v->type ) {
                                case VT_FLOAT:
                            
                            }

                            }
                            break;
                        case 8:
                            v->value = memory[address];
                            break;
                        case 16:
                            v->value = memory[address] | ( memory[address+1] << 8 );
                            break;
                        case 24:
                            v->value = memory[address] | ( memory[address+1] << 8 ) | ( memory[address+2] << 16 );
                            break;
                        case 32:
                            v->value = memory[address] | ( memory[address+1] << 8 ) | ( memory[address+2] << 16 ) | ( memory[address+3] << 24 );
                            break;
                    }
                }
                v = v->next;
            }

            printf( "%s = %x [%2.2x]\n", name, address, (unsigned char) memory[address] );

        }
    }

    remove( binaryFileName );
    remove( mapFileName );

}

int test_fp_6502( Environment * _environment ) {

    char * asmFileNameRoot = get_temporary_filename( _environment );
    char asmFileName[MAX_TEMPORARY_STORAGE];
    sprintf( asmFileName, "%s.asm", asmFileNameRoot );

    _environment->asmFile = fopen( asmFileName, "wt");
    deploy( vars, src_hw_atari_vars_asm);
    setup_text_variables( _environment );
    deploy( startup, src_hw_atari_startup_asm);
    deploy( fp_vars, src_hw_6502_fp_routines_asm );
    int result[4];
    cpu_float_single_from_double_to_int_array( _environment, 0.1, &result[0] );
    outline1("LDA #$%2.2x", result[0] );
    outline0("STA FP1X" );
    outline1("LDA #$%2.2x", result[1] );
    outline0("STA FP1M" );
    outline1("LDA #$%2.2x", result[2] );
    outline0("STA FP1M+1" );
    outline1("LDA #$%2.2x", result[3] );
    outline0("STA FP1M+2" );
    cpu_float_single_from_double_to_int_array( _environment, 0.2, &result[0] );
    outline1("LDA #$%2.2x", result[0] );
    outline0("STA FP2X" );
    outline1("LDA #$%2.2x", result[1] );
    outline0("STA FP2M" );
    outline1("LDA #$%2.2x", result[2] );
    outline0("STA FP2M+1" );
    outline1("LDA #$%2.2x", result[3] );
    outline0("STA FP2M+2" );
    outline0("JSR FPADD" );
    outline0("BRK" );
    buffered_output( _environment->asmFile );
    fclose( _environment->asmFile );
    execute6502( _environment, asmFileName );
//    remove( asmFileName );

}

int main( int _argc, char *_argv[] ) {

    Environment * environment = malloc( sizeof( Environment ) );
    memset( environment, 0, sizeof( Environment ) );

    // test_fp( environment );
    test_fp_6502( environment );

}