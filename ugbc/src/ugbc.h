#ifndef __UGBASICCOMPILER__
#define __UGBASICCOMPILER__

/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

/*! @mainpage ugBASIC - REFERENCE MANUAL
 *
 * @section intro_sec Introduction
 *
 * This documentation is intended for anyone wishing to extend the compiler 
 * to include new instructions, new build targets, and support other hardware.
 * However, it is not suitable for those who simply want to use the ugBASIC 
 * language, for which you should refer to the [USER MANUAL](https://retroprogramming.iwashere.eu/ugbasic:user).
 */

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

/****************************************************************************
 * DECLARATIONS AND DEFINITIONS SECTION 
 ****************************************************************************/

/**
 * @brief Type of memory banks
 */
typedef enum _BankType {

    /** Executable code */
    BT_CODE = 0,

    /** Variables */
    BT_VARIABLES = 1,

    /** Temporary variables */
    BT_TEMPORARY = 2,

    /** Generic (unknonw) data */
    BT_DATA = 3,

    /** Strings (static and dynamic) */
    BT_STRINGS = 4

} BankType;

/**
 * @brief Maximum number of bank types
 */
#define BANK_TYPE_COUNT   5

/**
 * @brief Structure of a single bank
 */
typedef struct _Bank {

    /** Name of the bank */
    char * name;

    /** Starting address */
    int address;

    /** Bank type */
    BankType type;

    /** (optional) file name that will be loaded into the bank */
    char *filename;

    /** Link to the next bank (NULL if this is the last one) */
    struct _Bank * next;

} Bank;

typedef enum _OutputFileType {

    OUTPUT_FILE_TYPE_BIN = 0,
    OUTPUT_FILE_TYPE_PRG = 1,
    OUTPUT_FILE_TYPE_XEX = 2,
    OUTPUT_FILE_TYPE_K7_ORIGINAL = 3,
    OUTPUT_FILE_TYPE_K7_NEW = 4,
    OUTPUT_FILE_TYPE_TAP = 5

} OutputFileType;

/**
 * @brief Type of variables
 * 
 * @todo support for data type VT_STRING
 * @todo support for signed data type
 * @todo support for arrays
 */
typedef enum _VariableType {

    /** Single unsigned byte (8 bit) */
    VT_BYTE = 1,
    /** Single signed byte (7 bit w / 2 complement) */
    VT_SBYTE = 2,

    /** Single unsigned word (16 bit) */
    VT_WORD = 3,
    /** Single signed word (15 bit w / 2 complement) */
    VT_SWORD = 4,

    /** Single unsigned double word (32 bit) */
    VT_DWORD = 5,
    /** Single signed double word (31 bit w / 2 complement) */
    VT_SDWORD = 6,

    /** Memory address (16 bit) */
    VT_ADDRESS = 7,

    /** Ordinate or abscissa (8 bit or 16 bit) */
    VT_POSITION = 8,

    /** Color index (8 bit) */
    VT_COLOR = 9,

    /** Strings (static) */
    VT_STRING = 10,

    /** Static buffer of a specific size */
    VT_BUFFER = 11,

    /** Array of any kind */
    VT_ARRAY = 12,

    /** Strings (dynamic) */
    VT_DSTRING = 13,

    /** MOBs (Movable OBjects) */
    VT_MOB = 14,

    /** IMAGE (static picture) */
    VT_IMAGE = 15,

    /** THREAD ID */
    VT_THREAD = 16,

    /** IMAGES (static pictures) */
    VT_IMAGES = 17

} VariableType;

#define MAX_ARRAY_DIMENSIONS            256
#define MAX_PARAMETERS                  256
#define MAX_PALETTE                     256
#define MAX_NESTED_ARRAYS               16
#define MAX_PROCEDURES                  4096
#define DSTRING_DEFAULT_COUNT           255
#define DSTRING_DEFAULT_SPACE           1024

#define VT_BW_8BIT( t, v )              ( ( (t) == (v) ) ? 8 : 0 )
#define VT_BW_16BIT( t, v )             ( ( (t) == (v) ) ? 16 : 0 )
#define VT_BW_32BIT( t, v )             ( ( (t) == (v) ) ? 32 : 0 )

#define VT_BITWIDTH( t ) \
        ( VT_BW_8BIT( t, VT_BYTE ) + VT_BW_8BIT( t, VT_SBYTE ) + VT_BW_8BIT( t, VT_COLOR ) + VT_BW_8BIT( t, VT_THREAD ) + \
        VT_BW_16BIT( t, VT_WORD ) + VT_BW_16BIT( t, VT_SWORD ) + VT_BW_16BIT( t, VT_ADDRESS ) + VT_BW_16BIT( t, VT_POSITION ) + \
        VT_BW_32BIT( t, VT_DWORD ) + VT_BW_32BIT( t, VT_SDWORD ) )

#define VT_SIGNED( t ) \
        ( ( (t) == VT_SBYTE ) || ( (t) == VT_SWORD ) || ( (t) == VT_SDWORD ) || ( (t) == VT_POSITION ) )

#define VT_UNSIGN( t ) \
            ( VT_SIGNED( t ) ? \
                ( \
                    ( ( (t) == (VT_SBYTE) ) ? VT_BYTE : 0 ) + \
                    ( ( (t) == (VT_SWORD) ) ? VT_WORD : 0 ) + \
                    ( ( (t) == (VT_SDWORD) ) ? VT_DWORD : 0 ) + \
                    ( ( (t) == (VT_POSITION) ) ? VT_WORD : 0 ) \
                ) \
            : t )

#define VT_SIGN( t ) \
            ( ! VT_SIGNED( t ) ? \
                ( \
                    ( ( (t) == (VT_BYTE) ) ? VT_SBYTE : 0 ) + \
                    ( ( (t) == (VT_WORD) ) ? VT_SWORD : 0 ) + \
                    ( ( (t) == (VT_DWORD) ) ? VT_SDWORD : 0 ) \
                ) \
            : t )

#define VT_SIGN_8BIT( v ) ( v < 0 ? ( ((~(unsigned char)(abs(v)))+1 ) ) : (v) )
#define VT_SIGN_16BIT( v ) ( v < 0 ? ( ((~(unsigned short)(abs(v)))+1 ) ) : (v) )
#define VT_SIGN_32BIT( v ) ( v < 0 ? ( (~((unsigned int) (abs(v)))+1 ) ) : (v) )

#define VT_ESIGN_8BIT( t, v ) ( VT_SIGNED(t) ? VT_SIGN_8BIT(v) : (v) )
#define VT_ESIGN_16BIT( t, v ) ( VT_SIGNED(t) ? VT_SIGN_16BIT(v) : (v) ) 
#define VT_ESIGN_32BIT( t, v ) ( VT_SIGNED(t) ? VT_SIGN_32BIT(v) : (v) ) 

#define VT_USIGN_8BIT( v ) (char)( ( v & 0x80 ) ? -( ((~((unsigned char)v)))+1 ) : (v) )
#define VT_USIGN_16BIT( v ) (short)( ( v & 0x8000 ) ? -( ((~((unsigned short)v)))+1 ) : (v) )
#define VT_USIGN_32BIT( v ) (int)( ( v & 0x80000000 ) ? -( ((~((unsigned int)v)))+1 ) : (v) )

#define VT_UNSIGN_8BIT( t, v ) ( VT_SIGNED(t) ? VT_USIGN_8BIT(v) : (v) )
#define VT_UNSIGN_16BIT( t, v ) ( VT_SIGNED(t) ? VT_USIGN_16BIT(v) : (v) ) 
#define VT_UNSIGN_32BIT( t, v ) ( VT_SIGNED(t) ? VT_USIGN_32BIT(v) : (v) ) 

/**
 * @brief Maximum number of variable types
 */
#define VARIABLE_TYPE_COUNT   16

/**
 * @brief Enum for memory area type
 * 
 * This enum will describe the kind of memory area, if it is
 * accessible directly (so: it can be used for code and variable,
 * without limits) or it is "gated" through a specific prologue
 * and epilogue code.
 */
typedef enum _MemoryAreaType {

    /**
     * This memory area can be accessed directly. 
     */
    MAT_DIRECT = 1,

    /**
     * This memory area can be accessed only after calling a specific
     * prologue and epilogue code. 
     */
    MAT_GATED = 2

} MemoryAreaType;

typedef struct _MemoryArea {

    /**
     * Starting address
     */
    int start;

    /**
     * Ending address
     */
    int end;

    /**
     * Current available size
     */
    int size;

    /**
     * Type
     */
    MemoryAreaType type;

    /** Link to the next memory area (NULL if this is the last one) */
    struct _MemoryArea * next;

} MemoryArea;

#define MEMORY_AREA_DEFINE( _type, _start, _end ) \
    { \
        MemoryArea * memoryArea = malloc( sizeof( MemoryArea ) ); \
        memset( memoryArea, 0, sizeof( MemoryArea ) ) ; \
        memoryArea->start = _start; \
        memoryArea->end = _end; \
        memoryArea->size = (_end-_start); \
        memoryArea->type = _type; \
        memoryArea->next = NULL; \
        MemoryArea * last = _environment->memoryAreas; \
        if ( last ) { \
            while( last->next ) { \
                last = last->next; \
            } \
            last->next = memoryArea; \
        } else { \
            _environment->memoryAreas = memoryArea; \
        } \
    }


/**
 * @brief Structure of a single variable
 */
