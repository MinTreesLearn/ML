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
int n,f[N];
set<int>a[N];
vector<pii>b;
ll dem=0,ans=0,cnt=0;
void xuly()
{
    cin>>n;
    f1(i,n)
    {
        int m;
        cin>>m;
        f1(j,m)
        {
            int x;
            cin>>x;
            if(a[i].empty())
            {
                a[i].insert(x);
                continue;
            }
            auto it=a[i].lower_bound(x);
            if(it!=a[i].begin()) it--;
            if((*it)<x) f[i]=1;
            a[i].insert(x);
        }
        if(f[i]) dem++;
        else
        {
            auto it=a[i].begin();
            b.pb({(*it)+1,0});
            it=a[i].end();
            it--;
            b.pb({(*it),1});
        }
    }
    sort(all(b));
    for(auto i:b)
    {
        if(i.se) ans+=cnt;
        else cnt++;
    }
    ans+=dem*dem+2*dem*cnt;
    cout<<ans;
}
int main()
{
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--) xuly();
}
//-----YEU CODE HON CRUSH-----//
