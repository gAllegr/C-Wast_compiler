/* ===== Interface with lexer ===== */

int lineno;                                     /* variable counting lines */
void yyerror(const char *);                     /* prints grammar violation message */

/* ===== Parser functions ===== */

char* concat(int n_token, char *token,...);     /* concat tokens of a rule */

