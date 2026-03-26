#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep3(i,m,n) for(int i=(m);i<(n);i++)
#define foreach(x,a) for(auto& (x) : (a) )

#define endl '\n'
#define dump(x)  cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl

#define pb(a) push_back(a)

#define sz(x) ((int)(x).size())
#define in(a,us) (us).find(a)!=(us).end()

template<typename S>
using Vec = vector<S>;

template<typename S, typename T>
using P = pair<S,T>;

template<typename S, typename T, typename U>
using Tpl = tuple<S,T,U>;

using ll = long long;
using ld = long double;

using Pii = P<int,int>;
using Pll = P<ll,ll>;

using Tiii = Tpl<int,int,int>;
using Tll = Tpl<ll,ll,ll>;

using Vi = Vec<int>;
using VVi = Vec<Vi>;

template<typename S, typename T>
using umap = unordered_map<S,T>;

template<typename S>
using uset = unordered_set<S>;

struct Edge{
    int src;
    int dst;
    Edge(int _src, int _dst) : src(_src), dst(_dst){}
};
using Graph = Vec<Vec<Edge>>;

int C[2002];

bool dfs(int v, Graph &g, VVi &ans){
    int n = 0;
    bool aflag = false;
    bool rflag = true;
    for (auto e: g[v]){
        int v1 = e.dst;
        rflag &= dfs(v1, g, ans);
        rep(i,ans[v1].size()){
            n++;
            if (n-1==C[v]){
                aflag = true;
                ans[v].push_back(v+1);
                n++;
            }
            ans[v].push_back(ans[v1][i]);
        }
    }
    if (n==C[v]){
        aflag = true;
        ans[v].push_back(v+1);
        n++;
    }
    //cout << n << endl;
    return aflag & rflag;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    Vi p(n);
    int root;
    rep(i,n) cin >> p[i] >> C[i];
    Graph g(n, Vec<Edge>());
    rep(i,n){
        if(p[i]!=0){
            p[i]--;
            g[p[i]].push_back(Edge(p[i],i));
        } else {
            root = i;
        }
    }
    VVi ans(n);
    if (dfs(root, g, ans)){
        Vi a(n);
        cout << "YES" << endl;
        rep(i,n){
            a[ans[root][i]-1] = i+1;
        }
        rep(i,n) cout << a[i] << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
