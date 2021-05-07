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

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

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

static Bank * bank_find( Bank * _first, char * _name ) {
    Bank * actual = _first;
    while( actual ) {
        if ( strcmp( actual->name, _name ) == 0 ) {
            break;
        }
        actual = actual->next;
    }
    return actual;
}

static void variable_dump( Variable * _first );

static void variable_dump( Variable * _first ) {
    fprintf(stderr, "Variables defined:\n");
    Variable * actual = _first;
    while( actual ) {
        fprintf(stderr, "\t- %s (%d)\n", actual->name, actual->type);
        actual = actual->next;
    }
}

static void variable_reset_pool( Variable * _pool ) {
    Variable * actual = _pool;
    while( actual ) {
        if ( actual->locked == 0 ) {
            actual->used = 0;            
        }
        actual = actual->next;
    }
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

/**
 * @brief Implementation for <b>BANK xxx AT [WITH yyy]</b>
 * 
 * This method deals with populating the data structures for the definition of
 * a "bank" of memory. The memory banks are defined and separate areas, 
 * identified by a name (optionally given) and a starting address and 
 * populated (optionally) with data coming from an external file. This 
 * definition occurs when the program presents a <b>BANK</b> instruction. 
 * Banks are characterized by a "type", which represents the nature of the 
 * data contained therein. The types surveyed are the following:
 * 
 * - `BT_CODE` (<b>CODE</b>) - executable code
 * - `BT_VARIABLES` (<b>VARIABLES</b>) - program's variables
 * - `BT_TEMPORARY` (<b>TEMPORARY</b>) - temporary variables
 * - `BT_DATA` (<b>DATA</b>) - untyped data (graphics, sound, ...)
 * 
 * There can be only one definition of a bank with a specific name. 
 * Any duplicate definitions will be ignored.
 * 
 * @param _environment Current calling environment
 * @param _name Name of the bank (NULL if automatic)
 * @param _type 
 * @param _address 
 * @param _filename 
 * @return Bank* 
 */
/* <usermanual>
@keyword BANK

@english
Define a bank of memory named [identifier], starting from [address] 
of type [bankType]. Optionally, fill the bank of memory with static 
data coming from [filename].

Available [bankType]:

    * ''CODE'' executable code (binary)
    * ''VARIABLES'' program's variables
    * ''TEMPORARY'' temporary variables
    * ''DATA'' unspecified data

If [identifier] is missing, the bank will have an unique name.
If [bankType] is missing, the default type is DATA.
If [filename] is missing, the default is a simply memory reservation.

@italian
Definisce un banco di memoria di nome [identifier], che inizia
all'indirizzo [address] e del tipo [bankType]. In opzione, è possibile
riempire tale banco con dei dati statici che provengano dal file
[filename].

I tipi di banco sono:

    * ''CODE'' codice eseguibile (binario)
    * ''VARIABLES'' variabili del programma
    * ''TEMPORARY'' variabili temporanee
    * ''DATA'' dati non meglio specificati

Se [identifier] manca, al banco sarà assegnato un nome univoco.
Se non viene indicato il [bankType], quello di default è DATA.
Se manca il [filename] allora il banco non sarà preriempito.

@syntax BANK { [identifier] } AT # [address] { AS [bankType]} { WITH [filename] }
@syntax BANK { [bankType] } { [identifier] } AT # [address] { WITH [filename] }

@example BANK VARIABLES AT $c000

@seeAlso VAR

@target all

 </usermanual> */
Bank * bank_define( Environment * _environment, char * _name, BankType _type, int _address, char * _filename ) {
    Bank * bank = NULL;
    if ( _name != NULL ) {
        bank = bank_find( _environment->banks[_type], _name );
    } else {
        char temporaryName[16];
        sprintf(temporaryName, "bank%4.4d", UNIQUE_ID );
        _name = strdup( temporaryName );
    }
    if ( bank ) {
        if ( _filename ) {
            outline4("; BANK %s %s AT $%4.4x WITH \"%s\" (duplicate)", BANK_TYPE_AS_STRING[_type], _name, _address, _filename);
        } else {
            outline3("; BANK %s %s AT $%4.4x (duplicate)", BANK_TYPE_AS_STRING[_type], _name, _address);
        }
    } else {
        if ( _filename ) {
            outline4("; BANK %s %s AT $%4.4x WITH \"%s\"", BANK_TYPE_AS_STRING[_type], _name, _address, _filename);
        } else {
            outline3("; BANK %s %s AT $%4.4x", BANK_TYPE_AS_STRING[_type], _name, _address);
        }
        bank = malloc( sizeof( Variable ) );
        bank->name = strdup( _name );
        bank->type = _type;
        bank->filename = _filename;
        bank->address = _address;
        if ( bank->type == BT_STRINGS ) {
            variable_store( _environment, "strings_address", bank->address );
        }
        bank->next = _environment->banks[_type]; 
        _environment->banks[_type] = bank;
    }
    return bank;
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
    Variable * var = variable_find( _environment->tempVariables, _name );
    if ( ! var ) {
        var = variable_find( _environment->variables, _name );
    }
    if ( ! var ) {
        CRITICAL_VARIABLE( _name );
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
    variable_reset_pool( _environment->tempVariables );        
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
        var->name = strdup( _name );
        var->realName = malloc( strlen( _name ) + 1 ); strcpy( var->realName, "_" ); strcat( var->realName, var->name );
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
        if ( var->type != VT_STRING && var->type != VT_BUFFER ) {
            variable_store( _environment, var->name, _value );
        }
    }
    var->used = 1;
    var->locked = 0;
    return var;
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
 * - `VT_COLOR` (<b>COLOR</b>)
 * - `VT_WORD` (<b>WORD</b>)
 * - `VT_ADDRESS` (<b>ADDRESS</b>)
 * - `VT_POSITION` (<b>POSITION</b>)
 * - `VT_DWORD` (<b>DWORD</b>)
 * 
 * @param _environment Current calling environment
 * @param _type Type of the variable to define
 * @return Variable* The variable definition
 */
Variable * variable_temporary( Environment * _environment, VariableType _type, char * _meaning ) {
    Variable * var = variable_find_first_unused( _environment->tempVariables, _type );
    if ( var ) {
        var->meaningName = _meaning;
    } else {
        char * name = malloc(32);
        sprintf(name, "_tmp%d", UNIQUE_ID);
        var = malloc( sizeof( Variable ) );
        var->name = name;
        var->realName = malloc( strlen( var->name ) + 1 ); strcpy( var->realName, "_" ); strcat( var->realName, var->name );
        var->meaningName = _meaning;
        var->type = _type;
        var->bank = _environment->banks[BT_TEMPORARY];
        Variable * varLast = _environment->tempVariables;
        if ( varLast ) {
            while( varLast->next ) {
                varLast = varLast->next;
            }
            varLast->next = var;
        } else {
            _environment->tempVariables = var;
        }
    }
    if ( var->meaningName ) {
        outline2("; %s <-> %s", var->realName, var->meaningName );
    }
    var->used = 1;
    var->locked = 0;
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
    Variable * source = variable_find( _environment->variables, _source );
    if ( ! source ) {
        source = variable_find( _environment->tempVariables, _source );
    }
    if ( ! source ) {
        CRITICAL_VARIABLE( _source );
    }
    Variable * target = variable_temporary( _environment, _type, "(generated for cast)" );
    switch( source->type ) {
        case VT_ADDRESS:
            switch( target->type ) {
                case VT_ADDRESS:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_BYTE:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case VT_WORD:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_POSITION:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_COLOR:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case VT_DWORD:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot cast from ADDRESS to STRING.");
                    break;
                case VT_BUFFER:
                    CRITICAL("Cannot cast from ADDRESS to BUFFER.");
                    break;
            }
            break;
        case VT_DWORD:
            switch( target->type ) {
                case VT_ADDRESS:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_BYTE:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case VT_WORD:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_POSITION:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_COLOR:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case VT_DWORD:
                    cpu_move_32bit( _environment, source->realName, target->realName );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot cast from DWORD to STRING.");
                    break;
                case VT_BUFFER:
                    CRITICAL("Cannot cast from DWORD to BUFFER.");
                    break;
            }
            break;
        case VT_BYTE:
            switch( target->type ) {
                case VT_ADDRESS:
                case VT_BYTE:
                case VT_WORD:
                case VT_POSITION:
                case VT_COLOR:
                case VT_DWORD:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot cast from BYTE to STRING.");
                    break;
                case VT_BUFFER:
                    CRITICAL("Cannot cast from BYTE to BUFFER.");
                    break;
            }
            break;
        case VT_WORD:
            switch( target->type ) {
                case VT_ADDRESS:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_BYTE:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case VT_WORD:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                    break;
                case VT_POSITION:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                    break;
                case VT_COLOR:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case VT_DWORD:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot cast from WORD to STRING.");
                    break;
                case VT_BUFFER:
                    CRITICAL("Cannot cast from WORD to BUFFER.");
                    break;
            }
            break;
        case VT_POSITION:
            switch( target->type ) {
                case VT_ADDRESS:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_BYTE:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case VT_WORD:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                    break;
                case VT_POSITION:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                    break;
                case VT_COLOR:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case VT_DWORD:
                    cpu_move_16bit( _environment, source->realName, target->realName );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot cast from POSITION to STRING.");
                    break;
                case VT_BUFFER:
                    CRITICAL("Cannot cast from POSITION to BUFFER.");
                    break;
            }
            break;
        case VT_COLOR:
            switch( target->type ) {
                case VT_ADDRESS:
                case VT_BYTE:
                case VT_WORD:
                case VT_POSITION:
                case VT_COLOR:
                case VT_DWORD:
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot cast from COLOR to STRING.");
                    break;
                case VT_BUFFER:
                    CRITICAL("Cannot cast from COLOR to BUFFER.");
                    break;
            }
            break;
        case VT_STRING:
            switch( target->type ) {
                case VT_ADDRESS:
                    CRITICAL("Cannot cast from STRING to ADDRESS.");
                    break;
                case VT_BYTE:
                    CRITICAL("Cannot cast from STRING to BYTE.");
                    break;
                case VT_WORD:
                    CRITICAL("Cannot cast from STRING to WORD.");
                    break;
                case VT_POSITION:
                    CRITICAL("Cannot cast from STRING to POSITION.");
                    break;
                case VT_COLOR:
                    CRITICAL("Cannot cast from STRING to COLOR.");
                    break;
                case VT_DWORD:
                    CRITICAL("Cannot cast from STRING to DWORD.");
                    break;
                case VT_STRING: {
                    char sourceAddress[16]; sprintf(sourceAddress, "%s+1", source->realName );
                    char destinationAddress[16]; sprintf(destinationAddress, "%s+1", target->realName );
                    cpu_move_8bit( _environment, source->realName, target->realName );
                    cpu_move_16bit( _environment, sourceAddress, destinationAddress );
                    break;
                }
                case VT_BUFFER:
                    CRITICAL("Cannot cast from STRING to BUFFER.");
                    break;
            }
            break;
    }
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
Variable * variable_store( Environment * _environment, char * _destination, int _value ) {
    Variable * destination = variable_find( _environment->tempVariables, _destination );
    if ( ! destination ) {
        destination = variable_find( _environment->variables, _destination );
        if ( ! destination ) {
            CRITICAL_VARIABLE( _destination );
        }
    }
    switch( destination->type ) {
        case VT_DWORD:
            cpu_store_32bit( _environment, destination->realName, _value );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_store_16bit( _environment, destination->realName, _value );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_store_8bit( _environment, destination->realName, _value );
            break;
        case VT_STRING:
            CRITICAL("Cannot store a direct value on STRING");
            break;
        case VT_BUFFER:
            CRITICAL("Cannot store a direct value on BUFFER.");
            break;
    }
    return destination;
}

Variable * variable_store_string( Environment * _environment, char * _destination, char * _value ) {
    Variable * destination = variable_find( _environment->tempVariables, _destination );
    if ( ! destination ) {
        destination = variable_find( _environment->variables, _destination );
        if ( ! destination ) {
            CRITICAL_VARIABLE( _destination );
        }
    }
    switch( destination->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot store a STRING on a numeric value");
            break;
        case VT_STRING: {
            Variable * strings_address = variable_retrieve( _environment, "strings_address" );
            char destinationAddress[16]; sprintf(destinationAddress, "%s+1", destination->realName );
            cpu_store_8bit( _environment, destination->realName, strlen( _value ) );
            cpu_move_16bit( _environment, strings_address->realName, destinationAddress );
            while( *_value ) {
                outline1("; storing letter %c", *_value );
                cpu_store_8bit_indirect( _environment, strings_address->realName, *_value );
                cpu_inc_16bit( _environment, strings_address->realName );
                ++_value;
            }
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot store a STRING on BUFFER.");
            break;
    }
    return destination;
}

Variable * variable_resize_buffer( Environment * _environment, char * _destination, int _size ) {
    Variable * destination = variable_find( _environment->tempVariables, _destination );
    if ( ! destination ) {
        destination = variable_find( _environment->variables, _destination );
        if ( ! destination ) {
            CRITICAL_VARIABLE( _destination );
        }
    }
    switch( destination->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
        case VT_STRING:
            CRITICAL("Cannot change the size of a STRING or a numeric value");
            break;
        case VT_BUFFER: {
            destination->size = _size;
            break;
        }
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
    Variable * target = variable_find( _environment->tempVariables, _destination );
    if ( ! target ) {
        target = variable_find( _environment->variables, _destination );
        if ( ! target ) {
            CRITICAL( "Destination variable does not exist" );
        }
    }
    Variable * source = variable_cast( _environment, _source, target->type );
    if ( ! source ) {
        CRITICAL( "Source variable does not cast" );
    }
    switch( source->type ) {
        case VT_DWORD:
            cpu_move_32bit( _environment, source->realName, target->realName );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_move_16bit( _environment, source->realName, target->realName );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_move_8bit( _environment, source->realName, target->realName );
            break;
        case VT_STRING: {
            char sourceAddress[16]; sprintf(sourceAddress, "%s+1", source->realName );
            char destinationAddress[16]; sprintf(destinationAddress, "%s+1", target->realName );
            cpu_move_8bit( _environment, source->realName, target->realName );
            cpu_move_16bit( _environment, sourceAddress, destinationAddress );
            break;
        }
        case VT_BUFFER: {
            if ( source->size != target->size ) {
                CRITICAL( "Cannot move BUFFERS of different sizes");
            }
            cpu_mem_move_size( _environment, source->realName, target->realName, source->size );
            break;
        }
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
    Variable * source = variable_find( _environment->tempVariables, _source );
    if ( ! source ) {
        source = variable_find( _environment->variables, _source );
        if ( ! source ) {
            CRITICAL_VARIABLE( _source );
        }
    }
    Variable * target = variable_find( _environment->tempVariables, _destination );
    if ( ! target ) {
        target = variable_find( _environment->variables, _destination );
        if ( ! target ) {
            CRITICAL_VARIABLE( _source );
        }
    }
    switch( source->type ) {
        case VT_DWORD:
            cpu_move_32bit( _environment, source->realName, target->realName );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_move_16bit( _environment, source->realName, target->realName );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_move_8bit( _environment, source->realName, target->realName );
            break;
        case VT_STRING: {
            char sourceAddress[16]; sprintf(sourceAddress, "%s+1", source->realName );
            char destinationAddress[16]; sprintf(destinationAddress, "%s+1", target->realName );
            cpu_move_8bit( _environment, source->realName, target->realName );
            cpu_move_16bit( _environment, sourceAddress, destinationAddress );
            break;
        }
        case VT_BUFFER: {
            if ( source->size != target->size ) {
                CRITICAL( "Cannot move BUFFERS of different sizes");
            }
            cpu_mem_move_size( _environment, source->realName, target->realName, source->size );
            break;
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
    Variable * source = variable_find( _environment->tempVariables, _source );
    if ( ! source ) {
        source = variable_find( _environment->variables, _source );
    }
    if ( ! source ) {
        CRITICAL_VARIABLE(_source);
    }
    Variable * target = variable_cast( _environment, _destination, source->type );
    if ( ! target ) {
        CRITICAL_VARIABLE(_destination);
    }
    Variable * result = variable_temporary( _environment, source->type, "(result of adding)" );
    switch( source->type ) {
        case VT_DWORD:
            cpu_math_add_32bit( _environment, source->realName, target->realName, result->realName );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_math_add_16bit( _environment, source->realName, target->realName, result->realName );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_math_add_8bit( _environment, source->realName, target->realName, result->realName );
            break;
        case VT_STRING:  {
            outline2("; ADD STRINGS (%s,%s)", source->realName, target->realName);
            Variable * strings_address = variable_retrieve( _environment, "strings_address" );
            char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );
            char sourceAddress[16]; sprintf(sourceAddress, "%s+1", source->realName );
            char targetAddress[16]; sprintf(targetAddress, "%s+1", target->realName );
            outline0("; cpu_move_8bit");
            cpu_move_8bit( _environment, source->realName, result->realName );
            outline0("; cpu_math_add_8bit");
            cpu_math_add_8bit( _environment, target->realName, result->realName, result->realName );
            outline0("; cpu_move_16bit");
            cpu_move_16bit( _environment, strings_address->realName, resultAddress );
            outline0("; cpu_mem_move");
            cpu_mem_move( _environment, sourceAddress, resultAddress, source->realName );
            outline0("; cpu_math_add_16bit_with_8bit");
            cpu_math_add_16bit_with_8bit( _environment, resultAddress, source->realName, resultAddress );
            outline0("; cpu_mem_move");
            cpu_mem_move( _environment, targetAddress, resultAddress, target->realName );
            outline0("; cpu_math_sub_16bit_with_8bit");
            cpu_math_sub_16bit_with_8bit( _environment, resultAddress, source->realName, resultAddress );
            outline0("; ---");
            cpu_math_add_16bit_with_8bit( _environment, strings_address->realName, source->realName, strings_address->realName );
            cpu_math_add_16bit_with_8bit( _environment, strings_address->realName, target->realName, strings_address->realName );
            break;
        }
        case VT_BUFFER: {
            CRITICAL( "Cannot add BUFFERS");
        }
    }
    return result;
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
    Variable * source = variable_find( _environment->tempVariables, _source );
    if ( ! source ) {
        source = variable_find( _environment->variables, _source );
        if ( ! source ) {
            CRITICAL("Source variable does not exist");
        }
    }
    Variable * target = variable_cast( _environment, _dest, source->type );
    if ( ! target ) {
        CRITICAL("Destination variable does not cast");
    }
    Variable * result = variable_temporary( _environment, source->type, "(result of subtracting)" );
    switch( source->type ) {
        case VT_DWORD:
            cpu_math_sub_32bit( _environment, source->realName, target->realName, result->realName );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_math_sub_16bit( _environment, source->realName, target->realName, result->realName );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_math_sub_8bit( _environment, source->realName, target->realName, result->realName );
            break;
        case VT_STRING:
            CRITICAL("Cannot subtract STRINGS!");
            break;
        case VT_BUFFER: {
            CRITICAL( "Cannot sub BUFFERS");
        }

     }
    return result;
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
    Variable * destination = variable_find( _environment->tempVariables, _destination );
    if ( ! destination ) {
        destination = variable_find( _environment->variables, _destination );
        if ( ! destination ) {
            CRITICAL("Destination variable does not exist");
        }
    }
    switch( destination->type ) {
        case VT_DWORD:
            cpu_math_complement_const_32bit( _environment, destination->realName, _value );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_math_complement_const_16bit( _environment, destination->realName, _value );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_math_complement_const_8bit( _environment, destination->realName, _value );
            break;
        case VT_STRING:
            CRITICAL("Cannot calculate a complement of a STRING");
            break;
        case VT_BUFFER: {
            CRITICAL( "Cannot calculate complement of a BUFFER");
        }
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
    Variable * source = variable_find( _environment->tempVariables, _source );
    if ( ! source ) {
        source = variable_find( _environment->variables, _source );
        if ( ! source ) {
            CRITICAL("Source variable does not exist");
        }
    }
    Variable * target = variable_cast( _environment, _destination, source->type );
    if ( ! target ) {
        CRITICAL("Destination variable does not cast");
    }
    Variable * result = NULL;
    switch( source->type ) {
        case VT_DWORD:
            WARNING_BITWIDTH(source->name);
            WARNING_BITWIDTH(target->name);
            result = variable_temporary( _environment, VT_DWORD, "(result of multiplication)" );
            cpu_math_mul_16bit_to_32bit( _environment, source->realName, target->realName, result->realName );
            break;
        case VT_STRING:
            CRITICAL("Cannot calculate multiplication of STRING variables");
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            result = variable_temporary( _environment, VT_DWORD, "(result of multiplication)" );
            cpu_math_mul_16bit_to_32bit( _environment, source->realName, target->realName, result->realName );
            break;
        case VT_BYTE:
        case VT_COLOR:
            result = variable_temporary( _environment, VT_WORD, "(result of multiplication)" );
            cpu_math_mul_8bit_to_16bit( _environment, source->realName, target->realName, result->realName );
            break;
        case VT_BUFFER: {
            CRITICAL( "Cannot multiplicate a BUFFER");
        }
    }

    return result;
}

Variable * variable_div( Environment * _environment, char * _source, char * _destination ) {
    Variable * source = variable_find( _environment->tempVariables, _source );
    if ( ! source ) {
        source = variable_find( _environment->variables, _source );
        if ( ! source ) {
            CRITICAL("Source variable does not exist");
        }
    }
    Variable * target = variable_cast( _environment, _destination, source->type );
    if ( ! target ) {
        CRITICAL("Destination variable does not cast");
    }
    Variable * result = NULL;
    Variable * remainder = NULL;
    switch( source->type ) {
        case VT_DWORD:
            result = variable_temporary( _environment, VT_DWORD, "(result of division)" );
            remainder = variable_temporary( _environment, VT_WORD, "(remainder of division)" );
            cpu_math_div_32bit_to_16bit( _environment, source->realName, target->realName, result->realName, remainder->realName );
            break;
        case VT_STRING:
            CRITICAL("Cannot calculate division of STRING variables");
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            result = variable_temporary( _environment, VT_DWORD, "(result of division)" );
            remainder = variable_temporary( _environment, VT_WORD, "(remainder of division)" );
            cpu_math_div_16bit_to_16bit( _environment, source->realName, target->realName, result->realName, remainder->realName );
            break;
        case VT_BYTE:
        case VT_COLOR:
            result = variable_temporary( _environment, VT_BYTE, "(result of division)" );
            remainder = variable_temporary( _environment, VT_BYTE, "(remainder of division)" );
            cpu_math_div_8bit_to_8bit( _environment, source->realName, target->realName, result->realName, remainder->realName );
            break;
        case VT_BUFFER: {
            CRITICAL( "Cannot divide a BUFFER");
        }
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
Variable * variable_compare( Environment * _environment, char * _source, char * _destination ) {
    Variable * source = variable_find( _environment->tempVariables, _source );
    if ( ! source ) {
        source = variable_find( _environment->variables, _source );
    }
    if ( ! source ) {
        CRITICAL("Source variable does not exist");
    }
    Variable * target = variable_find( _environment->tempVariables, _destination );
    if ( ! target ) {
        target = variable_find( _environment->variables, _destination );
    }
    if ( ! target ) {
        CRITICAL("Destination variable does not exist");
    }
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of compare)" );
    switch( source->type ) {
        case VT_DWORD:
            switch( target->type ) {
                case VT_DWORD:
                    cpu_compare_32bit( _environment, source->realName, target->realName, result->realName, 1 );
                    break;
                case VT_ADDRESS:
                case VT_POSITION:
                case VT_WORD:
                    cpu_compare_16bit( _environment, source->realName, target->realName, result->realName, 1 );
                    break;
                case VT_BYTE:
                case VT_COLOR:
                    cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 1 );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot compare DWORD with STRING");
                    break;
                case VT_BUFFER:
                    CRITICAL("Cannot compare DWORD with BUFFER");
                    break;
            }
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            switch( target->type ) {
                case VT_DWORD:
                case VT_ADDRESS:
                case VT_POSITION:
                case VT_WORD:
                    cpu_compare_16bit( _environment, source->realName, target->realName, result->realName, 1 );
                    break;
                case VT_BYTE:
                case VT_COLOR:
                    cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 1 );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot compare ADDRESS/POSITION/WORD with STRING");
                    break;
                case VT_BUFFER:
                    CRITICAL("Cannot compare ADDRESS/POSITION/WORD with BUFFER");
                    break;
            }
            break;
        case VT_BYTE:
        case VT_COLOR:
            switch( target->type ) {
                case VT_DWORD:
                case VT_ADDRESS:
                case VT_POSITION:
                case VT_WORD:
                case VT_BYTE:
                case VT_COLOR:
                    cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 1 );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot compare BYTE/COLOR with STRING");
                    break;
                case VT_BUFFER:
                    CRITICAL("Cannot compare BYTE/COLOR with BUFFER");
                    break;
            }
            break;
        case VT_STRING:
            switch( target->type ) {
                case VT_DWORD:
                    CRITICAL("Cannot compare STRING with DWORD");
                    break;
                case VT_ADDRESS:
                    CRITICAL("Cannot compare STRING with DWORD");
                    break;
                case VT_POSITION:
                    CRITICAL("Cannot compare STRING with POSITION");
                    break;
                case VT_WORD:
                    CRITICAL("Cannot compare STRING with WORD");
                    break;
                case VT_BYTE:
                    CRITICAL("Cannot compare STRING with BYTE");
                    break;
                case VT_COLOR:
                    CRITICAL("Cannot compare STRING with COLOR");
                    break;
                case VT_STRING: {
                    
                    MAKE_LABEL

                    char sourceAddress[16]; sprintf(sourceAddress, "%s+1", source->realName );
                    char destinationAddress[16]; sprintf(destinationAddress, "%s+1", target->realName );
                    cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 1 );
                    cpu_bveq( _environment, result->realName, label );
                    cpu_compare_memory( _environment, sourceAddress, destinationAddress, source->realName, result->realName, 1 );
                    cpu_label( _environment, label );
                    break;
                }
                case VT_BUFFER:
                    CRITICAL("Cannot compare STRING with BUFFER");
                    break;
            }
            break;
        case VT_BUFFER:
            switch( target->type ) {
                case VT_DWORD:
                    CRITICAL("Cannot compare BUFFER with DWORD");
                    break;
                case VT_ADDRESS:
                    CRITICAL("Cannot compare BUFFER with ADDRESS");
                    break;
                case VT_POSITION:
                    CRITICAL("Cannot compare BUFFER with POSITION");
                    break;
                case VT_WORD:
                    CRITICAL("Cannot compare BUFFER with WORD");
                    break;
                case VT_BYTE:
                    CRITICAL("Cannot compare BUFFER with BYTE");
                    break;
                case VT_COLOR:
                    CRITICAL("Cannot compare BUFFER with COLOR");
                    break;
                case VT_STRING:
                    CRITICAL("Cannot compare BUFFER with STRING");
                    break;
                case VT_BUFFER: 
                    cpu_compare_memory_size( _environment, source->realName, target->realName, source->size, result->realName, 1 );
                    break;
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
    Variable * destination = variable_find( _environment->tempVariables, _destination );
    if ( ! destination ) {
        destination = variable_find( _environment->variables, _destination );
        if ( ! destination ) {
            CRITICAL( "Destination variable does not exist" );
        }
    }
    switch( destination->type ) {
        case VT_DWORD:
            cpu_math_mul2_const_32bit( _environment, destination->realName, _steps );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_math_mul2_const_16bit( _environment, destination->realName, _steps );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_math_mul2_const_8bit( _environment, destination->realName, _steps );
            break;
        case VT_STRING:
            CRITICAL("Cannot multiplicate a STRING by 2");
            break;
        case VT_BUFFER:
            CRITICAL("Cannot multiplicate a BUFFER by 2");
            break;
    }
    return destination;
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
    Variable * destination = variable_find( _environment->tempVariables, _destination );
    if ( ! destination ) {
        destination = variable_find( _environment->variables, _destination );
        if ( ! destination ) {
            CRITICAL("Destination variable does not exist");
        }
    }
    switch( destination->type ) {
        case VT_DWORD:
            cpu_math_div2_const_32bit( _environment, destination->realName, _bits );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_math_div2_const_16bit( _environment, destination->realName, _bits );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_math_div2_const_8bit( _environment, destination->realName, _bits );
            break;
        case VT_STRING:
            CRITICAL("Cannot divide a STRING by 2");
            break;
        case VT_BUFFER:
            CRITICAL("Cannot divide a BUFFER by 2");
            break;
    }
    return destination;
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
    Variable * destination = variable_find( _environment->tempVariables, _destination );
    if ( ! destination ) {
        destination = variable_find( _environment->variables, _destination );
        if ( ! destination ) {
            CRITICAL("Destination variable does not exist");
        }
    }
    switch( destination->type ) {
        case VT_DWORD:
            cpu_math_and_const_32bit( _environment, destination->realName, _mask );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_math_and_const_16bit( _environment, destination->realName, _mask );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_math_and_const_8bit( _environment, destination->realName, _mask );
            break;
        case VT_STRING:
            CRITICAL("Cannot make an \"and\" with a STRING");
            break;
        case VT_BUFFER:
            CRITICAL("Cannot make an \"and\" with a BUFFER");
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
    Variable * left = variable_cast( _environment, _left, VT_BYTE );
    Variable * right = variable_cast( _environment, _right, VT_BYTE );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of logical AND)");
    cpu_logical_and_8bit( _environment, left->realName, right->realName, result->realName );
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
    Variable * left = variable_cast( _environment, _left, VT_BYTE );
    Variable * right = variable_cast( _environment, _right, VT_BYTE );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of logical OR)");
    cpu_logical_or_8bit( _environment, left->realName, right->realName, result->realName );
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
    Variable * value = variable_cast( _environment, _value, VT_BYTE );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of logical NOT)");
    cpu_logical_not_8bit( _environment, value->realName, result->realName );
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
    Variable * source = variable_find( _environment->tempVariables, _source );
    if ( ! source ) {
        source = variable_find( _environment->variables, _source );
    }
    if ( ! source ) {
        CRITICAL("Source variable does not exist");
    }
    Variable * target = variable_find( _environment->tempVariables, _destination );
    if ( ! target ) {
        target = variable_find( _environment->variables, _destination );
    }
    if ( ! source ) {
        CRITICAL("Destination variable does not exist");
    }
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of compare)" );
    switch( source->type ) {
        case VT_DWORD:
            cpu_less_than_32bit( _environment, source->realName, target->realName, result->realName, _equal );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_less_than_16bit( _environment, source->realName, target->realName, result->realName, _equal );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_less_than_8bit( _environment, source->realName, target->realName, result->realName, _equal );
            break;
        case VT_STRING: {

            MAKE_LABEL

            char sourceAddress[16]; sprintf(sourceAddress, "%s+1", source->realName );
            char destinationAddress[16]; sprintf(destinationAddress, "%s+1", target->realName );
            cpu_less_than_8bit( _environment, source->realName, target->realName, result->realName, _equal );
            cpu_bveq( _environment, result->realName, label );
            cpu_less_than_memory( _environment, sourceAddress, destinationAddress, source->realName, result->realName, _equal );
            cpu_label( _environment, label );
            break;
        }
        case VT_BUFFER:
            cpu_less_than_memory_size( _environment, source->realName, target->realName, source->size, result->realName, _equal );
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
    Variable * source = variable_find( _environment->tempVariables, _source );
    if ( ! source ) {
        source = variable_find( _environment->variables, _source );
    }
    if ( ! source ) {
        CRITICAL("Source variable does not exist");
    }
    Variable * target = variable_find( _environment->tempVariables, _destination );
    if ( ! target ) {
        target = variable_find( _environment->variables, _destination );
    }
    if ( ! source ) {
        CRITICAL("Destination variable does not exist");
    }
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of compare)" );
    switch( source->type ) {
        case VT_DWORD:
            cpu_greater_than_32bit( _environment, source->realName, target->realName, result->realName, _equal );
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_greater_than_16bit( _environment, source->realName, target->realName, result->realName, _equal );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_greater_than_8bit( _environment, source->realName, target->realName, result->realName, _equal );
            break;
        case VT_STRING: {
            
            MAKE_LABEL

            char sourceAddress[16]; sprintf(sourceAddress, "%s+1", source->realName );
            char destinationAddress[16]; sprintf(destinationAddress, "%s+1", target->realName );
            cpu_greater_than_8bit( _environment, source->realName, target->realName, result->realName, _equal );
            cpu_bveq( _environment, result->realName, label );
            cpu_greater_than_memory( _environment, sourceAddress, destinationAddress, source->realName, result->realName, _equal );
            cpu_label( _environment, label );
            break;
        }
        case VT_BUFFER:
            cpu_greater_than_memory_size( _environment, source->realName, target->realName, source->size, result->realName, _equal );
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
    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }
    Variable * position = variable_find( _environment->tempVariables, _position );
    if ( ! position ) {
        position = variable_find( _environment->variables, _position );
    }
    if ( ! position ) {
        CRITICAL("Position variable does not exist");
    }
    Variable * result = variable_temporary( _environment, VT_STRING, "(result of left)" );
    switch( string->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot make a LEFT function on a number");
            break;
        case VT_STRING: {            
            char stringAddress[16]; sprintf(stringAddress, "%s+1", string->realName );
            char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );
            Variable * strings_address = variable_retrieve( _environment, "strings_address" );
            outline0("; here 1!");
            cpu_move_16bit( _environment, strings_address->realName, resultAddress );
            outline0("; here 2!");
            cpu_mem_move( _environment, stringAddress, resultAddress, position->realName );
            outline0("; here 3!");
            cpu_move_8bit( _environment, position->realName, result->realName );
            outline0("; here 4!");
            cpu_math_add_16bit_with_8bit( _environment, strings_address->realName, position->realName, strings_address->realName );
            outline0("; here 5!");
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot make a LEFT function on a BUFFER");
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
    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }
    Variable * position = variable_find( _environment->tempVariables, _position );
    if ( ! position ) {
        position = variable_find( _environment->variables, _position );
    }
    if ( ! position ) {
        CRITICAL("Position variable does not exist");
    }
    Variable * expression = variable_find( _environment->tempVariables, _expression );
    if ( ! expression ) {
        expression = variable_find( _environment->variables, _expression );
    }
    if ( ! expression ) {
        CRITICAL("Position variable does not exist");
    }
    switch( string->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot make a LEFT assignment on a number");
            break;
        case VT_STRING: {            
            char expressionAddress[16]; sprintf(expressionAddress, "%s+1", expression->realName );
            char stringAddress[16]; sprintf(stringAddress, "%s+1", string->realName );
            cpu_mem_move( _environment, expressionAddress, stringAddress, position->realName );
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot make a LEFT function on a BUFFER");
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
    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }
    Variable * position = variable_find( _environment->tempVariables, _position );
    if ( ! position ) {
        position = variable_find( _environment->variables, _position );
    }
    if ( ! position ) {
        CRITICAL("Position variable does not exist");
    }
    Variable * result = variable_temporary( _environment, VT_STRING, "(result of left)" );
    switch( string->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot make a LEFT function on a number");
            break;
        case VT_STRING: {            
            char stringAddress[16]; sprintf(stringAddress, "%s+1", string->realName );
            char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );
            Variable * strings_address = variable_retrieve( _environment, "strings_address" );
            outline0("; here 1!");
            cpu_move_16bit( _environment, strings_address->realName, resultAddress );
            outline0("; here 2!");
            cpu_math_add_16bit_with_8bit( _environment, stringAddress, string->realName, stringAddress );
            outline0("NOP");
            outline0("NOP");
            outline0("NOP");
            outline0("NOP");
            outline0("NOP");
            cpu_math_sub_16bit_with_8bit( _environment, stringAddress, position->realName, stringAddress );
            cpu_mem_move( _environment, stringAddress, resultAddress, position->realName );
            outline0("; here 3!");
            cpu_move_8bit( _environment, position->realName, result->realName );
            outline0("; here 4!");
            cpu_math_add_16bit_with_8bit( _environment, strings_address->realName, position->realName, strings_address->realName );
            outline0("; here 5!");
            cpu_math_add_16bit_with_8bit( _environment, stringAddress, position->realName, stringAddress );
            cpu_math_sub_16bit_with_8bit( _environment, stringAddress, string->realName, stringAddress );
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot make a RIGHT function on a BUFFER");
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
    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }
    Variable * position = variable_find( _environment->tempVariables, _position );
    if ( ! position ) {
        position = variable_find( _environment->variables, _position );
    }
    if ( ! position ) {
        CRITICAL("Position variable does not exist");
    }
    Variable * expression = variable_find( _environment->tempVariables, _expression );
    if ( ! expression ) {
        expression = variable_find( _environment->variables, _expression );
    }
    if ( ! expression ) {
        CRITICAL("Position variable does not exist");
    }
    switch( string->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot make a RIGHT assignment on a number");
            break;
        case VT_STRING: {            
            char expressionAddress[16]; sprintf(expressionAddress, "%s+1", expression->realName );
            char stringAddress[16]; sprintf(stringAddress, "%s+1", string->realName );
            cpu_math_add_16bit_with_8bit( _environment, stringAddress, string->realName, stringAddress );
            cpu_math_sub_16bit_with_8bit( _environment, stringAddress, position->realName, stringAddress );
            cpu_mem_move( _environment, expressionAddress, stringAddress, position->realName );
            cpu_math_add_16bit_with_8bit( _environment, stringAddress, position->realName, stringAddress );
            cpu_math_sub_16bit_with_8bit( _environment, stringAddress, string->realName, stringAddress );
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot make a RIGHT assignment on a BUFFER");
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
    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }
    Variable * position = variable_find( _environment->tempVariables, _position );
    if ( ! position ) {
        position = variable_find( _environment->variables, _position );
    }
    if ( ! position ) {
        CRITICAL("Position variable does not exist");
    }
    Variable * len;
    if ( _len ) {
        len = variable_find( _environment->tempVariables, _len );
        if ( ! len ) {
            len = variable_find( _environment->variables, _len );
        }
        if ( ! position ) {
            CRITICAL("Len variable does not exist");
        }
    } else {
        len = variable_temporary( _environment, VT_BYTE, "(calculated MID len)");
        variable_store( _environment, len->name, 0 );
    }
    Variable * result = variable_temporary( _environment, VT_STRING, "(result of mid)" );
    switch( string->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot make a MID function on a number");
            break;
        case VT_STRING: {            
            Variable * strings_address = variable_retrieve( _environment, "strings_address" );
            char stringAddress[16]; sprintf(stringAddress, "%s+1", string->realName );
            char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );
            if ( _len ) {
                cpu_move_16bit( _environment, strings_address->realName, resultAddress );
                cpu_math_add_16bit_with_8bit( _environment, stringAddress, position->realName, stringAddress );
                cpu_mem_move( _environment, stringAddress, resultAddress, len->realName );
                cpu_move_8bit( _environment, len->realName, result->realName );
                cpu_math_add_16bit_with_8bit( _environment, strings_address->realName, len->realName, strings_address->realName );
                cpu_math_sub_16bit_with_8bit( _environment, stringAddress, position->realName, stringAddress );
            } else {
                cpu_math_add_8bit( _environment, len->realName, string->realName, len->realName );
                cpu_math_sub_8bit( _environment, len->realName, position->realName, len->realName );
                cpu_move_16bit( _environment, strings_address->realName, resultAddress );
                cpu_math_add_16bit_with_8bit( _environment, stringAddress, position->realName, stringAddress );
                cpu_mem_move( _environment, stringAddress, resultAddress, len->realName );
                cpu_move_8bit( _environment, len->realName, result->realName );
                cpu_math_add_16bit_with_8bit( _environment, strings_address->realName, len->realName, strings_address->realName );
                cpu_math_sub_16bit_with_8bit( _environment, stringAddress, position->realName, stringAddress );
            }
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot make a MID function on a BUFFER");
            break;
    }
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
    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }
    Variable * position = variable_find( _environment->tempVariables, _position );
    if ( ! position ) {
        position = variable_find( _environment->variables, _position );
    }
    if ( ! position ) {
        CRITICAL("Position variable does not exist");
    }
    Variable * len;
    if ( _len ) {
        len = variable_find( _environment->tempVariables, _len );
        if ( ! len ) {
            len = variable_find( _environment->variables, _len );
        }
        if ( ! position ) {
            CRITICAL("Len variable does not exist");
        }
    } else {
        len = variable_temporary( _environment, VT_BYTE, "(calculated MID len)");
        variable_store( _environment, len->name, 0 );
        cpu_math_add_8bit( _environment, len->realName, string->realName, len->realName );
        cpu_math_sub_8bit( _environment, len->realName, position->realName, len->realName );
    }
    Variable * expression = variable_find( _environment->tempVariables, _expression );
    if ( ! expression ) {
        expression = variable_find( _environment->variables, _expression );
    }
    if ( ! expression ) {
        CRITICAL("Position variable does not exist");
    }
    switch( string->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot make a RIGHT assignment on a number");
            break;
        case VT_STRING: {            
            char expressionAddress[16]; sprintf(expressionAddress, "%s+1", expression->realName );
            char stringAddress[16]; sprintf(stringAddress, "%s+1", string->realName );
            cpu_math_add_16bit_with_8bit( _environment, stringAddress, position->realName, stringAddress );
            cpu_mem_move( _environment, expressionAddress, stringAddress, len->realName );
            cpu_math_sub_16bit_with_8bit( _environment, stringAddress, position->realName, stringAddress );
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot make a MID assignment on a BUFFER");
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
    Variable * search = variable_find( _environment->tempVariables, _search );
    if ( ! search ) {
        search = variable_find( _environment->variables, _search );
    }
    if ( ! search ) {
        CRITICAL("String variable does not exist");
    }
    Variable * searched = variable_find( _environment->tempVariables, _searched );
    if ( ! searched ) {
        searched = variable_find( _environment->variables, _searched );
    }
    if ( ! searched ) {
        CRITICAL("Position variable does not exist");
    }
    Variable * start = NULL;
    if ( _start ) {
        start = variable_find( _environment->tempVariables, _start );
        if ( ! start ) {
            start = variable_find( _environment->variables, _start );
        }
        if ( ! start ) {
            CRITICAL("Len variable does not exist");
        }
    }
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of INSTR)" );
    switch( search->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot make a INSTR function on a number");
            break;
        case VT_STRING:
            break;
        case VT_BUFFER:
            CRITICAL("Cannot make a INSTR function on a BUFFER");
    }
    switch( searched->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot make a INSTR function on a number");
            break;
        case VT_STRING:
            break;
        case VT_BUFFER:
            CRITICAL("Cannot make a INSTR function on a BUFFER");
    }

    MAKE_LABEL

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address offset of search)" );
    Variable * found = variable_temporary( _environment, VT_BYTE, "(found flag)" );
    char searchAddress[16]; sprintf(searchAddress, "%s+1", search->realName );
    char searchedAddress[16]; sprintf(searchedAddress, "%s+1", searched->realName );
    char repeatLabel[16]; sprintf( repeatLabel, "%srep", label );
    char foundLabel[16]; sprintf( foundLabel, "%sfnd", label );
    char notFoundLabel[16]; sprintf( notFoundLabel, "%snfnd", label );

    cpu_move_16bit( _environment, searchAddress, address->realName );
    if ( start ) {
        cpu_math_add_16bit_with_8bit( _environment, address->realName, start->realName, address->realName );
        cpu_move_8bit( _environment, start->realName, result->realName );
    } else {
        cpu_store_8bit( _environment, result->realName, 0 );        
    }

    cpu_label( _environment, repeatLabel );

    cpu_compare_8bit( _environment, result->realName, search->realName, found->realName, 1 );

    cpu_bvneq( _environment, found->realName, notFoundLabel );

    outline0("NOP");
    outline0("NOP");
    outline0("NOP");

    cpu_compare_memory( _environment, address->realName, searchedAddress, searched->realName, found->realName, 1 );

    outline0("NOP");
    outline0("NOP");
    outline0("NOP");
    outline0("NOP");

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
    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }
    Variable * result = variable_cast( _environment, string->name, VT_STRING );
    switch( string->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot make a UPPER function on a number");
            break;
        case VT_STRING:
            break;
        case VT_BUFFER:
            CRITICAL("Cannot make a UPPER function on a BUFFER");
    }
    Variable * found = variable_temporary( _environment, VT_BYTE, "(valid alphabetic)" );
    Variable * index = variable_temporary( _environment, VT_BYTE, "(index)" );

    MAKE_LABEL

    char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );

    cpu_lowercase( _environment, resultAddress, result->realName, resultAddress );

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
    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }
    Variable * result = variable_cast( _environment, string->name, VT_STRING );
    switch( string->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot make a UPPER function on a number");
            break;
        case VT_STRING:
            break;
        case VT_BUFFER:
            CRITICAL("Cannot make a UPPER function on a BUFFER");
    }
    Variable * found = variable_temporary( _environment, VT_BYTE, "(valid alphabetic)" );
    Variable * index = variable_temporary( _environment, VT_BYTE, "(index)" );

    MAKE_LABEL

    char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );

    cpu_uppercase( _environment, resultAddress, result->realName, resultAddress );

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
    Variable * value = variable_find( _environment->tempVariables, _value );
    if ( ! value ) {
        value = variable_find( _environment->variables, _value );
    }
    if ( ! value ) {
        CRITICAL("String variable does not exist");
    }
    Variable * dword = variable_temporary( _environment, VT_DWORD, "(bcd result of STR)" );
    Variable * result = variable_temporary( _environment, VT_STRING, "(result of STR)" );

    switch( value->type ) {
        case VT_DWORD:
            CRITICAL("Cannot convert a DWORD into BCD");
            break;
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            cpu_convert_upto_24bit_bcd( _environment, value->realName, dword->realName, 16 );
            break;
        case VT_BYTE:
        case VT_COLOR:
            cpu_convert_upto_24bit_bcd( _environment, value->realName, dword->realName, 8 );
            break;
        case VT_STRING:
            CRITICAL("Cannot use STR with a STRING value");
            break;
        case VT_BUFFER:
            CRITICAL("Cannot use STR on a BUFFER");
    }

    variable_store_string( _environment, result->name, "      " );

    char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );

    cpu_convert_bcd_to_digits( _environment, dword->realName, resultAddress );

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
    Variable * value = variable_find( _environment->tempVariables, _value );
    if ( ! value ) {
        value = variable_find( _environment->variables, _value );
    }
    if ( ! value ) {
        CRITICAL("String variable does not exist");
    }
    Variable * result = variable_temporary( _environment, VT_WORD, "(result of val)" );

    switch( value->type ) {
        case VT_DWORD:
            CRITICAL("Cannot call VAL on DWORD");
            break;
        case VT_ADDRESS:
            CRITICAL("Cannot call VAL on ADDRESS");
            break;
        case VT_POSITION:
            CRITICAL("Cannot call VAL on POSITION");
            break;
        case VT_WORD:
            CRITICAL("Cannot call VAL on WORD");
            break;
        case VT_BYTE:
            CRITICAL("Cannot call VAL on BYTE");
            break;
        case VT_COLOR:
            CRITICAL("Cannot call VAL on COLOR");
            break;
        case VT_STRING: {
            char valueAddress[16]; sprintf(valueAddress, "%s+1", value->realName );
            cpu_convert_string_into_16bit( _environment, valueAddress, value->realName, result->realName );
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot use VAL on a BUFFER");
            break;
    }

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

    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }

    Variable * repetitions = variable_find( _environment->tempVariables, _repetitions );
    if ( ! repetitions ) {
        repetitions = variable_find( _environment->variables, _repetitions );
    }
    if ( ! repetitions ) {
        CRITICAL("String variable does not exist");
    }

    Variable * result = variable_temporary( _environment, VT_STRING, "(result of STRING)");
    
    Variable * strings_address = variable_retrieve( _environment, "strings_address" );
    
    char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );
    char stringAddress[16]; sprintf(stringAddress, "%s+1", string->realName );

    cpu_move_8bit( _environment, repetitions->realName, result->realName );
    cpu_move_16bit( _environment, strings_address->realName, resultAddress );
    cpu_math_add_16bit_with_8bit( _environment, strings_address->realName, repetitions->realName, strings_address->realName );

    cpu_fill_indirect( _environment, resultAddress, result->realName, stringAddress );

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

    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }

    Variable * result = variable_temporary( _environment, VT_STRING, "(result of STRING)");
    
    Variable * strings_address = variable_retrieve( _environment, "strings_address" );
    
    char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );
    char stringAddress[16]; sprintf(stringAddress, "%s+1", string->realName );

    cpu_move_8bit( _environment, string->realName, result->realName );
    cpu_move_16bit( _environment, strings_address->realName, resultAddress );
    cpu_math_add_16bit_with_8bit( _environment, strings_address->realName, string->realName, strings_address->realName );

    cpu_flip( _environment, stringAddress, result->realName, resultAddress );

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

    Variable * ascii = variable_find( _environment->tempVariables, _ascii );
    if ( ! ascii ) {
        ascii = variable_find( _environment->variables, _ascii );
    }
    if ( ! ascii ) {
        CRITICAL("String variable does not exist");
    }

    Variable * result = variable_temporary( _environment, VT_STRING, "(result of STRING)");
    
    Variable * strings_address = variable_retrieve( _environment, "strings_address" );
    
    char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );

    switch( ascii->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            break;
        case VT_STRING: {
            CRITICAL("Cannot call CHR on STRING");
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot call CHR on a BUFFER");
            break;
    }

    cpu_store_8bit( _environment, result->realName, 1 );
    cpu_move_8bit_indirect( _environment, ascii->realName, resultAddress );
    cpu_math_add_16bit_with_8bit( _environment, strings_address->realName, result->realName, strings_address->realName );

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

    Variable * character = variable_find( _environment->tempVariables, _char );
    if ( ! character ) {
        character = variable_find( _environment->variables, _char );
    }
    if ( ! character ) {
        CRITICAL("String variable does not exist");
    }

    char characterAddress[16]; sprintf(characterAddress, "%s+1", character->realName );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of STRING)");
    
    switch( character->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot call VAL on number");
            break;
        case VT_STRING: {
            cpu_move_8bit_indirect2( _environment, characterAddress, result->realName );
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot call VAL on a BUFFER");
            break;
    }


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

    Variable * string = variable_find( _environment->tempVariables, _string );
    if ( ! string ) {
        string = variable_find( _environment->variables, _string );
    }
    if ( ! string ) {
        CRITICAL("String variable does not exist");
    }

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of LEN)");
    
    switch( string->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot call LEN on number");
            break;
        case VT_STRING: {
            cpu_move_8bit( _environment, string->realName, result->realName );
            break;
        }
        case VT_BUFFER:
            CRITICAL("Cannot call LEN on a BUFFER");
            break;
    }


    return result;
    
}

