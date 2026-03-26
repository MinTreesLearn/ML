//Made By Phuong Nam PROPTIT <3//
#pragma GCC Optimize("O3")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define f0(i,n) for(int i=0;i<n;i++)
#define ff(i,b,a) for(int i=b;i>=a;i--)
#define el cout<<'\n'
#define fi first
#define se second
#define pb push_back
#define pk pop_back
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(s) s.begin(),s.end()
#define oset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
typedef long long ll;
const int N=1e6+3;
const int MOD=1e9+7;
int n,m,k,a[N],b[N];
ll dem=0;
set<pii>s;
ll tinh(int x,int y)
{
    ll s1=0,s2=0;
    f1(i,n)
    {
        if(a[i])
        {
            int j=i;
            while(j<=n&&a[j]==1) j++;
            j--;
            s1+=max(0,((j-i+1)-x+1));
            i=j;
        }
    }
    f1(i,m)
    {
        if(b[i])
        {
            int j=i;
            while(j<=m&&b[j]==1) j++;
            j--;
            s2+=max(0,((j-i+1)-y+1));
            i=j;
        }
    }
    return s1*s2;
}
void xuly()
{
    cin>>n>>m>>k;
    f1(i,n) cin>>a[i];
    f1(i,m) cin>>b[i];
    s.insert({1,k});
    f(i,2,sqrt(k))
    {
        if(k%i==0) s.insert({min(i,k/i),max(i,k/i)});
    }
    for(auto i:s)
    {
        int x=i.fi,y=i.se;
        dem+=tinh(x,y);
        if(x!=y) dem+=tinh(y,x);
    }
    cout<<dem;
}
int main()
{
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--) xuly();
}
//-----YEU CODE HON CRUSH-----//
