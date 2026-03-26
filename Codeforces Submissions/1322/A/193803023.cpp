#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
signed main()
{
    int n;cin>>n;
   string s;cin>>s;
   int a=0,b=0;
   int c=0;
   int res=0;
   for(int i=0;i<s.size();i++)
   {
       if(s[i]=='(') a++,c++;
       else
       {
           b++;if(c>0) c--;
       }
       if(a==b) 
       {
           if(c)
           res+=2*a;
           a=b=c=0;
       }
   }
   if(a!=b) puts("-1");
   else cout<<res<<"\n";
}