// LUOGU_RID: 94264985
#include<bits/stdc++.h>
#define int long long
using namespace std;
main(){
ios::sync_with_stdio(false);
int t; cin>>t;
while (t--){
int n,m,s=0,c=0; cin>>n>>m;
multiset<int,greater<int>> f;
while(m--){
int x; cin>>x;
s+=x; f.insert(x);
}
if(s<n){cout<<"-1\n"; continue;}
while(n){
m=*f.begin();
f.erase(f.begin());
if(m<=n)n-=m,s-=m;
else if(s-m<n){
c++; f.insert(m>>1);
f.insert(m>>1);
}
else s-=m;
}
cout<<c<<endl;
}
return 0;
}