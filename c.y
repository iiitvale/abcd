%{
    #include <stdio.h>
    #include <stdlib.h>
    int yywrap();
    int yyparse();
    void yyerror();
    int yylex();
%}

%union {
    float num;
}


%token <num> NUMBER
%type <num> E
%type <num> T
%type <num> F
%type <num> P
%token '+' '-'
%token '*' '/'
%token '(' ')'
/* %nonassoc UMINUS */

%%

calc: E { printf("THE RESULT IS : %.4f\n", $1); };

E       : E '+' T { $$ = $1 + $3; printf("ACTION: %.4f + %.4f = %.4f\n", $1, $3, $$); }
        | E '-' T { $$ = $1 - $3; printf("ACTION: %.4f - %.4f = %.4f\n", $1, $3, $$); }
        | T {$$ = $1;};

T       : T '*' P { $$ = $1 * $3; printf("ACTION: %.4f * %.4f = %.4f\n", $1, $3, $$); }
        | P {$$ = $1;};

P       : P '/' F { $$ = $1 / $3; printf("ACTION: %.4f / %.4f = %.4f\n", $1, $3, $$); }
        | F {$$ = $1;};

F       : NUMBER { $$ = $1; printf("ACTION: %.4f\n", $$);}
        | '(' E ')' {$$ = $2; printf("ACTION : ( %.4f )\n",$$);};


%%

int main(){
    yyparse();
    return 0;
}

void yyerror(char const *s) {
    printf("ERROR DETECTED :  ","%s\n",s);
}

int yywrap(){
    return 1;
}

/*

calc: E { printf("THE RESULT IS : %d\n", $1); };

E       : E '+' T { $$ = $1 + $3; printf("ACTION: %d + %d = %d\n", $1, $3, $$); }
        | E '-' T { $$ = $1 - $3; printf("ACTION: %d - %d = %d\n", $1, $3, $$); }
        | T {$$ = $1;};

T       : T '*' P { $$ = $1 * $3; printf("ACTION: %d * %d = %d\n", $1, $3, $$); }
        | P {$$ = $1;};

P       : P '/' F { $$ = $1 / $3; printf("ACTION: %d / %d = %d\n", $1, $3, $$); }
        | F {$$ = $1;};

F       : NUMBER { $$ = $1; printf("ACTION: %d\n", $$);};



calc: expr { printf("Result: %d\n", $1); };

expr    : expr '+' expr { $$ = $1 + $3; printf("Stack: %d + %d = %d\n", $1, $3, $$); }
        | expr '-' expr { $$ = $1 - $3; printf("Stack: %d - %d = %d\n", $1, $3, $$); }
        | expr '*' expr { $$ = $1 * $3; printf("Stack: %d * %d = %d\n", $1, $3, $$); }
        | expr '/' expr { $$ = $1 / $3; printf("Stack: %d / %d = %d\n", $1, $3, $$); }
        | '-' expr %prec UMINUS { $$ = -$2; printf("Stack: -%d = %d\n", $2, $$); }
        | '(' expr ')' { $$ = $2; }
        | NUMBER { $$ = $1; printf("Stack: %d\n", $$); }
;


*/

