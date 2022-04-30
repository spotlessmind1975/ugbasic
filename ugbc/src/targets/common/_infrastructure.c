/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
#include <math.h>
#include <ctype.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#define strcmp_nocase strcasecmp

extern RGBi SYSTEM_PALETTE[];

/**
 * @brief Description of BANK TYPE, in readable format
 */
char BANK_TYPE_AS_STRING[][16] = {
    "CODE", 
    "VARIABLES",
    "TEMPORARY",
    "DATA",
    "STRINGS"
};

char DATATYPE_AS_STRING[][16] = {
    "",
    "BYTE",
    "SBYTE",
    "WORD",
    "SWORD",
    "DWORD",
    "SDWORD",
    "ADDRESS",
    "POSITION",
    "COLOR",
    "STATIC STRING",
    "BUFFER",
    "ARRAY",
    "DYNAMIC STRING",   
    "MOB",  
    "IMAGE",
    "THREAD",
    "IMAGES",
    "CHAR",
    "SPRITE",
    "TILE",
    "TILES",
    "TILESET"
};

char OUTPUT_FILE_TYPE_AS_STRING[][16] = {
    "bin",
    "prg",
    "xex",
    "k7 (original)",
    "k7 (new)",
    "tap",
    "rom"
};

void memory_area_assign( MemoryArea * _first, Variable * _variable ) {

    int neededSpace = 0;

    if ( _variable->type == VT_ARRAY ) {
        neededSpace = _variable->size;
    } else if ( _variable->type == VT_DSTRING ) {
        neededSpace = 1;
    } else {
        neededSpace = VT_BITWIDTH( _variable->type ) ? ( VT_BITWIDTH( _variable->type ) >> 3 ) : _variable->size;   
    }

    if ( neededSpace == 0 ) return;

    MemoryArea * actual = _first;
    while( actual ) {
        int enoughSpace = actual->size > neededSpace;
        if ( actual->type == MAT_RAM ) {
            if ( _variable->type == VT_STRING || _variable->type == VT_BUFFER || _variable->type == VT_IMAGE || _variable->type == VT_IMAGES || _variable->type == VT_SEQUENCE || _variable->type == VT_MUSIC ) {
                enoughSpace = 0;
            }
        }
        if ( enoughSpace ) {
            actual->size -= neededSpace;
            _variable->memoryArea = actual;
            _variable->absoluteAddress = actual->current;
            actual->current += neededSpace;
            break;
        }
        actual = actual->next;
    }

}

Bank * bank_find( Bank * _first, char * _name ) {
    Bank * actual = _first;
    while( actual ) {
        if ( strcmp( actual->name, _name ) == 0 ) {
            break;
        }
        actual = actual->next;
    }
    return actual;
}

static void variable_reset_pool( Environment * _environment, Variable * _pool ) {
    Variable * actual = _pool;
    while( actual ) {
        if ( actual->locked == 0 ) {
            if ( actual->used && actual->type != VT_DSTRING ) {
                // outline0("; variable reset pool");
                actual->used = 0;       
                // cpu_dsfree( _environment, actual->realName );
            }     
        }
        actual = actual->next;
    }
}

static Variable * variable_find_by_realname( Variable * _first, char * _name ) {

    Variable * actual = _first;
    while( actual ) {
        if ( strcmp( actual->realName, _name ) == 0 ) {
            break;
        }
        actual = actual->next;
    }
    return actual;
}

static Variable * variable_find( Variable * _first, char * _name ) {

    Variable * actual = _first;
    while( actual ) {
        if ( strcmp( actual->name, _name ) == 0 ) {
            break;
        }
        actual = actual->next;
    }
    return actual;
}

static void variable_remove( Variable * _first, char * _name ) {

    Variable * previous = NULL;
    Variable * actual = _first;
    while( actual ) {
        if ( strcmp( actual->name, _name ) == 0 ) {
            break;
        }
        previous = actual;
        actual = actual->next;
    }
    if ( previous ) {
        previous->next = actual->next;
    } else {
        _first->next = actual->next;
    }

}

static Variable * variable_find_first_unused( Variable * _first, VariableType _type ) {
    Variable * actual = _first;
    while( actual ) {
        if ( actual->used || ( actual->type != _type )  ) {
            actual = actual->next;
        } else {
            break;
        }
    }
    return actual;
}

static Constant * constant_find_by_realname( Constant * _first, char * _name ) {

    Constant * actual = _first;
    while( actual ) {
        if ( strcmp( actual->realName, _name ) == 0 ) {
            break;
        }
        actual = actual->next;
    }
    return actual;
}

Constant * constant_find( Constant * _first, char * _name ) {

    Constant * actual = _first;
    while( actual ) {
        if ( strcmp( actual->name, _name ) == 0 ) {
            break;
        }
        actual = actual->next;
    }
    return actual;
}

static Offsetting * offsetting_by_size( Offsetting * _first, int _size ) {

    Offsetting * actual = _first;
    while( actual ) {
        if ( actual->size == _size ) {
            break;
        }
        actual = actual->next;
    }
    return actual;
}

void offsetting_size_count( Environment * _environment, int _size, int _count ) {

    Offsetting * actual = offsetting_by_size( _environment->offsetting, _size );
    if ( ! actual ) {
        actual = malloc( sizeof( Offsetting ) );
        memset( actual, 0, sizeof( Offsetting ) );
        actual->size = _size;
        actual->count = _count;
        actual->next = _environment->offsetting;
        _environment->offsetting = actual;
    } else {
        if ( actual->count < _count ) {
            actual->count = _count;
        }
    }

}

void variable_global( Environment * _environment, char * _pattern ) {

    Pattern * pattern = malloc( sizeof( Pattern ) ) ;
    memset( pattern, 0, sizeof( Pattern ) );

    pattern->pattern = strdup( _pattern );
    pattern->next = _environment->globalVariablePatterns;
    _environment->globalVariablePatterns = pattern;

}

/**
 * @brief Define a variable for the program
 * 
 * This function is necessary to define a variable within the program. This
 * call reserves a space compatible with the given variable type, and 
 * assigns it to the given name. The initial value of the variable is 
 * also passed.
 * 
 * Allowed types:
 * 
 * - `VT_CHAR` (<b>CHAR</b>)
 * - `VT_BYTE` (<b>BYTE</b>)
 * - `VT_COLOR` (<b>COLOR</b>)
 * - `VT_WORD` (<b>WORD</b>)
 * - `VT_ADDRESS` (<b>ADDRESS</b>)
 * - `VT_POSITION` (<b>POSITION</b>)
 * - `VT_DWORD` (<b>DWORD</b>)
 * 
 * It is possible to call the function several times with the same variable 
 * name: a single memory space will always be reserved. If the type differs, 
 * an exception will be thrown.
 * Note that the variable will be defined in the last bank defined 
 * by the <b>BANK</b> command as <b>VARIABLES</b>. In other words, it is possible 
 * to define different variables in different banks, thus optimizing 
 * the space occupied by the program.
 * 
 * @param _environment Current calling environment
 * @param _name Name of the variable to define
 * @param _type Type of the variable to define
 * @param _value Inital valure
 * @return Variable* The variable definition
 * @throw EXIT_FAILURE "Variable redefined with a different type"
 */
/* <usermanual>
@keyword VAR

@english
Define a variable [name] on bank [bank]. Optionally,
you can assign to that variable a value given by [expression].

@italian
Definisci una variabile [name] sul banko [bank]. Eventualmente,
è possibile assegnare alla variabile il valore dell'espressione
[expression].

@syntax VAR [name] ON [bank] { = [expression] }

@example VAR x ON bank1 = #$42

@seeAlso BANK

@target all

 </usermanual> */

