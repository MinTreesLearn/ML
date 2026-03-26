#include <bits/stdc++.h>
using namespace std;
int a[100000];
int c=1e9+1;
int main(){
int t;
cin>>t;
while(t--){
int ans=0;
int n,m,k;
cin>>n>>m>>k;
k=min(k,m-1);
for(int i=0;i<n;i++) cin>>a[i];
for(int i=0;i<=k;i++){
c=1e9+1;
for(int j=0;j<m-k;j++){
c=min(c,max(a[i+j],a[i+j+n-m]));
}
ans=max(ans,c);
}
cout<<ans<<'\n';
ans=0;
}
}