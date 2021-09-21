#include "tester.h"

void show_usage_and_exit( int _argc, char *_argv[] ) {

    printf("ugBASIC Compiler TESTER v1.0\n");
    printf("----------------------------\n");
    printf("Copyright 2021 Marco Spedaletti (asimov@mclink.it)\n\n");
    printf("Licensed under the Apache License, Version 2.0 (the \"License\");\n");
    printf("you may not use this program except in compliance with the License.\n\n");

    printf("usage: %s\n\n", _argv[0] );

    exit(EXIT_FAILURE);
}

int main( int _argc, char *_argv[] ) {

    test_cpu( );
    test_variables( );
    test_conditionals( );
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
    
}