Variable * variable_define( Environment * _environment, char * _name, VariableType _type, int _value ) {

    Variable * var = variable_find( _environment->variables, _name );
    if ( var ) {
        if ( var->type != _type ) {
            CRITICAL( "Variable redefined with a different type");
        }
        var->value = _value;
    } else {
        var = malloc( sizeof( Variable ) );
        memset( var, 0, sizeof( Variable ) );
        var->name = strdup( _name );
        var->realName = malloc( strlen( _name ) + strlen( var->name ) + 2 ); strcpy( var->realName, "_" ); strcat( var->realName, var->name );
        var->type = _type;
        var->value = _value;
        var->bank = _environment->banks[BT_VARIABLES];
        Variable * varLast = _environment->variables;
        if ( varLast ) {
            while( varLast->next ) {
                varLast = varLast->next;
            }
            varLast->next = var;
        } else {
            _environment->variables = var;
        }
        if ( var->type == VT_ARRAY ) {
            memcpy( var->arrayDimensionsEach, ((struct _Environment *)_environment)->arrayDimensionsEach, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
            var->arrayDimensions = ((struct _Environment *)_environment)->arrayDimensions;
        }
        // switch( var->type ) {
        //     case VT_STRING:
        //     case VT_DSTRING:
        //     case VT_MOB:
        //     case VT_BUFFER:
        //     case VT_IMAGE:
        //     case VT_IMAGES:
        //     case VT_ARRAY:
        //         break;
        //     default:
        //         ;
        //         // variable_store( _environment, var->name, _value );
        // }
        memory_area_assign( _environment->memoryAreas, var );
    }
    var->used = 1;
    var->locked = 0;
    return var;
}

Variable * variable_import( Environment * _environment, char * _name, VariableType _type, int _size_or_value ) {

    Variable * var = variable_find( _environment->variables, _name );
    if ( var ) {
        if ( var->type != _type ) {
            CRITICAL( "Variable imported with a different type");
        }
    } else {
        var = malloc( sizeof( Variable ) );
        memset( var, 0, sizeof( Variable ) );
        var->name = strdup( _name );
        var->realName = strdup( _name );
        var->type = _type;
        if ( var->type == VT_BUFFER ) {
            var->size = _size_or_value;
        } else {
            var->value = _size_or_value;
        }
        var->bank = NULL;
        Variable * varLast = _environment->variables;
        if ( varLast ) {
            while( varLast->next ) {
                varLast = varLast->next;
            }
            varLast->next = var;
        } else {
            _environment->variables = var;
        }
    }
    var->imported = 1;
    var->used = 1;
    var->locked = 1;
    return var;
}

Variable * variable_define_no_init( Environment * _environment, char * _name, VariableType _type ) {

    Variable * var = variable_find( _environment->variables, _name );
    if ( var ) {
        if ( var->type != _type ) {
            CRITICAL( "Variable redefined with a different type");
        }
    } else {
        var = malloc( sizeof( Variable ) );
        memset( var, 0, sizeof( Variable ) );
        var->name = strdup( _name );
        var->realName = malloc( strlen( _name ) + strlen( var->name ) + 2 ); strcpy( var->realName, "_" ); strcat( var->realName, var->name );
        var->type = _type;
        var->bank = _environment->banks[BT_VARIABLES];
        Variable * varLast = _environment->variables;
        if ( varLast ) {
            while( varLast->next ) {
                varLast = varLast->next;
            }
            varLast->next = var;
        } else {
            _environment->variables = var;
        }
        if ( var->type == VT_ARRAY ) {
            memcpy( var->arrayDimensionsEach, ((struct _Environment *)_environment)->arrayDimensionsEach, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
            var->arrayDimensions = ((struct _Environment *)_environment)->arrayDimensions;
        }
        memory_area_assign( _environment->memoryAreas, var );
    }
    var->used = 1;
    var->locked = 0;
    return var;
}

Variable * variable_define_local( Environment * _environment, char * _name, VariableType _type, int _value ) {

    Variable * var = variable_find( _environment->procedureVariables, _name );
    if ( var ) {
        if ( var->type != _type ) {
            CRITICAL( "Variable redefined with a different type");
        }
        var->value = _value;
    } else {
        var = malloc( sizeof( Variable ) );
        memset( var, 0, sizeof( Variable ) );
        var->name = strdup( _name );
        var->realName = malloc( strlen( _name ) + strlen( _environment->procedureName ) + 3 ); strcpy( var->realName, "_" ); strcat( var->realName, _environment->procedureName ); strcat( var->realName, "_" ); strcat( var->realName, _name );
        var->type = _type;
        var->value = _value;
        var->bank = _environment->banks[BT_VARIABLES];
        Variable * varLast = _environment->procedureVariables;
        if ( varLast ) {
            while( varLast->next ) {
                varLast = varLast->next;
            }
            varLast->next = var;
        } else {
            _environment->procedureVariables = var;
        }
        switch( var->type ) {
            case VT_STRING:
            case VT_DSTRING:
            case VT_MOB:
            // case VT_TILE:
            // case VT_TILESET:
            // case VT_TILES:
            case VT_SPRITE:
            case VT_BUFFER:
            case VT_IMAGE:
            case VT_IMAGES:
            case VT_SEQUENCE:
            case VT_MUSIC:
            case VT_ARRAY:
                break;
            default:
                variable_store( _environment, var->name, _value );
        }
        if ( var->type == VT_ARRAY ) {
            memcpy( var->arrayDimensionsEach, ((struct _Environment *)_environment)->arrayDimensionsEach, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
            var->arrayDimensions = ((struct _Environment *)_environment)->arrayDimensions;
        }
        memory_area_assign( _environment->memoryAreas, var );
    }
    var->used = 1;
    var->locked = 0;
    return var;
}


Variable * variable_retrieve_by_realname( Environment * _environment, char * _name ) {

    Variable * var = NULL;
    if ( _environment->procedureName ) {
        var = variable_find_by_realname( _environment->tempVariables[_environment->currentProcedure], _name );
    } else {
        var = variable_find_by_realname( _environment->tempVariables[0], _name );
    }

    if ( ! var ) {
        var = variable_find_by_realname( _environment->tempResidentVariables, _name );
    }
    if ( ! var ) {
        var = variable_find_by_realname( _environment->procedureVariables, _name );
    }
    if ( ! var ) {
        var = variable_find_by_realname( _environment->variables, _name );
    }
    return var;
}

/**
 * @brief Retrieve the definition of a variable
 * 
 * This function allows you to retrieve the definition of an actual or temporary 
 * variable, searching for it by name. Where the variable does not exist, a NULL 
 * will be returned. Otherwise, a pointer to the structure with the variable 
 * definition.
 * 
 * @param _environment Current calling environment
 * @param _name Name of the variable to look for.
 * @return Variable* Definition of the variable (if it exists) or NULL.
 */
Variable * variable_retrieve( Environment * _environment, char * _name ) {

    if ( _environment->procedureName && strstr( _name, "__" ) == NULL ) {
        char parameterName[MAX_TEMPORARY_STORAGE]; sprintf( parameterName, "%s__%s", _environment->procedureName, _name );
        Variable * var = variable_find( _environment->variables, parameterName );
        if ( var ) {
            return var;
        }
    }

    int isGlobal = 0;
    Variable * var = NULL;
    if ( _environment->procedureName ) {
        var = variable_find( _environment->tempVariables[_environment->currentProcedure], _name );
    } else {
        var = variable_find( _environment->tempVariables[0], _name );
    }
    if ( ! var ) {
        var = variable_find( _environment->tempResidentVariables, _name );
    }
    if ( ! var ) {
        Pattern * current = _environment->globalVariablePatterns;
        if ( _environment->procedureName ) {
            if ( strstr( _name, "__" ) != NULL ) {
                isGlobal = 1;
            } else {
                while( current ) {
                    if ( pattern_match( current->pattern, _name ) == 0 ) {
                        isGlobal = 1;
                        break;
                    }
                    current = current->next;
                }
            }
        } else {
            isGlobal = 1;
        }
        if ( isGlobal ) {
            var = variable_find( _environment->variables, _name );
        } else {
            var = variable_find( _environment->procedureVariables, _name );
        }
        // _environment->globalVariablePatterns;
    }
    if ( ! var ) {
        CRITICAL_VARIABLE( _name );
    }
    return var;
}

int variable_exists( Environment * _environment, char * _name ) {
    if ( _environment->procedureName && strstr( _name, "__" ) == NULL ) {
        char parameterName[MAX_TEMPORARY_STORAGE]; sprintf( parameterName, "%s__%s", _environment->procedureName, _name );
        Variable * var = variable_find( _environment->variables, parameterName );
        if ( var ) {
            return 1;
        }
    }

    int isGlobal = 0;
    Variable * var = NULL;
    if ( _environment->procedureName ) {
        var = variable_find( _environment->tempVariables[_environment->currentProcedure], _name );
    } else {
        var = variable_find( _environment->tempVariables[0], _name );
    }
    if ( ! var ) {
        var = variable_find( _environment->tempResidentVariables, _name );
    }
    if ( ! var ) {
        Pattern * current = _environment->globalVariablePatterns;
        if ( _environment->procedureName ) {
            if ( strstr( _name, "__" ) != NULL ) {
                isGlobal = 1;
            } else {
                while( current ) {
                    if ( pattern_match( current->pattern, _name ) == 0 ) {
                        isGlobal = 1;
                        break;
                    }
                    current = current->next;
                }
            }
        } else {
            isGlobal = 1;
        }
        if ( isGlobal ) {
            var = variable_find( _environment->variables, _name );
        } else {
            var = variable_find( _environment->procedureVariables, _name );
        }
        // _environment->globalVariablePatterns;
    }
    if ( ! var ) {
        return 0;
    }
    return 1;

}

int variable_delete( Environment * _environment, char * _name ) {

    Variable * var = NULL;
    if ( _environment->procedureName ) {
        var = variable_find( _environment->tempVariables[_environment->currentProcedure], _name );
        if ( var ) {
            variable_remove( _environment->tempVariables[_environment->currentProcedure], _name );
            return 1;
        }
    } else {
        var = variable_find( _environment->tempVariables[0], _name );
        if ( var ) {
            variable_remove( _environment->tempVariables[0], _name );
            return 1;
        }
    }
    if ( ! var ) {
        var = variable_find( _environment->tempResidentVariables, _name );
        if ( var ) {
            variable_remove( _environment->tempResidentVariables, _name );
            return 1;
        }
    }
    return 0;

}

Variable * variable_retrieve_or_define( Environment * _environment, char * _name, VariableType _type, int _value ) {

    Variable * var = NULL;
    if ( _environment->procedureName ) {
        var = variable_find( _environment->tempVariables[_environment->currentProcedure], _name );
    } else {
        var = variable_find( _environment->tempVariables[0], _name );
    }
    if ( !var ) {
        var = variable_find( _environment->tempResidentVariables, _name );
    }
    if ( var ){
        if ( VT_BITWIDTH( var->type ) != VT_BITWIDTH( _type ) && VT_BITWIDTH( _type ) > 0 && VT_BITWIDTH( var->type ) > 0 ) {
            var = variable_cast( _environment, var->name, _type );
        }
        return var;
    }

    if ( _environment->procedureName && strstr( _name, "__" ) == NULL ) {
        char parameterName[MAX_TEMPORARY_STORAGE]; sprintf( parameterName, "%s__%s", _environment->procedureName, _name );
        var = variable_find( _environment->variables, parameterName );
        if ( var ) {
            if ( VT_BITWIDTH( var->type ) != VT_BITWIDTH( _type ) && VT_BITWIDTH( _type ) > 0 && VT_BITWIDTH( var->type ) > 0 ) {
                var = variable_cast( _environment, var->name, _type );
            }
            return var;
        }
    }

    var = variable_find( _environment->procedureVariables, _name );

    if ( ! var ) {
        if ( _type == VT_STRING ) {
            _type = VT_DSTRING;
        }
        int isGlobal = 0;
        Pattern * current = _environment->globalVariablePatterns;
        if ( _environment->procedureName ) {
            if ( strstr( _name, "__" ) != NULL ) {
                isGlobal = 1;
            } else {
                while( current ) {
                    if ( pattern_match( current->pattern, _name ) == 0 ) {
                        isGlobal = 1;
                        break;
                    }
                    current = current->next;
                }
            }
        } else {
            isGlobal = 1;
        }
        if ( isGlobal ) {
            var = variable_find( _environment->variables, _name );
            if ( ! var  ) {
                if ( _environment->procedureName ) {
                    var = variable_define_no_init( _environment, _name, _type );
                } else {
                    var = variable_define( _environment, _name, _type, _value );
                }
            }
        } else {
            var = variable_define_local( _environment, _name, _type, _value );
        }        
    }
    if (!var) {
        CRITICAL_VARIABLE( _name );
    } else {
        if ( VT_BITWIDTH( var->type ) != VT_BITWIDTH( _type ) && VT_BITWIDTH( _type ) > 0 && VT_BITWIDTH( var->type ) > 0 ) {
            var = variable_cast( _environment, var->name, _type );
        }
    }
    return var;
}

/**
 * @brief Reset the usage flags for the temporary variable pool
 * 
 * This function allows you to reset the use flag of each temporary variable
 * in the pool. The purpose of this function is to allow the reuse of variables.
 * 
 * @param _environment Current calling environment
 */
void variable_reset( Environment * _environment ) {
    if ( _environment->procedureName ) {
        variable_reset_pool( _environment, _environment->tempVariables[_environment->currentProcedure] );
    } else {
        variable_reset_pool( _environment, _environment->tempVariables[0] );
    }    
}

Variable * variable_array_type( Environment * _environment, char *_name, VariableType _type ) {
    Variable * var = variable_find( _environment->variables, _name );
    if ( ! var ) {
        CRITICAL_VARIABLE( _name );
    }
    var->arrayType = _type;
    int i=0,size=1;
    for( i=0; i<var->arrayDimensions; ++i ) {
        size *= var->arrayDimensionsEach[i];
    }
    if ( VT_BITWIDTH( var->arrayType ) > 0 ) {
        size *= ( VT_BITWIDTH( var->arrayType ) >> 3 );
    } else if ( var->arrayType == VT_DSTRING ) {
        size *= 1;
    } else if ( var->arrayType == VT_MOB ) {
        size *= 1;
    } else if ( var->arrayType == VT_SPRITE ) {
        size *= 1;
    } else if ( var->arrayType == VT_TILE ) {
        size *= 1;
    } else if ( var->arrayType == VT_TILES ) {
        size *= 4;
    } else {
        CRITICAL_DATATYPE_UNSUPPORTED("array(1)", DATATYPE_AS_STRING[var->arrayType]);
    }
    var->size = size;
}

/**
 * @brief Define a temporary variable
 * 
 * This function is necessary to define a temporary variable. This
 * call will search for a (unused) temporary variable of the same
 * type. If there is none, a new temporary variable will be reserved.
 * The name will be chosen so as not to collide with either existing 
 * temporary variables or already defined actual variables.
 * Note that the variable will be defined in the last bank defined 
 * by the <b>BANK</b> command as <b>TEMPORARY</b>. In other words, it is possible 
 * to define different variables in different banks, thus optimizing 
 * the space occupied by the program.
 * 
 * Allowed types:
 * 
 * - `VT_BYTE` (<b>BYTE</b>)
 * - `VT_SBYTE` (<b>SIGNED BYTE</b>)
 * - `VT_COLOR` (<b>COLOR</b>)
 * - `VT_WORD` (<b>WORD</b>)
 * - `VT_SWORD` (<b>SIGNED WORD</b>)
 * - `VT_ADDRESS` (<b>ADDRESS</b>)
 * - `VT_POSITION` (<b>POSITION</b>)
 * - `VT_DWORD` (<b>DWORD</b>)
 * - `VT_SIGNED DWORD` (<b>SIGNED DWORD</b>)
 * - `VT_STRING` (<b>STATIC STRING</b>)
 * - `VT_DSTRING` (<b>DYNAMIC STRING</b>)
 * - `VT_BUFFER`
 * - `VT_MOB`
 * - `VT_SPRITE`
 * - `VT_TILE`
 * - `VT_TILESET`
 * - `VT_TILES`
 * 
 * @param _environment Current calling environment
 * @param _type Type of the variable to define
 * @return Variable* The variable definition
 */
Variable * variable_temporary( Environment * _environment, VariableType _type, char * _meaning ) {

    Variable * var = NULL;
    if ( _environment->procedureName ) {
        var = variable_find_first_unused( _environment->tempVariables[_environment->currentProcedure], _type );
    } else {
        var = variable_find_first_unused( _environment->tempVariables[0], _type );
    }    
    if ( var ) {
        var->meaningName = _meaning;
    } else {
        char * name = malloc(MAX_TEMPORARY_STORAGE);
        var = malloc( sizeof( Variable ) );
        memset( var, 0, sizeof( Variable ) );
        var->locked = 0;
        if ( _type == VT_STRING ) {
            sprintf(name, "Tstr%d", UNIQUE_ID);
            var->locked = 1;
        } else if ( _type == VT_BUFFER ) {
            sprintf(name, "Tbuf%d", UNIQUE_ID);
            var->locked = 1;
        } else if ( _type == VT_IMAGE ) {
            sprintf(name, "Timg%d", UNIQUE_ID);
            var->locked = 1;
        } else if ( _type == VT_IMAGES ) {
            sprintf(name, "Timgs%d", UNIQUE_ID);
            var->locked = 1;
        } else if ( _type == VT_SEQUENCE ) {
            sprintf(name, "Tseq%d", UNIQUE_ID);
            var->locked = 1;
        } else if ( _type == VT_MUSIC ) {
            sprintf(name, "Tmus%d", UNIQUE_ID);
            var->locked = 1;
        } else {
            sprintf(name, "Ttmp%d", UNIQUE_ID);
        }
        var->name = name;
        var->realName = malloc( strlen( var->name ) + 2 ); strcpy( var->realName, "_" ); strcat( var->realName, var->name );
        var->meaningName = _meaning;
        var->type = _type;
        var->bank = _environment->banks[BT_TEMPORARY];
        Variable * varLast = NULL;
        if ( _environment->procedureName ) {
            varLast = _environment->tempVariables[_environment->currentProcedure];
        } else {
            varLast = _environment->tempVariables[0];
        }        
        if ( varLast ) {
            while( varLast->next ) {
                varLast = varLast->next;
            }
            varLast->next = var;
        } else {
            if ( _environment->procedureName ) {
                _environment->tempVariables[_environment->currentProcedure] = var;
            } else {
                _environment->tempVariables[0] = var;
            }                
        }
        memory_area_assign( _environment->memoryAreas, var );
    }
    if ( var->meaningName ) {
        
    }
    var->used = 1;
    var->temporary = 1;
    return var;
}

Variable * variable_resident( Environment * _environment, VariableType _type, char * _meaning ) {
    char * name = malloc(MAX_TEMPORARY_STORAGE);
    Variable * var = malloc( sizeof( Variable ) );
    memset( var, 0, sizeof( Variable ) );
    if ( _type == VT_STRING ) {
        sprintf(name, "Tstr%d", UNIQUE_ID);
    } else if ( _type == VT_BUFFER ) {
        sprintf(name, "Tbuf%d", UNIQUE_ID);
    } else if ( _type == VT_IMAGE ) {
        sprintf(name, "Timg%d", UNIQUE_ID);
    } else if ( _type == VT_IMAGES ) {
        sprintf(name, "Timgs%d", UNIQUE_ID);
    } else if ( _type == VT_SEQUENCE ) {
        sprintf(name, "Tseq%d", UNIQUE_ID);
    } else if ( _type == VT_MUSIC ) {
        sprintf(name, "Tmus%d", UNIQUE_ID);
    } else {
        sprintf(name, "Ttmp%d", UNIQUE_ID);
    }
    var->name = name;
    var->realName = malloc( strlen( var->name ) + 2 ); strcpy( var->realName, "_" ); strcat( var->realName, var->name );
    var->meaningName = _meaning;
    var->type = _type;
    var->bank = _environment->banks[BT_TEMPORARY];
    Variable * varLast = _environment->tempResidentVariables;
    if ( varLast ) {
        while( varLast->next ) {
            varLast = varLast->next;
        }
        varLast->next = var;
    } else {
        _environment->tempResidentVariables = var;
    }
    memory_area_assign( _environment->memoryAreas, var );
    if ( var->meaningName ) {
        outline2("; %s <-> %s (resident)", var->realName, var->meaningName );
    }
    return var;
}


/**
 * @brief Cast a variable from a type to another
 * 
 * This function can be called to convert a variable from one type to another. 
 * The function takes care of both creating a temporary variable and copying 
 * the value into it, conveying it differently depending on the type.
 * The variable must exist in order to work, otherwise an exception will 
 * be thrown. 
 * 
 * @pre _source variable must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _type Required type
 * @return Variable* A new temporary variable with the content converted to the required type
 * @throw EXIT_FAILURE "Cannot find source var"
 */
Variable * variable_cast( Environment * _environment, char * _source, VariableType _type ) {

    Variable * source = variable_retrieve( _environment, _source );
    
    if ( _type == VT_STRING ) {
        _type = VT_DSTRING;
    }

    if ( source->type == _type ) {
        return source;
    }

    Variable * target = variable_temporary( _environment, _type, "(generated for cast)" );

    variable_move( _environment, source->name, target->name );

    return target;
}

/**
 * @brief Store a direct value to a variable
 * 
 * This function outputs code to initialize a variable to a specific direct value.
 * The variable must exist in order to work, otherwise an exception will 
 * be thrown. 
 * 
 * @pre _destination variable must exist
 * 
 * @param _environment Current calling environment
 * @param _destination Destination variable's name
 * @param _value Value to assign
 * @return Variable* The destination variable
 * @throw EXIT_FAILURE "Destination variable does not exists"
 */
Variable * variable_store( Environment * _environment, char * _destination, unsigned int _value ) {
    
    Variable * destination = variable_retrieve( _environment, _destination );

    switch( VT_BITWIDTH( destination->type ) ) {
        case 32:
            cpu_store_32bit( _environment, destination->realName, VT_ESIGN_32BIT( destination->type, _value ) );
            break;
        case 16:
            cpu_store_16bit( _environment, destination->realName, VT_ESIGN_16BIT( destination->type, _value ) );
            break;
        case 8:
            cpu_store_8bit( _environment, destination->realName, VT_ESIGN_8BIT( destination->type, _value ) );
            break;
        case 0:
            if ( destination->type == VT_ARRAY ) {
                int i=0,size=1;
                for( i=0; i<destination->arrayDimensions; ++i ) {
                    size *= destination->arrayDimensionsEach[i];
                }
                if ( VT_BITWIDTH( destination->arrayType ) > 0 ) {
                    size *= ( VT_BITWIDTH( destination->arrayType ) >> 3 );
                } else if ( destination->arrayType == VT_DSTRING ) {
                    size *= 1;
                } else if ( destination->arrayType == VT_MOB ) {
                    size *= 1;
                } else if ( destination->arrayType == VT_SPRITE ) {
                    size *= 1;
                } else if ( destination->arrayType == VT_TILE ) {
                    size *= 1;
                } else if ( destination->arrayType == VT_TILESET ) {
                    size *= 1;
                } else if ( destination->arrayType == VT_TILES ) {
                    size *= 4;
                } else {
                    CRITICAL_DATATYPE_UNSUPPORTED("array(1)", DATATYPE_AS_STRING[destination->arrayType]);
                }
                cpu_fill_direct_size_value( _environment, destination->realName, size, _value );
            } else {
                CRITICAL_STORE_UNSUPPORTED(DATATYPE_AS_STRING[destination->type]);
            }
            break;
    }
    return destination;
}

#define UNESCAPE_COLOR( c, d ) \
            else if ( strcmp_nocase( word, c ) == 0 ) { \
                            if ( _printing ) { \
                                *q = '*'; \
                            } else { \
                                *q = 1; \
                            } \
                            ++q; \
                            if ( _printing ) { \
                                *q = '*'; \
                            } else { \
                                *q = COLOR_##d; \
                            } \
                            ++q; \
                    }

char * unescape_string( Environment * _environment, char * _value, int _printing ) {

    char * newValue = malloc( strlen( _value ) + 1 );
    
    memset( newValue, 0, strlen( _value ) + 1 );

    char * p = _value, * q = newValue;
    int c = 0;

    while( *p ) {
        if ( *p == '{' ) {
            ++p;
            if ( isdigit(*p) ) {
                c = 0;
                while( *p && *p != '}' ) {
                    c = 10 * c + ( *p - '0' );
                    ++p;
                }
                if ( _printing ) {
                    *q = '*';
                } else {
                    *q = c;
                }
                ++q;
                ++p;
            } else {
                char * p2 = strchr(p+1, '}' );
                if ( p2 ) {
                    char word[MAX_TEMPORARY_STORAGE];
                    memset( word, 0, MAX_TEMPORARY_STORAGE );
                    memcpy( word, p, p2-p );
                    p = p2+1;
                    // printf( "checking '%s'\n", word );

                    if ( strcmp_nocase( word, "clear" ) == 0 ) {
                        if ( _printing ) {
                            *q = '*';
                        } else {
                            *q = 5;
                        }
                        ++q;
                    } 
                    UNESCAPE_COLOR( "black", BLACK )
                    UNESCAPE_COLOR( "white", WHITE )
                    UNESCAPE_COLOR( "red", RED )
                    UNESCAPE_COLOR( "cyan", CYAN )
                    UNESCAPE_COLOR( "violet", VIOLET )
                    UNESCAPE_COLOR( "green", GREEN )
                    UNESCAPE_COLOR( "blue", BLUE )
                    UNESCAPE_COLOR( "yellow", YELLOW )
                    UNESCAPE_COLOR( "orange", ORANGE )
                    UNESCAPE_COLOR( "brown", BROWN )
                    UNESCAPE_COLOR( "lt red", LIGHT_RED )
                    UNESCAPE_COLOR( "light red", LIGHT_RED )
                    UNESCAPE_COLOR( "dk grey", DARK_GREY )
                    UNESCAPE_COLOR( "dark grey", DARK_GREY )
                    UNESCAPE_COLOR( "dk gray", DARK_GREY )
                    UNESCAPE_COLOR( "dark gray", DARK_GREY )
                    UNESCAPE_COLOR( "grey", GREY )
                    UNESCAPE_COLOR( "gray", GREY )
                    UNESCAPE_COLOR( "lt green", LIGHT_GREEN )
                    UNESCAPE_COLOR( "light green", LIGHT_GREEN )
                    UNESCAPE_COLOR( "lt blue", LIGHT_BLUE )
                    UNESCAPE_COLOR( "light blue", LIGHT_BLUE )
                    UNESCAPE_COLOR( "lt grey", LIGHT_GREY )
                    UNESCAPE_COLOR( "light grey", LIGHT_GREY )
                    UNESCAPE_COLOR( "lt gray", LIGHT_GREY )
                    UNESCAPE_COLOR( "light gray", LIGHT_GREY )
                    UNESCAPE_COLOR( "dk blue", DARK_BLUE )
                    UNESCAPE_COLOR( "dark blue", DARK_BLUE )
                    UNESCAPE_COLOR( "magenta", MAGENTA )
                    UNESCAPE_COLOR( "purple", PURPLE )
                    UNESCAPE_COLOR( "lavender", LAVENDER )
                    UNESCAPE_COLOR( "gold", GOLD )
                    UNESCAPE_COLOR( "turquoise", TURQUOISE )
                    UNESCAPE_COLOR( "tan", TAN )
                    UNESCAPE_COLOR( "yellow green", YELLOW_GREEN )
                    UNESCAPE_COLOR( "olive green", OLIVE_GREEN )
                    UNESCAPE_COLOR( "pink", PINK )
                    UNESCAPE_COLOR( "peach", PEACH )
                } else {
                    *q = *p;
                    ++p;
                    ++q;
                }
            }
        } else {
            *q = *p;
            ++q;
            ++p;
        }
    }

    // printf( "\"%s\" = { ", _value );
    // int i=0;
    // for( i=0; i<strlen(newValue); ++i ) {
    //     printf( "$%2.2x, ", (unsigned char)*(newValue+i) );
    // }
    // printf( "}\n" );

    return newValue;

}

/**
 * @brief Store a string to a variable 
 * 
 * @param _environment Current calling environment
 * @param _destination Destination variable's name
 * @param _value Value to assign
 * @return Variable* The destination variable
 */
Variable * variable_store_string( Environment * _environment, char * _destination, char * _value ) {

    Variable * destination = variable_retrieve( _environment, _destination );

    switch( destination->type ) {
        case VT_STRING: {
            if ( !_environment->emptyProcedure ) {
                destination->valueString = strdup( unescape_string( _environment, _value, 0 ) );
                destination->size = strlen( destination->valueString ) + 1;
                memory_area_assign( _environment->memoryAreas, destination );
            } else {
                destination->valueString = strdup( "" );
            }
            break;
        }
        case VT_DSTRING: {
            Variable * temporary = variable_temporary( _environment, VT_STRING, "(temporary)");
            variable_store_string( _environment, temporary->name, _value );
            cpu_dsfree( _environment, destination->realName );
            cpu_dsdefine( _environment, temporary->realName, destination->realName );
            break;
        }
        default:
            CRITICAL_STORE_UNSUPPORTED(DATATYPE_AS_STRING[destination->type]);
    }
    return destination;
}

/**
 * @brief Resize the (static) size of a buffer
 * 
 * @param _environment Current calling environment
 * @param _destination Destination variable's name
 * @param _size Size of the buffer, in bytes
 * @return Variable* The destination variable
 */
Variable * variable_resize_buffer( Environment * _environment, char * _destination, int _size ) {
    Variable * destination = variable_retrieve( _environment, _destination );
    switch( destination->type ) {
        case VT_BUFFER: {
            destination->size = _size;
            break;
        }
        default:
            CRITICAL_RESIZE_UNSUPPORTED(DATATYPE_AS_STRING[destination->type]);
    }
    return destination;
}

Variable * variable_store_buffer( Environment * _environment, char * _destination, unsigned char * _buffer, int _size, int _at ) {
    Variable * destination = variable_retrieve( _environment, _destination );
    switch( destination->type ) {
        case VT_IMAGE:
        case VT_IMAGES:
        case VT_SEQUENCE:
        case VT_MUSIC:
        case VT_BUFFER:
            if ( ! destination->valueBuffer ) {
                destination->valueBuffer = malloc( _size );
                memcpy( destination->valueBuffer, _buffer, _size );
                destination->size = _size;
                if ( _at ) {
                    destination->absoluteAddress = _at;
                    char bufferCopy[MAX_TEMPORARY_STORAGE]; sprintf( bufferCopy, "%scopy", destination->realName );
                    cpu_mem_move_direct_size( _environment, bufferCopy, destination->realName, _size );
                } else {
                    memory_area_assign( _environment->memoryAreas, destination );
                }
            } else {
                Variable * temporary = variable_temporary( _environment, destination->type, "(copy of buffer/image)");
                temporary->valueBuffer = malloc( _size );
                memcpy( temporary->valueBuffer, _buffer, _size );
                temporary->size = _size;
                memory_area_assign( _environment->memoryAreas, temporary );
                if ( destination->size < _size ) {
                    destination->valueBuffer = realloc( destination->valueBuffer, _size );
                    memset( destination->valueBuffer + destination->size, 0, ( _size - destination->size ) );
                    destination->size = _size;
                    memory_area_assign( _environment->memoryAreas, destination );
                }
                variable_move_naked( _environment, temporary->name, destination->name );                
            }
            break;
        default:
            CRITICAL_STORE_UNSUPPORTED(DATATYPE_AS_STRING[destination->type]);
    }
    return destination;
}

Variable * variable_store_array( Environment * _environment, char * _destination, unsigned char * _buffer, int _size, int _at ) {
    Variable * destination = variable_retrieve( _environment, _destination );
    switch( destination->type ) {
        case VT_ARRAY:
            if ( ! destination->valueBuffer ) {
                destination->valueBuffer = malloc( _size );
                memcpy( destination->valueBuffer, _buffer, _size );
                destination->size = _size;
                if ( _at ) {
                    destination->absoluteAddress = _at;
                    char bufferCopy[MAX_TEMPORARY_STORAGE]; sprintf( bufferCopy, "%scopy", destination->realName );
                    cpu_mem_move_direct_size( _environment, bufferCopy, destination->realName, _size );
                }
            } else {
                Variable * temporary = variable_temporary( _environment, destination->type, "(copy of buffer/image)");
                temporary->valueBuffer = malloc( _size );
                memcpy( temporary->valueBuffer, _buffer, _size );
                temporary->size = _size;
                if ( destination->size < _size ) {
                    destination->valueBuffer = realloc( destination->valueBuffer, _size );
                    memset( destination->valueBuffer + destination->size, 0, ( _size - destination->size ) );
                    destination->size = _size;
                }
                variable_move_naked( _environment, temporary->name, destination->name );                
            }
            break;
        default:
            CRITICAL_STORE_UNSUPPORTED(DATATYPE_AS_STRING[destination->type]);
    }
    return destination;
}

/**
 * @brief Store the value of a variable inside another variable by converting it
 * 
 * This function allows you to store the value of one variable in another, 
 * making it (implicitly) cast (type conversion). Note that both variables 
 * must pre-exist before the operation, under penalty of an exception.
 * 
 * @pre _source and _dest variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Destination variable's name
 * @param _destination Destination variable's name
 * @return Variable* The destination variable
 * @throw EXIT_FAILURE "Destination variable does not exist"
 * @throw EXIT_FAILURE "Source variable does not cast"
 */
Variable * variable_move( Environment * _environment, char * _source, char * _destination ) {

    Variable * source = variable_retrieve( _environment, _source );
    Variable * sign = variable_temporary( _environment, VT_BYTE, "(sign)" );

    Variable * target = variable_retrieve( _environment, _destination );

    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            switch( VT_BITWIDTH( target->type ) ) {
                case 32:
                    cpu_move_32bit( _environment, source->realName, target->realName );
                    break;
                case 16:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+2", source->realName );
                            cpu_move_16bit( _environment, sourceRealName, target->realName );
                        }
                    #else
                        cpu_move_16bit( _environment, source->realName, target->realName );
                    #endif
                    break;
                case 8:
                    WARNING_DOWNCAST( _source, target->name );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+3", source->realName );
                            cpu_move_8bit( _environment, sourceRealName, target->realName );
                        }
                    #else
                        cpu_move_8bit( _environment, source->realName, target->realName );
                    #endif
                    break;
                case 0:
                    switch( target->type ) {
                        case VT_TILE:
                            WARNING_DOWNCAST( _source, target->name );
                            #ifdef CPU_BIG_ENDIAN
                                {
                                    char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+3", source->realName );
                                    cpu_move_8bit( _environment, sourceRealName, target->realName );
                                }
                            #else
                                cpu_move_8bit( _environment, source->realName, target->realName );
                            #endif
                            break;
                        default:
                            CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                    }
                    break;
            }
            break;
        case 16:
            switch( VT_BITWIDTH( target->type ) ) {
                case 32:
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE];
                            
							sprintf( targetRealName, "%s+2", target->realName );
                            cpu_move_16bit( _environment, source->realName, targetRealName );

							if ( VT_SIGNED( source->type ) ) {
								cpu_is_negative( _environment, source->realName, sign->realName );
							} else {
								variable_store( _environment, sign->name, 0 );
							}
							
                            sprintf( targetRealName, "%s", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                            sprintf( targetRealName, "(%s+1)", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                        }
                    #else
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE];
                            cpu_move_16bit( _environment, source->realName, target->realName );
							
							if ( VT_SIGNED( source->type ) ) {
								cpu_is_negative( _environment, source->realName, sign->realName );
							} else {
								variable_store( _environment, sign->name, 0 );
							}
                            
							sprintf( targetRealName, "%s+3", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                            sprintf( targetRealName, "%s+2", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                        }
                    #endif
                    break;
                case 16:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case 8:
                    WARNING_DOWNCAST( _source, target->name );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+1", source->realName );
                            cpu_move_8bit( _environment, sourceRealName, target->realName );
                        }
                    #else
                        cpu_move_8bit( _environment, source->realName, target->realName );
                    #endif
                    break;
                case 0:
                    switch( target->type ) {
                        case VT_TILE:
                            WARNING_DOWNCAST( _source, target->name );
                            #ifdef CPU_BIG_ENDIAN
                                {
                                    char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+1", source->realName );
                                    cpu_move_8bit( _environment, sourceRealName, target->realName );
                                }
                            #else
                                cpu_move_8bit( _environment, source->realName, target->realName );
                            #endif
                            break;
                        default:
                            CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                    }
                    break;
            }
            break;
        case 8:
            switch( VT_BITWIDTH( target->type ) ) {
                case 32:
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE];
                            sprintf( targetRealName, "%s+3", target->realName );
                            cpu_move_8bit( _environment, source->realName, targetRealName );
							
							if ( VT_SIGNED( source->type ) ) {
								cpu_is_negative( _environment, source->realName, sign->realName );
							} else {
								variable_store( _environment, sign->name, 0 );
							}
                            
							sprintf( targetRealName, "%s+2", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                            sprintf( targetRealName, "%s+1", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                            sprintf( targetRealName, "%s", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                        }
                    #else
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE];
                            sprintf( targetRealName, "%s", target->realName );
                            cpu_move_8bit( _environment, source->realName, targetRealName );
							
							if ( VT_SIGNED( source->type ) ) {
								cpu_is_negative( _environment, source->realName, sign->realName );
							} else {
								variable_store( _environment, sign->name, 0 );
							}
                            
							sprintf( targetRealName, "%s+1", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                            sprintf( targetRealName, "%s+2", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                            sprintf( targetRealName, "%s+3", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                        }
                    #endif
                    break;
                case 16:
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE];
                            sprintf( targetRealName, "%s+1", target->realName );
                            cpu_move_8bit( _environment, source->realName, targetRealName );
							
							if ( VT_SIGNED( source->type ) ) {
								cpu_is_negative( _environment, source->realName, sign->realName );
							} else {
								variable_store( _environment, sign->name, 0 );
							}
                            
							sprintf( targetRealName, "%s", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                        }
                    #else
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE];
                            sprintf( targetRealName, "%s", target->realName );
                            cpu_move_8bit( _environment, source->realName, targetRealName );
							
							if ( VT_SIGNED( source->type ) ) {
								cpu_is_negative( _environment, source->realName, sign->realName );
							} else {
								variable_store( _environment, sign->name, 0 );
							}
                            
							sprintf( targetRealName, "%s+1", target->realName );
                            cpu_move_8bit( _environment, sign->realName, targetRealName );
                        }
                    #endif
                    break;
                case 8:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case 0:
                    switch( target->type ) {
                        case VT_TILE:
                            cpu_move_8bit( _environment, source->realName, target->realName );
                            break;
                        default:
                            CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                    }
                    break;
            }
            break;
        case 0:
            switch( VT_BITWIDTH( target->type ) ) {
                case 32:
                case 16:
                case 8:
                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                case 0:
                    switch( source->type ) {
                        case VT_STRING:
                            switch( target->type ) {
                                case VT_DSTRING: {
                                    cpu_dsfree( _environment, target->realName );
                                    cpu_dsdefine( _environment, source->realName, target->realName );
                                    break;
                                }
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    break;
                            }
                            break;
                        case VT_DSTRING:
                            switch( target->type ) {
                                case VT_DSTRING: {
                                    Variable * sourceAddress = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                                    Variable * sourceSize = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                                    Variable * targetAddress = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                                    Variable * targetSize = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                                    cpu_dsdescriptor( _environment, source->realName, sourceAddress->realName, sourceSize->realName );
                                    cpu_dsfree( _environment, target->realName );
                                    cpu_dsalloc( _environment, sourceSize->realName, target->realName );
                                    cpu_dsdescriptor( _environment, target->realName, targetAddress->realName, targetSize->realName );
                                    cpu_mem_move( _environment, sourceAddress->realName, targetAddress->realName, sourceSize->realName );
                                    break;
                                }
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    break;
                            }
                            break;
                        case VT_MOB:
                            switch( target->type ) {
                                case VT_MOB: {
                                    cpu_move_8bit( _environment, source->realName, target->realName );
                                    break;
                                }
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    break;
                            }
                            break;
                        case VT_SPRITE:
                            switch( target->type ) {
                                case VT_SPRITE: {
                                    cpu_move_8bit( _environment, source->realName, target->realName );
                                    break;
                                }
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    break;
                            }
                            break;
                        case VT_TILE:
                            switch( target->type ) {
                                case VT_TILE: {
                                    cpu_move_8bit( _environment, source->realName, target->realName );
                                    break;
                                }
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    break;
                            }
                            break;
                        case VT_TILESET:
                            switch( target->type ) {
                                case VT_TILESET: {
                                    cpu_move_8bit( _environment, source->realName, target->realName );
                                    break;
                                }
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    break;
                            }
                            break;
                        case VT_TILES:
                            switch( target->type ) {
                                case VT_TILES: {
                                    target->originalWidth = source->originalWidth;
                                    target->originalHeight = source->originalHeight;
                                    cpu_move_32bit( _environment, source->realName, target->realName );
                                    break;
                                }
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    break;
                            }
                            break;
                        case VT_IMAGE:
                            switch( target->type ) {
                                case VT_IMAGE:
                                    target->originalBitmap = source->originalBitmap;
                                    target->originalWidth = source->originalWidth;
                                    target->originalHeight = source->originalHeight;
                                    target->originalColors = source->originalColors;
                                    memcpy( target->originalPalette, source->originalPalette, MAX_PALETTE * sizeof( RGBi ) );
                                case VT_BUFFER:
                                    if ( target->size == 0 ) {
                                        target->size = source->size;
                                    }
                                    if ( source->size <= target->size ) {
                                        cpu_mem_move_direct_size( _environment, source->realName, target->realName, source->size );
                                    } else {
                                        CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    }
                                    break;
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                            }
                            break;
                        case VT_IMAGES:
                            switch( target->type ) {
                                case VT_IMAGES:
                                case VT_BUFFER:
                                    if ( target->size == 0 ) {
                                        target->size = source->size;
                                    }
                                    if ( source->size <= target->size ) {
                                        cpu_mem_move_direct_size( _environment, source->realName, target->realName, source->size );
                                    } else {
                                        CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    }
                                    break;
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                            }
                            break;
                        case VT_SEQUENCE:
                            switch( target->type ) {
                                case VT_SEQUENCE:
                                case VT_BUFFER:
                                    if ( target->size == 0 ) {
                                        target->size = source->size;
                                    }
                                    if ( source->size <= target->size ) {
                                        cpu_mem_move_direct_size( _environment, source->realName, target->realName, source->size );
                                    } else {
                                        CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    }
                                    break;
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                            }
                            break;
                        case VT_MUSIC:
                            switch( target->type ) {
                                case VT_MUSIC:
                                case VT_BUFFER:
                                    if ( target->size == 0 ) {
                                        target->size = source->size;
                                    }
                                    if ( source->size <= target->size ) {
                                        cpu_mem_move_direct_size( _environment, source->realName, target->realName, source->size );
                                    } else {
                                        CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    }
                                    break;
                                default:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                            }
                            break;
                        case VT_BUFFER:
                            switch( target->type ) {
                                case VT_DSTRING: {
                                    if ( source->size > 255 ) {
                                        CRITICAL_CANNOT_CAST_BUFFER_STRING_SIZE( source->name, target->name );
                                    }
                                    cpu_dsfree( _environment, target->realName );
                                    cpu_dsalloc_size( _environment, source->size, target->realName );
                                    Variable * targetAddress = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                                    Variable * targetSize = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                                    cpu_dsdescriptor( _environment, target->realName, targetAddress->realName, targetSize->realName );
                                    cpu_mem_move_direct_indirect_size( _environment, source->realName, targetAddress->realName, source->size );
                                    break;
                                }
                                case VT_STRING:
                                    CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                case VT_IMAGE:
                                case VT_IMAGES:
                                case VT_SEQUENCE:
                                case VT_MUSIC:
                                case VT_BUFFER:
                                    if ( target->size == 0 ) {
                                        target->size = source->size;
                                    }
                                    if ( source->size <= target->size ) {
                                        cpu_mem_move_direct_size( _environment, source->realName, target->realName, source->size );
                                    } else {
                                        CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type]);
                                    }
                                    break;
                            }
                            break;
                    }
                    break;

            }
            break;
    }


    return target;
}

