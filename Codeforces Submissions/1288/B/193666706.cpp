#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
using namespace std;
 
#define MOD 1000000007
#define MOD2 998244353
#define MAXN 20000001
#define INF 2e9
#define INF2 1e18
#define ll long long
#define nl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second

typedef pair<int,int> pii; 
typedef pair<ll,ll> pll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    ll a,b;
    while(cin >> a >> b){
        cout << a*(ll)(log10(b+1)) << nl;
    }
}