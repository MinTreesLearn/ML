#include<bits/stdc++.h>
using namespace std;
int a[3][1010101],x,y;
int n,q,i,j,k;
int main(){
cin>>n>>q;
while(q--){
cin>>x>>y;
if(a[x][y]==0){
a[x][y]=1;
for(i=-1;i<=1;i++){
if(a[3-x][y+i]==1)
k++;}
}else{
a[x][y]=0;
for(i=-1;i<=1;i++){
if(a[3-x][y+i]==1)
k--;}
}if(k==0){
cout<<"YES"<<endl;
}else{
cout<<"NO"<<endl;
}
}
}
