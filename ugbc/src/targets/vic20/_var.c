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

        if ( ( !variable->assigned || ( variable->assigned && !variable->temporary ) ) && !variable->imported ) {

            if ( variable->memoryArea && _environment->debuggerLabelsFile ) {
                fprintf( _environment->debuggerLabelsFile, "%4.4x %s\r\n", variable->absoluteAddress, variable->realName );
            }

            switch( variable->type ) {
                case VT_CHAR:
                case VT_BYTE:
                case VT_SBYTE:
                case VT_COLOR:
                case VT_THREAD:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        vars_emit_byte( _environment, variable->realName, variable->initialValue);
                    }        
                    break;
                case VT_DOJOKA:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s: .res 4,0", variable->realName);
                    }        
                    break;
                case VT_IMAGEREF:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s: .res 12,0", variable->realName);
                    }        
                    break;
                case VT_PATH:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s: .res 18,0", variable->realName);
                    }        
                    break;
                case VT_VECTOR2:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s: .res 4,0", variable->realName);
                    }        
                    break;
                case VT_WORD:
                case VT_SWORD:
                case VT_POSITION:
                case VT_ADDRESS:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        vars_emit_word( _environment, variable->realName, variable->initialValue);
                    }
                    break;
                case VT_DWORD:
                case VT_SDWORD:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        vars_emit_dword( _environment, variable->realName, variable->initialValue);
                    }
                    break;
               case VT_FLOAT:
                    if ( variable->memoryArea && !variable->bankAssigned != -1 ) {
                        // outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s: .res 4,0", variable->realName);
                    }
                    break;
                case VT_STRING:
                    outhead2("%s = cstring%d", variable->realName, variable->valueString->id );
                    break;
                case VT_DSTRING:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s: .res 1,0", variable->realName);
                    }
                    break;
                case VT_MSPRITE:
                case VT_SPRITE:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s: .res 1,0", variable->realName);
                    }
                    break;
                case VT_TILE:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s: .res 1,0", variable->realName);
                    }
                    break;
                case VT_TILESET:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s: .res 1,0", variable->realName);
                    }
                    break;
                case VT_TILES:
                    if ( variable->memoryArea ) {
                        outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s: .res 4,0", variable->realName);
                    }
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
                        outhead1("%s: .byte $0", variable->realName );
                    } else {
                        if ( ! variable->absoluteAddress ) {
                            if ( variable->valueBuffer ) {
                                if ( variable->printable ) {
                                    char * string = malloc( variable->size + 1 );
                                    memset( string, 0, variable->size + 1 );
                                    memcpy( string, variable->valueBuffer, variable->size );
                                    outhead2("%s: .byte %s", variable->realName, escape_newlines( string ) );
                                } else {
                                    out1("%s: .byte ", variable->realName);
                                    int i=0;
                                    for (i=0; i<(variable->size-1); ++i ) {
                                        if ( ( ( i + 1 ) % 16 ) == 0 ) {
                                            outline1("%d", variable->valueBuffer[i]);
                                            out0("   .byte  ");
                                        } else {
                                            out1("%d,", variable->valueBuffer[i]);
                                        }
                                    }
                                    outline1("%d", variable->valueBuffer[(variable->size-1)]);
                                }
                            } else {
                                outhead2("%s: .res %d,0", variable->realName, variable->size);
                            }
                        } else {
                            outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                            if ( variable->valueBuffer ) {
                                if ( variable->printable ) {
                                    char * string = malloc( variable->size + 1 );
                                    memset( string, 0, variable->size + 1 );
                                    memcpy( string, variable->valueBuffer, variable->size );
                                    outhead2("%scopy: .byte %s", variable->realName, escape_newlines( string ) );
                                } else {
                                    out1("%scopy: .byte ", variable->realName);
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
                            outhead2("%s: .res %d, $00", variable->realName, (VT_BITWIDTH( variable->arrayType )>>3) );
                        } else {
                            if (VT_BITWIDTH( variable->type ) == 0 ) {
                                CRITICAL_DATATYPE_UNSUPPORTED( "BANKED", DATATYPE_AS_STRING[ variable->type ] );
                            }
                            // force +1 byte if size is odd
                            outhead2("%s: .res %d, $00", variable->realName, (VT_BITWIDTH( variable->type )>>3) );
                        }
                    } else {

                        if ( variable->valueBuffer ) {
                            out1("%s: .byte ", variable->realName);
                            int i=0;
                            for (i=0; i<(variable->size-1); ++i ) {
                                out1("%d,", variable->valueBuffer[i]);
                            }
                            outline1("%d", variable->valueBuffer[(variable->size-1)]);
                        } else if ( variable->memoryArea && ! variable->value ) {
                            outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                        } else {
                            if ( variable->value ) {

                                switch( VT_BITWIDTH( variable->arrayType ) ) {
                                    case 32: {
                                        out1("%s: .byte ", variable->realName );
                                        for( int i=0; i<(variable->size/4)-1; ++i ) {
                                            out4("$%2.2x, $%2.2x, $%2.2x, $%2.2x, ", (unsigned int)( variable->value & 0xff ), (unsigned int)( ( variable->value >> 8 ) & 0xff ), (unsigned int)( ( variable->value >> 16 ) & 0xff ), (unsigned int)( ( variable->value >> 24 ) & 0xff ) );
                                        }
                                        out4("$%2.2x, $%2.2x, $%2.2x, $%2.2x", (unsigned int)( variable->value & 0xff ), (unsigned int)( ( variable->value >> 8 ) & 0xff ), (unsigned int)( ( variable->value >> 16 ) & 0xff ), (unsigned int)( ( variable->value >> 24 ) & 0xff ) );
                                        outline0("");
                                        break;
                                    }
                                    case 16: {
                                        out1("%s: .byte ", variable->realName );
                                        for( int i=0; i<(variable->size/2)-1; ++i ) {
                                            out2("$%2.2x, $%2.2x,", (unsigned int)( variable->value & 0xff ), (unsigned int)( ( variable->value >> 8 ) & 0xff ) );
                                        }
                                        out2("$%2.2x, $%2.2x", (unsigned int)( variable->value & 0xff ), (unsigned int)( ( variable->value >> 8 ) & 0xff ) );
                                        outline0("");
                                        break;
                                    }
                                    case 8:
                                        outhead3("%s: .res %d, $%2.2x", variable->realName, variable->size, (unsigned char)(variable->value&0xff) );
                                        break;
                                    case 1:
                                        outhead3("%s: .res %d, $%2.2x", variable->realName, variable->size, (unsigned char)(variable->value?0xff:0x00));
                                        break;
                                }                    
                                
                            } else {
                                outhead2("%s: .res %d, 0", variable->realName, variable->size);
                            }
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

    while( variable ) {

        if ( ( !variable->assigned || ( variable->assigned && !variable->temporary ) ) && !variable->imported && !variable->memoryArea ) {

            if ( variable->memoryArea && _environment->debuggerLabelsFile ) {
                fprintf( _environment->debuggerLabelsFile, "%4.4x %s\r\n", variable->absoluteAddress, variable->realName );
            }

            switch( variable->type ) {
                case VT_BIT:
                    if ( variable->memoryArea ) {
                        // outhead2("%s = $%4.4x", variable->realName, variable->absoluteAddress);
                    } else {
                        outhead1("%s:", variable->realName);
                    }
                    ++bitCount;
                    if ( bitCount == 8 ) {
                        outline0("   .res 1,0");
                    }        
                    break;
            }

        }

        variable = variable->next;

    }

    if ( bitCount > 0 ) {
        outline0("   .res 1,0");
    }

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
        outhead1("DATAFIRSTSEGMENT = %s", _environment->dataSegment->realName );
        if ( _environment->readDataUsed && _environment->restoreDynamic ) {
            outhead0("DATASEGMENTNUMERIC:" );
            DataSegment * actual = _environment->dataSegment;
            while( actual ) {
                if ( actual->isNumeric ) {
                    outline2( ".word $%4.4x, %s", actual->lineNumber, actual->realName );
                }
                actual = actual->next;
            }
            outline0( ".word $ffff, DATAPTRE" );
        }
    }
    
    if ( _environment->offsetting ) {
        Offsetting * actual = _environment->offsetting;
        while( actual ) {
            out1("OFFSETS%4.4x: .word ", actual->size );
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
                outline1("LDA #<OFFSETS%4.4x", actual->size );
                outline0("STA MATHPTR1" );
                outline1("LDA #>OFFSETS%4.4x", actual->size );
                outline0("STA MATHPTR1+1" );
                outline0("CLC" );
                outline0("LDA MATHPTR0" );
                outline0("ASL" );
                outline0("TAY" );
                outline0("LDA TMPPTR" );
                outline0("ADC (MATHPTR1), Y" );
                outline0("STA TMPPTR" );
                outline0("INY" );
                outline0("LDA TMPPTR+1" );
                outline0("ADC (MATHPTR1), Y" );
                outline0("STA TMPPTR+1" );
                outline0("RTS" );
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

    generate_cgoto_address_table( _environment );

    banks_generate( _environment );

    for(i=0; i<BANK_TYPE_COUNT; ++i) {
        Bank * actual = _environment->banks[i];
        while( actual ) {
            if ( actual->type == BT_VARIABLES ) {
                // cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                // cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
                // outhead1(".segment \"%s\"", actual->name);
                Variable * variable = _environment->variables;
                
                variable_cleanup_entry( _environment, variable );
                variable_cleanup_entry_bit( _environment, variable );

            } else if ( actual->type == BT_TEMPORARY ) {
                // cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
                // cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
                // outhead1(".segment \"%s\"", actual->name);

                for( int j=0; j< (_environment->currentProcedure+1); ++j ) {
                    Variable * variable = _environment->tempVariables[j];
                    variable_cleanup_entry( _environment, variable );
                    variable_cleanup_entry_bit( _environment, variable );
                }
                
                Variable * variable = _environment->tempResidentVariables;

                variable_cleanup_entry( _environment, variable );
                variable_cleanup_entry_bit( _environment, variable );

            // } else if ( actual->type == BT_STRINGS ) {
            //     cfgline3("# BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[actual->type], actual->name, actual->address);
            //     cfgline2("%s:   load = MAIN,     type = ro,  optional = yes, start = $%4.4x;", actual->name, actual->address);
            } else {

            }
           actual = actual->next;
        }
    }

    if ( ( _environment->program.startingAddress < 0x2000 ) ) {
        CRITICAL_INVALID_PROGRAM_START( _environment->program.startingAddress );
    }

    buffered_push_output( _environment );

    char buffer[32];
    sprintf( buffer, "%5.5d", _environment->program.startingAddress );

    outhead0(".segment \"BASIC\"");
    outline0(".byte $01, $12, $0B, $12, $00, $00, $9E" );
    outline5(".byte $%2.2x,$%2.2x,$%2.2x,$%2.2x,$%2.2x",
        buffer[0],
        buffer[1],
        buffer[2],
        buffer[3],
        buffer[4]
    );
    outline0(".byte $00,$00,$00,$00" );
    outhead0(".segment \"CODE\"");
    outline0("NOP");
    outline0("NOP");
    outline0("JMP CODESTART")

    deploy_inplace( vars, src_hw_vic20_vars_asm );
    deploy_inplace_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy_inplace_preferred( vScrollTextUp, src_hw_vic1_vscroll_text_up_asm );
    deploy_inplace_preferred( vScrollTextDown, src_hw_vic1_vscroll_text_down_asm );
    deploy_inplace_preferred( textHScroll, src_hw_vic1_hscroll_text_asm );

    variable_on_memory_init( _environment, 0 );

    DataSegment * dataSegment = _environment->dataSegment;
    while( dataSegment ) {
        int i=0;
        if ( dataSegment->data ) {
            out1("%s: .BYTE ", dataSegment->realName );
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
        outhead3("cstring%d: .byte %d, %s", staticStrings->id, (int)strlen(staticStrings->value), escape_newlines( staticStrings->value ) );
        staticStrings = staticStrings->next;
    }

    if ( _environment->descriptors ) {
        outhead0(".segment \"UDCCHAR\"" );
        int i=0,j=0;
        for(i=0;i<_environment->descriptors->firstFree;++i) {
            outline1("; $%2.2x ", i);
            out0(".byte " );
            for(j=0;j<7;++j) {
                out1("$%2.2x,", ((unsigned char)_environment->descriptors->data[i].data[j]) );
            }
            outline1("$%2.2x", ((unsigned char)_environment->descriptors->data[i].data[j]) );

        }
        outhead0(".segment \"CODE\"" );
        outhead0("TILESETSLOTUSED: ");
        for(j=0;j<8;++j) {
            int k;
            out0("   .byte " );
            for(k=0;k<31;++k) {
                if ( (k*8) < _environment->descriptors->firstFree ) {
                    out0("$FF,");
                } else {
                    out0("$00,");
                }
            }
            outline0("$00");
        }
        outhead0("TILESETSLOTATTRIBUTE: ");
        out0("   .byte " );
        for(j=0;j<255;++j) {
            int k;
            if ( j < _environment->descriptors->firstFree ) {
                out0("$07,");
            } else {
                out0("$00,");
            }
        }
        outline0("$00");
    } else {
        outhead0("TILESETSLOTUSED: .res 256, $00 ");
        outhead0("TILESETSLOTATTRIBUTE: .res 256, $00 ");
    }

    for( i=0; i<MAX_RESIDENT_SHAREDS; ++i ) {
        if ( _environment->maxExpansionBankSize[i] ) {
            outhead1("BANKWINDOWID%2.2x: .byte $FF, $FF", i );
            outhead2("BANKWINDOW%2.2x: .res %d,0", i, _environment->maxExpansionBankSize[i]);
        }
    }

    if ( _environment->bitmaskNeeded ) {
        outhead0("BITMASK: .byte $01,$02,$04,$08,$10,$20,$40,$80");
        outhead0("BITMASKN: .byte $fe,$fd,$fb,$f7,$ef,$df,$bf,$7f");
    }
    if ( _environment->deployed.dstring ) {
        outhead1("max_free_string = $%4.4x", _environment->dstring.space == 0 ? DSTRING_DEFAULT_SPACE : _environment->dstring.space );
    }

}
