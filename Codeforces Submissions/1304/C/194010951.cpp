#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fr(i,a,b,k) for(int i=a;i<b;i+=k)
#define frrev(i,a,b,k) for(int i=a;i>b;i-=k)
#define NO cout<<"NO\n"
#define YES cout<<"YES\n"
#define V vector<ll int> 
#define VP vector<pair<ll int,ll int>> 
#define MP map<ll int,ll int> 
#define pb push_back
#define ff first 
#define ss second 
#define input(A) for(auto &i:A)cin>>i
#define output(A) for(auto &i:A)cout<<i<<" "
int H[100],L[100],T[100];
void solve(int t)
{
  int n,m;
  cin>>n>>m;
  fr(i,0,n,1)
  cin>>T[i]>>L[i]>>H[i];
  int pt=0;
  int mini=m;
  int maxi=m;
  bool f=true;
  fr(i,0,n,1)
  {
    mini-=T[i]-pt;
    maxi+=T[i]-pt;
    if(maxi<L[i] || mini>H[i])
    {
       f=false;
       break;
    }
    maxi=min(maxi,H[i]);
    mini=max(mini,L[i]);
    pt=T[i];
  }  
  if(f)
  YES;
  else
 NO;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       solve(t);
    }
    return 0;
}

