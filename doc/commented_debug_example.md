# Parsing
Starting parse
Entering state 0
## Trova float e lo risolve come var_type
  Reading a token: Next token is token FLOAT ()
  Shifting token FLOAT ()
  Entering state 3
  Reducing stack by rule 9 (line 74):
     $1 = token FLOAT ()
  -> $$ = nterm var_type ()
  Stack now 0
## Trova anche b; (var_type ID SEMICOLON) e lo risolve come declaration 
  Entering state 8
  Reading a token: Next token is token ID ()
  Shifting token ID ()
  Entering state 15
  Reading a token: Next token is token SEMICOLON ()
  Shifting token SEMICOLON ()
  Entering state 20
  Reducing stack by rule 6 (line 68):
     $1 = nterm var_type ()
     $2 = token ID ()
     $3 = token SEMICOLON ()
  -> $$ = nterm declaration ()
  Stack now 0
## declaration è risolta come glob_decl
  Entering state 7
  Reducing stack by rule 3 (line 61):
     $1 = nterm declaration ()
  -> $$ = nterm glob_decl ()
  Stack now 0
## Trova int e lo risolve come var_type
  Entering state 6
  Reading a token: Next token is token INT ()
  Shifting token INT ()
  Entering state 2
  Reducing stack by rule 8 (line 73):
     $1 = token INT ()
  -> $$ = nterm var_type ()         *nterm = glob_decl*
  Stack now 0 6
## Trova anche main(VOID){
  Entering state 8
  Reading a token: Next token is token ID ()
  Shifting token ID ()
  Entering state 15
  Reading a token: Next token is token O_ROUND_BRACES ()
  Shifting token O_ROUND_BRACES ()
  Entering state 19
  Reading a token: Next token is token VOID ()
  Shifting token VOID ()
  Entering state 26
  Reading a token: Next token is token C_ROUND_BRACES ()
  Shifting token C_ROUND_BRACES ()
  Entering state 34
  Reading a token: Next token is token O_CURLY_BRACES ()
  Shifting token O_CURLY_BRACES ()
## Riduce "int main(VOID){" come nterm e inizia a risolvere statements
  Entering state 39
  Reducing stack by rule 20 (line 97):
  -> $$ = nterm statements ()
  Stack now 0 6 8 15 19 26 34 39
## Trova int e lo riduce come var_type
  Entering state 55
  Reading a token: Next token is token INT ()
  Shifting token INT ()
  Entering state 2
  Reducing stack by rule 8 (line 73):
     $1 = token INT ()
  -> $$ = nterm var_type ()
  Stack now 0 6 8 15 19 26 34 39 55
