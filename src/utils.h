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
    IDENTIFIER,
    CONST,
    ASSIGN,
    EXP,
    IF,
    FOR
};

/* Enumeration for value types */
enum ValType {
    VOID,
    INT,
    FLOAT,
    CHAR,
    STRING,
    STRUCT
};

enum Operator {
    IN,       /* ++ */
    DE,       /* -- */
    AD,       /* + */
    SU,       /* - */
    MU,       /* * */
    DI,       /* / */
    EQ,       /* == */
    NE,       /* != */
    LT,       /* < */
    LE,       /* <= */
    GT,       /* > */
    GE,       /* >= */
    LA,       /* && */
    LO,       /* || */
    LN        /* ! */
};

/* Generic nodes in the Abstract Syntax Tree */
struct ast {
  enum NodeType nodetype;
  struct ast *l;
  struct ast *r;
};

/* Function Call node */
struct ast_fun {
  enum NodeType nodetype;
  struct symbol identifier;
  struct ast *l;		/* list of arguments */
};

/* Identifier node */
struct symbol {
    enum NodeType nodetype;
    char *name;
    enum ValType type;
    union {
        int ival;
        float fval;
        char cval;
        char *sval;
    };
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

/* Expression node */
struct ast_exp {
    enum NodeType nodetype;
    enum Operator op;
    struct ast *left;
    struct ast *right;
};

/* Assignment node */
struct ast_assign {
    enum NodeType nodetype;
    struct symbol identifier;
    struct ast *value;
};

/* I/O node */
struct ast_io {
    enum NodeType nodetype;
    int print;
};
