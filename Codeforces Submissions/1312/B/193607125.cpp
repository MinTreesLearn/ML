#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define elif else if
#define accepted cout << "YES\n"
#define error cout << "NO\n"

using namespace std;
const ll N = 2e10;
const ll mod = 1e9 + 7;

void func()
{
    ll n;
    cin >> n;

    vector < ll > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(rall(a));
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;

    while (t--)
        func();
    return 0;
}