/**
 * @brief Emit code to raise a variable to a given variable
 * 
 * This function allows you to emit a code that raise a variable
 * to a given variable.
 * 
 * @pre _source and _destination variables must exist
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @return Variable* The result of calculation
 */
Variable * variable_pow( Environment * _environment, char * _source, char * _destination ) {
    Variable * source = variable_find( _environment->tempVariables, _source );
    if ( ! source ) {
        source = variable_find( _environment->variables, _source );
    }
    if ( ! source ) {
        CRITICAL_VARIABLE(_source);
    }
    Variable * target = variable_cast( _environment, _destination, source->type );
    if ( ! target ) {
        CRITICAL_VARIABLE(_destination);
    }
    Variable * result;

    if ( source->type == VT_DWORD || target->type == VT_DWORD ) {
        CRITICAL("Cannot raise a DWORD");
    }

    if ( source->type == VT_STRING || target->type == VT_STRING ) {
        CRITICAL("Cannot raise a STRING");
    }

    if ( source->type == VT_BUFFER || target->type == VT_BUFFER ) {
        CRITICAL("Cannot raise a BUFFER");
    }

    MAKE_LABEL

    char endLabel[16]; sprintf(endLabel, "%send", label);

    Variable * counter = variable_cast( _environment, target->name, VT_BYTE );
    switch( source->type ) {
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
            result = variable_temporary( _environment, VT_DWORD, "(result of pow)");
            variable_store( _environment, result->name, 1 );
            cpu_bveq( _environment, counter->realName, endLabel );
            cpu_label( _environment, label );
            cpu_math_mul_16bit_to_32bit( _environment, source->realName, result->realName, result->realName );
            cpu_dec( _environment, counter->realName );
            cpu_bvneq( _environment, counter->realName, label );
            cpu_label( _environment, endLabel );
            break;
        case VT_BYTE:
        case VT_COLOR:
            result = variable_temporary( _environment, VT_DWORD, "(result of pow)");
            variable_store( _environment, result->name, 1 );
            cpu_bveq( _environment, counter->realName, endLabel );
            cpu_label( _environment, label );
            cpu_math_mul_8bit_to_16bit( _environment, source->realName, result->realName, result->realName );
            cpu_dec( _environment, counter->realName );
            cpu_bvneq( _environment, counter->realName, label );
            cpu_label( _environment, endLabel );
            break;
    }
    return result;
}
