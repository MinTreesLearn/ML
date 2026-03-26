#include<bits/stdc++.h>
using namespace std;
int const M=1100;int i,j,n,k,Ans,B,Bound,a[M],L[M],R[M];
void clr(){cout<<"R"<<endl;}
bool ask(int x){cout<<"? "<<x<<endl;
char ch;cin>>ch;return ch=='Y';
}
void solve(int x){
for (int i=L[x];i<=R[x];i++)
if (ask(i)) a[i]=0;
}
int main(){ cin>>n>>k;
for (i=1;i<=n;i++) a[i]=1;
if (k==n){
for (i=1;i<=n;i++)
if (!ask(i))
Ans++;
return cout<<"! "<<Ans<<endl,0;
}
B=max(1,k/2);Bound=n/B;
for (i=1;i<=Bound;i++) L[i]=R[i-1]+1,R[i]=i*B;
for (i=1;i<Bound;i++)
for (j=i+1;j<=Bound;j++)
solve(i),solve(j),clr();
for (i=1;i<=n;i++) Ans+=a[i];
return cout<<"! "<<Ans<<endl,0;
}