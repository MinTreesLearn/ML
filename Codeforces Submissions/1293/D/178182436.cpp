#include<bits/stdc++.h>
#define x first
#define y second
#define uid(a, b) uniform_int_distribution<int>(a, b)(eng)
using namespace std;
#define int long long
using i64=long long;
void solve()
{
	int x,y;
  int ax,ay,bx,by;
  cin>>x>>y>>ax>>ay>>bx>>by;

  int xs,ys,t;
  cin>>xs>>ys>>t;
  vector<int>dis; 
  int ans=0;
  vector<pair<int,int>>point;
  point.push_back({x,y});
  int n=1;
  while(1)
  { 
      if(point[n-1].x*ax+bx-xs<=t&&point[n-1].y*ay+by-ys<=t)
      {
        point.push_back({point[n-1].x*ax+bx,point[n-1].y*ay+by});
        n++;
      }
      else
      {
        break;
      }
  }
  auto d=[&](pair<int,int> a,pair<int,int> b)
  {
    return abs(a.x-b.x)+abs(a.y-b.y);
  };
  for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
    {
      if(j-i+1<=ans)continue;
      int tp=min(d(point[i],{xs,ys}),d(point[j],{xs,ys}));
      tp+=d(point[i],point[j]);
      if(tp<=t)
      {
        ans=j-i+1;
      }
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