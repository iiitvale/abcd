// <-- Code By: Ashu Mittal -->
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T> >;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ff first
#define ss second
#define ll long long
#define all(sss) (sss).begin(),(sss).end()
#define pb push_back
#define pob pop_back
#define endl "\n"
#define input(ass) for(auto &x:(ass)) cin>>x;
#define iendl "\n", cout<<flush

const int mod = 1000000007;
// const int mod = 998244353;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(x)
#endif

// help
ll LCM(ll aaa, ll bbb) {return (aaa / __gcd(aaa, bbb)) * bbb;}
ll power(ll aaa, ll bbb) {ll ans = 1; while (bbb) {if (bbb & 1) ans = (ans * aaa) % mod; bbb >>= 1; aaa = (aaa * aaa) % mod;} return ans;}
ll mod_inv(ll a) {return power(a, mod - 2);}

/*----------------------------------x x x---------------------------------*/
void solve();
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    ll TT = 1;
    // cin >> TT;
    for (ll TEST = 1; TEST <= TT; TEST++) {
        // cout<<"Case #"<<TEST<<": ";
        solve();
    }
}

struct stck {
public:
    string cur;
    int a;
    char top, opn;
    stck(string c1, char op1, int c, char tp1) {
        cur = c1;
        a = c;
        top = tp1, opn = op1;
    }
};

void solve() {

    // initialising ACTION table ...
    map<int, map<char, int>> Action;
    Action[0]['x'] = 3, Action[0]['y'] = 4;
    Action[1]['$'] = 0;
    Action[2]['x'] = 6, Action[2]['y'] = 7;
    Action[3]['x'] = 3, Action[3]['y'] = 4;
    Action[4]['x'] = -3, Action[4]['y'] = -3;
    Action[5]['$'] = -1;
    Action[6]['x'] = 6, Action[6]['y'] = 7;
    Action[7]['$'] = -3;
    Action[8]['x'] = -2, Action[8]['y'] = -2;
    Action[9]['$'] = -2;

    // initialising GOTO table ...
    map<int, map<char, int>> Goto;
    Goto[0]['X'] = 1, Goto[0]['Z'] = 2;
    Goto[2]['Z'] = 5;
    Goto[3]['Z'] = 8;
    Goto[6]['Z'] = 9;

    // Numbering Grammar Productions ...
    map<int, pair<char, int>> reduce;
    reduce[-1] = {'X', 4}, reduce[-2] = {'Z', 4}, reduce[-3] = {'Z', 2};

    string input, s = "0"; cin >> input;
    std::vector<stck*> entry;

    for (int i = 0; i < input.size();) {
        if (s.empty()) break;
        char ch = input[i];
        int top = s.back() - '0';
        int num = Action[top][ch];

        stck *obj = new stck(s, (num >= 0 ? 'S' : 'R'), top, ch);
        if (num > 0) i++;
        else if (num < 0) {
            auto p = reduce[num];
            while (s.size() and p.ss-- > 0) s.pop_back();
            if (s.empty()) break;
            ch =  p.ff;
            top = s.back() - '0', num = Goto[top][ch];
        }
        else  break;
        s += ch, s += '0' + num;
        entry.push_back(obj);
    }

    if (s.size()) {
        int top = s.back() - '0';
        stck *obj = new stck(s, 'A', top, '$');
        entry.push_back(obj);
    }

    dbg(s)
    cout << (s.back() != '1' ? "String Rejected \n" : "String Accepted \n");
    cout << "\n                 Stack Entries         \n\n";
    cout << "Top_of_Stack    Cur_alphabet     Operation      Stack\n\n";

    for (int i = 0; i < entry.size(); i++)
        cout << "    " << entry[i]->a << "              " << entry[i]->top << "                " << entry[i]->opn << "             " << entry[i]->cur << endl;
}