/**
 * @brief Store the value of a variable inside another variable without conversion
 * 
 * This function allows you to store the value of one variable in another, 
 * without cast (type conversion). Note that both variables 
 * must pre-exist before the operation, under penalty of an exception.
 * 
 * @pre _source and _dest variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Destination variable's name
 * @param _destination Destination variable's name
 * @return Variable* The destination variable
 * @throw EXIT_FAILURE "Destination variable does not exist"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
Variable * variable_move_naked( Environment * _environment, char * _source, char * _destination ) {
    Variable * source = variable_retrieve( _environment, _source );

    Variable * target = variable_retrieve( _environment, _destination );

    if ( source->type != target->type ) {
        CRITICAL_DATATYPE_MISMATCH( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );
    }
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            cpu_move_32bit( _environment, source->realName, target->realName );
            break;
        case 16:
            cpu_move_16bit( _environment, source->realName, target->realName );
            break;
        case 8:
            cpu_move_8bit( _environment, source->realName, target->realName );
            break;
        case 0:
            switch( target->type ) {
                case VT_DSTRING: {
                    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                    cpu_dsdescriptor( _environment, source->realName, address->realName, size->realName );
                    cpu_dsfree( _environment, target->realName );
                    cpu_dsalloc( _environment, size->realName, target->realName );
                    cpu_dsdescriptor( _environment, target->realName, address2->realName, size2->realName );
                    cpu_mem_move( _environment, address->realName, address2->realName, size->realName );
                    break;
                }
                case VT_MOB:
                    switch( target->type ) {
                        case VT_MOB: {
                            cpu_move_8bit( _environment, source->realName, target->realName );
                            break;
                        }
                        default:
                            CRITICAL_MOVE_NAKED_UNSUPPORTED( DATATYPE_AS_STRING[target->type]);
                            break;
                    }
                    break;
                case VT_SPRITE:
                    switch( target->type ) {
                        case VT_SPRITE: {
                            cpu_move_8bit( _environment, source->realName, target->realName );
                            break;
                        }
                        default:
                            CRITICAL_MOVE_NAKED_UNSUPPORTED( DATATYPE_AS_STRING[target->type]);
                            break;
                    }
                    break;
                case VT_TILE:
                    switch( target->type ) {
                        case VT_TILE: {
                            cpu_move_8bit( _environment, source->realName, target->realName );
                            break;
                        }
                        default:
                            CRITICAL_MOVE_NAKED_UNSUPPORTED( DATATYPE_AS_STRING[target->type]);
                            break;
                    }
                    break;
                case VT_TILESET:
                    switch( target->type ) {
                        case VT_TILESET: {
                            cpu_move_8bit( _environment, source->realName, target->realName );
                            break;
                        }
                        default:
                            CRITICAL_MOVE_NAKED_UNSUPPORTED( DATATYPE_AS_STRING[target->type]);
                            break;
                    }
                    break;
                case VT_TILES:
                    switch( target->type ) {
                        case VT_TILES: {
                            target->originalWidth = source->originalWidth;
                            target->originalHeight = source->originalHeight;
                            cpu_move_16bit( _environment, source->realName, target->realName );
                            break;
                        }
                        default:
                            CRITICAL_MOVE_NAKED_UNSUPPORTED( DATATYPE_AS_STRING[target->type]);
                            break;
                    }
                    break;
                case VT_IMAGE:
                    target->originalBitmap = source->originalBitmap;
                    target->originalWidth = source->originalWidth;
                    target->originalHeight = source->originalHeight;
                    target->originalColors = source->originalColors;
                    target->bankAssigned = source->bankAssigned;
                    if ( target->bankAssigned ) {
                        target->absoluteAddress = source->absoluteAddress;
                        target->residentAssigned = source->residentAssigned;
                        target->variableUniqueId = source->variableUniqueId;
                    }
                    memcpy( target->originalPalette, source->originalPalette, MAX_PALETTE * sizeof( RGBi ) );
                case VT_IMAGES:
                case VT_SEQUENCE:
                case VT_MUSIC:
                case VT_ARRAY:
                case VT_BUFFER: {
                    if ( target->size == 0 ) {
                        target->size = source->size;
                    }
                    if ( source->size > target->size ) {
                        CRITICAL_BUFFER_SIZE_MISMATCH(_source, _destination);
                    }
                    cpu_mem_move_direct_size( _environment, source->realName, target->realName, source->size );
                    break;
                }
                default:
                    CRITICAL_MOVE_NAKED_UNSUPPORTED(DATATYPE_AS_STRING[target->type]);
            }
    }
    return source;
}

/**
 * @brief Add two variable and return the sum of them
 * 
 * This function allows you to sum the value of two variables. Note 
 * that both variables must pre-exist before the operation, 
 * under penalty of an exception.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @return Variable* The sum of source and destination variable
 * @throw EXIT_FAILURE "Destination variable does not cast"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
Variable * variable_add( Environment * _environment, char * _source, char * _destination ) {

    Variable * source = variable_retrieve( _environment, _source );
    if ( source->type == VT_STRING ) {
        source = variable_cast( _environment, _source, VT_DSTRING );
    }

    Variable * target = variable_cast( _environment, _destination, source->type );
    if ( ! target ) {
        CRITICAL_VARIABLE(_destination);
    }

    Variable * result = variable_temporary( _environment, source->type, "(result of adding)" );

    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            cpu_math_add_32bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 16:
            cpu_math_add_16bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 8:
            cpu_math_add_8bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 0:
            switch( source->type ) {
                case VT_DSTRING:  {
                    Variable * address1 = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING1)");
                    Variable * size1 = variable_temporary( _environment, VT_BYTE, "(size of DSTRING1)");
                    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING2)");
                    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of DSTRING2)");
                    Variable * address= variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                    cpu_dsdescriptor( _environment, source->realName, address1->realName, size1->realName );
                    cpu_dsdescriptor( _environment, target->realName, address2->realName, size2->realName );
                    cpu_math_add_8bit( _environment, size1->realName, size2->realName, size->realName );
                    cpu_dsfree( _environment, result->realName );
                    cpu_dsalloc( _environment, size->realName, result->realName );
                    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );
                    cpu_mem_move( _environment, address1->realName, address->realName, size1->realName );
                    cpu_math_add_16bit_with_8bit( _environment, address->realName, size1->realName, address->realName );
                    cpu_mem_move( _environment, address2->realName, address->realName, size2->realName );
                    break;
                }
                case VT_STRING: {
                    Variable * address1 = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING1)");
                    Variable * size1 = variable_temporary( _environment, VT_BYTE, "(size of DSTRING1)");
                    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING2)");
                    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of DSTRING2)");
                    Variable * address= variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                    cpu_move_8bit( _environment, source->realName, size1->realName );
                    cpu_addressof_16bit( _environment, source->realName, address1->realName );
                    cpu_inc_16bit( _environment, address1->realName );
                    cpu_math_add_8bit( _environment, size1->realName, size2->realName, size->realName );
                    cpu_dsfree( _environment, result->realName );
                    cpu_dsalloc( _environment, size->realName, result->realName );
                    cpu_mem_move( _environment, address1->realName, address->realName, size1->realName );
                    cpu_math_add_16bit_with_8bit( _environment, address->realName, size1->realName, address->realName );
                    cpu_mem_move( _environment, address2->realName, address->realName, size2->realName );
                    break;
                }
                default: {
                    CRITICAL_ADD_UNSUPPORTED( _source, DATATYPE_AS_STRING[source->type]);
                }
            }
    }
    return result;
}

void variable_add_inplace( Environment * _environment, char * _source, int _destination ) {

    Variable * source = variable_retrieve( _environment, _source );
    if ( source->type == VT_STRING ) {
        source = variable_cast( _environment, _source, VT_DSTRING );
    }

    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            cpu_math_add_32bit_const( _environment, source->realName, _destination, source->realName );
            break;
        case 16:
            cpu_math_add_16bit_const( _environment, source->realName, _destination, source->realName );
            break;
        case 8:
            cpu_math_add_8bit_const( _environment, source->realName, _destination, source->realName );
            break;
        case 0:
            CRITICAL_ADD_INPLACE_UNSUPPORTED( _source, DATATYPE_AS_STRING[source->type]);
    }

}

/**
 * @brief Add two variable and return the sum of them on the first
 * 
 * This function allows you to sum the value of two variables. Note 
 * that both variables must pre-exist before the operation, 
 * under penalty of an exception.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name and destination of sum
 * @param _destination Value to sum
 * @throw EXIT_FAILURE "Destination variable does not cast"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
void variable_add_inplace_vars( Environment * _environment, char * _source, char * _destination ) {

    Variable * source = variable_retrieve( _environment, _source );
    if ( source->type == VT_STRING ) {
        source = variable_cast( _environment, _source, VT_DSTRING );
    }

    Variable * target = variable_cast( _environment, _destination, source->type );
    if ( ! target ) {
        CRITICAL_VARIABLE(_destination);
    }

    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            cpu_math_add_32bit( _environment, source->realName, target->realName, source->realName );
            break;
        case 16:
            cpu_math_add_16bit( _environment, source->realName, target->realName, source->realName );
            break;
        case 8:
            cpu_math_add_8bit( _environment, source->realName, target->realName, source->realName );
            break;
        case 0:
            CRITICAL_ADD_INPLACE_UNSUPPORTED( _source, DATATYPE_AS_STRING[source->type]);
    }

}

/**
 * @brief Add a variable to an array element, and return the sum of them on the array element
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name and destination of sum
 * @param _destination Value to sum
 */
void variable_add_inplace_array( Environment * _environment, char * _source, char * _destination ) {

    Variable * array = variable_retrieve( _environment, _source );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _source );
    }
    Variable * value = variable_move_from_array( _environment, array->name );

    variable_add_inplace_vars( _environment, value->name, _destination );

    variable_move_array( _environment, array->name, value->name );

}


/**
 * @brief Add two variable and return the sum of them on the first
 * 
 * This function allows you to sum the value of two variables. Note 
 * that both variables must pre-exist before the operation, 
 * under penalty of an exception.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name and destination of sum
 * @param _destination Value to sum
 * @throw EXIT_FAILURE "Destination variable does not cast"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
void variable_add_inplace_mt( Environment * _environment, char * _source, char * _destination ) {

    ++((struct _Environment *)_environment)->arrayNestedIndex;
    memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
    ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
    ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    Variable * array = variable_retrieve( _environment, _source );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _source );
    }
    Variable * value = variable_move_from_array( _environment, array->name );
    --((struct _Environment *)_environment)->arrayNestedIndex;

    variable_add_inplace_vars( _environment, value->name, _destination );

    ++((struct _Environment *)_environment)->arrayNestedIndex;
    memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
    ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
    ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    array = variable_retrieve( _environment, _source );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _source );
    }
    variable_move_array( _environment, array->name, value->name );
    --((struct _Environment *)_environment)->arrayNestedIndex;

}

/**
 * @brief Make a differenze between two variable and return the difference of them
 * 
 * This function allows you to difference the value of two variables. Note 
 * that both variables must pre-exist before the operation, 
 * under penalty of an exception.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @return Variable* The sum of source and destination variable
 * @throw EXIT_FAILURE "Destination variable does not cast"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
Variable * variable_sub( Environment * _environment, char * _source, char * _dest ) {
    Variable * source = variable_retrieve( _environment, _source );
    Variable * target = variable_cast( _environment, _dest, source->type );
    Variable * result = variable_temporary( _environment, source->type, "(result of subtracting)" );
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            cpu_math_sub_32bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 16:
            cpu_math_sub_16bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 8:
            cpu_math_sub_8bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 0:
            CRITICAL_SUB_UNSUPPORTED( _source, DATATYPE_AS_STRING[source->type]);
     }
    return result;
}

/**
 * @brief Make a differenze between two variable and assign the difference of them to the first
 * 
 * This function allows you to difference the value of two variables. Note 
 * that both variables must pre-exist before the operation, 
 * under penalty of an exception.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name and destination of the subtraction
 * @param _destination Destination variable's name
 * @throw EXIT_FAILURE "Destination variable does not cast"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
void variable_sub_inplace( Environment * _environment, char * _source, char * _dest ) {
    Variable * source = variable_retrieve( _environment, _source );
    Variable * target = variable_cast( _environment, _dest, source->type );
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            cpu_math_sub_32bit( _environment, source->realName, target->realName, source->realName );
            break;
        case 16:
            cpu_math_sub_16bit( _environment, source->realName, target->realName, source->realName );
            break;
        case 8:
            cpu_math_sub_8bit( _environment, source->realName, target->realName, source->realName );
            break;
        case 0:
            CRITICAL_SUB_INPLACE_UNSUPPORTED( _source, DATATYPE_AS_STRING[source->type]);
     }

}

/**
 * @brief Calculate the complement of a variable
 * 
 * 
 * This function allows you to calculate a complement of the value of one variable. 
 * Note that the variable must pre-exist before the operation, under penalty
 * of an exception.
 * 
 * @pre _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _destination Destination variable's name
 * @param _value Value to use for complement
 * @return Variable* The complement of _destination variable
 * @throw EXIT_FAILURE "Destination variable does not exist"
 */
Variable * variable_complement_const( Environment * _environment, char * _destination, int _value ) {
    Variable * destination = variable_retrieve( _environment, _destination );
    switch( VT_BITWIDTH( destination->type ) ) {
        case 32:
            cpu_math_complement_const_32bit( _environment, destination->realName, _value );
            break;
        case 16:
            cpu_math_complement_const_16bit( _environment, destination->realName, _value );
            break;
        case 8:
            cpu_math_complement_const_8bit( _environment, destination->realName, _value );
            break;
        case 0:
            CRITICAL_COMPLEMENT_UNSUPPORTED( _destination, DATATYPE_AS_STRING[destination->type]);
     }
    return destination;
}

/**
 * @brief Make a multiplication between two variable and return the product of them
 * 
 * This function allows you to multiplicate the value of two variables. Note 
 * that both variables must pre-exist before the operation, 
 * under penalty of an exception.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @return Variable* The product of source and destination variable
 * @throw EXIT_FAILURE "Destination variable does not cast"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
Variable * variable_mul( Environment * _environment, char * _source, char * _destination ) {

    Variable * source = variable_retrieve( _environment, _source );
    Variable * target = variable_retrieve( _environment, _destination );

    if ( VT_SIGNED( source->type ) != VT_SIGNED( target->type ) ) {
        if ( VT_SIGNED( source->type ) ) {
            target = variable_cast( _environment, _destination, source->type );
        } else {
            source = variable_cast( _environment, _source, VT_SIGN( source->type ) );
            target = variable_cast( _environment, _destination, VT_SIGN( source->type ) );
        }
    } else {
        target = variable_cast( _environment, _destination, source->type );
    }

    Variable * result = NULL;
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            WARNING_BITWIDTH(_source, _destination );
            result = variable_temporary( _environment, VT_SIGNED( source->type ) ? VT_SDWORD : VT_DWORD, "(result of multiplication)" );
            #ifdef CPU_BIG_ENDIAN
                {
                    char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+2", source->realName );
                    char targetRealName[MAX_TEMPORARY_STORAGE]; sprintf( targetRealName, "%s+2", target->realName );
                    cpu_math_mul_16bit_to_32bit( _environment, sourceRealName, targetRealName, result->realName, VT_SIGNED( source->type ) );
                }
            #else
                cpu_math_mul_16bit_to_32bit( _environment, source->realName, target->realName, result->realName, VT_SIGNED( source->type ) );
            #endif
            break;
        case 16:
            result = variable_temporary( _environment, VT_SIGNED( source->type ) ? VT_SDWORD : VT_DWORD, "(result of multiplication)" );
            cpu_math_mul_16bit_to_32bit( _environment, source->realName, target->realName, result->realName, VT_SIGNED( source->type ) );
            break;
        case 8:
            result = variable_temporary( _environment, VT_SIGNED( source->type ) ? VT_SWORD : VT_WORD, "(result of multiplication)" );
            cpu_math_mul_8bit_to_16bit( _environment, source->realName, target->realName, result->realName, VT_SIGNED( source->type ) );
            break;
        case 0:
            CRITICAL_MUL_UNSUPPORTED(_source, DATATYPE_AS_STRING[source->type]);
            break;
    }

    return result;
}

/**
 * @brief Make a division between two variable and return the product of them
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @return Variable* The quotient of source and destination variable
 */
/* <usermanual>
@keyword DIV

@english
The ''DIV'' statement allows you to make a division using the dividend 
as a variable where the result will be stored. Optionally, it is possible 
to indicate a variable where to store the remainder of the division operation. 

@italian
L'istruzione ''DIV'' consente di effettuare una divisione utilizzando il 
dividendo come variabile dove sarà memorizzato il risultato. In opzione, 
è possibile indicare una variabile dove memorizzare il resto dell'operazione 
di divisione.

@syntax DIV [variable],[divisor]
@syntax DIV [variable],[divisor],[remainder]

@example DIV a,2
@example DIV a,3,q

@usedInExample contrib_sierpinski3.bas

@target all
</usermanual> */
Variable * variable_div( Environment * _environment, char * _source, char * _destination, char * _remainder ) {
    Variable * source = variable_retrieve( _environment, _source );
    Variable * target = variable_retrieve( _environment, _destination );

    if ( VT_SIGNED( source->type ) != VT_SIGNED( target->type ) ) {
        if ( VT_SIGNED( source->type ) ) {
            target = variable_cast( _environment, _destination, source->type );
        } else {
            source = variable_cast( _environment, _source, VT_SIGN( source->type ) );
            target = variable_cast( _environment, _destination, VT_SIGN( source->type ) );
        }
    } else {
        target = variable_cast( _environment, _destination, source->type );
    }

    Variable * result = NULL;
    Variable * remainder = NULL;
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            result = variable_temporary( _environment, VT_SIGNED( source->type ) ? VT_SWORD : VT_WORD, "(result of division)" );
            remainder = variable_temporary( _environment, VT_SIGNED( source->type ) ? VT_SWORD : VT_WORD, "(remainder of division)" );
            cpu_math_div_32bit_to_16bit( _environment, source->realName, target->realName, result->realName, remainder->realName, VT_SIGNED( source->type ) );
            break;
        case 16:
            result = variable_temporary( _environment, VT_SIGNED( source->type ) ? VT_SWORD : VT_WORD, "(result of division)" );
            remainder = variable_temporary( _environment, VT_SIGNED( source->type ) ? VT_SWORD : VT_WORD, "(remainder of division)" );
            cpu_math_div_16bit_to_16bit( _environment, source->realName, target->realName, result->realName, remainder->realName, VT_SIGNED( source->type ) );
            break;
        case 8:
            result = variable_temporary( _environment, VT_SIGNED( source->type ) ? VT_SBYTE : VT_BYTE, "(result of division)" );
            remainder = variable_temporary( _environment, VT_SIGNED( source->type ) ? VT_SBYTE : VT_BYTE, "(remainder of division)" );
            cpu_math_div_8bit_to_8bit( _environment, source->realName, target->realName, result->realName, remainder->realName, VT_SIGNED( source->type ) );
            break;
        case 0:
            CRITICAL_DIV_UNSUPPORTED(_source, DATATYPE_AS_STRING[source->type]);
            break;
    }

    if ( _remainder ) {
        variable_move( _environment, remainder->name, _remainder );
    }
    
    return result;
}

/**
 * @brief Increment a variable by one
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @return Variable* The source variable
 */
/* <usermanual>
@keyword INC

@english
The ''INC'' command allows you to increase a variable by one. 
This is much more efficient than using the standard syntax ''v = v + 1''.

@italian
Il comando ''INC'' permette di incrementare di uno una variabile. 
Tale operazione è assai più efficiente che utilizzare la sintassi standard ''v = v + 1''.

@syntax INC [variable]

@example INC v

@usedInExample contrib_sierpinski3.bas

@target all
</usermanual> */
Variable * variable_increment( Environment * _environment, char * _source ) {
    Variable * source = variable_retrieve( _environment, _source );
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
        case 0:
            CRITICAL_DATATYPE_UNSUPPORTED("INC", DATATYPE_AS_STRING[source->type])
            break;
        case 16:
            cpu_inc_16bit( _environment, source->realName );
            break;
        case 8:
            cpu_inc( _environment, source->realName );
            break;
    }
    return source;
}

/**
 * @brief Increment a variable by one
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @return Variable* The source variable
 */
Variable * variable_increment_array( Environment * _environment, char * _source ) {

    Variable * array = variable_retrieve( _environment, _source );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _source );
    }
    Variable * value = variable_move_from_array( _environment, array->name );

    variable_increment( _environment, value->name );

    variable_move_array( _environment, array->name, value->name );

    return value;

}

/**
 * @brief Increment a variable by one
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @return Variable* The source variable
 */
