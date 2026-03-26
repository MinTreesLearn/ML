#include<iostream>
using namespace std;
int main()
{
int n,i;
cin>>n;
if(n%2)
{
cout<<"NO"<<endl;
return 0;
}
pair<int,int>a[n],p,temp;
for(i=0;i<n;i++)cin>>a[i].first>>a[i].second;
p={a[0].first+a[n/2].first,a[0].second+a[n/2].second};
for(i=1;i<n/2;i++){temp={a[i].first+a[i+n/2].first,a[i].second+a[i+n/2].second};if(p!=temp){cout<<"NO"<<endl;return 0;}}
cout<<"YES"<<endl;
}