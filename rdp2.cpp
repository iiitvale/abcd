#include <bits/stdc++.h>

using namespace std;

/*
A -> aA'
A' -> BdA' | aA' | #
B -> bB'
B' -> eB' | #

A' -> C
B' -> D
# -> epislon production
*/


//declaring as global variables so they are accessible for all scopes in the program.
stack <char> st;
int i = 0;
string s;
//end of declaration of global variables.

//declaration of all the functions used 

int A(),C(),B(),D(),match();

void show_stack(stack <char> tempst){

    queue < char> tempq;
    while(!tempst.empty()){
        tempq.push(tempst.top());
        tempst.pop();
    }

    while(!tempq.empty()){
        cout<<tempq.front()<<" ";
        tempq.pop();
    }
    cout<<endl;
}

int match(char temp){

    if(s[i] == temp){
        i++;
        return 1;
    }
    return 0;
}

int A(){

    show_stack(st);
    st.push('A');

    if(s[i] == 'a'){
        if(match('a')){
            if(C()){
                st.pop();
                return 1;
            }
        }
    }
    return 0;
}

int C(){

    show_stack(st);
    st.push('C');

    if(s[i] == 'a'){
        if(match('a')){
            if(C()){
                st.pop();
                return 1;
            }
        } 
    } else if(B() == 1){
        if(match('d')){
            if(C()){
                st.pop();
                return 1;
            }
        }
    } else {
        st.pop();
        return 1;
    }

    return 0;
}

int B(){

    int temp = i;

    show_stack(st);
    st.push('B');

    if(match('b')){
        if(D()){
            st.pop();
            return 1;
        }
    }

    if(s[temp] != 'b'){
        st.pop();
        return 3;
    }

    return 0;
}

int D(){

    show_stack(st);
    st.push('D');

    if(match('e')){
        if(D()){
            st.pop();
            return 1;
        }
    } else {
        st.pop();
        return 1;
    }

    return 0;
}

int main(){

    cout<<"ENTER THE STRING TO BE CHECKED : ";
    cin>>s;

    cout<<"\nTHE STACK ENTERIES ARE : "<<endl;
    st.push('$');
    int c = A();
    show_stack(st);

    if(c && st.top() == '$' && i == s.length()){
        cout<<"--THE STRING IS ACCEPTED--"<<endl;
    } else {
        cout<<"--THE STRING IS NOT ACCEPTED--"<<endl;
    }

    return 0;
}