Variable * variable_increment_mt( Environment * _environment, char * _source ) {

    ++((struct _Environment *)_environment)->arrayNestedIndex;
    memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
    ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
    ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    Variable * array = variable_retrieve( _environment, _source );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _source );
    }
    Variable * value = variable_move_from_array( _environment, array->name );
    --((struct _Environment *)_environment)->arrayNestedIndex;

    variable_increment( _environment, value->name );

    ++((struct _Environment *)_environment)->arrayNestedIndex;
    memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
    ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
    ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    array = variable_retrieve( _environment, _source );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _source );
    }
    variable_move_array( _environment, array->name, value->name );
    --((struct _Environment *)_environment)->arrayNestedIndex;

    return value;
    
}

/**
 * @brief Decrement a variable by one
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @return Variable* The source variable
 */
Variable * variable_decrement( Environment * _environment, char * _source ) {
    Variable * source = variable_retrieve( _environment, _source );
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
        case 0:
            CRITICAL_DATATYPE_UNSUPPORTED("DEC", DATATYPE_AS_STRING[source->type])
            break;
        case 16:
            cpu_dec_16bit( _environment, source->realName );
            break;
        case 8:
            cpu_dec( _environment, source->realName );
            break;
    }
    return source;
}

/**
 * @brief Decrement a variable by one
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @return Variable* The source variable
 */
Variable * variable_decrement_array( Environment * _environment, char * _source ) {

    Variable * array = variable_retrieve( _environment, _source );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _source );
    }
    Variable * value = variable_move_from_array( _environment, array->name );

    variable_decrement( _environment, value->name );

    variable_move_array( _environment, array->name, value->name );

    return value;


}

/**
 * @brief Decrement a variable by one
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @return Variable* The source variable
 */
Variable * variable_decrement_mt( Environment * _environment, char * _source ) {

    ++((struct _Environment *)_environment)->arrayNestedIndex;
    memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
    ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
    ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    Variable * array = variable_retrieve( _environment, _source );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _source );
    }
    Variable * value = variable_move_from_array( _environment, array->name );
    --((struct _Environment *)_environment)->arrayNestedIndex;

    variable_decrement( _environment, value->name );

    ++((struct _Environment *)_environment)->arrayNestedIndex;
    memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
    ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
    ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    array = variable_retrieve( _environment, _source );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _source );
    }
    variable_move_array( _environment, array->name, value->name );
    --((struct _Environment *)_environment)->arrayNestedIndex;

    return value;

}

/**
 * @brief Compare two variable and return the result of comparation
 * 
 * This function allows you to compare the value of two variables. Note 
 * that both variables must pre-exist before the operation, 
 * under penalty of an exception.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @return Variable* The product of source and destination variable
 * @throw EXIT_FAILURE "Destination variable does not cast"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
Variable * variable_compare( Environment * _environment, char * _source, char * _destination ) {
    Variable * source = variable_retrieve( _environment, _source );
    Variable * target = variable_retrieve( _environment, _destination );

    if ( VT_SIGNED( source->type ) != VT_SIGNED( target->type ) ) {
        if ( VT_SIGNED( source->type ) ) {
            target = variable_cast( _environment, _destination, source->type );
        } else {
            source = variable_cast( _environment, _source, VT_SIGN( source->type ) );
            target = variable_cast( _environment, _destination, VT_SIGN( source->type ) );
        }
    } else {
        target = variable_cast( _environment, _destination, source->type );
    }

    MAKE_LABEL

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of compare)" );
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            switch( VT_BITWIDTH( target->type ) ) {
                case 32:
                    cpu_compare_32bit( _environment, source->realName, target->realName, result->realName, 1 );
                    break;
                case 16:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+2", source->realName );
                            cpu_compare_16bit( _environment, sourceRealName, target->realName, result->realName, 1 );
                        }
                    #else
                        cpu_compare_16bit( _environment, source->realName, target->realName, result->realName, 1 );
                    #endif
                    break;
                case 8:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+3", source->realName );
                            cpu_compare_8bit( _environment, sourceRealName, target->realName, result->realName, 1 );
                        }
                    #else
                        cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 1 );
                    #endif
                    break;
                case 0:
                    CRITICAL_CANNOT_COMPARE(DATATYPE_AS_STRING[source->type],DATATYPE_AS_STRING[target->type]);
            }
            break;
        case 16:
            switch( VT_BITWIDTH( target->type ) ) {
                case 32:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE]; sprintf( targetRealName, "%s+2", target->realName );
                        cpu_compare_16bit( _environment, source->realName, targetRealName, result->realName, 1 );
                        }
                    #else
                        cpu_compare_16bit( _environment, source->realName, target->realName, result->realName, 1 );
                    #endif
                    break;
                case 16:
                    cpu_compare_16bit( _environment, source->realName, target->realName, result->realName, 1 );
                    break;
                case 8:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+1", source->realName );
                            cpu_compare_8bit( _environment, sourceRealName, target->realName, result->realName, 1 );
                        }
                    #else                      
                        cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 1 );
                    #endif
                    break;
                case 0:
                    CRITICAL_CANNOT_COMPARE(DATATYPE_AS_STRING[source->type],DATATYPE_AS_STRING[target->type]);
            }
            break;
        case 8:
            switch( VT_BITWIDTH( target->type ) ) {
                case 32:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE]; sprintf( targetRealName, "%s+3", target->realName );
                            cpu_compare_8bit( _environment, source->realName, targetRealName, result->realName, 1 );
                        }
                    #else                      
                        cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 1 );
                    #endif
                    break;
                case 16:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE]; sprintf( targetRealName, "%s+1", target->realName );
                            cpu_compare_8bit( _environment, source->realName, targetRealName, result->realName, 1 );
                        }
                    #else                      
                        cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 1 );
                    #endif
                    break;
                case 8:
                    cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 1 );
                    break;
                case 0:
                    CRITICAL_CANNOT_COMPARE(DATATYPE_AS_STRING[source->type],DATATYPE_AS_STRING[target->type]);
            }
            break;
        case 0:
            switch( source->type ) {
                case VT_STRING:
                    switch( target->type ) {
                        case VT_STRING: {
                            cpu_compare_memory( _environment, source->realName, target->realName, source->realName, result->realName, 1 );
                            break;
                        }
                        case VT_DSTRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_move_8bit( _environment, source->realName, size->realName );
                            cpu_dsdescriptor( _environment, target->realName, address2->realName, size2->realName );
                            cpu_compare_8bit( _environment, size->realName, size2->realName, result->realName, 1 );
                            cpu_bveq( _environment, result->realName, differentLabel );
                            cpu_addressof_16bit( _environment, source->realName, address->realName );
                            cpu_inc_16bit(  _environment, address->realName );
                            cpu_compare_memory( _environment, address->realName, address2->realName, size->realName, result->realName, 1 );
                            cpu_label( _environment, differentLabel );
                            break;
                        }
                        case VT_IMAGE:
                        case VT_IMAGES:
                        case VT_SEQUENCE:
                        case VT_MUSIC:
                        case VT_BUFFER:
                        default:
                            CRITICAL_CANNOT_COMPARE(DATATYPE_AS_STRING[source->type],DATATYPE_AS_STRING[target->type]);
                            break;
                    }
                    break;
                case VT_DSTRING:
                    switch( target->type ) {
                        case VT_STRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_move_8bit( _environment, target->realName, size2->realName );
                            cpu_dsdescriptor( _environment, source->realName, address->realName, size->realName );
                            cpu_compare_8bit( _environment, size->realName, size2->realName, result->realName, 1 );
                            cpu_bveq( _environment, result->realName, differentLabel );
                            cpu_addressof_16bit( _environment, target->realName, address2->realName );
                            cpu_inc_16bit(  _environment, address2->realName );
                            cpu_compare_memory( _environment, address->realName, address2->realName, size->realName, result->realName, 1 );
                            cpu_label( _environment, differentLabel );
                            break;
                        }
                        case VT_DSTRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_dsdescriptor( _environment, source->realName, address->realName, size->realName );
                            cpu_dsdescriptor( _environment, target->realName, address2->realName, size2->realName );
                            cpu_compare_8bit( _environment, size->realName, size2->realName, result->realName, 1 );
                            cpu_bveq( _environment, result->realName, differentLabel );
                            cpu_compare_memory( _environment, address->realName, address2->realName, size->realName, result->realName, 1 );
                            cpu_label( _environment, differentLabel );
                            break;
                        }
                        default:
                            CRITICAL_CANNOT_COMPARE(DATATYPE_AS_STRING[source->type],DATATYPE_AS_STRING[target->type]);
                            break;
                    }
                    break;
                case VT_IMAGE:
                case VT_IMAGES:
                case VT_SEQUENCE:
                case VT_MUSIC:
                case VT_BUFFER:
                    switch( target->type ) {
                        case VT_BUFFER:
                        case VT_IMAGE:
                        case VT_IMAGES:
                        case VT_SEQUENCE:
                        case VT_MUSIC:
                            cpu_compare_memory_size( _environment, source->realName, target->realName, source->size, result->realName, 1 );
                            break;
                        default:
                        case VT_DSTRING:
                        case VT_STRING:
                            CRITICAL_CANNOT_COMPARE(DATATYPE_AS_STRING[source->type],DATATYPE_AS_STRING[target->type]);
                            break;
                    }
                    break;
                default:
                    CRITICAL_CANNOT_COMPARE(DATATYPE_AS_STRING[source->type],DATATYPE_AS_STRING[target->type]);
            }
            break;
    }
    return result;
}

/**
 * @brief Compare two variable and return the result of comparation
 * 
 * This function allows you to compare the value of two variables. Note 
 * that both variables must pre-exist before the operation, 
 * under penalty of an exception.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @return Variable* The product of source and destination variable
 * @throw EXIT_FAILURE "Destination variable does not cast"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
Variable * variable_compare_not( Environment * _environment, char * _source, char * _destination ) {
    return variable_not( _environment, variable_compare( _environment, _source, _destination)->name );
}

/**
 * @brief Double a variable for various times and return the result
 * 
 * This function allows you to double the value of a
 * variable for various times. Note that variable
 * must pre-exist before the operation, under penalty 
 * of an exception.
 * 
 * @pre _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _destination Destination variable's name
 * @return Variable* The result of operation
 * @throw EXIT_FAILURE "Destination variable does not exist"
 */
Variable * variable_mul2_const( Environment * _environment, char * _destination, int _steps ) {

    if ( _steps < 0 ) {
        CRITICAL_MUL2_INVALID_STEPS( _destination );
    }

    Variable * destination = variable_retrieve( _environment, _destination );    

    if ( _steps == 0 ) {
        return destination;
    }

    Variable * result = variable_temporary( _environment, destination->type, "(mul2)" );    
    variable_move_naked( _environment, destination->name, result->name );

    switch( VT_BITWIDTH( destination->type ) ) {
        case 32:
            cpu_math_mul2_const_32bit( _environment, result->realName, _steps, VT_SIGNED( destination->type ) );
            break;
        case 16:
            cpu_math_mul2_const_16bit( _environment, result->realName, _steps, VT_SIGNED( destination->type ) );
            break;
        case 8:
            cpu_math_mul2_const_8bit( _environment, result->realName, _steps, VT_SIGNED( destination->type ) );
            break;
        case 0:
            CRITICAL_MUL2_UNSUPPORTED( _destination, DATATYPE_AS_STRING[destination->type] );
            break;
    }
    return result;
}

/**
 * @brief Subdivide by two a variable for various times and return the result
 * 
 * This function allows you to subdivide the value of a
 * variable for two for various times. Note that variable
 * must pre-exist before the operation, under penalty 
 * of an exception.
 * 
 * @pre _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _destination Destination variable's name
 * @param _bits Times to subdivide
 * @return Variable* The result of operation
 * @throw EXIT_FAILURE "Destination variable does not exist"
 */
Variable * variable_div2_const( Environment * _environment, char * _destination, int _bits ) {
    Variable * destination = variable_retrieve( _environment, _destination );    
    Variable * result = variable_temporary( _environment, destination->type, "(div2)" );    
    variable_move_naked( _environment, destination->name, result->name );

    switch( VT_BITWIDTH( destination->type ) ) {
        case 32:
            cpu_math_div2_const_32bit( _environment, result->realName, _bits, VT_SIGNED( destination->type ) );
            break;
        case 16:
            cpu_math_div2_const_16bit( _environment, result->realName, _bits, VT_SIGNED( destination->type ) );
            break;
        case 8:
            cpu_math_div2_const_8bit( _environment, result->realName, _bits, VT_SIGNED( destination->type ) );
            break;
        case 0:
            CRITICAL_DIV2_UNSUPPORTED( _destination, DATATYPE_AS_STRING[destination->type] );
            break;
    }
    return result;
}

/**
 * @brief Calculate "and" mask for a variable and it as the result
 * 
 * This function allows you to subdivide the value of a
 * variable for two for various times. Note that variable
 * must pre-exist before the operation, under penalty 
 * of an exception.
 * 
 * @pre _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _destination Destination variable's name
 * @param _mask And mask to apply
 * @return Variable* The result of operation
 * @throw EXIT_FAILURE "Destination variable does not exist"
 */
Variable * variable_and_const( Environment * _environment, char * _destination, int _mask ) {
    Variable * destination = variable_retrieve( _environment, _destination );
    switch( VT_BITWIDTH( destination->type ) ) {
        case 32:
            cpu_math_and_const_32bit( _environment, destination->realName, _mask );
            break;
        case 16:
            cpu_math_and_const_16bit( _environment, destination->realName, _mask );
            break;
        case 8:
            cpu_math_and_const_8bit( _environment, destination->realName, _mask );
            break;
        case 0:
            CRITICAL_AND_UNSUPPORTED( _destination, DATATYPE_AS_STRING[destination->type] );
            break;

    }
    return destination;
}

/**
 * @brief Calculate logical "and" and return it as the result
 * 
 * This function allows you to emit code to make a logical
 * AND between two expressions, and return the result
 * as boolean.
 * 
 * @param _environment Current calling environment
 * @param _left Left expression to check
 * @param _right Right expression to check
 * @return Variable* The result of operation
 */
Variable * variable_and( Environment * _environment, char * _left, char * _right ) {

    Variable * source = variable_retrieve( _environment, _left );
    Variable * target = variable_cast( _environment, _right, source->type );
    if ( ! target ) {
        CRITICAL_VARIABLE(_right);
    }

    Variable * result = variable_temporary( _environment, source->type, "(result of OR)" );

    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            cpu_and_32bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 16:
            cpu_and_16bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 8:
            cpu_and_8bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 0:
            CRITICAL_AND_UNSUPPORTED( _left, DATATYPE_AS_STRING[source->type]);
    }

    return result;
}

/**
 * @brief Calculate logical "or" and return it as the result
 * 
 * This function allows you to emit code to make a logical
 * OR between two expressions, and return the result
 * as boolean.
 * 
 * @param _environment Current calling environment
 * @param _left Left expression to check
 * @param _right Right expression to check
 * @return Variable* The result of operation
 */
Variable * variable_or( Environment * _environment, char * _left, char * _right ) {

    Variable * source = variable_retrieve( _environment, _left );
    Variable * target = variable_cast( _environment, _right, source->type );
    if ( ! target ) {
        CRITICAL_VARIABLE(_right);
    }

    Variable * result = variable_temporary( _environment, source->type, "(result of OR)" );

    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            cpu_or_32bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 16:
            cpu_or_16bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 8:
            cpu_or_8bit( _environment, source->realName, target->realName, result->realName );
            break;
        case 0:
            CRITICAL_OR_UNSUPPORTED( _left, DATATYPE_AS_STRING[source->type]);
    }

    return result;

}

/**
 * @brief Calculate logical "not" and return it as the result
 * 
 * This function allows you to emit code to make a logical
 * OR between two expressions, and return the result
 * as boolean.
 * 
 * @param _environment Current calling environment
 * @param _value Left expression to check
 * @return Variable* The result of operation
 */
Variable * variable_not( Environment * _environment, char * _value ) {

    Variable * source = variable_retrieve( _environment, _value );

    Variable * result = variable_temporary( _environment, source->type, "(result of OR)" );

    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            cpu_not_32bit( _environment, source->realName, result->realName );
            break;
        case 16:
            cpu_not_16bit( _environment, source->realName, result->realName );
            break;
        case 8:
            cpu_not_8bit( _environment, source->realName, result->realName );
            break;
        case 0:
            CRITICAL_NOT_UNSUPPORTED( _value, DATATYPE_AS_STRING[source->type]);
    }

    return result;

}

/**
 * @brief Compare two variable and return the result of comparation
 * 
 * This function allows you to compare the value of two variables. Note 
 * that both variables must pre-exist before the operation, 
 * under penalty of an exception.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @param _equal True if equal
 * @return Variable* The product of source and destination variable
 * @throw EXIT_FAILURE "Destination variable does not cast"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
Variable * variable_less_than( Environment * _environment, char * _source, char * _destination, int _equal ) {

    MAKE_LABEL

    Variable * source = variable_retrieve( _environment, _source );
    Variable * target = variable_retrieve( _environment, _destination );

    if ( VT_SIGNED( source->type ) != VT_SIGNED( target->type ) ) {
        if ( VT_SIGNED( source->type ) ) {
            target = variable_cast( _environment, _destination, source->type );
        } else {
            source = variable_cast( _environment, _source, VT_SIGN( source->type ) );
            target = variable_cast( _environment, _destination, VT_SIGN( source->type ) );
        }
    } else {
        target = variable_cast( _environment, _destination, source->type );
    }

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of compare)" );
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            switch( VT_BITWIDTH( target->type ) ) {
                case 32:
                    cpu_less_than_32bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    break;
                case 16:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+2", source->realName );
                            cpu_less_than_16bit( _environment, sourceRealName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                        }
                    #else                      
                        cpu_less_than_16bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    #endif
                    break;
                case 8:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+3", source->realName );
                            cpu_less_than_8bit( _environment, sourceRealName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                        }
                    #else                      
                        cpu_less_than_8bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    #endif
                    break;
                case 0:
                    CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );
            }
            break;
        case 16:
            switch( VT_BITWIDTH( target->type ) ) {
                case 32:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE]; sprintf( targetRealName, "%s+2", target->realName );
                            cpu_less_than_16bit( _environment, source->realName, targetRealName, result->realName, _equal, VT_SIGNED( source->type ) );
                        }
                    #else                      
                        cpu_less_than_16bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    #endif
                    break;
                case 16:
                    cpu_less_than_16bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    break;
                case 8:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+1", source->realName );
                            cpu_less_than_8bit( _environment, sourceRealName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                        }
                    #else                      
                        cpu_less_than_8bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    #endif
                    break;
                case 0:
                    CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );
            }
            break;
        case 8:
            switch( VT_BITWIDTH( target->type ) ) {
                case 32:
                case 16:
                    WARNING_BITWIDTH( _source, _destination );
                    if ( VT_SIGNED( source->type ) ) {
                        CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );
                    }
                    cpu_less_than_8bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    break;
                case 8:
                    cpu_less_than_8bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    break;
                case 0:
                    CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );
            }
            break;
        case 0:
            switch( source->type ) {
                case VT_STRING:
                    switch( target->type ) {
                        case VT_STRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_move_8bit( _environment, source->realName, size->realName );
                            cpu_move_8bit( _environment, target->realName, size2->realName );
                            cpu_less_than_8bit( _environment, size->realName, size2->realName, result->realName, _equal, 0 );
                            cpu_bveq( _environment, result->realName, differentLabel );
                            cpu_addressof_16bit( _environment, source->realName, address->realName );
                            cpu_inc_16bit(  _environment, address->realName );
                            cpu_addressof_16bit( _environment, target->realName, address2->realName );
                            cpu_inc_16bit(  _environment, address2->realName );
                            cpu_less_than_memory( _environment, address->realName, address2->realName, size->realName, result->realName, _equal );
                            cpu_label( _environment, differentLabel );
                            break;
                        }
                        case VT_DSTRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_move_8bit( _environment, source->realName, size->realName );
                            cpu_dsdescriptor( _environment, target->realName, address2->realName, size2->realName );
                            cpu_less_than_8bit( _environment, size->realName, size2->realName, result->realName, 1, 0 );
                            cpu_bveq( _environment, result->realName, differentLabel );
                            cpu_addressof_16bit( _environment, source->realName, address->realName );
                            cpu_inc_16bit(  _environment, address->realName );
                            cpu_less_than_memory( _environment, address->realName, address2->realName, size->realName, result->realName, 1 );
                            cpu_label( _environment, differentLabel );
                            break;
                        }
                        default:
                            CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );        
                    }
                    break;
                case VT_DSTRING:
                    switch( target->type ) {
                        case VT_STRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_move_8bit( _environment, target->realName, size2->realName );
                            cpu_dsdescriptor( _environment, source->realName, address->realName, size->realName );
                            cpu_less_than_8bit( _environment, size->realName, size2->realName, result->realName, 1, 0 );
                            cpu_bveq( _environment, result->realName, differentLabel );
                            cpu_addressof_16bit( _environment, target->realName, address2->realName );
                            cpu_inc_16bit(  _environment, address2->realName );
                            cpu_less_than_memory( _environment, address->realName, address2->realName, size->realName, result->realName, 1 );
                            cpu_label( _environment, differentLabel );
                            break;
                        }
                        case VT_DSTRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_dsdescriptor( _environment, source->realName, address->realName, size->realName );
                            cpu_dsdescriptor( _environment, target->realName, address2->realName, size2->realName );
                            cpu_less_than_8bit( _environment, size->realName, size2->realName, result->realName, _equal, 0 );
                            cpu_bveq( _environment, result->realName, differentLabel );
                            cpu_less_than_memory( _environment, address->realName, address2->realName, size->realName, result->realName, _equal );
                            cpu_label( _environment, differentLabel );
                            break;
                        }
                        default:
                            CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );        
                    }
                    break;
                case VT_IMAGE:
                case VT_IMAGES:
                case VT_SEQUENCE:
                case VT_MUSIC:
                case VT_BUFFER:
                    switch( target->type ) {
                        case VT_BUFFER:
                        case VT_IMAGE:
                        case VT_IMAGES:
                        case VT_SEQUENCE:
                        case VT_MUSIC:
                            cpu_less_than_memory_size( _environment, source->realName, target->realName, source->size, result->realName, _equal );
                            break;
                        default:                
                            CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );        
                    }
                    break;
                default:
                    CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );
            }
            break;
    }
    return result;
}

Variable * variable_less_than_const( Environment * _environment, char * _source, int _destination, int _equal ) {

    MAKE_LABEL

    Variable * source = variable_retrieve( _environment, _source );

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of compare)" );
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            cpu_less_than_32bit_const( _environment, source->realName, _destination, result->realName, _equal, VT_SIGNED( source->type ) );
            break;
        case 16:
            cpu_less_than_16bit_const( _environment, source->realName, _destination, result->realName, _equal, VT_SIGNED( source->type ) );
            break;
        case 8:
            cpu_less_than_8bit_const( _environment, source->realName, _destination, result->realName, _equal, VT_SIGNED( source->type ) );
            break;
        default:
            CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], "(const integer)" );
            break;
    }
    return result;
}

/**
 * @brief Compare two variable and return the result of comparation
 * 
 * This function allows you to compare the value of two variables. Note 
 * that both variables must pre-exist before the operation, 
 * under penalty of an exception.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @param _equal True if equal
 * @return Variable* The product of source and destination variable
 * @throw EXIT_FAILURE "Destination variable does not cast"
 * @throw EXIT_FAILURE "Source variable does not exist"
 */
