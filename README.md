# Compiler project for FLC exam (C - Wat)
Aim of this project is to implement a compiler which transform a C source file into a text file (.wat), written using s-expressions.<br>
Compiler will produce a set of files:
* .wat -> textual version of WebAssembly code
* .wasm -> binary version of WebAssembly code
* .html -> html page to show result
* .css -> small style file
* .js -> javascript to instantiate a WebAssembly module

## Building Instruction
### Software requirements
This compiler need the following tools: Flex, Bison, Xdot (optional), WABT.<br>
Here is how to install them<br>

    // Install Flex (mandatory)
    sudo apt-get install flex
    // Install Bison (mandatory)
    sudo apt-get install bison
    // Install Xdot (optional)
    sudo apt install xdot
    // Install WABT (mandatory)
    git clone --recursive https://github.com/WebAssembly/wabt
    cd wabt
    make

### Installation process

    // clone project
    git clone https://github.com/gAllegr/C-Wat_compiler.git
    cd C-Wat_compiler
    // create compiler, will be saved into bin folder as compiler.out
    make

### Commands available
#### Run compiler
Run compiler using command `make run`, it will ask a C source file as input.<br>
Output files will be saved into output_code folder.
<br>
Example:

    $ make run
    Enter C source code:
    ./example_programs/correct1.c

#### Clean output files
All previous compiled files could be easily removed by running `make clean`. It will delete immediately all files inside output_code folder.

#### Load output files to local server
Compiled files can be copied to local server folder by running `make load`. This command will require root privilege!

#### Create a compiler image
If you have installed Xdot, an image with all states generated by compiler can be created by running `make image`. Image will be saved into project main folder.

## Lexicon and Syntax Rules
### Types allowed
* Integer values
* Float values
* Character values
* Array
* Struct
  * Typedef keyword to name structures is not supported
  * Accessing members of a structure is possible by using dotted notation
  * Accessing members by using structure pointer operator `->` is not supported

### Operators
#### Comparison operators
Are accepted only comparison between numbers
* Equal `==`
* Not equal `!=`
* Less then `<`
* Greater then `>`
* Less or equal then `<=`
* Greater or equal then `>=`

#### Logical operators
* And `&&`
* Or `||`
* Not `!`

#### Mathematical operators
* All four usual mathematical operators `+` `-` `*` `/`
* Reverse operation `-a`
* Postfix increment and decrement operators `++` `--`

### Comments
* Ignore single line comments
* Ignore multi line comments

### Headers
* Ignore headers

### Global C program
C is a procedural language, so the main structure of a program is composed only of variable and function declarations.
* Accept variable declarations
* Accept function declarations
* Variable declarations **must be written before** function declarations
* Do not accept statements outside functions scope

*An example of not allowed syntax can be found at* `syntax_test/not_working/improper_program.c` 

### Variable declarations
* Variables can be defined both globally and locally within the program
* Variables can be declared only at the beginning of the program (for global variables) or at the beginning of the functions (for local variables)<br><br>
* Accept simple declaration `int var;`
* Accept multiple declaration on single line `int a, b;`
* Accept declaration with initialitazion<br><br>
* Variables can be initialited by using a constant or a mathematical expression `char var = "a";` `int var = 3+2;`
* Array can be declared only with size specification<br>
  * Allowed: `int a[2] = {3,5};`<br>
  * Not allowed: `int a[] = {3,5};`
* Char array (string) can be declared as `char s[6]={"H","e","l","l","o"};` or as `char s[6]="Hello";`<br>
* If array dimension is specified by a variable, further checks cannot be made (e.g. during initialization)<br><br>
* Struct can be created as a list of variable declarations without initialization
* After defining a struct, a variable can be declared in two possible way:
  * as an usual declaration`struct struct_identifier identifier;`
  * at the end of a struct definition `struct struct_name {...} var1, var2;`
* Structure members can be initialized only in listing order<br>
  * Assuming the following structure is defined<br>
  `struct Point
{
   int x;
   int y;
};`<br>
  Allowed: `struct Point punto = {1,5};`<br>
  Not allowed: `struct Point punto = {.y=1,.x=5};`<br>

*An example of allowed declaration can be found at* `syntax_test/declaration_tests` <br>
*An example of not allowed declaration can be found at* `syntax_test/not_working/struct.c` 

### Function declarations
* Functions can return only *void* or basic types
* Support void parameters<br>
Examples: `int main ()` or `void main (void)`
* A single or more parameters can be passed by values 
* During function definition, parameters can be specified by *type identifier*
* Do not support struct parameters
* Do not support parameters passed by reference
* This compilers does not consider the possibility to define a function prototype. So something like `int sum (int, int);` is not to be considered as an optional way to define functions

### Statements allowed
* Variable declaration (with or without assignment)
* Method call
* Assignment
* Mathematical expression
* Output statement `printf`
* Input statement `scanf`
* Branching statement `if`
* Iteration statement `for`
* Return statement

### Ouput statement (printf)
* A simple string can be printed out `printf("Hello world!\n");`
* One or more variable at a time can be printed out

