#include<bits/stdc++.h>
using namespace std;
int main()
{
int T;
cin>>T;
while(T--)
{
long long n,x,arr[100005],best=INT_MAX;
cin>>n>>x;
for(int i=0;i<n;i++)
{
cin>>arr[i];
best=min(best,x/arr[i]+(x%arr[i]?1:0)+(arr[i]>x?1:0));
}
cout<<best<<endl;

}
}

