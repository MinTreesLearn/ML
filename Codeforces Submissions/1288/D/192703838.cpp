#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef map<ll,ll> mll;
typedef vector<int> vi;
typedef set<ll> sll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {return a == 0? b: gcd(b%a,a);}
ll lcm(ll a, ll b) {return a * (b / gcd(a,b));}
#define inf 1e17
#define pb(x) push_back(x)
#define rep(x,n) for (int i = x; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define fo(x) find_by_order(x)
#define ok(x) order_of_key(x)
ll mod = 1e9 + 7;
int MAXN = 100000;

ii f(vector<vi> &grid, int k, vector<vi> &adj){
    int n = grid.size(), m = grid[0].size();
    vi cnt(1 << m,-1);
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] >= k) mask |= (1 << j);
        }
        cnt[mask] = i;
        for (auto v : adj[mask]) if (cnt[v] != -1) return {i,cnt[v]};
    }
    return {-1,-1};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;
    int M = 1 << m;
    vector<vi> adj(M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if ((i | j) == (M - 1)) adj[i].pb(j);
        }
    }

    vector<vi> grid(n,vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    }

    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (f(grid,mid,adj).first != -1) {
            l = mid + 1;
        }else r = mid - 1;
    }
    ii ans = f(grid,r,adj);
    //cout << r << "\n";
    cout << ans.first + 1 << " " << ans.second + 1 << "\n";

    return 0;
}