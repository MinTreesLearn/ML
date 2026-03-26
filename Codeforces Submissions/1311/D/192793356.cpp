#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
int too=1e9;
int x,y,z;
cin>>x>>y>>z;
int px,py,pz;
for(int i=1; i<=10000; i++)
{
for(int j=i; j<=10000*2; j+=i)
{
for(int l=j; l<=10000*3; l+=j)
{
if(abs(x-i)+abs(y-j)+abs(z-l)<too)
{
too=abs(x-i)+abs(y-j)+abs(z-l);
px=i;
py=j;
pz=l;
}
}
}
}
printf("%d\n",too);
printf("%d %d %d\n",px,py,pz);
}
return 0;
}
