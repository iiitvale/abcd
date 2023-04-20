#include <bits/stdc++.h>

using namespace std;

/*
E –> TD 
D –> +TD|# 
T –> FR 
R –> *FR|#
F –> (E)|a
*/

//declaring as global variables so they are accessible for all scopes in the program.
stack <char> st;
int i = 0;
string s;
//end of declaration of global variables.

//declaration of all the functions used 

int E(),D(),T(),R(),F();


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
    if(temp == s[i]){
        i++;
        return 1;
    } 

    return 0;
}

int E(){

    show_stack(st);

    st.push('E');

    if(T()){
        if(D()){
            st.pop();
            return 1;
        }
    }

    return 0;
}

int D(){

    show_stack(st);

    st.push('D');
    if(s[i] == '+'){
        if(match('+')){
            if(T()){
                if(D()){
                    st.pop();
                    return 1;
                }
            }
        } 
    } else {
        st.pop();
        return 1;
    }

    return 0;
}

int T(){

    show_stack(st);

    st.push('T');
    if(F()){
        if(R()){
            st.pop();
            return 1;
        }
    }

    return 0;
}

int R(){

    show_stack(st);

    st.push('R');
    if(s[i] == '*'){
        if(match('*')){
            if(F()){
                if(R()){
                    st.pop();
                    return 1;
                }
            }
        } 
    } else {
        st.pop();
        return 1;
    }

    return 0;
}

int F(){

    show_stack(st);

    st.push('F');
    if(s[i] == '('){
        if(match('(')){
            if(E()){
                if(match(')')){
                    st.pop();
                    return 1;
                }
            }
        } 
    } else if(s[i] == 'a'){
        if(match('a')){
            st.pop();
            return 1;
        }
    } 
    return 0;
}

int main(){

    cout<<"ENTER THE STRING TO BE CHECKED : ";
    cin>>s;

    // cout<<s<<endl;
    cout<<"\nTHE STACK ENTERIES ARE : "<<endl;
    st.push('$');
    int c = E();

    show_stack(st);
    if(c && st.top() == '$'){
        cout<<"--THE STRING IS ACCEPTED--"<<endl;
    } else {
        cout<<"--UNMACTHED TERMINAL FOUND--"<<endl;
        cout<<"--THE STRING IS NOT ACCEPTED--"<<endl;
    }

    return 0;
}