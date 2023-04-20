%{
    #include "y.tab.h"
%}

%%

[ \t\n]         /* ignore whitespace */
[0-9]+         { yylval.num = (float)atoi(yytext); return NUMBER; }
"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"("             { return '('; }
")"             { return ')'; }
.               { printf("INVALID CHARACTER ENTERED : %s\n", yytext); }

%%
// flex c.l
// yacc -d -v c.y if error in yacc then bison
// gcc lex.yy.c y.tab.c
// ./a.out
// ctrl z or enter