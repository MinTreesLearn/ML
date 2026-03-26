#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FORI(start, stop, step) for(int i = start; (step > 0) ? (i < stop) : (i >= stop); i += step)
#define FORJ(start, stop, step) for(int j = start; (step > 0) ? (j < stop) : (j >= stop); j += step)
#define FORK(start, stop, step) for(int k = start; (step > 0) ? (k < stop) : (k >= stop); k += step)
#define FOR(i, start, stop, step) for(int i = start; (step > 0) ? (i < stop) : (i >= stop); i += step)
#define MODULO 1000000007
#define PI 3.14159265358979323846
#define nl '\n'
#define YES "YES"
#define NO "NO"
#define all(arr) arr.begin(), arr.end()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

bool isPrime(int n){if(n<2) return false;for(int i=2;i*i<=n;i++){if(n%i==0) return false;}return true;}
ll mod(ll a, ll b){ll r=a%b;return r>=0?r:r+abs(b);}
int gcd(int a, int b){if(b==0)return a; return gcd(b,mod(a, b));}
int lcm(int a, int b){return a/gcd(a, b)*b;}
ll powmod(ll n,ll p,ll m){if(p==0)return 1%m;ll u=powmod(n,p/2,m);u=(u*u)%m;if(p%2==1)u=(u*n)%m;return u;}

int n;
vector<int> vals;
vector<vector<int>> adj;
vector<int> dp;
vector<int> ans;

void get_dp_dfs(int u, int e)
{
    for(int v : adj[u])
    {
        if(v == e) continue;
        get_dp_dfs(v, u);
    }
    dp[u] = vals[u] == 0 ? -1 : 1;
    for(int v : adj[u])
    {
        if(v != e && dp[v] > 0) dp[u] += dp[v];
    }
}

void get_solutions_for_all(int u, int e)
{
    int d = dp[u];
    ans[u] = vals[u] == 0 ? -1 : 1;
    for(int v : adj[u]) if(dp[v] > 0) ans[u] += dp[v];
    for(int v : adj[u])
    {
        if(v == e) continue;
        dp[u] = dp[v] > 0 ? ans[u] - dp[v] : ans[u];
        get_solutions_for_all(v, u);
    }
    dp[u] = d;
}

void solve()
{
    cin >> n;
    vals = vector<int>(n+1);
    FORI(1, n+1, 1) cin >> vals[i];
    adj = vector<vector<int>>(n+1, vector<int>());
    dp = vector<int>(n+1);
    ans = vector<int>(n+1);
    FORI(0, n-1, 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    get_dp_dfs(1, 0);
    get_solutions_for_all(1, 0);
    //FORI(1, n+1, 1) cout << dp[i] << ' ';
    //cout <<nl;
    FORI(1, n+1, 1) cout << ans[i] << ' ';
    cout << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
