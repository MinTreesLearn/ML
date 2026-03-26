#include <bits/stdc++.h>
#include <time.h>
#include <random>
#include <conio.h>

typedef long double ld;
typedef long long  ll;

#define rall(a) a.rbegin(), a.rend()
#define all(a) a.begin(), a.end()
#define accepdet cout << "YES\n"
#define error cout << "NO\n"

/// author: University ITMO

using namespace std;

bool arr(vector < ll > &a) {
    return is_sorted(a.begin(), a.end());}

ll Sum(vector < ll > &a) {
    return accumulate(a.begin(), a.end(), 0);}

ll mod = 1000000007;
bool flag = true;
ll k = 0, d = 0;

ll powing(ll x, ll n)
{
    if (n == 0) return 1;
    ll r = powing(x, n / 2);
    r = (r * r) % mod;
    if (n & 1) r = (r * 2) % mod;
    return r;
}

ll summa(ll n) {return n * (n + 1) / 2;}

ll fact(ll n) {
    return n * (n - 1) / 2;
}

void func()
{
    ll n, Robo = 0, Bionic = 0;
    cin >> n;

    vector < ll > a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        Robo += (!b[i] and a[i] > 0);
        Bionic += (b[i] > 0 and !a[i]);
    }

    if (!Robo) {
        cout << "-1\n";
        return;
    }
    cout << Bionic / Robo + 1 << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    ios_base::sync_with_stdio(true);
    cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;

    while (t--)
    {
        func();
    }
    return 0;
}
