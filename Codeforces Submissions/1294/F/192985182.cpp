#include <bits/stdc++.h>
#define ll long long
#define fast ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
vector<ll> v[200009];
ll mx,a,b,c,vis[200009],n,ans;
void dfs(ll i,ll p,ll d) {
if(d>mx){ mx=d; a=i; }
for(int x : v[i]) if(x!=p) dfs(x,i,d+1);
}
ll dfs1(ll i,ll p) {
if(i==b) return vis[i]=1;
for(int x : v[i]) if( x!=p && dfs1(x,i) ) return vis[i]=1;
return 0;
}
void dfs2(ll i,ll p,ll d) {
if(vis[i]) d=0;
if(d>mx){ mx=d; c=i; }
for(int x : v[i]) if(x!=p) dfs2(x,i,d+1);
}
int main() {
fast cin>>n;
for(int i=1;i<n;i++){ cin>>a>>b; v[a].push_back(b); v[b].push_back(a); }
dfs(1,0,0); b=a; mx=0;
dfs(b,0,0); ans+=mx; mx=0;
dfs1(a,0); dfs2(a,-1,0); ans+=mx;
if(mx==0) c=v[a].back();
cout<<ans<<endl<<a<<" "<<b<<" "<<c<<endl;
}
