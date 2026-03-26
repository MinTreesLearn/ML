#include <bits/stdc++.h>
using namespace std;
int a[510],f[510],s[510],t,n;
int main(){
cin>>n;
for (int i=1;i<=n;i++) cin>>a[i];
for (int i=1;i<=n;i++){
for (int j=1;j<=i;j++){
t=0; s[++t]=a[j];
for (int k=j+1;k<=i;k++){
s[++t]=a[k];
while (s[t]==s[t-1]) s[t-1]++,t--;}
f[i]=max(f[i],f[j-1]+(i-j+1-t));}}
cout<<n-f[n];
return 0;
}