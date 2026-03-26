#include<bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<> pp(0.0,1.0);
#define int long long
#define pii pair<int,int>
#define maxn 150005
const int inf=1e18;
struct node{
    int sum,len0,len1,cnt;
};
struct line{
    mutable int a,b,p;
    bool operator<(const line &o)const{return a<o.a;}
    bool operator<(int o)const{return p<o;};
};
struct dcht:multiset<line,less<>>{
    int div(int a,int b){
        return (a/b)-((a^b)<0 && a%b);
    }
    bool isect(iterator x,iterator y){
        if(y==end()){x->p=inf;return 0;}
        if(x->a==y->a) x->p=(x->b>=y->b)?inf:-inf;
        else x->p=div(y->b-x->b,x->a-y->a);
        return x->p>=y->p;
    }
    void add_line(line l){
        auto z=insert(l),y=z++,x=y;
        while(isect(y,z)) z=erase(z);
        if(x!=begin() && isect(--x,y)) isect(x,erase(y));
        while((y=x)!=begin() && (--x)->p>=y->p) isect(x,erase(y));
    }
    int query(int v){
        auto l=*lower_bound(v);
        return l.a*v+l.b;
    }
}s[2];
vector<int> edge[maxn];
int n,a[maxn],ans,child[maxn],sz;
bool used[maxn];
vector<node> total[maxn];
void dfs(int u,int par){
    child[u]=1;
    for(int v:edge[u]){
        if(v==par || used[v]) continue;
        dfs(v,u);
        child[u]+=child[v];
    }
}
int findcen(int u,int par){
    for(int v:edge[u]){
        if(v==par || used[v]) continue;
        if(child[v]>sz/2) return findcen(v,u);
    }
    return u;
}
void calc(int u,int par,int anc,int add,int len0,int len1,int sum,int cnt){
    cnt++;sum+=a[u];
    len0+=cnt*a[u];len1+=sum;
    total[anc].push_back({sum,len0,len1,cnt});
    ans=max(ans,len0+s[1].query(sum+add)+sum+add);
    ans=max(ans,len1+(cnt+1)*add+s[0].query(cnt+1));
    for(int v:edge[u]){
        if(v==par || used[v]) continue;
        calc(v,u,anc,add,len0,len1,sum,cnt);
    }
}
void decompose(int u,int par){
    dfs(u,par);sz=child[u];
    int cen=findcen(u,par);
    used[cen]=true;
    s[0].clear();s[1].clear();
    for(int v:edge[cen]){
        if(v==par || used[v]) continue;
        total[v].clear();
        calc(v,cen,v,a[cen],0,0,0,0);
        for(node x:total[v]){
            s[0].add_line({x.sum,x.len0,inf});
            s[1].add_line({x.cnt,x.len1,inf});
        }
    }
    for(int v:edge[cen]){
        if(v==par || used[v]) continue;
        decompose(v,cen);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v;cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin >> a[i];
    decompose(1,0);
    cout << ans << '\n';
}
