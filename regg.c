#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int S(int index),A(int index),B(int index),C(int index);
char s[100];

int S(int index){

    if(s[index] == 'a'){
        if(S(index+1) == 1){
            return 1;
        }
    } else if(s[index] == 'b'){
        if(A(index+1) == 1){
            return 1;
        }
    }

    return 0;
}

int A(int index){

    if(s[index] == 'a'){
        return 0;
    } else if(s[index] == 'b'){
        if(B(index+1) == 1){
            return 1;
        }
    }
}

int B(int index){

    if(index == strlen(s)){
        return 1;
    } else if(s[index] == 'b'){
        if(B(index+1) == 1){
            return 1;
        }
    } else if(s[index] == 'a'){
        if(C(index+1) == 1){
            return 1;
        }
    }

    return 0;
}

int C(int index){

    if(index == strlen(s)){
        return 1;
    } else if(s[index] == 'a'){
        if(C(index+1) == 1){
            return 1;
        }
    } else if(s[index] == 'b'){
        return 0;
    }

    return 0;
}

int main(){


    printf("ENTER THE STRING : ");
    scanf("%s",s);

    int n = strlen(s);

    if(S(0) == 1){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}