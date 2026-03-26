#include<bits/stdc++.h>
using namespace std;
int n,K,kc,ks,vis[1030];
char s[3];
void ins(int x){
int l=kc*x+1,r=l+kc-1;
for(int i=l;i<=r;i++)if(!vis[i]){cout<<"? "<<i<<endl;cin>>s;if(s[0]=='Y')vis[i]=1;}
}
void work(int x){
ins(x);
for(int i=1;i<(ks>>1);i++){
ins((x-i+ks)%ks);
ins((x+i)%ks);
}if(ks>1)ins((x+(ks>>1))%ks);
}
int main(){
cin>>n>>K;kc=min(n,K);ks=n/kc;
for(int i=0;i<ks;i++){
work(i);cout<<"R"<<endl;
}int ans=0;
for(int i=1;i<=n;i++)ans+=vis[i]^1;
cout<<"! "<<ans<<endl;
return 0;
}
