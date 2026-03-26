#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
int n,m,p,cy[4*N],modif[4*N],res=-1e18;
pair<int,int>a[N];
void push(int v,int tl,int tr){
modif[2*v]+=modif[v];
modif[2*v+1]+=modif[v];
cy[2*v]+=modif[v];
cy[2*v+1]+=modif[v];
modif[v]=0;
}
void upd(int v,int tl,int tr,int l,int r,int d){
if(tl>r||tr<l)return;
if(l<=tl&&tr<=r){
if(l==r)cy[v]=max(cy[v],d);
else cy[v]+=d;
modif[v]+=d;
return;
}
push(v,tl,tr);
int tmed=tl+tr>>1;
upd(2*v,tl,tmed,l,r,d);
upd(2*v+1,tmed+1,tr,l,r,d);
cy[v]=max(cy[2*v],cy[2*v+1]);
}
signed main(){
ios_base::sync_with_stdio(0);
cin>>n>>m>>p;
for(int i=0;i<n;++i)cin>>a[i].first>>a[i].second;
sort(a,a+n);
fill(cy,cy+4*N,-1e18);
for(int i=0;i<m;++i){
int j,el;
cin>>j>>el;
upd(1,1,1e6+1,j,j,-el);
}
vector<pair<pair<int,int>,int>>xyz;
for(int i=0;i<p;++i){
int x,y,z;
cin>>x>>y>>z;
xyz.push_back({{x,y},z});
}
sort(xyz.begin(),xyz.end());
int l=0;
for(int i=0;i<n;++i){
while(l<p&&xyz[l].first.first<a[i].first){
upd(1,1,1e6+1,xyz[l].first.second+1,1e6+1,xyz[l].second);
l++;
}
res=max(res,cy[1]-a[i].second);
}
cout<<res;
}
