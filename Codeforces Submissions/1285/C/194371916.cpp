#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using namespace std;

ll gcd(ll a, ll b)
{
    if (a==0) return b;
    return gcd(b%a, a);
}

ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a,b);
}

int main() {
    IOS;

    time_t start, end;
    time(&start);

    ll n; cin >> n;
    ll a = 1, b = n;
    ll l = 2, r;

    for (l = 2; l<int(sqrt(n)+100); l++)
    {
        if (n%l!=0) {continue;}
        r = n/l;
        if (l>r) {break;}
        if (lcm(l,r)!=n) {continue;}
        a = l; b = r;
    }

    cout << a << " " << b;

    // time(&end);
    // cout << '\n' << end-start;

    return 0;
}