Variable * variable_greater_than( Environment * _environment, char * _source, char * _destination, int _equal ) {

    MAKE_LABEL

    Variable * source = variable_retrieve( _environment, _source );
    Variable * target = variable_retrieve( _environment, _destination );

    if ( VT_SIGNED( source->type ) != VT_SIGNED( target->type ) ) {
        if ( VT_SIGNED( source->type ) ) {
            target = variable_cast( _environment, _destination, source->type );
        } else {
            source = variable_cast( _environment, _source, VT_SIGN( source->type ) );
            target = variable_cast( _environment, _destination, VT_SIGN( source->type ) );
        }
    } else {
        target = variable_cast( _environment, _destination, source->type );
    }

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of compare)" );
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            switch( VT_BITWIDTH( target->type) ) {
                case 32:
                    cpu_greater_than_32bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    break;
                case 16:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+2", source->realName );
                            cpu_greater_than_16bit( _environment, sourceRealName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                        }
                    #else                      
                        cpu_greater_than_16bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    #endif
                    break;
                case 8:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+3", source->realName );
                            cpu_greater_than_8bit( _environment, sourceRealName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                        }
                    #else                      
                        cpu_greater_than_8bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    #endif
                    break;
                case 0:
                    CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );        
            }
            break;
        case 16:
            switch( VT_BITWIDTH( target->type) ) {
                case 32:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE]; sprintf( targetRealName, "%s+2", target->realName );
                            cpu_greater_than_16bit( _environment, source->realName, targetRealName, result->realName, _equal, VT_SIGNED( source->type ) );
                        }
                    #else                      
                        cpu_greater_than_16bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    #endif
                    break;
                case 16:
                    cpu_greater_than_16bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    break;
                case 8:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char sourceRealName[MAX_TEMPORARY_STORAGE]; sprintf( sourceRealName, "%s+1", source->realName );
                            cpu_greater_than_8bit( _environment, sourceRealName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                        }
                    #else                      
                        cpu_greater_than_8bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    #endif
                    break;
                case 0:
                    CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );        
            }
            break;
        case 8:
            switch( VT_BITWIDTH( target->type) ) {
                case 32:
                    WARNING_BITWIDTH( _source, _destination );
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE]; sprintf( targetRealName, "%s+3", target->realName );
                            cpu_greater_than_8bit( _environment, source->realName, targetRealName, result->realName, _equal, VT_SIGNED( source->type ) );
                        }
                    #else                      
                        cpu_greater_than_8bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    #endif
                    break;
                case 16:
                    #ifdef CPU_BIG_ENDIAN
                        {
                            char targetRealName[MAX_TEMPORARY_STORAGE]; sprintf( targetRealName, "%s+1", target->realName );
                            cpu_greater_than_8bit( _environment, source->realName, targetRealName, result->realName, _equal, VT_SIGNED( source->type ) );
                        }
                    #else                      
                        cpu_greater_than_8bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    #endif
                    break;
                case 8:
                    cpu_greater_than_8bit( _environment, source->realName, target->realName, result->realName, _equal, VT_SIGNED( source->type ) );
                    break;
                case 0:
                    CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );        
            }
            break;
        case 0:
            switch( source->type ) {
                case VT_STRING:
                    switch( target->type ) {
                        case VT_STRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf(doneLabel, "%sdone", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_move_8bit( _environment, source->realName, size->realName );
                            cpu_move_8bit( _environment, target->realName, size2->realName );
                            cpu_compare_8bit( _environment, size->realName, size2->realName, result->realName, 1 );
                            cpu_bveq( _environment, result->realName, differentLabel );

                            cpu_addressof_16bit( _environment, source->realName, address->realName );
                            cpu_inc_16bit(  _environment, address->realName );
                            cpu_addressof_16bit( _environment, target->realName, address2->realName );
                            cpu_inc_16bit(  _environment, address2->realName );
                            cpu_greater_than_memory( _environment, address->realName, address2->realName, size->realName, result->realName, _equal );
                            cpu_jump( _environment, doneLabel );

                            cpu_label( _environment, differentLabel );
                            cpu_greater_than_8bit( _environment, size->realName, size2->realName, result->realName, _equal, 0 );
                            cpu_label( _environment, doneLabel );
                            break;
                        }
                        case VT_DSTRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf(doneLabel, "%sdone", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_move_8bit( _environment, source->realName, size->realName );
                            cpu_dsdescriptor( _environment, target->realName, address2->realName, size2->realName );
                            cpu_compare_8bit( _environment, size->realName, size2->realName, result->realName, 1 );
                            cpu_bveq( _environment, result->realName, differentLabel );

                            cpu_addressof_16bit( _environment, source->realName, address->realName );
                            cpu_inc_16bit(  _environment, address->realName );
                            cpu_greater_than_memory( _environment, address->realName, address2->realName, size->realName, result->realName, 1 );
                            cpu_jump( _environment, doneLabel );

                            cpu_label( _environment, differentLabel );
                            cpu_greater_than_8bit( _environment, size->realName, size2->realName, result->realName, 1, 0 );
                            cpu_bveq( _environment, result->realName, differentLabel );
                            cpu_label( _environment, doneLabel );
                        }
                        
                        default:
                            CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );        
                    }
                    break;
                case VT_DSTRING:
                    switch( target->type ) {
                        case VT_STRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf(doneLabel, "%sdone", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_move_8bit( _environment, target->realName, size->realName );
                            cpu_dsdescriptor( _environment, source->realName, address->realName, size->realName );
                            cpu_compare_8bit( _environment, size->realName, size2->realName, result->realName, 1 );
                            cpu_bveq( _environment, result->realName, differentLabel );

                            cpu_addressof_16bit( _environment, target->realName, address2->realName );
                            cpu_inc_16bit(  _environment, address2->realName );
                            cpu_greater_than_memory( _environment, address->realName, address2->realName, size->realName, result->realName, 1 );
                            cpu_jump( _environment, doneLabel );

                            cpu_label( _environment, differentLabel );
                            cpu_greater_than_8bit( _environment, size->realName, size2->realName, result->realName, 1, 0 );
                            cpu_bveq( _environment, result->realName, differentLabel );
                            cpu_label( _environment, doneLabel );
                            break;
                        }
                        case VT_DSTRING: {
                            char differentLabel[MAX_TEMPORARY_STORAGE]; sprintf(differentLabel, "%s", label );
                            char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf(doneLabel, "%sdone", label );
                            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
                            Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
                            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address of STRING)");
                            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size of STRING)");
                            cpu_dsdescriptor( _environment, source->realName, address->realName, size->realName );
                            cpu_dsdescriptor( _environment, target->realName, address2->realName, size2->realName );
                            cpu_compare_8bit( _environment, size->realName, size2->realName, result->realName, 1 );
                            cpu_bveq( _environment, result->realName, differentLabel );

                            cpu_greater_than_memory( _environment, address->realName, address2->realName, size->realName, result->realName, 1 );
                            cpu_jump( _environment, doneLabel );

                            cpu_label( _environment, differentLabel );
                            cpu_greater_than_8bit( _environment, size->realName, size2->realName, result->realName, 1, 0 );
                            cpu_bveq( _environment, result->realName, differentLabel );
                            cpu_label( _environment, doneLabel );
                            
                            break;
                        }
                        default:
                            CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );        
                    }
                    break;
                case VT_IMAGE:
                case VT_IMAGES:
                case VT_SEQUENCE:
                case VT_MUSIC:
                case VT_BUFFER:
                    switch( target->type ) {
                        case VT_BUFFER:
                        case VT_IMAGE:
                        case VT_IMAGES:
                        case VT_SEQUENCE:
                        case VT_MUSIC:
                            cpu_greater_than_memory_size( _environment, source->realName, target->realName, source->size, result->realName, _equal );
                            break;
                        default:                
                            CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );        
                    }
                    break;
                default:
                    CRITICAL_CANNOT_COMPARE( DATATYPE_AS_STRING[source->type], DATATYPE_AS_STRING[target->type] );        
            }
            break;            
    }
    return result;
}

/**
 * @brief Emit code for <b>= LEFT( ..., ... )</b>
 * 
 * @param _environment Current calling environment
 * @param _string String to extract text from
 * @param _position Position to start from
 * @return Variable* Result of text extraction
 */
/* <usermanual>
@keyword LEFT

@english
This function reads the specified number of characters from a source string, 
starting from the left-hand side, and copies them into a destination string,
that is returned. The first type of usage of this function creates a new 
destination string from the chosen number of characters of the source string.
The second usage is to replace the leftmost number of characters:

@italian
Questa funzione legge il numero di caratteri specificato da una stringa di origine, 
a partire dall'inizio, e li copia in una stringa di destinazione, che viene 
restituita. Il primo tipo di utilizzo di questa funzione crea una nuova stringa 
di destinazione dal numero di caratteri scelto della stringa di origine. 
Il secondo utilizzo è sostituire il numero di caratteri più a sinistra:

@syntax = LEFT( [text], [position] )

@example x = LEFT( "TEST", 2 )
@usedInExample strings_left_01.bas
@usedInExample strings_left_02.bas

@seeAlso RIGHT
@seeAlso MID

@target all
 </usermanual> */
Variable * variable_string_left( Environment * _environment, char * _string, char * _position ) {
    Variable * string = variable_retrieve( _environment, _string );
    Variable * position = variable_retrieve_or_define( _environment, _position, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of left)" );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of left)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of left)" );

    cpu_dsfree( _environment, result->realName );
    cpu_dsalloc( _environment, position->realName, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    switch( string->type ) {
        case VT_STRING: {            
            Variable * temporary = variable_temporary( _environment, VT_DSTRING, "(temporary)");
            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of left)" );
            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of left)" );
            cpu_dsdefine( _environment, string->realName, temporary->realName );
            cpu_dsdescriptor( _environment, temporary->realName, address2->realName, size2->realName );
            cpu_mem_move( _environment, address2->realName, address->realName, size->realName );
            break;
        }
        case VT_DSTRING: {            
            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of left)" );
            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of left)" );
            cpu_dsdescriptor( _environment, string->realName, address2->realName, size2->realName );
            cpu_mem_move( _environment, address2->realName, address->realName, size->realName );
            break;
        }
        default:
            CRITICAL_LEFT_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
            break;
    }
    return result;
}

/**
 * @brief Emit code for <b>LEFT( ..., ... ) = ...</b>
 * 
 * @param _environment Current calling environment
 * @param _string String to extract text from
 * @param _position Position to start from
 * @return Variable* Result of text extraction
 */
/* <usermanual>
@keyword LEFT

@syntax LEFT( [text], [position] ) = [expression]

@example LEFT( "TEST", 2 ) = "PA"

@target all
 </usermanual> */
void variable_string_left_assign( Environment * _environment, char * _string, char * _position, char * _expression ) {
    Variable * string = variable_retrieve( _environment, _string );
    Variable * position = variable_retrieve_or_define( _environment, _position, VT_BYTE, 0 );
    Variable * expression = variable_cast( _environment, _expression, VT_DSTRING );
    switch( string->type ) {
        case VT_STRING: {            
            CRITICAL_LEFT_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
            break;
        }
        case VT_DSTRING: {            
            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of left)" );
            Variable * size = variable_temporary( _environment, VT_BYTE, "(result of left)" );
            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of left)" );
            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of left)" );
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            cpu_dsdescriptor( _environment, expression->realName, address2->realName, size2->realName );
            cpu_mem_move( _environment, address2->realName, address->realName, position->realName );
            break;
        }
        default:
            CRITICAL_LEFT_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
            break;
    }
}

/**
 * @brief Emit code for <b>= RIGHT( ..., ... )</b>
 * 
 * @param _environment Current calling environment
 * @param _string String to extract text from
 * @param _position Position to start from
 * @return Variable* Result of text extraction
 */
/* <usermanual>
@keyword RIGHT

@english
This function reads the specified number of characters from a source string, 
starting from the right-hand side, and it copies them into a destination string,
that is returned. The first type of usage of this function creates a new 
destination string from the chosen number of characters of the source string.
The second usage is to replace the rightmost number of characters:

@italian
Questa funzione legge il numero di caratteri specificato da una stringa di origine, 
a partire dalla fine, e li copia in una stringa di destinazione, che viene 
restituita. Il primo tipo di utilizzo di questa funzione crea una nuova stringa 
di destinazione dal numero di caratteri scelto della stringa di origine. 
Il secondo utilizzo è sostituire il numero di caratteri più a destra.

@syntax = RIGHT( [text], [position] )

@example x = RIGHT( "TEST", 2 )
@usedInExample strings_right_01.bas

@seeAlso LEFT 
@seeAlso MID

@target all
 </usermanual> */
Variable * variable_string_right( Environment * _environment, char * _string, char * _position ) {
    Variable * string = variable_retrieve( _environment, _string );
    Variable * position = variable_retrieve_or_define( _environment, _position, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of right)" );

    switch( string->type ) {
        case VT_STRING: {            
            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of right)" );
            Variable * size = variable_temporary( _environment, VT_BYTE, "(result of right)" );
            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of right)" );
            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of right)" );
            cpu_move_8bit( _environment, string->realName, size->realName );
            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            cpu_move_8bit( _environment, position->realName, size2->realName );
            cpu_dsfree( _environment, result->realName );
            cpu_dsalloc( _environment, size2->realName, result->realName );
            cpu_dsdescriptor( _environment, result->realName, address2->realName, size2->realName );
            cpu_math_add_16bit_with_8bit( _environment, address->realName, size->realName, address->realName );
            cpu_math_sub_16bit_with_8bit( _environment, address->realName, position->realName, address->realName );
            cpu_mem_move( _environment, address->realName, address2->realName, size2->realName );
            break;
        }
        case VT_DSTRING: { 
            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of right)" );
            Variable * size = variable_temporary( _environment, VT_BYTE, "(result of right)" );
            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of right)" );
            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of right)" );
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            cpu_move_8bit( _environment, position->realName, size2->realName );
            cpu_dsfree( _environment, result->realName );
            cpu_dsalloc( _environment, size2->realName, result->realName );
            cpu_dsdescriptor( _environment, result->realName, address2->realName, size2->realName );
            cpu_math_add_16bit_with_8bit( _environment, address->realName, size->realName, address->realName );
            cpu_math_sub_16bit_with_8bit( _environment, address->realName, position->realName, address->realName );
            cpu_mem_move( _environment, address->realName, address2->realName, size2->realName );
            break;
        }
        case VT_IMAGE:
        case VT_IMAGES:
        case VT_SEQUENCE:
        case VT_MUSIC:
        case VT_BUFFER:
        default:
            CRITICAL_RIGHT_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
            break;
    }
    return result;
}

/**
 * @brief Emit code for <b>RIGHT( ..., ... ) = ...</b>
 * 
 * @param _environment Current calling environment
 * @param _string String to extract text from
 * @param _position Position to start from
 * @return Variable* Result of text extraction
 */
/* <usermanual>
@keyword RIGHT

@syntax RIGHT( [text], [position] ) = [expression]

@example RIGHT( "TEST", 2 ) = "AM"

@target all
 </usermanual> */
void variable_string_right_assign( Environment * _environment, char * _string, char * _position, char * _expression ) {
    Variable * string = variable_retrieve( _environment, _string );
    Variable * position = variable_retrieve_or_define( _environment, _position, VT_BYTE, 0 );
    Variable * expression = variable_cast( _environment, _expression, VT_DSTRING );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of right)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of right)" );
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of right)" );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of right)" );

    switch( string->type ) {
        case VT_DSTRING: {            
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            cpu_dsdescriptor( _environment, expression->realName, address2->realName, size2->realName );
            cpu_move_8bit( _environment, size->realName, size2->realName );
            cpu_math_sub_8bit( _environment, size2->realName, position->realName, size2->realName );
            cpu_math_add_16bit_with_8bit( _environment, address->realName, size->realName, address->realName );
            cpu_math_sub_16bit_with_8bit( _environment, address->realName, position->realName, address->realName );
            cpu_mem_move( _environment, address2->realName, address->realName, size2->realName );
            break;
        }
        default:
            CRITICAL_RIGHT_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
            break;
    }
}

/**
 * @brief Emit code for <b>= MID( ..., ... [, ...] )</b>
 * 
 * @param _environment Current calling environment
 * @param _string String to extract text from
 * @param _position Position to start from
 * @param _len Length to extract
 * @return Variable* Result of text extraction
 */
/* <usermanual>
@keyword MID

@english
This function returns characters from the middle of a string, with the first 
number specified in brackets setting the offset from the start of the string 
and the second number setting how many characters are to be fetched. 
If the number of characters to be fetched is omitted from your instruction, 
then the characters will be read right up to the end of the string being examined.
A second usage of this function is to replace the middle number of characters.

@italian
Questa funzione restituisce caratteri dalla metà di una stringa, con il primo 
numero specificato tra parentesi che imposta l'offset dall'inizio della stringa 
e il secondo numero che imposta quanti caratteri devono essere recuperati.
Se il numero di caratteri da recuperare viene omesso dall'istruzione, 
i caratteri verranno letti fino alla fine della stringa in esame. Un secondo 
utilizzo di questa funzione è sostituire il numero medio di caratteri.

@syntax = MID( [text], [position] { , [length] } )

@example x = MID( "TEST", 2, 2 )
@usedInExample strings_mid_01.bas

@seeAlso LEFT
@seeAlso RIGHT

@target all
 </usermanual> */
Variable * variable_string_mid( Environment * _environment, char * _string, char * _position, char * _len ) {
    Variable * string = variable_retrieve( _environment, _string );
    Variable * position = variable_retrieve_or_define( _environment, _position, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of mid)" );
    Variable * len;
    Variable * copyofLen = variable_temporary( _environment, VT_BYTE, "(copy of len)" );

    MAKE_LABEL

    char emptyResultLabel[MAX_TEMPORARY_STORAGE]; sprintf( emptyResultLabel, "%sempty", label );

    cpu_compare_and_branch_8bit_const( _environment, position->realName, 0, emptyResultLabel, 1 );
    
    switch( string->type ) {
        case VT_STRING: {          
            outline0("; VT_STRING")  ;
            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of mid)" );
            Variable * size = variable_temporary( _environment, VT_BYTE, "(result of mid)" );
            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of mid)" );
            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of mid)" );
            cpu_move_8bit( _environment, string->realName, size->realName );

            if ( _len ) {
                len = variable_retrieve_or_define( _environment, _len, VT_BYTE, 0 );
                cpu_move_8bit( _environment, len->realName, copyofLen->realName );
                Variable * temp = variable_temporary( _environment, VT_BYTE, "(checker)");
                cpu_move_8bit( _environment, copyofLen->realName, temp->realName );
                cpu_math_add_8bit( _environment, position->realName, temp->realName, temp->realName );
                cpu_greater_than_8bit( _environment, temp->realName, size->realName, temp->realName, 0, 0 );

                char unlimitedLenLabel[MAX_TEMPORARY_STORAGE]; sprintf( unlimitedLenLabel, "%sunlim", label );
                cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, unlimitedLenLabel, 1 );
                cpu_move_8bit( _environment, size->realName, temp->realName );
                cpu_math_sub_8bit( _environment, temp->realName, position->realName, copyofLen->realName );
                cpu_inc( _environment, copyofLen->realName );
                cpu_label( _environment, unlimitedLenLabel );
            } else {
                cpu_move_8bit( _environment, size->realName, copyofLen->realName );
            }

            cpu_greater_than_8bit( _environment, position->realName, size->realName, size2->realName, 0, 0 );
            cpu_compare_and_branch_8bit_const( _environment, size2->realName, (unsigned char) 0xff, emptyResultLabel, 1 );

            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            cpu_math_add_16bit_with_8bit( _environment, address->realName, position->realName, address->realName );
            cpu_dec_16bit( _environment, address->realName );

            cpu_dsfree( _environment, result->realName );
            cpu_dsalloc( _environment, copyofLen->realName, result->realName );
            cpu_dsdescriptor( _environment, result->realName, address2->realName, size2->realName );
            cpu_mem_move( _environment, address->realName, address2->realName, copyofLen->realName );

            break;
        }
        case VT_DSTRING: {            
            outline0("; VT_DSTRING")  ;
            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of mid)" );
            Variable * size = variable_temporary( _environment, VT_BYTE, "(result of mid)" );
            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of mid)" );
            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of mid)" );
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );

            cpu_greater_than_8bit( _environment, position->realName, size->realName, size2->realName, 0, 0 );
            cpu_compare_and_branch_8bit_const( _environment, size2->realName, 0, emptyResultLabel, 0 );

            cpu_math_add_16bit_with_8bit( _environment, address->realName, position->realName, address->realName );
            cpu_dec_16bit( _environment, address->realName );
            if ( _len ) {
                len = variable_retrieve_or_define( _environment, _len, VT_BYTE, 0 );
                cpu_move_8bit( _environment, len->realName, copyofLen->realName );
                Variable * temp = variable_temporary( _environment, VT_BYTE, "(checker)");
                cpu_move_8bit( _environment, len->realName, temp->realName );
                cpu_math_add_8bit( _environment, position->realName, temp->realName, temp->realName );
                cpu_greater_than_8bit( _environment, temp->realName, size->realName, temp->realName, 0, 0 );

                char unlimitedLenLabel[MAX_TEMPORARY_STORAGE]; sprintf( unlimitedLenLabel, "%sunlim", label );
                cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, unlimitedLenLabel, 1 );
                cpu_move_8bit( _environment, size->realName, temp->realName );
                cpu_math_sub_8bit( _environment, temp->realName, position->realName, copyofLen->realName );
                cpu_inc( _environment, copyofLen->realName );
                cpu_label( _environment, unlimitedLenLabel );
            } else {
                cpu_move_8bit( _environment, size->realName, copyofLen->realName );
            }

            cpu_greater_than_8bit( _environment, position->realName, size->realName, size2->realName, 0, 0 );
            cpu_compare_and_branch_8bit_const( _environment, size2->realName, (unsigned char) 0xff, emptyResultLabel, 1 );

            cpu_dsfree( _environment, result->realName );
            cpu_dsalloc( _environment, copyofLen->realName, result->realName );
            cpu_dsdescriptor( _environment, result->realName, address2->realName, size2->realName );
            cpu_mem_move( _environment, address->realName, address2->realName, copyofLen->realName );
            break;
        }
        default:
            CRITICAL_MID_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
            break;
    }

    char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneLabel, "%sdone", label );

    cpu_jump( _environment, doneLabel );

    cpu_label( _environment, emptyResultLabel );

    cpu_dsfree( _environment, result->realName );
    cpu_dsalloc_size( _environment, 0, result->realName );

    cpu_label( _environment, doneLabel );

    return result;
}

/**
 * @brief Emit code for <b>MID( ..., ... [, ...] ) = ...</b>
 * 
 * @param _environment Current calling environment
 * @param _string String to extract text from
 * @param _position Position to start from
 * @param _len Length to extract
 * @return Variable* Result of text extraction
 */
/* <usermanual>
@keyword MID

@syntax MID( [text], [position] { , [length] } ) = [expression]

@example MID( "TEST", 2, 2 ) = "xx"

@target all
 </usermanual> */
void variable_string_mid_assign( Environment * _environment, char * _string, char * _position, char * _len, char * _expression ) {
    Variable * string = variable_retrieve( _environment, _string );
    Variable * position = variable_retrieve_or_define( _environment, _position, VT_BYTE, 0 );
    Variable * expression = variable_cast( _environment, _expression, VT_DSTRING );
    Variable * len;
    if ( _len ) {
        len = variable_retrieve_or_define( _environment, _len, VT_BYTE, 0 );
    } else {
        len = variable_temporary( _environment, VT_BYTE, "(calculated MID len)");
        variable_store( _environment, len->name, 0 );
    }
    switch( string->type ) {
        case VT_STRING: {            
            CRITICAL_MID_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
        }
        case VT_DSTRING: {            
            Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of mid)" );
            Variable * size = variable_temporary( _environment, VT_BYTE, "(result of mid)" );
            Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of mid)" );
            Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of mid)" );

            cpu_dsdescriptor( _environment, string->realName, address2->realName, size2->realName );
            cpu_dsdescriptor( _environment, expression->realName, address->realName, size->realName );

            cpu_math_add_16bit_with_8bit( _environment, address2->realName, position->realName, address2->realName );

            if ( _len ) {

            } else {
                cpu_move_8bit( _environment, size2->realName, len->realName );
                cpu_math_sub_8bit( _environment, len->realName, position->realName, len->realName );
            }
            cpu_mem_move( _environment, address->realName, address2->realName, len->realName );
            break;
        }
        default:
            CRITICAL_MID_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
            break;
    }
}

/**
 * @brief Emit code for <b>= INSTR( ..., ... [, ...] )</b>
 * 
 * @param _environment Current calling environment
 * @param _search String to be searched
 * @param _searched String to search
 * @param _start Starting position to start to search
 * @return Variable* Result of text search
 */
