#include <iostream>

using namespace std;

// For identify weather grammer is multiline or not
int main(){

    string s,temp = "";
    getline(cin,temp);

    while(temp != "end"){
        s+=temp;
        getline(cin,temp);
    }

    int n = s.size(),index = s.find("*/");
    if(s.substr(0,2) != "/*" || s.substr(n-2,2) != "*/" || index != n-2){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}
