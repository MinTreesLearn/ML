#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e6+10;
int n,a[N],p=1;
vector<int> g[756];
signed main(){
scanf("%lld",&n);
for(int i=1;i<=n;++i){
scanf("%lld",a+i);
for(int j=0;j<31;++j){
if(a[i]&(1ll<<j))g[j].push_back(i);
}
}
for(int i=30;i>=0;--i){
if(g[i].size()==1){
p=g[i][0];
break;
}
}
swap(a[p],a[1]);
for(int i=1;i<=n;++i)printf("%lld ",a[i]);
puts("");
return (0^0);
}