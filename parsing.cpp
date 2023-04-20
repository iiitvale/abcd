#include<iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

int main(){ 

    int popl[3]={2,2,1}; //how many symbols in production
    char rhs[3]={'S','A','A'}; //lhs of production

    vector<vector<string> > parseTable;

    for(int i=0;i<10;i++){ //change

        vector<string> temp;
        string emp="";

        if(i==0){
            temp.push_back("S3");
            temp.push_back("S4");
            temp.push_back(emp);
            temp.push_back("1");
            temp.push_back("2");
        }else if(i==1){
            temp.push_back(emp);
            temp.push_back(emp);
            temp.push_back("acc");
            temp.push_back(emp);
            temp.push_back(emp);
        }else if(i==2){
            temp.push_back("S6");
            temp.push_back("S7");
            temp.push_back(emp);
            temp.push_back(emp);
            temp.push_back("5");
        }else if(i==3){
            temp.push_back("S3");
            temp.push_back("S4");
            temp.push_back(emp);
            temp.push_back(emp);
            temp.push_back("8");
        }else if(i==4){
            temp.push_back("R3");
            temp.push_back("R3");
            temp.push_back(emp);
            temp.push_back(emp);
            temp.push_back(emp);
        }else if(i==5){
            temp.push_back(emp);
            temp.push_back(emp);
            temp.push_back("R1");
            temp.push_back(emp);
            temp.push_back(emp);
        }else if(i==6){
            temp.push_back("S6");
            temp.push_back("S7");
            temp.push_back(emp);
            temp.push_back(emp);
            temp.push_back("9");
        }else if(i==7){
            temp.push_back(emp);
            temp.push_back(emp);
            temp.push_back("R3");
            temp.push_back(emp);
            temp.push_back(emp);
        }else if(i==8){
            temp.push_back("R2");
            temp.push_back("R2");
            temp.push_back(emp);
            temp.push_back(emp);
            temp.push_back(emp);
        }else{
            temp.push_back(emp);
            temp.push_back(emp);
            temp.push_back("R2");
            temp.push_back(emp);
            temp.push_back(emp);  
        }
        parseTable.push_back(temp);
    }

    cout<<"\t CLR(1) Parsing Table"<<endl;
    cout<<"\n\ta\tb\t$\t|\tS\tA"<<endl;
    cout<<"- - - - - - - - - - - - - - -";
    cout<<endl;
    for(int i=0;i<10;i++){  //change
        cout<<i<<"\t";
        for(int j=0;j<5;j++){   //change
            cout<<parseTable[i][j]<<"\t";
            if(j==2){
                cout<<"|\t";
            }
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;

    string s;
    cin>>s;
    s+='$';
    char a[10]={'0','1','2','3','4','5','6','7','8','9'}; //row name
    char b[5]={'a','b','$','S','A'}; //column name

    map<char,int> am;
    for(int i=0;i<10;i++){
        am[a[i]]=i;  //change
    }
    map<char,int> bm;
    for(int i=0;i<5;i++){
        bm[b[i]]=i; //change
    }

    stack<char> ms;

    ms.push('0');

    bool ans=true;
    int pt=0;

    cout<<"Stack Entries : "<<endl;
    cout<<endl;

    while(pt<s.length() && !ms.empty()){

        stack<char> msc;
        msc=ms;

        vector<char>sentry;

        while(!msc.empty()){
            sentry.push_back(msc.top());
            msc.pop();
        }

        reverse(sentry.begin(),sentry.end());
        for(int some=0;some<sentry.size();some++){
            cout<<sentry[some]<<" ";
        }
        cout<<endl;

        int ind1=am[ms.top()],ind2=bm[s[pt]];

        string here=parseTable[ind1][ind2];

        if(here=="acc"){
            break;
        }

        if(here==""){
            ans=false;
            break;
        }

        if(here[0]=='S'){
            ms.push(s[pt]);
            ms.push(here[1]);
            pt++;

        }else if(here[0]=='R'){
            int reduce=am[here[1]];
            int cntp=2*popl[reduce-1];

            while(cntp){
                ms.pop();
                cntp--;
            }

            int x=am[ms.top()];
            ms.push(rhs[reduce-1]);
            int col=bm[rhs[reduce-1]];
            string enter=parseTable[x][col];
            ms.push(enter[0]);

        } else {
            ans=false;
            break;
        }
    }

    cout<<endl;
    cout<<endl;

    if(ans){
        cout<<"\t  -----STRING ACCEPTED-----";
    }else{
        cout<<"Given String doesn't belong to this Grammar";
    }

    return 0;
}