#include<bits/stdc++.h>
using namespace std;
signed main(){
int x,i,j,m=0,n=0;
cin>>x;
int a[2*x]={0};
for(i=0;i<2*x;i++){
cin>>a[i];
}
for(i=0;i<x;i++){
if(a[i]>a[x+i]) m++;
if(a[i]<a[i+x]) n++;
}
if(m==0) cout<<-1<<endl;
else cout<<n/m+1<<endl;

}
