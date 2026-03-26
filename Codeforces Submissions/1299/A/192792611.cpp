#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[100010];
int main(){
ll n,i,j,c,k,t;
cin>>n;
for(i=1;i<=n;i++) cin>>a[i];
for(j=30;j>=0;j--){
c=0;
for(i=1;i<=n;i++)
if((a[i]>>j)&1)c++,k=i;
if(c==1)break;
}
if(c==1) swap(a[1],a[k]);
for(i=1;i<=n;i++) cout<<a[i]<<" ";
}