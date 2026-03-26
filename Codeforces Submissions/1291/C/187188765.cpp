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
    int n,m,k;cin >> n >> m >> k;
    vector<int>v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int>picks;
    for (int i = 0; i < m; ++i) {
        int topick = (m - 1) - i;
        int ind = n - topick - 1;
        picks.push_back(max(v[i],v[ind]));
    }
    if(k >= picks.size() - 1){
        cout << *max_element(all(picks)) << endl;
        return;
    }
    int ans = 0;
    int jump = (int)picks.size() - k - 1;
    for (int i = 0; i + jump < picks.size(); ++i) {
        int l = i,r = i + jump;
        int mn = 2e9;
        for (int j = l; j <= r; ++j) {
            mn = min(mn,picks[j]);
        }
        ans = max(ans,mn);
    }
    cout << ans << endl;
}


signed main() {
    Gamal();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}