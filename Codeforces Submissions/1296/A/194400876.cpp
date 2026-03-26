#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
  int x;
  cin>>x;
  int a[x];
  int flag=0;
  int del=0;
  for(int i=0;i<x;++i){
    cin>>a[i];
    if(a[i]%2!=0)
    flag=1;

    if(a[i]%2==0)
    del=1;
   }
  if(x%2!=0 && flag==1)
  cout<<"YES";
  else if(x%2==0 && del==1 && flag==1)
   cout<<"YES";
  else 
  cout<<"NO";
   cout<<endl;
  }
}