#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 7;

ll lcm(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll a = 1, b = n;
    
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ll d = n / i;
            if(d != i && d <= b && lcm(i, d) == n) {
                a = i;
                b = d;
            }
        }
    }
    cout << a << " " << b << "\n";
}