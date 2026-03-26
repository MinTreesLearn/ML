#import<bits/stdc++.h>
using namespace std;
int i,j,n,t,a[240],b[105],p[240];
main()
{
for(cin>>t;t--;)
{
cin>>n;
for(i=0;i++<n;)
{
cin>>b[i];
p[b[i]]=1;
}
for(i=0;i++<n;)
{
for(j=b[i];p[j]&&j<=2*n;)j++;
if(j>2*n)
{
cout<<-1<<endl;
goto G;
}
a[2*i-1]=b[i];
a[2*i]=j;
p[j]=1;
}
for(i=0;i++<2*n;)cout<<a[i]<<' ';
cout<<endl;
G:
for(i=0;i++<2*n;)p[i]=0;
}
}