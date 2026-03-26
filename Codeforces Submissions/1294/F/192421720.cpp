#include<bits/stdc++.h>
#define ll long long
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define repin rep(i,0,n)
#define di(a) int a;cin>>a;
#define precise(i) cout<<fixed<<setprecision(i)
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j];
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' ';
#define vpii vector<pair<int,int>>
#define sis string s;
#define sin string s;cin>>s;
#define db double
#define be(x) x.begin(),x.end()
#define pii pair<int,int>
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bpc(x) __builtin_popcountll(x) 
#define btz(x) __builtin_ctz(x)
using namespace std;

const long long INF=1e18;
const long long M=1e9+7;
const long long MM=998244353;
  
int power( int N, int M){
    int power = N, sum = 1;
    if(N == 0) sum = 0;
    while(M > 0){if((M & 1) == 1){sum *= power;}
    power = power * power;M = M >> 1;}
    return sum;
}

const int N =200005;
vector<int> adj[N];

vector<int> bfs(int n,int s){
    queue<int> q;
    vector<bool> used(n+1);
    vector<int> d(n+1), p(n+1);
    
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    
    }

    return d;
}

pair<vector<int>, vector<int>> bfs1(int n,int s){
    queue<int> q;
    vector<int> used(n+1);
    vector<int> d(n+1), p(n+1);
    
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    
    }

    return {used,p};
}

vi path(int u,vector<int> used,vector<int> p){
    // if (!used[u]) {
    //     cout << "No path!";
    // } else {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        return path;
    // }    
}
 
void solve()
{
    di(n)
    rep(i,0,n-1){
        di(u) di(v)
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int temp = 0;
    int p = -1;
    vi d = bfs(n,1);
    rep(i,1,n+1){
        if(d[i]>p){p=d[i];temp=i;}
    }
    vi ans;
    ans.pb(temp);
    int res = 0;
    d=bfs(n,temp);
    auto y = bfs1(n,temp);
    temp = 0;
    p = -1;
    rep(i,1,n+1){
        if(d[i]>p){p=d[i];temp=i;}
    }
    res+=d[temp];
    ans.pb(temp);
    // cout<<res<<"\n";
    // for(auto x : ans){cout<<x<<" ";}cout<<"\n";
    vi f = path(temp,y.ff,y.ss); 
    queue<int> q;
    vector<int> used(n+1);
    vector<int> d1(n+1);
    
    for(auto s : f){
    q.push(s);
    used[s] = true;
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d1[u] = d1[v] + 1;
                // p[u] = v;
            }
        }
    
    }
    temp = 0;
    p = -1;
    rep(i,1,n+1){
        if(d1[i]>p && i!=ans[0] && i!=ans[1]){p=d1[i];temp=i;}
    }
    res+=d1[temp];
    ans.pb(temp);
    cout<<res<<"\n";
    for(auto x : ans){cout<<x<<" ";}cout<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef NCR
        init();
    #endif
    #ifdef SIEVE
        sieve();
    #endif
        solve();
    return 0;
}