## Trova anche sum=5+3; e riduce tutto come add_stat
  Entering state 46
  Reading a token: Next token is token ID ()
  Shifting token ID ()
  Entering state 61
  Reading a token: Next token is token ASSIGN ()
  Shifting token ASSIGN ()
  Entering state 74
  Reading a token: Next token is token ICONST ()
  Shifting token ICONST ()
  Entering state 85
  Reading a token: Next token is token ADD ()
  Shifting token ADD ()
  Entering state 97
  Reading a token: Next token is token ICONST ()
  Shifting token ICONST ()
  Entering state 106
  Reading a token: Next token is token SEMICOLON ()
  Shifting token SEMICOLON ()
  Entering state 113
  Reducing stack by rule 28 (line 110):
     $1 = nterm var_type ()
     $2 = token ID ()
     $3 = token ASSIGN ()
     $4 = token ICONST ()
     $5 = token ADD ()
     $6 = token ICONST ()
     $7 = token SEMICOLON ()
  -> $$ = nterm add_stat ()       *Il tutto è ridotto a n_term (glob_decl int main (void){) e add_stat*
  Stack now 0 6 8 15 19 26 34 39 55
## add_stat è ridotto come statement
  Entering state 48
  Reducing stack by rule 27 (line 107):
     $1 = nterm add_stat ()
  -> $$ = nterm statement ()
  Stack now 0 6 8 15 19 26 34 39 55
## Tornano nello stato 55, statement è risolto nello stato 47 come statements
### nterm *(glob_decl int main (void){)*
### statements include anche *(int sum=5+3;)*
  Entering state 47
  Reducing stack by rule 21 (line 98):
     $1 = nterm statements ()
     $2 = nterm statement ()
  -> $$ = nterm statements ()
  Stack now 0 6 8 15 19 26 34 39
## Stessa risoluzione appena vista, per il codice int diff = 4-2;
  Entering state 55
  Reading a token: Next token is token INT ()
  Shifting token INT ()
  Entering state 2
  Reducing stack by rule 8 (line 73):
     $1 = token INT ()
  -> $$ = nterm var_type ()
  Stack now 0 6 8 15 19 26 34 39 55
  Entering state 46
  Reading a token: Next token is token ID ()
  Shifting token ID ()
  Entering state 61
  Reading a token: Next token is token ASSIGN ()
  Shifting token ASSIGN ()
  Entering state 74
  Reading a token: Next token is token ICONST ()
  Shifting token ICONST ()
  Entering state 85
  Reading a token: Next token is token ADD ()
  Shifting token ADD ()
  Entering state 97
  Reading a token: Next token is token ICONST ()
  Shifting token ICONST ()
  Entering state 106
  Reading a token: Next token is token SEMICOLON ()
  Shifting token SEMICOLON ()
  Entering state 113
  Reducing stack by rule 28 (line 110):
     $1 = nterm var_type ()
     $2 = token ID ()
     $3 = token ASSIGN ()
     $4 = token ICONST ()
     $5 = token ADD ()
     $6 = token ICONST ()
     $7 = token SEMICOLON ()
  -> $$ = nterm add_stat ()
  Stack now 0 6 8 15 19 26 34 39 55
## add_stat è ridotto di nuovo come statement
  Entering state 48
  Reducing stack by rule 27 (line 107):
     $1 = nterm add_stat ()
  -> $$ = nterm statement ()
  Stack now 0 6 8 15 19 26 34 39 55
## Torna allo stato 55 ed entra nello stat 47 che riduce a statements
### nterm *(glob_decl int main (void){)*
### statements include anche *(int sum=5+3; int diff=4-2;)*
  Entering state 47
  Reducing stack by rule 21 (line 98):
     $1 = nterm statements ()
     $2 = nterm statement ()
  -> $$ = nterm statements ()
  Stack now 0 6 8 15 19 26 34 39
## Trova in sequenza return,0, semicolon ed entra nei rispettivi stati dopo uno shift
  Entering state 55
  Reading a token: Next token is token RETURN ()
  Shifting token RETURN ()
  Entering state 44
  Reading a token: Next token is token ICONST ()
  Shifting token ICONST ()
  Entering state 60
  Reading a token: Next token is token SEMICOLON ()
  Shifting token SEMICOLON ()
## return 0; è risolto come return_stat
  Entering state 73
  Reducing stack by rule 48 (line 158):
     $1 = token RETURN ()
     $2 = token ICONST ()
     $3 = token SEMICOLON ()
  -> $$ = nterm return_stat ()
  Stack now 0 6 8 15 19 26 34 39 55
## return_stat è ridotto come statement
    Entering state 52
    Reducing stack by rule 26 (line 106):
       $1 = nterm return_stat ()
    -> $$ = nterm statement ()
    Stack now 0 6 8 15 19 26 34 39 55
## statement è a sua volta ridotto come statements
### nterm *(glob_decl int main (void){)*
### statements include anche *(int sum=5+3; int diff=4-2; return 0;)*
  Entering state 47
  Reducing stack by rule 21 (line 98):
     $1 = nterm statements ()
     $2 = nterm statement ()
  -> $$ = nterm statements ()
  Stack now 0 6 8 15 19 26 34 39
## Dopo aver risolto gli statements torna nello stato 55 e trova }
  Entering state 55
  Reading a token: Next token is token C_CURLY_BRACES ()
  Shifting token C_CURLY_BRACES ()
## Dopo lo shift riconosce function e riduce
  Entering state 63
  Reducing stack by rule 19 (line 93):
     $1 = nterm var_type ()           *nterm=glob_decl var_type=int*
     $2 = token ID ()                 *main*
     $3 = token O_ROUND_BRACES ()     *(*
     $4 = token VOID ()               *void*
     $5 = token C_ROUND_BRACES ()     *)*
     $6 = token O_CURLY_BRACES ()     *{*
     $7 = nterm statements ()         *int sum=5+3; int diff=4-2; return 0;*
     $8 = token C_CURLY_BRACES ()     *}*
  -> $$ = nterm function ()           *glob_decl function*
  Stack now 0 6
## function è ridotto come functions
  Entering state 10
  Reducing stack by rule 14 (line 84):
     $1 = nterm function ()
  -> $$ = nterm functions ()  *nterm=glob_decl ; functions="int main(void) {[...]}"*
  Stack now 0 6
## Trova la fine del file e riduce come stream
  Entering state 14
  Reading a token: Now at end of input.
  Reducing stack by rule 2 (line 57):
     $1 = nterm glob_decl ()
     $2 = nterm functions ()
  -> $$ = nterm stream ()
  Stack now 0
## Trova e shifta l'EOF
  Entering state 5
  Now at end of input.
  Shifting token $end ()
## Restituisce i token trovati
  Entering state 12
  Stack now 0 5 12
  Cleanup: popping token $end ()
  Cleanup: popping nterm stream ()

# Output
float b;

int main (void)
{
    int sum = 5 + 3;

    int diff = 4 - 2;
 
    return 0;
}
 int main (void)
{
    int sum = 5 + 3;

    int diff = 4 - 2;
 
    return 0;
}

Correct syntax!
