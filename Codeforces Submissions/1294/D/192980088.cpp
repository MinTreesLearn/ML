#include<bits/stdc++.h>
using namespace std;
int a[400007],k;
int main()
{
int n,x,y;
cin>>n>>x;
while(n--)
{
cin>>y;
a[y%x]++;
while(a[k%x]>k/x)  k++;
cout<<k<<endl;
}
return 0;
}
