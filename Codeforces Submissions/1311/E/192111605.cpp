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
        ll n, d;
        cin >> n >> d;
        ll sum = n * (n - 1) / 2;
        ll low = 0;
        for(ll i = 1, cd = 0; i <= n; i++) {
            if(!(i & (i - 1))) cd++;
            low += cd - 1;
        }
        if(d < low or d > sum) {
            cout << "NO" << '\n';
            continue;
        }
        vector<ll> par(n), cnt(n, 1), dep(n);
        vector<bool> bad(n);
        rep(i, 0, n) {
            par[i] = i - 1;
        }
        cnt[n - 1] = 0;
        rep(i, 0, n) {
            dep[i] = i;
        }
        bool flag = true;
        while(flag and sum > d) {
            ll v = -1;
            rep(i, 0, n) {
                if(!bad[i] and cnt[i] == 0) {
                    if(v == -1 or dep[v] > dep[i]) {
                        v = i;
                    }
                }
            }
            if(v == -1) {
                flag = false;
                break;
            }
            ll p = -1;
            rep(i, 0, n) {
                if(cnt[i] < 2 and dep[i] == dep[v] - 2) {
                    p = i;
                }
            }
            if(p == -1) {
                bad[v] = true;
                continue;
            }
            cnt[par[v]]--;
            dep[v]--;
            cnt[p]++;
            par[v] = p;
            sum--;
        }
        if(flag) {
            cout << "YES" << '\n';
            rep(i, 1, n) {
                cout << par[i] + 1 << " \n"[i == n - 1];
            }
        } else {
            cout << "NO" << '\n';
        }
    }
}