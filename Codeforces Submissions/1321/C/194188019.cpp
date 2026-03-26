/*
ID: armaan48
LANG: C++ 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define mod2 998244353
#define endl '\n' 
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define print(x) {for(auto v: x) {cout << v<< ' ';} cout << endl;}
#define printp(x) {for(auto v: x) {cout << v.first << ':' << v.second << ' ';} cout << endl;}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    int t = 2;
    int org = n;
    while (1){
        n = sz(s);
        int f = 1;
        for (int i=25;i>=0;i--){
            for (int j=0;j<n;j++){
                if ((s[j] - 'a')!=i)
                    continue;
                if ((j-1>=0 and (s[j-1]-'a')+1==i) or (j+1<n and (s[j+1]-'a')+1==i)){
                    f=0;
                    s = s.substr(0,j) + s.substr(j + 1);
                    break;
                }
            }
            if (!f){
                break;
            }
        }
        if (f){
            break;
        }
    }
    cout <<  org- sz(s) << endl;

    

    
    return 0;
}