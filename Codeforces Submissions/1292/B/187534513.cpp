#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int maxn=1e5+11;
const int Maxx=1e5+11;
const int mod=1e9+7;
//int t;
ll xo,yo,ax,ay,bx,by;
ll xs,ys,t;
void solve()
{
     cin>>xo>>yo>>ax>>ay>>bx>>by;
     cin>>xs>>ys>>t;
     vector<pair<ll,ll>>v;
     v.emplace_back(xo,yo);
     pair<ll,ll>pi=make_pair(xo,yo);
     while(1)
     {
         if((ll(1e17)-bx)/pi.first<ax||(ll(1e17)-by)/pi.second<ay) break;
         ll px=ax*pi.first*1ll+bx;
         ll py=ay*pi.second*1ll+by;
         v.emplace_back(px,py);
         pi=make_pair(px,py);
     }
     //cout<<int(v.size())<<endl;
     int ans=0;
     for(int i=0;i<v.size();++i)
     {
         for(int j=i;j<v.size();++j)
         {
             for(int k=i;k<=j;++k)
             {
                 ll sum=abs(xs-v[k].first)+abs(ys-v[k].second);
                 sum+=abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second);
                 sum+=min(abs(v[i].first-v[k].first)+abs(v[i].second-v[k].second),abs(v[j].first-v[k].first)+abs(v[j].second-v[k].second));
                 if(sum<=t)
                 {
                     ans=max(ans,j-i+1);
                 }
             }
         }
     }
     cout<<ans<<endl;
}
int main()
{
    //scanf("%d",&t);
    ios::sync_with_stdio(false);cin.tie(0);
    //ios::sync_with_stdio(false);cin.tie(0);cin>>t;while(t--)
        solve();
    return 0;
}