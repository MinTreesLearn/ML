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
   string s;
   cin>>s;
   for(char ch='z';ch>='b';ch--)
   {
      string t="";
      if(s.find(ch)==string :: npos) continue;
      for(int i=0;i<s.size();i++)
      {
         char ch1=(char)(ch-1);
         int j=i;
         int p=0,q=0;
         while(i<s.size() and (s[i]==ch or s[i]==ch1)) 
         {
            if(s[i]==ch) p=1;
            else q=1;
            i++;
         }
         if(p and q)
         {
            for(int k=j;k<i;k++) if(s[k]==ch) s[k]='@';
         }
      }
      for(auto it:s) if(it!='@') t+=it;
      s=t;
   }
   //cout<<s<<endl;
   cout<<n-s.size()<<endl;
}
int main()
{ 
   IOS
   int t=1;
   //cin>>t;
   while (t--) ram();
}