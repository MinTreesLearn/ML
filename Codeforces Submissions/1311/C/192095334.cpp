#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, a, b) for(ll i = a; i >= b; i--)
const ll inf = 4e18;
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<ll> p(m);
        rep(i, 0, m) {
            cin >> p[i];
            p[i]--;
        }
        sort(p.begin(), p.end());
        vector<ll> cnt(26);
        rep(i, 0, n) {
            ll idx = lower_bound(p.begin(), p.end(), i) - p.begin();
            cnt[s[i] - 'a'] += (m - idx + 1);
        }
        rep(i, 0, 26) {
            cout << cnt[i] << " \n"[i == 25];
        }
    }
}