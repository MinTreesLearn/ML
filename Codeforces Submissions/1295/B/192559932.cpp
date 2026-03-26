#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);                   \
        cout.tie(0);
#define ll long long
const int N = 100001;
const int P = 1e9 + 7;
const ll inf = LLONG_MAX;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define cnu continue

int am()
{
     ll n,x;
     cin>>n>>x;
     string s;
     cin>>s;
     map<ll,ll>m;
     ll val = 0;
     for( int i = 0 ; i < n; i ++)
     {
        if( s[i] == '0')
        val++;
        else
        val--;
        m[val]++;
     }
     if( val == 0 )
     {
        if( m[x] != 0)
        cout<<"-1\n";
        else
        cout<<"0\n";
        return 0;
     }
     ll ans = 0;
     for( auto it = m.begin() ; it != m.end() ; ++it)
     {
        if( (x-it->ff) % val== 0 && (x-it->ff) * val >= 0)
        ans += (it->ss);
     }
     if(x == 0) ans++;
     cout<<ans<<"\n";
     return 0;
}


/***********************************************************/

int main()
{
        IOS;
        //  freopen("input.txt", "r", stdin);
        //  freopen("output.txt", "w", stdout);
        ll T = 1;
        cin >> T;
        while (T--)
               am();
        return 0;
}