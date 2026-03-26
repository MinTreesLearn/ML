#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define fi first
#define se second
#define pp push_back
#define inarr(n, arr) for(int ax = 0; ax<(n); ax++)cin>>(arr)[ax];
#define rep(aa, bb, cc) for(int aa = bb; aa < cc;aa++)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(),(x).rend()
#define Ones(n) __builtin_popcount(n)
#define endl '\n'
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
//#define int long long

void Gamal() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef Clion
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

const double EPS = 1e-9;
const ll N = 2e5 + 5, INF = INT_MAX, MOD = 1e9 + 7, OO = 0X3F3F3F3F3F3F3F3F, LOG = 25;

void solve() {
    string s;cin >> s;
    vector<int>adj[30];
    for (int i = 0; i < s.size(); ++i) {
        adj[s[i] - 'a'].push_back(i);
    }
    int q;cin >> q;
    while (q--){
        int l,r;cin >> l >> r;
        l--,r--;
        if(l == r || s[l] != s[r]){
            cout << "Yes\n";
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            if(i == s[l]-'a')continue;
            cnt += min(1,(int)(upper_bound(all(adj[i]),r) - lower_bound(all(adj[i]),l)));
        }
        if(cnt >= 2){
            cout << "Yes\n";
        }
        else cout << "No\n";
    }

}


signed main() {
    Gamal();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}