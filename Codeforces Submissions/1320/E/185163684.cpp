#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
struct LCA {
    vi par,d,jmp,in,out;
    vector<basic_string<int>> adj;
    LCA(int n) : par(n),d(n),jmp(n),in(n),out(n),adj(n) {}
    void add(int i) {
        int p = par[i];
        d[i]=1+d[p];
        if(d[p] - d[jmp[p]] == d[jmp[p]] - d[jmp[jmp[p]]]) jmp[i] = jmp[jmp[p]];
        else jmp[i] = p;
    }
    int jump(int a, int k) {
        int D = max(0,d[a]-k);
        while(d[a]>D) {
            if(d[jmp[a]]>=D) a = jmp[a];
            else a = par[a];
        }
        return a;
    }
    int lca(int a, int b) {
        if(d[a]<d[b]) swap(a,b);
        a = jump(a,d[a]-d[b]);
        while(a!=b) {
            if(jmp[a]!=jmp[b]) a=jmp[a],b=jmp[b];
            else a=par[a],b=par[b];
        }
        return a;
    }
    void addE(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt=0;
    void dfs(int at) {
        in[at]=cnt++;
        for(int to: adj[at]) if(to!=par[at])  {
            par[to]=at;
            add(to);
            dfs(to);
        }
        out[at]=cnt;
    }
    void init() {
        dfs(0);
    }
};
struct virtualtree { // gives weighted subtree that connects all the nodes in vv in O(|vv| log(n))
    vector<vector<pi>> adj;
    vi v;
    int n;
    int size() {return n;}
    virtualtree (const vi& vv, LCA& lca) : v(vv) {
        sort(all(v),[&](int i, int j) {return lca.in[i]<lca.in[j];});
        n = v.size();
        for(int i=0;i+1<n;++i) {
            v.push_back(lca.lca(v[i],v[i+1]));
        }
        sort(all(v),[&](int i, int j) {return lca.in[i]<lca.in[j];});
        v.erase(unique(all(v)),v.end());
        n=v.size();
        adj.resize(n);
        vi st;
        for(int i=0;i<n;++i) {
            int at = v[i];
            while(!st.empty() and lca.out[v[st.back()]]<=lca.in[at]) {
                st.pop_back();
            }
            if(!st.empty()) {
                int par = st.back(), w = lca.d[at]-lca.d[v[st.back()]];
                adj[par].push_back({i,w});
                adj[i].push_back({par,w});
            }
            st.push_back(i);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    LCA lca(n);
    for(int i=0;i<n-1;++i) {
        int x,y; cin >> x >> y;
        --x,--y;
        lca.addE(x,y);
    }
    lca.init();
    int q; cin >> q;
    vi who(n),ans(n);
    while(q--) {
        int k,m; cin >> k >> m;
        vi s(k);
        vi v(k+m);
        for(int i=0;i<k;++i) {
            cin >> v[i];
            v[i]--;
            cin >> s[i];
        }
        for(int i=k;i<k+m;++i) {
            cin >> v[i];
            --v[i];
        }
        virtualtree vt(v,lca);
        for(int i=0;i<vt.n;++i) who[vt.v[i]]=i;
        struct event {
            int time, at,virusid,extra;
            bool operator<(const event& o) const {
                return make_pair(time,virusid)>make_pair(o.time,o.virusid);
            }
        };
        priority_queue<event> pq;
        for(int i=0;i<k;++i) {
            pq.push({0,who[v[i]],i,0});
        }
        vector<bool> vis(vt.n);
        while(!pq.empty()) {
            auto e = pq.top(); pq.pop();
            if(vis[e.at]) continue;
            vis[e.at]=1;
            ans[vt.v[e.at]]=e.virusid+1;
            for(auto [to,w] : vt.adj[e.at]) {
                int need = max(0, (w-e.extra + s[e.virusid]-1)/s[e.virusid]); // ceil division
                pq.push({e.time+need,to,e.virusid,e.extra+need*s[e.virusid]-w});
            }
        }
        for(int i=k;i<k+m;++i) {
            cout << ans[v[i]] << ' ';
        } cout << '\n';

    }
}