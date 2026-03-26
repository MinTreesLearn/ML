#include<bits/stdc++.h>
using namespace std;
int t,n,x,s,a;
int main(){
cin>>t;
while(t--&&cin>>n){
a=s=0;
for(int i=1;i<=n;i++){
cin>>x;
if(x==0)
a++,s++;
s+=x;
}
cout<<a+(s==0)<<'\n';
}
return 0;
}
