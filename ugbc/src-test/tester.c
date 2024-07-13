#include "tester.h"

int yycolno;
int yyposno;

void welcome( ) {

    printf("ugBASIC Compiler TESTER v1.0\n");
    printf("----------------------------\n");
    printf("Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)\n\n");
    printf("Licensed under the Apache License, Version 2.0 (the \"License\");\n");
    printf("you may not use this program except in compliance with the License.\n\n");

}

int main( int _argc, char *_argv[] ) {

    welcome( );

    Environment * environment = malloc( sizeof( Environment ) );
    memset( environment, 0, sizeof( Environment ) );

    printf( "################################################\n" );
    printf( "############       TEST SUITES      ############ \n" );
    printf( "################################################\n" );

    suite_fp( environment );
    suite_fp_6502( environment );

}