typedef struct _Variable {

    /** Name of the variable (in the program) */
    char * name;

    /** Real name (used for source generation) */
    char * realName;

    /** Only for temporary vars: the meaning for this variable */
    char * meaningName;

    /** Variable type */
    VariableType type;

    /** 
     * This flag mark if this variable is used (1) or not (0); 
     * it is valid only for temporary one. 
     */
    int used;

    /** 
     * This flag mark if this variable is locked (1) or not (0); 
     * it is valid only for temporary one and avoid to free
     * variables that are still used. 
     */
    int locked;

    /** 
     * This flag mark if this variable is imported by external ASM
     */
    int imported;

    /** 
     * This flag mark if this variable has been assigned.
     * If it is temporary MUST not be outputed as value.
     */
    int assigned;

    /** 
     * The initial value of the variable, as given by last (re)definition.
     */
    int value;

    /** 
     * The static string's valu, as given by last (re)definition.
     */
    char * valueString;

    /** 
     * The static buffer's value, as given by last (re)definition.
     */
    unsigned char * valueBuffer;

    /** 
     * The size of the static buffer (in bytes).
     */
    int size;

    /** 
     * The absolute address of this variable (if any).
     */
    int absoluteAddress;

    /** 
     * Pointer to the bank where this variable belongs to.
     */
    Bank * bank;

    /** 
     * Pointer to the memory area where this variable belongs to.
     */
    MemoryArea * memoryArea;

    /**
     * Number of dimensions of this array
     */
    int arrayDimensions;

    /**
     * Size of each dimension
     */
    int arrayDimensionsEach[MAX_ARRAY_DIMENSIONS];

    /** Variable type */
    VariableType arrayType;

    /** Is threaded? */
    int threaded;

    /** size of single frame (if IMAGES) */
    int frameSize;

    /** count of frames (if IMAGES) */
    int frameCount;

    /** Link to the next variable (NULL if this is the last one) */
    struct _Variable * next;

} Variable;

/**
 * @brief Structure of a single constant
 */
typedef struct _Constant {

    /** Name of the constant (in the program) */
    char * name;

    /** Real name (used for source generation) */
    char * realName;

    /** 
     * This flag mark if this variable is imported by external ASM
     */
    int imported;

    /** 
     * The initial (numeric) value of the variable, as given by last (re)definition.
     */
    int value;

    /** 
     * The initial (string) value of the variable, as given by last (re)definition.
     */
    char * valueString;

    /** Link to the next constant (NULL if this is the last one) */
    struct _Constant * next;

} Constant;

typedef struct _Procedure {

    /** Name of the procedure (in the program) */
    char * name;

    /**
     * Parameters definition
     */
    int parameters;

    /**
     * Parameters definition
     */
    char * parametersEach[MAX_PARAMETERS];

    /**
     * Parameters definition
     */
    VariableType parametersTypeEach[MAX_PARAMETERS];

    /**
     * Is a protothread?
     */
    int protothread;

    /** Link to the next procedure (NULL if this is the last one) */
    struct _Procedure * next;

} Procedure;

typedef struct _Offsetting {

    /**
     * Size of an element
     */
    int size;

    /**
     * Count of elements
     */
    int count;

    /** Link to the next offsetting */
    struct _Offsetting * next;

} Offsetting;

/**
 * @brief Types of conditional jumps supported.
 */
typedef enum _ConditionalType {
    /** IF ... THEN ... ENDIF */
    CT_IF = 0,

    /** ON ... GOTO ... */
    CT_ON_GOTO = 1,

    /** ON ... GOSUB ... */
    CT_ON_GOSUB = 2,

    /** ON ... PROC ... */
    CT_ON_PROC = 3

} ConditionalType;

/**
 * @brief Maximum number of conditional types
 */
#define CONDITIONAL_TYPE_COUNT   1

/**
 * @brief Structure of a single conditional jump.
 */
typedef struct _Conditional {

    /** Type of conditional */
    ConditionalType type;

    /** Label to jump. */
    char *label;

    /** Expression to evaluate. */
    Variable *expression;

    /** Incremental index for forced jumps. */
    int index;

    /** Next conditional */
    struct _Conditional * next;

} Conditional;

/**
 * @brief Types of loops supported.
 */
typedef enum _LoopType {
    /** DO ... LOOP */
    LT_DO = 0,

    /** WHILE ... WEND */
    LT_WHILE = 0,

    /** REPEAT ... UNTIL */
    LT_REPEAT = 0,

    /** FOR ... NEXT */
    LT_FOR = 0,

} LoopType;

/**
 * @brief Maximum number of loop types
 */
#define LOOP_TYPE_COUNT   1

/**
 * @brief Structure of a single loop.
 */
typedef struct _Loop {

    /** Type of conditional */
    LoopType type;

    /** Label to jump. */
    char *label;

    /** Variable with index. */
    Variable *index;

    /** Variable with to. */
    Variable *to;

    /** Variable with step. */
    Variable *step;

    /** Variable with zero (0). */
    Variable *zero;

    /** Next conditional */
    struct _Loop * next;

} Loop;

typedef struct _Pattern {

    char * pattern;

    /** Next pattern */
    struct _Pattern * next;

} Pattern;

typedef enum _Writing {

    WRITING_REPLACE = 0,
    WRITING_OR = 1,
    WRITING_XOR = 2,
    WRITING_AND = 3,
    WRITING_IGNORE = 4,

    WRITING_PAPER = 1,
    WRITING_PEN = 2,
    WRITING_NORMAL = 3

} Writing;

typedef struct _LoadedFile {

    char * fileName;

    Variable * variable;

    /** Next loaded file */
    struct _LoadedFile * next;

} LoadedFile;

typedef struct _ScreenMode {

    int         id;

    char *      description;

    int         bitmap;

    int         width;

    int         height;

    int         colors;

    int         score;

    struct _ScreenMode  * next;

} ScreenMode;

#define SCREEN_MODE_DEFINE( _id, _bitmap, _width, _height, _colors, _description ) \
    { \
        ScreenMode * screenMode = malloc( sizeof( ScreenMode ) ); \
        memset( screenMode, 0, sizeof( screenMode ) ) ; \
        screenMode->bitmap = _bitmap; \
        screenMode->id = _id; \
        screenMode->width = _width; \
        screenMode->height = _height; \
        screenMode->colors = _colors; \
        screenMode->score = 0; \
        screenMode->description = strdup( _description ); \
        screenMode->next = NULL; \
        ScreenMode * last = _environment->screenModes; \
        if ( last ) { \
            while( last->next ) { \
                last = last->next; \
            } \
            last->next = screenMode; \
        } else { \
            _environment->screenModes = screenMode; \
        } \
    }

/**
 * @brief Structure to store color components (red, green and blue)
 * 
 * This structure stores the color components (red, blue and green) 
 * of a pixel, 8 bits wide. This structure is used both to represent the 
 * retrocomputer palette and to process input data from image files.
 */
typedef struct _RGBi {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char index;
    unsigned char used;
} RGBi;

typedef struct _Embedded {

    int cpu_beq;
    int cpu_bneq;
    int cpu_busy_wait;
    int cpu_bveq;
    int cpu_bvneq;
    int cpu_combine_nibbles;
    int cpu_compare_16bit;
    int cpu_compare_32bit;
    int cpu_compare_8bit;
    int cpu_di;
    int cpu_ei;
    int cpu_inc;
    int cpu_inc_16bit;
    int cpu_inc_32bit;
    int cpu_dec;
    int cpu_dec_16bit;
    int cpu_less_than_16bit;
    int cpu_less_than_32bit;
    int cpu_less_than_8bit;
    int cpu_greater_than_16bit;
    int cpu_greater_than_32bit;
    int cpu_greater_than_8bit;
    int cpu_fill;
    int cpu_fill_blocks;
    int cpu_halt;
    int cpu_end;
    int cpu_jump;
    int cpu_call;
    int cpu_return;
    int cpu_pop;
    int cpu_label;
    int cpu_limit_16bit;
    int cpu_logical_not_8bit;
    int cpu_logical_and_8bit;
    int cpu_logical_or_8bit;
    int cpu_not_8bit;
    int cpu_and_8bit;
    int cpu_or_8bit;
    int cpu_not_16bit;
    int cpu_and_16bit;
    int cpu_or_16bit;
    int cpu_not_32bit;
    int cpu_and_32bit;
    int cpu_or_32bit;
    int cpu_math_add_16bit;
    int cpu_math_add_16bit_with_16bit;
    int cpu_math_add_16bit_with_8bit;
    int cpu_math_add_32bit;
    int cpu_math_add_8bit;
    int cpu_math_and_const_16bit;
    int cpu_math_and_const_32bit;
    int cpu_math_and_const_8bit;
    int cpu_math_complement_const_16bit;
    int cpu_math_complement_const_32bit;
    int cpu_math_complement_const_8bit;
    int cpu_math_div2_8bit;
    int cpu_math_div2_const_16bit;
    int cpu_math_div2_const_32bit;
    int cpu_math_div2_const_8bit;
    int cpu_math_double_16bit;
    int cpu_math_double_32bit;
    int cpu_math_double_8bit;
    int cpu_math_mul_16bit_to_32bit;
    int cpu_math_mul_8bit_to_16bit;
    int cpu_math_div_32bit_to_16bit;
    int cpu_math_div_16bit_to_16bit;
    int cpu_math_div_8bit_to_8bit;
    int cpu_math_mul2_const_16bit;
    int cpu_math_mul2_const_32bit;
    int cpu_math_mul2_const_8bit;
    int cpu_math_sub_16bit;
    int cpu_math_sub_32bit;
    int cpu_math_sub_8bit;
    int cpu_math_sub_16bit_with_8bit;
    int cpu_move_16bit;
    int cpu_addressof_16bit;
    int cpu_move_32bit;
    int cpu_move_8bit;
    int cpu_peek;
    int cpu_poke;
    int cpu_random;
    int cpu_random_16bit;
    int cpu_random_32bit;
    int cpu_random_8bit;
    int cpu_store_16bit;
    int cpu_store_32bit;
    int cpu_store_8bit;
    int cpu_mem_move;
    int cpu_mem_move_direct;
    int cpu_mem_move_size;
    int cpu_mem_move_direct_size;
    int cpu_mem_move_direct_indirect_size;
    int cpu_compare_memory;
    int cpu_compare_memory_size;
    int cpu_less_than_memory;
    int cpu_less_than_memory_size;
    int cpu_greater_than_memory;
    int cpu_greater_than_memory_size;
    int cpu_uppercase;
    int cpu_lowercase;
    int cpu_convert_string_into_16bit;
    int cpu_fill_indirect;
    int cpu_flip;
    int cpu_move_8bit_indirect;
    int cpu_move_8bit_indirect2;
    int cpu_move_16bit_indirect;
    int cpu_move_16bit_indirect2;
    int cpu_move_32bit_indirect;
    int cpu_move_32bit_indirect2;
    int cpu_bit_check;
    int cpu_number_to_string;
    int cpu_move_8bit_indirect_with_offset;
    int cpu_bits_to_string;
    int cpu_bit_check_extended;
    int cpu_move_8bit_indirect_with_offset2;
    int cpu_dsdefine;
    int cpu_dsalloc;
    int cpu_dsfree;
    int cpu_dswrite;
    int cpu_dsresize;
    int cpu_dsresize_size;
    int cpu_dsgc;
    int cpu_dsdescriptor;
    int cpu_move_8bit_with_offset;
    int cpu_move_8bit_with_offset2;
    int cpu_store_8bit_with_offset;
    int cpu_dsalloc_size;
    int cpu_complement2_8bit;
    int cpu_complement2_16bit;
    int cpu_complement2_32bit;
    int cpu_mobinit;
    int cpu_mobshow;
    int cpu_mobhide;
    int cpu_mobat;
    int cpu_mobrender;
    int cpu_sqroot;

} Embedded;