/* <usermanual>
@keyword INSTR

@english

This function can be called to search through strings for individual characters or sub-strings:
it allows you to search for all instances of one string inside another. The string is searched 
for the first occurrence of the second strings. If it is found, its location will be reported 
in the form of the number of characters from the left-hand side of the searched string. 
If the search is unsuccessful, a result of zero will be given.

Normally, the search will begin from the first character at the extreme left-hand side of the 
host string, but you can specify an (optional) number of characters from the beginning of the 
searched string. The optional start-of-search position can range from one to the maximum 
number of characters in the searched string to be searched.

@italian

Questa funzione può essere chiamata per cercare nelle stringhe singoli caratteri o sottostringhe: 
permette di cercare tutte le istanze di una stringa all'interno di un'altra.
La stringa viene ricercata per la prima occorrenza della seconda stringa. Se viene trovato, 
la sua posizione verrà riportata sotto forma di numero di caratteri dall'inizio della 
stringa cercata. Se la ricerca ha esito negativo, verrà fornito un risultato pari a zero.

Normalmente, la ricerca inizierà dal primo carattere all'estrema sinistra della stringa host,
ma è possibile specificare un numero (facoltativo) di caratteri dall'inizio della stringa 
cercata. La posizione di inizio ricerca opzionale può variare da uno al massimo
numero di caratteri nella stringa da cercare.

@syntax = INSTR( [text], [searched] {, [start] } )

@example x = INSTR( "ugBASIC", "A" )
@example x = INSTR( "ugBASIC", "A", 2 )
@usedInExample strings_instr_01.bas
@usedInExample strings_instr_02.bas

@target all
 </usermanual> */
Variable * variable_string_instr( Environment * _environment, char * _search, char * _searched, char * _start ) {
    Variable * search = variable_retrieve( _environment, _search );
    Variable * searched = variable_retrieve( _environment, _searched );
    Variable * start = NULL;
    if ( _start ) {
        start = variable_retrieve_or_define( _environment, _start, VT_BYTE, 0 );
    }
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of INSTR)" );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of INSTR)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of INSTR)" );
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of INSTR)" );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of INSTR)" );

    switch( search->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, search->realName, size->realName );
            cpu_addressof_16bit( _environment, search->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, search->realName, address->realName, size->realName );
            break;
        default:
            CRITICAL_INSTR_UNSUPPORTED( _search, DATATYPE_AS_STRING[search->type]);
    }
    switch( searched->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, searched->realName, size2->realName );
            cpu_addressof_16bit( _environment, searched->realName, address2->realName );
            cpu_inc_16bit( _environment, address2->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, searched->realName, address2->realName, size2->realName );
            break;
        default:
            CRITICAL_INSTR_UNSUPPORTED( _searched, DATATYPE_AS_STRING[searched->type]);
    }

    MAKE_LABEL

    Variable * found = variable_temporary( _environment, VT_BYTE, "(found flag)" );

    char repeatLabel[MAX_TEMPORARY_STORAGE]; sprintf( repeatLabel, "%srep", label );
    char foundLabel[MAX_TEMPORARY_STORAGE]; sprintf( foundLabel, "%sfnd", label );
    char notFoundLabel[MAX_TEMPORARY_STORAGE]; sprintf( notFoundLabel, "%snfnd", label );

    if ( start ) {
        cpu_math_add_16bit_with_8bit( _environment, address->realName, start->realName, address->realName );
        cpu_move_8bit( _environment, start->realName, result->realName );
    } else {
        cpu_store_8bit( _environment, result->realName, 0 );        
    }

    cpu_label( _environment, repeatLabel );

    cpu_compare_8bit( _environment, result->realName, size->realName, found->realName, 1 );

    cpu_bvneq( _environment, found->realName, notFoundLabel );

    cpu_compare_memory( _environment, address->realName, address2->realName, size2->realName, found->realName, 1 );

    cpu_inc_16bit( _environment, address->realName );
    cpu_inc( _environment, result->realName );

    cpu_bvneq( _environment, found->realName, foundLabel );

    cpu_jump( _environment, repeatLabel );

    cpu_label( _environment, notFoundLabel );
    cpu_store_8bit( _environment, result->realName, 0 );

    cpu_label( _environment, foundLabel );

    return result;
}

/**
 * @brief Emit code for <b>= UPPER( ... )</b>
 * 
 * @param _environment Current calling environment
 * @param _string String to convert in lower case
 * @return Variable* Result of case conversion
 */
/* <usermanual>
@keyword LOWER

@english
This function converts the characters in a string into lower case (capital) letters.

@italian
Questa funzione converte i caratteri presenti in una stringa in lettere minuscole.

@syntax = LOWER( [text] )

@example x = LOWER( "ugBASIC" )
@usedInExample strings_cases_01.bas

@target all
 </usermanual> */
Variable * variable_string_lower( Environment * _environment, char * _string ) {
    Variable * string = variable_retrieve( _environment, _string );
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of LOWER)" );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of LOWER)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of LOWER)" );
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of LOWER)" );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of LOWER)" );

    switch( string->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, string->realName, size->realName );
            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            break;
        default:
            CRITICAL_LOWER_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
    }

    cpu_dsfree( _environment, result->realName );
    cpu_dsalloc( _environment, size->realName, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address2->realName, size2->realName );

    MAKE_LABEL

    cpu_lowercase( _environment, address->realName, size->realName, address2->realName );

    return result;

}

/**
 * @brief Emit code for <b>= UPPER( ... )</b>
 * 
 * @param _environment Current calling environment
 * @param _string String to convert in uppercase
 * @return Variable* Result of case conversion
 */
/* <usermanual>
@keyword UPPER

@english
This function converts the characters in a string into upper case (capital) letters.

@italian
Questa funzione converte i caratteri presenti in una stringa in lettere maiuscole.

@syntax = UPPER( [text] )

@example x = UPPER( "ugBASIC" )
@usedInExample strings_cases_01.bas

@target all
 </usermanual> */
Variable * variable_string_upper( Environment * _environment, char * _string ) {
    Variable * string = variable_retrieve( _environment, _string );
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of LOWER)" );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of LOWER)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of LOWER)" );
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of LOWER)" );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of LOWER)" );

    switch( string->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, string->realName, size->realName );
            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            break;
        default:
            CRITICAL_LOWER_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
    }

    cpu_dsfree( _environment, result->realName );
    cpu_dsalloc( _environment, size->realName, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address2->realName, size2->realName );

    MAKE_LABEL

    cpu_uppercase( _environment, address->realName, size->realName, address2->realName );

    return result;
    
}

/**
 * @brief Emit code for <b>= STR( ... )</b>
 * 
 * @param _environment Current calling environment
 * @param _value Number to convert to string
 * @return Variable* Result of conversion
 */
/* <usermanual>
@keyword STR

@english
This function converts numbers into strings. This can be used to overcome some 
limitations posed by functions which does not accept numbers as parameters, 
but will work happily with parameters in the form of strings. 
Also, when string adding is performed, all operand must be strings,
so this function is really useful.

@italian
Questa funzione converte i numeri in stringhe. Può essere usata per superare 
alcune limitazioni poste dalle funzioni che non accettano numeri come parametri, 
ma che funzionano bene con  parametri sotto forma di stringhe. Inoltre, quando 
viene eseguita l'aggiunta di stringhe, tutti gli operandi devono essere stringhe, 
quindi questa funzione è davvero utile.

@syntax = STR( [number] )

@example x = STR( 42 )
@usedInExample strings_str_01.bas

@target all
 </usermanual> */
Variable * variable_string_str( Environment * _environment, char * _value ) {
    Variable * value = variable_retrieve( _environment, _value );
    Variable * dword = variable_temporary( _environment, VT_DWORD, "(bcd result of STR)" );
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of STR)" );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of STR)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of STR)" );

    switch( VT_BITWIDTH( value->type ) ) {
        case 0:
            CRITICAL_STR_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type]);
            break;
        case 32:
        case 16:
        case 8:
            break;
    }

    variable_store_string( _environment, result->name, "          " );
    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_number_to_string( _environment, value->realName, address->realName, size->realName, VT_BITWIDTH( value->type ), VT_SIGNED( value->type ) );
    
    cpu_dsresize( _environment, result->realName, size->realName );
    
    return result;
    
}

/**
 * @brief Emit code for <b>= VAL( ... )</b>
 * 
 * @param _environment Current calling environment
 * @param _value String to convert to number
 * @return Variable* Result of conversion
 */
/* <usermanual>
@keyword VAL

@english
This function converts strings into number.

@italian
Questa funzione converte le stringhe in numeri.

@syntax = VAL( [number] )

@example x = VAL( 42 )
@usedInExample strings_val_01.bas

@target all
 </usermanual> */
Variable * variable_string_val( Environment * _environment, char * _value ) {
    Variable * value = variable_retrieve( _environment, _value );
    Variable * result = variable_temporary( _environment, VT_WORD, "(result of val)" );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of val)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of val)" );

    switch( value->type ) {
        case VT_STRING: {
            cpu_move_8bit( _environment, value->realName, size->realName );
            cpu_addressof_16bit( _environment, value->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            cpu_convert_string_into_16bit( _environment, address->realName, size->realName, result->realName );
            break;
        }
        case VT_DSTRING: {
            cpu_dsdescriptor( _environment, value->realName, address->realName, size->realName );
            cpu_convert_string_into_16bit( _environment, address->realName, size->realName, result->realName );
            break;
        }
        default:
            CRITICAL_VAL_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type]);
            break;
    }

    return result;
    
}

/**
 * @brief Emit code for <b>= HEX( ... )</b>
 * 
 * @param _environment Current calling environment
 * @param _value  Number to convert to hexadecimal
 * @return Variable* Result of conversion
 */
/* <usermanual>
@keyword HEX

@english
This function converts a number into hexadecimal.

@italian
Questa funzione converte un numero in formato esadecimale.

@syntax = HEX( [number] )

@example x = HEX( 42 )

@target all
 </usermanual> */
Variable * variable_hex( Environment * _environment, char * _value ) {

    MAKE_LABEL

    Variable * originalValue = variable_retrieve( _environment, _value );
    Variable * digits = NULL;
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of BIN)" );
    Variable * pad = variable_temporary( _environment, VT_BYTE, "(is padding needed?)");

    switch( VT_BITWIDTH( originalValue->type ) ) {
        case 0:
            CRITICAL_HEX_UNSUPPORTED( _value, DATATYPE_AS_STRING[originalValue->type]);
            break;
        case 32:
            variable_store_string( _environment, result->name, "        " );
            break;
        case 16:
            variable_store_string( _environment, result->name, "    " );
            break;
        case 8:
            variable_store_string( _environment, result->name, "  " );
            break;
    }

    char finishedLabel[MAX_TEMPORARY_STORAGE]; sprintf(finishedLabel, "%send", label); 
    char padLabel[MAX_TEMPORARY_STORAGE]; sprintf(padLabel, "%spad", label); 
    char truncateLabel[MAX_TEMPORARY_STORAGE]; sprintf(truncateLabel, "%strunc", label); 

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of hex)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of hex)" );
    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_hex_to_string( _environment, originalValue->realName, address->realName, size->realName, VT_BITWIDTH( originalValue->type ) );

    return result;
    
}

/**
 * @brief Emit code for <b>= STRING( ..., ... )</b>
 *
 * @param _environment Current calling environment
 * @param _string String to use as base (the first letter)
 * @param _repetitions Number of repetition of output string
 * @return Variable* Result of production
 */
/* <usermanual>
@keyword STRING

@english
This function can be used to create 
a new string filled with the required number of copies of the first 
character from an existing string.

@italian
Questa funzione può essere utilizzata per creare
una nuova stringa riempita con tante copie della prima lettera
della stringa in ingresso.

@syntax = STRING( [text], [number] )

@example x = STRING( "A", 42 )
@usedInExample strings_string_01.bas

@target all
 </usermanual> */
Variable * variable_string_string( Environment * _environment, char * _string, char * _repetitions  ) {

    Variable * string = variable_retrieve( _environment, _string );
    Variable * repetitions = variable_retrieve_or_define( _environment, _repetitions, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of STRING)");

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of LOWER)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of LOWER)" );
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of LOWER)" );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of LOWER)" );

    cpu_dsfree( _environment, result->realName );
    cpu_dsalloc( _environment, repetitions->realName, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address2->realName, size2->realName );

    switch( string->type ) {
        case VT_STRING: {
            cpu_move_8bit( _environment, string->realName, size->realName );
            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        }
        case VT_DSTRING: {
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            break;
        }
        default:
            CRITICAL_STRING_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
    }

    cpu_fill_indirect( _environment, address2->realName, size2->realName, address->realName );

    return result;
    
}

/**
 * @brief Emit code for <b>= SPACE( ... )</b>
 * 
 * @param _environment Current calling environment
 * @param _repetitions Number of spaces to produce in output string
 * @return Variable* Result of production
 */
/* <usermanual>
@keyword SPACE

@english
This function can be used to create 
a new string filled with the required number of spaces.

@italian
Questa funzione può essere utilizzata per creare
una nuova stringa riempita con tanti spazi quanto
quelli richiesti.

@syntax = SPACE( [number] )

@example x = SPACE( 42 )
@usedInExample strings_space_01.bas

@target all
 </usermanual> */
Variable * variable_string_space( Environment * _environment, char * _repetitions  ) {
    
    Variable * space = variable_temporary( _environment, VT_STRING, "(space)");
    
    variable_store_string( _environment, space->name, " " );

    return variable_string_string( _environment, space->name, _repetitions  );
    
}

/**
 * @brief Emit code for <b>= FLIP( ... )</b>
 * 
 * @param _environment Current calling environment
 * @param _string String to flip
 * @return Variable* Result of flip
 */
/* <usermanual>
@keyword FLIP

@english
This function will flip a given string, reversing the order of letters.

@italian
Questa funzione inverte l'ordine delle lettere della stringa data in ingresso.

@syntax = FLIP( [string] )

@example x = FLIP( "test" )
@usedInExample strings_flip_01.bas

@target all
 </usermanual> */
Variable * variable_string_flip( Environment * _environment, char * _string  ) {

    Variable * string = variable_retrieve( _environment, _string );

    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of STRING)");
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of val)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of val)" );
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of val)" );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of val)" );        

    switch( string->type ) {
        case VT_STRING: {
            cpu_move_8bit( _environment, string->realName, size->realName );
            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );

            break;
        }
        case VT_DSTRING: {
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            break;
        }
        default:
            CRITICAL_STRING_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
    }

    cpu_dsfree( _environment, result->realName );
    cpu_dsalloc( _environment, size->realName, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address2->realName, size2->realName );

    cpu_flip( _environment, address->realName, size->realName, address2->realName );

    return result;
    
}

/**
 * @brief Emit code for <b>= CHR( ... )</b> 
 * 
 * @param _environment Current calling environment
 * @param _ascii ASCII value to convert to string
 * @return Variable* Result of conversion
 */
/* <usermanual>
@keyword CHR

@english
This function creates a string that contains a single character, generated by a 
given ASCII code number. Note that, depending on the hardware, only some characters 
are printable on the screen. Others are used internally as control codes.

@italian
Questa funzione crea una stringa che contiene un singolo carattere, generato da un dato
codice ASCII. Da notare che, a seconda dell'hardware, solo alcuni caratteri sono 
stampabili sullo schermo. Altri sono usati internamente come codici di controllo.

@syntax = CHR( [ascii] )

@example x = CHR( 65 )
@usedInExample strings_chr_01.bas

@target all
 </usermanual> */
Variable * variable_string_chr( Environment * _environment, char * _ascii  ) {

    Variable * ascii = variable_retrieve_or_define( _environment, _ascii, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of CHR)");
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of val)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of val)" );

    switch( VT_BITWIDTH( ascii->type ) ) {
        case 8:
        case 16:
        case 32:
            break;
        default:
            CRITICAL_CHR_UNSUPPORTED( _ascii, DATATYPE_AS_STRING[ascii->type]);
            break;
    }

    cpu_dsfree( _environment, result->realName );
    cpu_dsalloc_size( _environment, 1, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_move_8bit_indirect( _environment, ascii->realName, address->realName );

    return result;
    
}

/**
 * @brief Emit code for <b>= ASC( ... )</b>  
 * 
 * @param _environment Current calling environment
 * @param _char String to convert to ascii
 * @return Variable* Result of conversion
 */
/* <usermanual>
@keyword ASC

@english
This function returns the internal ASCII code of the first character
in a string.

@italian
Questa funzione ritorna il codice ASCII del primo carattere di una stringa.

@syntax = ASC( [text] )

@example x = ASC( "UGBASIC" )
@usedInExample strings_asc_01.bas

@target all
 </usermanual> */
Variable * variable_string_asc( Environment * _environment, char * _char  ) {

    Variable * character = variable_retrieve_or_define( _environment, _char, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of ASC)");
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of ASC)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of ASC)" );

    switch( character->type ) {
        case VT_STRING: {
            cpu_move_8bit( _environment, character->realName, size->realName );
            cpu_addressof_16bit( _environment, character->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );

            break;
        }
        case VT_DSTRING: {
            cpu_dsdescriptor( _environment, character->realName, address->realName, size->realName );
            break;
        }
        default:
            CRITICAL_ASC_UNSUPPORTED( _char, DATATYPE_AS_STRING[character->type]);
    }

    cpu_move_8bit_indirect2( _environment, address->realName, result->realName );

    return result;
    
}

/**
 * @brief Emit code for <b>= LEN( ... )</b>   
 * 
 * @param _environment Current calling environment
 * @param _string String to examinate
 * @return Variable* Result of length measurement
 */
/* <usermanual>
@keyword LEN

@english
This function returns the number of characters stored in a string.

@italian
Questa funzione restituisce il numero di caratteri memorizzato in una stringa.

@syntax = LEN( [text] )

@example x = LEN( "TEST" )

@usedInExample strings_len_01.bas

@target all
 </usermanual> */
Variable * variable_string_len( Environment * _environment, char * _string  ) {

    Variable * string = variable_retrieve( _environment, _string );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of LEN)");
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of val)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of val)" );

    switch( string->type ) {
        case VT_STRING: {
            cpu_move_8bit( _environment, string->realName, size->realName );
            break;
        }
        case VT_DSTRING: {
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            break;
        }
        default:
            CRITICAL_LEN_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
    }

    cpu_move_8bit( _environment, size->realName, result->realName );

    return result;
    
}

static Variable * calculate_offset_in_array( Environment * _environment, char * _array ) {

    Variable * array = variable_retrieve( _environment, _array );

    if ( array->arrayDimensions != _environment->arrayIndexes[_environment->arrayNestedIndex] ) {
        CRITICAL_ARRAY_SIZE_MISMATCH( _array, array->arrayDimensions, _environment->arrayIndexes[_environment->arrayNestedIndex] );
    }

    Variable * base = variable_temporary( _environment, VT_WORD, "(base in array)");
    Variable * offset = variable_temporary( _environment, VT_WORD, "(offset in array)");

    variable_store( _environment, offset->name, 0 );

    int i,j;

    if ( _environment->arrayIndexes[_environment->arrayNestedIndex] == 1 ) {
        Variable * index = variable_retrieve( _environment, _environment->arrayIndexesEach[_environment->arrayNestedIndex][0]);
        variable_add_inplace_vars( _environment, offset->name, index->name );
    } else {
        for( i = 0; i<_environment->arrayIndexes[_environment->arrayNestedIndex]; ++i ) {
            int baseValue = 1;
            for( j=0; j<i; ++j ) {
                baseValue *= array->arrayDimensionsEach[array->arrayDimensions-j-1];
            }
            Variable * index = variable_retrieve( _environment, _environment->arrayIndexesEach[_environment->arrayNestedIndex][array->arrayDimensions-i-1]);
            if(baseValue!=1) {
                variable_store( _environment, base->name, baseValue );
                Variable * additionalOffset = variable_mul( _environment, index->name, base->name );
                variable_add_inplace_vars( _environment, offset->name, additionalOffset->name );
            } else {
                variable_add_inplace_vars( _environment, offset->name, index->name );
            }
        }
    }

    return offset;

}

void variable_move_array( Environment * _environment, char * _array, char * _value  ) {

    MAKE_LABEL;

    Variable * array = variable_retrieve( _environment, _array );

    if ( array->arrayDimensions != _environment->arrayIndexes[_environment->arrayNestedIndex] ) {
        CRITICAL_ARRAY_SIZE_MISMATCH( _array, array->arrayDimensions, _environment->arrayIndexes[_environment->arrayNestedIndex] );
    }

    if ( array->arrayType == 0 ) {
        WARNING_USE_OF_UNDEFINED_ARRAY( array->name );
        array->arrayType = VT_WORD;
    }

    Variable * offset = calculate_offset_in_array( _environment, _array);

    switch( array->arrayType ) {
        case VT_STRING:
            CRITICAL_DATATYPE_UNSUPPORTED("array(a)", DATATYPE_AS_STRING[array->arrayType]);
         case VT_TILE:
         case VT_TILESET:
         case VT_SPRITE:
         case VT_DSTRING:
            offset = variable_mul2_const( _environment, offset->name, 0 );
            break;
         case VT_TILES:
            offset = variable_mul2_const( _environment, offset->name, 2 );
            break;
         default:
            offset = variable_mul2_const( _environment, offset->name, ( VT_BITWIDTH( array->arrayType ) >> 3 ) - 1 );
            break;
    }

    cpu_math_add_16bit_with_16bit( _environment, offset->realName, array->realName, offset->realName );

    Variable * value = variable_cast( _environment, _value, array->arrayType );

    switch( array->arrayType ) {
        case VT_TILES:
            cpu_move_32bit_indirect( _environment, value->realName, offset->realName );
            break;
        case VT_TILE:
        case VT_TILESET:
        case VT_SPRITE:
            cpu_move_8bit_indirect( _environment, value->realName, offset->realName );
            break;
        default:
            switch( VT_BITWIDTH( array->arrayType ) ) {
                case 32:
                    cpu_move_32bit_indirect( _environment, value->realName, offset->realName );
                    break;
                case 16:
                    cpu_move_16bit_indirect( _environment, value->realName, offset->realName );
                    break;
                case 8:
                    cpu_move_8bit_indirect( _environment, value->realName, offset->realName );
                    break;
                case 0:
                    CRITICAL_DATATYPE_UNSUPPORTED("array(3)", DATATYPE_AS_STRING[array->arrayType]);
            }
            break;
    }
}

void variable_move_array_string( Environment * _environment, char * _array, char * _string  ) {

    Variable * array = variable_retrieve( _environment, _array );
    Variable * string = variable_retrieve( _environment, _string );

    if ( array->arrayDimensions != _environment->arrayIndexes[_environment->arrayNestedIndex] ) {
        CRITICAL_ARRAY_SIZE_MISMATCH( _array, array->arrayDimensions, _environment->arrayIndexes[_environment->arrayNestedIndex] );
    }

    Variable * offset = calculate_offset_in_array( _environment, _array);
    
    cpu_math_add_16bit_with_16bit( _environment, offset->realName, array->realName, offset->realName );

    Variable * dstring = variable_temporary( _environment, VT_DSTRING, "(array element)");

    cpu_move_8bit_indirect2( _environment, offset->realName, dstring->realName );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of array move)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of array move)" );
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of array move)" );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of array move)" );

    switch( string->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, string->realName, size->realName );
            cpu_addressof_16bit( _environment, string->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );
            break;
        default:
            CRITICAL_LOWER_UNSUPPORTED( _string, DATATYPE_AS_STRING[string->type]);
    }

    cpu_dsfree( _environment, dstring->realName );
    cpu_dsalloc( _environment, size->realName, dstring->realName );
    cpu_dsdescriptor( _environment, dstring->realName, address2->realName, size2->realName );
    cpu_mem_move(_environment, address->realName, address2->realName, size->realName );
    cpu_move_8bit_indirect( _environment, dstring->realName, offset->realName );
    cpu_store_8bit( _environment, dstring->realName, 0 );

}

