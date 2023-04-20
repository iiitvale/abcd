%{
#include <stdio.h>
#include <stdlib.h>
int yywrap();
int v = 0,c = 0,s = 0;
%}
%%
"end" {return 0;}
[\.\?\!] { s++; }
[aeiouAEIOU] { v++; }
[^(aeiouAEIOU)] { c++; }
. ;
%%
int main(){
    yylex();
    printf("NUMBER OF VOWELS : %d\n",v);
    printf("NUMBER OF CONSONANTS : %d\n",c);
    printf("NUMBER OF SENTENCES : %d\n",s);
    return 0;
}
int yywrap(){
    return 1;
}
// flex file.l
// gcc lex.yy.c
// ./a.out or exe which is there
// for run end