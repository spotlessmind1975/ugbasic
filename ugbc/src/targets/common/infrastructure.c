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
        var->next = _environment->variables; 
        var->type = _type;
        var->value = _value;
        var->bank = _environment->banks[BT_VARIABLES];
        _environment->variables = var;
        variable_store( _environment, var->name, _value );
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
        var->next = _environment->tempVariables; 
        var->type = _type;
        var->bank = _environment->banks[BT_TEMPORARY];
        _environment->tempVariables = var;
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
        CRITICAL("Cannot find source var");
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
                case VT_STRING:
                    // TODO 
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
            CRITICAL( "Destination variable does not exists" );
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
            CRITICAL("Cannot store a direct value on STRING");;
            break;
    }
    return destination;
}

Variable * variable_store_string( Environment * _environment, char * _destination, char * _value ) {
    Variable * destination = variable_find( _environment->tempVariables, _destination );
    if ( ! destination ) {
        destination = variable_find( _environment->variables, _destination );
        if ( ! destination ) {
            CRITICAL( "Destination variable does not exists" );
        }
    }
    switch( destination->type ) {
        case VT_DWORD:
        case VT_ADDRESS:
        case VT_POSITION:
        case VT_WORD:
        case VT_BYTE:
        case VT_COLOR:
            CRITICAL("Cannot store a STRING on a numeric value");;
            break;
        case VT_STRING: {
            char destinationAddress[16]; sprintf(destinationAddress, "%s+1", destination->realName );
            destination->valueString = strdup( _value );
            cpu_store_8bit( _environment, destination->realName, strlen( _value ) );
            cpu_store_16bit( _environment, destinationAddress, _environment->valueStringOffset );
            _environment->valueStringOffset += strlen( _value );
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
            CRITICAL( "Source variable does not exist" );
        }
    }
    Variable * target = variable_find( _environment->tempVariables, _destination );
    if ( ! target ) {
        target = variable_find( _environment->variables, _destination );
        if ( ! target ) {
            CRITICAL( "Destination variable does not exist" );
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
        CRITICAL("Source variable does not exist");
    }
    Variable * target = variable_cast( _environment, _destination, source->type );
    if ( ! target ) {
        CRITICAL("Destination variable does not cast");
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
        case VT_STRING: {
            char sourceAddress[16]; sprintf(sourceAddress, "%s+1", source->realName );
            char destinationAddress[16]; sprintf(destinationAddress, "%s+1", target->realName );
            char resultAddress[16]; sprintf(resultAddress, "%s+1", result->realName );
            cpu6502_math_add_8bit( _environment, sourceAddress, destinationAddress, resultAddress );
            cpu_mem_move( _environment, sourceAddress, resultAddress, source->realName );
            cpu_mem_move_displacement( _environment, sourceAddress, resultAddress, source->realName, target->realName );
            break;
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
            CRITICAL("Cannot calculate multiplication of DWORD variables");
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
                    cpu_compare_32bit( _environment, source->realName, target->realName, result->realName, 0 );
                    break;
                case VT_ADDRESS:
                case VT_POSITION:
                case VT_WORD:
                    cpu_compare_16bit( _environment, source->realName, target->realName, result->realName, 0 );
                    break;
                case VT_BYTE:
                case VT_COLOR:
                    cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 0 );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot compare DWORD with STRING");
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
                    cpu_compare_16bit( _environment, source->realName, target->realName, result->realName, 0 );
                    break;
                case VT_BYTE:
                case VT_COLOR:
                    cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 0 );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot compare ADDRESS/POSITION/WORD with STRING");
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
                    cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 0 );
                    break;
                case VT_STRING:
                    CRITICAL("Cannot compare BYTE/COLOR with STRING");
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
                    cpu_compare_8bit( _environment, source->realName, target->realName, result->realName, 0 );
                    cpu_bveq( _environment, result->realName, label );
                    cpu_compare_memory( _environment, sourceAddress, destinationAddress, source->realName, result->realName, 0 );
                    cpu_label( _environment, label );
                    break;
                }
            }
            break;
    }
    return result;
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
    }
    return result;
}
