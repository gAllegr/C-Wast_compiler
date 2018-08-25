# Compiler project for FLC exam

Aim of this project is to implement a front-end compiler which transform a C source file into a text file (.wast) written using s-expressions.

## Software requirements
### Flex
* Generate lexical analyzer
* To install on Ubuntu use:<br>
`sudo apt-get install flex`

### Bison
* Generate syntax analyzer
* To install on Ubuntu use:<br>
`sudo apt-get install bison`

### Xdot
* Generate an image of the compiler graph
* To install on Ubuntu use:<br>
`sudo apt install xdot`

## Lexicon and Syntax Rules
### S/S and S/R Conflicts
This compiler has only 1 shift/reduce conflict, related to [dangling else](https://en.wikipedia.org/wiki/Dangling_else) problem.

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

*An example of not allowed syntax can be found at* `test/not_working/improper_program.c` 

### Variable declarations
* Variables can be defined both globally and locally within the program
* Variables can be declared only at the beginning of the program (for global variables) or at the beginning of the functions (for local variables)<br><br>
* Accept simple declaration `int var;`
* Accept multiple declaration on single line `int a, b;`
* Accept declaration with inizialitazion<br><br>
* Variables can be inizialited by using a constant or a mathematical expression `char var = "a";` `int var = 3+2;`
* Array can be declared only with size specification<br>
  * Allowed: `int a[2] = {3,5};`<br>
  * Not allowed: `int a[] = {3,5};`
* Char array (string) can be declared as `char s[6]={"H","e","l","l","o"};` or as `char s[6]="Hello";`<br><br>
* Struct can be created as a list of variable declarations without inizialization
* After defining a struct, a variable can be declared in two possible way:
  * as an usual declaration`struct struct_identifier identifier;`
  * at the end of a struct definition `struct struct_name {...} var1, var2;`
* Structure members can be inizialized only in listing order<br>
  * Assuming the following structure is defined<br>
  `struct Point
{
   int x;
   int y;
};`<br>
  Allowed: `struct Point punto = {1,5};`<br>
  Not allowed: `struct Point punto = {.y=1,.x=5};`<br>

*An example of allowed declaration can be found at* `test/declaration_tests` <br>
*An example of not allowed declaration can be found at* `test/not_working/struct.c` 

### Function declarations
* Functions can return only *void* or *struct* or basic types
* Support void parameters<br>
Examples: `int main ()` or `void main (void)`
* A single or more parameters can be passed by values 
* During function definition, parameters can be specified by *type identifier*
* Support struct parameters
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

*Examples of allowed syntax can be found in folder* `test/if_tests`<br>

### Iteration statement (for)
* Inizialization parameter can be empty or a comma-separated list of variables
* Loop condition must be present but can't use comma `,` to separate conditions. On the other hand, more conditions can be bounded with logical operators.
* Increment statement cannot be empty, because we had a shift/reduce conflict that we can't understand how to solve.

### Conditions for branching and iteration statements
* Conditions can use all comparison and logical operators listed above
* Support nested conditions<br>
` !(mix of conditions)`<br> 
`(mix of conditions) && (mix of conditions)`<br>
`(mix of conditions) || (mix of conditions)`

*Examples of allowed syntax can be found in folder* `test/condition_tests` 

### Return statement
* Support for void functions `return;`
* Support for int, float and char functions `return 0;`
* Support returning of variables

## Syntax Tree
**Next step!!!**

## Symbol Table
**Next next step!!!**<br>
Related files in `src` folder are a first shy try :)

## Code generator
**Will we get there???**