
#include <bits/stdc++.h>
using namespace std;
unordered_map<char, vector<string>> S;
unordered_map<char, vector<char>> FI;
unordered_map<char, vector<char>> FO;
vector<char> Z;
bool notin(char x)
{
    for (auto it : Z)
    {
        if (it == x)
            return false;
    }
    return true;
}
void first(char z)
{
    vector<char> temp;
    for (auto it : S[z])
    {
        if (notin(it[0]))
        {
            temp.push_back(it[0]);
        }
        else
        {
            if (FI.find(it[0]) != FI.end())
            {
                vector<char> temp2 = FI[it[0]];
                for (auto i : temp2)
                    temp.push_back(i);
            }
            else
            {
                first(it[0]);
                vector<char> temp2 = FI[it[0]];
                for (auto i : temp2)
                    temp.push_back(i);
            }
        }
    }
    FI[z] = temp;
}
void follow(char x)
{
    vector<char> temp;
    for (auto it : S)
    {
        for (int i = 0; i < it.second.size(); i++)
        {
            for (int j = 0; j < it.second[i].size(); j++)
            {
                if (it.second[i][j] == x)
                {
                    if (i == it.second[i].size() - 1)
                    {
                        if (it.first != x)
                        {
                            if (FO.find(it.first) != FO.end())
                            {
                                vector<char> temp2 = FO[it.first];
                                for (auto i : temp2)
                                    temp.push_back(i);
                            }
                            else
                            {
                                follow(it.first);
                                vector<char> temp2 = FO[it.first];
                                for (auto i : temp2)
                                    temp.push_back(i);
                            }
                        }
                    }
                    else if (notin(it.second[i][j + 1]))
                    {
                        temp.push_back(it.second[i][j + 1]);
                    }
                    else
                    {
                        vector<char> temp2 = FI[it.second[i][j + 1]];
                        for (auto i : temp2)
                            temp.push_back(i);
                    }
                }
            }
        }
    }
    set<char> X;
    for (auto it : temp)
    {
        if (it != '!')
            X.insert(it);
    }
    vector<char> res;
    for (auto it : X)
    {
        FO[x].push_back(it);
    }
}
void remove(){
    for(auto it:FO){
        set<char>t;
        for(auto it2:it.second){
            t.insert(it2);
        }
        vector<char>temp;
        for(auto it2:t){
            temp.push_back(it2);
        }
        FO[it.first]=temp;
    }
}
void printfollow()
{
    for (auto it : FO)
    {
        cout << it.first << "-> ";
        for (auto it2 : it.second)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}
void printfirst()
{
    for (auto it : FI)
    {
        cout << it.first << "-> ";
        for (auto it2 : it.second)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}
int main()
{
    cout << "Enter number of prod" << endl;
    int n;
    cin >> n;
    int k = n;
    cout << "Enter epsiolon as !" << endl;
    while (k--)
    {
        cout << "Enter left prod" << endl;
        char c;
        cin >> c;
        cout << "Enter right prod" << endl;
        string l;
        cin >> l;
        S[c].push_back(l);
    }
    for (auto it = S.begin(); it != S.end(); it++)
    {
        Z.push_back(it->first);
    }
    for (auto it : Z)
    {
        first(it);
    }
    for (auto it : Z)
    {
        follow(it);
    }
    cout << "First" << endl;
    printfirst();
    FO[Z[0]].push_back('$');
    remove();
    cout << "Follow" << endl;
    printfollow();
    return 0;
}

