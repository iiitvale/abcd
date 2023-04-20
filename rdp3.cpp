
- REcursive descent parser
#include <bits/stdc++.h>
using namespace std;
int i=0;
string s;
bool X();bool Y();bool Z();bool W();
bool X(){
    if(s[i]=='x'){
        i++;
        if(Y()){
            return true;
        }
        return false;
    }
    return false;
}
bool Y(){
    if(Z()){
        if(W()){
            if(Y()) return true;
            return false;
        }
        return false;
    }
    else if(s[i]=='x'){
        i++;
        if(s[i]=='y') {i++;return true;}
        return false;
    }
    return true;
}
bool Z(){
    if(s[i]=='y'){
        i++;
        if(W())return true;
        return false;
    }
    return false;
}
bool W(){
    if(s[i]=='z') {
        i++;
        if(W()) return true;
        return false;
    }
    return true;
}
int main(){
    cin>>s;
    if(X()){
        cout<<"Accepted"<<endl;
        return 0;
    }
    cout<<"Rejected"<<endl;
    return 0;
}

