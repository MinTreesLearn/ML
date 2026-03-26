#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define S second
#define F first
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 2e5 + 123;
ll n, a, b, k;
ll c[N];
int main() {
    cin >> n >> a >> b >> k;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        c[i] = c[i] % (a + b);

        if(c[i] == 0) c[i] = a + b;

        if(c[i] % a != 0) {
            c[i] = c[i] / a;
        }
        else {
            c[i] = c[i] / a - 1;
        }
    }
    ll ans = 0;
    sort(c + 1, c + n + 1);
    for(int i = 1; i <= n; i++) {
        if(k - c[i] < 0) break;

        ans++;

        k -= c[i];
    }

    cout << ans;
}
