#include <bits/stdc++.h>
using namespace std;
#define  enl          '\n'
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()

mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<int>deg(n+1);
    for(int i=1;i<n;i++) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
        deg[x]++;
        deg[y]++;
    }

    sort(all(deg),greater<int>());
    vector<int>color(n+1);
    int r = max(1LL,deg[k]);
    
    function<void(int,int,int)>dfs = [&](int s,int p,int clr) {
        for(auto [u,idx]:adj[s]) {
            if(u == p) continue;
            color[idx] = clr%r+1;
            clr++;
            dfs(u,s,clr%r);
        }
    };

    dfs(1,-1,1);

    cout<<r<<enl;
    for(int i=1;i<n;i++) cout<<color[i]<<' ';
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases = 1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}