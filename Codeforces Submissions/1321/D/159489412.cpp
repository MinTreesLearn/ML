#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, q, m, k;
int a[N], b[N];
vector<int>graph[N];
vector<int>transpose[N];
auto main() ->int32_t
{
  IOS
  cin >> n >> m;
  for(int i=1;i<=m;i++)
  {
    int u,v;
    cin >> u >> v;
    graph[u].push_back(v);
    transpose[v].push_back(u);
  }
  cin >> k;
  for(int i=1;i<=k;i++)
    cin >> a[i];
  int mnr = 0, mxr = 0;
  vector<int>dist(n+1,1e17);
  vector<int>vis(n+1,0);
  queue<int>q;
  q.push(a[k]);
  dist[a[k]] = 0;
  while(q.size())
  {
    auto x = q.front();
    q.pop();
    vis[x] = 1;
    for(auto i:transpose[x])
    {
      if(vis[i])continue;
      vis[i] = 1;
      dist[i] = min(dist[i],dist[x]+1);
      q.push(i);
    }
  }
  for(int i=1;i<k;i++)
  {
    if(dist[a[i+1]]>dist[a[i]]-1)
    {
      mnr++;
      mxr++;
    }
    else if(dist[a[i+1]] == dist[a[i]]-1)
    {
      int ok = 1; int flag = 1;
      for(auto j:graph[a[i]])
      {
        if(dist[j] == dist[a[i]]-1)
        {
          if(flag)
            flag = 0;
          else
            ok = 0;
        }
      }
      mxr+=(1^ok);
    }
  }
  cout<<mnr<<' '<<mxr<<endl;
}