#include "tester.h"

int yycolno;
int yyposno;

void show_usage_and_exit( int _argc, char *_argv[] ) {

    printf("ugBASIC Compiler TESTER v1.0\n");
    printf("----------------------------\n");
    printf("Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)\n\n");
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

void test_msc1( ) {

    for( int i=1; i<2048; ++i ) {
        int compressed_size = 0;
        int uncompressed_size = 0;
        MemoryBlock * block = malloc( i );
        for( int j=0; j<i; ++j ) {
            block[j] = ( j & 0x3 );
        }

        // dump( "original", block, i );

        MSC1Compressor * compressor = msc1_create( 16 );
        MemoryBlock * compressed = msc1_compress( compressor, block, i, &compressed_size );

        // dump( "compressed", compressed, compressed_size );

        MemoryBlock * uncompressed = msc1_uncompress( compressor, compressed, compressed_size, &uncompressed_size );

        // dump( "uncompressed", uncompressed, uncompressed_size );

        printf( " * %d, ratio = %d %  \n", i, ( ( 100 * compressed_size ) / uncompressed_size ) );

        if ( uncompressed_size != i ) {
            printf( "ERROR: compress / uncompress SIZE mismatch at %d", i );
            exit(0);
        }

        if ( memcmp( uncompressed, block, i ) != 0 ) {
            printf( "ERROR: compress / uncompress DATA mismatch at %d", i );
            exit(0);
        }

        msc1_free( compressor );
        free( block );

    }

}


int main( int _argc, char *_argv[] ) {

    // test_cpu( );
    // test_variables( );
    // test_conditionals( );
    // test_loops( );
    // test_ons( );
    // test_controls( );
    // test_examples( );

    // #ifdef __c64__
    //     test_vic2( );
    // #endif

    // #ifdef __zx__
    //     test_zx( );
    // #endif

    // test_print( );
    
    test_msc1( );

}