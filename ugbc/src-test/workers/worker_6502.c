#include "../tester.h"

void execute6502( Environment * _environment, char * _asm_filename, Variable * _variable ) {

    char * binaryFileNameRoot = get_temporary_filename( _environment );
    char * mapFileNameRoot = get_temporary_filename( _environment );

    char binaryFileName[MAX_TEMPORARY_STORAGE];
    sprintf( binaryFileName, "%s.bin", binaryFileNameRoot );
    char mapFileName[MAX_TEMPORARY_STORAGE];
    sprintf( mapFileName, "%s.lbl", mapFileNameRoot );

    char commandLine[4*MAX_TEMPORARY_STORAGE];
    sprintf( commandLine, "cl65 -g -Ln %s --start-addr 32768 -t none -o %s %s >/dev/null", mapFileName, binaryFileName, _asm_filename );
    // printf( "%s\n", commandLine );
    (void)!system( commandLine );
    sprintf( commandLine, "run6502 -l 8000 %s -R 8000 -X 0000 -D >/dev/null 2>/dev/null", binaryFileName );
    // printf( "%s\n", commandLine );
    (void)!system( commandLine );

    unsigned char memory[0xffff];
    memset( memory, 0, 0xffff );

    FILE * dumpFile = fopen( "run6502.dump", "rb" );
    if ( dumpFile ) {
        (void)!fread( &memory[0], 1, 0xffff, dumpFile );
        fclose( dumpFile );
    }

    FILE * mapFile = fopen( mapFileName, "r" );
    if ( mapFile ) {
        while( ! feof( mapFile ) ) {
            char type[32];
            unsigned int address;
            char name[256];

            (void)!fscanf( mapFile, "%s %x .%s", type, &address, name );

            Variable * v = _variable;
            while ( v ) {
                if ( strcmp( v->name, name ) == 0 ) {
                    switch( VT_BITWIDTH( v->type ) ) {
                        case 0: {
                                switch( v->type ) {
                                    case VT_FLOAT: {
                                        int value[4];
                                        value[0] = memory[address];
                                        value[1] = memory[address+1];
                                        value[2] = memory[address+2];
                                        value[3] = memory[address+3];
                                        cpu_float_single_from_int_array_to_double( _environment, &value[0], &v->valueFloating );
                                        break;
                                    }
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

            // printf( "%s = %x [%2.2x]\n", name, address, (unsigned char) memory[address] );

        }
    }

    remove( binaryFileName );
    remove( mapFileName );
    remove( "run6502.dump" );

}
