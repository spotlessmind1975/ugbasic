/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *----------------------------------------------------------------------------
 * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
 * (la "Licenza"); è proibito usare questo file se non in conformità alla
 * Licenza. Una copia della Licenza è disponibile all'indirizzo:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Se non richiesto dalla legislazione vigente o concordato per iscritto,
 * il software distribuito nei termini della Licenza è distribuito
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char BANK_TYPE_AS_STRING[][16];
extern char DATATYPE_AS_STRING[][16];

static void variable_cleanup_entry( Environment * _environment, Variable * _first ) {

    Variable * variable = _first;

    while( variable ) {

        if ( ( !variable->assigned || ( variable->assigned && !variable->temporary ) ) ) {
            switch( variable->type ) {
                case VT_CHAR:
                case VT_BYTE:
                case VT_SBYTE:
                case VT_COLOR:
                case VT_THREAD:
                    vars_emit_byte( _environment, variable->realName, variable->initialValue);
                    break;
                case VT_DOJOKA:
                    outline1("%s: defs 4", variable->realName);
                    break;
                case VT_IMAGEREF:
                    outline1("%s: defs 12", variable->realName);
                    break;
                case VT_PATH:
                    outline1("%s: defs 16", variable->realName);
                    break;
                case VT_VECTOR2:
                    outline1("%s: defs 4", variable->realName);
                    break;
                case VT_WORD:
                case VT_SWORD:
                case VT_POSITION:
                case VT_ADDRESS:
                    vars_emit_word( _environment, variable->realName, variable->initialValue);
                    break;
                case VT_DWORD:
                case VT_SDWORD:
                    vars_emit_dword( _environment, variable->realName, variable->initialValue);
                    break;
                case VT_FLOAT:
                    if ( variable->memoryArea ) {
                        outline2("%s: EQU $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outline2("%s: defs %d", variable->realName, 1 << VT_FLOAT_NORMALIZED_POW2_WIDTH( variable->arrayPrecision) );
                    }
                    break;
                case VT_STRING:
                    outline2("%s = cstring%d", variable->realName, variable->valueString->id );
                    break;
                case VT_DSTRING:
                    outline1("%s: db 0", variable->realName);
                    break;
                case VT_MSPRITE:
                case VT_SPRITE:
                    outline1("%s: db 0", variable->realName);
                    break;
                case VT_TILE:
                    outline1("%s: db 0", variable->realName);
                    break;
                case VT_TILESET:
                    outline1("%s: db 0", variable->realName);
                    break;
                case VT_TILES:
                    outline1("%s: db 0,0,0,0", variable->realName);
                    break;
                case VT_BLIT:
                    break;
                case VT_IMAGE:
                case VT_IMAGES:
                case VT_SEQUENCE:
                case VT_MUSIC:
                case VT_BUFFER:
                case VT_TYPE:
                    if ( variable->bankAssigned != -1 ) {
                        outhead2("; relocated on bank %d (at %4.4x)", variable->bankAssigned, variable->absoluteAddress );
                        outhead1("%s: db $0", variable->realName );
                    } else {
                        if ( ! variable->absoluteAddress ) {
                            if ( variable->valueBuffer ) {
                                if ( variable->printable ) {
                                    char * string = malloc( variable->size + 1 );
                                    memset( string, 0, variable->size + 1 );
                                    memcpy( string, variable->valueBuffer, variable->size );
                                    outline2("%s: db %s", variable->realName, escape_newlines( string ) );
                                } else {
                                    out1("%s: db ", variable->realName);
                                    int i=0;
                                    for (i=0; i<(variable->size-1); ++i ) {
                                        if ( ( (i+1) % 16 ) == 0 ) {
                                            outline1("%d", variable->valueBuffer[i]);
                                            out0(" db ");
                                        } else {
                                            out1("%d,", variable->valueBuffer[i]);
                                        }
                                    }
                                    outline1("%d", variable->valueBuffer[(variable->size-1)]);
                                }
                            } else {
                                outline2("%s: defs %d", variable->realName, variable->size);
                            }
                        } else {
                            outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                            if ( variable->valueBuffer ) {
                                if ( variable->printable ) {
                                    char * string = malloc( variable->size + 1 );
                                    memset( string, 0, variable->size + 1 );
                                    memcpy( string, variable->valueBuffer, variable->size );
                                    outline2("%scopy: db %s", variable->realName, escape_newlines( string ) );
                                } else {
                                    out1("%scopy: db ", variable->realName);
                                    int i=0;
                                    for (i=0; i<(variable->size-1); ++i ) {
                                        out1("%d,", variable->valueBuffer[i]);
                                    }
                                    outline1("%d", variable->valueBuffer[(variable->size-1)]);
                                }
                            }
                        }
                    }
                    break;
                case VT_TILEMAP:
                case VT_TARRAY: {
                    if ( variable->bankAssigned != -1 ) {
                        outhead4("; relocated on bank %d (at %4.4x) for %d bytes (uncompressed: %d)", variable->bankAssigned, variable->absoluteAddress, variable->size, variable->uncompressedSize );
                        if ( variable->type == VT_TARRAY ) {
                            if (VT_BITWIDTH( variable->arrayType ) == 0 ) {
                                CRITICAL_DATATYPE_UNSUPPORTED( "BANKED", DATATYPE_AS_STRING[ variable->arrayType ] );
                            }
                            // force +1 byte if size is odd
                            outhead2("%s: defs %d, $00", variable->realName, (VT_BITWIDTH( variable->arrayType )>>3) );
                        } else {
                            if (VT_BITWIDTH( variable->type ) == 0 ) {
                                CRITICAL_DATATYPE_UNSUPPORTED( "BANKED", DATATYPE_AS_STRING[ variable->type ] );
                            }
                            // force +1 byte if size is odd
                            outhead2("%s: defs %d, $00", variable->realName, (VT_BITWIDTH( variable->type )>>3) );
                        }
                    } else {
                        if ( variable->valueBuffer ) {
                            out1("%s: db ", variable->realName);
                            int i=0;
                            for (i=0; i<(variable->size-1); ++i ) {
                                out1("%d,", variable->valueBuffer[i]);
                            }
                            outline1("%d", variable->valueBuffer[(variable->size-1)]);
                        } else if ( variable->value ) {

                            switch( VT_BITWIDTH( variable->arrayType ) ) {
                                case 32: {
                                    out1("%s: db ", variable->realName );
                                    for( int i=0; i<(variable->size/4)-1; ++i ) {
                                        out4("$%2.2x, $%2.2x, $%2.2x, $%2.2x, ", (unsigned int)( variable->value & 0xff ), (unsigned int)( ( variable->value >> 8 ) & 0xff ), (unsigned int)( ( variable->value >> 16 ) & 0xff ), (unsigned int)( ( variable->value >> 24 ) & 0xff ) );
                                    }
                                    out4("$%2.2x, $%2.2x, $%2.2x, $%2.2x", (unsigned int)( variable->value & 0xff ), (unsigned int)( ( variable->value >> 8 ) & 0xff ), (unsigned int)( ( variable->value >> 16 ) & 0xff ), (unsigned int)( ( variable->value >> 24 ) & 0xff ) );
                                    outline0("");
                                    break;
                                }
                                case 16: {
                                    out1("%s: db ", variable->realName );
                                    for( int i=0; i<(variable->size/2)-1; ++i ) {
                                        out2("$%2.2x, $%2.2x,", (unsigned int)( variable->value & 0xff ), (unsigned int)( ( variable->value >> 8 ) & 0xff ) );
                                    }
                                    out2("$%2.2x, $%2.2x", (unsigned int)( variable->value & 0xff ), (unsigned int)( ( variable->value >> 8 ) & 0xff ) );
                                    outline0("");
                                    break;
                                }
                                case 8:
                                    outline3("%s: defs %d, $%2.2x", variable->realName, variable->size, (unsigned char)(variable->value&0xff) );
                                    break;
                                case 1:
                                    outline3("%s: defs %d, $%2.2x", variable->realName, variable->size, (unsigned char)(variable->value?0xff:0x00));
                                    break;
                            }                             
                            
                        } else {
                            outline2("%s: defs %d", variable->realName, variable->size);
                        }
                    }

                    break;
                }
            }
        }
        variable = variable->next;
    }

}

static void variable_cleanup_entry_bit( Environment * _environment, Variable * _first ) {

    Variable * variable = _first;

    int bitCount = 0;

    // outhead0("section data_user");
    while( variable ) {

        if ( ( !variable->assigned || ( variable->assigned && !variable->temporary ) ) && !variable->imported && !variable->memoryArea ) {

            if ( variable->memoryArea && _environment->debuggerLabelsFile ) {
                fprintf( _environment->debuggerLabelsFile, "%4.4x %s\r\n", variable->absoluteAddress, variable->realName );
            }

            switch( variable->type ) {
                case VT_BIT:
                    if ( variable->memoryArea ) {
                        // outline2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outline1("%s:", variable->realName);
                    }
                    ++bitCount;
                    if ( bitCount == 8 ) {
                        outline0("   defs 1");
                    }        
                    break;
            }

        }

        variable = variable->next;

    }

    if ( bitCount > 0 ) {
        outline0("   defs 1");
    }
    // outhead0("section code_user");

}

/**
 * @brief Emit source and configuration lines for variables
 * 
 * This function can be called to generate all the definitions (on the source
 * file, on the configuration file and on any support file) necessary to 
 * implement the variables.
 * 
 * @param _environment Current calling environment
 */
void variable_cleanup( Environment * _environment ) {

    int i=0;

    vars_emit_constants( _environment );

    if ( _environment->dataSegment ) {
        outhead1("DATAFIRSTSEGMENT EQU %s", _environment->dataSegment->realName );
        if ( _environment->readDataUsed && _environment->restoreDynamic ) {
            outhead0("DATASEGMENTNUMERIC:" );
            DataSegment * actual = _environment->dataSegment;
            while( actual ) {
                if ( actual->isNumeric ) {
                    outline2( "dw $%4.4x, %s", actual->lineNumber, actual->realName );
                }
                actual = actual->next;
            }
            outline0( "dw $ffff, DATAPTRE" );
        }
    }   

    if ( _environment->offsetting ) {
        Offsetting * actual = _environment->offsetting;
        while( actual ) {
            out1("OFFSETS%4.4x: dw ", actual->size );
            for( i=0; i<actual->count; ++i ) {
                out1("$%4.4x", i * actual->size );
                if ( i < ( actual->count - 1 ) ) {
                    out0(",");
                } else {
                    outline0("");
                }
            }
            if ( actual->variables ) {
                OffsettingVariable * actualVariable = actual->variables;
                while( actualVariable ) {
                    if ( actualVariable->sequence ) {
                        outhead1("%soffsetsequence:", actualVariable->variable->realName );
                    } else {
                        outhead1("%soffsetframe:", actualVariable->variable->realName );
                    }
                    actualVariable = actualVariable->next;
                }
                outhead1("fs%4.4xoffsetsequence:", actual->size );
                outhead1("fs%4.4xoffsetframe:", actual->size );    
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline0("ADD HL, HL" );
                outline0("LD DE, HL" );
                outline1("LD HL, OFFSETS%4.4x", actual->size );
                outline0("ADD HL, DE" );
                outline0("LD A, (HL)" );
                outline0("LD E, A" );
                outline0("INC HL" );
                outline0("LD A, (HL)" );
                outline0("LD D, A" );
                outline0("PUSH IX" );
                outline0("POP HL" );
                outline0("ADD HL, DE" );
                outline0("RET" );
            }            
            actual = actual->next;
        }

        int values[MAX_TEMPORARY_STORAGE];
        char * address[MAX_TEMPORARY_STORAGE];

        actual = _environment->offsetting;
        int count = 0;
        while( actual ) {
            values[count] = actual->size;
            address[count] = malloc( MAX_TEMPORARY_STORAGE );
            sprintf( address[count], "fs%4.4xoffsetframe", actual->size );
            actual = actual->next;
            ++count;
        }

        cpu_address_table_build( _environment, "EXECOFFSETS", values, address, count );

        cpu_address_table_lookup( _environment, "EXECOFFSETS", count );        

    }

    Constant * c = _environment->constants;
    while( c ) {
        if ( c->valueString ) {
            int len = strlen( c->valueString->value );
            out2("%s: db %d,", c->realName, len);
            int i=0;
            for (i=0; i<(len-1); ++i ) {
                out1("$%2.2x,", (unsigned char)c->valueString->value[i]);
            }
            outline1("$%2.2x", (unsigned char)c->valueString->value[(len-1)]);
        }
        c = c->next;
    }

    generate_cgoto_address_table( _environment );

    banks_generate( _environment );
        
    for(i=0; i<BANK_TYPE_COUNT; ++i) {
        Bank * actual = _environment->banks[i];
        while( actual ) {
            if ( actual->type == BT_VARIABLES ) {
                // TODO: zx: management of banks' variables
                // outhead1("section %s", actual->name);
                // outline1("org $%4.4x", actual->address);
                Variable * variable = _environment->variables;

                variable_cleanup_entry( _environment, variable );
                variable_cleanup_entry_bit( _environment, variable );

            } else if ( actual->type == BT_TEMPORARY ) {
                // TODO: zx: management of banks' variables
                // outhead1("section %s", actual->name);
                // outline1("org $%4.4x", actual->address);

                for( int j=0; j< (_environment->currentProcedure+1); ++j ) {
                    Variable * variable = _environment->tempVariables[j];
                    variable_cleanup_entry( _environment, variable );
                    variable_cleanup_entry_bit( _environment, variable );
                } 

                Variable * variable = _environment->tempResidentVariables;

                variable_cleanup_entry( _environment, variable );
                variable_cleanup_entry_bit( _environment, variable );

            } else {

            }
           actual = actual->next;
        }
    }    

    variable_on_memory_init( _environment, 1 );

    DataSegment * dataSegment = _environment->dataSegment;
    while( dataSegment ) {
        int i=0;
        if ( dataSegment->data ) {
            out1("%s: db ", dataSegment->realName );
        } else {
            outhead1("%s: ", dataSegment->realName );
        }                
        DataDataSegment * dataDataSegment = dataSegment->data;
        while( dataDataSegment ) {
            if ( dataSegment->type ) {
                if ( dataDataSegment->type == VT_STRING || dataDataSegment->type == VT_DSTRING ) {
                    out1("$%2.2x,", (unsigned char)(dataDataSegment->size) );
                    out1("\"%s\"", dataDataSegment->data );
                } else {
                    for( i=0; i<(dataDataSegment->size-1); ++i ) {
                        out1("$%2.2x,", (unsigned char)(dataDataSegment->data[i]&0xff) );
                    }
                    out1("$%2.2x", (unsigned char)(dataDataSegment->data[i]&0xff) );
                }
            } else {
                if ( dataDataSegment->type == VT_STRING || dataDataSegment->type == VT_DSTRING ) {
                    out1("$%2.2x,", (unsigned char)(dataDataSegment->type) );
                    out1("$%2.2x,", (unsigned char)(dataDataSegment->size) );
                    out1("\"%s\"", dataDataSegment->data );
                } else {
                    out1("$%2.2x,", (unsigned char)(dataDataSegment->type) );
                    for( i=0; i<(dataDataSegment->size-1); ++i ) {
                        out1("$%2.2x,", (unsigned char)(dataDataSegment->data[i]&0xff) );
                    }
                    out1("$%2.2x", (unsigned char)(dataDataSegment->data[i]&0xff) );
                }
            }
            dataDataSegment = dataDataSegment->next;
            if ( dataDataSegment ) {
                out0(",");
            }
        }
        outline0("");
        dataSegment = dataSegment->next;
    }

    if ( _environment->dataNeeded || _environment->dataSegment || _environment->deployed.read_data_unsafe ) {
        outhead0("DATAPTRE:");
    }
    
    StaticString * staticStrings = _environment->strings;
    while( staticStrings ) {
        outline3("cstring%d: db %d, %s", staticStrings->id, (int)strlen(staticStrings->value), escape_newlines( staticStrings->value ) );
        staticStrings = staticStrings->next;
    }

    for( i=0; i<MAX_RESIDENT_SHAREDS; ++i ) {
        if ( _environment->maxExpansionBankSize[i] ) {
            outhead2("BANKWINDOW%2.2x: defs %d", i, _environment->maxExpansionBankSize[i]);
            outhead1("BANKWINDOWID%2.2x: db $FF, $FF", i );
        }
    }

    if ( _environment->bitmaskNeeded ) {
        outhead0("BITMASK: defm $01,$02,$04,$08,$10,$20,$40,$80");
        outhead0("BITMASKN: defm $fe,$fd,$fb,$f7,$ef,$df,$bf,$7f");
    }
    if ( _environment->deployed.dstring ) {
        outhead1("max_free_string = $%4.4x", _environment->dstring.space == 0 ? DSTRING_DEFAULT_SPACE : _environment->dstring.space );
    }

}