typedef struct _Deployed {

    int vbl;
    int joystick;
    int sqr;
    int back;
    int vars;
    int startup;
    int c6847startup;
    int c6847vars;
    int bitmap;
    int vic1vars;
    int vic1startup;
    int vic2vars;
    int vic2startup;
    int tedvars;
    int tedstartup;
    int anticstartup;
    int gtiastartup;
    int gtiavars;
    int zxvars;
    int ef936xvars;
    int ef936xstartup;
    int plot;
    int dstring;
    int scancode;
    int textEncodedAt;
    int numberToString;
    int bitsToString;
    int vScroll;
    int vScrollText;
    int textVScrollScreen;
    int cls;
    int textCline;
    int textHScroll;
    int textHScrollLine;
    int textHScrollScreen;
    int raster;
    int image;
    int mob;
    int mobcs;
    int protothread;

    Embedded embedded;

} Deployed;

typedef struct _DString {

    int count;
    int space;

} DString;

typedef struct _TileDescriptor {

    int whiteArea;
    int horizontalEdges[8];
    int verticalEdges[8];

} TileDescriptor;

typedef struct _TileData {

    char data[8];

} TileData;

typedef struct _TileDescriptors {

    int                 count;

    TileDescriptor *    descriptor[256];
    TileData            data[256];

} TileDescriptors;

/**
 * @brief Structure of compilation environment
 * 
 * @todo implement DEF FN
 * @todo implement PROCEDURE
 */
typedef struct _Environment {

    // TODO: implement DEF FN

    /* --------------------------------------------------------------------- */
    /* INPUT PARAMETERS                                                      */
    /* --------------------------------------------------------------------- */

    /**
     * Filename of BAS source (*.bas) 
     */
    char * sourceFileName;

    /**
     * Filename of ASM source (*.asm) 
     */
    char * asmFileName;

    /**
     * Filename of EXE source (extension depends on target and output format) 
     */
    char * exeFileName;

    /**
     * Filename of linker's configuration file (*.cfg) 
     */
    char * configurationFileName;

    /**
     * Filename of debugger's labels file (*.lb2) 
     */
    char * debuggerLabelsFileName;

    /**
     * Enable the visualization of warnings during compilation.
     */
    int warningsEnabled;

    /**
     * Enable the installation of chain tool.
     */
    int installChainTool;

    /**
     * List of embedded methods
     */
    Embedded embedded;

    /**
     * Stats about usage of embedded methods
     */
    Embedded embeddedStats;

    /**
     * 
     */
    DString dstring;

    /**
     * Type of output. 
     */
    OutputFileType outputFileType;

    /* --------------------------------------------------------------------- */
    /* INTERNAL STRUCTURES                                                   */
    /* --------------------------------------------------------------------- */

    /**
     * Current line parsed.
     */
    char * parsedLine;

    /**
     * Current line number in the BAS file.
     */
    int yylineno;

    /**
     * Last unique identification number 
     * (used for temporary variables and labels)
     */
    int uniqueId;

    /**
     * Set of banks defined during compilation. 
     * It contains all the banks, divided by type.
     */
    Bank * banks[BANK_TYPE_COUNT];

    ScreenMode * screenModes;

    /**
     * List of temporary (but not reusable) variables.
     */
    Variable * tempResidentVariables;

    /**
     * Current procedure (for temporary variables),
     * 0 = main program
     */
    int currentProcedure;
    
    /**
     * List of temporary (and reusable) variables (per procedure).
     */
    Variable * tempVariables[MAX_PROCEDURES];

    /**
     * List of constants defined in the program.
     */
    Constant * constants;

    /**
     * List of variables defined in the program.
     */
    Variable * variables;

    /**
     * List of procedures defined in the program.
     */
    Procedure * procedures;

    /**
     * List of variables defined in the procedure.
     */
    Variable * procedureVariables;

    /**
     * List of patterns for GLOBAL / SHARED variables
     */
    Pattern * globalVariablePatterns;

    /**
     * List of loaded files
     */
    LoadedFile * loadedFiles;

    /**
     * This flag marks if the program has opened a "game loop".
     */
    int hasGameLoop;

    /**
     * This flag marks if the program needs a BITMASK/BITMASKN temporary variable.
     */
    int bitmaskNeeded;

    /**
     * List of (currently opened) conditionals.
     */
    Conditional * conditionals;

    /**
     * List of (currently opened) loops.
     */
    Loop * loops;

    /**
     * "Every" status
     */
    Variable * everyStatus;

    /**
     * "Every" counter
     */
    Variable * everyCounter;

    /**
     * "Every" timing
     */
    Variable * everyTiming;

    /**
     * Memory areas available for the specific platform
     */
    MemoryArea * memoryAreas;

    /**
     * Current graphical mode
     */
    int currentMode;

    /**
     * Temporary storage for array definition
     */
    int arrayDimensions;

    /**
     * Temporary storage for array definition
     */
    int arrayDimensionsEach[MAX_ARRAY_DIMENSIONS];

    /**
     * Actual index of nested array access
     */
    int arrayNestedIndex;

    /**
     * Temporary storage for array access
     */
    int arrayIndexes[MAX_NESTED_ARRAYS];

    /**
     * Temporary storage for array access
     */
    char * arrayIndexesEach[MAX_NESTED_ARRAYS][MAX_ARRAY_DIMENSIONS];

    /**
     * Current procedure
     */
    char * procedureName;

    /**
     * Temporary storage for parameters definition
     */
    int parameters;

    /**
     * Temporary storage for parameters definition
     */
    char * parametersEach[MAX_PARAMETERS];

    /**
     * Temporary storage for parameters definition
     */
    VariableType parametersTypeEach[MAX_PARAMETERS];

    /**
     * Temporary storage for protothread definition
     */
    int protothread;

    /**
     * Has at least one parallel procedure?
     */
    int anyProtothread;

    /**
     * Step when resuming the protothread
     */
    int protothreadStep;
    
    /**
     * Screen width in pixels (statically determined)
     */
    int screenWidth;

    /**
     * Screen height in pixels (statically determined)
     */
    int screenHeight;

    /**
     * Screen width in characters (statically determined)
     */
    int screenTilesWidth;

    /**
     * Screen height in characters (statically determined)
     */
    int screenTilesHeight;

    /**
     * Font width in pixels (statically determined)
     */
    int fontWidth;

    /**
     * Font height in pixels (statically determined)
     */
    int fontHeight;

    /**
     * Deployed modules.
     */
    Deployed deployed;

    /**
     * Enable stats of embedded modules
     */

    int embeddedStatsEnabled;

    /**
     * If true, the body of procedure will not be produced
     */
    int emptyProcedure;

    /**
     * List of offset table to generate.
     */
    Offsetting * offsetting;

    TileDescriptors * descriptors;

    /* --------------------------------------------------------------------- */
    /* OUTPUT PARAMETERS                                                     */
    /* --------------------------------------------------------------------- */

    /**
     * Handle to the file opened to write the ASM source (*.asm).
     */
    FILE * asmFile;

    /**
     * Handle to the file opened to write the linker configuration file (*.cfg).
     */
    FILE * configurationFile;

    /**
     * Handle to the file opened to write the list of labels (*.lb2).
     */
    FILE * debuggerLabelsFile;

} Environment;

