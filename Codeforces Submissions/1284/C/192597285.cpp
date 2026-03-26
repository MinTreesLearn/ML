#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#define int long long
void solve()
{
    int n,mod;
    cin>>n>>mod;
    vector<int> fact(n+1,1);
    for(int i=2;i<=n;i++)fact[i]=(fact[i-1]*i)%mod;
    int rez=0LL;
    for(int i=1;i<=n;i++)
    {
        ///permutari restu, poz in care se afla, de la cat la cat
        rez+=((((fact[n-i]*(n-i+1))%mod)*(n-i+1)%mod)*fact[i])%mod;
        rez%=mod;
        //cout<<rez;
    }
    cout<<rez;
}
main()
{
    auto sol=[](bool x)->string
    {
        if(x)return "YES";
        return "NO";
    };
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        solve();
        cout<<'\n';
    }
}
