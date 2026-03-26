#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int binexp(int a,int b,int m=1e9+7)
{
   if(b==0) return 1;
   int x=binexp(a,b/2,m)%m;
   if(b%2) x=((a%m)*(x*1LL*x)%m)%m;
   else x=(x*1LL*x)%m;
   return x%m;
}
void ram()
{ 
   int n;
   cin>>n;
   string s,t;
   cin>>s>>t;
   vector<pair<char,int>> a,b;
   vector<int> x,y;
   for(int i=0;i<n;i++)
   {
      if(s[i]=='?') x.push_back(i);
      else a.push_back({s[i],i});
   }
   for(int i=0;i<n;i++)
   {
      if(t[i]=='?') y.push_back(i);
      else b.push_back({t[i],i});
   }
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   vector<pair<int,int>> ans;
   int i=0,j=0;
   while(i<a.size() && j<b.size())
   {
      if(a[i].first==b[j].first) 
      {
         ans.push_back({a[i].second,b[j].second});
         i++;
         j++;
      }
      else if(a[i].first>b[j].first)
      {
         if(x.size()>0){
            ans.push_back({x.back(),b[j].second});
            x.pop_back();
         }
         j++;
      }
      else if(a[i].first<b[j].first)
      {
          if(y.size()>0){
            ans.push_back({a[i].second,y.back()});
            y.pop_back();
         }
         i++;
      }
   }
   while(i<a.size()){
       if(y.size()>0){
            ans.push_back({a[i].second,y.back()});
            y.pop_back();
         }
       i++;
   }
   while(j<b.size())
   {
      if(x.size()>0){
            ans.push_back({x.back(),b[j].second});
            x.pop_back();
         }
      j++;
   }
   while(x.size()>0 and y.size()>0)
   {
      ans.push_back({x.back(),y.back()});
      x.pop_back();
      y.pop_back();
   }
   cout<<ans.size()<<endl;
   for(auto it:ans) cout<<it.first+1<<" "<<it.second+1<<endl;
}
int main()
{ 
   int t=1;
   //cin>>t;
   while (t--) ram();
}