#define UNIQUE_ID   _environment->uniqueId++
#define MAKE_LABEL  char label[12]; sprintf( label, "_label%d", UNIQUE_ID);
#define CRITICAL( s ) fprintf(stderr, "CRITICAL ERROR during compilation of %s:\n\t%s at %d\n", ((struct _Environment *)_environment)->sourceFileName, s, ((struct _Environment *)_environment)->yylineno ); exit( EXIT_FAILURE );
#define CRITICAL2( s, v ) fprintf(stderr, "CRITICAL ERROR during compilation of %s:\n\t%s (%s) at %d\n", ((struct _Environment *)_environment)->sourceFileName, s, v, ((struct _Environment *)_environment)->yylineno ); exit( EXIT_FAILURE );
#define CRITICAL2i( s, v ) fprintf(stderr, "CRITICAL ERROR during compilation of %s:\n\t%s (%d) at %d\n", ((struct _Environment *)_environment)->sourceFileName, s, v, ((struct _Environment *)_environment)->yylineno ); exit( EXIT_FAILURE );
#define CRITICAL3( s, v1, v2 ) fprintf(stderr, "CRITICAL ERROR during compilation of %s:\n\t%s (%s, %s) at %d\n", ((struct _Environment *)_environment)->sourceFileName, s, v1, v2, ((struct _Environment *)_environment)->yylineno ); exit( EXIT_FAILURE );
#define CRITICAL4si( s, v, d1, d2 ) fprintf(stderr, "CRITICAL ERROR during compilation of %s:\n\t%s (%s, %d, %d) at %d\n", ((struct _Environment *)_environment)->sourceFileName, s, v, d1, d2, ((struct _Environment *)_environment)->yylineno ); exit( EXIT_FAILURE );
#define CRITICAL_UNIMPLEMENTED( v ) CRITICAL2("E000 - Internal method not implemented:", v );
#define CRITICAL_TEMPORARY2( v ) CRITICAL2("E001 - Unable to create space for temporary variable", v );
#define CRITICAL_VARIABLE( v ) CRITICAL2("E002 - Using of an undefined variable", v );
#define CRITICAL_DATATYPE_UNSUPPORTED( k, v ) CRITICAL3("E003 - Datatype not supported for keyword", k, v );
#define CRITICAL_CANNOT_CAST( t1, t2 ) CRITICAL3("E004 - Cannot cast types", t1, t2 );
#define CRITICAL_STORE_UNSUPPORTED( t ) CRITICAL2("E005 - Datatype cannot be stored directly", t );
#define CRITICAL_RESIZE_UNSUPPORTED( t ) CRITICAL2("E006 - Datatype cannot be resized directly", t );
#define CRITICAL_MOVE_NAKED_UNSUPPORTED( t ) CRITICAL2("E007 - Datatype cannot be copied directly", t );
#define CRITICAL_BUFFER_SIZE_MISMATCH( v1, v2 ) CRITICAL3("E008 - Buffer sizes mismatch -- cannot be copied", v1, v2 );
#define CRITICAL_DATATYPE_MISMATCH( v1, v2 ) CRITICAL3("E009 - Datatype mismatch", v1, v2 );
#define CRITICAL_ADD_UNSUPPORTED( v, t ) CRITICAL3("E010 - Add unsupported for variable of given datatype", v, t );
#define CRITICAL_SUB_UNSUPPORTED( v, t ) CRITICAL3("E011 - Sub unsupported for variable of given datatype", v, t );
#define CRITICAL_COMPLEMENT_UNSUPPORTED( v, t ) CRITICAL3("E012 - Complement unsupported for variable of given datatype", v, t );
#define CRITICAL_MUL_UNSUPPORTED( v, t ) CRITICAL3("E013 - Multiplication unsupported for variable of given datatype", v, t );
#define CRITICAL_DIV_UNSUPPORTED( v, t ) CRITICAL3("E014 - Division unsupported for variable of given datatype", v, t );
#define CRITICAL_CANNOT_COMPARE( t1, t2 ) CRITICAL3("E015 - Cannot compare types", t1, t2 );
#define CRITICAL_MUL2_UNSUPPORTED( v, t ) CRITICAL3("E016 - Double unsupported for variable of given datatype", v, t );
#define CRITICAL_DIV2_UNSUPPORTED( v, t ) CRITICAL3("E017 - Division by 2 unsupported for variable of given datatype", v, t );
#define CRITICAL_AND_UNSUPPORTED( v, t ) CRITICAL3("E018 - Bitwise AND unsupported for variable of given datatype", v, t );
#define CRITICAL_LEFT_UNSUPPORTED( v, t ) CRITICAL3("E019 - LEFT unsupported for variable of given datatype", v, t );
#define CRITICAL_RIGHT_UNSUPPORTED( v, t ) CRITICAL3("E020 - RIGHT unsupported for variable of given datatype", v, t );
#define CRITICAL_MID_UNSUPPORTED( v, t ) CRITICAL3("E021 - MID unsupported for variable of given datatype", v, t );
#define CRITICAL_INSTR_UNSUPPORTED( v, t ) CRITICAL3("E022 - INSTR unsupported for variable of given datatype", v, t );
#define CRITICAL_STRING_UNSUPPORTED( v, t ) CRITICAL3("E023 - STRING unsupported for variable of given datatype", v, t );
#define CRITICAL_UPPER_UNSUPPORTED( v, t ) CRITICAL3("E024 - UPPER unsupported for variable of given datatype", v, t );
#define CRITICAL_LOWER_UNSUPPORTED( v, t ) CRITICAL3("E025 - LOWER unsupported for variable of given datatype", v, t );
#define CRITICAL_STR_UNSUPPORTED( v, t ) CRITICAL3("E026 - STR unsupported for variable of given datatype", v, t );
#define CRITICAL_VAL_UNSUPPORTED( v, t ) CRITICAL3("E027 - VAL unsupported for variable of given datatype", v, t );
#define CRITICAL_CHR_UNSUPPORTED( v, t ) CRITICAL3("E028 - CHR unsupported for variable of given datatype", v, t );
#define CRITICAL_ASC_UNSUPPORTED( v, t ) CRITICAL3("E029 - ASC unsupported for variable of given datatype", v, t );
#define CRITICAL_LEN_UNSUPPORTED( v, t ) CRITICAL3("E030 - LEN unsupported for variable of given datatype", v, t );
#define CRITICAL_POW_UNSUPPORTED( v, t ) CRITICAL3("E031 - ^ unsupported for variable of given datatype", v, t );
#define CRITICAL_SGN_UNSUPPORTED( v, t ) CRITICAL3("E032 - SGN unsupported for variable of given datatype", v, t );
#define CRITICAL_ABS_UNSUPPORTED( v, t ) CRITICAL3("E033 - ABS unsupported for variable of given datatype", v, t );
#define CRITICAL_DEBUG_UNSUPPORTED( v, t ) CRITICAL3("E034 - DEBUG unsupported for variable of given datatype", v, t );
#define CRITICAL_ARRAY_SIZE_MISMATCH( v, d1, d2 ) CRITICAL4si("E035 - number of indexes different from array dimensions", v, d1, d2 );
#define CRITICAL_NOT_ARRAY( v ) CRITICAL2("E036 - accessing with indexes on a non array variable", v );
#define CRITICAL_PROCEDURE_NESTED_UNSUPPORTED( n ) CRITICAL2("E037 - cannot define a nested procedure (a procedure inside a procedure)", n ); 
#define CRITICAL_PROCEDURE_NOT_OPENED() CRITICAL("E038 - END PROC outside a procedure" ); 
#define CRITICAL_PROCEDURE_MISSING( n ) CRITICAL2("E039 - call to an undefined procedure", n ); 
#define CRITICAL_PROCEDURE_PARAMETERS_MISMATCH( n, d1, d2 ) CRITICAL4si("E040 - wrong number of parameters on procedure call", n, d1, d2 ); 
#define CRITICAL_SHARED_ONLY_IN_PROCEDURES() CRITICAL("E041 - SHARED can be used only inside a PROCEDURE");
#define CRITICAL_GLOBAL_ONLY_OUTSIDE_PROCEDURES() CRITICAL("E042 - GLOBAL can be used only outside a PROCEDURE");
#define CRITICAL_PRINT_UNSUPPORTED(v, t) CRITICAL3("E043 - PRINT unsupported for variable of given datatype", v, t );
#define CRITICAL_NOT_SUPPORTED( v ) CRITICAL2("E044 - Command / Keyword not supported:", v );
#define CRITICAL_BIT_UNSUPPORTED( v, t ) CRITICAL3("E045 - BIT unsupported for variable of given datatype", v, t );
#define CRITICAL_INPUT_UNSUPPORTED( v, t ) CRITICAL3("E046 - INPUT unsupported for variable of given datatype", v, t );
#define CRITICAL_MOVE_UNSUPPORTED( t ) CRITICAL2("E047 - Datatype cannot be copied", t );
#define CRITICAL_SCREEN_MODE_BITMAP_UNSUPPORTED( t ) CRITICAL2("E048 - Screen mode unsupported for BITMAP mode", t );
#define CRITICAL_SCREEN_MODE_TILEMAP_UNSUPPORTED( t ) CRITICAL2("E049 - Screen mode unsupported for TILEMAP mode", t );
#define CRITICAL_RANDOM_UNSUPPORTED(v, t) CRITICAL3("E050 - RANDOM unsupported for variable of given datatype", v, t );
#define CRITICAL_MOD_UNSUPPORTED(v, t) CRITICAL3("E051 - MOD unsupported for variable of given datatype", v, t );
#define CRITICAL_SCREEN_UNSUPPORTED(v) CRITICAL2i("E052 - SCREEN mode unsupported", v );
#define CRITICAL_LOAD_MISSING_FILE(f) CRITICAL2("E053 - LOAD missing file", f );
#define CRITICAL_LOAD_FILE_TOO_LONG(f) CRITICAL2("E054 - LOAD file too long (>255 bytes)", f );
#define CRITICAL_CANNOT_CAST_BUFFER_STRING_SIZE(a,b) CRITICAL3("E055 - Cannot cast BUFFER to STRING: buffer too long (>255 bytes)", a, b );
#define CRITICAL_IMAGE_LOAD_MISSING_FILE(f) CRITICAL2("E056 - IMAGE LOAD missing file", f );
#define CRITICAL_IMAGE_LOAD_UNKNOWN_FORMAT(f) CRITICAL2("E057 - IMAGE LOAD file format unknown", f );
#define CRITICAL_IMAGE_CONVERTER_UNSUPPORTED_MODE(f) CRITICAL2i("E058 - IMAGE converter unsupported for the given screen mode", f );
#define CRITICAL_IMAGE_CONVERTER_TOO_COLORS(f) CRITICAL2i("E059 - IMAGE converter unsupported -- too much colors", f );
#define CRITICAL_SQR_UNSUPPORTED( v, t ) CRITICAL3("E060 - SQR unsupported for variable of given datatype", v, t );
#define CRITICAL_UNDEFINED_CONSTANT( c ) CRITICAL2("E061 - use of an undefined constant", c );
#define CRITICAL_TYPE_MISMATCH_CONSTANT_NUMERIC( c ) CRITICAL2("E062 - use of an wrong type constant (numeric expected, string used)", c );
#define CRITICAL_IMAGE_CONVERTER_INVALID_WIDTH( w ) CRITICAL2i("E063 - invalid width for image, must be multiple of 8 pixels", w );
#define CRITICAL_IMAGE_CONVERTER_INVALID_HEIGHT( h ) CRITICAL2i("E064 - invalid height for image, must be multiple of 8 pixels", h );
#define CRITICAL_BIN_UNSUPPORTED( v, t ) CRITICAL3("E065 - BIN unsupported for variable of given datatype", v, t );
#define CRITICAL_MUL2_INVALID_STEPS( v ) CRITICAL2("E066 - invalid steps for multiplication by 2", v );
#define CRITICAL_UNABLE_TO_EMBED( v ) CRITICAL2("E067 - unable to embed library, only inline available", v );
#define CRITICAL_UNABLE_TO_INLINE( v ) CRITICAL2("E068 - unable to inline call, only library available", v );
#define CRITICAL_NOT_IMAGE( v ) CRITICAL2("E069 - variable is not an image", v );
#define CRITICAL_NOT_ASSIGNED_IMAGE( v ) CRITICAL2("E070 - variable is not an loaded image, please use assign operator", v );
#define CRITICAL_NEGATIVE_CONSTANT( v ) CRITICAL2("E071 - negative constant is not allowed", v);
#define CRITICAL_TOO_LITTLE_CONSTANT( v ) CRITICAL2("E072 - constant value under the minimum limit", v);
#define CRITICAL_TOO_BIG_CONSTANT( v ) CRITICAL2("E073 - constant value over the maximum limit", v);
#define CRITICAL_INVALID_STRING_COUNT( d ) CRITICAL2i("E074 - invalid maximum number of strings", d);
#define CRITICAL_INVALID_STRING_SPACE( d ) CRITICAL2i("E075 - invalid maximum space occupied by strings", d);
#define CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( c ) CRITICAL2("E076 - use of an wrong type constant (string expected, numeric used)", c );
#define CRITICAL_CANNOT_OPEN_EXECUTABLE_FILE( c )  CRITICAL2("E077 - cannot open executable file for post elaboration", c );
#define CRITICAL_PARALLEL_PROCEDURE_CANNOT_BE_CALLED( c ) CRITICAL2("E078 - cannot CALL a PARALLEL PROCEDURE: use SPAWN instead", c );
#define CRITICAL_PROCEDURE_CANNOT_BE_INVOKED( c ) CRITICAL2("E078 - cannot SPAWN a PROCEDURE: use CALL instead", c );
#define CRITICAL_LOCAL_VARIABLE_OUTSIDE_PROCEDURE( c )  CRITICAL2("E079 - cannot define LOCAL vars outside PARALLEL PROCEDURE", c );
#define CRITICAL_OR_UNSUPPORTED( v, t ) CRITICAL3("E080 - Bitwise OR unsupported for variable of given datatype", v, t );
#define CRITICAL_NOT_UNSUPPORTED( v, t ) CRITICAL3("E081 - Bitwise NOT unsupported for variable of given datatype", v, t );
#define CRITICAL_IMAGE_CONVERTER_INVALID_FRAME_WIDTH( w ) CRITICAL2i("E082 - invalid width for framed image, must be multiple of 8 pixels", w );
#define CRITICAL_IMAGE_CONVERTER_INVALID_FRAME_HEIGHT( h ) CRITICAL2i("E083 - invalid height for framed image, must be multiple of 8 pixels", h );
#define CRITICAL_IMAGE_CONVERTER_INVALID_OFFSET_X( x ) CRITICAL2i("E084 - invalid offset x for image, must be >= 0 and < width", x );
#define CRITICAL_IMAGE_CONVERTER_INVALID_OFFSET_Y( y ) CRITICAL2i("E085 - invalid offset y for image, must be >= 0 and < height", y );
#define CRITICAL_IMAGES_LOAD_INVALID_FRAME_WIDTH( w ) CRITICAL2i("E086 - invalid frame width, not multiple of width", w );
#define CRITICAL_IMAGES_LOAD_INVALID_FRAME_HEIGHT( h ) CRITICAL2i("E087 - invalid frame height, not multiple of height", h );
#define CRITICAL_PUT_IMAGE_UNSUPPORTED( v, t ) CRITICAL3("E088 - PUT IMAGE unsupported for given datatype", v, t );
#define CRITICAL_NOT_IMAGES( v ) CRITICAL2("E089 - variable is not an collection of images", v );
#define CRITICAL_NOT_ASSIGNED_IMAGES( v ) CRITICAL2("E090 - variable is not a loaded collection of images, please use assign operator", v );
#define CRITICAL_NOT_STRING_ARRAY( v ) CRITICAL2("E091 - accessing as a string array on a non string array", v );
#define CRITICAL_SIZE_UNSUPPORTED( v, t ) CRITICAL3("E092 - SIZE unsupported for variable of given datatype", v, t );
#define CRITICAL_UNSUPPORTED_OUTPUT_FILE_TYPE( t ) CRITICAL2("E093 - output file type format unsupported for this type of executable", t );
#define WARNING( s ) if ( ((struct _Environment *)_environment)->warningsEnabled) { fprintf(stderr, "WARNING during compilation of %s:\n\t%s at %d\n", ((struct _Environment *)_environment)->sourceFileName, s, ((struct _Environment *)_environment)->yylineno ); }
#define WARNING2( s, v ) if ( ((struct _Environment *)_environment)->warningsEnabled) { fprintf(stderr, "WARNING during compilation of %s:\n\t%s (%s) at %d\n", ((struct _Environment *)_environment)->sourceFileName, s, v, _environment->yylineno ); }
#define WARNING2i( s, v ) if ( ((struct _Environment *)_environment)->warningsEnabled) { fprintf(stderr, "WARNING during compilation of %s:\n\t%s (%i) at %d\n", ((struct _Environment *)_environment)->sourceFileName, s, v, _environment->yylineno ); }
#define WARNING3( s, v1, v2 ) if ( ((struct _Environment *)_environment)->warningsEnabled) { fprintf(stderr, "WARNING during compilation of %s:\n\t%s (%s, %s) at %d\n", ((struct _Environment *)_environment)->sourceFileName, s, v1, v2, _environment->yylineno ); }
#define WARNING_BITWIDTH( v1, v2 ) WARNING3("W001 - Multiplication could loose precision", v1, v2 );
#define WARNING_DOWNCAST( v1, v2 ) WARNING3("W002 - Implicit downcasting to less bitwidth (precision loss)", v1, v2 );
#define WARNING_SCREEN_MODE( v1 ) WARNING2i("W003 - Screen mode unsupported", v1 );
#define WARNING_USE_OF_UNDEFINED_ARRAY( v1 ) WARNING2("W004 - use of undefined array", v1 );

