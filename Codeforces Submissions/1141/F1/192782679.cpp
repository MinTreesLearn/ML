#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
enum{N=1600};
map<ll,vector<pair<int,int>>>mp;
ll a[N],p[N];
void solve(){
int n;cin>>n;
for(int i=1;i<=n;i++)cin>>a[i],p[i]=p[i-1]+a[i];
for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)
if(mp[p[i]-p[j-1]].empty())mp[p[i]-p[j-1]].push_back({j,i});
else if(mp[p[i]-p[j-1]].back().second<j)mp[p[i]-p[j-1]].push_back({j,i});
vector<pair<int,int>>r={};
for(auto [x,v]:mp)if(v.size()>r.size())r=v;
cout<<r.size()<<'\n';
for(auto[x,y]:r)cout<<x<<' '<<y<<'\n';
}
int main(){
ios::sync_with_stdio(0);
int T=1;//cin>>T;
while(T--)solve();
}