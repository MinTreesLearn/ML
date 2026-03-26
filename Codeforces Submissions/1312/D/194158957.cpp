#include <bits/stdc++.h>
using namespace std;

#define ll long long int

// nCr using inverse factorial

ll mod = 998244353;

ll power(ll a, ll b, ll m = mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

ll invmod(ll a, ll m = mod) {return power(a, m - 2, m);} //For prime mod

ll mAdd(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mSub(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mMul(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mDiv(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return mMul(a, invmod(b), m);}

ll N = 1e6 + 1;

vector<ll> factorial (N, 1);
vector<ll> invFactorial (N, 1);

//Call this in main function
void prenCr(){
    for (ll i = 2; i < N; i++)
    {
        factorial[i] = mMul(i, factorial[i-1]);
        invFactorial[i] = mDiv(1, factorial[i]);
    }
}

ll nCr(ll n, ll r){
    if(r > n || r < 0){
        return 0;
    }
    return mMul(factorial[n], mMul(invFactorial[r], invFactorial[n-r]));
}

void solve(){

    ll n, m;
    cin >> n >> m;

    if(n == 2){
        cout << 0 << endl;
        return;
    }

    ll ans = 0;

    ll p = power(2, n-3);
    ll invModNminus2 = invmod(1, n-1);

    for (ll i = n-1; i <= m; i++)
    {
        ll sa = nCr(i-1, n-2);
        sa *= p;
        sa %= mod;
        sa *= n-2;
        sa %= mod;
        sa = mMul(sa, invModNminus2);

        ans += sa;
        ans %= mod;
    }
    
    cout << ans << endl;
}

int main() { 

    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    prenCr();
    
    ll T = 1;
    
    while (T--)
    {
        solve();
    }
    
    return 0;

}