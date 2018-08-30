/* ===== Interface with lexer ===== */

int lineno;                                     /* variable counting lines */
void yyerror(const char *);                     /* prints grammar violation message */

/* ===== Parser functions ===== */

char* concat(int n_token, char *token,...);     /* concat tokens of a rule */

/* ===== Syntax Tree ===== */

/* Enumeration for node types */
enum NodeType {
    GENERIC,
    FUNCTION,
    IF,
    FOR,
    CONST,
    CMP
};

/* Enumeration for value types */
enum ValType {
    VOID,
    INT,
    FLOAT,
    CHAR,
    STRING
};

enum Cmp_Op {
    EQ,
    NE,
    LT,
    LE,
    GT,
    GE
};

/* Generic nodes in the Abstract Syntax Tree */
struct ast {
  enum NodeType nodetype;
  struct ast *l;
  struct ast *r;
};

/* Function node */
struct ast_fun {
  enum NodeType nodetype;
  struct ast *l;		/* list of arguments */
  char *name;
};

/* IF statement node */
struct ast_if {
  enum NodeType nodetype;
  struct ast *cond;		/* condition */
  struct ast *tl;		/* then-branch */
  struct ast *el;		/* optional else-branch */
};

/* FOR statement node */
struct ast_for {
    enum NodeType nodetype;
    struct ast *init;   /* inizialization */
    struct ast *cond;   /* condition */
    struct ast *incr;   /* increment */
    struct ast *loop;   /* loop statements */
};

/* Constant node */
struct ast_const {
  enum NodeType nodetype;
    enum ValType type;
    union {
        int ival;
        float fval;
        char cval;
        char *sval;
    };
};

/* Comparison node */
struct ast_cmp {
    enum NodeType nodetype;
    enum Cmp_Op cmp_op;
    struct ast *left;
    struct ast *right;
};

