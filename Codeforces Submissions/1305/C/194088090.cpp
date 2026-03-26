#include "bits/stdc++.h"

using namespace std;

#define int long long
//#define endl "\n"
#define inf (int)1e18
#define BeethovenBeedrilla true
#define TheEndOfPutin true


const int MOD =1000000000+7;

int binPow(int x, int p, int mod) {
    int res = 1;
    while (p > 0) {
        if (p % 2)
            res = (res * x) % mod;
        x = (x * x) % mod;
        p /= 2;
    }
    return res;
}

inline int modDiv(int a, int b, int mod = MOD) {
    int p = binPow(b, mod - 2, mod);
    return (a * p) % mod;
}

vector<int> facts;

int fact(int x, int mod = MOD) {
    if (facts.size() <= x) {
        facts.push_back(x <= 0 ? 1 : (fact(x - 1, mod) * x) % mod);
    }
    return facts[x];
}

inline int binom(int n, int k, int mod = MOD) {
    return modDiv(fact(n), fact(n - k) * fact(k) % mod);
}

int logPow(int n, int p, int mod = MOD) {
    int ans = 1;
    int c = n % mod;
    while (p > 0) {
        if (p % 2) {
            ans = (ans * c) % mod;
        }
        p /= 2;
        c%=mod;
        c = (c * c) % mod;
    }
    return ans;
}
//int fact(int n){
//    int ans = 1;
//    while(n>= 2){
//        ans *=n;
//        n--;
//    }
//    return ans;
//}
int sp_mult(int l,int r){
    int ans = 1;
    for(int i = l+1 ; i <=r ; i ++){
        ans *= i;
    }
    return ans ;
}

signed main() {
    cin.tie(nullptr), cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    int n,m;
    cin>>n>>m;
    int num[n];
    int x=1;
    for(int j=0;j<n;j++)
    {
        cin>>num[j];
        for(int i=0;i<j&&x!=0;i++)
            x=x*abs(num[i]-num[j])%m;

    }
    cout<<x%m;
}