Variable * variable_move_from_array( Environment * _environment, char * _array ) {

    MAKE_LABEL

    Variable * array = variable_retrieve( _environment, _array );

    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _array );
    }

    if ( array->arrayDimensions != _environment->arrayIndexes[_environment->arrayNestedIndex] ) {
        CRITICAL_ARRAY_SIZE_MISMATCH( _array, array->arrayDimensions, _environment->arrayIndexes[_environment->arrayNestedIndex] );
    }

    Variable * result = variable_temporary( _environment, array->arrayType, "(element from array)" );

    if ( array->arrayDimensions == 1 && array->arrayDimensionsEach[0] <= 256 && VT_BITWIDTH( array->arrayType ) == 8 ) {

        Variable * index = variable_retrieve( _environment, _environment->arrayIndexesEach[_environment->arrayNestedIndex][0] );

        cpu_move_8bit_indirect2_8bit( _environment, array->realName, index->realName, result->realName );

    } else {

        Variable * offset = calculate_offset_in_array( _environment, _array);

        switch( array->arrayType ) {
            case VT_STRING: {

                CRITICAL_DATATYPE_UNSUPPORTED("array(a)", DATATYPE_AS_STRING[array->arrayType]);

                break;
            }
            case VT_TILES:{

                offset = variable_mul2_const( _environment, offset->name, 2 );

                cpu_math_add_16bit_with_16bit( _environment, offset->realName, array->realName, offset->realName );

                cpu_move_32bit_indirect2( _environment, offset->realName, result->realName );

                break;

            }
            case VT_TILESET:
            case VT_TILE:
            case VT_SPRITE: {

                offset = variable_mul2_const( _environment, offset->name, 0 );

                cpu_math_add_16bit_with_16bit( _environment, offset->realName, array->realName, offset->realName );

                cpu_move_8bit_indirect2( _environment, offset->realName, result->realName );

                break;

            }
            case VT_DSTRING: {

                cpu_math_add_16bit_with_16bit( _environment, offset->realName, array->realName, offset->realName );

                Variable * dstring = variable_temporary( _environment, array->arrayType, "(array element)");

                cpu_move_8bit_indirect2( _environment, offset->realName, dstring->realName );

                Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of array move)" );
                Variable * size = variable_temporary( _environment, VT_BYTE, "(result of array move)" );
                Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(result of array move)" );
                Variable * size2 = variable_temporary( _environment, VT_BYTE, "(result of array move)" );

                cpu_dsdescriptor( _environment, dstring->realName, address->realName, size->realName );
                cpu_dsfree( _environment, result->realName );
                cpu_dsalloc( _environment, size->realName, result->realName );
                cpu_dsdescriptor( _environment, result->realName, address2->realName, size2->realName );
                cpu_mem_move(_environment, address->realName, address2->realName, size->realName );

                break;
            }

            default: {

                if ( array->arrayType == 0 ) {
                    WARNING_USE_OF_UNDEFINED_ARRAY( array->name );
                    array->arrayType = VT_WORD;
                }
        
                offset = variable_mul2_const( _environment, offset->name, ( VT_BITWIDTH( array->arrayType ) >> 3 ) - 1 );

                cpu_math_add_16bit_with_16bit( _environment, offset->realName, array->realName, offset->realName );

                switch( VT_BITWIDTH( array->arrayType ) ) {
                    case 32:
                        cpu_move_32bit_indirect2( _environment, offset->realName, result->realName );
                        break;
                    case 16:
                        cpu_move_16bit_indirect2( _environment, offset->realName, result->realName);
                        break;
                    case 8:
                        cpu_move_8bit_indirect2( _environment, offset->realName, result->realName );
                        break;
                    case 0:
                        CRITICAL_DATATYPE_UNSUPPORTED("array(4)", DATATYPE_AS_STRING[array->arrayType]);
                }

            }

        }

    }

    return result;

}

int pattern_match(char *_pattern, char * _value)
{
    // If we reach at the end of both strings, we are done
    if (*_pattern == '\0' && *_value == '\0')
        return 1;
 
    // Make sure that the characters after '*' are present
    // in second string. This function assumes that the first
    // string will not contain two consecutive '*'
    if (*_pattern == '*' && *(_pattern+1) != '\0' && *_value == '\0')
        return 1;
 
    // If the first string contains '?', or current characters
    // of both strings match
    if (*_pattern == '?' || *_pattern == *_value)
        return pattern_match(_pattern+1, _value+1);
 
    // If there is *, then there are two possibilities
    // a) We consider current character of second string
    // b) We ignore current character of second string.
    if (*_pattern == '*')
        return pattern_match(_pattern+1, _value) || pattern_match(_pattern, _value+1);
    return 0;

}


/**
 * @brief Emit code for <string>BIN(...)</strong>
 * 
 * Emit the code to convert the given value in a binary string.
 * 
 * @param _environment Current calling environment
 * @param _value Value to convert into string
 * @param _digits Number of digits to represent
 * @return Variable* String with the binary representation
 */
/* <usermanual>
@keyword BIN

@english
This function converts a number into a string of bits, from the most significant
to the least significant. It is also possible to indicate the number of digits 
to be represented. If this parameter is omitted, the minimum number of digits 
for that data format (8, 16 or 32 digits) will be used.

@italian
Questa funzione converte un numero in una stringa di bit, dal più significativo 
al meno significativo. E' possibile indicare anche il numero di cifre da 
rappresentare. Se questo parametro viene omesso, sarà utilizzato il numero di 
cifre minimo per quel formato di dati (8, 16 o 32 cifre).

@syntax = BIN( [value] )
@syntax = BIN( [value], [digits] )

@example x = BIN(42)
@example z = BIN(42, 5)

@target all
 </usermanual> */
Variable * variable_bin( Environment * _environment, char * _value, char * _digits ) {

    MAKE_LABEL

    Variable * originalValue = variable_retrieve( _environment, _value );
    Variable * digits = NULL;
    if ( _digits ) {
        digits = variable_retrieve_or_define( _environment, _digits, VT_BYTE, 8 );
    }
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of BIN)" );
    Variable * pad = variable_temporary( _environment, VT_BYTE, "(is padding needed?)");

    switch( VT_BITWIDTH( originalValue->type ) ) {
        case 0:
            CRITICAL_BIN_UNSUPPORTED( _value, DATATYPE_AS_STRING[originalValue->type]);
            break;
        case 32:
            variable_store_string( _environment, result->name, "                                " );
            break;
        case 16:
            variable_store_string( _environment, result->name, "                " );
            break;
        case 8:
            variable_store_string( _environment, result->name, "        " );
            break;
    }

    char finishedLabel[MAX_TEMPORARY_STORAGE]; sprintf(finishedLabel, "%send", label); 
    char padLabel[MAX_TEMPORARY_STORAGE]; sprintf(padLabel, "%spad", label); 
    char truncateLabel[MAX_TEMPORARY_STORAGE]; sprintf(truncateLabel, "%strunc", label); 

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(result of val)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(result of val)" );
    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_bits_to_string( _environment, originalValue->realName, address->realName, size->realName, VT_BITWIDTH( originalValue->type ) );

    if ( digits ) {
        Variable * result2 = variable_temporary( _environment, VT_DSTRING, "(padding/truncating)" );
        Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(padding/truncating)" );
        Variable * size2 = variable_temporary( _environment, VT_BYTE, "(padding/truncating)" );
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(0)" );

        cpu_store_8bit( _environment, zero->realName, '0' );

        cpu_less_than_8bit( _environment, size->realName, digits->realName, pad->realName, 0, 0 );

        cpu_dsfree( _environment, result2->realName );
        cpu_dsalloc( _environment, digits->realName, result2->realName );

        cpu_bvneq( _environment, pad->realName, truncateLabel );

        cpu_label( _environment, padLabel );

        cpu_dsdescriptor( _environment, result2->realName, address2->realName, size2->realName );
        cpu_fill( _environment, address2->realName, digits->realName, zero->realName );
        
        cpu_math_add_16bit_with_8bit( _environment, address2->realName, digits->realName, address2->realName );
        cpu_math_sub_16bit_with_8bit( _environment, address2->realName, size->realName, address2->realName );
        cpu_mem_move( _environment, address->realName, address2->realName, size->realName );

        cpu_jump( _environment, finishedLabel );

        cpu_label( _environment, truncateLabel );
        
        cpu_dsdescriptor( _environment, result2->realName, address2->realName, size2->realName );
        cpu_math_add_16bit_with_8bit( _environment, address->realName, size->realName, address->realName );
        cpu_math_sub_16bit_with_8bit( _environment, address->realName, digits->realName, address->realName );
        cpu_mem_move( _environment, address->realName, address2->realName, digits->realName );

        cpu_label( _environment, finishedLabel );

        cpu_dsfree( _environment, result->realName );

        result = result2;

    }
    
    return result;
    
}

/**
 * @brief Emit code for <b>HAS BIT / BIT(...)</b>
 * 
 * @param _environment Current calling environment
 * @param _value Value to check at bit level
 * @param _position Position to check at bit level
 * @return Variable* Bit value for that position
 */
/* <usermanual>
@keyword HAS BIT

@english
This instruction allows you to check if a certain bit in a certain position (0 based)
in a variable or expression is set to 0 or to 1. If that certain bit is set to 0, 
the instruction will return the value `FALSE`. Otherwise, the statement will return `TRUE`.

@italian
Questa istruzione permette di verificare se un certo bit in una certa posizione 
(0 based) in una variabile o un'espressione è impostato su 0 oppure a 1. 
Se quel certo bit è impostato su 0, l'istruzione restituirà il valore `FALSE`. 
Altrimenti, l'istruzione restituirà il valore `TRUE`.

@syntax = value HAS BIT position

@example IF x HAS BIT 2 THEN: PRINT "bit 2 is 1!": ENDIF

@usedInExample controls_joy_02.bas
@usedInExample controls_keyboard_06.bas
@usedInExample screens_bitmap_01.bas
@usedInExample screens_tilemap_01.bas

@seeAlso HAS NOT BIT
@seeAlso IS
@seeAlso IS NOT

@target all
 </usermanual> */
/* <usermanual>
@keyword HAS NOT BIT

@english
This instruction allows you to check if a certain bit in a certain position (0 based)
in a variable or expression is set to 0 or to 1. If that certain bit is set to 0, 
the instruction will return the value `TRUE`. Otherwise, the statement will return `FALSE`.

@italian
Questa istruzione permette di verificare se un certo bit in una certa posizione 
(0 based) in una variabile o un'espressione è impostato su 0 oppure a 1. 
Se quel certo bit è impostato su 0, l'istruzione restituirà il valore `TRUE`. 
Altrimenti, l'istruzione restituirà il valore `FALSE`.

@syntax = value HAS NOT BIT position

@example IF x HAS NOT BIT 2 THEN: PRINT "bit 2 is 0": ENDIF

@usedInExample controls_joy_02.bas
@usedInExample controls_keyboard_05.bas

@seeAlso HAS NOT BIT
@seeAlso IS
@seeAlso IS NOT

@target all
 </usermanual> */
/* <usermanual>
@keyword IS

@english
This instruction allows you to check if a certain bit in a certain position (0 based)
in a variable or expression is set to 0 or to 1. If that certain bit is set to 0, 
the instruction will return the value `FALSE`. Otherwise, the statement will return `TRUE`.

@italian
Questa istruzione permette di verificare se un certo bit in una certa posizione 
(0 based) in una variabile o un'espressione è impostato su 0 oppure a 1. 
Se quel certo bit è impostato su 0, l'istruzione restituirà il valore `FALSE`. 
Altrimenti, l'istruzione restituirà il valore `TRUE`.

@syntax = value IS position

@example IF x IS 2 THEN: PRINT "bit 2 is 1!": ENDIF

@usedInExample controls_joy_02.bas
@usedInExample controls_keyboard_03.bas

@seeAlso IS NOT
@seeAlso HAS BIT
@seeAlso HAS NOT BIT

@target all
 </usermanual> */
/* <usermanual>
@keyword IS NOT

@english
This instruction allows you to check if a certain bit in a certain position (0 based)
in a variable or expression is set to 0 or to 1. If that certain bit is set to 0, 
the instruction will return the value `TRUE`. Otherwise, the statement will return `FALSE`.

@italian
Questa istruzione permette di verificare se un certo bit in una certa posizione 
(0 based) in una variabile o un'espressione è impostato su 0 oppure a 1. 
Se quel certo bit è impostato su 0, l'istruzione restituirà il valore `TRUE`. 
Altrimenti, l'istruzione restituirà il valore `FALSE`.

@syntax = value IS NOT position

@example IF x IS NOT 2 THEN: PRINT "bit 2 is 0": ENDIF

@usedInExample controls_joy_02.bas
@usedInExample controls_keyboard_05.bas

@seeAlso IS BIT
@seeAlso HAS BIT
@seeAlso HAS NOT BIT

@target all
 </usermanual> */
/* <usermanual>
@keyword BIT...OF

@english
This instruction allows you to check if a certain bit in a certain position (0 based)
in a variable or expression is set to 0 or to 1. If that certain bit is set to 0, 
the instruction will return the value `FALSE`. Otherwise, the statement will return `TRUE`.

@italian
Questa istruzione permette di verificare se un certo bit in una certa posizione 
(0 based) in una variabile o un'espressione è impostato su 0 oppure a 1. 
Se quel certo bit è impostato su 0, l'istruzione restituirà il valore `FALSE`. 
Altrimenti, l'istruzione restituirà il valore `TRUE`.

@syntax = BIT position OF value

@example IF BIT 2 OF x THEN: PRINT "bit 2 is 1!": ENDIF

@seeAlso IS NOT
@seeAlso HAS BIT
@seeAlso HAS NOT BIT

@target all
 </usermanual> */
Variable * variable_bit( Environment * _environment, char * _value, char * _position ) {
    Variable * value = variable_retrieve_or_define( _environment, _value, VT_DWORD, 0 );
    Variable * position = variable_retrieve_or_define( _environment, _position, VT_BYTE, 1 );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of BIT)");

    MAKE_LABEL

    char unsetLabel[MAX_TEMPORARY_STORAGE]; sprintf(unsetLabel, "%sunset", label );
    char setLabel[MAX_TEMPORARY_STORAGE]; sprintf(setLabel, "%sset", label );
    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label );

    switch( VT_BITWIDTH( value->type ) ) {
        case 32:
        case 16:
        case 8:
            cpu_bit_check_extended( _environment, value->realName, position->realName, result->realName, VT_BITWIDTH( value->type ) );
            break;
        case 0:
            CRITICAL_BIT_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type] );
            break;
    }

    return result;
}

ScreenMode * find_screen_mode_by_suggestion( Environment * _environment, int _bitmap, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * screenMode = _environment->screenModes;
    ScreenMode * firstMode = NULL;

    while ( screenMode ) {
        if ( screenMode->bitmap == _bitmap ) {
            firstMode = screenMode;
            break;
        }
        screenMode = screenMode->next;
    }

    if ( ! _width && ! _height && ! _colors ) {
        return firstMode;
    }

    screenMode = _environment->screenModes;
    ScreenMode * bestMode = NULL;

    while ( screenMode ) {
        if ( screenMode->bitmap == _bitmap ) {
           screenMode->score = 1000;
            screenMode->score -= ( _width ) ? ( abs( _width - screenMode->width ) ) : 0;
            screenMode->score -= ( _height ) ? ( abs( _height - screenMode->height ) ) : 0;
            screenMode->score -= ( _colors ) ? ( abs( _colors - screenMode->colors ) ) : 0;
            screenMode->score -= ( _tile_width ) ? ( abs( _tile_width - screenMode->tileWidth ) * 10 ) : 0;
            screenMode->score -= ( _tile_height ) ? ( abs( _tile_height - screenMode->tileHeight ) * 10 ) : 0;
        } else {
            screenMode->score = -1000;
        }
        screenMode = screenMode->next;
    }

    screenMode = _environment->screenModes;
    bestMode = firstMode;

    if ( firstMode ) {
        while ( screenMode ) {
            if ( screenMode->score > bestMode->score ) {
                bestMode = screenMode;
            }
            screenMode = screenMode->next;
        }
    }
   
    return bestMode;

}

ScreenMode * find_screen_mode_by_id( Environment * _environment, int _id ) {

    ScreenMode * screenMode = _environment->screenModes;
    ScreenMode * firstMode = NULL;

    while ( screenMode ) {
        if ( screenMode->id == _id ) {
            firstMode = screenMode;
            break;
        }
        screenMode = screenMode->next;
    }

    return firstMode;

}

Variable * variable_mod( Environment * _environment, char * _source, char * _destination ) {
    
    Variable * source = variable_retrieve( _environment, _source );
    Variable * target = variable_retrieve( _environment, _destination );

    if ( VT_SIGNED( source->type ) != VT_SIGNED( target->type ) ) {
        if ( VT_SIGNED( source->type ) ) {
            target = variable_cast( _environment, _destination, source->type );
        } else {
            source = variable_cast( _environment, _source, VT_SIGN( source->type ) );
            target = variable_cast( _environment, _destination, VT_SIGN( source->type ) );
        }
    } else {
        target = variable_cast( _environment, _destination, source->type );
    }

    Variable * result = NULL;
    Variable * remainder = NULL;
    switch( VT_BITWIDTH( source->type ) ) {
        case 32:
            result = variable_temporary( _environment, VT_DWORD, "(result of division)" );
            remainder = variable_temporary( _environment, VT_WORD, "(remainder of division)" );
            cpu_math_div_32bit_to_16bit( _environment, source->realName, target->realName, result->realName, remainder->realName, VT_SIGNED( source->type ) );
            break;
        case 16:
            result = variable_temporary( _environment, VT_WORD, "(result of division)" );
            remainder = variable_temporary( _environment, VT_WORD, "(remainder of division)" );
            cpu_math_div_16bit_to_16bit( _environment, source->realName, target->realName, result->realName, remainder->realName, VT_SIGNED( source->type ) );
            break;
        case 8:
            result = variable_temporary( _environment, VT_BYTE, "(result of division)" );
            remainder = variable_temporary( _environment, VT_BYTE, "(remainder of division)" );
            cpu_math_div_8bit_to_8bit( _environment, source->realName, target->realName, result->realName, remainder->realName, VT_SIGNED( source->type ) );
            break;
        case 0:
            CRITICAL_DIV_UNSUPPORTED(_source, DATATYPE_AS_STRING[source->type]);
            break;
    }

    return remainder;
}

void const_define_numeric( Environment * _environment, char * _name, int _value ) {

    Constant * c = constant_find( _environment->constants, _name );
    if ( c ) {
        if ( c->valueString ) {
            CRITICAL( "Constant redefined with a different type (numeric -> string)");
        }
        if ( c->value != _value ) {
            CRITICAL( "Numeric constant redefined with a different value");
        }
    } else {
        c = malloc( sizeof( Constant ) );
        memset( c, 0, sizeof( Constant ) );
        c->name = strdup( _name );
        c->realName = malloc( strlen( _name ) + strlen( c->name ) + 2 ); strcpy( c->realName, "_" ); strcat( c->realName, c->name );
        c->value = _value;
        Constant * constLast = _environment->constants;
        if ( constLast ) {
            while( constLast->next ) {
                constLast = constLast->next;
            }
            constLast->next = c;
        } else {
            _environment->constants = c;
        }
        const_emit( _environment, c->name );
    }

}

void const_define_string( Environment * _environment, char * _name, char * _value ) {

    Constant * c = constant_find( _environment->constants, _name );
    if ( c ) {
        if ( ! c->valueString ) {
            CRITICAL( "Constant redefined with a different type (string -> numeric)");
        }
        if ( strcmp( c->valueString , _value ) != 0 ) {
            CRITICAL( "String constant redefined with a different value");
        }
    } else {
        c = malloc( sizeof( Constant ) );
        memset( c, 0, sizeof( Constant ) );
        c->name = strdup( _name );
        c->realName = malloc( strlen( _name ) + strlen( c->name ) + 2 ); strcpy( c->realName, "_" ); strcat( c->realName, c->name );
        c->valueString = strdup( _value );
        Constant * constLast = _environment->constants;
        if ( constLast ) {
            while( constLast->next ) {
                constLast = constLast->next;
            }
            constLast->next = c;
        } else {
            _environment->constants = c;
        }

        const_emit( _environment, c->name );
    
    }

}

void variable_array_fill( Environment * _environment, char * _name, int _value ) {
    
    Variable * array = variable_retrieve( _environment, _name );

    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( array->name );
    }

    if ( array->size > 0 ) {
        cpu_fill_direct_size_value( _environment, array->realName, array->size, _value );
    } else {
        CRITICAL_NOT_SUPPORTED( array->name );
    }

}

void image_converter_asserts( Environment * _environment, int _width, int _height, int _offset_x, int _offset_y, int * _frame_width, int * _frame_height ) {

    if ( _width % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_WIDTH( _width );
    }

    if ( *_frame_width == 0 ) {
        *_frame_width = _width;
    }

    if ( (_offset_x < 0) || (_offset_x >= _width) || ( ( _offset_x + (*_frame_width ) ) > _width ) ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_OFFSET_X( _offset_x );
    }

    if ( _height % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_HEIGHT( _height );
    }

    if ( *_frame_height == 0 ) {
        *_frame_height = _height;
    }

    if ( (_offset_y < 0) || (_offset_y >= _height) || ( ( _offset_y + ( *_frame_height )) > _height ) ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_OFFSET_Y( _offset_y );
    }

}

void image_converter_asserts_free_height( Environment * _environment, int _width, int _height, int _offset_x, int _offset_y, int * _frame_width, int * _frame_height ) {

    if ( _width % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_WIDTH( _width );
    }

    if ( *_frame_width == 0 ) {
        *_frame_width = _width;
    }

    if ( (_offset_x < 0) || (_offset_x >= _width) || ( ( _offset_x + (*_frame_width ) ) > _width ) ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_OFFSET_X( _offset_x );
    }

    if ( *_frame_height == 0 ) {
        *_frame_height = _height;
    }

    if ( (_offset_y < 0) || (_offset_y >= _height) || ( ( _offset_y + ( *_frame_height )) > _height ) ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_OFFSET_Y( _offset_y );
    }

}

char * image_load_asserts( Environment * _environment, char * _filename ) {

    char * lookedFilename = malloc(MAX_TEMPORARY_STORAGE);
    char lookedExtension[MAX_TEMPORARY_STORAGE];
    memset( lookedExtension, 0, MAX_TEMPORARY_STORAGE);

    check_if_filename_is_valid( _environment,  _filename );

    strcpy( lookedFilename, _filename );
    char * c = strrchr( lookedFilename, '/' );
    if ( c ) {
        strcpy( lookedExtension, c );
        *c = 0;
    } else {
        strcpy( lookedExtension, "" );
    }
#if defined(__atari__) 
    strcat( lookedFilename, "/atari" );
#elif defined(__atarixl__) 
    strcat( lookedFilename, "/atarixl" );
#elif __c64__
    strcat( lookedFilename, "/c64" );
#elif __plus4__
    strcat( lookedFilename, "/plus4" );
#elif __zx__
    strcat( lookedFilename, "/zx" );
#elif __d32__ 
    strcat( lookedFilename, "/d32" );
#elif __d64__ 
    strcat( lookedFilename, "/d64" );
#elif __pc128op__ 
    strcat( lookedFilename, "/pc128op" );
#elif __mo5__ 
    strcat( lookedFilename, "/mo5" );
#elif __vic20__ 
    strcat( lookedFilename, "/vic20" );
#elif __msx1__
    strcat( lookedFilename, "/msx1" );
#elif __coleco__
    strcat( lookedFilename, "/coleco" );
#elif __sc3000__
    strcat( lookedFilename, "/sc3000" );
#elif __sg1000__
    strcat( lookedFilename, "/sg1000" );
#elif __c128__
    strcat( lookedFilename, "/c128" );
#endif
    strcat( lookedFilename, lookedExtension );

    FILE * file = fopen( lookedFilename, "rb" );

    if ( !file ) {

        strcpy( lookedFilename, _filename );

        file = fopen( lookedFilename, "rb" );

        if ( !file ) {
            CRITICAL_IMAGE_LOAD_MISSING_FILE( lookedFilename );
        }
    }

    fclose( file );

    return lookedFilename;

}

void variable_temporary_remove( Environment * _environment, char * _name ) {
    
    Variable * varLast = NULL;
    if ( _environment->procedureName ) {
        varLast = _environment->tempVariables[_environment->currentProcedure];
    } else {
        varLast = _environment->tempVariables[0];
    }        
    if ( varLast ) {
        Variable * previous = varLast;
        varLast = varLast->next;
        while( varLast ) {
            if ( strcmp( varLast->name, _name ) == 0 ) {
                previous->next = varLast->next;
                break;
            }
            previous = varLast;
            varLast = varLast->next;
        }
    }

}

int calculate_white_area( TileData * _tileData ) {
    int i=0, j=0;
    int actual = 0;
    for(i=0;i<8;++i) {
        for(j=0;j<8;++j) {
            if ( _tileData->data[j] & ( 1 << i ) ) {
                ++actual;
            }
        }
    }
    return actual;
}

int calculate_horizontal_edges( TileData * _tileData, int _position ) {
    int edges = 0;
    int i=0;
    int actual = 0;
    for(i=0;i<8;++i) {
        if ( _tileData->data[_position] & ( 1 << i ) ) {
            if ( !actual ) {
                ++edges;
                actual = 1;
            }
        } else {
            if ( actual ) {
                ++edges;
                actual = 0;
            }
        }
    }
    return edges;
}

