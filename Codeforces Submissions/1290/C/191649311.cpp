#include <bits/stdc++.h>
#define int long long 
#define pb push_back
using namespace std;
const int INF=1e6+5;
int n,m,fa_set[INF],sz[INF],vis2[INF],ans,vis[INF];
int find_set(int x) {return x==fa_set[x]?x:fa_set[x]=find_set(fa_set[x]);}
void mer(int x,int y) {
    x=find_set(x);y=find_set(y);
    if (x==y) return ;
    // cout<<x<<" "<<y<<" okkkkkkkqweq??????\n";
    fa_set[x]=y;
    sz[y]+=sz[x];sz[x]=0;
    vis2[y]|=vis2[x];
}
string s1;
vector <int> v[INF];
void solve(int x,int y) {
    x=find_set(x);y=find_set(y);
    if (vis2[x]) ans-=sz[x];
    else if (vis2[y]) ans-=sz[y];
    else if (vis[x]) ans-=sz[x];
    else ans-=sz[y];
    vis[x]=vis[y]=0;
}
void solve2(int x,int y) {
    x=find_set(x);y=find_set(y);
    if (vis2[x]) ans+=sz[x];
    else if (vis2[y]) ans+=sz[y];
    else {
        if (sz[x]<sz[y]) ans+=sz[x],vis[x]=1;
        else ans+=sz[y],vis[y]=1;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>s1; s1=" "+s1;
    for (int i=1;i<=m;i++) {
        int c=0;cin>>c;
        for (int j=1;j<=c;j++) {
            int y=0;cin>>y;
            v[y].pb(i);
        }
    }
    for (int i=1;i<=m;i++) fa_set[i]=i,sz[i]=1;
    for (int i=1;i<=m;i++) fa_set[i+m]=i+m;

    for (int i=1;i<=n;i++) {
        if (v[i].size()==1) {
            int id=v[i][0];
            int xx=find_set(id),yy=find_set(id+m);
            solve(xx,yy);
            if (s1[i]=='0') vis2[xx]=1;
            else vis2[yy]=1;
            solve2(xx,yy);
        }
        else if (v[i].size()==2) {
            int id=v[i][0],id2=v[i][1];
            int xx=find_set(id),yy=find_set(id+m);
            int aa=find_set(id2),bb=find_set(id2+m);
            if (xx==aa || xx==bb) ;
            else {
                // cout<<i<<" "<<vis2[yy]<<" "<<vis2[bb]<<" "<<sz[yy]<<" "<<yy<<" "<<sz[aa]<<" iwjriewr\n";
                // cout<<find_set(aa)<<" "<<find_set(yy)<<" this one?\n";
                solve(xx,yy);solve(aa,bb);
                if (s1[i]=='0') {mer(xx,bb);mer(yy,aa);}
                else {mer(xx,aa);mer(yy,bb);}
                xx=find_set(xx);yy=find_set(yy);
                solve2(xx,yy);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}