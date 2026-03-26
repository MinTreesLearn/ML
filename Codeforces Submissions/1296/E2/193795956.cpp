#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define S second
#define F first
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 2e5 + 123;
ll n, a, b, k;
vector <ll> dp(N, 1);
vector <ll> dpn(N);
string s;
int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        for(int j = 25; j > s[i] - 97; j--) {
            dp[i] = max(dp[i], dpn[j] + 1);
        }
        dpn[s[i] - 97] = max(dpn[s[i] - 97], dp[i]);
    }
    ll mx = *max_element(all(dpn));
    cout << mx << '\n';
    for(int i = 0; i < n; i++) {
        cout << dp[i] << ' ';
    }
}
