#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
#define pb push_back
#include <bits/stdc++.h>
using namespace std;
// ll mod = 1e9 + 7 ;
// const ll maxn = 1e5+1 ;
// ll fac[maxn],invfact[maxn];
// ll power(ll x, ll y)
// {
//     ll res = 1;
//     x = x % mod;

//     while (y > 0) {
//         if (y & 1)
//             res = (res * x) % mod;
//         y = y >> 1;
//         x = (x * x) % mod;
//     }

//     return res;
// }
// ll modInverse(ll n)
// {
//     return power(n, mod - 2);
// }
// ll NCR(ll n, ll r, ll p=mod)
// {
//     if(r < 0 || n < 0)
//         assert(false);

//     if( n < r ) return 0;

//     if (r == 0 || r == n)
//         return 1;

//     return ( fac[n] * invfact[r]  % mod) * invfact[n - r] % mod;
// }
// void comp()
// {
//     fac[0] = 1, invfact[0] = 1;

//     for (ll i = 1; i < maxn; i++){
//         fac[i] = (fac[i - 1] * i) % mod;
//         invfact[i] = modInverse(fac[i]);
//     }
// }
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = true;
    int dec = s[0] - 'a';
    string ans = "0";
    int mx = s[0]-'a';
    set<int> one;
    for (int i = 1; i < n; i++)
    {
        if (s[i] - 'a' >= mx)
            ans.push_back('0');
        else
        {
            for (auto j:one)
            {
                if(j>s[i]-'a'){
                    ok = false ; 
                    break ;
                }
            }
            one.insert(s[i]-'a') ;
            ans.push_back('1');
        }
        mx = max(mx, s[i] - 'a');
    }
    if (ok)
        cout << "YES\n"
             << ans << endl;
    else
        cout << "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // comp() ; -> to use ncr
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}