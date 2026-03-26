#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd_sum(ll num) {
    ll t = num, d= 0;

    while (t > 0) {
        d += t % 10;
        t /= 10;
    }

    ll gcd = __gcd(num, d);
    return gcd;
}

void Void(){
 ll n, s = 0, p = 1, c = 0, ans = 0;
    cin >> n;
    vector <ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 0)
            c++, a[i] = 1;
        s += a[i];
    }
    ans = (s == 0);
    if(c == 0)
        cout << ans << endl;
    else
        cout << ans + c << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--)Void();
}
