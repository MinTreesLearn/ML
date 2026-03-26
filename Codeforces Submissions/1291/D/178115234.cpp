#include<bits/stdc++.h>
#define x first
#define y second
#define uid(a, b) uniform_int_distribution<int>(a, b)(eng)
using namespace std;
#define int long long
using i64=long long;
void solve()
{
	 string s;
   cin>>s;
   int n=s.size();
   vector prefix(n+1,vector<int>(26));
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<26;j++)
      prefix[i+1][j]=prefix[i][j]+(s[i]==('a'+j));
   }
   int q;
   cin>>q;
   while(q--)
   {
    int l,r;
    cin>>l>>r;
    if(l==r||(s[l-1]!=s[r-1]))
    {
      cout<<"Yes\n";
      continue;
    }
    else
    {
      int cnt=0;
      for(int i=0;i<26;i++)
        if(prefix[r][i]-prefix[l-1][i]>0)cnt++;
      if(cnt>=3)
      {
        cout<<"Yes\n";
        continue;
      }
    }
    cout<<"No\n";
   }
}
signed main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}