### Input statement (scanf)
* One or more variable at a time can be retrieved

### Branching statement (if)
* Support both IF and IF-ELSE statements
* Support nested IFs
* Then-branch and Else-branch can have a single instruction or a block/sequence of instructions
* The S/R conflict of the [dangling else](https://en.wikipedia.org/wiki/Dangling_else) has been solved with the shift action. The else-branch is attached to the nearby if-statement, as C language's convention.


*Examples of allowed syntax can be found in folder* `syntax_test/if_tests`<br>

### Iteration statement (for)
* Initialization parameter cannot be empty. Can be a single variable or a comma-separated list of variables
* Loop condition must be present but can't use comma `,` to separate conditions. On the other hand, more conditions can be bounded with logical operators.
* Increment statement cannot be empty

### Conditions for branching and iteration statements
* Conditions can use all comparison and logical operators listed above
* Support nested conditions<br>
` !(mix of conditions)`<br> 
`(mix of conditions) && (mix of conditions)`<br>
`(mix of conditions) || (mix of conditions)`

*Examples of allowed syntax can be found in folder* `syntax_test/condition_tests` 

### Return statement
* Support for void functions `return;`
* Support for int, float and char functions `return 0;`
* Support returning of variables

## Syntax Tree
We decided to build and use an Abstract Syntax Tree.<br>
We build a particular node of AST for almost all non-terminals.<br>
AST is built during the parsing phase and, after that, it's printed out! <br>
Before exiting, the memory is released.

_Example code_

    int sum(int a, int b) {
      int s = a + b;
      return s;
    }

    int main ()
    {
      int c = 1, d = 2, somma;
      somma = sum(c,d);

      return 0;
    }

_Printed Tree_

    Program GLOBAL DECLARATIONS
    Program FUNCTIONS
        Function Definition NAME
            VARIABLE (INT type) sum
        Function Definition PARAMETERS
            List
                VARIABLE (INT type) a
                VARIABLE (INT type) b
        Function Definition BODY
            Function Body DECLARATIONS
                Assignment VARIABLE
                    VARIABLE (INT type) s
                Assignment EXPRESSION
                    BinaryExpr (Addition) LEFT
                        VARIABLE (INT type) a
                    BinaryExpr (Addition) RIGHT
                        VARIABLE (INT type) b
            Function Body STATEMENTS
                Return_Statement
                    VARIABLE (INT type) s
        Function Definition NAME
            VARIABLE (INT type) main
        Function Definition PARAMETERS

        Function Definition BODY
            Function Body DECLARATIONS
                Assignment VARIABLE
                    VARIABLE (INT type) c
                Assignment EXPRESSION
                    INT_CONSTANT 1
                Assignment VARIABLE
                    VARIABLE (INT type) d
                Assignment EXPRESSION
                    INT_CONSTANT 2
                VARIABLE (INT type) somma
            Function Body STATEMENTS
                Assignment VARIABLE
                    VARIABLE (INT type) somma
                Assignment EXPRESSION
                    Function Call NAME
                        VARIABLE (INT type) sum
                    Function Call ARGUMENTS
                        VARIABLE (INT type) c
                        VARIABLE (INT type) d
                Return_Statement
                    INT_CONSTANT 0

## Symbol Table
An hierarchical symbol table has been implemented.<br><br>
For each variable, the following information are saved:
* name
* dimension
* type
* struct composition (only for struct variables)
* if variable has been initialized
<br><br>

For each function, the following information are saved:
* name
* return type
* list of parameters
* list of local variables

_Example code_

    struct Point
    {
    int x;
    int y;
    } punto1 = {1,5}, punto2, punto3[2] = {{1,2},{3,4}};
    
    int main ()
    {
        struct Line
        {
            int a;
            int b;
        } line1, line2;

        punto2.x = 10;
        punto2.y = 20;

        punto1.x = punto1.y * 2;

        return 0;
    }

_Symbol Table generated_

    GLOBAL SYMBOL TABLE
    Name            Kind            Type            Dimension
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    punto1          VAR             STRUCT Point    /
    punto2          VAR             STRUCT Point    /
    punto3          VAR             STRUCT Point    2
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    STRUCT Point
    x               VAR             INT             /
    y               VAR             INT             /
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    main            FUN             INT             /



    MAIN SYMBOL TABLE
    Name            Kind            Type            Dimension
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    line1           VAR             STRUCT Line     /
    line2           VAR             STRUCT Line     /
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    STRUCT Line
    a               VAR             INT             /
    b               VAR             INT             /
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### Issue
This symbol table, however, has one problem.<br>
If a variable is declared before of a struct and this variable has the same name of a variable inside the following struct, the program will generate a _segmentation fault_.<br>
At the beginning, struct element variables are saved as global or local variables and only after, they are removed 
and stored as struct elements inside symbol table. That cause the segmentation error, because our code will delete the first variable with specified name found.<br>
A possible limitation to this problem could be the following.

_What there is now in grammar.y_<br>
`declarations: declaration | declarations declaration ;`

_With what could be replaced_<br>
`declarations: struct_declarations var_declarations`<br>
`struct_declarations: struct_declarations struct_declaration`<br>
`var_declarations: var_declarations var_declaration`

This will limit the issue, but will not fully solve it. Declaration of two different struct with same variable name will generate anyway the segmentation fault.

## Semantic checks
### Declarations
* variables cannot have void type
* array variable dimension must be constant
* struct elements cannot be initialized
* check on variable redeclaration
* check on initialization of variables (variables can be initialized only with constants)
### Function definition - Parameters
* parameters cannot have void type
### Function call
* check if a function has been defined
* check if arguments are in the same number of parameters
* check if arguments and parameters have same type
### Assignment statement
* check if assignment variable and expression have the same type
* if variable on the left of assignment is a struct variable, checks only if it has been declared
* do not make any check if variable on the left is an array variable of struct
### Expression
* check that all types are compatible among them
### I/O statements
* no checks on string content passed to printf and scanf (number and types)
* on both I/O function, check if variables passed have been declared
* for scanf function, also set variables as initialized
### Return statement
* verify that variable returned is a simple variable
* if function returns void type, compiler gives warning message if there are valorized returns
* if function returns something, compiler gives warning message if there are no return statements
* if function returns something, compiler gives warning message if return statement type mismatches
### Variable used as array index
* check if has been previously declared and initialized
* check if it's an integer variable
* check that it's a simple variable

## Code generator
Code convertion is based on Abstract Syntax Tree and Symbol Table, allowing a one-to-one convertion.<br>
Final code is obtained through a sequence of string concatenation and is saved as .wat file.<br>
Then the .wat file is converted in a .wasm file, using the WABT's `wat2wasm` command.<br>
Finally, compiler also generate html, css and javascript files needed to run WebAssembly code. In particular, javascript file creation is based on values of some flags, which enable import of memory and functions to WebAssembly module.<br><br>
*Full code for html, css and javascript can be found in `doc/Site_Page` folder*

### Issues
WebAssembly is a Minimum Viable Product (MVP), so some features are missing. Also, textual representation of WebAssembly code (.wat) seems to be very basic.<br>
Main issues found are listed below:<br>
* types allowed are limited (i32, i64, f32, f64)
* logical operators are not defined for float
* no direct support for strings and arrays
* no direct support for struct objects
* limited nondeterminism
* a single module can use at most 1 memory instance

At the beginning, Emscripten has been taken has reference to create textual representation, but it generates very big files (also with more than 10'000 code lines). Also, seems that Emscripten convert also used C libraries.<br>
For the implementation of this compiler, [MDN WebAssembly documentation](https://developer.mozilla.org/en-US/docs/WebAssembly) has been considered.

#### Array and Struct
So, to use more complex object like arrays and struct a memory management is strictly required. This compiler works fine with strings, which are saved in a memory instance sequentially.<br>
On the other hand, arrays and structs have not been considered at all. Arrays should be created outside WebAssembly code (so, in Javascript) and passed through a memory instance with their length. This would increase the difficult of memory management.<br>
*[Analog issue opened in WebAssembly Github repository](https://github.com/WebAssembly/design/issues/1099)*

#### Scanf conversion
There is no direct conversion of scanf instruction, due to limited nondeterminism. Web Assembly currently has no support for direct DOM and Browser API access and has to rely on JavaScript interop to update the DOM.<br>
So, inputs must be asked in Javascript code and then passed to WebAssembly module as imported global mutable variable.
This compiler, however, can't generate equivalent code for imported variables<br>
`(global $v (import "js" "value") (mut i32))`

#### Printf conversion
Also printf instruction cannot be directly converted in textual WebAssembly code. There is a simple workaround, implemented in this compiler, that allows printing out integer, float, char and string, both variables and constants, on the html page.<br>
Unfortunately, also this case has a limitation. An instruction like the following<br>
`printf("Value of v is %d", v);`<br>
would print to html page only variable's value. Assuming v is equal to 5, the html page will show `5`.

## References
[Bison Manual](https://www.gnu.org/software/bison/manual/html_node/)<br>
[Book: Flex and Bison - John Levine](http://web.iitd.ac.in/~sumeet/flex__bison.pdf)<br>
[C operator precedence](https://en.cppreference.com/w/c/language/operator_precedence)<br>
[WebAssembly Semantics](https://webassembly.org/docs/semantics/)<br>
[WebAssembly - Text format specification](https://webassembly.github.io/spec/core/text/)<br>
[WebAssembly - Future features](https://webassembly.org/docs/future-features/)<br>
[MDN - Understanding the text format](https://developer.mozilla.org/en-US/docs/WebAssembly/Understanding_the_text_format)<br>
[MDN - Using the JavaScript API](https://developer.mozilla.org/en-US/docs/WebAssembly/Using_the_JavaScript_API)<br>
[MDN - Array example (html+js)](https://github.com/mdn/webassembly-examples/blob/master/js-api-examples/memory.html) - [MDN - Array example (wat)](https://github.com/mdn/webassembly-examples/blob/master/js-api-examples/memory.wat)