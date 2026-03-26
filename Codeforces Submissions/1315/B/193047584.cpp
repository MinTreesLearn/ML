#include <bits/stdc++.h>
using namespace std;
int t,a,b,p,i,c;
string s;
main()
{
cin>>t;
while (t--)
{
cin>>a>>b>>p>>s;
for (i=s.size()-2,c=0; i>=0; --i)
{
if (c!=s[i])
{
c=s[i];
p-=(c=='A'? a: b);
if (p<0) break;
}
}
cout<<i+2<<endl;
}
}