#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],lef[500005],righ[500005],ansr[5000005],ansl[500005],i,ans,ind;
int main(){
cin>>n;
for(k=1;k<=n;k++)
cin>>a[k];

for(k=1;k<=n;k++){
i=k-1;
while(i>0 && a[i]>a[k]){
i=lef[i];
}
lef[k]=i;
ansl[k]=ansl[i]+(k-i)*a[k];
}
for(k=n;k>=1;k--){
i=k+1;
while(i<=n && a[i]>a[k]){
i=righ[i];
}
righ[k]=i;
ansr[k]=ansr[i]+(i-k)*a[k];

if(ansr[k]+ansl[k]-a[k]>ans){
ans=ansr[k]+ansl[k]-a[k];
ind=k;
}
}
for(k=ind-1;k>=1;k--){
a[k]=min(a[k],a[k+1]);
}
for(k=ind+1;k<=n;k++)
a[k]=min(a[k],a[k-1]);

for(k=1;k<=n;k++)
cout<<a[k]<<" ";
}