#define outline0n(n,s,r)     \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->asmFile); \
        if ( ((Environment *)_environment)->emptyProcedure ) { \
            fputs("\t; (excluded by ON target) : ", ((Environment *)_environment)->asmFile); \
        } \
        fputs(s,((Environment *)_environment)->asmFile); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->asmFile); \
    }

#define outline1n(n,s,a,r)   \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->asmFile); \
        if ( ((Environment *)_environment)->emptyProcedure ) { \
            fputs("\t; (excluded by ON target) : ", ((Environment *)_environment)->asmFile); \
        } \
        fprintf(((Environment *)_environment)->asmFile, s, a); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->asmFile); \
    }

#define outline2n(n,s,a,b,r)   \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->asmFile); \
        if ( ((Environment *)_environment)->emptyProcedure ) { \
            fputs("\t; (excluded by ON target) : ", ((Environment *)_environment)->asmFile); \
        } \
        fprintf(((Environment *)_environment)->asmFile, s, a, b); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->asmFile); \
    }

#define outline3n(n,s,a,b,c,r)   \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->asmFile); \
        if ( ((Environment *)_environment)->emptyProcedure ) { \
            fputs("\t; (excluded by ON target) : ", ((Environment *)_environment)->asmFile); \
        } \
        fprintf(((Environment *)_environment)->asmFile, s, a, b, c); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->asmFile); \
    }

#define outline4n(n,s,a,b,c,d,r)   \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->asmFile); \
        if ( ((Environment *)_environment)->emptyProcedure ) { \
            fputs("\t; (excluded by ON target) : ", ((Environment *)_environment)->asmFile); \
        } \
        fprintf(((Environment *)_environment)->asmFile, s, a, b, c, d); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->asmFile); \
    }

#define outline5n(n,s,a,b,c,d,e,r)   \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->asmFile); \
        if ( ((Environment *)_environment)->emptyProcedure ) { \
            fputs("\t; (excluded by ON target) : ", ((Environment *)_environment)->asmFile); \
        } \
        fprintf(((Environment *)_environment)->asmFile, s, a, b, c, d, e); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->asmFile); \
    }

#define cfgline0n(n,s,r)     \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->configurationFile); \
        fputs(s,((Environment *)_environment)->configurationFile); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->configurationFile); \
    }

#define cfgline1n(n,s,a,r)   \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->configurationFile); \
        fprintf(((Environment *)_environment)->configurationFile, s, a); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->configurationFile); \
    }

#define cfgline2n(n,s,a,b,r)   \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->configurationFile); \
        fprintf(((Environment *)_environment)->configurationFile, s, a, b); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->configurationFile); \
    }

#define cfgline3n(n,s,a,b,c,r)   \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->configurationFile); \
        fprintf(((Environment *)_environment)->configurationFile, s, a, b, c); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->configurationFile); \
    }

#define cfgline4n(n,s,a,b,c,d,r)   \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->configurationFile); \
        fprintf(((Environment *)_environment)->configurationFile, s, a, b, c, d); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->configurationFile); \
    }

#define cfgline5n(n,s,a,b,c,d,e,r)   \
    { \
        int outsi; \
        for(outsi=0; outsi<n; ++outsi) \
            fputs("\t", ((Environment *)_environment)->configurationFile); \
        fprintf(((Environment *)_environment)->configurationFile, s, a, b, c, d, e); \
        if ( r ) \
            fputs("\n", ((Environment *)_environment)->configurationFile); \
    }

#define outfile0(f)     \
    { \
        FILE * fh = fopen( f, "rt" ); \
        if ( fh ) { \
            char line[MAX_TEMPORARY_STORAGE]; \
            while( ! feof( fh ) ) { \
                if ( fgets( line, MAX_TEMPORARY_STORAGE, fh ) ) { \
                    fputs( line, ((Environment *)_environment)->asmFile); \
                } \
            } \
            fclose( fh ); \
            fputs("\n", ((Environment *)_environment)->asmFile); \
        } else { \
            CRITICAL2("Unable to include ugbasic system file", f ); \
        } \
    } 

