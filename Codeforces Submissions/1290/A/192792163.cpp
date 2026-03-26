#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
//int a[N];
signed main(){
int t;
cin>>t;
while(t--){
int n,m,k;
cin>>n>>m>>k;
m--;
k=min(k,m);
vector<int> a(n);
for(int&x :a) cin>>x;
int op=0;
for(int i=0;i<=k;i++){
int l=k-i;
int minl=1e9;
for(int j=l;j<=m-i;j++){
minl=min(minl,max(a[j],a[n-1-(m-j)]));
}
op=max(op,minl);
}
cout<<op<<"\n";
}
}