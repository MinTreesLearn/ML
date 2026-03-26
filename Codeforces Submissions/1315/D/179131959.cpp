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
  vector<pair<int,int>>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i].x;
  for(int i=0;i<n;i++)
    cin>>a[i].y;
  vector<int>p(n);
  iota(p.begin(),p.end(),0ll);
  sort(p.begin(),p.end(),[&](auto i,auto j)
  {
    return a[i]<a[j];
  });
  int ans=0;
  set<pair<int,int>>S;
  for(int i=0,j=0,x=0;i<n;i++,x++)
  {
    if(i==j)
      x=a[p[i]].x;
    while(j<n&&a[p[j]].x==x)
    {
      S.insert({-a[p[j]].y,p[j]});
      j++;
    }
    int k=S.begin()->y;
    ans+=(x-a[k].x)*a[k].y;
    S.erase(S.begin());
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