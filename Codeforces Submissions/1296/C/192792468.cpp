#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500000];
void solve()
{
ll n;string s;
cin>>n>>s;
map<pair<ll,ll>,ll >m;
ll x=0,y=0,mi=3e9,dis,l,r;
s='0'+s;
m[{0,0}]=0;
for(int i=1;i<=n;i++)
{
if(s[i]=='L')x--;
if(s[i]=='R')x++;
if(s[i]=='U')y--;
if(s[i]=='D')y++;
if(m.count({x,y}))
{
ll juli=i-m[{x,y}];
if(mi>juli)
{
mi=juli;
l=m[{x,y}]+1;
r=i;
}
}
m[{x,y}]=i;
}
if(mi==3e9)cout<<"-1"<<endl;
else cout<<l<<" "<<r<<endl;
}
int main()
{
int t;
cin>>t;
while(t--)
solve();
}