#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#define int long long
#define N (int)2e5+5
using namespace std;
typedef pair<int, int> P;
const int mod = 998244353;
int fac[N];
int fastpow(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}
void init(int mx){
    fac[1] = fac[0] = 1;
    for(int i = 2; i <= mx; i++) fac[i] = (fac[i - 1] * i) % mod;
}
int c(int n, int m){
    return fac[n] * fastpow(fac[m], mod - 2) % mod * fastpow(fac[n - m], mod - 2) % mod;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if(n == 2){
        cout << "0\n";
        exit(0);
    }
    init(m);
    // c(m, n - 1) * c(n - 2, 1) * sigma(k = 1 ~ n - 3)(c(n - 3, k - 1))
    cout << c(m, n - 1) * (n - 2) % mod * fastpow(2, n - 3) % mod << "\n";
    return 0;
}