#include<bits/stdc++.h>
#define x first
#define y second
#define uid(a, b) uniform_int_distribution<int>(a, b)(eng)
using namespace std;
#define int long long
using i64=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  vector<int>b(n);
  
  int ans=0;
  auto ask=[&](int l,int r,int idx)
  {
      int r1=upper_bound(b.begin(),b.end(),r)-b.begin()-1;
      int l1=lower_bound(b.begin(),b.end(),l)-b.begin();

      int as=r1-l1+1;
      if(idx>=l1&&idx<=r1)as--;

      return max(0ll,as);
  };
  for(int i=0;i<25;i++)
  {
    int T=(1<<i);
    
    for(int j=0;j<n;j++)
      b[j]=a[j]%(2*T);

    sort(b.begin(),b.end());

    int cnt=0;

    for(int j=0;j<n;j++)
    {
      cnt+=ask(T-b[j],2*T-1-b[j],j);
      cnt+=ask(3*T-b[j],4*T-1-b[j],j);
    }
    cnt/=2;
    if(cnt&1)
       ans+=T;
  }
  cout<<ans<<"\n";
}
signed main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}