#include<bits/stdc++.h>
using namespace std;
#define f(i,j,k) for(register int i=j;i<=k;++i)
#define g(i,j,k) for(register int i=j;i>=k;--i)
int n,m,s,l;
int f[303];
int a[303030][10];
int doing(int x){
int p=(1<<m)-1,q;
f(i,0,p)f[i]=0;
f(i,1,n){
q=0;
f(j,1,m)q=(q<<1)+(a[i][j]>=x);
f[q]=i;
}
f(i,0,p)f(j,0,p)if(f[i] && f[j] && (i|j)==p){
s=f[i];l=f[j];
return 1;
}
return 0;
}
int main(){
cin>>n>>m;
f(i,1,n)f(j,1,m)scanf("%d",&a[i][j]);
s=l=1;
int le=1,ri=1e9,mid;
while(le<=ri){
mid=(le+ri)>>1;
if(doing(mid))le=mid+1;
else ri=mid-1;
}
printf("%d %d\n",s,l);
return 0;
}
