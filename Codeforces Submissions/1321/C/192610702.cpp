 //ANY TIME YOU SEE OPTIMIZATION PROBLEM -> BINARY SEARCH THE ANSWER!!!

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define No cout<<"No"<<endl; 
#define NO cout<<"NO"<<endl;  
#define Yes cout<<"Yes"<<endl; 
#define YES cout<<"YES"<<endl; 
#define MOD 1000000007
 
 
void solve()
{ 
  ll n, m, i, j, cnt=0;
  string s;
  cin>>n>>s;
  for(i=0;i<=n;i++)
  { 
    vector<pair<char,ll>> v;
    for(j=0;j<n;j++)
    {
      if((j>0 && s[j]==s[j-1]+1) || (j<n-1 && s[j]==s[j+1]+1))
      {
        v.push_back({s[j], j});
      }
    }

    if(v.size()==0)
    {
      //cout<<cnt<<endl;
      break;
    }
    sort(v.rbegin(),v.rend());
    s.erase(v[0].second, 1);
    cnt++;

  }
  //cout<<s<<endl;
  cout<<n-s.size()<<endl;
 
}
 
 int main()
 {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //int t; cin>>t;
    //while(t--)
    solve();
  }