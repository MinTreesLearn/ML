#include<bits/stdc++.h>
using namespace std;
int i,a,n,r,c,f;
int main()
{
for(cin>>n;n>0;n--)cin>>a,a?c++:(f?(r=max(r,c)):(f=1,i=c),c=0);
cout<<max(r,c+i);
}