#define outembedded0(e)     \
    { \
        fwrite( e, e##_len, 1, ((Environment *)_environment)->asmFile ); \
        fputs( "\n", ((Environment *)_environment)->asmFile ); \
    } 

#define outhead0(s)             outline0n(0, s, 1)
#define outhead1(s,a)           outline1n(0, s, a, 1)
#define outhead2(s,a,b)         outline2n(0, s, a, b, 1)
#define outhead3(s,a,b,c)       outline3n(0, s, a, b, c, 1)
#define outhead4(s,a,b,c,d)     outline4n(0, s, a, b, c, d, 1)
#define outhead5(s,a,b,c,d,e)   outline5n(0, s, a, b, c, d, e, 1)
#define outline0(s)             outline0n(1, s, 1)
#define outline1(s,a)           outline1n(1, s, a, 1)
#define outline2(s,a,b)         outline2n(1, s, a, b, 1)
#define outline3(s,a,b,c)       outline3n(1, s, a, b, c, 1)
#define outline4(s,a,b,c,d)     outline4n(1, s, a, b, c, d, 1)
#define outline5(s,a,b,c,d,e)   outline5n(1, s, a, b, c, d, e, 1)
#define out0(s)                 outline0n(0, s, 0)
#define out1(s,a)               outline1n(0, s, a, 0)
#define out2(s,a,b)             outline2n(0, s, a, b, 0)
#define out3(s,a,b,c)           outline3n(0, s, a, b, c, 0)
#define out4(s,a,b,c,d)         outline4n(0, s, a, b, c, d, 0)
#define out5(s,a,b,c,d,e)       outline5n(0, s, a, b, c, d, e, 0)

#define cfghead0(s)             cfgline0n(0, s, 1)
#define cfghead1(s,a)           cfgline1n(0, s, a, 1)
#define cfghead2(s,a,b)         cfgline2n(0, s, a, b, 1)
#define cfghead3(s,a,b,c)       cfgline3n(0, s, a, b, c, 1)
#define cfghead4(s,a,b,c,d)     cfgline4n(0, s, a, b, c, d, 1)
#define cfghead5(s,a,b,c,d,e)   cfgline5n(0, s, a, b, c, d, e, 1)
#define cfgline0(s)             cfgline0n(1, s, 1)
#define cfgline1(s,a)           cfgline1n(1, s, a, 1)
#define cfgline2(s,a,b)         cfgline2n(1, s, a, b, 1)
#define cfgline3(s,a,b,c)       cfgline3n(1, s, a, b, c, 1)
#define cfgline4(s,a,b,c,d)     cfgline4n(1, s, a, b, c, d, 1)
#define cfgline5(s,a,b,c,d,e)   cfgline5n(1, s, a, b, c, d, e 1)
#define cfg0(s)                 cfgline0n(0, s, 0)
#define cfg1(s,a)               cfgline1n(0, s, a, 0)
#define cfg2(s,a,b)             cfgline2n(0, s, a, b, 0)
#define cfg3(s,a,b,c)           cfgline3n(0, s, a, b, c, 0)
#define cfg4(s,a,b,c,d)         cfgline4n(0, s, a, b, c, d, 0)
#define cfg5(s,a,b,c,d,e)       cfgline5n(0, s, a, b, c, d, e, 0)

#define deploy(s,e)  \
        if ( ! _environment->deployed.s ) { \
            int ignoreEmptyProcedure = _environment->emptyProcedure; \
            _environment->emptyProcedure = 0; \
            cpu_jump( _environment, #s "_after" ); \
            outembedded0(e); \
            cpu_label( _environment, #s "_after" ); \
            _environment->emptyProcedure = ignoreEmptyProcedure; \
            _environment->deployed.s = 1; \
        }

#define deploy_with_vars(s,e,v)  \
        if ( ! _environment->deployed.s ) { \
            int ignoreEmptyProcedure = _environment->emptyProcedure; \
            _environment->emptyProcedure = 0; \
            cpu_jump( _environment, #s "_after" ); \
            outembedded0(e); \
            v(_environment);\
            cpu_label( _environment, #s "_after" ); \
            _environment->emptyProcedure = ignoreEmptyProcedure; \
            _environment->deployed.s = 1; \
        }

#define deploy_embedded(s,e)  \
        if ( ! _environment->deployed.embedded.s ) { \
            int ignoreEmptyProcedure = _environment->emptyProcedure; \
            _environment->emptyProcedure = 0; \
            cpu_jump( _environment, #s "_after" ); \
            outembedded0(e); \
            cpu_label( _environment, #s "_after" ); \
            _environment->emptyProcedure = ignoreEmptyProcedure; \
            _environment->deployed.embedded.s = 1; \
        }

#define inline(s) \
        _environment->embeddedStats.s++; \
        if ( !_environment->embedded.s ) {

#define no_inline(s) \
        if ( !_environment->embedded.s ) { \
            CRITICAL_UNABLE_TO_INLINE(#s); \

#define no_embedded(s) \
        } else { \
            CRITICAL_UNABLE_TO_EMBED(#s); \
        }

#define embedded(s,e) \
        } else { \
            deploy_embedded(s,e) \

#define done() \
        }

#define parse_embedded(p, s) \
    if ( strcmp( p, #s ) == 0 ) { \
        _environment->embedded.s = 1; \
    }

#define stats_embedded(s) \
    printf("%s:\t%d\t%s\t\n", #s, _environment->embeddedStats.s, _environment->embedded.s ? "embedded" : "inline" );

#define MAX_TEMPORARY_STORAGE   1024

#define WW_PEN              1
#define WW_PAPER            2

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            4

#define SHIFT_LEFT          1
#define SHIFT_RIGHT         2
#define SHIFT_CAPSLOCK      4
#define SHIFT_CONTROL       8
#define SHIFT_LEFT_ALT      16
#define SHIFT_RIGHT_ALT     32

#define TILEMAP_NATIVE      0
#define BITMAP_NATIVE       1

#define PROTOTHREAD_STATUS_WAITING		0
#define PROTOTHREAD_STATUS_RUNNING		1
#define PROTOTHREAD_STATUS_YIELDED		2
#define PROTOTHREAD_STATUS_EXITED		3
#define PROTOTHREAD_STATUS_ENDED		4

#define FLAG_FLIP_X         1
#define FLAG_FLIP_Y         2
#define FLAG_ROLL_X         4

#define FLAG_TRANSPARENCY   1

void setup_embedded( Environment *_environment );
void target_install( Environment *_environment );
void begin_compilation( Environment * _environment );
void target_initialization( Environment *_environment );
void target_finalization( Environment * _environment );
void end_compilation( Environment * _environment );
void target_peephole_optimizer( Environment * _environment );
void begin_build( Environment * _environment );
void target_linkage( Environment *_environment );
void target_cleanup( Environment *_environment );
void end_build( Environment * _environment );
void bank_cleanup( Environment * _environment );
void gameloop_cleanup( Environment * _environment );
void linker_cleanup( Environment * _environment );
void linker_setup( Environment * _environment );
int pattern_match( char * _pattern, char * _value );
void setup_text_variables( Environment * _environment );
ScreenMode * find_screen_mode_by_suggestion( Environment * _environment, int _bitmap, int _width, int _height, int _colors );
ScreenMode * find_screen_mode_by_id( Environment * _environment, int _id );
Bank * bank_find( Bank * _first, char * _name );

#define FUNCTION_STUB( t )   Variable * result = variable_temporary( _environment, t, "(stub)" ); return result;

//----------------------------------------------------------------------------
// *A*
//----------------------------------------------------------------------------

Variable *              absolute( Environment * _environment, char * _value );
void                    add_complex( Environment * _environment, char * _variable, char * _expression, char * _limit_lower, char * _limit_upper );

//----------------------------------------------------------------------------
// *B*
//----------------------------------------------------------------------------

void                    back( Environment * _environment, char * _color );
Bank *                  bank_define( Environment * _environment, char * _name, BankType _type, int _address, char * _filename );
void                    begin_for( Environment * _environment, char * _index, char * _from, char * _to );  
void                    begin_for_step( Environment * _environment, char * _index, char * _from, char * _to, char * _step );  
void                    begin_gameloop( Environment * _environment );
void                    begin_loop( Environment * _environment );
void                    begin_procedure( Environment * _environment, char * _name );
void                    begin_repeat( Environment * _environment );
void                    begin_while( Environment * _environment );
void                    begin_while_condition( Environment * _environment, char * _expression );
void                    bitmap_at( Environment * _environment, int _address );
void                    bitmap_at_var( Environment * _environment, char * _address );
void                    bitmap_clear( Environment * _environment );
void                    bitmap_clear_with( Environment * _environment, int _value );
void                    bitmap_clear_with_vars( Environment * _environment, char * _value );
void                    bitmap_disable( Environment * _environment );
void                    bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void                    box( Environment * _environment, char * _x1, char * _y1, char * _x2, char * _y2, char * _c );

//----------------------------------------------------------------------------
// *C*
//----------------------------------------------------------------------------

int                     calculate_nearest_tile( TileDescriptor * _tile, TileDescriptors * _tiles );
int                     calculate_exact_tile( TileDescriptor * _tile, TileDescriptors * _tiles );
int                     calculate_tile_affinity( TileDescriptor * _first, TileDescriptor * _second );
TileDescriptor *        calculate_tile_descriptor( TileData * _tileData );
void                    call_procedure( Environment * _environment, char * _name );
void                    center( Environment * _environment, char * _string );
void                    circle( Environment * _environment, char * _x, char * _y, char * _r, char *_c );
Variable *              clear_key( Environment * _environment );
void                    cline( Environment * _environment, char * _characters );
void                    clip( Environment * _environment, char * _x1, char * _y1, char * _x2, char * _y2 );
void                    cls( Environment * _environment, char * _paper );
void                    cmove( Environment * _environment, char * _dx, char * _dy );
void                    cmove_direct( Environment * _environment, int _dx, int _dy );
Variable *              collision_to( Environment * _environment, int _sprite );
Variable *              collision_to_vars( Environment * _environment, char * _sprite );
void                    color_background( Environment * _environment, int _index, int _background_color );
void                    color_background_vars( Environment * _environment, char * _index, char * _background_color );
void                    color_border( Environment * _environment, int _border_color );
void                    color_border_var( Environment * _environment, char * _border_color );
void                    color_sprite( Environment * _environment, int _index, int _color );
void                    color_sprite_vars( Environment * _environment, char * _sprite, char * _color );
void                    colormap_at( Environment * _environment, int _address );
void                    colormap_at_var( Environment * _environment, char * _address );
void                    colormap_clear( Environment * _environment );
void                    colormap_clear_with( Environment * _environment, int _foreground, int _background );
void                    colormap_clear_with_vars( Environment * _environment, char * _foreground, char * _background );
void                    const_define_numeric( Environment * _environment, char * _name, int _value );
void                    const_define_string( Environment * _environment, char * _name, char * _value );
void                    const_emit( Environment * _environment, char * _name );
Constant *              constant_find( Constant * _constant, char * _name );

//----------------------------------------------------------------------------
// *D*
//----------------------------------------------------------------------------

void                    draw( Environment * _environment, char * _x0, char * _y0, char * _x1, char * _y1, char * _c );

//----------------------------------------------------------------------------
// *E*
//----------------------------------------------------------------------------

void                    ellipse( Environment * _environment, char * _x, char * _y, char * _rx, char * _ry, char * _c );
void                    else_if_then( Environment * _environment, char * _expression );
void                    else_if_then_label( Environment * _environment );
void                    end( Environment * _environment );
void                    end_for( Environment * _environment );
void                    end_gameloop( Environment * _environment );
void                    end_if_then( Environment * _environment  );
void                    end_loop( Environment * _environment );
void                    end_procedure( Environment * _environment, char * _value );
void                    end_repeat( Environment * _environment, char * _expression );
void                    end_while( Environment * _environment );
void                    every_cleanup( Environment * _environment );
void                    every_off( Environment * _environment );
void                    every_on( Environment * _environment );
void                    every_ticks_call( Environment * _environment, char * _timing, char * _label );
void                    every_ticks_gosub( Environment * _environment, char * _timing, char * _label );
void                    exit_loop( Environment * _environment, int _number );
void                    exit_loop_if( Environment * _environment, char * _expression, int _number );
void                    exit_proc_if( Environment * _environment, char * _expression, char * _value );
void                    exit_procedure( Environment * _environment );

//----------------------------------------------------------------------------
// *F*
//----------------------------------------------------------------------------

int                     frames( Environment * _environment, char * _image );

//----------------------------------------------------------------------------
// *G*
//----------------------------------------------------------------------------

Variable *              get_at( Environment * _environment, char * _x, char * _y );
Variable *              get_cmove( Environment * _environment, char * _x, char * _y );
Variable *              get_cmove_direct( Environment * _environment, int _x, int _y );
Variable *              get_paper( Environment * _environment, char * _color );
Variable *              get_pen( Environment * _environment, char * _color );
Variable *              get_tab( Environment * _environment );
Variable *              get_timer( Environment * _environment );
void                    global( Environment * _environment );
void                    gosub_label( Environment * _environment, char * _label );
void                    gosub_number( Environment * _environment, int _number );
void                    goto_label( Environment * _environment, char * _label );
void                    goto_number( Environment * _environment, int _number );
void                    graphic( Environment * _environment );
void                    gr_locate( Environment * _environment, char * _x, char * _y );

//----------------------------------------------------------------------------
// *H*
//----------------------------------------------------------------------------

void                    halt( Environment * _environment );
Variable *              hit_to( Environment * _environment, int _sprite );
Variable *              hit_to_vars( Environment * _environment, char * _sprite );
void                    home( Environment * _environment );

//----------------------------------------------------------------------------
// *I*
//----------------------------------------------------------------------------

void                    if_then( Environment * _environment, char * _expression );
char *                  image_flip_x( Environment * _environment, char * _source, int _width, int _height );
char *                  image_flip_y( Environment * _environment, char * _source, int _width, int _height );
Variable *              image_load( Environment * _environment, char * _filename, char * _alias, int _mode, int _flags, int _transparent_color, int _background_color );
char *                  image_load_asserts( Environment * _environment, char * _filename );
Variable *              image_converter( Environment * _environment, char * _data, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _background_color );
void                    image_converter_asserts( Environment * _environment, int _width, int _height, int _offset_x, int _offset_y, int * _frame_width, int * _frame_height );
Variable *              image_get_height( Environment * _environment, char * _image );
Variable *              image_get_width( Environment * _environment, char * _image );
char *                  image_roll_x_left( Environment * _environment, char * _source, int _width, int _height );
char *                  image_roll_x_right( Environment * _environment, char * _source, int _width, int _height );
Variable *              images_load( Environment * _environment, char * _filename, char * _alias, int _mode, int _frame_width, int _frame_height, int _flags, int _transparent_color, int _background_color );
void                    ink( Environment * _environment, char * _expression );
Variable *              inkey( Environment * _environment );
void                    input( Environment * _environment, char * _variable );
Variable *              input_string( Environment * _environment, char * _size );

//----------------------------------------------------------------------------
// *J*
//----------------------------------------------------------------------------

Variable *              joy( Environment * _environment, char * _port );
Variable *              joy_direction( Environment * _environment, char * _port, int _direction );

//----------------------------------------------------------------------------
// *K*
//----------------------------------------------------------------------------

Variable *              keystate( Environment * _environment, char * _scancode );
Variable *              keyshift( Environment * _environment );

//----------------------------------------------------------------------------
// *L*
//----------------------------------------------------------------------------

Variable *              load( Environment * _environment, char * _filename, char * _alias, int _at );
void                    locate( Environment * _environment, char * _x, char * _y );
void                    loop( Environment * _environment, char *_label );

//----------------------------------------------------------------------------
// *M*
//----------------------------------------------------------------------------

Variable *              maximum( Environment * _environment, char * _source, char * _dest );
void                    memorize( Environment * _environment );
Variable *              minimum( Environment * _environment, char * _source, char * _dest );
void                    mob_at( Environment * _environment, char * _index, char * _x, char * _y );
void                    mob_hide( Environment * _environment, char * _index );
Variable *              mob_init( Environment * _environment, char * _image, char * _x, char * _y );
void                    mob_render( Environment * _environment, int _on_vbl );
void                    mob_show( Environment * _environment, char * _index );

//----------------------------------------------------------------------------
// *N*
//----------------------------------------------------------------------------

void                    next_raster( Environment * _environment );
void                    next_raster_at_with( Environment * _environment, int _at, char * _with );
void                    next_raster_at_with_var( Environment * _environment, char * _var, char * _with );

//----------------------------------------------------------------------------
// *O*
//----------------------------------------------------------------------------

void                    offsetting_size_count( Environment * _environment, int _size, int _count );
void                    on_gosub( Environment * _environment, char * _expression );
void                    on_gosub_end( Environment * _environment );
void                    on_gosub_index( Environment * _environment, char * _label );
void                    on_goto( Environment * _environment, char * _expression );
void                    on_goto_end( Environment * _environment );
void                    on_goto_index( Environment * _environment, char * _label );
void                    on_proc( Environment * _environment, char * _expression );
void                    on_proc_end( Environment * _environment );
void                    on_proc_index( Environment * _environment, char * _label );

//----------------------------------------------------------------------------
// *P*
//----------------------------------------------------------------------------

void                    paper( Environment * _environment, char * _paper );
Variable *              param_procedure( Environment * _environment, char * _name );
Variable *              parse_buffer_definition( Environment * _environment, char * _buffer, VariableType _type );
Variable *              peek( Environment * _environment, int _location );
Variable *              peek_var( Environment * _environment, char * _location );
void                    pen( Environment * _environment, char * _color );
void                    plot( Environment * _environment, char * _x, char * _y, char *_c );
Variable *              point( Environment * _environment, char * _x, char * _y );
void                    point_at( Environment * _environment, int _x, int _y );
void                    point_at_vars( Environment * _environment, char * _x, char * _y );
void                    poke_var( Environment * _environment, char * _address, char * _value );
void                    pop( Environment * _environment );
Variable *              powering( Environment * _environment, char * _source, char * _dest );
TileDescriptors *       precalculate_tile_descriptors_for_font( char * _fontData );
void                    print( Environment * _environment, char * _text, int _new_line );
void                    print_newline( Environment * _environment );
void                    print_question_mark( Environment * _environment );
void                    print_tab( Environment * _environment, int _new_line );
void                    put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, int _flags );

//----------------------------------------------------------------------------
// *Q*
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// *R*
//----------------------------------------------------------------------------

Variable *              random_height( Environment * _environment );
Variable *              random_value( Environment * _environment, VariableType _type );
Variable *              random_width( Environment * _environment );
void                    randomize( Environment * _environment, char * _seed );
void                    raster_at( Environment * _environment, char * _label, int _position );
void                    raster_at_var( Environment * _environment, char * _label, char * _position );
void                    remember( Environment * _environment );
void                    repeat( Environment * _environment, char *_label );
void                    return_label( Environment * _environment );
void                    return_procedure( Environment * _environment, char * _value );
Variable *              rnd( Environment * _environment, char * _value );
void                    run_parallel( Environment * _environment );

//----------------------------------------------------------------------------
// *S*
//----------------------------------------------------------------------------

Variable *              scancode( Environment * _environment );
Variable *              scanshift( Environment * _environment );
Variable *              screen_can( Environment * _environment, int _mode );
Variable *              screen_get_height( Environment * _environment );
Variable *              screen_get_width( Environment * _environment );
void                    screen_horizontal_scroll( Environment * _environment, int _displacement );
void                    screen_horizontal_scroll_var( Environment * _environment, char * _displacement );
void                    screen_mode( Environment * _environment, int _mode );
void                    screen_off( Environment * _environment );
void                    screen_on( Environment * _environment );
void                    screen_rows( Environment * _environment, int _rows );
void                    screen_rows_var( Environment * _environment, char * _rows );
Variable *              screen_tiles_get_height( Environment * _environment );
Variable *              screen_tiles_get_width( Environment * _environment );
void                    screen_vertical_scroll( Environment * _environment, int _displacement );
void                    screen_vertical_scroll_var( Environment * _environment, char * _displacement );
void                    set_timer( Environment * _environment, char * _value );
void                    shared( Environment * _environment );
Variable *              sign( Environment * _environment, char * _value );
Variable *              spawn_procedure( Environment * _environment, char * _name );
void                    sprite_color( Environment * _environment, int _sprite, int _color );
void                    sprite_color_vars( Environment * _environment, char * _sprite, char * _color );
void                    sprite_compress_horizontal( Environment * _environment, int _sprite );
void                    sprite_compress_horizontal_var( Environment * _environment, char * _sprite );
void                    sprite_compress_vertical( Environment * _environment, int _sprite );
void                    sprite_compress_vertical_var( Environment * _environment, char * _sprite );
void                    sprite_data_from( Environment * _environment, int _sprite, int _address );
void                    sprite_data_from_vars( Environment * _environment, char * _sprite, char * _address );
void                    sprite_disable( Environment * _environment, int _sprite );
void                    sprite_disable_var( Environment * _environment, char * _sprite );
void                    sprite_enable( Environment * _environment, int _sprite );
void                    sprite_enable_var( Environment * _environment, char * _sprite );
void                    sprite_expand_horizontal( Environment * _environment, int _sprite );
void                    sprite_expand_horizontal_var( Environment * _environment, char * _sprite );
void                    sprite_expand_vertical( Environment * _environment, int _sprite );
void                    sprite_expand_vertical_var( Environment * _environment, char * _sprite );
void                    sprite_monocolor( Environment * _environment, int _sprite );
void                    sprite_monocolor_var( Environment * _environment, char * _sprite );
void                    sprite_multicolor( Environment * _environment, int _sprite );
void                    sprite_multicolor_var( Environment * _environment, char * _sprite );
void                    sprite_at( Environment * _environment, int _sprite, int _x, int _y );
void                    sprite_at_vars( Environment * _environment, char * _sprite, char * _x, char * _y );
Variable *              sqroot( Environment * _environment, char * _value );

//----------------------------------------------------------------------------
// *T*
//----------------------------------------------------------------------------

void                    text_at( Environment * _environment, char * _x, char * _y, char * _text );
void                    text_encoded( Environment * _environment, char * _text, char * _pen, char * _paper );
Variable *              text_get_xcurs( Environment * _environment );
Variable *              text_get_ycurs( Environment * _environment );
void                    text_hscroll_line( Environment * _environment, int _direction );
void                    text_hscroll_screen( Environment * _environment, int _direction );
void                    text_newline( Environment * _environment );
void                    text_question_mark( Environment * _environment );
void                    text_set_tab( Environment * _environment, char * _net_tab );
void                    text_shade( Environment * _environment, int _value );
void                    text_tab( Environment * _environment );
void                    text_text( Environment * _environment, char * _text );
void                    text_under( Environment * _environment, int _value );
void                    text_vscroll( Environment * _environment );
void                    text_vscroll_screen( Environment * _environment, int _direction );
void                    textmap_at( Environment * _environment, int _address );
void                    textmap_at_var( Environment * _environment, char * _address );
void                    tilemap_disable( Environment * _environment );
void                    tilemap_enable( Environment * _environment, int _width, int _height, int _colors );
void                    tiles_at( Environment * _environment, int _address );
void                    tiles_at_var( Environment * _environment, char * _address );

//----------------------------------------------------------------------------
// *V*
//----------------------------------------------------------------------------

Variable *              variable_add( Environment * _environment, char * _source, char * _dest );
Variable *              variable_and( Environment * _environment, char * _left, char * _right );
Variable *              variable_and_const( Environment * _environment, char * _source, int _mask );
void                    variable_array_fill( Environment * _environment, char * _name, int _value );
Variable *              variable_array_type( Environment * _environment, char *_name, VariableType _type );
Variable *              variable_bin( Environment * _environment, char * _value, char * _digits );
Variable *              variable_bit( Environment * _environment, char * _value, char * _position );
Variable *              variable_cast( Environment * _environment, char * _source, VariableType _type );
void                    variable_cleanup( Environment * _Environment );
Variable *              variable_compare( Environment * _environment, char * _source, char * _dest );
Variable *              variable_compare_not( Environment * _environment, char * _source, char * _dest );
Variable *              variable_complement_const( Environment * _environment, char * _source, int _mask );
Variable *              variable_decrement( Environment * _environment, char * _source );
Variable *              variable_define( Environment * _environment, char * _name, VariableType _type, int _value );
Variable *              variable_define_no_init( Environment * _environment, char * _name, VariableType _type );
Variable *              variable_div( Environment * _environment, char * _source, char * _dest );
Variable *              variable_div2_const( Environment * _environment, char * _source, int _bits );
void                    variable_global( Environment * _environment, char * _pattern );
Variable *              variable_greater_than( Environment * _environment, char * _source, char * _dest, int _equal );
Variable *              variable_import( Environment * _environment, char * _name, VariableType _type );
Variable *              variable_increment( Environment * _environment, char * _source );
Variable *              variable_less_than( Environment * _environment, char * _source, char * _dest, int _equal );
Variable *              variable_mod( Environment * _environment, char * _source, char * _destination );
Variable *              variable_move( Environment * _environment, char * _source, char * _dest );
void                    variable_move_array( Environment * _environment, char * _array, char * _value  );
void                    variable_move_array_string( Environment * _environment, char * _array, char * _string  );
Variable *              variable_move_from_array( Environment * _environment, char * _array );
Variable *              variable_move_naked( Environment * _environment, char * _source, char * _dest );
Variable *              variable_mul( Environment * _environment, char * _source, char * _dest );
Variable *              variable_mul2_const( Environment * _environment, char * _source, int _bits );
Variable *              variable_not( Environment * _environment, char * _value );
Variable *              variable_or( Environment * _environment, char * _left, char * _right );
Variable *              variable_or( Environment * _environment, char * _source, char * _dest );
void                    variable_temporary_remove( Environment * _environment, char * _name );
void                    variable_reset( Environment * _environment );
Variable *              variable_resize_buffer( Environment * _environment, char * _destination, int _size );
int                     variable_exists( Environment * _environment, char * _name );
Variable *              variable_retrieve( Environment * _environment, char * _name );
Variable *              variable_retrieve_by_realname( Environment * _environment, char * _name );
Variable *              variable_retrieve_or_define( Environment * _environment, char * _name, VariableType _type, int _value );
Variable *              variable_store( Environment * _environment, char * _source, unsigned int _value );
Variable *              variable_store_buffer( Environment * _environment, char * _destination, unsigned char * _buffer, int _size, int _at );
Variable *              variable_store_string( Environment * _environment, char * _source, char * _string );
Variable *              variable_string_asc( Environment * _environment, char * _char );
Variable *              variable_string_chr( Environment * _environment, char * _ascii  );
Variable *              variable_string_flip( Environment * _environment, char * _string  );
Variable *              variable_string_instr( Environment * _environment, char * _search, char * _searched, char * _start );
Variable *              variable_string_left( Environment * _environment, char * _string, char * _position );
void                    variable_string_left_assign( Environment * _environment, char * _string, char * _position, char * _expression );
Variable *              variable_string_len( Environment * _environment, char * _string );
Variable *              variable_string_lower( Environment * _environment, char * _string );
Variable *              variable_string_mid( Environment * _environment, char * _string, char * _position, char * _len );
void                    variable_string_mid_assign( Environment * _environment, char * _string, char * _position, char * _len, char * _expression );
Variable *              variable_string_right( Environment * _environment, char * _string, char * _position );
void                    variable_string_right_assign( Environment * _environment, char * _string, char * _position, char * _expression );
Variable *              variable_string_space( Environment * _environment, char * _repetitions  );
Variable *              variable_string_str( Environment * _environment, char * _value );
Variable *              variable_string_string( Environment * _environment, char * _string, char * _repetitions  );
Variable *              variable_string_upper( Environment * _environment, char * _string );
Variable *              variable_string_val( Environment * _environment, char * _value );
Variable *              variable_sub( Environment * _environment, char * _source, char * _dest );
Variable *              variable_temporary( Environment * _environment, VariableType _type, char * _meaning );
Variable *              variable_resident( Environment * _environment, VariableType _type, char * _meaning );

//----------------------------------------------------------------------------
// *W*
//----------------------------------------------------------------------------

void                    wait_cycles( Environment * _environment, int _timing );
void                    wait_cycles_var( Environment * _environment, char * _timing );
void                    wait_key( Environment * _environment );
void                    wait_milliseconds( Environment * _environment, int _timing );
void                    wait_milliseconds_var( Environment * _environment, char * _timing );
void                    wait_ticks( Environment * _environment, int _timing );
void                    wait_ticks_var( Environment * _environment, char * _timing );
void                    wait_vbl( Environment * _environment );
void                    wait_until( Environment * _environment );
void                    wait_until_condition( Environment * _environment, char * _condition );
void                    wait_while( Environment * _environment );
void                    wait_while_condition( Environment * _environment, char * _condition );
void                    wait_parallel( Environment * _environment, char * _thread );
void                    writing( Environment * _environment, char * _mode, char * _parts );

//----------------------------------------------------------------------------
// *X*
//----------------------------------------------------------------------------

Variable *              xpen( Environment * _environment );

//----------------------------------------------------------------------------
// *Y*
//----------------------------------------------------------------------------

void                    yield( Environment * _environment );
Variable *              ypen( Environment * _environment );

#if defined(__atari__) 
    #include "../src-generated/modules_atari.h"
    #include "hw/6502.h"
    #include "hw/antic.h"
    #include "hw/gtia.h"
    #include "hw/atari.h"
#elif defined(__atarixl__) 
    #include "../src-generated/modules_atarixl.h"
    #include "hw/6502.h"
    #include "hw/antic.h"
    #include "hw/gtia.h"
    #include "hw/atari.h"
#elif __c64__
    #include "../src-generated/modules_c64.h"
    #include "hw/6502.h"
    #include "hw/vic2.h"
    #include "hw/c64.h"
#elif __plus4__
    #include "../src-generated/modules_plus4.h"
    #include "hw/6502.h"
    #include "hw/ted.h"
    #include "hw/plus4.h"
#elif __zx__
    #include "../src-generated/modules_zx.h"
    #include "hw/z80.h"
    #include "hw/zx.h"
#elif __d32__ 
    #include "../src-generated/modules_d32.h"
    #include "hw/6809.h"
    #include "hw/6847.h"
    #include "hw/d32.h"
#elif __d64__ 
    #include "../src-generated/modules_d64.h"
    #include "hw/6809.h"
    #include "hw/6847.h"
    #include "hw/d64.h"
#elif __pc128op__ 
    #include "../src-generated/modules_pc128op.h"
    #include "hw/6809.h"
    #include "hw/ef936x.h"
    #include "hw/pc128op.h"
#elif __mo5__ 
    #include "../src-generated/modules_mo5.h"
    #include "hw/6809.h"
    #include "hw/ef936x.h"
    #include "hw/mo5.h"
#elif __vic20__
    #include "../src-generated/modules_vic20.h"
    #include "hw/6502.h"
    #include "hw/vic1.h"
    #include "hw/vic20.h"
#endif

#endif