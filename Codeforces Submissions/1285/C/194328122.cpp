#include<bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;
void solve(){
    ll x;
    cin >> x;
    vector<ll>a;
    int cnt = 0;
    ll mn = 1000000000000;
    bool ok = false;
    for (ll i = 2; i * i <= x; i++){
        if (x % i == 0){
            ll y = x / i;
            if (__gcd(i, y) == 1){
                ok = true;
                mn = min(y, mn);
            }
        }
    }
    if (ok)cout << mn << ' ' << x / mn;
    else  cout << x << ' ' << x;
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
