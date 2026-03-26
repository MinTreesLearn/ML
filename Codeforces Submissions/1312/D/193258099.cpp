#include<bits/stdc++.h>
#define MOD 998244353
#define eps 1e-9
#define emailam  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll              long long
#define ull             unsigned long long
#define MAX 200010
#define pb push_back
#define all(a)  a.begin(),a.end()
#define pf push_front
#define fi first
#define se second
#define pii pair<int,int>
const int INF = INT_MAX;
using namespace std;
const int N=1e6+10;
const int mod=998244353;
/*----------------------------------------------------------------*/
int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};
/*----------------------------------------------------------------*/
void READ(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
#define int long long

ll power(ll x, ll y) {
    ll ret = 1;
    while (y > 0) {
        if (y % 2 == 0) {
            x = x * x;
            x %= MOD;
            y = y / 2;
        } else {
            ret = ret * x;
            ret %= MOD;
            y = y - 1;
        }
    }
    return ret;
}

int fac[N], inv[N];

void precalc() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= MOD;
    }
    inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        inv[i] = power(fac[i], MOD - 2);
    }
}

int ncr(int x, int y) {
    if (x < y)return 0;
    return ((fac[x] * inv[x - y]) % MOD * inv[y]) % MOD;
}
int mul(int a,int b){
    return (a*b)%mod;
}
int add(int a,int b){
    return ((a)+(b)+2*mod)%mod;
}
void solve(){
    int n,m;
    cin>>n>>m;
    cout<<mul(mul(ncr(m,n-1),power(2,max(0LL,n-3))),n-2)<<endl;
}



signed main() {
    emailam
    //READ();
    int t=1;
    precalc();
    //cin>>t;
    while(t--){
        solve();
    }
}