int calculate_vertical_edges( TileData * _tileData, int _position ) {
    int edges = 0;
    int i=0;
    int actual = 0;
    for(i=0;i<8;++i) {
        if ( _tileData->data[i] & ( 1 << _position ) ) {
            if ( !actual ) {
                ++edges;
                actual = 1;
            }
        } else {
            if ( actual ) {
                ++edges;
                actual = 0;
            }
        }
    }
    return edges;
}

TileDescriptor * calculate_tile_descriptor( TileData * _tileData ) {

    TileDescriptor * tileDescriptor = malloc( sizeof( TileDescriptor ) );

    int i=0;

    tileDescriptor->whiteArea = calculate_white_area( _tileData );
    for(i=0;i<8;++i) {
        tileDescriptor->horizontalEdges[i] = calculate_horizontal_edges( _tileData, i );
        tileDescriptor->verticalEdges[i] = calculate_vertical_edges( _tileData, i );
    }

    return tileDescriptor;

}

TileDescriptors * precalculate_tile_descriptors_for_font( char * _fontData ) {

    TileDescriptors * tileDescriptors = malloc( sizeof( TileDescriptors ) );
    memset( tileDescriptors, 0, sizeof( TileDescriptors ) );
    
    int i=0,j=0;

    for(i=0;i<128;++i) {
        for(j=0;j<8;++j) {
            tileDescriptors->data[i].data[j] = *(_fontData + i*8 + j);
        }
        tileDescriptors->descriptor[i] = calculate_tile_descriptor( &tileDescriptors->data[i] );
    }

    tileDescriptors->count = 0;

    return tileDescriptors;

}

int calculate_tile_affinity( TileDescriptor * _first, TileDescriptor * _second ) {

    int affinity = 0;
    int i=0;

    affinity += abs( _first->whiteArea - _second->whiteArea );
    for(i=0;i<8;++i) {
        affinity += abs( _first->horizontalEdges[i] - _second->horizontalEdges[i] );
        affinity += abs( _first->verticalEdges[i] - _second->verticalEdges[i] );
    }

    return affinity;

}

int calculate_nearest_tile( TileDescriptor * _tile, TileDescriptors * _tiles ) {

    int minAffinity = 0xffffff;
    int nearestTileIndex = -1;
    int i;

    for(i=0;i<256;++i) {
        if ( _tiles->descriptor[i] ) {
            int affinity = calculate_tile_affinity( _tile, _tiles->descriptor[i] );
            if ( minAffinity > affinity ) {
                minAffinity = affinity;
                nearestTileIndex = i;
            }
        }
    }

    return nearestTileIndex;

}

int calculate_exact_tile( TileDescriptor * _tile, TileDescriptors * _tiles ) {

    int i=0;

    for(i=0;i<256;++i) {
        if ( _tiles->descriptor[i] ) {
            if ( calculate_tile_affinity( _tile, _tiles->descriptor[i] ) == 0 ) {
                return i;
            };
        }
    }

    return -1;

}

int tile_allocate( TileDescriptors * _tiles, char * _data ) {

    if ( _tiles->firstFree == _tiles->lastFree ) {
        return -1;
    }

    memcpy( _tiles->data[_tiles->firstFree].data, _data, 8 );

    _tiles->descriptor[_tiles->firstFree] = calculate_tile_descriptor( &_tiles->data[_tiles->firstFree] );

    ++_tiles->count;

    return _tiles->firstFree++;

}

Variable * parse_buffer_definition( Environment * _environment, char * _buffer, VariableType _type ) {

    char * buffer = malloc( strlen( _buffer ) / 2 );
    char hexdigits[3];
    int i = 0, c = 0;
    for( i = 1, c = strlen( _buffer ); i<(c-1); i += 2 ) {
        hexdigits[0] = _buffer[i];
        hexdigits[1] = _buffer[i+1];
        hexdigits[2] = 0;
        buffer[i>>1] = strtol(hexdigits,0,16);
    }
    Variable * result = variable_temporary( _environment, _type, "(buffer)" );
    variable_store_buffer( _environment, result->name, buffer, strlen( _buffer ) / 2, 0 );

    return result;

}

char * image_flip_x( Environment * _environment, char * _source, int _width, int _height ) {

    int x,y;

    for( y=0; y<_height; ++y ) {
        for( x=0; x<( _width >> 1 ); ++x ) {
            char * pixel1r = _source + ( y * _width * 3 ) + ( x * 3 );
            char * pixel1g = _source + ( y * _width * 3 ) + ( x * 3 ) + 1;
            char * pixel1b = _source + ( y * _width * 3 ) + ( x * 3 ) + 2;
            char * pixel2r = _source + ( y * _width * 3 ) + ( ( _width - x - 1 ) * 3 );
            char * pixel2g = _source + ( y * _width * 3 ) + ( ( _width - x - 1 ) * 3 ) + 1;
            char * pixel2b = _source + ( y * _width * 3 ) + ( ( _width - x - 1 ) * 3 ) + 2;
            
            char t;
            
            t = *pixel1r;
            *pixel1r = *pixel2r;
            *pixel2r = t;

            t = *pixel1g;
            *pixel1g = *pixel2g;
            *pixel2g = t;

            t = *pixel1b;
            *pixel1b = *pixel2b;
            *pixel2b = t;
        }
    }

    return _source;

}

char * image_flip_y( Environment * _environment, char * _source, int _width, int _height ) {

    int x,y;

    for( x=0; x<_width; ++x ) {
        for( y=0; y<( _height >> 1 ); ++y ) {
            char * pixel1r = _source + ( y * _width * 3 ) + ( x * 3 );
            char * pixel1g = _source + ( y * _width * 3 ) + ( x * 3 ) + 1;
            char * pixel1b = _source + ( y * _width * 3 ) + ( x * 3 ) + 2;
            char * pixel2r = _source + ( ( _height - y - 1) * _width * 3 ) + ( x * 3 );
            char * pixel2g = _source + ( ( _height - y - 1) * _width * 3 ) + ( x * 3 ) + 1;
            char * pixel2b = _source + ( ( _height - y - 1) * _width * 3 ) + ( x * 3 ) + 2;
            
            char t;
            
            t = *pixel1r;
            *pixel1r = *pixel2r;
            *pixel2r = t;

            t = *pixel1g;
            *pixel1g = *pixel2g;
            *pixel2g = t;

            t = *pixel1b;
            *pixel1b = *pixel2b;
            *pixel2b = t;
        }
    }

    return _source;
    
}

char * image_roll_x_right( Environment * _environment, char * _source, int _width, int _height ) {

    int x,y;

    // FILE * f = fopen("/tmp/picture1.bin", "wb" );
    // fwrite( _source, _width * _height * 3, 1, f );
    // fclose( f );

    // printf("*** %d,%d\n", _width, _height );

    for( y=0; y<_height; ++y ) {

        unsigned char * pixel2r = _source + ( y * _width * 3 ) + ( (_width-1) * 3 );
        unsigned char * pixel2g = _source + ( y * _width * 3 ) + ( (_width-1) * 3 ) + 1;
        unsigned char * pixel2b = _source + ( y * _width * 3 ) + ( (_width-1) * 3 ) + 2;        

        unsigned char r, g, b;
        
        r = *pixel2r;
        g = *pixel2g;
        b = *pixel2b;

        for( x=(_width-2); x > -1; --x ) {
            unsigned char * pixel1r = _source + ( y * _width * 3 ) + ( x * 3 );
            unsigned char * pixel1g = _source + ( y * _width * 3 ) + ( x * 3 ) + 1;
            unsigned char * pixel1b = _source + ( y * _width * 3 ) + ( x * 3 ) + 2;
            unsigned char * pixel2r = _source + ( y * _width * 3 ) + ( (x+1) * 3 );
            unsigned char * pixel2g = _source + ( y * _width * 3 ) + ( (x+1) * 3 ) + 1;
            unsigned char * pixel2b = _source + ( y * _width * 3 ) + ( (x+1) * 3 ) + 2;
            
            // printf( "%d,%d : %2.2x%2.2x%2.2x -> %2.2x%2.2x%2.2x\n", y, x, (unsigned char) *pixel2r, (unsigned char) *pixel2g, (unsigned char) *pixel2b, (unsigned char) *pixel1r, (unsigned char) *pixel1g, (unsigned char) *pixel1b );

            *pixel2r = (unsigned char) *pixel1r;
            *pixel2g = (unsigned char) *pixel1g;
            *pixel2b = (unsigned char) *pixel1b;

        }

        unsigned char * pixel1r = _source + ( y * _width * 3 );
        unsigned char * pixel1g = _source + ( y * _width * 3 ) + 1;
        unsigned char * pixel1b = _source + ( y * _width * 3 ) + 2;

        *pixel1r = r;
        *pixel1g = g;
        *pixel1b = b;
    }

    // f = fopen("/tmp/picture2.bin", "wb" );
    // fwrite( _source, _width * _height * 3, 1, f );
    // fclose( f );

    return _source;

}

char * image_roll_x_left( Environment * _environment, char * _source, int _width, int _height ) {

    int x,y;

    // FILE * f = fopen("/tmp/picture1.bin", "wb" );
    // fwrite( _source, _width * _height * 3, 1, f );
    // fclose( f );

    // printf("*** %d,%d\n", _width, _height );

    for( y=0; y<_height; ++y ) {

        unsigned char * pixel2r = _source + ( y * _width * 3 );
        unsigned char * pixel2g = _source + ( y * _width * 3 ) + 1;
        unsigned char * pixel2b = _source + ( y * _width * 3 ) + 2;        

        unsigned char r, g, b;
        
        r = *pixel2r;
        g = *pixel2g;
        b = *pixel2b;

        for( x=0; x<_width-2; ++x ) {
            unsigned char * pixel1r = _source + ( y * _width * 3 ) + ( (x+1) * 3 );
            unsigned char * pixel1g = _source + ( y * _width * 3 ) + ( (x+1) * 3 ) + 1;
            unsigned char * pixel1b = _source + ( y * _width * 3 ) + ( (x+1) * 3 ) + 2;
            unsigned char * pixel2r = _source + ( y * _width * 3 ) + ( (x) * 3 );
            unsigned char * pixel2g = _source + ( y * _width * 3 ) + ( (x) * 3 ) + 1;
            unsigned char * pixel2b = _source + ( y * _width * 3 ) + ( (x) * 3 ) + 2;
            
            // printf( "%d,%d : %2.2x%2.2x%2.2x -> %2.2x%2.2x%2.2x\n", y, x, (unsigned char) *pixel2r, (unsigned char) *pixel2g, (unsigned char) *pixel2b, (unsigned char) *pixel1r, (unsigned char) *pixel1g, (unsigned char) *pixel1b );

            *pixel2r = (unsigned char) *pixel1r;
            *pixel2g = (unsigned char) *pixel1g;
            *pixel2b = (unsigned char) *pixel1b;

        }

        unsigned char * pixel1r = _source + ( y * _width * 3 ) + ( (_width-1) * 3 );
        unsigned char * pixel1g = _source + ( y * _width * 3 ) + ( (_width-1) * 3 ) + 1;
        unsigned char * pixel1b = _source + ( y * _width * 3 ) + ( (_width-1) * 3 ) + 2;

        *pixel1r = r;
        *pixel1g = g;
        *pixel1b = b;
    }

    // f = fopen("/tmp/picture2.bin", "wb" );
    // fwrite( _source, _width * _height * 3, 1, f );
    // fclose( f );

    return _source;

}

char * image_roll_y_down( Environment * _environment, char * _source, int _width, int _height ) {

    int x,y;

    // FILE * f = fopen("/tmp/picture1.bin", "wb" );
    // fwrite( _source, _width * _height * 3, 1, f );
    // fclose( f );

    // printf("*** %d,%d\n", _width, _height );

    for( x=0; x < _width; ++x ) {

        unsigned char * pixel2r = _source + ( ( _height - 1 ) * _width * 3 ) + x * 3;
        unsigned char * pixel2g = _source + ( ( _height - 1 ) * _width * 3 ) + x * 3 + 1;
        unsigned char * pixel2b = _source + ( ( _height - 1 ) * _width * 3 ) + x * 3 + 2;

        unsigned char r, g, b;
        
        r = *pixel2r;
        g = *pixel2g;
        b = *pixel2b;

        for( y=( _height - 2); y > -1; --y ) {
            unsigned char * pixel1r = _source + ( y * _width * 3 ) + ( x * 3 );
            unsigned char * pixel1g = _source + ( y * _width * 3 ) + ( x * 3 ) + 1;
            unsigned char * pixel1b = _source + ( y * _width * 3 ) + ( x * 3 ) + 2;
            unsigned char * pixel2r = _source + ( (y+1) * _width * 3 ) + ( x * 3 );
            unsigned char * pixel2g = _source + ( (y+1) * _width * 3 ) + ( x * 3 ) + 1;
            unsigned char * pixel2b = _source + ( (y+1) * _width * 3 ) + ( x * 3 ) + 2;
            
            // printf( "%d,%d : %2.2x%2.2x%2.2x -> %2.2x%2.2x%2.2x\n", y, x, (unsigned char) *pixel2r, (unsigned char) *pixel2g, (unsigned char) *pixel2b, (unsigned char) *pixel1r, (unsigned char) *pixel1g, (unsigned char) *pixel1b );

            *pixel2r = (unsigned char) *pixel1r;
            *pixel2g = (unsigned char) *pixel1g;
            *pixel2b = (unsigned char) *pixel1b;

        }

        unsigned char * pixel1r = _source + x * 3;
        unsigned char * pixel1g = _source + x * 3 + 1;
        unsigned char * pixel1b = _source + x * 3 + 2;

        *pixel1r = r;
        *pixel1g = g;
        *pixel1b = b;
    }

    // f = fopen("/tmp/picture2.bin", "wb" );
    // fwrite( _source, _width * _height * 3, 1, f );
    // fclose( f );

    return _source;

}

char * image_enlarge_right( Environment * _environment, char * _source, int _width, int _height, int _delta ) {

    int x,y;

    int size = ( _width + _delta ) * 3 * _height;
    char * destination = malloc( size );
    memset( destination, 0, size );

    // FILE * f = fopen("/tmp/picture1.bin", "wb" );
    // fwrite( _source, _width * _height * 3, 1, f );
    // fclose( f );

    // printf("*** %d,%d\n", _width, _height );

    for( y=0; y<_height; ++y ) {
        for( x=0; x < _width; ++x ) {
            unsigned char * pixel1r = _source + ( y * _width * 3 ) + ( x * 3 );
            unsigned char * pixel1g = _source + ( y * _width * 3 ) + ( x * 3 ) + 1;
            unsigned char * pixel1b = _source + ( y * _width * 3 ) + ( x * 3 ) + 2;
            unsigned char * pixel2r = destination + ( y * ( _width + _delta ) * 3 ) + ( (x+1) * 3 );
            unsigned char * pixel2g = destination + ( y * ( _width + _delta ) * 3 ) + ( (x+1) * 3 ) + 1;
            unsigned char * pixel2b = destination + ( y * ( _width + _delta ) * 3 ) + ( (x+1) * 3 ) + 2;
            
            // printf( "%d,%d : %2.2x%2.2x%2.2x -> %2.2x%2.2x%2.2x\n", y, x, (unsigned char) *pixel2r, (unsigned char) *pixel2g, (unsigned char) *pixel2b, (unsigned char) *pixel1r, (unsigned char) *pixel1g, (unsigned char) *pixel1b );

            *pixel2r = (unsigned char) *pixel1r;
            *pixel2g = (unsigned char) *pixel1g;
            *pixel2b = (unsigned char) *pixel1b;
        }
    }

    // f = fopen("/tmp/picture2.bin", "wb" );
    // fwrite( _source, _width * _height * 3, 1, f );
    // fclose( f );

    return destination;

}

char * image_enlarge_bottom( Environment * _environment, char * _source, int _width, int _height, int _delta ) {

    int x,y;

    int size = ( _width ) * 3 * ( _height + _delta);
    char * destination = malloc( size );
    memset( destination, 0, size );
    memcpy( destination, _source, ( _width ) * 3 * ( _height ) );

    return destination;

}

int rgbi_equals_rgb( RGBi * _first, RGBi * _second ) {
    return _first->red == _second->red && _first->green == _second->green && _first->blue == _second->blue;
}

void rgbi_move( RGBi * _source, RGBi * _destination ) {
    memcpy( _destination, _source, sizeof( RGBi ) );
}

/**
 * @brief Calculate the distance between two colors
 *
 * This function calculates the color distance between two colors(_a and _b).
 * By "distance" we mean the geometric distance between two points in a 
 * three-dimensional space, where each dimension corresponds to one of the 
 * components (red, green and blue). The returned value is normalized to 
 * the nearest 8-bit value. 
 * 
 * @param _e1 First color 
 * @param _e2 Second color
 * @return int distance
 */
int rgbi_distance( RGBi * _e1, RGBi * _e2 ) {

    long rmean = ( (long)_e1->red + (long)_e2->red ) / 2;
    long r = (long)_e1->red - (long)_e2->red;
    long g = (long)_e1->green - (long)_e2->green;
    long b = (long)_e1->blue - (long)_e2->blue;
    return (int)( sqrt((((512+rmean)*r*r)>>8) + 4*g*g + (((767-rmean)*b*b)>>8)) );

}

static int rgbi_qsort_compare(const void * _first, const void * _second ) {

    RGBi * first = (RGBi *) _first;
    RGBi * second = (RGBi *) _second;

    return ( first->count <= second->count );

}

/**
 * @brief Extract the color palette from the given image
 * 
 * @param _source 
 * @param _palette 
 * @param _palette_size 
 * @return int 
 */
int rgbi_extract_palette( unsigned char* _source, int _width, int _height, RGBi _palette[], int _palette_size, int _sorted) {

    RGBi rgb;

    memset( _palette, 0, sizeof( RGBi ) * _palette_size );

    int image_x, image_y;

    int usedPalette = 0;
    int i = 0;
    unsigned char* source = _source;

    for (image_y = 0; image_y < _height; ++image_y) {
        for (image_x = 0; image_x < _width; ++image_x) {
            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);
            rgb.count = 0;

            for (i = 0; i < usedPalette; ++i) {
                if (rgbi_equals_rgb( &_palette[i], &rgb )) {
                    break;
                }
            }

            if (i >= usedPalette) {
                rgbi_move( &rgb, &_palette[usedPalette] );
                ++usedPalette;
                if (usedPalette > _palette_size) {
                    break;
                }
            } else {
                ++_palette[i].count;
            }
            source += 3;
        }
        if (usedPalette > _palette_size) {
            break;
        }
    }

    // printf("USED PALETTE: %d\n", usedPalette );

    // printf("PALETTE:\n" );
    // for(i=0;i<8;++i) {
    //     printf("  %i) %2.2x%2.2x%2.2x (%d)\n", i, _palette[i].red, _palette[i].green, _palette[i].blue, _palette[i].count );
    // }

    if ( _sorted ) {
        qsort( _palette, _palette_size, sizeof( RGBi ), rgbi_qsort_compare );
    }

    // printf("QSORT:\n" );
    // for(i=0;i<8;++i) {
    //     printf("  %i) %2.2x%2.2x%2.2x (%d)\n", i, _palette[i].red, _palette[i].green, _palette[i].blue, _palette[i].count );
    // }

    return usedPalette;

}

float max_of_two(float _x, float _y) {
   return (_x > _y) ? _x : _y;
}

float max_of_three(float _m, float _n, float _p) {
   return max_of_two(max_of_two(_m, _n), _p);
}

float min_of_two(float _x, float _y) {
   return (_x < _y) ? _x : _y;
}

float min_of_three(float _m, float _n, float _p) {
   return min_of_two(min_of_two(_m, _n), _p);
}

char * get_temporary_filename( Environment * _environment ) {

    char temp[16];
    memset( temp, 0, 16 );

    char temporaryFilename[MAX_TEMPORARY_STORAGE];

    int i = 0;
    for( i=0; i<15; ++i ) {
        temp[i] = 'a' + ((char) (rand() % 20));
    }

    for(i=0; i<strlen(temp); ++i ) {
        if ( temp[i] == '.' ) {
            temp[i] = '0';
        }
    }

    if ( _environment->temporaryPath ) {
        strcpy( temporaryFilename, _environment->temporaryPath );
        strcat( temporaryFilename, temp );
    } else {
        strcpy( temporaryFilename, temp );
    }

    return strdup( temporaryFilename );

}

int system_call( Environment * _environment, char * _commandline ) {

    #ifdef _WIN32

        char batchFileName[MAX_TEMPORARY_STORAGE];

        sprintf( batchFileName, "%s.bat", get_temporary_filename( _environment ) );

        FILE * fh = fopen( batchFileName, "w+t" );
        fprintf( fh, "@echo off\n%s\n", _commandline );
        fclose( fh );

        char batchFileName2[MAX_TEMPORARY_STORAGE];
        sprintf( batchFileName2, "\"%s\"", batchFileName );

        int result = system( batchFileName2 );

        remove( batchFileName );

        return result;
        
    #else

        return system( _commandline );
        
    #endif

}

char * escape_newlines( char * _string ) {

    char * result = malloc( 6 * strlen( _string ) + 1 );

    memset( result, 0, 6 * strlen( _string ) + 1 );

    char * p = _string, * q = result;

    while( *p ) {
        if ( *p == '\n' || *p == '\r' ) {
            if ( (q-result) > 2 && ( *(q-1) == '"') && ( *(q-2) == ',') ) {
                --q;
            } else {
                *q = '"';
                ++q;
                *q = ',';
                ++q;
            }
            *q = '1';
            ++q;
            *q = '3';
            ++q;
            *q = ',';
            ++q;
            *q = '"';
            ++q;
            ++p;
        } else if ( *p < 31 ) {
            if ( (q-result) > 2 && ( *(q-1) == '"') && ( *(q-2) == ',') ) {
                --q;
            } else {
                *q = '"';
                ++q;
                *q = ',';
                ++q;
            }
            *q = '$';
            ++q;
            *q = ( ( (*p & 0xf0) >> 4 ) < 10 ) ? ( ( (*p & 0xf0) >> 4 ) + '0' ) : ( ( ( (*p & 0xf0) >> 4 ) - 10 ) + 'a' );
            ++q;
            *q = ( ( (*p & 0x0f) ) < 10 ) ? ( ( (*p & 0x0f) ) + '0' ) : ( ( ( (*p & 0x0f) ) - 10 ) + 'a' );
            ++q;
            *q = ',';
            ++q;
            *q = '"';
            ++q;
            ++p;
        } else if ( *p == '"' ) {
            if ( (q-result) > 2 && ( *(q-1) == '"') && ( *(q-2) == ',') ) {
                --q;
            } else {
                *q = '"';
                ++q;
                *q = ',';
                ++q;
            }
            *q = '3';
            ++q;
            *q = '4';
            ++q;
            *q = ',';
            ++q;
            *q = '"';
            ++q;
            ++p;
        } else {
            *q++ = *p++;
        }
    }

    *q = 0;
    int escaped = 1;
    if ( ( *result == '"' ) && ( *(result+1) == ',' ) ) {
        memmove( result, result+2, strlen( result ) - 2 );
        escaped = 0;
        *(result+strlen( result ) - 2) = 0;
    }

    if ( ( *(result+strlen( result )-1) == '"' ) && ( *(result+strlen( result )-2) == ',' ) ) {
        *(result+strlen( result )-2 ) = 0;
    }

    q = result;

    int close_escaped = 0;
    while(*q) {
        if ( *q == '"' ) {
            close_escaped = ! close_escaped;
        }
        ++q;
    }

    char * result2 = malloc( 2 * strlen( result ) );

    if ( escaped ) {
        sprintf( result2, "\"%s", result );
        close_escaped = ! close_escaped;
    } else {
        strcpy( result2, result );
    }
    strcpy( result, result2 );

    if ( close_escaped ) {
        sprintf( result2, "%s\"", result );
    } else {
        strcpy( result2, result );
    }
    strcpy( result, result2 );

    free( result2 );
    
    return result;

}

int check_if_filename_is_valid( Environment * _environment,  char * _filename ) {

    if ( strchr( _filename, ':' ) ) {
        CRITICAL_FILENAME_INVALID_COLON( _filename );
    }

    if ( strchr( _filename, '\\' ) ) {
        CRITICAL_FILENAME_INVALID_BACKSLASH( _filename );
    }

    return 1;

}