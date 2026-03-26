#include <bits/stdc++.h>
using namespace std;
long long st[800009];
long long lazy[800009];
long long a[200009];
long long b[200009];
void push(int id){
lazy[id*2]+=lazy[id];
lazy[id*2+1]+=lazy[id];
st[id*2]+=lazy[id];
st[id*2+1]+=lazy[id];
lazy[id]=0;
}
void update(int id,int l,int r,int u,int v,long long val){
if (l>v||r<u||u>v)return;
if (u<=l&&r<=v){
st[id]+=val;
lazy[id]+=val;
return;
}
int mid=(l+r)/2;
push(id);
update(id*2,l,mid,u,v,val);
update(id*2+1,mid+1,r,u,v,val);
st[id]=min(st[id*2],st[id*2+1]);
}
signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
for (int i=1;i<=n;i++)cin>>a[i];
for (int i=1;i<=n;i++){
cin>>b[i];
update(1,1,n,1,a[i]-1,b[i]);
}
long long ans=1e18;
for (int i=n;i>=2;i--){
update(1,1,n,1,a[i]-1,-b[i]);
update(1,1,n,a[i]+1,n,b[i]);
ans=min(ans,st[1]);
}
cout<<ans;

}
