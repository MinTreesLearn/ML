#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define fi first
#define se second
#define pp push_back
#define all(x) (x).begin(), (x).end()
#define Ones(n) __builtin_popcount(n)
#define endl '\n'
#define fill(arrr,xx) memset(arrr,xx,sizeof arrr)
#define rep(aa, bb, cc) for(int aa = bb; aa < cc;aa++)
#define PI acos(-1)
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

vector<pii>adj[N];
int deg[N],ans,color[N];

void dfs(int u,int par,int prv){
    int cur = 0;
    for(auto v:adj[u]){
        if(v.fi == par)continue;
        if(cur == prv){
            cur = (cur + 1)%ans;
        }
        color[v.se] = cur;
        dfs(v.fi,u,cur);
        cur = (cur + 1)%ans;
    }
}

void solve() {
    int n,k;cin >> n >> k;
    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        u--,v--;
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
        deg[u]++,deg[v]++;
    }
    sort(deg,deg + n);
    ans = deg[n - k - 1];
    dfs(0,0,-1);
    cout << ans << endl;
    for (int i = 0; i < n - 1; ++i) {
        cout << color[i] + 1<< ' ';
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