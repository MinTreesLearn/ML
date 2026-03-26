#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n;
int a[N];
set<int>s;

inline void Solve(int x)
{
for(int i=2;i*i<=x;i++)
{
if(x%i==0)
{
s.insert(i);
while(x%i==0)x/=i;
}
}
if(x>1)s.insert(x);
}
signed main()
{
mt19937 rnd(time(0));
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=40;i++)
{
int p=rnd()%n+1;
Solve(a[p]);
Solve(a[p]+1);
if(a[p]>1)Solve(a[p]-1);
}
int ans=0x3f3f3f3f3f3f3f3f;
for(auto x:s)
{
int res=0;
for(int i=1;i<=n;i++)
res+=(a[i]<=x?x-a[i]:min(a[i]%x,x-a[i]%x));
ans=min(ans,res);
}
cout<<ans<<'\n';
return 0;
}