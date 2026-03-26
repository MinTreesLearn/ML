#include<bits/stdc++.h>
using namespace std;
set<int> kit;
int main(){
int t;
cin>>t;
int n,s,k;
while(t--){
cin>>n>>s>>k;
kit.clear();
int x;
for(int i=1;i<=k;i++){
cin>>x;
kit.insert(x);
}
int minx=1e9;
for(int i=max(1,s-1005);i<=min(n,s+1005);i++){
if(!kit.count(i)) minx=min(minx,abs(i-s));
}
cout<<minx<<endl;
}
}