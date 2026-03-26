#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int maxn=1e5+11;
const int Maxx=1e5+11;
const int mod=1e9+7;
int t;
int n,m;
ll k,now;
void solve()
{
   cin>>n>>m>>k;
   now=0;
   if(k>4*n*m-2*n-2*m) {cout<<"NO"<<endl;return;}
   cout<<"YES"<<endl;
   vector<pair<int,string>>ans;
   if(m!=1)
   {
       if(now+m-1<=k)
       {
           ans.emplace_back(m-1,"R");
           now+=m-1;
       }
       else
       {
           ans.emplace_back(k,"R");
           now+=k;
       }
       if(now+m-1<=k)
       {
           ans.emplace_back(m-1,"L");
           now+=m-1;
       }
       else if(k-now)
       {
           ans.emplace_back(k-now,"L");
           now=k;
       }
   }
   for(int i=2;i<=n;++i)
   {
       if(now+1<=k&&n!=1)
       {
           ans.emplace_back(1,"D");
           ++now;
       }
       if(m!=1)
       {
           if(now+m-1<=k)
           {
               ans.emplace_back(m-1,"R");
               now+=m-1;
           }
           else if(k-now)
           {
               ans.emplace_back(k-now,"R");
               now=k;
           }
           if(now+3*(m-1)<=k)
           {
               ans.emplace_back(m-1,"UDL");
               now+=3*(m-1);
           }
           else
           {
               ll num=(k-now)/3;
               if(num) ans.emplace_back(num,"UDL");
               ll res=(k-now)%3;
               if(res==1) ans.emplace_back(1,"U");
               else if(res==2) ans.emplace_back(1,"UD");
               now=k;
           }
       }
   }
   if(now!=k&&n!=1)
   {
       ans.emplace_back(k-now,"U");
   }
   cout<<int(ans.size())<<endl;
   for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
}
int main()
{
    //scanf("%d",&t);
    ios::sync_with_stdio(false);cin.tie(0);
    //ios::sync_with_stdio(false);cin.tie(0);cin>>t;while(t--)
        solve();
    return 0;
}