#include "list.h"

#ifndef WAT_H
#define WAT_H

FILE *fp;

/* Imports, to be written depending on flags */
char *imports[3] = {
    "(import \"console\" \"log\" (func $log (param i32)))",
    "(import \"console\" \"str_log\" (func $str_log (param i32) (param i32)))",
    "(import \"js\" \"mem\" (memory 1))"
};
int import_flag[3] = {0,0,0};

/* List of data in memory */
List *data;

/* Functions */
char *function;
/* Variables */
char *glob_var;
char *local_var;
char *init;         // inizialization for local variables
char *instr;

#endif