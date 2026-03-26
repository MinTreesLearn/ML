#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
pair<long long,long long>q[200005];
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1;i<=n;i++)
{
long long x;
cin>>x;
q[i]=make_pair(x,a[i]);
}
sort(a+1,a+n+1);
sort(q+1,q+n+1);
for(int i=1;i<=n;i++)
ans+=(lower_bound(a+1,a+n+1,q[i].second)-a-n+i-1)*q[i].second;
cout<<ans;
}