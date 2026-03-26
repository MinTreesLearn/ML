#include <iostream>
#include <map>
#include <vector>
#define ll int

using namespace std;


int32_t main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++){
        ll n, x, y;
        cin >> n >> x >> y;
        ll res1, res2;
        res1 = min(std::max(1, x + y - n + 1), n);
        res2 = min(x + y - 1, n);
        cout << res1 << ' ' << res2 << endl;
    }
    return 0;
}