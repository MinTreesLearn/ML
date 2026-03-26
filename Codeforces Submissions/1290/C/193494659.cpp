#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define all(v) v.begin(), v.end()
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=3e5+5;
int n, k, sz[2*N], p[2*N], st[N], val[N], ans;
string s;
vector<int>w[N];

int par(int u){
    if(p[u]==u) return u;
    return p[u]=par(p[u]);
}

void dsu(int u, int v){
    p[u]=v;
    sz[v]+=sz[u];
}

void opr(int u, int v){
    u=par(u);v=par(v);
    if(u==v)
        return;
    ans-=val[v>>1]+val[u>>1];
    dsu(u, v);
    dsu(u^1, v^1);
    if(st[u>>1]!=-1)
        st[v>>1]=(u&1)^(v&1)^st[u>>1];
    if(st[v>>1]!=-1){
        int vv=(v>>1)<<1;
        val[v>>1]=sz[vv^st[v>>1]];
    }
    else
        val[v>>1]=min(sz[v], sz[v^1]);
    ans+=val[v>>1];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>s;
    for(int i=0;i<k;++i){
        int c;
        cin>>c;
        for(int j=0;j<c;++j){
            int x;
            cin>>x;
            w[--x].push_back(i);
        }
    }
    iota(p, p+2*k, 0);
    memset(st, -1, sizeof(st));
    for(int i=0;i<k;++i)
        sz[i<<1]=1;
    for(int i=0;i<n;++i){
        if(s[i]=='1'){
            if((int)w[i].size()==2)
                opr(w[i][0]<<1, w[i][1]<<1);
            else if(!w[i].empty()){
                int v=par(w[i][0]<<1);
                ans-=val[v>>1];
                st[v>>1]=(v&1)^1;
                val[v>>1]=sz[v^1];
                ans+=sz[v^1];
            }
        }
        else{
            if((int)w[i].size()==2)
                opr(par(w[i][0]<<1)^1, w[i][1]<<1);
            else{
                int v=par(w[i][0]<<1);
                ans-=val[v>>1];
                st[v>>1]=v&1;
                val[v>>1]=sz[v];
                ans+=sz[v];
            }
        }
        cout<<ans<<'\n';
    }
}
